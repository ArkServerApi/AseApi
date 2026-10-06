#pragma once

#include <API/Base.h>

#include <cstring>
#include <mutex>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace API
{
	struct NameHash
	{
		using is_transparent = void;

		size_t operator()(std::string_view name) const noexcept
		{
			return std::hash<std::string_view>{}(name);
		}
	};

	template <typename T>
	using NameMap = std::unordered_map<std::string, T, NameHash, std::equal_to<>>;

	// names in one contiguous arena, open addressing index. entries are never removed
	template <typename T>
	class NameTable
	{
	public:
		// eight bytes at a time
		static uint32_t Hash(std::string_view name) noexcept
		{
			const char* data = name.data();
			size_t size = name.size();

			uint64_t hash = 0x9E3779B97F4A7C15ULL ^ size;
			for (; size >= 8; data += 8, size -= 8)
			{
				uint64_t word;
				memcpy(&word, data, 8);
				hash = (hash ^ word) * 0xBF58476D1CE4E5B9ULL;
				hash ^= hash >> 31;
			}

			if (size != 0)
			{
				uint64_t word = 0;
				for (size_t i = 0; i < size; ++i)
					word |= static_cast<uint64_t>(static_cast<unsigned char>(data[i])) << (i * 8);

				hash = (hash ^ word) * 0xBF58476D1CE4E5B9ULL;
				hash ^= hash >> 31;
			}

			hash *= 0x94D049BB133111EBULL;
			hash ^= hash >> 29;

			return static_cast<uint32_t>(hash ^ (hash >> 32));
		}

		size_t Size() const { return entries_.size(); }
		std::string_view Name(size_t index) const { return {names_.data() + entries_[index].name, entries_[index].size}; }
		const T& Value(size_t index) const { return entries_[index].value; }

		const T* Find(std::string_view name) const
		{
			const size_t index = FindIndex(name, Hash(name));
			return index != npos ? &entries_[index].value : nullptr;
		}

		// inserts or overwrites, returns the entry index
		size_t Assign(std::string_view name, const T& value)
		{
			const auto [index, inserted] = Emplace(name, value);
			if (!inserted)
				entries_[index].value = value;

			return index;
		}

		bool TryEmplace(std::string_view name, const T& value)
		{
			return Emplace(name, value).second;
		}

		void Reserve(size_t count, size_t name_bytes)
		{
			entries_.reserve(count);
			names_.reserve(name_bytes);
			Rehash(count);
		}

		void ShrinkToFit()
		{
			entries_.shrink_to_fit();
			names_.shrink_to_fit();
		}

		void Clear()
		{
			entries_ = {};
			names_ = {};
			slots_ = {};
		}

	private:
		static constexpr size_t npos = ~size_t(0);

		struct Entry
		{
			uint32_t name;
			uint32_t size;
			T value;
		};

		size_t FindIndex(std::string_view name, uint32_t hash) const
		{
			if (slots_.empty())
				return npos;

			const size_t mask = slots_.size() - 1;
			for (size_t slot = hash & mask;; slot = (slot + 1) & mask)
			{
				const uint64_t value = slots_[slot];
				if (value == 0)
					return npos;

				const size_t index = static_cast<uint32_t>(value) - 1;
				if (static_cast<uint32_t>(value >> 32) == hash && Name(index) == name)
					return index;
			}
		}

		std::pair<size_t, bool> Emplace(std::string_view name, const T& value)
		{
			const uint32_t hash = Hash(name);
			const size_t found = FindIndex(name, hash);
			if (found != npos)
				return {found, false};

			if ((entries_.size() + 1) * 4 > slots_.size() * 3)
				Rehash(entries_.size() + 1);

			const size_t index = entries_.size();
			entries_.push_back({static_cast<uint32_t>(names_.size()), static_cast<uint32_t>(name.size()), value});
			names_.insert(names_.end(), name.begin(), name.end());
			Insert(hash, index);

			return {index, true};
		}

		void Insert(uint32_t hash, size_t index)
		{
			const size_t mask = slots_.size() - 1;
			size_t slot = hash & mask;
			while (slots_[slot] != 0)
				slot = (slot + 1) & mask;

			slots_[slot] = (static_cast<uint64_t>(hash) << 32) | (index + 1);
		}

		void Rehash(size_t count)
		{
			size_t size = 16;
			while (count * 4 > size * 3)
				size *= 2;

			if (size <= slots_.size())
				return;

			slots_.assign(size, 0);
			for (size_t index = 0; index < entries_.size(); ++index)
				Insert(Hash(Name(index)), index);
		}

		std::vector<char> names_;
		std::vector<Entry> entries_;
		std::vector<uint64_t> slots_;
	};

	// logs once per module and name that the module uses something this game build does not have
	void ReportDeprecatedUse(std::string_view api_name, HMODULE caller);

	class Offsets
	{
	public:
		static Offsets& Get();

		Offsets(const Offsets&) = delete;
		Offsets(Offsets&&) = delete;
		Offsets& operator=(const Offsets&) = delete;
		Offsets& operator=(Offsets&&) = delete;

		void Init(NameTable<intptr_t>&& offsets_dump, NameTable<BitField>&& bitfields_dump);
		void Init(std::unordered_map<std::string, intptr_t>&& offsets_dump,
		          std::unordered_map<std::string, BitField>&& bitfields_dump);

		const NameTable<intptr_t>& OffsetsDump() const { return offsets_dump_; }
		const NameTable<BitField>& BitFieldsDump() const { return bitfields_dump_; }

		// caller is an address in the module the lookup is reported for, nullptr looks for it on the stack
		DWORD64 GetAddress(const void* base, std::string_view name, const void* caller = nullptr);
		LPVOID GetAddress(std::string_view name, const void* caller = nullptr);

		LPVOID GetDataAddress(std::string_view name, const void* caller = nullptr);

		BitField GetBitField(const void* base, std::string_view name, const void* caller = nullptr);
		BitField GetBitField(LPVOID base, std::string_view name, const void* caller = nullptr);

		// old exports: unknown names give a stub returning 0, base, or zeroed storage
		DWORD64 GetAddress(const void* base, const std::string& name, const void* call_site = nullptr);
		LPVOID GetAddress(const std::string& name, const void* call_site = nullptr);

		LPVOID GetDataAddress(const std::string& name, const void* call_site = nullptr);

		BitField GetBitField(const void* base, const std::string& name, const void* call_site = nullptr);
		BitField GetBitField(LPVOID base, const std::string& name, const void* call_site = nullptr);

		bool IsMissingFunctionStub(LPVOID address) const;

		bool FindOffset(std::string_view name, intptr_t* offset) const;
		bool FindBitField(std::string_view name, BitField* bit_field) const;

		// collapses whitespace and drops it next to punctuation, so "Foo(const FQuat &)" == "Foo(const FQuat&)"
		static std::string NormalizeName(std::string_view name);

	private:
		Offsets();
		~Offsets() = default;

		BitField GetBitFieldInternal(const void* base, std::string_view name, bool legacy, const void* caller);

		const intptr_t* FindValue(std::string_view name) const;

		// logs an unknown name once per module; with storage it also returns a zeroed block owned by that name
		void* ReportMissing(std::string_view name, bool storage, const void* caller);

		static const void* CallerOutsideApi();

		// a call site outside the api, or nullptr
		static const void* PluginCallSite(const void* call_site);

		DWORD64 module_base_;
		LPVOID missing_function_stub_{nullptr};

		NameTable<intptr_t> offsets_dump_;
		NameTable<BitField> bitfields_dump_;

		std::mutex missing_mutex_;
		NameMap<void*> missing_;
		size_t missing_blocks_{0};
	};
} // namespace API
