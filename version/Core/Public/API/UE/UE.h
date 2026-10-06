#pragma once

#include <comdef.h>
#include <xmmintrin.h>
#include <unordered_map>

#include "Crc.h"
#include "Containers/TArray.h"
#include "Containers/FString.h"
#include "Containers/EnumAsByte.h"
#include "Templates/SharedPointer.h"
#include "API/Fields.h"
#include "API/Enums.h"
#include "API/UE/Math/Color.h"
#include "Misc/GlobalObjectsArray.h"

// Base types

struct FText;

struct FName
{
	int ComparisonIndex;
	unsigned int Number;

	// Functions

	FName() : ComparisonIndex(0), Number(0)
	{
	}

	FName(EName) : ComparisonIndex(0), Number(0)
	{
	}

	static FString* NameToDisplayString(FString* result, FString* InDisplayName, const bool bIsBool) { static NativeFunction f{ "FName.NameToDisplayString" }; return NativeCall<FString*, FString*, FString*, const bool>(nullptr, f, result, InDisplayName, bIsBool); }

	FName(const char* Name, EFindName FindType)
	{
		Init(Name, 0, FindType, true, -1);
	}

	bool operator==(const wchar_t* Other) { static NativeFunction f{ "FName.operator==" }; return NativeCall<bool, const wchar_t*>(this, f, Other); }
	int Compare(FName* Other) { static NativeFunction f{ "FName.Compare" }; return NativeCall<int, FName*>(this, f, Other); }
	void ToString(FString* Out) { static NativeFunction f{ "FName.ToString(FString&)const" }; NativeCall<void, FString*>(this, f, Out); }
	FString ToString() const
	{
		FString out;
		FName tmp = *this;

		tmp.ToString(&out);

		return out;
	}
	void AppendString(FString* Out) { static NativeFunction f{ "FName.AppendString" }; NativeCall<void, FString*>(this, f, Out); }
	static bool SplitNameWithCheck(const wchar_t* OldName, wchar_t* NewName, int NewNameLen, int* NewNumber) { static NativeFunction f{ "FName.SplitNameWithCheck" }; return NativeCall<bool, const wchar_t*, wchar_t*, int, int*>(nullptr, f, OldName, NewName, NewNameLen, NewNumber); }
	bool IsValidXName(FString InvalidChars, FText* Reason) { static NativeFunction f{ "FName.IsValidXName" }; return NativeCall<bool, FString, FText*>(this, f, InvalidChars, Reason); }
	void Init(const char* InName, int InNumber, EFindName FindType, bool bSplitName, int HardcodeIndex) { static NativeFunction f{ "FName.Init(const char*,int,EFindName,bool,int)" }; NativeCall<void, const char*, int, EFindName, bool, int>(this, f, InName, InNumber, FindType, bSplitName, HardcodeIndex); }
	FString* GetPlainNameString(FString* result) { static NativeFunction f{ "FName.GetPlainNameString" }; return NativeCall<FString*, FString*>(this, f, result); }

	bool operator==(const FName& Other) const { return ComparisonIndex == Other.ComparisonIndex && Number == Other.Number; }
};

FORCEINLINE uint32 GetTypeHash(const FName& name)
{
	return name.ComparisonIndex;
}

struct FTransform
{
	__m128 Rotation;
	__m128 Translation;
	__m128 Scale3D;
};

struct FBoxSphereBounds
{
};

struct FGuid
{
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
};

struct FBox
{
};

template <typename ObjectType>
struct TSubobjectPtr
{
	ObjectType* Object;

	FORCEINLINE ObjectType& operator*() const
	{
		return *Object;
	}

	FORCEINLINE ObjectType* operator->() const
	{
		return Object;
	}
};

struct __declspec(align(8)) FTextHistory
{
	void* vfptr;
	int Revision;
};

struct FText
{
	TSharedPtr<FTextHistory, ESPMode::ThreadSafe> History;
	int Flags;
	TSharedPtr<FString, ESPMode::ThreadSafe> DisplayString;

	// Functions

	int CompareTo(FText* Other, ETextComparisonLevel::Type ComparisonLevel) { static NativeFunction f{ "FText.CompareTo" }; return NativeCall<int, FText*, ETextComparisonLevel::Type>(this, f, Other, ComparisonLevel); }
	FText() { static NativeFunction f{ "FText.FText()" }; NativeCall<void>(this, f); }
	FText(FText* Source) { static NativeFunction f{ "FText.FText(const FText&)" }; NativeCall<void, FText*>(this, f, Source); }
	FText* operator=(FText* Source) { static NativeFunction f{ "FText.operator=(const FText&)" }; return NativeCall<FText*, FText*>(this, f, Source); }
	FText(FString InSourceString) { static NativeFunction f{ "FText.FText(FString)" }; NativeCall<void, FString>(this, f, InSourceString); }
	FText(FString InSourceString, FString InNamespace, FString InKey, int InFlags) { static NativeFunction f{ "FText.FText(FString,FString,FString,int)" }; NativeCall<void, FString, FString, FString, int>(this, f, InSourceString, InNamespace, InKey, InFlags); }
	static FText* TrimPreceding(FText* result, FText* InText) { static NativeFunction f{ "FText.TrimPreceding" }; return NativeCall<FText*, FText*, FText*>(nullptr, f, result, InText); }
	static FText* TrimTrailing(FText* result, FText* InText) { static NativeFunction f{ "FText.TrimTrailing" }; return NativeCall<FText*, FText*, FText*>(nullptr, f, result, InText); }
	static FText* TrimPrecedingAndTrailing(FText* result, FText* InText) { static NativeFunction f{ "FText.TrimPrecedingAndTrailing" }; return NativeCall<FText*, FText*, FText*>(nullptr, f, result, InText); }
	static FText* Format(FText* result, FText* Fmt, FText* v1) { static NativeFunction f{ "FText.Format(const FText&,const FText&)" }; return NativeCall<FText*, FText*, FText*, FText*>(nullptr, f, result, Fmt, v1); }
	static FText* Format(FText* result, FText* Fmt, FText* v1, FText* v2) { static NativeFunction f{ "FText.Format(const FText&,const FText&,const FText&)" }; return NativeCall<FText*, FText*, FText*, FText*, FText*>(nullptr, f, result, Fmt, v1, v2); }
	[[deprecated("the engine has no overload with three values, this formats through the argument list")]] static FText* Format(FText* result, FText* Fmt, FText* v1, FText* v2, FText* v3)
	{
		ReportDeprecatedApiUse("FText.Format(Fmt, v1, v2, v3)");
		struct FArgumentValue { int Type; void* Value; } values[3] = {};
		FText* texts[3] = { v1, v2, v3 };
		static NativeFunction f{ "FFormatArgumentValue.FFormatArgumentValue(const FText&)" };
		for (int i = 0; i < 3; ++i)
			NativeCall<void, FText*>(&values[i], f, texts[i]);
		struct { FArgumentValue* Data; int Num; int Max; } args{ values, 3, 3 };
		static NativeFunction f2{ "FText.Format(const FText&,const TArray<FFormatArgumentValue,FDefaultAllocator>&)" };
		NativeCall<FText*, FText*, FText*, void*>(nullptr, f2, result, Fmt, &args);
		static NativeFunction f3{ "FFormatArgumentValue.~FFormatArgumentValue" };
		for (FArgumentValue& value : values)
			NativeCall<void>(&value, f3);
		return result;
	}
	static bool FindText(FString* Namespace, FString* Key, FText* OutText, FString* const  SourceString) { static NativeFunction f{ "FText.FindText" }; return NativeCall<bool, FString*, FString*, FText*, FString* const>(nullptr, f, Namespace, Key, OutText, SourceString); }
	static FText* CreateChronologicalText(FText* result, FString InSourceString) { static NativeFunction f{ "FText.CreateChronologicalText" }; return NativeCall<FText*, FText*, FString>(nullptr, f, result, InSourceString); }
	static FText* FromName(FText* result, FName* Val) { static NativeFunction f{ "FText.FromName" }; return NativeCall<FText*, FText*, FName*>(nullptr, f, result, Val); }
	static FText* FromString(FText* result, FString String) { static NativeFunction f{ "FText.FromString" }; return NativeCall<FText*, FText*, FString>(nullptr, f, result, String); }
	FString* ToString() { static NativeFunction f{ "FText.ToString" }; return NativeCall<FString*>(this, f); }
	bool ShouldGatherForLocalization() { static NativeFunction f{ "FText.ShouldGatherForLocalization" }; return NativeCall<bool>(this, f); }
	TSharedPtr<FString>* GetSourceString(TSharedPtr<FString>* result) { static NativeFunction f{ "FText.GetSourceString" }; return NativeCall<TSharedPtr<FString>*, TSharedPtr<FString>*>(this, f, result); }
	TSharedPtr<FString, ESPMode::ThreadSafe>* GetSourceString(TSharedPtr<FString, ESPMode::ThreadSafe>* result) { static NativeFunction f{ "FText.GetSourceString" }; return NativeCall<TSharedPtr<FString, ESPMode::ThreadSafe>*, TSharedPtr<FString, ESPMode::ThreadSafe>*>(this, f, result); }
	static void GetEmpty() { static NativeFunction f{ "FText.GetEmpty" }; NativeCall<void>(nullptr, f); }
};

struct FDateTime
{
	__int64 Ticks;
};

struct FWeakObjectPtr
{
	int ObjectIndex;
	int ObjectSerialNumber;

	void operator=(UObject const* __that) { static NativeFunction f{ "FWeakObjectPtr.operator=" }; return NativeCall<void, UObject const*>(this, f, __that); }
	bool IsValid() { static NativeFunction f{ "FWeakObjectPtr.IsValid()const" }; return NativeCall<bool>(this, f); }
};

template <typename T>
struct TWeakObjectPtr
{
	int ObjectIndex;
	int ObjectSerialNumber;

	FORCEINLINE T& operator*()
	{
		return *Get();
	}

	FORCEINLINE T* operator->()
	{
		return Get();
	}

	T* Get(bool bEvenIfPendingKill = false)
	{
		static NativeFunction f{ "FWeakObjectPtr.Get(bool)const" };
		return NativeCall<T*, bool>(this, f, bEvenIfPendingKill);
	}

	FORCEINLINE operator bool()
	{
		return Get() != nullptr;
	}

	FORCEINLINE operator T* ()
	{
		return Get();
	}

	FORCEINLINE bool operator==(const TWeakObjectPtr<T>& __that) const
	{
		return this->ObjectIndex == __that.ObjectIndex
			&& this->ObjectSerialNumber == __that.ObjectSerialNumber;
	}

	TWeakObjectPtr()
		: ObjectIndex(-1),
		ObjectSerialNumber(0)
	{}

	TWeakObjectPtr(int index, int serialnumber)
		:ObjectIndex(index),
		ObjectSerialNumber(serialnumber)
	{}
};

template <typename T>
TWeakObjectPtr<T> GetWeakReference(T* object)
{
	FWeakObjectPtr tempWeak;
	tempWeak.operator=(object);
	TWeakObjectPtr<T> tempTWeak(tempWeak.ObjectIndex, tempWeak.ObjectSerialNumber);
	return tempTWeak;
}
template <typename T>
using TAutoWeakObjectPtr = TWeakObjectPtr<T>;

template <typename T>
struct TSubclassOf
{
	TSubclassOf()
		: uClass(nullptr)
	{
	}

	TSubclassOf(UClass* uClass)
		: uClass(uClass)
	{
	}

	UClass* uClass;
};

struct IOnlinePlatformData
{
	void* vfptr;
	FString* ToHumanReadableString(FString* result) { static NativeFunction f{ "IOnlinePlatformData.ToHumanReadableString" }; return NativeCall<FString*, FString*>(this, f, result); }
};

struct FUniqueNetId : IOnlinePlatformData
{
};

