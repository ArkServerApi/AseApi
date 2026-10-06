#pragma once

#include "..\Base.h"
#include "BasicTypes.h"
#include "HAL/UnrealMemory.h"
#include "Templates/AreTypesEqual.h"
#include "Templates/UnrealTypeTraits.h"
#include "Templates/UnrealTemplate.h"

struct FCrc
{
    static uint32 MemCrc32(const void* Data, int32 Lenght, uint32 CRC = 0) { static NativeFunction f{ "FCrc.MemCrc32" }; return NativeCall<uint32, const void*, int32, uint32>(nullptr, f, Data, Lenght, CRC); }
    static uint32 Strihash_DEPRECATED(const wchar_t* Data) { static NativeFunction f{ "FCrc.Strihash_DEPRECATED<wchar_t>" }; return NativeCall<uint32, const wchar_t*>(nullptr, f, Data); }
};
