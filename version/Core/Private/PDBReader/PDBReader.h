#pragma once

#include <dia2.h>
#include <map>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "json.hpp"

#include <API/Fields.h>

#include "../Offsets.h"

namespace API
{
	class PdbReader
	{
	public:
		PdbReader() = default;
		~PdbReader() = default;

		// use_cache: load/save <pdb>.cache when the pdb matches
		void Read(const std::wstring& path, NameTable<intptr_t>* offsets_dump, NameTable<BitField>* bitfields_dump,
		          bool use_cache = false);
		void Read(const std::wstring& path, std::unordered_map<std::string, intptr_t>* offsets_dump,
		          std::unordered_map<std::string, BitField>* bitfields_dump);

	private:
		static void LoadDataFromPdb(const std::wstring& /*path*/, IDiaDataSource** /*dia_source*/, IDiaSession**
		                            /*session*/, IDiaSymbol** /*symbol*/);

		void DumpStructs(IDiaSymbol* /*g_symbol*/);
		void DumpFunctions(IDiaSymbol* /*g_symbol*/);
		void DumpOverloads();
		void DumpGlobalVariables(IDiaSymbol* /*g_symbol*/);
		void DumpType(IDiaSymbol* /*symbol*/, const std::string& /*structure*/, int /*indent*/) const;
		void DumpData(IDiaSymbol* /*symbol*/, const std::string& /*structure*/) const;

		static std::string GetSymbolNameString(IDiaSymbol* /*symbol*/);
		static std::string GetTypeName(IDiaSymbol* /*type*/, int /*depth*/);
		static std::string GetArguments(IDiaSymbol* /*function_type*/, int /*depth*/);
		static std::string GetSignature(IDiaSymbol* /*function*/);
		static uint32_t GetSymbolId(IDiaSymbol* /*symbol*/);
		static bool GetPdbIdentity(IDiaSymbol* /*g_symbol*/, const std::wstring& /*path*/, std::string* /*identity*/);
		bool LoadCache(const std::wstring& /*path*/, const std::string& /*identity*/);
		void SaveCache(const std::wstring& /*path*/, const std::string& /*identity*/) const;
		static void Cleanup(IDiaSymbol* /*symbol*/, IDiaSession* /*session*/, IDiaDataSource* /*source*/);

		NameTable<intptr_t>* offsets_dump_{nullptr};
		NameTable<BitField>* bitfields_dump_{nullptr};

		std::unordered_set<uint32_t> visited_;

		IDiaSession* session_{nullptr};

		// first address per function key, and all addresses of overloaded names
		std::unordered_map<size_t, std::pair<DWORD, DWORD>> functions_;
		std::map<std::string, std::vector<DWORD>> overloads_;
	};
} // namespace API