struct FUniqueNetIdUInt64 : FUniqueNetId
{
	unsigned __int64 UniqueNetId;

	unsigned __int64& UniqueNetIdField() { static NativeFieldOffset f{ "FUniqueNetIdUInt64.UniqueNetId" }; return *GetNativePointerField<unsigned __int64*>(this, f); }

	// Functions

	FUniqueNetIdUInt64(FString* Str) { static NativeFunction f{ "FUniqueNetIdUInt64.FUniqueNetIdUInt64(const FString&)" }; NativeCall<void, FString*>(this, f, Str); }
	FUniqueNetIdUInt64(FUniqueNetIdUInt64* Src) { static NativeFunction f{ "FUniqueNetIdUInt64.FUniqueNetIdUInt64(const FUniqueNetIdUInt64&)" }; NativeCall<void, FUniqueNetIdUInt64*>(this, f, Src); }
	FUniqueNetIdUInt64(FUniqueNetId* InUniqueNetId) { static NativeFunction f{ "FUniqueNetIdUInt64.FUniqueNetIdUInt64(const FUniqueNetId&)" }; NativeCall<void, FUniqueNetId*>(this, f, InUniqueNetId); }
	FUniqueNetIdUInt64(uint64 InUniqueNetId) { static NativeFunction f{ "FUniqueNetIdUInt64.FUniqueNetIdUInt64(unsigned __int64)" }; NativeCall<void, uint64>(this, f, InUniqueNetId); }

	bool IsValid() { static NativeFunction f{ "FUniqueNetIdUInt64.IsValid" }; return NativeCall<bool>(this, f); }
	FString* ToDebugString(FString* result) { static NativeFunction f{ "FUniqueNetIdUInt64.ToDebugString" }; return NativeCall<FString*, FString*>(this, f, result); }
	unsigned int GetHash() { static NativeFunction f{ "FUniqueNetIdUInt64.GetHash" }; return NativeCall<int>(this, f); }
	FString* ToString(FString* result) { static NativeFunction f{ "FUniqueNetIdUInt64.ToString" }; return NativeCall<FString*, FString*>(this, f, result); }
};

struct FUniqueNetIdSteamOrEOS : FUniqueNetId
{
	unsigned __int64 kEOSIdentMask;
	unsigned __int64 kEOSIdentBits;
	unsigned __int64 kEOSBitClearMask;
	FString OriginalEOSNetString;
	FString EpicAccountId;
	FString ProductUserId;
	union
	{
		unsigned __int64 UniqueIdAsUint64;
		unsigned __int64 UniqueNetId;
	};
	bool bIsEOS;
	bool bIsSteam;
	bool bIsStadia;
};

struct FUniqueNetIdSteam : FUniqueNetIdSteamOrEOS
{
	unsigned __int64 GetUniqueNetId() const { return UniqueIdAsUint64; }
	void SetUniqueNetId(unsigned __int64 Value) { UniqueIdAsUint64 = Value; }

	// Functions

	int GetSize() { return sizeof(unsigned __int64); }
	FString* ToString(FString* result) { *result = FString(std::to_string(UniqueIdAsUint64)); return result; }
	bool IsValid() { static NativeFunction f{ "FUniqueNetIdSteam.IsValid" }; return NativeCall<bool>(this, f); }
	FString* ToDebugString(FString* result) { static NativeFunction f{ "FUniqueNetIdSteam.ToDebugString" }; return NativeCall<FString*, FString*>(this, f, result); }
};

struct FUniqueNetIdString : FUniqueNetId
{
	FString UniqueNetIdStr;
};

struct UObjectBase
{
	EObjectFlags& ObjectFlagsField() { static NativeFieldOffset f{ "UObjectBase.ObjectFlags" }; return *GetNativePointerField<EObjectFlags*>(this, f); }
	int& InternalIndexField() { static NativeFieldOffset f{ "UObjectBase.InternalIndex" }; return *GetNativePointerField<int*>(this, f); }
	UClass* ClassField() { static NativeFieldOffset f{ "UObjectBase.Class" }; return *GetNativePointerField<UClass**>(this, f); }
	FName& NameField() { static NativeFieldOffset f{ "UObjectBase.Name" }; return *GetNativePointerField<FName*>(this, f); }
	UObject* OuterField() { static NativeFieldOffset f{ "UObjectBase.Outer" }; return *GetNativePointerField<UObject**>(this, f); }

	// Functions

	void DeferredRegister(UClass* UClassStaticClass, const wchar_t* PackageName, const wchar_t* InName) { static NativeFunction f{ "UObjectBase.DeferredRegister" }; NativeCall<void, UClass*, const wchar_t*, const wchar_t*>(this, f, UClassStaticClass, PackageName, InName); }
	bool IsValidLowLevel() { static NativeFunction f{ "UObjectBase.IsValidLowLevel" }; return NativeCall<bool>(this, f); }
	bool IsValidLowLevelFast(bool bRecursive) { static NativeFunction f{ "UObjectBase.IsValidLowLevelFast" }; return NativeCall<bool, bool>(this, f, bRecursive); }
	static void EmitBaseReferences(UClass* RootClass) { static NativeFunction f{ "UObjectBase.EmitBaseReferences" }; NativeCall<void, UClass*>(nullptr, f, RootClass); }
	void Register(const wchar_t* PackageName, const wchar_t* InName) { static NativeFunction f{ "UObjectBase.Register" }; NativeCall<void, const wchar_t*, const wchar_t*>(this, f, PackageName, InName); }
};

struct UObjectBaseUtility : public UObjectBase
{
	int GetLinkerUE4Version() { static NativeFunction f{ "UObjectBaseUtility.GetLinkerUE4Version" }; return NativeCall<int>(this, f); }
	int GetLinkerLicenseeUE4Version() { static NativeFunction f{ "UObjectBaseUtility.GetLinkerLicenseeUE4Version" }; return NativeCall<int>(this, f); }
	FString* GetPathName(FString* result, UObject* StopOuter) { static NativeFunction f{ "UObjectBaseUtility.GetPathName(const UObject*)const" }; return NativeCall<FString*, FString*, UObject*>(this, f, result, StopOuter); }
	void GetPathName(UObject* StopOuter, FString* ResultString) { static NativeFunction f{ "UObjectBaseUtility.GetPathName(const UObject*,FString&)const" }; NativeCall<void, UObject*, FString*>(this, f, StopOuter, ResultString); }
	FString* GetFullName(FString* result, UObject* StopOuter) { static NativeFunction f{ "UObjectBaseUtility.GetFullName" }; return NativeCall<FString*, FString*, UObject*>(this, f, result, StopOuter); }
	void MarkPackageDirty() { static NativeFunction f{ "UObjectBaseUtility.MarkPackageDirty" }; NativeCall<void>(this, f); }
	bool IsIn(UObject* SomeOuter) { static NativeFunction f{ "UObjectBaseUtility.IsIn" }; return NativeCall<bool, UObject*>(this, f, SomeOuter); }
	bool IsA(UClass* SomeBase)
	{
		// the engine's walk starts at the object's own class
		UClass* object_class = ClassField();
		if (object_class != nullptr && object_class == SomeBase)
			return true;

		static NativeFunction f{ "UObjectBaseUtility.IsA" };
		return NativeCall<bool, UClass*>(this, f, SomeBase);
	}
	void* GetInterfaceAddress(UClass* InterfaceClass) { static NativeFunction f{ "UObjectBaseUtility.GetInterfaceAddress" }; return NativeCall<void*, UClass*>(this, f, InterfaceClass); }
	bool IsDefaultSubobject() { static NativeFunction f{ "UObjectBaseUtility.IsDefaultSubobject" }; return NativeCall<bool>(this, f); }
	int GetLinkerIndex() { static NativeFunction f{ "UObjectBaseUtility.GetLinkerIndex" }; return NativeCall<int>(this, f); }
};

