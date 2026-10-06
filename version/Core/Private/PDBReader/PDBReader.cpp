#include "PDBReader.h"

#include <filesystem>
#include <fstream>

#include <Logger/Logger.h>
#include <Tools.h>

#include "../Private/Helpers.h"
#include "../Private/Offsets.h"

namespace API
{
	template <typename T>
	class ScopedDiaType
	{
	public:
		ScopedDiaType() : _sym(nullptr)
		{
		}

		ScopedDiaType(T* sym) : _sym(sym)
		{
		}

		~ScopedDiaType()
		{
			if (_sym != nullptr)
				_sym->Release();
		}

		T** ref() { return &_sym; }
		T** operator&() { return ref(); }
		T* operator->() { return _sym; }
		operator T*() { return _sym; }
		void Attach(T* sym) { _sym = sym; }

	private:
		T* _sym;
	};

	template <typename T>
	using CComPtr = ScopedDiaType<T>;

	namespace
	{
		// bump whenever the dump logic or the file layout changes
		constexpr uint32_t cache_version = 1;
		constexpr char cache_magic[8] = {'A', 'P', 'I', 'P', 'D', 'B', 'C', '1'};

		uint64_t Checksum(const char* data, size_t size)
		{
			uint64_t hash = 14695981039346656037ULL;
			size_t i = 0;
			for (; i + 8 <= size; i += 8)
			{
				uint64_t word;
				memcpy(&word, data + i, 8);
				hash = (hash ^ word) * 1099511628211ULL;
				hash ^= hash >> 29;
			}

			for (; i < size; ++i)
				hash = (hash ^ static_cast<unsigned char>(data[i])) * 1099511628211ULL;

			return hash;
		}

		template <typename V>
		void Put(std::string& out, const V& value)
		{
			out.append(reinterpret_cast<const char*>(&value), sizeof(V));
		}

		void PutValue(std::string& out, intptr_t value)
		{
			Put(out, value);
		}

		// field by field, so the padding is written as zeros
		void PutValue(std::string& out, const BitField& value)
		{
			char bytes[sizeof(BitField)] = {};
			memcpy(bytes + offsetof(BitField, offset), &value.offset, sizeof(value.offset));
			memcpy(bytes + offsetof(BitField, bit_position), &value.bit_position, sizeof(value.bit_position));
			memcpy(bytes + offsetof(BitField, num_bits), &value.num_bits, sizeof(value.num_bits));
			memcpy(bytes + offsetof(BitField, length), &value.length, sizeof(value.length));
			out.append(bytes, sizeof(bytes));
		}

		class CacheInput
		{
		public:
			CacheInput(const char* data, size_t size) : data_(data), size_(size)
			{
			}

			template <typename V>
			bool Get(V* value)
			{
				if (size_ - pos_ < sizeof(V))
					return false;

				memcpy(value, data_ + pos_, sizeof(V));
				pos_ += sizeof(V);
				return true;
			}

			const char* Take(uint64_t size)
			{
				if (size_ - pos_ < size)
					return nullptr;

				const char* result = data_ + pos_;
				pos_ += static_cast<size_t>(size);
				return result;
			}

			bool AtEnd() const { return pos_ == size_; }

		private:
			const char* data_;
			size_t size_;
			size_t pos_{0};
		};

		template <typename T>
		void WriteTable(std::string& out, const NameTable<T>& table)
		{
			uint64_t name_bytes = 0;
			for (size_t i = 0; i < table.Size(); ++i)
				name_bytes += table.Name(i).size();

			Put(out, static_cast<uint64_t>(table.Size()));
			Put(out, name_bytes);

			for (size_t i = 0; i < table.Size(); ++i)
			{
				Put(out, static_cast<uint32_t>(table.Name(i).size()));
				PutValue(out, table.Value(i));
			}

			for (size_t i = 0; i < table.Size(); ++i)
				out += table.Name(i);
		}

