#pragma once

struct FTribeGovernment
{
	FTribeGovernment()
	{
		TribeGovern_PINCode = 0;
		TribeGovern_DinoOwnership = 0;
		TribeGovern_StructureOwnership = 0;
		TribeGovern_DinoTaming = 0;
		TribeGovern_DinoUnclaimAdminOnly = 0;
	}

	int TribeGovern_PINCode;
	int TribeGovern_DinoOwnership;
	int TribeGovern_StructureOwnership;
	int TribeGovern_DinoTaming;
	int TribeGovern_DinoUnclaimAdminOnly;
};

struct FTribeData
{
	alignas(8) unsigned char __padding[0x140];
	FString& TribeNameField() { static NativeFieldOffset f{ "FTribeData.TribeName" }; return *GetNativePointerField<FString*>(this, f); }
	long double& LastNameChangeTimeField() { static NativeFieldOffset f{ "FTribeData.LastNameChangeTime" }; return *GetNativePointerField<long double*>(this, f); }
	unsigned int& OwnerPlayerDataIDField() { static NativeFieldOffset f{ "FTribeData.OwnerPlayerDataID" }; return *GetNativePointerField<unsigned int*>(this, f); }
	int& TribeIDField() { static NativeFieldOffset f{ "FTribeData.TribeID" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FString>& MembersPlayerNameField() { static NativeFieldOffset f{ "FTribeData.MembersPlayerName" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TArray<unsigned int>& MembersPlayerDataIDField() { static NativeFieldOffset f{ "FTribeData.MembersPlayerDataID" }; return *GetNativePointerField<TArray<unsigned int>*>(this, f); }
	TArray<unsigned char>& MembersRankGroupsField() { static NativeFieldOffset f{ "FTribeData.MembersRankGroups" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	TArray<double>& SlotFreedTimeField() { static NativeFieldOffset f{ "FTribeData.SlotFreedTime" }; return *GetNativePointerField<TArray<double>*>(this, f); }
	TArray<unsigned int>& TribeAdminsField() { static NativeFieldOffset f{ "FTribeData.TribeAdmins" }; return *GetNativePointerField<TArray<unsigned int>*>(this, f); }
	TArray<FTribeAlliance>& TribeAlliancesField() { static NativeFieldOffset f{ "FTribeData.TribeAlliances" }; return *GetNativePointerField<TArray<FTribeAlliance>*>(this, f); }
	bool& bSetGovernmentField() { static NativeFieldOffset f{ "FTribeData.bSetGovernment" }; return *GetNativePointerField<bool*>(this, f); }
	FTribeGovernment& TribeGovernmentField() { static NativeFieldOffset f{ "FTribeData.TribeGovernment" }; return *GetNativePointerField<FTribeGovernment*>(this, f); }
	TArray<FPrimalPlayerCharacterConfigStruct>& MembersConfigsField() { static NativeFieldOffset f{ "FTribeData.MembersConfigs" }; return *GetNativePointerField<TArray<FPrimalPlayerCharacterConfigStruct>*>(this, f); }
	TArray<FTribeWar>& TribeWarsField() { static NativeFieldOffset f{ "FTribeData.TribeWars" }; return *GetNativePointerField<TArray<FTribeWar>*>(this, f); }
	TArray<FString>& TribeLogField() { static NativeFieldOffset f{ "FTribeData.TribeLog" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	int& LogIndexField() { static NativeFieldOffset f{ "FTribeData.LogIndex" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FTribeRankGroup>& TribeRankGroupsField() { static NativeFieldOffset f{ "FTribeData.TribeRankGroups" }; return *GetNativePointerField<TArray<FTribeRankGroup>*>(this, f); }
	int& NumTribeDinosField() { static NativeFieldOffset f{ "FTribeData.NumTribeDinos" }; return *GetNativePointerField<int*>(this, f); }
	TSet<unsigned __int64, DefaultKeyFuncs<unsigned __int64, 0>, FDefaultSetAllocator>& MembersPlayerDataIDSet_ServerField() { static NativeFieldOffset f{ "FTribeData.MembersPlayerDataIDSet_Server" }; return *GetNativePointerField<TSet<unsigned __int64, DefaultKeyFuncs<unsigned __int64, 0>, FDefaultSetAllocator>*>(this, f); }

	// Functions

	bool IsTribeWarActive(int TribeID, UWorld* ForWorld, bool bIncludeUnstarted) { static NativeFunction f{ "FTribeData.IsTribeWarActive" }; return NativeCall<bool, int, UWorld*, bool>(this, f, TribeID, ForWorld, bIncludeUnstarted); }
	bool HasTribeWarRequest(int TribeID, UWorld* ForWorld) { static NativeFunction f{ "FTribeData.HasTribeWarRequest" }; return NativeCall<bool, int, UWorld*>(this, f, TribeID, ForWorld); }
	void RefreshTribeWars(UWorld* ForWorld) { static NativeFunction f{ "FTribeData.RefreshTribeWars" }; NativeCall<void, UWorld*>(this, f, ForWorld); }
	FTribeAlliance* FindTribeAlliance(unsigned int AllianceID) { static NativeFunction f{ "FTribeData.FindTribeAlliance" }; return NativeCall<FTribeAlliance*, unsigned int>(this, f, AllianceID); }
	bool IsTribeAlliedWith(unsigned int OtherTribeID) { static NativeFunction f{ "FTribeData.IsTribeAlliedWith" }; return NativeCall<bool, unsigned int>(this, f, OtherTribeID); }
	FString* GetTribeNameWithRankGroup(FString* result, unsigned int PlayerDataID) { static NativeFunction f{ "FTribeData.GetTribeNameWithRankGroup" }; return NativeCall<FString*, FString*, unsigned int>(this, f, result, PlayerDataID); }
	FString* GetRankNameForPlayerID(FString* result, unsigned int PlayerDataID) { static NativeFunction f{ "FTribeData.GetRankNameForPlayerID" }; return NativeCall<FString*, FString*, unsigned int>(this, f, result, PlayerDataID); }
	bool GetTribeRankGroupForPlayer(unsigned int PlayerDataID, FTribeRankGroup* outRankGroup) { static NativeFunction f{ "FTribeData.GetTribeRankGroupForPlayer" }; return NativeCall<bool, unsigned int, FTribeRankGroup*>(this, f, PlayerDataID, outRankGroup); }
	int GetTribeRankGroupIndexForPlayer(unsigned int PlayerDataID) { static NativeFunction f{ "FTribeData.GetTribeRankGroupIndexForPlayer" }; return NativeCall<int, unsigned int>(this, f, PlayerDataID); }
	int GetBestRankGroupForRank(int Rank) { static NativeFunction f{ "FTribeData.GetBestRankGroupForRank" }; return NativeCall<int, int>(this, f, Rank); }
	void MarkTribeNameChanged(UObject* WorldContextObject) { static NativeFunction f{ "FTribeData.MarkTribeNameChanged" }; NativeCall<void, UObject*>(this, f, WorldContextObject); }
	long double GetSecondsSinceLastNameChange(UObject* WorldContextObject) { static NativeFunction f{ "FTribeData.GetSecondsSinceLastNameChange" }; return NativeCall<long double, UObject*>(this, f, WorldContextObject); }
	float GetTribeNameChangeCooldownTime(UObject* WorldContextObject) { static NativeFunction f{ "FTribeData.GetTribeNameChangeCooldownTime" }; return NativeCall<float, UObject*>(this, f, WorldContextObject); }
	int GetDefaultRankGroupIndex() { static NativeFunction f{ "FTribeData.GetDefaultRankGroupIndex" }; return NativeCall<int>(this, f); }
	FTribeData* operator=(FTribeData* __that) { static NativeFunction f{ "FTribeData.operator=" }; return NativeCall<FTribeData*, FTribeData*>(this, f, __that); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FTribeData.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FTribeWar
{
	alignas(8) unsigned char __padding[0x30];
	int& EnemyTribeIDField() { static NativeFieldOffset f{ "FTribeWar.EnemyTribeID" }; return *GetNativePointerField<int*>(this, f); }
	int& StartDayNumberField() { static NativeFieldOffset f{ "FTribeWar.StartDayNumber" }; return *GetNativePointerField<int*>(this, f); }
	int& EndDayNumberField() { static NativeFieldOffset f{ "FTribeWar.EndDayNumber" }; return *GetNativePointerField<int*>(this, f); }
	float& StartDayTimeField() { static NativeFieldOffset f{ "FTribeWar.StartDayTime" }; return *GetNativePointerField<float*>(this, f); }
	float& EndDayTimeField() { static NativeFieldOffset f{ "FTribeWar.EndDayTime" }; return *GetNativePointerField<float*>(this, f); }
	bool& bIsApprovedField() { static NativeFieldOffset f{ "FTribeWar.bIsApproved" }; return *GetNativePointerField<bool*>(this, f); }
	int& InitiatingTribeIDField() { static NativeFieldOffset f{ "FTribeWar.InitiatingTribeID" }; return *GetNativePointerField<int*>(this, f); }
	FString& EnemyTribeNameField() { static NativeFieldOffset f{ "FTribeWar.EnemyTribeName" }; return *GetNativePointerField<FString*>(this, f); }

	// Functions

	bool CanBeRejected(UWorld* ForWorld) { static NativeFunction f{ "FTribeWar.CanBeRejected" }; return NativeCall<bool, UWorld*>(this, f, ForWorld); }
	bool IsCurrentlyActive(UWorld* ForWorld) { static NativeFunction f{ "FTribeWar.IsCurrentlyActive" }; return NativeCall<bool, UWorld*>(this, f, ForWorld); }
	bool IsTribeWarOn(UWorld* ForWorld) { static NativeFunction f{ "FTribeWar.IsTribeWarOn" }; return NativeCall<bool, UWorld*>(this, f, ForWorld); }
	FString* GetWarTimeString(FString* result, int DayNumber, float DayTime) { static NativeFunction f{ "FTribeWar.GetWarTimeString" }; return NativeCall<FString*, FString*, int, float>(this, f, result, DayNumber, DayTime); }
	bool operator==(FTribeWar* Other) { static NativeFunction f{ "FTribeWar.operator==" }; return NativeCall<bool, FTribeWar*>(this, f, Other); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FTribeWar.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FTribeRankGroup
{
	alignas(8) unsigned char __padding[0x28];
	FString& RankGroupNameField() { static NativeFieldOffset f{ "FTribeRankGroup.RankGroupName" }; return *GetNativePointerField<FString*>(this, f); }
	unsigned char& RankGroupRankField() { static NativeFieldOffset f{ "FTribeRankGroup.RankGroupRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& InventoryRankField() { static NativeFieldOffset f{ "FTribeRankGroup.InventoryRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& StructureActivationRankField() { static NativeFieldOffset f{ "FTribeRankGroup.StructureActivationRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& NewStructureActivationRankField() { static NativeFieldOffset f{ "FTribeRankGroup.NewStructureActivationRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& NewStructureInventoryRankField() { static NativeFieldOffset f{ "FTribeRankGroup.NewStructureInventoryRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& PetOrderRankField() { static NativeFieldOffset f{ "FTribeRankGroup.PetOrderRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& PetRidingRankField() { static NativeFieldOffset f{ "FTribeRankGroup.PetRidingRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& InviteToGroupRankField() { static NativeFieldOffset f{ "FTribeRankGroup.InviteToGroupRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& MaxPromotionGroupRankField() { static NativeFieldOffset f{ "FTribeRankGroup.MaxPromotionGroupRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& MaxDemotionGroupRankField() { static NativeFieldOffset f{ "FTribeRankGroup.MaxDemotionGroupRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& MaxBanishmentGroupRankField() { static NativeFieldOffset f{ "FTribeRankGroup.MaxBanishmentGroupRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& NumInvitesRemainingField() { static NativeFieldOffset f{ "FTribeRankGroup.NumInvitesRemaining" }; return *GetNativePointerField<unsigned char*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bPreventStructureDemolish() { static NativeBitField f{ "FTribeRankGroup.bPreventStructureDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventStructureAttachment() { static NativeBitField f{ "FTribeRankGroup.bPreventStructureAttachment" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventStructureBuildInRange() { static NativeBitField f{ "FTribeRankGroup.bPreventStructureBuildInRange" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUnclaiming() { static NativeBitField f{ "FTribeRankGroup.bPreventUnclaiming" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowInvites() { static NativeBitField f{ "FTribeRankGroup.bAllowInvites" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bLimitInvites() { static NativeBitField f{ "FTribeRankGroup.bLimitInvites" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowDemotions() { static NativeBitField f{ "FTribeRankGroup.bAllowDemotions" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowPromotions() { static NativeBitField f{ "FTribeRankGroup.bAllowPromotions" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowBanishments() { static NativeBitField f{ "FTribeRankGroup.bAllowBanishments" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDefaultRank() { static NativeBitField f{ "FTribeRankGroup.bDefaultRank" }; return { this, f }; }

	// Functions

	FTribeRankGroup* operator=(FTribeRankGroup* __that) { static NativeFunction f{ "FTribeRankGroup.operator=" }; return NativeCall<FTribeRankGroup*, FTribeRankGroup*>(this, f, __that); }
	void ValidateSettings() { static NativeFunction f{ "FTribeRankGroup.ValidateSettings" }; NativeCall<void>(this, f); }
	bool operator==(FTribeRankGroup* Other) { static NativeFunction f{ "FTribeRankGroup.operator==" }; return NativeCall<bool, FTribeRankGroup*>(this, f, Other); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FTribeRankGroup.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FTribeAlliance
{
    FString AllianceNameField;
    unsigned int AllianceIDField;
    TArray<FString> MembersTribeNameField;
    TArray<unsigned int> MembersTribeIDField;
    TArray<unsigned int> AdminsTribeIDField;
};