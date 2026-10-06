#include "Offsets.h"

#include <atomic>
#include <intrin.h>
#include <unordered_set>

#include <API/Fields.h>
#include "Logger/Logger.h"

#include "Helpers.h"

namespace
{
	constexpr size_t missing_block_size = 0x10000;
	constexpr size_t max_missing_blocks = 256;

	alignas(16) char shared_missing_block[missing_block_size];

	bool IsNameChar(char c)
	{
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
	}

	// out needs name.size() chars
	size_t NormalizeInto(std::string_view name, char* out)
	{
		size_t size = 0;

		bool space = false;
		for (const char c : name)
		{
			if (c == ' ' || c == '\t')
			{
				space = size != 0;
				continue;
			}

			if (space && IsNameChar(out[size - 1]) && IsNameChar(c))
				out[size++] = ' ';

			space = false;
			out[size++] = c;
		}

		return size;
	}

	HMODULE GetApiModule()
	{
		static const HMODULE module = API::GetModuleFromAddress(reinterpret_cast<const void*>(&GetApiModule));
		return module;
	}

	bool IsApiAddress(const void* address)
	{
		static const auto range = []
		{
			const auto* image = reinterpret_cast<const BYTE*>(GetApiModule());
			const auto* nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(
				image + reinterpret_cast<const IMAGE_DOS_HEADER*>(image)->e_lfanew);
			return std::pair<const BYTE*, const BYTE*>(image, image + nt_headers->OptionalHeader.SizeOfImage);
		}();

		return address >= range.first && address < range.second;
	}

	std::mutex reported_mutex;
	std::unordered_set<std::string> reported;

	// bumped on every dll load and unload
	std::atomic<uint32_t> module_generation{1};
	bool watching_modules = false;

	VOID CALLBACK OnDllNotification(ULONG, const void*, PVOID)
	{
		module_generation.fetch_add(1, std::memory_order_relaxed);
	}

	bool WatchModules()
	{
		using Callback = VOID(CALLBACK*)(ULONG, const void*, PVOID);
		using Register = LONG(NTAPI*)(ULONG, Callback, PVOID, PVOID*);

		const HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
		const auto register_notification = ntdll != nullptr
			                                   ? reinterpret_cast<Register>(GetProcAddress(
				                                   ntdll, "LdrRegisterDllNotification"))
			                                   : nullptr;

		PVOID cookie = nullptr;
		return register_notification != nullptr && register_notification(0, &OnDllNotification, nullptr, &cookie) >= 0;
	}

	// unknown names this thread already reported per call site
	struct ReportedMiss
	{
		const void* call_site;
		const char* name;
		void* storage;
		uint32_t size;
		uint32_t hash;
		uint32_t generation;
	};

	constexpr size_t reported_miss_sets = 16;
	constexpr size_t reported_miss_ways = 4;

	thread_local ReportedMiss reported_misses[reported_miss_sets * reported_miss_ways];
	thread_local uint32_t reported_miss_next;

	// first and last eight bytes, the name is compared in full anyway
	uint32_t ReportedMissHash(std::string_view name)
	{
		uint64_t word = name.size();
		if (name.size() >= 8)
		{
			uint64_t first, last;
			memcpy(&first, name.data(), 8);
			memcpy(&last, name.data() + name.size() - 8, 8);
			word ^= first ^ (last * 0x9E3779B97F4A7C15ULL);
		}
		else
		{
			for (size_t i = 0; i < name.size(); ++i)
				word ^= static_cast<uint64_t>(static_cast<unsigned char>(name[i])) << (i * 8 + 8);
		}

		word *= 0xBF58476D1CE4E5B9ULL;
		return static_cast<uint32_t>(word >> 32);
	}

	ReportedMiss* FindReportedMiss(const void* call_site, std::string_view name, uint32_t hash, uint32_t generation)
	{
		const size_t set = (hash ^ static_cast<uint32_t>(reinterpret_cast<uintptr_t>(call_site) >> 2)) %
			reported_miss_sets;

		ReportedMiss* ways = &reported_misses[set * reported_miss_ways];
		for (size_t i = 0; i < reported_miss_ways; ++i)
		{
			ReportedMiss& entry = ways[i];
			if (entry.call_site == call_site && entry.hash == hash && entry.generation == generation
				&& entry.size == name.size() && memcmp(entry.name, name.data(), name.size()) == 0)
			{
				return &entry;
			}
		}

		return nullptr;
	}