		template <typename T>
		bool ReadTable(CacheInput& in, NameTable<T>* table)
		{
			uint64_t count = 0;
			uint64_t name_bytes = 0;
			if (!in.Get(&count) || !in.Get(&name_bytes) || count > 0x10000000 || name_bytes > 0xFFFFFFFF)
				return false;

			const char* records = in.Take(count * (sizeof(uint32_t) + sizeof(T)));
			const char* names = in.Take(name_bytes);
			if (records == nullptr || names == nullptr)
				return false;

			table->Reserve(static_cast<size_t>(count), static_cast<size_t>(name_bytes));

			uint64_t used = 0;
			for (uint64_t i = 0; i < count; ++i)
			{
				uint32_t size;
				T value;
				memcpy(&size, records, sizeof(size));
				memcpy(&value, records + sizeof(size), sizeof(T));
				records += sizeof(size) + sizeof(T);

				if (size > name_bytes - used || !table->TryEmplace(std::string_view(names + used, size), value))
					return false;

				used += size;
			}

			return used == name_bytes;
		}
	} // namespace

	void PdbReader::Read(const std::wstring& path, std::unordered_map<std::string, intptr_t>* offsets_dump,
	                     std::unordered_map<std::string, BitField>* bitfields_dump)
	{
		NameTable<intptr_t> offsets;
		NameTable<BitField> bitfields;
		Read(path, &offsets, &bitfields);

		for (size_t i = 0; i < offsets.Size(); ++i)
			(*offsets_dump)[std::string(offsets.Name(i))] = offsets.Value(i);

		for (size_t i = 0; i < bitfields.Size(); ++i)
			(*bitfields_dump)[std::string(bitfields.Name(i))] = bitfields.Value(i);
	}

	void PdbReader::Read(const std::wstring& path, NameTable<intptr_t>* offsets_dump,
	                     NameTable<BitField>* bitfields_dump, bool use_cache)
	{
		offsets_dump_ = offsets_dump;
		bitfields_dump_ = bitfields_dump;

		std::ifstream f{path};
		if (!f.good())
			throw std::runtime_error("Failed to open pdb file");

		IDiaDataSource* data_source;
		IDiaSession* dia_session;
		IDiaSymbol* symbol;

		try
		{
			LoadDataFromPdb(path, &data_source, &dia_session, &symbol);
		}
		catch (const std::runtime_error&)
		{
			Log::GetLog()->error("Failed to load data from pdb file ");
			throw;
		}

		std::string identity;
		if (use_cache && GetPdbIdentity(symbol, path, &identity) && LoadCache(path, identity))
		{
			Cleanup(symbol, dia_session, data_source);

			Log::GetLog()->info("Successfully read information from the PDB cache\n");
			return;
		}

		Log::GetLog()->info("Dumping structures..");
		DumpStructs(symbol);

		Log::GetLog()->info("Dumping functions..");
		session_ = dia_session;
		DumpFunctions(symbol);
		DumpOverloads();

		Log::GetLog()->info("Dumping globals..");
		DumpGlobalVariables(symbol);

		Cleanup(symbol, dia_session, data_source);

		if (!identity.empty())
			SaveCache(path, identity);

		Log::GetLog()->info("Successfully read information from PDB\n");
	}

	bool PdbReader::GetPdbIdentity(IDiaSymbol* g_symbol, const std::wstring& path, std::string* identity)
	{
		GUID guid;
		DWORD age;
		if (g_symbol->get_guid(&guid) != S_OK || g_symbol->get_age(&age) != S_OK)
			return false;

		std::error_code error;
		const uint64_t size = std::filesystem::file_size(path, error);
		if (error)
			return false;

		identity->clear();
		Put(*identity, cache_version);
		Put(*identity, guid);
		Put(*identity, age);
		Put(*identity, size);
		Put(*identity, static_cast<uint32_t>(sizeof(intptr_t)));
		Put(*identity, static_cast<uint32_t>(sizeof(BitField)));

		return true;
	}

