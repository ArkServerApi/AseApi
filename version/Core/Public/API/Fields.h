#pragma once

#include <Windows.h>
#include <atomic>
#include <climits>
#include <string>
#include <type_traits>
#include <utility>

#include "Base.h"

namespace API
{
	// logs once per module and name, at warn level, that the module uses something deprecated or missing
	ARK_API void LogDeprecatedUse(const char* api_name, HMODULE caller);
}

// cached name lookups, constexpr so a local static needs no init guard
class NativeFunction
{
public:
	constexpr explicit NativeFunction(const char* name) noexcept
		: name_(name), address_(nullptr)
	{
	}

	LPVOID Get()
	{
		LPVOID address = address_.load(std::memory_order_relaxed);
		return address != nullptr ? address : Resolve();
	}

	const char* Name() const
	{
		return name_;
	}

private:
	// kept out of line so every call site only carries the cached path
	__declspec(noinline) LPVOID Resolve()
	{
		LPVOID address = GetAddress(name_);
		if (address != nullptr)
			address_.store(address, std::memory_order_relaxed);

		return address;
	}

	const char* name_;
	std::atomic<LPVOID> address_;
};

class NativeFieldOffset
{
public:
	constexpr explicit NativeFieldOffset(const char* name) noexcept
		: name_(name), offset_(INTPTR_MIN)
	{
	}

	DWORD64 Address(const void* base)
	{
		const intptr_t offset = offset_.load(std::memory_order_relaxed);
		if (offset == INTPTR_MIN)
			return Resolve(base);

		return reinterpret_cast<DWORD64>(base) + static_cast<DWORD64>(offset);
	}

	const char* Name() const
	{
		return name_;
	}

private:
	__declspec(noinline) DWORD64 Resolve(const void* base)
	{
		intptr_t offset = 0;
		if (!FindNativeOffset(name_, &offset))
			return GetAddress(base, name_);

		offset_.store(offset, std::memory_order_relaxed);
		return reinterpret_cast<DWORD64>(base) + static_cast<DWORD64>(offset);
	}

	const char* name_;
	std::atomic<intptr_t> offset_;
};

class NativeBitField
{
public:
	constexpr explicit NativeBitField(const char* name) noexcept
		: name_(name), offset_(INTPTR_MIN), bits_(0)
	{
	}

	BitField Get(const void* base)
	{
		const intptr_t offset = offset_.load(std::memory_order_acquire);
		if (offset == INTPTR_MIN)
			return Resolve(base);

		return Make(base, offset);
	}

	const char* Name() const
	{
		return name_;
	}

private:
	BitField Make(const void* base, intptr_t offset) const
	{
		const auto bits = bits_.load(std::memory_order_relaxed);

		BitField bf{};
		bf.offset = reinterpret_cast<DWORD64>(base) + static_cast<DWORD64>(offset);
		bf.bit_position = static_cast<DWORD>(bits >> 32);
		bf.num_bits = (bits >> 8) & 0xFF;
		bf.length = bits & 0xFF;
		return bf;
	}

	__declspec(noinline) BitField Resolve(const void* base)
	{
		BitField bf{};
		if (!FindNativeBitField(name_, &bf))
			return GetBitField(base, name_);

		bits_.store((static_cast<unsigned long long>(bf.bit_position) << 32) | ((bf.num_bits & 0xFF) << 8) |
		            (bf.length & 0xFF), std::memory_order_relaxed);
		const auto offset = static_cast<intptr_t>(bf.offset);
		offset_.store(offset, std::memory_order_release);
		return Make(base, offset);
	}

	const char* name_;
	std::atomic<intptr_t> offset_;
	std::atomic<unsigned long long> bits_;
};

// a static class getter: a native class object is created once and never freed, so the result is cached too
class NativeStaticClass
{
public:
	constexpr explicit NativeStaticClass(const char* name) noexcept
		: function_(name), class_(nullptr)
	{
	}

	template <typename RT, typename... ArgsTypes, typename... Args>
	RT Get(Args&&... args);