	void AddReportedMiss(const void* call_site, std::string_view name, uint32_t hash, uint32_t generation,
	                     void* storage)
	{
		const size_t set = (hash ^ static_cast<uint32_t>(reinterpret_cast<uintptr_t>(call_site) >> 2)) %
			reported_miss_sets;

		ReportedMiss* ways = &reported_misses[set * reported_miss_ways];
		ReportedMiss* slot = &ways[reported_miss_next++ % reported_miss_ways];
		for (size_t i = 0; i < reported_miss_ways; ++i)
		{
			if (ways[i].generation != generation)
			{
				slot = &ways[i];
				break;
			}
		}

		*slot = {call_site, name.data(), storage, static_cast<uint32_t>(name.size()), hash, generation};
	}
} // namespace

namespace API
{
	void ReportDeprecatedUse(std::string_view api_name, HMODULE caller)
	{
		std::string key = std::to_string(reinterpret_cast<uintptr_t>(caller));
		key += '|';
		key += api_name;

		{
			std::lock_guard<std::mutex> lock(reported_mutex);
			if (!reported.insert(std::move(key)).second)
				return;
		}

		if (caller != nullptr && caller != GetApiModule() && caller != GetModuleHandleW(nullptr))
		{
			Log::GetLog()->warn(
				"[ArkApi] Plugin '{}' uses '{}', which is deprecated or missing in this game build - plugin needs an update",
				GetModuleName(caller), api_name);
			return;
		}

		const char* who = caller == nullptr
			                  ? "An unknown module"
			                  : caller == GetApiModule()
			                  ? "ArkApi (version.dll)"
			                  : "The game executable";

		Log::GetLog()->warn("[ArkApi] {} uses '{}', which is deprecated or missing in this game build", who, api_name);
	}

	void LogDeprecatedUse(const char* api_name, HMODULE caller)
	{
		if (api_name != nullptr)
			ReportDeprecatedUse(api_name, caller);
	}