	bool PdbReader::LoadCache(const std::wstring& path, const std::string& identity)
	{
		try
		{
			std::ifstream file(path + L".cache", std::ios::binary | std::ios::ate);
			if (!file.good())
			{
				Log::GetLog()->info("No PDB cache yet, reading the PDB");
				return false;
			}

			std::string data(static_cast<size_t>(file.tellg()), '\0');
			file.seekg(0);
			if (!file.read(data.data(), static_cast<std::streamsize>(data.size())))
				throw std::runtime_error("read failed");

			const size_t header_size = sizeof(cache_magic) + identity.size() + sizeof(uint64_t);
			if (data.size() < header_size || memcmp(data.data(), cache_magic, sizeof(cache_magic)) != 0 ||
				data.compare(sizeof(cache_magic), identity.size(), identity) != 0)
			{
				Log::GetLog()->info("PDB cache does not match the PDB, reading the PDB");
				return false;
			}

			uint64_t checksum;
			memcpy(&checksum, data.data() + header_size - sizeof(uint64_t), sizeof(uint64_t));

			CacheInput in(data.data() + header_size, data.size() - header_size);
			if (Checksum(data.data() + header_size, data.size() - header_size) == checksum &&
				ReadTable(in, offsets_dump_) && ReadTable(in, bitfields_dump_) && in.AtEnd())
				return true;

			Log::GetLog()->warn("PDB cache is damaged, reading the PDB");
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->warn("Failed to read the PDB cache - {}", error.what());
		}

		offsets_dump_->Clear();
		bitfields_dump_->Clear();
		return false;
	}