	const char* Name() const
	{
		return function_.Name();
	}

private:
	NativeFunction function_;
	std::atomic<void*> class_;
};

template <typename RT, typename... ArgsTypes, typename... Args>
RT CallNativeAddress(LPVOID func, void* _this, Args&&... args)
{
	// unknown function: nothing to call. the name was already logged
	if constexpr (std::is_void_v<RT> || std::is_default_constructible_v<RT>)
	{
		if (func == nullptr)
			return RT();
	}

	return static_cast<RT(__fastcall*)(DWORD64, ArgsTypes ...)>(func)(
		reinterpret_cast<DWORD64>(_this), std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT CallNativeAddress(LPVOID func, nullptr_t, Args&&... args)
{
	if constexpr (std::is_void_v<RT> || std::is_default_constructible_v<RT>)
	{
		if (func == nullptr)
			return RT();
	}

	return static_cast<RT(__fastcall*)(ArgsTypes ...)>(func)(std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeStaticClass::Get(Args&&... args)
{
	void* result = class_.load(std::memory_order_acquire);
	if (result == nullptr)
	{
		result = CallNativeAddress<RT, ArgsTypes...>(function_.Get(), nullptr, std::forward<Args>(args)...);
		if (result != nullptr)
			class_.store(result, std::memory_order_release);
	}

	return static_cast<RT>(result);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(void* _this, const char* func_name, Args&&... args)
{
	return CallNativeAddress<RT, ArgsTypes...>(GetAddress(func_name), _this, std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(nullptr_t, const char* func_name, Args&&... args)
{
	return CallNativeAddress<RT, ArgsTypes...>(GetAddress(func_name), nullptr, std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(void* _this, NativeFunction& func, Args&&... args)
{
	return CallNativeAddress<RT, ArgsTypes...>(func.Get(), _this, std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(nullptr_t, NativeFunction& func, Args&&... args)
{
	return CallNativeAddress<RT, ArgsTypes...>(func.Get(), nullptr, std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(nullptr_t, NativeStaticClass& static_class, Args&&... args)
{
	return static_class.Get<RT, ArgsTypes...>(std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(void* _this, const std::string& func_name, Args&&... args)
{
	return NativeCall<RT, ArgsTypes...>(_this, func_name.c_str(), std::forward<Args>(args)...);
}

template <typename RT, typename... ArgsTypes, typename... Args>
RT NativeCall(nullptr_t, const std::string& funcName, Args&&... args)
{
	return NativeCall<RT, ArgsTypes...>(nullptr, funcName.c_str(), std::forward<Args>(args)...);
}

template <typename RT>
RT GetNativeField(const void* _this, const char* field_name)
{
	return *reinterpret_cast<RT*>(GetAddress(_this, field_name));
}

template <typename RT>
RT GetNativeField(const void* _this, const std::string& field_name)
{
	return GetNativeField<RT>(_this, field_name.c_str());
}

template <typename RT>
RT GetNativeField(const void* _this, NativeFieldOffset& field)
{
	return *reinterpret_cast<RT*>(field.Address(_this));
}

template <typename RT>
RT GetNativePointerField(const void* _this, const char* field_name)
{
	return reinterpret_cast<RT>(GetAddress(_this, field_name));
}

template <typename RT>
RT GetNativePointerField(const void* _this, const std::string& field_name)
{
	return GetNativePointerField<RT>(_this, field_name.c_str());
}

template <typename RT>
RT GetNativePointerField(const void* _this, NativeFieldOffset& field)
{
	return reinterpret_cast<RT>(field.Address(_this));
}

template <typename RT>
RT GetNativeDataPointerField(const char* field_name)
{
	LPVOID address = GetDataAddress(field_name);

	// unknown global: zeroed storage instead of a null reference
	if (address == nullptr)
		address = reinterpret_cast<LPVOID>(GetAddress(static_cast<const void*>(nullptr), field_name));

	return reinterpret_cast<RT>(address);
}

template <typename RT>
RT GetNativeDataPointerField(const std::string& field_name)
{
	return GetNativeDataPointerField<RT>(field_name.c_str());
}

template <typename RT, typename T>
RT ReadNativeBitField(const BitField& bf)
{
	// unknown name or bad width
	if (bf.num_bits == 0 || bf.num_bits > 64)
		return RT();

	const auto mask = bf.num_bits == 64 ? ~0ULL : (1ULL << bf.num_bits) - 1;
	T result = ((*reinterpret_cast<T*>(bf.offset)) >> bf.bit_position) & mask;

	return static_cast<RT>(result);
}

template <typename RT, typename T>
void WriteNativeBitField(const BitField& bf, RT new_value)
{
	if (bf.num_bits == 0 || bf.num_bits > 64)
		return;

	const auto mask = (bf.num_bits == 64 ? ~0ULL : (1ULL << bf.num_bits) - 1) << bf.bit_position;
	*reinterpret_cast<T*>(bf.offset) =
		(*reinterpret_cast<T*>(bf.offset) & ~mask) | ((static_cast<T>(new_value) << bf.bit_position) & mask);
}

template <typename RT, typename T>
RT GetNativeBitField(const LPVOID _this, const char* field_name)
{
	return ReadNativeBitField<RT, T>(GetBitField(_this, field_name));
}

template <typename RT, typename T>
RT GetNativeBitField(const LPVOID _this, const std::string& field_name)
{
	return GetNativeBitField<RT, T>(_this, field_name.c_str());
}

template <typename RT, typename T>
void SetNativeBitField(LPVOID _this, const char* field_name, RT new_value)
{
	WriteNativeBitField<RT, T>(GetBitField(_this, field_name), new_value);
}

template <typename RT, typename T>
void SetNativeBitField(LPVOID _this, const std::string& field_name, RT new_value)
{
	SetNativeBitField<RT, T>(_this, field_name.c_str(), new_value);
}

template <typename T, size_t size>
class FieldArray
{
public:
	FieldArray(void* parent, const char* field_name)
		: value_(GetNativePointerField<T*>(parent, field_name))
	{
	}

	FieldArray(void* parent, const std::string& field_name)
		: value_(GetNativePointerField<T*>(parent, field_name))
	{
	}

	FieldArray(void* parent, NativeFieldOffset& field)
		: value_(GetNativePointerField<T*>(parent, field))
	{
	}

	T* operator()()
	{
		return value_;
	}

	FieldArray& operator=(const T& other) = delete;

	static size_t GetSize()
	{
		return size;
	}

private:
	T* value_;
};

template <typename T>
class DataValue
{
public:
	DataValue(const char* field_name)
		: value_(GetNativeDataPointerField<T*>(field_name))
	{
	}

	DataValue(const std::string& field_name)
		: value_(GetNativeDataPointerField<T*>(field_name))
	{
	}

	T& operator()() const
	{
		return *value_;
	}

	DataValue& operator=(const T& other)
	{
		*value_ = other;
		return *this;
	}

	T& Get() const
	{
		return *value_;
	}

	void Set(const T& other)
	{
		*value_ = other;
	}

private:
	T* value_;
};

template <typename RT, typename T>
class BitFieldValue
{
public:
	BitFieldValue(void* parent, const char* field_name)
		: bit_field_(GetBitField(parent, field_name))
	{
	}

	BitFieldValue(void* parent, const std::string& field_name)
		: bit_field_(GetBitField(parent, field_name.c_str()))
	{
	}

	BitFieldValue(void* parent, NativeBitField& field)
		: bit_field_(field.Get(parent))
	{
	}

	RT operator()() const
	{
		return ReadNativeBitField<RT, T>(bit_field_);
	}

	BitFieldValue& operator=(RT other)
	{
		WriteNativeBitField<RT, T>(bit_field_, other);
		return *this;
	}

	RT Get() const
	{
		return ReadNativeBitField<RT, T>(bit_field_);
	}

	void Set(RT other)
	{
		WriteNativeBitField<RT, T>(bit_field_, other);
	}

private:
	BitField bit_field_;
};