	Offsets::Offsets()
		: module_base_(reinterpret_cast<DWORD64>(GetModuleHandle(nullptr)))
	{
		watching_modules = WatchModules();

		// xor eax, eax; xorps xmm0, xmm0; ret
		constexpr BYTE stub[] = {0x33, 0xC0, 0x0F, 0x57, 0xC0, 0xC3};

		void* page = VirtualAlloc(nullptr, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		if (page != nullptr)
		{
			memset(page, 0xCC, 4096);
			memcpy(page, stub, sizeof(stub));

			DWORD old_protect;
			if (VirtualProtect(page, 4096, PAGE_EXECUTE_READ, &old_protect))
			{
				FlushInstructionCache(GetCurrentProcess(), page, 4096);
				missing_function_stub_ = page;
			}
		}
	}

	Offsets& Offsets::Get()
	{
		static Offsets instance;
		return instance;
	}

	void Offsets::Init(NameTable<intptr_t>&& offsets_dump, NameTable<BitField>&& bitfields_dump)
	{
		offsets_dump_ = std::move(offsets_dump);
		offsets_dump_.ShrinkToFit();

		bitfields_dump_ = std::move(bitfields_dump);
		bitfields_dump_.ShrinkToFit();
	}

	void Offsets::Init(std::unordered_map<std::string, intptr_t>&& offsets_dump,
	                   std::unordered_map<std::string, BitField>&& bitfields_dump)
	{
		NameTable<intptr_t> offsets;
		for (const auto& [name, value] : offsets_dump)
			offsets.Assign(name, value);

		NameTable<BitField> bitfields;
		for (const auto& [name, value] : bitfields_dump)
			bitfields.Assign(name, value);

		offsets_dump.clear();
		bitfields_dump.clear();

		Init(std::move(offsets), std::move(bitfields));
	}

	std::string Offsets::NormalizeName(std::string_view name)
	{
		std::string result(name.size(), '\0');
		result.resize(NormalizeInto(name, result.data()));

		return result;
	}

	const intptr_t* Offsets::FindValue(std::string_view name) const
	{
		const intptr_t* value = offsets_dump_.Find(name);
		if (value != nullptr)
			return value;

		// overload keys may be written with different spacing
		if (name.find('(') == std::string_view::npos)
			return nullptr;

		char buffer[512];
		std::string long_name;
		char* out = buffer;
		if (name.size() > sizeof(buffer))
		{
			long_name.resize(name.size());
			out = long_name.data();
		}

		const std::string_view normalized(out, NormalizeInto(name, out));
		if (normalized == name)
			return nullptr;

		return offsets_dump_.Find(normalized);
	}

	bool Offsets::FindOffset(std::string_view name, intptr_t* offset) const
	{
		const intptr_t* value = FindValue(name);
		if (value == nullptr)
			return false;

		if (offset != nullptr)
			*offset = *value;

		return true;
	}

	bool Offsets::FindBitField(std::string_view name, BitField* bit_field) const
	{
		const BitField* value = bitfields_dump_.Find(name);
		if (value == nullptr)
			return false;

		if (bit_field != nullptr)
			*bit_field = *value;

		return true;
	}

	__declspec(noinline) const void* Offsets::CallerOutsideApi()
	{
		// called through Base.cpp, the plugin is a few frames up
		void* frames[4];
		const USHORT count = RtlCaptureStackBackTrace(1, 4, frames, nullptr);
		for (USHORT i = 0; i < count; ++i)
		{
			if (!IsApiAddress(frames[i]))
				return frames[i];
		}

		return reinterpret_cast<const void*>(&GetApiModule);
	}

	const void* Offsets::PluginCallSite(const void* call_site)
	{
		return call_site != nullptr && !IsApiAddress(call_site) ? call_site : nullptr;
	}

	void* Offsets::ReportMissing(std::string_view name, bool storage, const void* caller)
	{
		const bool cached = watching_modules;
		const uint32_t hash = cached ? ReportedMissHash(name) : 0;
		const uint32_t generation = cached ? module_generation.load(std::memory_order_acquire) : 0;

		ReportedMiss* reported_miss = cached ? FindReportedMiss(caller, name, hash, generation) : nullptr;
		if (reported_miss != nullptr)
		{
			if (!storage)
				return nullptr;

			if (reported_miss->storage != nullptr)
				return reported_miss->storage;
		}
		else
		{
			ReportDeprecatedUse(name, GetModuleFromAddress(caller));

			if (!storage && !cached)
				return nullptr;
		}

		std::lock_guard<std::mutex> lock(missing_mutex_);

		auto iter = missing_.find(name);
		if (iter == missing_.end())
			iter = missing_.emplace(std::string(name), nullptr).first;

		if (storage && iter->second == nullptr)
		{
			void* block = nullptr;
			if (missing_blocks_ < max_missing_blocks)
			{
				block = VirtualAlloc(nullptr, missing_block_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
				if (block != nullptr)
					++missing_blocks_;
			}

			iter->second = block != nullptr ? block : shared_missing_block;
		}

		if (reported_miss != nullptr)
			reported_miss->storage = iter->second;
		else if (cached)
			AddReportedMiss(caller, iter->first, hash, generation, iter->second);

		return storage ? iter->second : nullptr;
	}

	DWORD64 Offsets::GetAddress(const void* base, std::string_view name, const void* caller)
	{
		const intptr_t* value = FindValue(name);
		if (value == nullptr)
			return reinterpret_cast<DWORD64>(ReportMissing(name, true, caller != nullptr ? caller : CallerOutsideApi()));

		return reinterpret_cast<DWORD64>(base) + static_cast<DWORD64>(*value);
	}

	LPVOID Offsets::GetAddress(std::string_view name, const void* caller)
	{
		const intptr_t* value = FindValue(name);
		if (value == nullptr)
		{
			ReportMissing(name, false, caller != nullptr ? caller : CallerOutsideApi());
			return nullptr;
		}

		return reinterpret_cast<LPVOID>(module_base_ + static_cast<DWORD64>(*value));
	}

	LPVOID Offsets::GetDataAddress(std::string_view name, const void* caller)
	{
		return GetAddress(name, caller);
	}

	BitField Offsets::GetBitField(const void* base, std::string_view name, const void* caller)
	{
		return GetBitFieldInternal(base, name, false, caller);
	}

	BitField Offsets::GetBitField(LPVOID base, std::string_view name, const void* caller)
	{
		return GetBitFieldInternal(base, name, false, caller);
	}

	DWORD64 Offsets::GetAddress(const void* base, const std::string& name, const void* call_site)
	{
		const intptr_t* value = FindValue(name);
		if (value == nullptr)
		{
			// offset 0, plugins test with addr <= base
			const void* caller = PluginCallSite(call_site);
			ReportMissing(name, false, caller != nullptr ? caller : CallerOutsideApi());
			return reinterpret_cast<DWORD64>(base);
		}

		return reinterpret_cast<DWORD64>(base) + static_cast<DWORD64>(*value);
	}

	LPVOID Offsets::GetAddress(const std::string& name, const void* call_site)
	{
		const intptr_t* value = FindValue(name);
		if (value == nullptr)
		{
			const void* caller = PluginCallSite(call_site);
			ReportMissing(name, false, caller != nullptr ? caller : CallerOutsideApi());
			return missing_function_stub_;
		}

		return reinterpret_cast<LPVOID>(module_base_ + static_cast<DWORD64>(*value));
	}

	LPVOID Offsets::GetDataAddress(const std::string& name, const void* call_site)
	{
		const intptr_t* value = FindValue(name);
		if (value == nullptr)
		{
			const void* caller = PluginCallSite(call_site);
			return ReportMissing(name, true, caller != nullptr ? caller : CallerOutsideApi());
		}

		return reinterpret_cast<LPVOID>(module_base_ + static_cast<DWORD64>(*value));
	}

	BitField Offsets::GetBitField(const void* base, const std::string& name, const void* call_site)
	{
		return GetBitFieldInternal(base, name, true, PluginCallSite(call_site));
	}

	BitField Offsets::GetBitField(LPVOID base, const std::string& name, const void* call_site)
	{
		return GetBitFieldInternal(base, name, true, PluginCallSite(call_site));
	}

	bool Offsets::IsMissingFunctionStub(LPVOID address) const
	{
		return address != nullptr && address == missing_function_stub_;
	}

	BitField Offsets::GetBitFieldInternal(const void* base, std::string_view name, bool legacy, const void* caller)
	{
		const BitField* value = bitfields_dump_.Find(name);
		if (value == nullptr)
		{
			// num_bits 0, accessors skip it
			// null base: offset only
			void* storage = ReportMissing(name, true, caller != nullptr ? caller : CallerOutsideApi());
			if (legacy && base == nullptr)
				storage = nullptr;

			return BitField{reinterpret_cast<DWORD64>(storage), 0, 0, 0};
		}

		const auto& bf = *value;
		auto cf = BitField();
		cf.bit_position = bf.bit_position;
		cf.length = bf.length;
		cf.num_bits = bf.num_bits;
		cf.offset = reinterpret_cast<DWORD64>(base) + static_cast<DWORD64>(bf.offset);

		return cf;
	}
} // namespace API

__declspec(noinline) DWORD64 GetAddress(const void* base, const char* name)
{
	return API::Offsets::Get().GetAddress(base, std::string_view(name), _ReturnAddress());
}

__declspec(noinline) LPVOID GetAddress(const char* name)
{
	return API::Offsets::Get().GetAddress(std::string_view(name), _ReturnAddress());
}

__declspec(noinline) LPVOID GetDataAddress(const char* name)
{
	return API::Offsets::Get().GetDataAddress(std::string_view(name), _ReturnAddress());
}

__declspec(noinline) BitField GetBitField(const void* base, const char* name)
{
	return API::Offsets::Get().GetBitField(base, std::string_view(name), _ReturnAddress());
}

__declspec(noinline) BitField GetBitField(LPVOID base, const char* name)
{
	return API::Offsets::Get().GetBitField(base, std::string_view(name), _ReturnAddress());
}

bool FindNativeOffset(const char* name, intptr_t* offset)
{
	return API::Offsets::Get().FindOffset(name, offset);
}

bool FindNativeBitField(const char* name, BitField* bit_field)
{
	return API::Offsets::Get().FindBitField(name, bit_field);
}
