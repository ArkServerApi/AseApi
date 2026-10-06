#include <API/Base.h>

#include <intrin.h>

#include "Offsets.h"

__declspec(noinline) DWORD64 GetAddress(const void* base, const std::string& name)
{
	return API::Offsets::Get().GetAddress(base, name, _ReturnAddress());
}

__declspec(noinline) LPVOID GetAddress(const std::string& name)
{
	return API::Offsets::Get().GetAddress(name, _ReturnAddress());
}

__declspec(noinline) LPVOID GetDataAddress(const std::string& name)
{
	return API::Offsets::Get().GetDataAddress(name, _ReturnAddress());
}

__declspec(noinline) BitField GetBitField(const void* base, const std::string& name)
{
	return API::Offsets::Get().GetBitField(base, name, _ReturnAddress());
}

__declspec(noinline) BitField GetBitField(LPVOID base, const std::string& name)
{
	return API::Offsets::Get().GetBitField(base, name, _ReturnAddress());
}