	void PdbReader::SaveCache(const std::wstring& path, const std::string& identity) const
	{
		const std::wstring cache_path = path + L".cache";
		const std::wstring temp_path = cache_path + L"." + std::to_wstring(GetCurrentProcessId()) + L".tmp";

		try
		{
			std::string payload;
			WriteTable(payload, *offsets_dump_);
			WriteTable(payload, *bitfields_dump_);

			std::string header(cache_magic, sizeof(cache_magic));
			header += identity;
			Put(header, Checksum(payload.data(), payload.size()));

			{
				std::ofstream file(temp_path, std::ios::binary | std::ios::trunc);
				file.write(header.data(), static_cast<std::streamsize>(header.size()));
				file.write(payload.data(), static_cast<std::streamsize>(payload.size()));
				file.close();

				if (!file)
					throw std::runtime_error("write failed");
			}

			if (!MoveFileExW(temp_path.c_str(), cache_path.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
				throw std::runtime_error("rename failed, error " + std::to_string(GetLastError()));

			Log::GetLog()->info("Saved the PDB cache");
		}
		catch (const std::exception& error)
		{
			DeleteFileW(temp_path.c_str());
			Log::GetLog()->warn("Failed to save the PDB cache - {}", error.what());
		}
	}

	void PdbReader::LoadDataFromPdb(const std::wstring& path, IDiaDataSource** dia_source, IDiaSession** session,
	                                IDiaSymbol** symbol)
	{
		const std::string current_dir = Tools::GetCurrentDir();

		const std::string lib_path = current_dir + "\\msdia140.dll";
		const HMODULE h_module = LoadLibraryA(lib_path.c_str());
		if (h_module == nullptr)
		{
			throw std::runtime_error("Failed to load msdia140.dll. Error code - " + std::to_string(GetLastError()));
		}

		const auto dll_get_class_object = reinterpret_cast<HRESULT(WINAPI*)(REFCLSID, REFIID, LPVOID)>(GetProcAddress(
			h_module, "DllGetClassObject"));
		if (dll_get_class_object == nullptr)
		{
			throw std::runtime_error("Can't find DllGetClassObject. Error code - " + std::to_string(GetLastError()));
		}

		IClassFactory* class_factory;
		HRESULT hr = dll_get_class_object(__uuidof(DiaSource), IID_IClassFactory, &class_factory);
		if (FAILED(hr))
		{
			throw std::runtime_error("DllGetClassObject has failed. Error code - " + std::to_string(GetLastError()));
		}

		hr = class_factory->CreateInstance(nullptr, __uuidof(IDiaDataSource), reinterpret_cast<void**>(dia_source));
		if (FAILED(hr))
		{
			class_factory->Release();
			throw std::runtime_error("CreateInstance has failed. Error code - " + std::to_string(GetLastError()));
		}

		hr = (*dia_source)->loadDataFromPdb(path.c_str());
		if (FAILED(hr))
		{
			class_factory->Release();
			throw std::runtime_error("loadDataFromPdb has failed. HRESULT - " + std::to_string(hr));
		}

		// Open a session for querying symbols

		hr = (*dia_source)->openSession(session);
		if (FAILED(hr))
		{
			class_factory->Release();
			throw std::runtime_error("openSession has failed. HRESULT - " + std::to_string(hr));
		}

		// Retrieve a reference to the global scope

		hr = (*session)->get_globalScope(symbol);
		if (hr != S_OK)
		{
			class_factory->Release();
			throw std::runtime_error("get_globalScope has failed. HRESULT - " + std::to_string(hr));
		}

		class_factory->Release();
	}

	void PdbReader::DumpStructs(IDiaSymbol* g_symbol)
	{
		IDiaSymbol* symbol = nullptr;

		CComPtr<IDiaEnumSymbols> enum_symbols;
		if (FAILED(g_symbol->findChildren(SymTagUDT, nullptr, nsNone, &enum_symbols)))
			throw std::runtime_error("Failed to find symbols");

		ULONG celt = 0;
		while (SUCCEEDED(enum_symbols->Next(1, &symbol, &celt)) && celt == 1)
		{
			CComPtr<IDiaSymbol> sym(symbol);

			const uint32_t sym_id = GetSymbolId(symbol);
			if (visited_.find(sym_id) != visited_.end())
				continue;

			visited_.insert(sym_id);

			std::string str_name = GetSymbolNameString(sym);
			if (str_name.empty())
				continue;

			DumpType(sym, str_name, 0);
		}
	}

	void PdbReader::DumpFunctions(IDiaSymbol* g_symbol)
	{
		IDiaSymbol* symbol;

		CComPtr<IDiaEnumSymbols> enum_symbols;
		if (FAILED(g_symbol->findChildren(SymTagFunction, nullptr, nsNone, &enum_symbols)))
			throw std::runtime_error("Failed to find symbols");

		ULONG celt = 0;
		while (SUCCEEDED(enum_symbols->Next(1, &symbol, &celt)) && celt == 1)
		{
			CComPtr<IDiaSymbol> sym(symbol);

			DWORD sym_tag_type;
			if (sym->get_symTag(&sym_tag_type) != S_OK)
				continue;

			const uint32_t sym_id = GetSymbolId(sym);
			if (visited_.find(sym_id) != visited_.end())
				continue;

			visited_.insert(sym_id);

			std::string str_name = GetSymbolNameString(sym);
			if (str_name.empty())
				continue;

			DWORD offset;
			if (sym->get_relativeVirtualAddress(&offset) != S_OK)
				continue;

			// Filter out some useless functions
			if (str_name.find('`') != std::string::npos)
				continue;

			// Check if it's a member function
			std::string key = str_name.find(':') != std::string::npos
				                  ? ReplaceString(str_name, "::", ".")
				                  : "Global." + str_name;

			const size_t entry = offsets_dump_->Assign(key, offset);

			const auto first = functions_.try_emplace(entry, sym_id, offset).first;
			if (first->second.second != offset)
			{
				auto& ids = overloads_[std::string(offsets_dump_->Name(entry))];
				if (ids.empty())
					ids.push_back(first->second.first);

				ids.push_back(sym_id);
			}
		}
	}

	void PdbReader::DumpOverloads()
	{
		// the plain name keeps the last overload, each overload also gets "Name(Args)" with its own address
		size_t added = 0;

		for (const auto& [name, ids] : overloads_)
		{
			std::vector<std::pair<std::string, DWORD>> keys;
			std::unordered_set<DWORD> addresses;

			for (const DWORD id : ids)
			{
				CComPtr<IDiaSymbol> sym;
				if (session_->symbolById(id, &sym) != S_OK || sym == nullptr)
					continue;

				DWORD offset;
				if (sym->get_relativeVirtualAddress(&offset) != S_OK || !addresses.insert(offset).second)
					continue;

				keys.emplace_back(Offsets::NormalizeName(name + GetSignature(sym)), offset);
			}

			// same signature at different addresses: number them in pdb order
			std::unordered_map<std::string, int> counts;
			for (const auto& key : keys)
				++counts[key.first];

			std::unordered_map<std::string, int> numbers;
			for (auto& [key, offset] : keys)
			{
				if (counts[key] > 1)
					key += "#" + std::to_string(++numbers[key]);

				if (offsets_dump_->TryEmplace(key, offset))
					++added;
			}
		}

		Log::GetLog()->info("{} overloaded functions, {} overload keys", overloads_.size(), added);

		functions_.clear();
		overloads_.clear();
	}

	void PdbReader::DumpGlobalVariables(IDiaSymbol* g_symbol)
	{
		IDiaSymbol* symbol;

		CComPtr<IDiaEnumSymbols> enum_symbols;
		if (FAILED(g_symbol->findChildren(SymTagData, nullptr, nsNone, &enum_symbols)))
			throw std::runtime_error("Failed to find symbols");

		ULONG celt = 0;
		while (SUCCEEDED(enum_symbols->Next(1, &symbol, &celt)) && celt == 1)
		{
			CComPtr<IDiaSymbol> sym(symbol);

			const uint32_t sym_id = GetSymbolId(symbol);
			if (visited_.find(sym_id) != visited_.end())
				continue;

			visited_.insert(sym_id);

			std::string str_name = GetSymbolNameString(sym);
			if (str_name.empty())
				continue;

			DWORD sym_tag;
			if (sym->get_symTag(&sym_tag) != S_OK)
				continue;

			// rva 0 is an absolute symbol with no section
			DWORD offset;
			if (sym->get_relativeVirtualAddress(&offset) != S_OK || offset == 0)
				continue;

			offsets_dump_->Assign("Global." + str_name, offset);
		}
	}

	void PdbReader::DumpType(IDiaSymbol* symbol, const std::string& structure, int indent) const
	{
		CComPtr<IDiaEnumSymbols> enum_children;
		IDiaSymbol* symbol_child;
		DWORD sym_tag;
		ULONG celt = 0;

		if (indent > 5)
			return;

		if (symbol->get_symTag(&sym_tag) != S_OK)
			return;

		switch (sym_tag)
		{
		case SymTagData:
			DumpData(symbol, structure);
			break;
		case SymTagEnum:
		case SymTagUDT:
			// nested types are dumped under their own name
			if (indent > 0)
				break;

			if (SUCCEEDED(symbol->findChildren(SymTagNull, nullptr, nsNone, &enum_children)))
			{
				while (SUCCEEDED(enum_children->Next(1, &symbol_child, &celt)) && celt == 1)
				{
					CComPtr<IDiaSymbol> sym_child(symbol_child);

					DumpType(sym_child, structure, indent + 2);
				}
			}
			break;
		default:
			break;
		}
	}

	void PdbReader::DumpData(IDiaSymbol* symbol, const std::string& structure) const
	{
		DWORD loc_type;
		if (symbol->get_locationType(&loc_type) != S_OK)
			return;

		if (loc_type != LocIsThisRel && loc_type != LocIsBitField)
			return;

		CComPtr<IDiaSymbol> type;
		if (symbol->get_type(&type) != S_OK)
			return;

		if (type == nullptr)
			return;

		LONG offset;
		if (symbol->get_offset(&offset) != S_OK)
			return;

		std::string str_name = GetSymbolNameString(symbol);
		if (str_name.empty())
			return;

		if (loc_type == LocIsBitField)
		{
			DWORD bit_position;
			if (symbol->get_bitPosition(&bit_position) != S_OK)
				return;

			ULONGLONG num_bits;
			if (symbol->get_length(&num_bits) != S_OK)
				return;

			ULONGLONG length;
			if (type->get_length(&length) != S_OK)
				return;

			const BitField bit_field{static_cast<DWORD64>(offset), bit_position, num_bits, length};

			bitfields_dump_->Assign(structure + "." + str_name, bit_field);
		}
		else if (loc_type == LocIsThisRel)
		{
			offsets_dump_->Assign(structure + "." + str_name, offset);
		}
	}

	std::string PdbReader::GetSymbolNameString(IDiaSymbol* symbol)
	{
		BSTR str = nullptr;

		std::string name;

		HRESULT hr = symbol->get_name(&str);
		if (hr != S_OK)
			return name;

		if (str != nullptr)
		{
			name = Tools::Utf8Encode(str);
		}

		SysFreeString(str);

		return name;
	}

	std::string PdbReader::GetTypeName(IDiaSymbol* type, int depth)
	{
		if (type == nullptr || depth > 16)
			return "?";

		DWORD sym_tag;
		if (type->get_symTag(&sym_tag) != S_OK)
			return "?";

		BOOL is_const = FALSE;
		BOOL is_volatile = FALSE;
		type->get_constType(&is_const);
		type->get_volatileType(&is_volatile);

		std::string cv;
		if (is_const)
			cv += "const ";
		if (is_volatile)
			cv += "volatile ";

		switch (sym_tag)
		{
		case SymTagUDT:
		case SymTagEnum:
		case SymTagTypedef:
			return cv + GetSymbolNameString(type);
		case SymTagBaseType:
			{
				DWORD base_type = btNoType;
				ULONGLONG length = 0;
				type->get_baseType(&base_type);
				type->get_length(&length);

				switch (base_type)
				{
				case btVoid: return cv + "void";
				case btChar: return cv + "char";
				case btWChar: return cv + "wchar_t";
				case btChar8: return cv + "char8_t";
				case btChar16: return cv + "char16_t";
				case btChar32: return cv + "char32_t";
				case btBool: return cv + "bool";
				case btLong: return cv + "long";
				case btULong: return cv + "unsigned long";
				case btHresult: return cv + "HRESULT";
				case btFloat: return cv + (length == 8 ? "double" : "float");
				case btInt:
					return cv + (length == 1 ? "signed char" : length == 2 ? "short" : length == 8 ? "__int64" : "int");
				case btUInt:
					return cv + (length == 1
						             ? "unsigned char"
						             : length == 2
						             ? "unsigned short"
						             : length == 8
						             ? "unsigned __int64"
						             : "unsigned int");
				case btNoType: return cv + "...";
				default: return cv + "?";
				}
			}
		case SymTagPointerType:
			{
				CComPtr<IDiaSymbol> inner;
				type->get_type(&inner);

				BOOL is_reference = FALSE;
				BOOL is_rvalue_reference = FALSE;
				type->get_reference(&is_reference);
				type->get_RValueReference(&is_rvalue_reference);

				std::string name = GetTypeName(inner, depth + 1) + (is_rvalue_reference
					                                                    ? "&&"
					                                                    : is_reference
					                                                    ? "&"
					                                                    : "*");
				if (is_const)
					name += "const";
				if (is_volatile)
					name += "volatile";

				return name;
			}
		case SymTagArrayType:
			{
				CComPtr<IDiaSymbol> inner;
				type->get_type(&inner);

				DWORD count = 0;
				type->get_count(&count);

				return GetTypeName(inner, depth + 1) + "[" + std::to_string(count) + "]";
			}
		case SymTagFunctionType:
			{
				CComPtr<IDiaSymbol> return_type;
				type->get_type(&return_type);

				return GetTypeName(return_type, depth + 1) + GetArguments(type, depth + 1);
			}
		default:
			return cv + "?";
		}
	}

	std::string PdbReader::GetArguments(IDiaSymbol* function_type, int depth)
	{
		std::string args;

		CComPtr<IDiaEnumSymbols> enum_args;
		if (SUCCEEDED(function_type->findChildren(SymTagFunctionArgType, nullptr, nsNone, &enum_args)))
		{
			IDiaSymbol* arg;
			ULONG celt = 0;
			while (SUCCEEDED(enum_args->Next(1, &arg, &celt)) && celt == 1)
			{
				CComPtr<IDiaSymbol> sym_arg(arg);
				CComPtr<IDiaSymbol> arg_type;
				sym_arg->get_type(&arg_type);

				if (!args.empty())
					args += ",";
				args += GetTypeName(arg_type, depth);
			}
		}

		return "(" + args + ")";
	}

	std::string PdbReader::GetSignature(IDiaSymbol* function)
	{
		CComPtr<IDiaSymbol> type;
		if (function->get_type(&type) != S_OK || type == nullptr)
			return "(?)";

		std::string signature = GetArguments(type, 0);

		CComPtr<IDiaSymbol> this_type;
		if (type->get_objectPointerType(&this_type) == S_OK && this_type != nullptr)
		{
			CComPtr<IDiaSymbol> object_type;
			BOOL is_const = FALSE;
			if (this_type->get_type(&object_type) == S_OK && object_type != nullptr &&
				object_type->get_constType(&is_const) == S_OK && is_const)
				signature += "const";
		}

		return signature;
	}

	uint32_t PdbReader::GetSymbolId(IDiaSymbol* symbol)
	{
		DWORD id;
		symbol->get_symIndexId(&id);

		return id;
	}

	void PdbReader::Cleanup(IDiaSymbol* symbol, IDiaSession* session, IDiaDataSource* source)
	{
		if (symbol != nullptr)
			symbol->Release();
		if (session != nullptr)
			session->Release();
		if (source != nullptr)
			source->Release();

		CoUninitialize();
	}
} // namespace API