struct UObject : UObjectBaseUtility
{
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	static UClass* StaticClass() { static NativeStaticClass f{ "UObject.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	void ExecuteUbergraph(int EntryPoint) { static NativeFunction f{ "UObject.ExecuteUbergraph" }; NativeCall<void, int>(this, f, EntryPoint); }
	bool AreAllOuterObjectsValid() { static NativeFunction f{ "UObject.AreAllOuterObjectsValid" }; return NativeCall<bool>(this, f); }
	FName* GetExporterName(FName* result) { static NativeFunction f{ "UObject.GetExporterName" }; return NativeCall<FName*, FName*>(this, f, result); }
	FString* GetDetailedInfoInternal(FString* result) { static NativeFunction f{ "UObject.GetDetailedInfoInternal" }; return NativeCall<FString*, FString*>(this, f, result); }
	UObject* GetArchetype() { static NativeFunction f{ "UObject.GetArchetype" }; return NativeCall<UObject*>(this, f); }
	bool IsBasedOnArchetype(UObject* const  SomeObject) { static NativeFunction f{ "UObject.IsBasedOnArchetype" }; return NativeCall<bool, UObject* const>(this, f, SomeObject); }
	bool IsInBlueprint() { static NativeFunction f{ "UObject.IsInBlueprint" }; return NativeCall<bool>(this, f); }
	bool Rename(const wchar_t* InName, UObject* NewOuter, unsigned int Flags) { static NativeFunction f{ "UObject.Rename" }; return NativeCall<bool, const wchar_t*, UObject*, unsigned int>(this, f, InName, NewOuter, Flags); }
	void LoadLocalized(UObject* LocBase, bool bLoadHierachecally) { static NativeFunction f{ "UObject.LoadLocalized" }; NativeCall<void, UObject*, bool>(this, f, LocBase, bLoadHierachecally); }
	void LocalizeProperty(UObject* LocBase, TArray<FString>* PropertyTagChain, UProperty* const  BaseProperty, UProperty* const  Property, void* const  ValueAddress) { static NativeFunction f{ "UObject.LocalizeProperty" }; NativeCall<void, UObject*, TArray<FString>*, UProperty* const, UProperty* const, void* const>(this, f, LocBase, PropertyTagChain, BaseProperty, Property, ValueAddress); }
	void BeginDestroy() { static NativeFunction f{ "UObject.BeginDestroy" }; NativeCall<void>(this, f); }
	void FinishDestroy() { static NativeFunction f{ "UObject.FinishDestroy" }; NativeCall<void>(this, f); }
	FString* GetDetailedInfo(FString* result) { static NativeFunction f{ "UObject.GetDetailedInfo" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool ConditionalBeginDestroy() { static NativeFunction f{ "UObject.ConditionalBeginDestroy" }; return NativeCall<bool>(this, f); }
	bool ConditionalFinishDestroy() { static NativeFunction f{ "UObject.ConditionalFinishDestroy" }; return NativeCall<bool>(this, f); }
	void ConditionalPostLoad() { static NativeFunction f{ "UObject.ConditionalPostLoad" }; NativeCall<void>(this, f); }
	bool Modify(bool bAlwaysMarkDirty) { static NativeFunction f{ "UObject.Modify" }; return NativeCall<bool, bool>(this, f, bAlwaysMarkDirty); }
	bool IsSelected() { static NativeFunction f{ "UObject.IsSelected" }; return NativeCall<bool>(this, f); }
	void CollectDefaultSubobjects(TArray<UObject*>* OutSubobjectArray, bool bIncludeNestedSubobjects) { static NativeFunction f{ "UObject.CollectDefaultSubobjects" }; NativeCall<void, TArray<UObject*>*, bool>(this, f, OutSubobjectArray, bIncludeNestedSubobjects); }
	bool CheckDefaultSubobjectsInternal() { static NativeFunction f{ "UObject.CheckDefaultSubobjectsInternal" }; return NativeCall<bool>(this, f); }
	bool IsAsset() { static NativeFunction f{ "UObject.IsAsset" }; return NativeCall<bool>(this, f); }
	bool IsSafeForRootSet() { static NativeFunction f{ "UObject.IsSafeForRootSet" }; return NativeCall<bool>(this, f); }
	void LoadConfig(UClass* ConfigClass, const wchar_t* InFilename, unsigned int PropagationFlags, UProperty* PropertyToLoad) { static NativeFunction f{ "UObject.LoadConfig" }; NativeCall<void, UClass*, const wchar_t*, unsigned int, UProperty*>(this, f, ConfigClass, InFilename, PropagationFlags, PropertyToLoad); }
	void ConditionalShutdownAfterError() { static NativeFunction f{ "UObject.ConditionalShutdownAfterError" }; NativeCall<void>(this, f); }
	bool IsNameStableForNetworking() { static NativeFunction f{ "UObject.IsNameStableForNetworking" }; return NativeCall<bool>(this, f); }
	bool IsFullNameStableForNetworking() { static NativeFunction f{ "UObject.IsFullNameStableForNetworking" }; return NativeCall<bool>(this, f); }
	bool IsSupportedForNetworking() { static NativeFunction f{ "UObject.IsSupportedForNetworking" }; return NativeCall<bool>(this, f); }
	UFunction* FindFunctionChecked(FName InName) { static NativeFunction f{ "UObject.FindFunctionChecked" }; return NativeCall<UFunction*, FName>(this, f, InName); }
	void ProcessEvent(UFunction* Function, void* Parms) { static NativeFunction f{ "UObject.ProcessEvent" }; NativeCall<void, UFunction*, void*>(this, f, Function, Parms); }
	static UObject* GetArchetypeFromRequiredInfo(UClass* Class, UObject* Outer, FName Name, bool bIsCDO) { static NativeFunction f{ "UObject.GetArchetypeFromRequiredInfo" }; return NativeCall<UObject*, UClass*, UObject*, FName, bool>(nullptr, f, Class, Outer, Name, bIsCDO); }
	__declspec(dllexport) UProperty* FindProperty(FName name);
};

struct UField : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UField.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	UField* NextField() { static NativeFieldOffset f{ "UField.Next" }; return *GetNativePointerField<UField**>(this, f); }

	// Functions

	UClass* GetOwnerClass() { static NativeFunction f{ "UField.GetOwnerClass" }; return NativeCall<UClass*>(this, f); }
	UStruct* GetOwnerStruct() { static NativeFunction f{ "UField.GetOwnerStruct" }; return NativeCall<UStruct*>(this, f); }
	void PostLoad() { static NativeFunction f{ "UField.PostLoad" }; NativeCall<void>(this, f); }
	void AddCppProperty(UProperty* Property) { static NativeFunction f{ "UField.AddCppProperty" }; NativeCall<void, UProperty*>(this, f, Property); }
};

struct UStruct : UField
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UStruct.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	UStruct* SuperStructField() { static NativeFieldOffset f{ "UStruct.SuperStruct" }; return *GetNativePointerField<UStruct**>(this, f); }
	UField* ChildrenField() { static NativeFieldOffset f{ "UStruct.Children" }; return *GetNativePointerField<UField**>(this, f); }
	int& PropertiesSizeField() { static NativeFieldOffset f{ "UStruct.PropertiesSize" }; return *GetNativePointerField<int*>(this, f); }
	TArray<unsigned char>& ScriptField() { static NativeFieldOffset f{ "UStruct.Script" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	int& MinAlignmentField() { static NativeFieldOffset f{ "UStruct.MinAlignment" }; return *GetNativePointerField<int*>(this, f); }
	UProperty* PropertyLinkField() { static NativeFieldOffset f{ "UStruct.PropertyLink" }; return *GetNativePointerField<UProperty**>(this, f); }
	UProperty* RefLinkField() { static NativeFieldOffset f{ "UStruct.RefLink" }; return *GetNativePointerField<UProperty**>(this, f); }
	UProperty* DestructorLinkField() { static NativeFieldOffset f{ "UStruct.DestructorLink" }; return *GetNativePointerField<UProperty**>(this, f); }
	UProperty* PostConstructLinkField() { static NativeFieldOffset f{ "UStruct.PostConstructLink" }; return *GetNativePointerField<UProperty**>(this, f); }
	TArray<UObject*>& ScriptObjectReferencesField() { static NativeFieldOffset f{ "UStruct.ScriptObjectReferences" }; return *GetNativePointerField<TArray<UObject*>*>(this, f); }

	// Functions

	bool IsChildOf(UStruct* SomeBase) { static NativeFunction f{ "UStruct.IsChildOf" }; return NativeCall<bool, UStruct*>(this, f, SomeBase); }
	void LinkChild(UProperty* Property) { static NativeFunction f{ "UStruct.LinkChild" }; NativeCall<void, UProperty*>(this, f, Property); }
	const wchar_t* GetPrefixCPP() { static NativeFunction f{ "UStruct.GetPrefixCPP" }; return NativeCall<const wchar_t*>(this, f); }
	void RegisterDependencies() { static NativeFunction f{ "UStruct.RegisterDependencies" }; NativeCall<void>(this, f); }
	void StaticLink(bool bRelinkExistingProperties) { static NativeFunction f{ "UStruct.StaticLink" }; NativeCall<void, bool>(this, f, bRelinkExistingProperties); }
	void FinishDestroy() { static NativeFunction f{ "UStruct.FinishDestroy" }; NativeCall<void>(this, f); }
	void SetSuperStruct(UStruct* NewSuperStruct) { static NativeFunction f{ "UStruct.SetSuperStruct" }; NativeCall<void, UStruct*>(this, f, NewSuperStruct); }
	void TagSubobjects(EObjectFlags NewFlags) { static NativeFunction f{ "UStruct.TagSubobjects" }; NativeCall<void, EObjectFlags>(this, f, NewFlags); }
};

struct UFunction : UStruct
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UFunction.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	char UStructData[0x90];
	unsigned int FunctionFlags;
	unsigned __int16 RepOffset;
	char NumParms;
	unsigned __int16 ParmsSize;
	unsigned __int16 ReturnValueOffset;
	unsigned __int16 RPCId;
	unsigned __int16 RPCResponseId;
	UProperty* FirstPropertyToInit;
	void(__fastcall* Func)(UObject* _this, void*, void* const);
};

struct FNativeFunctionLookup
{
	FName Name;
	void(__fastcall* Pointer)(UObject* _this, void*, void* const);
};

struct UClass : UStruct
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UClass.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	unsigned int& ClassFlagsField() { static NativeFieldOffset f{ "UClass.ClassFlags" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned __int64& ClassCastFlagsField() { static NativeFieldOffset f{ "UClass.ClassCastFlags" }; return *GetNativePointerField<unsigned __int64*>(this, f); }
	int& ClassUniqueField() { static NativeFieldOffset f{ "UClass.ClassUnique" }; return *GetNativePointerField<int*>(this, f); }
	UClass* ClassWithinField() { static NativeFieldOffset f{ "UClass.ClassWithin" }; return *GetNativePointerField<UClass**>(this, f); }
	UObject* ClassGeneratedByField() { static NativeFieldOffset f{ "UClass.ClassGeneratedBy" }; return *GetNativePointerField<UObject**>(this, f); }
	bool& bIsGameClassField() { static NativeFieldOffset f{ "UClass.bIsGameClass" }; return *GetNativePointerField<bool*>(this, f); }
	FName& ClassConfigNameField() { static NativeFieldOffset f{ "UClass.ClassConfigName" }; return *GetNativePointerField<FName*>(this, f); }
	TArray<UField*>& NetFieldsField() { static NativeFieldOffset f{ "UClass.NetFields" }; return *GetNativePointerField<TArray<UField*>*>(this, f); }
	UObject* ClassDefaultObjectField() { static NativeFieldOffset f{ "UClass.ClassDefaultObject" }; return *GetNativePointerField<UObject**>(this, f); }
	bool& bCookedField() { static NativeFieldOffset f{ "UClass.bCooked" }; return *GetNativePointerField<bool*>(this, f); }
	TMap<FName, UFunction*>& FuncMapField() { static NativeFieldOffset f{ "UClass.FuncMap" }; return *GetNativePointerField<TMap<FName, UFunction*>*>(this, f); }
	[[deprecated("not in this game build")]] unsigned int EmitStructArrayBegin(int Offset, FName* DebugName, int Stride) { ReportDeprecatedApiUse("UClass.EmitStructArrayBegin"); static NativeFunction f{ "UClass.EmitStructArrayBegin" }; return NativeCall<unsigned int, int, FName*, int>(this, f, Offset, DebugName, Stride); }
	TArray<FNativeFunctionLookup>& NativeFunctionLookupTableField() { static NativeFieldOffset f{ "UClass.NativeFunctionLookupTable" }; return *GetNativePointerField<TArray<FNativeFunctionLookup>*>(this, f); }

	// Functions

	UObject* GetDefaultObject(bool bCreateIfNeeded) { static NativeFunction f{ "UClass.GetDefaultObject" }; return NativeCall<UObject*, bool>(this, f, bCreateIfNeeded); }
	void AddFunctionToFunctionMap(UFunction* NewFunction) { static NativeFunction f{ "UClass.AddFunctionToFunctionMap" }; NativeCall<void, UFunction*>(this, f, NewFunction); }
	void PostInitProperties() { static NativeFunction f{ "UClass.PostInitProperties" }; NativeCall<void>(this, f); }
	UObject* GetDefaultSubobjectByName(FName ToFind) { static NativeFunction f{ "UClass.GetDefaultSubobjectByName" }; return NativeCall<UObject*, FName>(this, f, ToFind); }
	void GetDefaultObjectSubobjects(TArray<UObject*>* OutDefaultSubobjects) { static NativeFunction f{ "UClass.GetDefaultObjectSubobjects" }; NativeCall<void, TArray<UObject*>*>(this, f, OutDefaultSubobjects); }
	UObject* CreateDefaultObject() { static NativeFunction f{ "UClass.CreateDefaultObject" }; return NativeCall<UObject*>(this, f); }
	FName* GetDefaultObjectName(FName* result) { static NativeFunction f{ "UClass.GetDefaultObjectName" }; return NativeCall<FName*, FName*>(this, f, result); }
	void DeferredRegister(UClass* UClassStaticClass, const wchar_t* PackageName, const wchar_t* Name) { static NativeFunction f{ "UClass.DeferredRegister" }; NativeCall<void, UClass*, const wchar_t*, const wchar_t*>(this, f, UClassStaticClass, PackageName, Name); }
	bool Rename(const wchar_t* InName, UObject* NewOuter, unsigned int Flags) { static NativeFunction f{ "UClass.Rename" }; return NativeCall<bool, const wchar_t*, UObject*, unsigned int>(this, f, InName, NewOuter, Flags); }
	void TagSubobjects(EObjectFlags NewFlags) { static NativeFunction f{ "UClass.TagSubobjects" }; NativeCall<void, EObjectFlags>(this, f, NewFlags); }
	void Bind() { static NativeFunction f{ "UClass.Bind" }; NativeCall<void>(this, f); }
	const wchar_t* GetPrefixCPP() { static NativeFunction f{ "UClass.GetPrefixCPP" }; return NativeCall<const wchar_t*>(this, f); }
	FString* GetDescription(FString* result) { static NativeFunction f{ "UClass.GetDescription" }; return NativeCall<FString*, FString*>(this, f, result); }
	void FinishDestroy() { static NativeFunction f{ "UClass.FinishDestroy" }; NativeCall<void>(this, f); }
	void PostLoad() { static NativeFunction f{ "UClass.PostLoad" }; NativeCall<void>(this, f); }
	void SetSuperStruct(UStruct* NewSuperStruct) { static NativeFunction f{ "UClass.SetSuperStruct" }; NativeCall<void, UStruct*>(this, f, NewSuperStruct); }
	bool ImplementsInterface(UClass* SomeInterface) { static NativeFunction f{ "UClass.ImplementsInterface" }; return NativeCall<bool, UClass*>(this, f, SomeInterface); }
	void PurgeClass(bool bRecompilingOnLoad) { static NativeFunction f{ "UClass.PurgeClass" }; NativeCall<void, bool>(this, f, bRecompilingOnLoad); }
	bool HasProperty(UProperty* InProperty) { static NativeFunction f{ "UClass.HasProperty" }; return NativeCall<bool, UProperty*>(this, f, InProperty); }
	UFunction* FindFunctionByName(FName InName, EIncludeSuperFlag::Type IncludeSuper) { static NativeFunction f{ "UClass.FindFunctionByName" }; return NativeCall<UFunction*, FName, EIncludeSuperFlag::Type>(this, f, InName, IncludeSuper); }
	FString* GetConfigName(FString* result) { static NativeFunction f{ "UClass.GetConfigName" }; return NativeCall<FString*, FString*>(this, f, result); }
	void AssembleReferenceTokenStream() { static NativeFunction f{ "UClass.AssembleReferenceTokenStream" }; NativeCall<void>(this, f); }
};

struct UBlueprintCore : UObject
{
	[[deprecated("no class symbol for UBlueprintCore in this game build, this returns UObject's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UBlueprintCore.StaticClass"); return UObject::StaticClass(); }
	[[deprecated("no class symbol for UBlueprintCore in this game build, this returns UObject's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UBlueprintCore.GetPrivateStaticClass"); return UObject::StaticClass(); }
	TSubclassOf<UObject>& SkeletonGeneratedClassField() { static NativeFieldOffset f{ "UBlueprintCore.SkeletonGeneratedClass" }; return *GetNativePointerField<TSubclassOf<UObject>*>(this, f); }
	TSubclassOf<UObject>& GeneratedClassField() { static NativeFieldOffset f{ "UBlueprintCore.GeneratedClass" }; return *GetNativePointerField<TSubclassOf<UObject>*>(this, f); }
	bool& bLegacyNeedToPurgeSkelRefsField() { static NativeFieldOffset f{ "UBlueprintCore.bLegacyNeedToPurgeSkelRefs" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bLegacyGeneratedClassIsAuthoritativeField() { static NativeFieldOffset f{ "UBlueprintCore.bLegacyGeneratedClassIsAuthoritative" }; return *GetNativePointerField<bool*>(this, f); }
	FGuid& BlueprintGuidField() { static NativeFieldOffset f{ "UBlueprintCore.BlueprintGuid" }; return *GetNativePointerField<FGuid*>(this, f); }

	// Functions

	void GenerateDeterministicGuid() { static NativeFunction f{ "UBlueprintCore.GenerateDeterministicGuid" }; NativeCall<void>(this, f); }
};

struct UBlueprint : UBlueprintCore
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UBlueprint.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	TSubclassOf<UObject>& ParentClassField() { static NativeFieldOffset f{ "UBlueprint.ParentClass" }; return *GetNativePointerField<TSubclassOf<UObject>*>(this, f); }
	UObject* PRIVATE_InnermostPreviousCDOField() { static NativeFieldOffset f{ "UBlueprint.PRIVATE_InnermostPreviousCDO" }; return *GetNativePointerField<UObject**>(this, f); }
	TArray<UActorComponent*>& ComponentTemplatesField() { static NativeFieldOffset f{ "UBlueprint.ComponentTemplates" }; return *GetNativePointerField<TArray<UActorComponent*>*>(this, f); }
	TEnumAsByte<enum EBlueprintType>& BlueprintTypeField() { static NativeFieldOffset f{ "UBlueprint.BlueprintType" }; return *GetNativePointerField<TEnumAsByte<enum EBlueprintType>*>(this, f); }
	int& BlueprintSystemVersionField() { static NativeFieldOffset f{ "UBlueprint.BlueprintSystemVersion" }; return *GetNativePointerField<int*>(this, f); }

	// Functions

	FString* GetDesc(FString* result) { static NativeFunction f{ "UBlueprint.GetDesc" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool NeedsLoadForClient() { static NativeFunction f{ "UBlueprint.NeedsLoadForClient" }; return NativeCall<bool>(this, f); }
	bool NeedsLoadForServer() { static NativeFunction f{ "UBlueprint.NeedsLoadForServer" }; return NativeCall<bool>(this, f); }
	void TagSubobjects(EObjectFlags NewFlags) { static NativeFunction f{ "UBlueprint.TagSubobjects" }; NativeCall<void, EObjectFlags>(this, f, NewFlags); }
};

struct UProperty : UField
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	int& ArrayDimField() { static NativeFieldOffset f{ "UProperty.ArrayDim" }; return *GetNativePointerField<int*>(this, f); }
	int& ElementSizeField() { static NativeFieldOffset f{ "UProperty.ElementSize" }; return *GetNativePointerField<int*>(this, f); }
	unsigned __int64& PropertyFlagsField() { static NativeFieldOffset f{ "UProperty.PropertyFlags" }; return *GetNativePointerField<unsigned __int64*>(this, f); }
	unsigned __int16& RepIndexField() { static NativeFieldOffset f{ "UProperty.RepIndex" }; return *GetNativePointerField<unsigned __int16*>(this, f); }
	FName& RepNotifyFuncField() { static NativeFieldOffset f{ "UProperty.RepNotifyFunc" }; return *GetNativePointerField<FName*>(this, f); }
	int& Offset_InternalField() { static NativeFieldOffset f{ "UProperty.Offset_Internal" }; return *GetNativePointerField<int*>(this, f); }
	UProperty* PropertyLinkNextField() { static NativeFieldOffset f{ "UProperty.PropertyLinkNext" }; return *GetNativePointerField<UProperty**>(this, f); }
	UProperty* NextRefField() { static NativeFieldOffset f{ "UProperty.NextRef" }; return *GetNativePointerField<UProperty**>(this, f); }
	UProperty* DestructorLinkNextField() { static NativeFieldOffset f{ "UProperty.DestructorLinkNext" }; return *GetNativePointerField<UProperty**>(this, f); }
	UProperty* PostConstructLinkNextField() { static NativeFieldOffset f{ "UProperty.PostConstructLinkNext" }; return *GetNativePointerField<UProperty**>(this, f); }

	// Functions

	bool Identical(const void* A, const void* B, unsigned int PortFlags) { static NativeFunction f{ "UProperty.Identical" }; return NativeCall<bool, const void*, const void*, unsigned int>(this, f, A, B, PortFlags); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
	void CopySingleValueFromScriptVM(void* Dest, const void* Src) { static NativeFunction f{ "UProperty.CopySingleValueFromScriptVM" }; NativeCall<void, void*, const void*>(this, f, Dest, Src); }
	void CopyCompleteValueFromScriptVM(void* Dest, const void* Src) { static NativeFunction f{ "UProperty.CopyCompleteValueFromScriptVM" }; NativeCall<void, void*, const void*>(this, f, Dest, Src); }
	FString* GetCPPType(FString* result, FString* ExtendedTypeText, unsigned int CPPExportFlags) { static NativeFunction f{ "UProperty.GetCPPType" }; return NativeCall<FString*, FString*, FString*, unsigned int>(this, f, result, ExtendedTypeText, CPPExportFlags); }
	bool Identical_InContainer(const void* A, const void* B, int ArrayIndex, unsigned int PortFlags) { static NativeFunction f{ "UProperty.Identical_InContainer" }; return NativeCall<bool, const void*, const void*, int, unsigned int>(this, f, A, B, ArrayIndex, PortFlags); }
	bool ShouldDuplicateValue() { static NativeFunction f{ "UProperty.ShouldDuplicateValue" }; return NativeCall<bool>(this, f); }
	FString* GetCPPMacroType(FString* result, FString* ExtendedTypeText) { static NativeFunction f{ "UProperty.GetCPPMacroType" }; return NativeCall<FString*, FString*, FString*>(this, f, result, ExtendedTypeText); }
	bool ExportText_Direct(FString* ValueStr, const void* Data, const void* Delta, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UProperty.ExportText_Direct" }; return NativeCall<bool, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, Data, Delta, Parent, PortFlags, ExportRootScope); }
	bool IsLocalized() { static NativeFunction f{ "UProperty.IsLocalized" }; return NativeCall<bool>(this, f); }
	bool ShouldPort(unsigned int PortFlags) { static NativeFunction f{ "UProperty.ShouldPort" }; return NativeCall<bool, unsigned int>(this, f, PortFlags); }
	FName* GetID(FName* result) { static NativeFunction f{ "UProperty.GetID" }; return NativeCall<FName*, FName*>(this, f, result); }
	bool SameType(UProperty* Other) { static NativeFunction f{ "UProperty.SameType" }; return NativeCall<bool, UProperty*>(this, f, Other); }

	template<typename T>
	T Get(UObject* object)
	{
		if (!object->ClassField()->HasProperty(this))
			throw std::invalid_argument("Object does not contain this property.");
		if (sizeof(T) != this->ElementSizeField())
			throw std::invalid_argument("Expected size does not match property size.");
		return *reinterpret_cast<T*>(reinterpret_cast<char*>(object) + this->Offset_InternalField());
	}

	template<typename T>
	void Set(UObject* object, T value)
	{
		if (!object->ClassField()->HasProperty(this))
			throw std::invalid_argument("Object does not contain this property.");
		if (sizeof(T) != this->ElementSizeField())
			throw std::invalid_argument("Expected size does not match property size.");
		*reinterpret_cast<T*>(reinterpret_cast<char*>(object) + this->Offset_InternalField()) = value;
	}
};

struct  UScriptStruct : UStruct
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UScriptStruct.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
};

struct UObjectPropertyBase : UProperty
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UObjectPropertyBase.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	UClass* PropertyClassField() { static NativeFieldOffset f{ "UObjectPropertyBase.PropertyClass" }; return *GetNativePointerField<UClass**>(this, f); }
};

struct  UStructProperty : UProperty
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UStructProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	UScriptStruct* StructField() { static NativeFieldOffset f{ "UStructProperty.Struct" }; return *GetNativePointerField<UScriptStruct* *>(this, f); }
	void ExportTextItem(
		FString* ValueStr,
		const void* PropertyValue,
		const void* DefaultValue,
		UObject* Parent,
		int PortFlags,
		UObject* ExportRootScope
	) {
		static NativeFunction f{ "UStructProperty.ExportTextItem" };
		NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope);
	}
};

template<typename InTCppType> struct TPropertyTypeFundamentals {};
template<typename InTCppType, class TInPropertyBaseClass> 
struct TProperty : public TInPropertyBaseClass, public TPropertyTypeFundamentals<InTCppType> {};
template<typename InTCppType> struct TUObjectPropertyBase : public TProperty<InTCppType, UObjectPropertyBase> {};

struct UObjectProperty : TUObjectPropertyBase<UObject*> { 
	static UClass* StaticClass() { static NativeStaticClass f{ "UObjectProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UObjectPropertyBase.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};
struct UClassProperty : UObjectProperty {
	static UClass* StaticClass() { static NativeStaticClass f{ "UClassProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UObjectPropertyBase.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UTextProperty : UProperty {
	[[deprecated("no class symbol for UTextProperty in this game build, this returns UProperty's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UTextProperty.StaticClass"); return UProperty::StaticClass(); }
	[[deprecated("no class symbol for UTextProperty in this game build, this returns UProperty's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UTextProperty.GetPrivateStaticClass"); return UProperty::StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UTextProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UDelegateProperty : UProperty {
	static UClass* StaticClass() { static NativeStaticClass f{ "UDelegateProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UDelegateProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UMulticastDelegateProperty : UProperty {
	[[deprecated("no class symbol for UMulticastDelegateProperty in this game build, this returns UProperty's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UMulticastDelegateProperty.StaticClass"); return UProperty::StaticClass(); }
	[[deprecated("no class symbol for UMulticastDelegateProperty in this game build, this returns UProperty's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UMulticastDelegateProperty.GetPrivateStaticClass"); return UProperty::StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UMulticastDelegateProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UWeakObjectProperty : UProperty {
	[[deprecated("no class symbol for UWeakObjectProperty in this game build, this returns UObjectPropertyBase's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UWeakObjectProperty.StaticClass"); return UObjectPropertyBase::StaticClass(); }
	[[deprecated("no class symbol for UWeakObjectProperty in this game build, this returns UObjectPropertyBase's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UWeakObjectProperty.GetPrivateStaticClass"); return UObjectPropertyBase::StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UObjectPropertyBase.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UInterfaceProperty : UProperty {
	[[deprecated("no class symbol for UInterfaceProperty in this game build, this returns UProperty's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UInterfaceProperty.StaticClass"); return UProperty::StaticClass(); }
	[[deprecated("no class symbol for UInterfaceProperty in this game build, this returns UProperty's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UInterfaceProperty.GetPrivateStaticClass"); return UProperty::StaticClass(); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UInterfaceProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UArrayProperty : UProperty {
	static UClass* StaticClass() { static NativeStaticClass f{ "UArrayProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	void ExportTextItem(
		FString* ValueStr,
		const void* PropertyValue,
		const void* DefaultValue,
		UObject* Parent,
		int PortFlags,
		UObject* ExportRootScope
	) { static NativeFunction f{ "UArrayProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
};

struct UNumericProperty : UProperty
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UNumericProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	__int64 GetSignedIntPropertyValue(void const* Data) { static NativeFunction f{ "UNumericProperty.GetSignedIntPropertyValue" }; return NativeCall<__int64, void const*>(this, f, Data); }
	double GetFloatingPointPropertyValue(void const* Data) { static NativeFunction f{ "UNumericProperty.GetFloatingPointPropertyValue" }; return NativeCall<double, void const*>(this, f, Data); }
	unsigned __int64 GetUnsignedIntPropertyValue(void const* Data) { static NativeFunction f{ "UNumericProperty.GetUnsignedIntPropertyValue" }; return NativeCall<unsigned __int64, void const*>(this, f, Data); }
};

struct UBoolProperty : UProperty
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UBoolProperty.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	char& FieldSizeField() { static NativeFieldOffset f{ "UBoolProperty.FieldSize" }; return *GetNativePointerField<char*>(this, f); }
	char& ByteOffsetField() { static NativeFieldOffset f{ "UBoolProperty.ByteOffset" }; return *GetNativePointerField<char*>(this, f); }
	char& ByteMaskField() { static NativeFieldOffset f{ "UBoolProperty.ByteMask" }; return *GetNativePointerField<char*>(this, f); }
	char& FieldMaskField() { static NativeFieldOffset f{ "UBoolProperty.FieldMask" }; return *GetNativePointerField<char*>(this, f); }

	// Functions

	static void* operator new(const unsigned __int64 InSize, UObject* InOuter, FName InName, EObjectFlags InSetFlags) { static NativeFunction f{ "UBoolProperty.operator new" }; return NativeCall<void*, const unsigned __int64, UObject*, FName, EObjectFlags>(nullptr, f, InSize, InOuter, InName, InSetFlags); }
	void SetBoolSize(const unsigned int InSize, const bool bIsNativeBool, const unsigned int InBitMask) { static NativeFunction f{ "UBoolProperty.SetBoolSize" }; NativeCall<void, const unsigned int, const bool, const unsigned int>(this, f, InSize, bIsNativeBool, InBitMask); }
	int GetMinAlignment() { static NativeFunction f{ "UBoolProperty.GetMinAlignment" }; return NativeCall<int>(this, f); }
	FString* GetCPPType(FString* result, FString* ExtendedTypeText, unsigned int CPPExportFlags) { static NativeFunction f{ "UBoolProperty.GetCPPType" }; return NativeCall<FString*, FString*, FString*, unsigned int>(this, f, result, ExtendedTypeText, CPPExportFlags); }
	FString* GetCPPMacroType(FString* result, FString* ExtendedTypeText) { static NativeFunction f{ "UBoolProperty.GetCPPMacroType" }; return NativeCall<FString*, FString*, FString*>(this, f, result, ExtendedTypeText); }
	void ExportTextItem(FString* ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int PortFlags, UObject* ExportRootScope) { static NativeFunction f{ "UBoolProperty.ExportTextItem" }; NativeCall<void, FString*, const void*, const void*, UObject*, int, UObject*>(this, f, ValueStr, PropertyValue, DefaultValue, Parent, PortFlags, ExportRootScope); }
	bool Identical(const void* A, const void* B, unsigned int PortFlags) { static NativeFunction f{ "UBoolProperty.Identical" }; return NativeCall<bool, const void*, const void*, unsigned int>(this, f, A, B, PortFlags); }
	void CopyValuesInternal(void* Dest, const void* Src, int Count) { static NativeFunction f{ "UBoolProperty.CopyValuesInternal" }; NativeCall<void, void*, const void*, int>(this, f, Dest, Src, Count); }
	void ClearValueInternal(void* Data) { static NativeFunction f{ "UBoolProperty.ClearValueInternal" }; NativeCall<void, void*>(this, f, Data); }
};

//not using this right now so leave empty
struct FObjectInstancingGraph
{
	/*UObject *SourceRoot;
	UObject *DestinationRoot;
	bool bCreatingArchetype;
	bool bEnableSubobjectInstancing;
	bool bLoadingObject;
	TMap<UObject *, UObject *, FDefaultSetAllocator, TDefaultMapKeyFuncs<UObject *, UObject *, 0> > SourceToDestinationMap;*/
};

namespace API
{
	// map shared between threads
	template <typename Key, typename Value>
	class SharedCache
	{
	public:
		constexpr SharedCache() noexcept = default;
		SharedCache(const SharedCache&) = delete;
		SharedCache& operator=(const SharedCache&) = delete;

		~SharedCache()
		{
			delete map_;
		}

		bool Find(const Key& key, Value& value)
		{
			Lock lock(&lock_, false);
			if (map_ == nullptr)
				return false;

			const auto iter = map_->find(key);
			if (iter == map_->end())
				return false;

			value = iter->second;
			return true;
		}

		void Set(const Key& key, const Value& value)
		{
			Lock lock(&lock_, true);
			if (map_ == nullptr)
				map_ = new std::unordered_map<Key, Value>();

			(*map_)[key] = value;
		}

		void Erase(const Key& key)
		{
			Lock lock(&lock_, true);
			if (map_ != nullptr)
				map_->erase(key);
		}

	private:
		struct Lock
		{
			Lock(SRWLOCK* lock, bool exclusive)
				: lock_(lock), exclusive_(exclusive)
			{
				exclusive_ ? AcquireSRWLockExclusive(lock_) : AcquireSRWLockShared(lock_);
			}

			~Lock()
			{
				exclusive_ ? ReleaseSRWLockExclusive(lock_) : ReleaseSRWLockShared(lock_);
			}

			Lock(const Lock&) = delete;
			Lock& operator=(const Lock&) = delete;

			SRWLOCK* lock_;
			bool exclusive_;
		};

		SRWLOCK lock_ = SRWLOCK_INIT;
		std::unordered_map<Key, Value>* map_ = nullptr;
	};
}

struct Globals
{
	//void __fastcall GetObjectsOfClass(UClass *ClassToLookFor, TArray<UObject *,FDefaultAllocator> *Results, bool bIncludeDerivedClasses, EObjectFlags ExclusionFlags)
	static void GetObjectsOfClass(UClass* ClassToLookFor, TArray<UObject*, FDefaultAllocator>* Results, bool bIncludeDerivedClasses, EObjectFlags ExclusionFlags)
	{
		static NativeFunction f{ "Global.GetObjectsOfClass" };
		NativeCall<void, UClass*, TArray<UObject*, FDefaultAllocator>*, bool, EObjectFlags >(
			nullptr, f, ClassToLookFor, Results, bIncludeDerivedClasses, ExclusionFlags);
	}

	static UObject* StaticLoadObject(UClass* ObjectClass, UObject* InOuter, const wchar_t* InName, const wchar_t* Filename,
		unsigned int LoadFlags, DWORD64 Sandbox, bool bAllowObjectReconciliation)
	{
		static NativeFunction f{ "Global.StaticLoadObject" };
		return NativeCall<UObject*, UClass*, UObject*, const wchar_t*, const wchar_t*, unsigned int, DWORD64, bool>(
			nullptr, f, ObjectClass, InOuter, InName, Filename, LoadFlags, Sandbox,
			bAllowObjectReconciliation);
	}

	//UObject *__fastcall StaticConstructObject(UClass *InClass, UObject *InOuter, FName InName, EObjectFlags InFlags, UObject *InTemplate, bool bCopyTransientsFromClassDefaults, FObjectInstancingGraph *InInstanceGraph)
	static UObject* StaticConstructObject(UClass* InClass, UObject* InOuter, FName InName, EObjectFlags InFlags,
		UObject* InTemplate, bool bCopyTransientsFromClassDefaults,
		FObjectInstancingGraph* InInstanceGraph)
	{
		static NativeFunction f{ "Global.StaticConstructObject" };
		return NativeCall<UObject*, UClass*, UObject*, FName, EObjectFlags, UObject*, bool, FObjectInstancingGraph*>(
			nullptr, f, InClass, InOuter, InName, InFlags, InTemplate,
			bCopyTransientsFromClassDefaults, InInstanceGraph);
	}

	//UObject *__fastcall StaticFindObjectFastInternal(UClass *ObjectClass, UObject *ObjectPackage, FName ObjectName, bool bExactClass, bool bAnyPackage, EObjectFlags ExcludeFlags)
	template <typename T>
	static void GetPrivateStaticClassBody(const wchar_t* PackageName, const wchar_t* Name, T** ReturnClass,
		void(__cdecl* RegisterNativeFunc)());

	/*template <>
	static void GetPrivateStaticClassBody<UClass>(const wchar_t *PackageName, const wchar_t *Name, UClass **ReturnClass, void(__cdecl *RegisterNativeFunc)()) {
	return NativeCall<void, const wchar_t *, const wchar_t *, UClass **, void(__cdecl *)()>(nullptr, "Global.GetPrivateStaticClassBody<UClass>", PackageName, Name, ReturnClass, RegisterNativeFunc);
	}*/

	//void __fastcall GetPrivateStaticClassBody<UClass>(const wchar_t *PackageName, const wchar_t *Name, UClass **ReturnClass, void(__cdecl *RegisterNativeFunc)())

	//static char RaycastSingle(UWorld *World, FHitResult *OutHit, FVector *Start, FVector *End, ECollisionChannel TraceChannel, FCollisionQueryParams *Params, FCollisionResponseParams *ResponseParams, FCollisionObjectQueryParams *ObjectParams) { return NativeCall<char, UWorld *, FHitResult *, FVector *, FVector *, ECollisionChannel, FCollisionQueryParams *, FCollisionResponseParams *, FCollisionObjectQueryParams *>(nullptr, "Global.RaycastSingle", World, OutHit, Start, End, TraceChannel, Params, ResponseParams, ObjectParams); }
	//char RaycastSingle(UWorld *World, FHitResult *OutHit, FVector *Start, FVector *End, ECollisionChannel TraceChannel, FCollisionQueryParams *Params, FCollisionResponseParams *ResponseParams, FCollisionObjectQueryParams *ObjectParams)

	static bool HasClassCastFlags(UObject* object, ClassCastFlags flags)
	{
		const auto flags_value = static_cast<std::underlying_type<ClassCastFlags>::type>(flags);
		return object != nullptr && (object->ClassField()->ClassCastFlagsField() & flags_value) == flags_value;
	}

	static bool HasClassCastFlags(UClass* _class, ClassCastFlags flags)
	{
		const auto flags_value = static_cast<std::underlying_type<ClassCastFlags>::type>(flags);
		return _class != nullptr && (_class->ClassCastFlagsField() & flags_value) == flags_value;
	}

	static DataValue<UEngine*> GEngine() { return { "Global.GEngine" }; }

	static DataValue<FUObjectArray> GUObjectArray() { return { "Global.GUObjectArray" }; }

	static FORCEINLINE UClass* FindClass(const std::string& name)
	{
		intptr_t class_offset = 0;
		intptr_t cast_flags_offset = 0;
		if (!FindNativeOffset("UObjectBase.Class", &class_offset) || !FindNativeOffset("UClass.ClassCastFlags", &cast_flags_offset))
			return nullptr;

		auto& objects = Globals::GUObjectArray()().ObjObjects;
		const auto class_flag = static_cast<unsigned long long>(ClassCastFlags::CASTCLASS_UClass);

		const auto is_class_named = [&](UObject* obj)
		{
			auto* obj_class = *reinterpret_cast<UClass**>(reinterpret_cast<char*>(obj) + class_offset);
			if (obj_class == nullptr || (*reinterpret_cast<unsigned long long*>(reinterpret_cast<char*>(obj_class) + cast_flags_offset) & class_flag) == 0)
				return false;

			FString full_name;
			obj->GetFullName(&full_name, nullptr);
			return name == full_name.ToString();
		};

		// only valid while the slot still holds that class
		FindClassEntry cached{};
		if (FindClassCache.Find(name, cached))
		{
			auto* item = cached.Index < objects.NumElements ? objects.GetObjectPtr(cached.Index) : nullptr;
			if (item != nullptr && item->Object == cached.Class && cached.Class != nullptr && is_class_named(cached.Class))
				return reinterpret_cast<UClass*>(cached.Class);

			FindClassCache.Erase(name);
		}

		for (auto i = 0; i < objects.NumElements; i++)
		{
			auto* item = objects.GetObjectPtr(i);
			auto obj = item != nullptr ? item->Object : nullptr;
			if (obj == nullptr)
				continue;

			if (is_class_named(obj))
			{
				FindClassCache.Set(name, { obj, i });
				return (UClass*)obj;
			}
		}
		return nullptr;
	}

	struct FindClassEntry
	{
		UObject* Class;
		int Index;
	};

	inline static API::SharedCache<std::string, FindClassEntry> FindClassCache;
};

template <>
inline void Globals::GetPrivateStaticClassBody<UClass>(const wchar_t* PackageName, const wchar_t* Name,
	UClass** ReturnClass, void(__cdecl* RegisterNativeFunc)())
{
	static NativeFunction f{ "Global.GetPrivateStaticClassBody<UClass>" };
	return NativeCall<void, const wchar_t*, const wchar_t*, UClass**, void(__cdecl*)()>(
		nullptr, f, PackageName, Name, ReturnClass, RegisterNativeFunc);
}

struct FAssetData
{
	FName ObjectPath;
	FName PackageName;
	FName PackagePath;
	FName GroupNames;
	FName AssetName;
	FName AssetClass;
	char unk[80];// TMap<FName, FString<FName, FString> > TagsAndValues;
	TArray<int> ChunkIDs;

	// Functions

	bool IsUAsset() { static NativeFunction f{ "FAssetData.IsUAsset" }; return NativeCall<bool>(this, f); }
	void PrintAssetData() { static NativeFunction f{ "FAssetData.PrintAssetData" }; NativeCall<void>(this, f); }
	UObject* GetAsset() { static NativeFunction f{ "FAssetData.GetAsset" }; return NativeCall<UObject*>(this, f); }
};

struct IModuleInterface
{
};

struct IAssetRegistryInterface : IModuleInterface
{
};

struct FAssetRegistryModule : IAssetRegistryInterface
{
	FAssetRegistry* Get() { static NativeFunction f{ "FAssetRegistryModule.Get" }; return NativeCall<FAssetRegistry*>(this, f); }
};

struct FModuleManager
{
	static FModuleManager* Get() { static NativeFunction f{ "FModuleManager.Get" }; return NativeCall<FModuleManager*>(nullptr, f); }
	void FindModules(const wchar_t* WildcardWithoutExtension, TArray<FName>* OutModules) { static NativeFunction f{ "FModuleManager.FindModules" }; NativeCall<void, const wchar_t*, TArray<FName>*>(this, f, WildcardWithoutExtension, OutModules); }
	bool IsModuleLoaded(FName InModuleName) { static NativeFunction f{ "FModuleManager.IsModuleLoaded" }; return NativeCall<bool, FName>(this, f, InModuleName); }
	bool IsModuleUpToDate(FName InModuleName) { static NativeFunction f{ "FModuleManager.IsModuleUpToDate" }; return NativeCall<bool, FName>(this, f, InModuleName); }
	void AddModule(FName InModuleName) { static NativeFunction f{ "FModuleManager.AddModule" }; NativeCall<void, FName>(this, f, InModuleName); }
	[[deprecated("not in this game build")]] void FModuleInfo() { ReportDeprecatedApiUse("FModuleManager.FModuleInfo"); static NativeFunction f{ "FModuleManager.FModuleInfo" }; NativeCall<void>(this, f); }
	TSharedPtr<IModuleInterface>* LoadModule(TSharedPtr<IModuleInterface>* result, FName InModuleName, const bool bWasReloaded) { static NativeFunction f{ "FModuleManager.LoadModule" }; return NativeCall<TSharedPtr<IModuleInterface>*, TSharedPtr<IModuleInterface>*, FName, const bool>(this, f, result, InModuleName, bWasReloaded); }
	bool UnloadModule(FName InModuleName, bool bIsShutdown) { static NativeFunction f{ "FModuleManager.UnloadModule" }; return NativeCall<bool, FName, bool>(this, f, InModuleName, bIsShutdown); }
	void UnloadModulesAtShutdown() { static NativeFunction f{ "FModuleManager.UnloadModulesAtShutdown" }; NativeCall<void>(this, f); }
	TSharedPtr<IModuleInterface>* GetModule(TSharedPtr<IModuleInterface>* result, FName InModuleName) { static NativeFunction f{ "FModuleManager.GetModule" }; return NativeCall<TSharedPtr<IModuleInterface>*, TSharedPtr<IModuleInterface>*, FName>(this, f, result, InModuleName); }
	static FString* GetCleanModuleFilename(FString* result, FName ModuleName, bool bGameModule) { static NativeFunction f{ "FModuleManager.GetCleanModuleFilename" }; return NativeCall<FString*, FString*, FName, bool>(nullptr, f, result, ModuleName, bGameModule); }
	static void GetModuleFilenameFormat(bool bGameModule, FString* OutPrefix, FString* OutSuffix) { static NativeFunction f{ "FModuleManager.GetModuleFilenameFormat" }; NativeCall<void, bool, FString*, FString*>(nullptr, f, bGameModule, OutPrefix, OutSuffix); }
	void AddBinariesDirectory(const wchar_t* InDirectory, bool bIsGameDirectory) { static NativeFunction f{ "FModuleManager.AddBinariesDirectory" }; NativeCall<void, const wchar_t*, bool>(this, f, InDirectory, bIsGameDirectory); }
};

struct FAssetRegistry
{
	void CollectCodeGeneratorClasses() { static NativeFunction f{ "FAssetRegistry.CollectCodeGeneratorClasses" }; NativeCall<void>(this, f); }
	void SearchAllAssets(bool bSynchronousSearch) { static NativeFunction f{ "FAssetRegistry.SearchAllAssets" }; NativeCall<void, bool>(this, f, bSynchronousSearch); }
	bool GetAssetsByPackageName(FName PackageName, TArray<FAssetData>* OutAssetData) { static NativeFunction f{ "FAssetRegistry.GetAssetsByPackageName" }; return NativeCall<bool, FName, TArray<FAssetData>*>(this, f, PackageName, OutAssetData); }
	bool GetAssetsByPath(FName PackagePath, TArray<FAssetData>* OutAssetData, bool bRecursive) { static NativeFunction f{ "FAssetRegistry.GetAssetsByPath" }; return NativeCall<bool, FName, TArray<FAssetData>*, bool>(this, f, PackagePath, OutAssetData, bRecursive); }
	bool GetAssetsByClass(FName ClassName, TArray<FAssetData>* OutAssetData, bool bSearchSubClasses) { static NativeFunction f{ "FAssetRegistry.GetAssetsByClass" }; return NativeCall<bool, FName, TArray<FAssetData>*, bool>(this, f, ClassName, OutAssetData, bSearchSubClasses); }
	//bool GetAssetsByTagValues(TMultiMap<FName, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FName, FString, 1> > * AssetTagsAndValues, TArray<FAssetData> * OutAssetData) { return NativeCall<bool, TMultiMap<FName, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FName, FString, 1> > *, TArray<FAssetData> *>(this, "FAssetRegistry.GetAssetsByTagValues", AssetTagsAndValues, OutAssetData); }
	//bool GetAssets(FARFilter * Filter, TArray<FAssetData> * OutAssetData) { return NativeCall<bool, FARFilter *, TArray<FAssetData> *>(this, "FAssetRegistry.GetAssets", Filter, OutAssetData); }
	FAssetData* GetAssetByObjectPath(FAssetData* result, FName ObjectPath) { static NativeFunction f{ "FAssetRegistry.GetAssetByObjectPath" }; return NativeCall<FAssetData*, FAssetData*, FName>(this, f, result, ObjectPath); }
	bool GetAllAssets(TArray<FAssetData>* OutAssetData) { static NativeFunction f{ "FAssetRegistry.GetAllAssets" }; return NativeCall<bool, TArray<FAssetData>*>(this, f, OutAssetData); }
	bool GetDependencies(FName PackageName, TArray<FName>* OutDependencies) { static NativeFunction f{ "FAssetRegistry.GetDependencies" }; return NativeCall<bool, FName, TArray<FName>*>(this, f, PackageName, OutDependencies); }
	bool GetReferencers(FName PackageName, TArray<FName>* OutReferencers) { static NativeFunction f{ "FAssetRegistry.GetReferencers" }; return NativeCall<bool, FName, TArray<FName>*>(this, f, PackageName, OutReferencers); }
	bool GetAncestorClassNames(FName ClassName, TArray<FName>* OutAncestorClassNames) { static NativeFunction f{ "FAssetRegistry.GetAncestorClassNames" }; return NativeCall<bool, FName, TArray<FName>*>(this, f, ClassName, OutAncestorClassNames); }
	void GetAllCachedPaths(TArray<FString>* OutPathList) { static NativeFunction f{ "FAssetRegistry.GetAllCachedPaths" }; NativeCall<void, TArray<FString>*>(this, f, OutPathList); }
	void GetSubPaths(FString* InBasePath, TArray<FString>* OutPathList, bool bInRecurse) { static NativeFunction f{ "FAssetRegistry.GetSubPaths" }; NativeCall<void, FString*, TArray<FString>*, bool>(this, f, InBasePath, OutPathList, bInRecurse); }
	EAssetAvailability::Type GetAssetAvailability(FAssetData* AssetData) { static NativeFunction f{ "FAssetRegistry.GetAssetAvailability" }; return NativeCall<EAssetAvailability::Type, FAssetData*>(this, f, AssetData); }
	float GetAssetAvailabilityProgress(FAssetData* AssetData, EAssetAvailabilityProgressReportingType::Type ReportType) { static NativeFunction f{ "FAssetRegistry.GetAssetAvailabilityProgress" }; return NativeCall<float, FAssetData*, EAssetAvailabilityProgressReportingType::Type>(this, f, AssetData, ReportType); }
	bool GetAssetAvailabilityProgressTypeSupported(EAssetAvailabilityProgressReportingType::Type ReportType) { static NativeFunction f{ "FAssetRegistry.GetAssetAvailabilityProgressTypeSupported" }; return NativeCall<bool, EAssetAvailabilityProgressReportingType::Type>(this, f, ReportType); }
	void PrioritizeAssetInstall(FAssetData* AssetData) { static NativeFunction f{ "FAssetRegistry.PrioritizeAssetInstall" }; NativeCall<void, FAssetData*>(this, f, AssetData); }
	bool AddPath(FString* PathToAdd) { static NativeFunction f{ "FAssetRegistry.AddPath" }; return NativeCall<bool, FString*>(this, f, PathToAdd); }
	bool RemovePath(FString* PathToRemove) { static NativeFunction f{ "FAssetRegistry.RemovePath" }; return NativeCall<bool, FString*>(this, f, PathToRemove); }
	void ScanPathsSynchronous(TArray<FString>* InPaths, bool bForceRescan) { static NativeFunction f{ "FAssetRegistry.ScanPathsSynchronous" }; NativeCall<void, TArray<FString>*, bool>(this, f, InPaths, bForceRescan); }
	void PrioritizeSearchPath(FString* PathToPrioritize) { static NativeFunction f{ "FAssetRegistry.PrioritizeSearchPath" }; NativeCall<void, FString*>(this, f, PathToPrioritize); }
	void AssetCreated(UObject* NewAsset) { static NativeFunction f{ "FAssetRegistry.AssetCreated" }; NativeCall<void, UObject*>(this, f, NewAsset); }
	void AssetDeleted(UObject* DeletedAsset) { static NativeFunction f{ "FAssetRegistry.AssetDeleted" }; NativeCall<void, UObject*>(this, f, DeletedAsset); }
	void AssetRenamed(UObject* RenamedAsset, FString* OldObjectPath) { static NativeFunction f{ "FAssetRegistry.AssetRenamed" }; NativeCall<void, UObject*, FString*>(this, f, RenamedAsset, OldObjectPath); }
	bool IsLoadingAssets() { static NativeFunction f{ "FAssetRegistry.IsLoadingAssets" }; return NativeCall<bool>(this, f); }
	void Tick(float DeltaTime) { static NativeFunction f{ "FAssetRegistry.Tick" }; NativeCall<void, float>(this, f, DeltaTime); }
	static bool IsUsingWorldAssets() { static NativeFunction f{ "FAssetRegistry.IsUsingWorldAssets" }; return NativeCall<bool>(nullptr, f); }
	void ScanPathsSynchronous_Internal(TArray<FString>* InPaths, bool bForceRescan, bool bUseCache) { static NativeFunction f{ "FAssetRegistry.ScanPathsSynchronous_Internal" }; NativeCall<void, TArray<FString>*, bool, bool>(this, f, InPaths, bForceRescan, bUseCache); }
	void PathDataGathered(const long double TickStartTime, TArray<FString>* PathResults) { static NativeFunction f{ "FAssetRegistry.PathDataGathered" }; NativeCall<void, const long double, TArray<FString>*>(this, f, TickStartTime, PathResults); }
	bool RemoveDependsNode(FName PackageName) { static NativeFunction f{ "FAssetRegistry.RemoveDependsNode" }; return NativeCall<bool, FName>(this, f, PackageName); }
	bool RemoveAssetPath(FString* PathToRemove, bool bEvenIfAssetsStillExist) { static NativeFunction f{ "FAssetRegistry.RemoveAssetPath" }; return NativeCall<bool, FString*, bool>(this, f, PathToRemove, bEvenIfAssetsStillExist); }
	FString* ExportTextPathToObjectName(FString* result, FString* InExportTextPath) { static NativeFunction f{ "FAssetRegistry.ExportTextPathToObjectName" }; return NativeCall<FString*, FString*, FString*>(this, f, result, InExportTextPath); }
	void AddAssetData(FAssetData* AssetData) { static NativeFunction f{ "FAssetRegistry.AddAssetData" }; NativeCall<void, FAssetData*>(this, f, AssetData); }
	bool RemoveAssetData(FAssetData* AssetData) { static NativeFunction f{ "FAssetRegistry.RemoveAssetData" }; return NativeCall<bool, FAssetData*>(this, f, AssetData); }
	void OnContentPathMounted(FString* InAssetPath, FString* FileSystemPath) { static NativeFunction f{ "FAssetRegistry.OnContentPathMounted" }; NativeCall<void, FString*, FString*>(this, f, InAssetPath, FileSystemPath); }
	void OnContentPathDismounted(FString* InAssetPath, FString* FileSystemPath) { static NativeFunction f{ "FAssetRegistry.OnContentPathDismounted" }; NativeCall<void, FString*, FString*>(this, f, InAssetPath, FileSystemPath); }
	//static void GetAssets(FAssetData ** First, const int Num, TDereferenceWrapper<FAssetData *, `FAssetRegistry::GetAssets'::`124'::FCompareFAssetData> * Predicate) { NativeCall<void, FAssetData **, const int, TDereferenceWrapper<FAssetData *, `FAssetRegistry::GetAssets'::`124'::FCompareFAssetData> *>(nullptr, "FAssetRegistry.GetAssets", First, Num, Predicate); }
};

enum EResourceSizeMode
{
	Exclusive = 0x0,
	Inclusive = 0x1,
	Open = 0x2,
};

struct FRenderResource
{
};

struct FTexture : FRenderResource
{
};

struct FTextureResource : FTexture
{
};

struct UTexture : UObject
{
	[[deprecated("no class symbol for UTexture in this game build, this returns UObject's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UTexture.StaticClass"); return UObject::StaticClass(); }
	[[deprecated("no class symbol for UTexture in this game build, this returns UObject's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UTexture.GetPrivateStaticClass"); return UObject::StaticClass(); }
};

struct UTexture2D : UTexture
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UTexture2D.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	void UpdateResourceW() { static NativeFunction f{ "UTexture2D.UpdateResourceW" }; return NativeCall<void>(this, f); }
	FTextureResource* CreateResource() { static NativeFunction f{ "UTexture2D.CreateResource" }; return NativeCall<FTextureResource*>(this, f); }
	__int64 GetResourceSize(EResourceSizeMode type) { static NativeFunction f{ "UTexture2D.GetResourceSize" }; return NativeCall<__int64, EResourceSizeMode>(this, f, type); }
	float GetSurfaceHeight() { static NativeFunction f{ "UTexture2D.GetSurfaceHeight" }; return NativeCall<float>(this, f); }
	int& SizeX_DEPRECATED() { static NativeFieldOffset f{ "UTexture2D.SizeX_DEPRECATED" }; return *GetNativePointerField<int*>(this, f); }
	int& SizeY_DEPRECATED() { static NativeFieldOffset f{ "UTexture2D.SizeY_DEPRECATED" }; return *GetNativePointerField<int*>(this, f); }
	[[deprecated("not in this game build")]] void GetMipData(int FirstMipToLoad, void** OutMipData) { ReportDeprecatedApiUse("UTexture2D.GetMipData"); static NativeFunction f{ "UTexture2D.GetMipData" }; NativeCall<void, int, void**>(this, f, FirstMipToLoad, OutMipData); }
};

struct FNavigationFilterFlags
{
	uint32_t Flags;
};

struct __declspec(align(8)) UNavArea : UObject
{
	[[deprecated("no class symbol for UNavArea in this game build, this returns UObject's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UNavArea.StaticClass"); return UObject::StaticClass(); }
	[[deprecated("no class symbol for UNavArea in this game build, this returns UObject's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UNavArea.GetPrivateStaticClass"); return UObject::StaticClass(); }
	char UObjectData[0x28];
	float DefaultCost;
	float FixedAreaEnteringCost;
	FColor DrawColor;
	uint32_t unk;
	uint16_t AreaFlags;
};

struct __declspec(align(8)) FNavigationFilterArea
{
	TSubclassOf<UNavArea> AreaClass;
	float TravelCostOverride;
	float EnteringCostOverride;
	uint32_t bIsExcluded : 1;
	uint32_t bOverrideTravelCost : 1;
	uint32_t bOverrideEnteringCost : 1;
};

struct UNavigationQueryFilter : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UNavigationQueryFilter.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	char UObjectData[0x28];
	//TArray<FNavigationFilterArea, FDefaultAllocator> Areas;
	TArray<FNavigationFilterArea> Areas;
	FNavigationFilterFlags IncludeFlags;
	FNavigationFilterFlags ExcludeFlags;
};

// TSet in the engine
struct FCollisionIgnoreActors : TSet<unsigned int>
{
	using TSet::operator[];

	[[deprecated("IgnoreActors is a TSet, index access walks the set")]] unsigned int operator[](int Index) const { return ElementAt(Index); }
	[[deprecated("IgnoreActors is a TSet, index access walks the set")]] unsigned int operator[](int Index) { return ElementAt(Index); }
	[[deprecated("IgnoreActors is a TSet, use Add")]] int AddUnique(unsigned int Id) { ReportDeprecatedApiUse("FCollisionQueryParams::IgnoreActors.AddUnique"); return Add(Id).AsInteger(); }

private:
	unsigned int ElementAt(int Index) const
	{
		ReportDeprecatedApiUse("FCollisionQueryParams::IgnoreActors[]");
		for (const unsigned int Id : *this)
			if (Index-- == 0)
				return Id;
		return 0;
	}
};

struct FCollisionQueryParams
{
	FName TraceTag;
	FName OwnerTag;
	bool bTraceAsyncScene = false;
	bool bTraceComplex = false;
	bool bFindInitialOverlaps = true;
	bool bReturnFaceIndex = false;
	bool bReturnPhysicalMaterial = false;
	FCollisionIgnoreActors IgnoreActors;
};

struct FCollisionResponseContainer
{
	char unk[32];
};

struct FCollisionResponseParams
{
	FCollisionResponseContainer CollisionResponse;
};

struct FCollisionObjectQueryParams
{
	int ObjectTypesToQuery;

	enum InitType
	{
		AllObjects = 0x0,
		AllStaticObjects = 0x1,
		AllDynamicObjects = 0x2,
	};
};

struct FHttpRequestWinInet;

struct FHttpResponseWinInet
{
	FHttpRequestWinInet* RequestField() { static NativeFieldOffset f{ "FHttpResponseWinInet.Request" }; return *GetNativePointerField<FHttpRequestWinInet**>(this, f); }
	int& AsyncBytesReadField() { static NativeFieldOffset f{ "FHttpResponseWinInet.AsyncBytesRead" }; return *GetNativePointerField<int*>(this, f); }
	int& TotalBytesReadField() { static NativeFieldOffset f{ "FHttpResponseWinInet.TotalBytesRead" }; return *GetNativePointerField<int*>(this, f); }
	TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >& ResponseHeadersField() { static NativeFieldOffset f{ "FHttpResponseWinInet.ResponseHeaders" }; return *GetNativePointerField<TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >*>(this, f); }
	int& ResponseCodeField() { static NativeFieldOffset f{ "FHttpResponseWinInet.ResponseCode" }; return *GetNativePointerField<int*>(this, f); }
	int& ContentLengthField() { static NativeFieldOffset f{ "FHttpResponseWinInet.ContentLength" }; return *GetNativePointerField<int*>(this, f); }
	TArray<unsigned char>& ResponsePayloadField() { static NativeFieldOffset f{ "FHttpResponseWinInet.ResponsePayload" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	volatile int& bIsReadyField() { static NativeFieldOffset f{ "FHttpResponseWinInet.bIsReady" }; return *GetNativePointerField<volatile int*>(this, f); }
	volatile int& bResponseSucceededField() { static NativeFieldOffset f{ "FHttpResponseWinInet.bResponseSucceeded" }; return *GetNativePointerField<volatile int*>(this, f); }
	int& MaxReadBufferSizeField() { static NativeFieldOffset f{ "FHttpResponseWinInet.MaxReadBufferSize" }; return *GetNativePointerField<int*>(this, f); }

	// Functions

	~FHttpResponseWinInet() { static NativeFunction f{ "FHttpResponseWinInet.~FHttpResponseWinInet" }; NativeCall<void>(this, f); }
	FString* GetURL(FString* result) { static NativeFunction f{ "FHttpResponseWinInet.GetURL" }; return NativeCall<FString*, FString*>(this, f, result); }
	FString* GetContentAsString(FString* result) { static NativeFunction f{ "FHttpResponseWinInet.GetContentAsString" }; return NativeCall<FString*, FString*>(this, f, result); }
	FString* GetURLParameter(FString* result, FString* ParameterName) { static NativeFunction f{ "FHttpResponseWinInet.GetURLParameter" }; return NativeCall<FString*, FString*, FString*>(this, f, result, ParameterName); }
	FString* GetHeader(FString* result, FString* HeaderName) { static NativeFunction f{ "FHttpResponseWinInet.GetHeader" }; return NativeCall<FString*, FString*, FString*>(this, f, result, HeaderName); }
	TArray<FString>* GetAllHeaders(TArray<FString>* result) { static NativeFunction f{ "FHttpResponseWinInet.GetAllHeaders" }; return NativeCall<TArray<FString>*, TArray<FString>*>(this, f, result); }
	FString* GetContentType(FString* result) { static NativeFunction f{ "FHttpResponseWinInet.GetContentType" }; return NativeCall<FString*, FString*>(this, f, result); }
	int GetContentLength() { static NativeFunction f{ "FHttpResponseWinInet.GetContentLength" }; return NativeCall<int>(this, f); }
	TArray<unsigned char>* GetContent() { static NativeFunction f{ "FHttpResponseWinInet.GetContent" }; return NativeCall<TArray<unsigned char>*>(this, f); }
	int GetResponseCode() { static NativeFunction f{ "FHttpResponseWinInet.GetResponseCode" }; return NativeCall<int>(this, f); }
	void ProcessResponse() { static NativeFunction f{ "FHttpResponseWinInet.ProcessResponse" }; NativeCall<void>(this, f); }
	void ProcessResponseHeaders() { static NativeFunction f{ "FHttpResponseWinInet.ProcessResponseHeaders" }; NativeCall<void>(this, f); }
	FString* QueryHeaderString(FString* result, unsigned int HttpQueryInfoLevel, FString* HeaderName) { static NativeFunction f{ "FHttpResponseWinInet.QueryHeaderString" }; return NativeCall<FString*, FString*, unsigned int, FString*>(this, f, result, HttpQueryInfoLevel, HeaderName); }
	int QueryContentLength() { static NativeFunction f{ "FHttpResponseWinInet.QueryContentLength" }; return NativeCall<int>(this, f); }
};

struct IHttpResponse : FHttpResponseWinInet
{
};

struct FHttpRequestWinInet
{
	FString& RequestVerbField() { static NativeFieldOffset f{ "FHttpRequestWinInet.RequestVerb" }; return *GetNativePointerField<FString*>(this, f); }
	TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >& RequestHeadersField() { static NativeFieldOffset f{ "FHttpRequestWinInet.RequestHeaders" }; return *GetNativePointerField<TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >*>(this, f); }
	TArray<unsigned char>& RequestPayloadField() { static NativeFieldOffset f{ "FHttpRequestWinInet.RequestPayload" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	TSharedPtr<FHttpResponseWinInet, 1>& ResponseField() { static NativeFieldOffset f{ "FHttpRequestWinInet.Response" }; return *GetNativePointerField<TSharedPtr<FHttpResponseWinInet, 1>*>(this, f); }
	EHttpRequestStatus::Type& CompletionStatusField() { static NativeFieldOffset f{ "FHttpRequestWinInet.CompletionStatus" }; return *GetNativePointerField<EHttpRequestStatus::Type*>(this, f); }
	void* ConnectionHandleField() { static NativeFieldOffset f{ "FHttpRequestWinInet.ConnectionHandle" }; return *GetNativePointerField<void**>(this, f); }
	void* RequestHandleField() { static NativeFieldOffset f{ "FHttpRequestWinInet.RequestHandle" }; return *GetNativePointerField<void**>(this, f); }
	volatile int& ElapsedTimeSinceLastServerResponseField() { static NativeFieldOffset f{ "FHttpRequestWinInet.ElapsedTimeSinceLastServerResponse" }; return *GetNativePointerField<volatile int*>(this, f); }
	int& ProgressBytesSentField() { static NativeFieldOffset f{ "FHttpRequestWinInet.ProgressBytesSent" }; return *GetNativePointerField<int*>(this, f); }
	long double& StartRequestTimeField() { static NativeFieldOffset f{ "FHttpRequestWinInet.StartRequestTime" }; return *GetNativePointerField<long double*>(this, f); }
	bool& bDebugVerboseField() { static NativeFieldOffset f{ "FHttpRequestWinInet.bDebugVerbose" }; return *GetNativePointerField<bool*>(this, f); }

	// Functions

	~FHttpRequestWinInet() { static NativeFunction f{ "FHttpRequestWinInet.~FHttpRequestWinInet" }; NativeCall<void>(this, f); }
	FString* GetURL(FString* result) { static NativeFunction f{ "FHttpRequestWinInet.GetURL" }; return NativeCall<FString*, FString*>(this, f, result); }
	FString* GetURLParameter(FString* result, FString* ParameterName) { static NativeFunction f{ "FHttpRequestWinInet.GetURLParameter" }; return NativeCall<FString*, FString*, FString*>(this, f, result, ParameterName); }
	FString* GetHeader(FString* result, FString* HeaderName) { static NativeFunction f{ "FHttpRequestWinInet.GetHeader" }; return NativeCall<FString*, FString*, FString*>(this, f, result, HeaderName); }
	TArray<FString>* GetAllHeaders(TArray<FString>* result) { static NativeFunction f{ "FHttpRequestWinInet.GetAllHeaders" }; return NativeCall<TArray<FString>*, TArray<FString>*>(this, f, result); }
	FString* GetContentType(FString* result) { static NativeFunction f{ "FHttpRequestWinInet.GetContentType" }; return NativeCall<FString*, FString*>(this, f, result); }
	int GetContentLength() { static NativeFunction f{ "FHttpRequestWinInet.GetContentLength" }; return NativeCall<int>(this, f); }
	FString* GetVerb(FString* result) { static NativeFunction f{ "FHttpRequestWinInet.GetVerb" }; return NativeCall<FString*, FString*>(this, f, result); }
	void SetVerb(FString* Verb) { static NativeFunction f{ "FHttpRequestWinInet.SetVerb" }; NativeCall<void, FString*>(this, f, Verb); }
	void SetURL(FString* URL) { static NativeFunction f{ "FHttpRequestWinInet.SetURL" }; NativeCall<void, FString*>(this, f, URL); }
	void SetContent(TArray<unsigned char>* ContentPayload) { static NativeFunction f{ "FHttpRequestWinInet.SetContent" }; NativeCall<void, TArray<unsigned char>*>(this, f, ContentPayload); }
	void SetContentAsString(FString* ContentString) { static NativeFunction f{ "FHttpRequestWinInet.SetContentAsString" }; NativeCall<void, FString*>(this, f, ContentString); }
	void SetHeader(FString* HeaderName, FString* HeaderValue) { static NativeFunction f{ "FHttpRequestWinInet.SetHeader" }; NativeCall<void, FString*, FString*>(this, f, HeaderName, HeaderValue); }
	bool ProcessRequest() { static NativeFunction f{ "FHttpRequestWinInet.ProcessRequest" }; return NativeCall<bool>(this, f); }
	bool StartRequest() { static NativeFunction f{ "FHttpRequestWinInet.StartRequest" }; return NativeCall<bool>(this, f); }
	void FinishedRequest() { static NativeFunction f{ "FHttpRequestWinInet.FinishedRequest" }; NativeCall<void>(this, f); }
	FString* GenerateHeaderBuffer(FString* result, unsigned int ContentLength) { static NativeFunction f{ "FHttpRequestWinInet.GenerateHeaderBuffer" }; return NativeCall<FString*, FString*, unsigned int>(this, f, result, ContentLength); }
	void CancelRequest() { static NativeFunction f{ "FHttpRequestWinInet.CancelRequest" }; NativeCall<void>(this, f); }
	EHttpRequestStatus::Type GetStatus() { static NativeFunction f{ "FHttpRequestWinInet.GetStatus" }; return NativeCall<EHttpRequestStatus::Type>(this, f); }
	TSharedPtr<IHttpResponse, 1>* GetResponse(TSharedPtr<IHttpResponse, 1>* result) { static NativeFunction f{ "FHttpRequestWinInet.GetResponse" }; return NativeCall<TSharedPtr<IHttpResponse, 1>*, TSharedPtr<IHttpResponse, 1>*>(this, f, result); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "FHttpRequestWinInet.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
};

struct IHttpRequest : FHttpRequestWinInet
{
};

struct FHttpModule
{
	//FHttpManager * HttpManagerField() { return *GetNativePointerField<FHttpManager **>(this, "FHttpModule.HttpManager"); }
	float& HttpTimeoutField() { static NativeFieldOffset f{ "FHttpModule.HttpTimeout" }; return *GetNativePointerField<float*>(this, f); }
	float& HttpConnectionTimeoutField() { static NativeFieldOffset f{ "FHttpModule.HttpConnectionTimeout" }; return *GetNativePointerField<float*>(this, f); }
	float& HttpReceiveTimeoutField() { static NativeFieldOffset f{ "FHttpModule.HttpReceiveTimeout" }; return *GetNativePointerField<float*>(this, f); }
	float& HttpSendTimeoutField() { static NativeFieldOffset f{ "FHttpModule.HttpSendTimeout" }; return *GetNativePointerField<float*>(this, f); }
	int& HttpMaxConnectionsPerServerField() { static NativeFieldOffset f{ "FHttpModule.HttpMaxConnectionsPerServer" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxReadBufferSizeField() { static NativeFieldOffset f{ "FHttpModule.MaxReadBufferSize" }; return *GetNativePointerField<int*>(this, f); }
	bool& bEnableHttpField() { static NativeFieldOffset f{ "FHttpModule.bEnableHttp" }; return *GetNativePointerField<bool*>(this, f); }

	// Functions

	void StartupModule() { static NativeFunction f{ "FHttpModule.StartupModule" }; NativeCall<void>(this, f); }
	void ShutdownModule() { static NativeFunction f{ "FHttpModule.ShutdownModule" }; NativeCall<void>(this, f); }
	static FHttpModule* Get() { static NativeFunction f{ "FHttpModule.Get" }; return NativeCall<FHttpModule*>(nullptr, f); }
	TSharedRef<IHttpRequest, 0>* CreateRequest(TSharedRef<IHttpRequest, 0>* result) { static NativeFunction f{ "FHttpModule.CreateRequest" }; return NativeCall<TSharedRef<IHttpRequest, 0>*, TSharedRef<IHttpRequest, 0>*>(this, f, result); }
};

/*
* \brief Gets the size in bytes of an Object class. Example: GetObjectClassSize<AActor>()
*
* tparam T - Object class
* \return The size of the class in bytes
*/
template <typename T>
int GetObjectClassSize()
{
	// Credits to Substitute#0001 for the idea
	UClass* objClass = T::StaticClass();
	if (objClass)
	{
		return objClass->PropertiesSizeField();
	}

	return 0;
}

/*
* \brief Gets the size in bytes of an struct class. Example: GetObjectClassSize<FTribeData>()
*
* \tparam T - Struct class
* \return The size in bytes
*/
template <typename T>
int GetStructSize()
{
	// Credits to Substitute#0001 for the idea
	int size = 0;
	UScriptStruct* staticStruct = T::StaticStruct();
	if (staticStruct)
	{
		return staticStruct->PropertiesSizeField();
	}
	return 0;
}