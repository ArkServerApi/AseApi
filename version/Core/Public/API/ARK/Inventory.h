#pragma once

struct UWorld;

struct FSupplyCrateItemSet {};

struct  FItemCount
{
	FString StringRef;
	int StackSize;
	int NumStacks;
	float Quality;
	bool bAutoEquip;
	bool bAutoSlot;
	int Slot;
};

struct FItemNetID
{
	unsigned int ItemID1;
	unsigned int ItemID2;
};

struct FCustomItemByteArray
{
	TArray<unsigned char, FDefaultAllocator> Bytes;
};

struct FCustomItemByteArrays
{
	TArray<FCustomItemByteArray, FDefaultAllocator> ByteArrays;
};

struct FCustomItemDoubles
{
	TArray<double, FDefaultAllocator> Doubles;
};

struct FCustomItemData
{
	FName CustomDataName;
	TArray<FString, FDefaultAllocator> CustomDataStrings;
	TArray<float, FDefaultAllocator> CustomDataFloats;
	TArray<UObject*, FDefaultAllocator> CustomDataObjects;
	TArray<UClass*, FDefaultAllocator> CustomDataClasses;
	TArray<FName, FDefaultAllocator> CustomDataNames;
	FCustomItemByteArrays CustomDataBytes;
	FCustomItemDoubles CustomDataDoubles;
};

struct FItemCraftQueueEntry
{
	FItemNetID ItemID;
	int Quantity;
	bool bIsRepair;
	bool bIgnoreInventoryRequirement;
	float RepairPercentage;
	float RepairSpeedMultiplier;
};

struct FItemSpawnActorClassOverride
{
	TSubclassOf<UPrimalItem> ItemClass;
	TSubclassOf<AActor> ActorClassOverride;
};

struct FLevelExperienceRamp
{
	TArray<float> ExperiencePointsForLevel;
};

struct FUseItemAddCharacterStatusValue
{
	float BaseAmountToAdd;
	unsigned __int32 bPercentOfMaxStatusValue : 1;
	unsigned __int32 bPercentOfCurrentStatusValue : 1;
	unsigned __int32 bUseItemQuality : 1;
	unsigned __int32 bDontRequireLessThanMaxToUse : 1;
	unsigned __int32 bAddOverTime : 1;
	unsigned __int32 bAddOverTimeSpeedInSeconds : 1;
	unsigned __int32 bContinueOnUnchangedValue : 1;
	unsigned __int32 bSetValue : 1;
	unsigned __int32 bSetAdditionalValue : 1;
	unsigned __int32 bResetExistingModifierDescriptionIndex : 1;
	unsigned __int32 bForceUseStatOnDinos : 1;
	float LimitExistingModifierDescriptionToMaxAmount;
	float AddOverTimeSpeed;
	float PercentAbsoluteMaxValue;
	float PercentAbsoluteMinValue;
	int StatusValueModifierDescriptionIndex;
	float ItemQualityAddValueMultiplier;
	TEnumAsByte<enum EPrimalCharacterStatusValue::Type> StatusValueType;
	TEnumAsByte<enum EPrimalCharacterStatusValue::Type> StopAtValueNearMax;
	TSubclassOf<UDamageType> ScaleValueByCharacterDamageType;
};

struct UAssetUserData : UObject
{
	[[deprecated("no class symbol for UAssetUserData in this game build, this returns UObject's class")]] static UClass* StaticClass() { ReportDeprecatedApiUse("UAssetUserData.StaticClass"); return UObject::StaticClass(); }
	[[deprecated("no class symbol for UAssetUserData in this game build, this returns UObject's class")]] static UClass* GetPrivateStaticClass() { ReportDeprecatedApiUse("UAssetUserData.GetPrivateStaticClass"); return UObject::StaticClass(); }
};

struct UActorComponent : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UActorComponent.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "UActorComponent.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	TArray<FName>& ComponentTagsField() { static NativeFieldOffset f{ "UActorComponent.ComponentTags" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	TArray<UAssetUserData*>& AssetUserDataField() { static NativeFieldOffset f{ "UActorComponent.AssetUserData" }; return *GetNativePointerField<TArray<UAssetUserData*>*>(this, f); }
	FName& CustomTagField() { static NativeFieldOffset f{ "UActorComponent.CustomTag" }; return *GetNativePointerField<FName*>(this, f); }
	int& CustomDataField() { static NativeFieldOffset f{ "UActorComponent.CustomData" }; return *GetNativePointerField<int*>(this, f); }
	AActor* CachedOwnerField() { static NativeFieldOffset f{ "UActorComponent.CachedOwner" }; return *GetNativePointerField<AActor**>(this, f); }
	UWorld* WorldField() { static NativeFieldOffset f{ "UActorComponent.World" }; return *GetNativePointerField<UWorld**>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bRegistered() { static NativeBitField f{ "UActorComponent.bRegistered" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRenderStateDirty() { static NativeBitField f{ "UActorComponent.bRenderStateDirty" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRenderTransformDirty() { static NativeBitField f{ "UActorComponent.bRenderTransformDirty" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRenderDynamicDataDirty() { static NativeBitField f{ "UActorComponent.bRenderDynamicDataDirty" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoRegister() { static NativeBitField f{ "UActorComponent.bAutoRegister" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTickInEditor() { static NativeBitField f{ "UActorComponent.bTickInEditor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNeverNeedsRenderUpdate() { static NativeBitField f{ "UActorComponent.bNeverNeedsRenderUpdate" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowConcurrentTick() { static NativeBitField f{ "UActorComponent.bAllowConcurrentTick" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCreatedByConstructionScript() { static NativeBitField f{ "UActorComponent.bCreatedByConstructionScript" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoActivate() { static NativeBitField f{ "UActorComponent.bAutoActivate" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsActive() { static NativeBitField f{ "UActorComponent.bIsActive" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bWantsInitializeComponent() { static NativeBitField f{ "UActorComponent.bWantsInitializeComponent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHasBeenCreated() { static NativeBitField f{ "UActorComponent.bHasBeenCreated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHasBeenInitialized() { static NativeBitField f{ "UActorComponent.bHasBeenInitialized" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysReplicatePropertyConditional() { static NativeBitField f{ "UActorComponent.bAlwaysReplicatePropertyConditional" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnComponentTick() { static NativeBitField f{ "UActorComponent.bUseBPOnComponentTick" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnComponentDestroyed() { static NativeBitField f{ "UActorComponent.bUseBPOnComponentDestroyed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyInitialReplication() { static NativeBitField f{ "UActorComponent.bOnlyInitialReplication" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHasCachedOwner() { static NativeBitField f{ "UActorComponent.bHasCachedOwner" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRenderStateCreated() { static NativeBitField f{ "UActorComponent.bRenderStateCreated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPhysicsStateCreated() { static NativeBitField f{ "UActorComponent.bPhysicsStateCreated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReplicates() { static NativeBitField f{ "UActorComponent.bReplicates" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNetAddressable() { static NativeBitField f{ "UActorComponent.bNetAddressable" }; return { this, f }; }

	// Functions

	void InvalidateLightingCache() { static NativeFunction f{ "UActorComponent.InvalidateLightingCache" }; NativeCall<void>(this, f); }
	bool IsPhysicsStateCreated() { static NativeFunction f{ "UActorComponent.IsPhysicsStateCreated" }; return NativeCall<bool>(this, f); }
	void PostInitProperties() { static NativeFunction f{ "UActorComponent.PostInitProperties" }; NativeCall<void>(this, f); }
	void PostRename(UObject* OldOuter, FName OldName) { static NativeFunction f{ "UActorComponent.PostRename" }; NativeCall<void, UObject*, FName>(this, f, OldOuter, OldName); }
	AActor* GetOwner() { static NativeFunction f{ "UActorComponent.GetOwner" }; return NativeCall<AActor*>(this, f); }
	UWorld* GetWorld() { static NativeFunction f{ "UActorComponent.GetWorld" }; return NativeCall<UWorld*>(this, f); }
	bool ComponentHasTag(FName Tag) { static NativeFunction f{ "UActorComponent.ComponentHasTag" }; return NativeCall<bool, FName>(this, f, Tag); }
	FString* GetReadableName(FString* result) { static NativeFunction f{ "UActorComponent.GetReadableName" }; return NativeCall<FString*, FString*>(this, f, result); }
	void BeginDestroy() { static NativeFunction f{ "UActorComponent.BeginDestroy" }; NativeCall<void>(this, f); }
	bool NeedsLoadForClient() { static NativeFunction f{ "UActorComponent.NeedsLoadForClient" }; return NativeCall<bool>(this, f); }
	bool NeedsLoadForServer() { static NativeFunction f{ "UActorComponent.NeedsLoadForServer" }; return NativeCall<bool>(this, f); }
	void OnRegister() { static NativeFunction f{ "UActorComponent.OnRegister" }; NativeCall<void>(this, f); }
	void InitializeComponent() { static NativeFunction f{ "UActorComponent.InitializeComponent" }; NativeCall<void>(this, f); }
	void UninitializeComponent() { static NativeFunction f{ "UActorComponent.UninitializeComponent" }; NativeCall<void>(this, f); }
	void SetComponentTickEnabled(bool bEnabled) { static NativeFunction f{ "UActorComponent.SetComponentTickEnabled" }; NativeCall<void, bool>(this, f, bEnabled); }
	void SetComponentTickEnabledAsync(bool bEnabled) { static NativeFunction f{ "UActorComponent.SetComponentTickEnabledAsync" }; NativeCall<void, bool>(this, f, bEnabled); }
	void RegisterComponentTickFunctions(bool bRegister, bool bSaveAndRestoreComponentTickState) { static NativeFunction f{ "UActorComponent.RegisterComponentTickFunctions" }; NativeCall<void, bool, bool>(this, f, bRegister, bSaveAndRestoreComponentTickState); }
	void RegisterComponentWithWorld(UWorld* InWorld) { static NativeFunction f{ "UActorComponent.RegisterComponentWithWorld" }; NativeCall<void, UWorld*>(this, f, InWorld); }
	void RegisterComponent() { static NativeFunction f{ "UActorComponent.RegisterComponent" }; NativeCall<void>(this, f); }
	void UnregisterComponent() { static NativeFunction f{ "UActorComponent.UnregisterComponent" }; NativeCall<void>(this, f); }
	void DestroyComponent() { static NativeFunction f{ "UActorComponent.DestroyComponent" }; NativeCall<void>(this, f); }
	void OnComponentCreated() { static NativeFunction f{ "UActorComponent.OnComponentCreated" }; NativeCall<void>(this, f); }
	void OnComponentDestroyed() { static NativeFunction f{ "UActorComponent.OnComponentDestroyed" }; NativeCall<void>(this, f); }
	void CreateRenderState_Concurrent() { static NativeFunction f{ "UActorComponent.CreateRenderState_Concurrent" }; NativeCall<void>(this, f); }
	void SendRenderTransform_Concurrent() { static NativeFunction f{ "UActorComponent.SendRenderTransform_Concurrent" }; NativeCall<void>(this, f); }
	void SendRenderDynamicData_Concurrent() { static NativeFunction f{ "UActorComponent.SendRenderDynamicData_Concurrent" }; NativeCall<void>(this, f); }
	void DestroyRenderState_Concurrent() { static NativeFunction f{ "UActorComponent.DestroyRenderState_Concurrent" }; NativeCall<void>(this, f); }
	void CreatePhysicsState() { static NativeFunction f{ "UActorComponent.CreatePhysicsState" }; NativeCall<void>(this, f); }
	void DestroyPhysicsState() { static NativeFunction f{ "UActorComponent.DestroyPhysicsState" }; NativeCall<void>(this, f); }
	void ExecuteRegisterEvents() { static NativeFunction f{ "UActorComponent.ExecuteRegisterEvents" }; NativeCall<void>(this, f); }
	void ExecuteUnregisterEvents() { static NativeFunction f{ "UActorComponent.ExecuteUnregisterEvents" }; NativeCall<void>(this, f); }
	void ReregisterComponent() { static NativeFunction f{ "UActorComponent.ReregisterComponent" }; NativeCall<void>(this, f); }
	void RecreateRenderState_Concurrent() { static NativeFunction f{ "UActorComponent.RecreateRenderState_Concurrent" }; NativeCall<void>(this, f); }
	void RecreatePhysicsState(bool bRestoreBoneTransforms) { static NativeFunction f{ "UActorComponent.RecreatePhysicsState" }; NativeCall<void, bool>(this, f, bRestoreBoneTransforms); }
	void AddTickPrerequisiteActor(AActor* PrerequisiteActor) { static NativeFunction f{ "UActorComponent.AddTickPrerequisiteActor" }; NativeCall<void, AActor*>(this, f, PrerequisiteActor); }
	void AddTickPrerequisiteComponent(UActorComponent* PrerequisiteComponent) { static NativeFunction f{ "UActorComponent.AddTickPrerequisiteComponent" }; NativeCall<void, UActorComponent*>(this, f, PrerequisiteComponent); }
	void RemoveTickPrerequisiteActor(AActor* PrerequisiteActor) { static NativeFunction f{ "UActorComponent.RemoveTickPrerequisiteActor" }; NativeCall<void, AActor*>(this, f, PrerequisiteActor); }
	void RemoveTickPrerequisiteComponent(UActorComponent* PrerequisiteComponent) { static NativeFunction f{ "UActorComponent.RemoveTickPrerequisiteComponent" }; NativeCall<void, UActorComponent*>(this, f, PrerequisiteComponent); }
	void DoDeferredRenderUpdates_Concurrent() { static NativeFunction f{ "UActorComponent.DoDeferredRenderUpdates_Concurrent" }; NativeCall<void>(this, f); }
	void MarkRenderDynamicDataDirty() { static NativeFunction f{ "UActorComponent.MarkRenderDynamicDataDirty" }; NativeCall<void>(this, f); }
	void MarkForNeededEndOfFrameUpdate() { static NativeFunction f{ "UActorComponent.MarkForNeededEndOfFrameUpdate" }; NativeCall<void>(this, f); }
	void MarkForNeededEndOfFrameRecreate() { static NativeFunction f{ "UActorComponent.MarkForNeededEndOfFrameRecreate" }; NativeCall<void>(this, f); }
	void Activate(bool bReset) { static NativeFunction f{ "UActorComponent.Activate" }; NativeCall<void, bool>(this, f, bReset); }
	void Deactivate() { static NativeFunction f{ "UActorComponent.Deactivate" }; NativeCall<void>(this, f); }
	bool ShouldActivate() { static NativeFunction f{ "UActorComponent.ShouldActivate" }; return NativeCall<bool>(this, f); }
	void SetActive(bool bNewActive, bool bReset) { static NativeFunction f{ "UActorComponent.SetActive" }; NativeCall<void, bool, bool>(this, f, bNewActive, bReset); }
	void ToggleActive() { static NativeFunction f{ "UActorComponent.ToggleActive" }; NativeCall<void>(this, f); }
	bool IsActive() { static NativeFunction f{ "UActorComponent.IsActive" }; return NativeCall<bool>(this, f); }
	void AddAssetUserData(UAssetUserData* InUserData) { static NativeFunction f{ "UActorComponent.AddAssetUserData" }; NativeCall<void, UAssetUserData*>(this, f, InUserData); }
	UAssetUserData* GetAssetUserDataOfClass(TSubclassOf<UAssetUserData> InUserDataClass) { static NativeFunction f{ "UActorComponent.GetAssetUserDataOfClass" }; return NativeCall<UAssetUserData*, TSubclassOf<UAssetUserData>>(this, f, InUserDataClass); }
	void RemoveUserDataOfClass(TSubclassOf<UAssetUserData> InUserDataClass) { static NativeFunction f{ "UActorComponent.RemoveUserDataOfClass" }; NativeCall<void, TSubclassOf<UAssetUserData>>(this, f, InUserDataClass); }
	void SetNetAddressable() { static NativeFunction f{ "UActorComponent.SetNetAddressable" }; NativeCall<void>(this, f); }
	bool IsNameStableForNetworking() { static NativeFunction f{ "UActorComponent.IsNameStableForNetworking" }; return NativeCall<bool>(this, f); }
	bool IsSupportedForNetworking() { static NativeFunction f{ "UActorComponent.IsSupportedForNetworking" }; return NativeCall<bool>(this, f); }
	void SetIsReplicated(bool ShouldReplicate) { static NativeFunction f{ "UActorComponent.SetIsReplicated" }; NativeCall<void, bool>(this, f, ShouldReplicate); }
	bool GetIsReplicated() { static NativeFunction f{ "UActorComponent.GetIsReplicated" }; return NativeCall<bool>(this, f); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "UActorComponent.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	bool AlwaysReplicatePropertyConditional(UProperty* forProperty) { static NativeFunction f{ "UActorComponent.AlwaysReplicatePropertyConditional" }; return NativeCall<bool, UProperty*>(this, f, forProperty); }
	static void StaticRegisterNativesUActorComponent() { static NativeFunction f{ "UActorComponent.StaticRegisterNativesUActorComponent" }; NativeCall<void>(nullptr, f); }
	void AddedAsPrimalItemAttachment() { static NativeFunction f{ "UActorComponent.AddedAsPrimalItemAttachment" }; NativeCall<void>(this, f); }
};

struct FServerCustomFolder
{
	int InventoryCompType;
	FString FolderName;
	TArray<FItemNetID, FDefaultAllocator> CustomFolderItemIds;
};

struct UPrimalInventoryComponent : UActorComponent
{
	TArray<TWeakObjectPtr<AShooterPlayerController>>& RemoteViewingInventoryPlayerControllersField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.RemoteViewingInventoryPlayerControllers" }; return *GetNativePointerField<TArray<TWeakObjectPtr<AShooterPlayerController>>*>(this, f); }
	TArray<UPrimalItem*>& InventoryItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.InventoryItems" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	TArray<UPrimalItem*>& EquippedItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.EquippedItems" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	TArray<UPrimalItem*>& ItemSlotsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemSlots" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	TArray<UPrimalItem*>& ArkTributeItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ArkTributeItems" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	TArray<UPrimalItem*>& AllDyeColorItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.AllDyeColorItems" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	TArray<FItemCraftQueueEntry>& ItemCraftQueueEntriesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemCraftQueueEntries" }; return *GetNativePointerField<TArray<FItemCraftQueueEntry>*>(this, f); }
	int& OverrideInventoryDefaultTabField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.OverrideInventoryDefaultTab" }; return *GetNativePointerField<int*>(this, f); }
	TArray<TEnumAsByte<enum EPrimalEquipmentType::Type>>& EquippableItemTypesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.EquippableItemTypes" }; return *GetNativePointerField<TArray<TEnumAsByte<enum EPrimalEquipmentType::Type>>*>(this, f); }
	float& CraftingItemSpeedField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.CraftingItemSpeed" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FItemMultiplier>& ItemSpoilingTimeMultipliersField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemSpoilingTimeMultipliers" }; return *GetNativePointerField<TArray<FItemMultiplier>*>(this, f); }
	UGenericDataListEntry* ExtraItemDisplayField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ExtraItemDisplay" }; return *GetNativePointerField<UGenericDataListEntry**>(this, f); }
	int& MaxInventoryItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxInventoryItems" }; return *GetNativePointerField<int*>(this, f); }
	float& MaxInventoryWeightField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxInventoryWeight" }; return *GetNativePointerField<float*>(this, f); }
	unsigned char& TribeGroupInventoryRankField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.TribeGroupInventoryRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	int& NumSlotsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.NumSlots" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxItemCraftQueueEntriesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxItemCraftQueueEntries" }; return *GetNativePointerField<int*>(this, f); }
	FString& RemoteInventoryDescriptionStringField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.RemoteInventoryDescriptionString" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<UPrimalItem>& EngramRequirementClassOverrideField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.EngramRequirementClassOverride" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& RemoteAddItemOnlyAllowItemClassesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.RemoteAddItemOnlyAllowItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& RemoteAddItemPreventItemClassesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.RemoteAddItemPreventItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<FEventItem>& EventItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.EventItems" }; return *GetNativePointerField<TArray<FEventItem>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultInventoryItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultInventoryItems2Field() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryItems2" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultInventoryItems3Field() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryItems3" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultInventoryItems4Field() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryItems4" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<FString>& DefaultInventoryItemsRandomCustomStringsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryItemsRandomCustomStrings" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TArray<float>& DefaultInventoryItemsRandomCustomStringsWeightsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryItemsRandomCustomStringsWeights" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& CheatInventoryItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.CheatInventoryItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultEquippedItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultEquippedItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultEquippedItemSkinsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultEquippedItemSkins" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& DefaultSlotItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultSlotItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<FItemSpawnActorClassOverride>& ItemSpawnActorClassOverridesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemSpawnActorClassOverrides" }; return *GetNativePointerField<TArray<FItemSpawnActorClassOverride>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& OnlyAllowCraftingItemClassesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.OnlyAllowCraftingItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<unsigned char>& DefaultEngramsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultEngrams" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	TArray<unsigned char>& DefaultEngrams2Field() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultEngrams2" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	TArray<unsigned char>& DefaultEngrams3Field() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultEngrams3" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	TArray<unsigned char>& DefaultEngrams4Field() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultEngrams4" }; return *GetNativePointerField<TArray<unsigned char>*>(this, f); }
	TArray<float>& DefaultInventoryQualitiesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultInventoryQualities" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	FString& InventoryNameOverrideField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.InventoryNameOverride" }; return *GetNativePointerField<FString*>(this, f); }
	float& MaxRemoteInventoryViewingDistanceField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxRemoteInventoryViewingDistance" }; return *GetNativePointerField<float*>(this, f); }
	float& ActiveInventoryRefreshIntervalField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ActiveInventoryRefreshInterval" }; return *GetNativePointerField<float*>(this, f); }
	int& AbsoluteMaxInventoryItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.AbsoluteMaxInventoryItems" }; return *GetNativePointerField<int*>(this, f); }
	long double& LastInventoryRefreshTimeField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.LastInventoryRefreshTime" }; return *GetNativePointerField<long double*>(this, f); }
	TSubclassOf<ADroppedItem>& DroppedItemTemplateOverrideField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DroppedItemTemplateOverride" }; return *GetNativePointerField<TSubclassOf<ADroppedItem>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& ForceAllowItemStackingsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ForceAllowItemStackings" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	FRotator& DropItemRotationOffsetField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DropItemRotationOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	TArray<FItemCraftingConsumptionReplenishment>& ItemCraftingConsumptionReplenishmentsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemCraftingConsumptionReplenishments" }; return *GetNativePointerField<TArray<FItemCraftingConsumptionReplenishment>*>(this, f); }
	float& MaxItemCooldownTimeClearField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxItemCooldownTimeClear" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FItemMultiplier>& MaxItemTemplateQuantitiesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxItemTemplateQuantities" }; return *GetNativePointerField<TArray<FItemMultiplier>*>(this, f); }
	USoundBase* ItemCraftingSoundOverrideField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemCraftingSoundOverride" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TArray<FActorClassAttachmentInfo>& WeaponAsEquipmentAttachmentInfosField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.WeaponAsEquipmentAttachmentInfos" }; return *GetNativePointerField<TArray<FActorClassAttachmentInfo>*>(this, f); }
	TArray<UPrimalItem*>& CraftingItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.CraftingItems" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	int& DisplayDefaultItemInventoryCountField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DisplayDefaultItemInventoryCount" }; return *GetNativePointerField<int*>(this, f); }
	bool& bHasBeenRegisteredField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.bHasBeenRegistered" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& LastUsedItemClassesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.LastUsedItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<double>& LastUsedItemTimesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.LastUsedItemTimes" }; return *GetNativePointerField<TArray<double>*>(this, f); }
	int& InvUpdatedFrameField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.InvUpdatedFrame" }; return *GetNativePointerField<int*>(this, f); }
	long double& LastRefreshCheckItemTimeField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.LastRefreshCheckItemTime" }; return *GetNativePointerField<long double*>(this, f); }
	bool& bLastPreventUseItemSpoilingTimeMultipliersField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.bLastPreventUseItemSpoilingTimeMultipliers" }; return *GetNativePointerField<bool*>(this, f); }
	FItemNetID& NextItemSpoilingIDField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.NextItemSpoilingID" }; return *GetNativePointerField<FItemNetID*>(this, f); }
	FItemNetID& NextItemConsumptionIDField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.NextItemConsumptionID" }; return *GetNativePointerField<FItemNetID*>(this, f); }
	float& MinItemSetsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MinItemSets" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxItemSetsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxItemSets" }; return *GetNativePointerField<float*>(this, f); }
	float& NumItemSetsPowerField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.NumItemSetsPower" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FSupplyCrateItemSet>& ItemSetsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemSets" }; return *GetNativePointerField<TArray<FSupplyCrateItemSet>*>(this, f); }
	TArray<FSupplyCrateItemSet>& AdditionalItemSetsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.AdditionalItemSets" }; return *GetNativePointerField<TArray<FSupplyCrateItemSet>*>(this, f); }
	TSubclassOf<UPrimalSupplyCrateItemSets>& ItemSetsOverrideField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemSetsOverride" }; return *GetNativePointerField<TSubclassOf<UPrimalSupplyCrateItemSets>*>(this, f); }
	TArray<float>& SetQuantityWeightsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.SetQuantityWeights" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	TArray<float>& SetQuantityValuesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.SetQuantityValues" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	USoundBase* ItemRemovedBySoundField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemRemovedBySound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* OpenInventorySoundField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.OpenInventorySound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* CloseInventorySoundField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.CloseInventorySound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	float& MaxInventoryAccessDistanceField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.MaxInventoryAccessDistance" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FString>& ServerCustomFolderField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ServerCustomFolder" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TArray<TSubclassOf<UPrimalInventoryComponent>>& ForceAllowCraftingForInventoryComponentsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ForceAllowCraftingForInventoryComponents" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalInventoryComponent>>*>(this, f); }
	TArray<FItemMultiplier>& ItemClassWeightMultipliersField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ItemClassWeightMultipliers" }; return *GetNativePointerField<TArray<FItemMultiplier>*>(this, f); }
	float& GenerateItemSetsQualityMultiplierMinField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.GenerateItemSetsQualityMultiplierMin" }; return *GetNativePointerField<float*>(this, f); }
	float& GenerateItemSetsQualityMultiplierMaxField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.GenerateItemSetsQualityMultiplierMax" }; return *GetNativePointerField<float*>(this, f); }
	float& DefaultCraftingRequirementsMultiplierField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultCraftingRequirementsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	int& DefaultCraftingQuantityMultiplierField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DefaultCraftingQuantityMultiplier" }; return *GetNativePointerField<int*>(this, f); }
	int& ActionWheelAccessInventoryPriorityField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ActionWheelAccessInventoryPriority" }; return *GetNativePointerField<int*>(this, f); }
	int& SavedForceDefaultInventoryRefreshVersionField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.SavedForceDefaultInventoryRefreshVersion" }; return *GetNativePointerField<int*>(this, f); }
	int& ForceDefaultInventoryRefreshVersionField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ForceDefaultInventoryRefreshVersion" }; return *GetNativePointerField<int*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& TamedDinoForceConsiderFoodTypesField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.TamedDinoForceConsiderFoodTypes" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<UPrimalItem*>& DinoAutoHealingItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.DinoAutoHealingItems" }; return *GetNativePointerField<TArray<UPrimalItem*>*>(this, f); }
	USoundBase* OverrideCraftingFinishedSoundField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.OverrideCraftingFinishedSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	long double& LastAddToCraftQueueSoundTimeField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.LastAddToCraftQueueSoundTime" }; return *GetNativePointerField<long double*>(this, f); }
	FString& ForceAddToFolderField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.ForceAddToFolder" }; return *GetNativePointerField<FString*>(this, f); }
	FVector& GroundDropTraceLocationOffsetField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.GroundDropTraceLocationOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	TArray<FServerCustomFolder>& CustomFolderItemsField() { static NativeFieldOffset f{ "UPrimalInventoryComponent.CustomFolderItems" }; return *GetNativePointerField<TArray<FServerCustomFolder>*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bInitializedMe() { static NativeBitField f{ "UPrimalInventoryComponent.bInitializedMe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReceivingEquippedItems() { static NativeBitField f{ "UPrimalInventoryComponent.bReceivingEquippedItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReceivingInventoryItems() { static NativeBitField f{ "UPrimalInventoryComponent.bReceivingInventoryItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReceivingArkInventoryItems() { static NativeBitField f{ "UPrimalInventoryComponent.bReceivingArkInventoryItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bFreeCraftingMode() { static NativeBitField f{ "UPrimalInventoryComponent.bFreeCraftingMode" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanEquipItems() { static NativeBitField f{ "UPrimalInventoryComponent.bCanEquipItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanUseWeaponAsEquipment() { static NativeBitField f{ "UPrimalInventoryComponent.bCanUseWeaponAsEquipment" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanInventoryItems() { static NativeBitField f{ "UPrimalInventoryComponent.bCanInventoryItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bConsumeCraftingRepairingRequirementsOnStart() { static NativeBitField f{ "UPrimalInventoryComponent.bConsumeCraftingRepairingRequirementsOnStart" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemoteCrafting() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowRemoteCrafting" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowDeactivatedCrafting() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowDeactivatedCrafting" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventAutoDecreaseDurability() { static NativeBitField f{ "UPrimalInventoryComponent.bPreventAutoDecreaseDurability" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemoteRepairing() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowRemoteRepairing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowItemStacking() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowItemStacking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseCraftQueue() { static NativeBitField f{ "UPrimalInventoryComponent.bUseCraftQueue" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bShowHiddenRemoteInventoryItems() { static NativeBitField f{ "UPrimalInventoryComponent.bShowHiddenRemoteInventoryItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceInventoryBlueprints() { static NativeBitField f{ "UPrimalInventoryComponent.bForceInventoryBlueprints" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceInventoryNonRemovable() { static NativeBitField f{ "UPrimalInventoryComponent.bForceInventoryNonRemovable" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideDefaultInventoryItemsFromDisplay() { static NativeBitField f{ "UPrimalInventoryComponent.bHideDefaultInventoryItemsFromDisplay" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDataListPadMaxInventoryItems() { static NativeBitField f{ "UPrimalInventoryComponent.bDataListPadMaxInventoryItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAddMaxInventoryItemsToDefaultItems() { static NativeBitField f{ "UPrimalInventoryComponent.bAddMaxInventoryItemsToDefaultItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCheckForAutoCraftBlueprints() { static NativeBitField f{ "UPrimalInventoryComponent.bCheckForAutoCraftBlueprints" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsTributeInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bIsTributeInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipmentMustRequireExplicitOwnerClass() { static NativeBitField f{ "UPrimalInventoryComponent.bEquipmentMustRequireExplicitOwnerClass" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipmentPlayerForceRequireExplicitOwnerClass() { static NativeBitField f{ "UPrimalInventoryComponent.bEquipmentPlayerForceRequireExplicitOwnerClass" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipmentForceIgnoreExplicitOwnerClass() { static NativeBitField f{ "UPrimalInventoryComponent.bEquipmentForceIgnoreExplicitOwnerClass" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInventoryRefresh() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPInventoryRefresh" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInitializeInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPInitializeInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAllowAddInventoryItem() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPAllowAddInventoryItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideSaddleFromInventoryDisplay() { static NativeBitField f{ "UPrimalInventoryComponent.bHideSaddleFromInventoryDisplay" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCraftingEnabled() { static NativeBitField f{ "UPrimalInventoryComponent.bCraftingEnabled" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRepairingEnabled() { static NativeBitField f{ "UPrimalInventoryComponent.bRepairingEnabled" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReplicateComponent() { static NativeBitField f{ "UPrimalInventoryComponent.bReplicateComponent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyOneCraftQueueItem() { static NativeBitField f{ "UPrimalInventoryComponent.bOnlyOneCraftQueueItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRemoteInventoryOnlyAllowTribe() { static NativeBitField f{ "UPrimalInventoryComponent.bRemoteInventoryOnlyAllowTribe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOverrideCraftingMinDurabilityRequirement() { static NativeBitField f{ "UPrimalInventoryComponent.bOverrideCraftingMinDurabilityRequirement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRemoteInventoryAllowRemoveItems() { static NativeBitField f{ "UPrimalInventoryComponent.bRemoteInventoryAllowRemoveItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRemoteInventoryAllowAddItems() { static NativeBitField f{ "UPrimalInventoryComponent.bRemoteInventoryAllowAddItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemoteInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowRemoteInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseCheatInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bUseCheatInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowAddingToArkTribute() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowAddingToArkTribute" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRemoteInventoryOnlyAllowSelf() { static NativeBitField f{ "UPrimalInventoryComponent.bRemoteInventoryOnlyAllowSelf" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bMaxInventoryWeightUseCharacterStatus() { static NativeBitField f{ "UPrimalInventoryComponent.bMaxInventoryWeightUseCharacterStatus" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventDropInventoryDeposit() { static NativeBitField f{ "UPrimalInventoryComponent.bPreventDropInventoryDeposit" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bShowItemDefaultFolders() { static NativeBitField f{ "UPrimalInventoryComponent.bShowItemDefaultFolders" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisableDropAllItems() { static NativeBitField f{ "UPrimalInventoryComponent.bDisableDropAllItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreMaxInventoryItems() { static NativeBitField f{ "UPrimalInventoryComponent.bIgnoreMaxInventoryItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsSecondaryInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bIsSecondaryInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRemoteOnlyAllowBlueprintsOrItemClasses() { static NativeBitField f{ "UPrimalInventoryComponent.bRemoteOnlyAllowBlueprintsOrItemClasses" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventSendingData() { static NativeBitField f{ "UPrimalInventoryComponent.bPreventSendingData" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupressInventoryItemNetworking() { static NativeBitField f{ "UPrimalInventoryComponent.bSupressInventoryItemNetworking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventInventoryViewTrace() { static NativeBitField f{ "UPrimalInventoryComponent.bPreventInventoryViewTrace" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSpawnActorOnTopOfStructure() { static NativeBitField f{ "UPrimalInventoryComponent.bSpawnActorOnTopOfStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDropPhysicalInventoryDeposit() { static NativeBitField f{ "UPrimalInventoryComponent.bDropPhysicalInventoryDeposit" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseExtendedCharacterCraftingFunctionality() { static NativeBitField f{ "UPrimalInventoryComponent.bUseExtendedCharacterCraftingFunctionality" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceGenerateItemSets() { static NativeBitField f{ "UPrimalInventoryComponent.bForceGenerateItemSets" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPHandleAccessInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bBPHandleAccessInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bGivesAchievementItems() { static NativeBitField f{ "UPrimalInventoryComponent.bGivesAchievementItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPAllowUseInInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bBPAllowUseInInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPRemoteInventoryAllowRemoveItems() { static NativeBitField f{ "UPrimalInventoryComponent.bBPRemoteInventoryAllowRemoveItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPRemoteInventoryGetMaxVisibleSlots() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPRemoteInventoryGetMaxVisibleSlots" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetExtraItemDisplay() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPGetExtraItemDisplay" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPNotifyItemAdded() { static NativeBitField f{ "UPrimalInventoryComponent.bBPNotifyItemAdded" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPNotifyItemRemoved() { static NativeBitField f{ "UPrimalInventoryComponent.bBPNotifyItemRemoved" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPNotifyItemQuantityUpdated() { static NativeBitField f{ "UPrimalInventoryComponent.bBPNotifyItemQuantityUpdated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideItemMinimumUseInterval() { static NativeBitField f{ "UPrimalInventoryComponent.bBPOverrideItemMinimumUseInterval" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPForceCustomRemoteInventoryAllowAddItems() { static NativeBitField f{ "UPrimalInventoryComponent.bBPForceCustomRemoteInventoryAllowAddItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPForceCustomRemoteInventoryAllowRemoveItems() { static NativeBitField f{ "UPrimalInventoryComponent.bBPForceCustomRemoteInventoryAllowRemoveItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceInventoryNotifyCraftingFinished() { static NativeBitField f{ "UPrimalInventoryComponent.bForceInventoryNotifyCraftingFinished" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowWorldSettingsInventoryComponentAppends() { static NativeBitField f{ "UPrimalInventoryComponent.bAllowWorldSettingsInventoryComponentAppends" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventCraftingResourceConsumption() { static NativeBitField f{ "UPrimalInventoryComponent.bPreventCraftingResourceConsumption" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOverrideInventoryDepositClassDontForceDrop() { static NativeBitField f{ "UPrimalInventoryComponent.bOverrideInventoryDepositClassDontForceDrop" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPIsCraftingAllowed() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPIsCraftingAllowed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPRemoteInventoryAllowCrafting() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPRemoteInventoryAllowCrafting" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNotifyAddedOnClientReceive() { static NativeBitField f{ "UPrimalInventoryComponent.bNotifyAddedOnClientReceive" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsTaxidermyBase() { static NativeBitField f{ "UPrimalInventoryComponent.bIsTaxidermyBase" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDeferCheckForAutoCraftBlueprintsOnInventoryChange() { static NativeBitField f{ "UPrimalInventoryComponent.bDeferCheckForAutoCraftBlueprintsOnInventoryChange" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSetsRandomWithoutReplacement() { static NativeBitField f{ "UPrimalInventoryComponent.bSetsRandomWithoutReplacement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowAllUseInInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bForceAllowAllUseInInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPIsValidCraftingResource() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPIsValidCraftingResource" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseParentStructureIsValidCraftingResource() { static NativeBitField f{ "UPrimalInventoryComponent.bUseParentStructureIsValidCraftingResource" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSetCraftingEnabledCheckForAutoCraftBlueprints() { static NativeBitField f{ "UPrimalInventoryComponent.bSetCraftingEnabledCheckForAutoCraftBlueprints" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPRemoteInventoryAllowViewing() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPRemoteInventoryAllowViewing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllDefaultInventoryIsEngrams() { static NativeBitField f{ "UPrimalInventoryComponent.bAllDefaultInventoryIsEngrams" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanGrindItems() { static NativeBitField f{ "UPrimalInventoryComponent.bUseBPCanGrindItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bGrinderCanGrindAll() { static NativeBitField f{ "UPrimalInventoryComponent.bGrinderCanGrindAll" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInitializedDefaultInventory() { static NativeBitField f{ "UPrimalInventoryComponent.bInitializedDefaultInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bGetDataListEntriesOnlyRootItems() { static NativeBitField f{ "UPrimalInventoryComponent.bGetDataListEntriesOnlyRootItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bConfigOverriden() { static NativeBitField f{ "UPrimalInventoryComponent.bConfigOverriden" }; return { this, f }; }

	// Functions

	int GetInventoryUpdatedFrame() { static NativeFunction f{ "UPrimalInventoryComponent.GetInventoryUpdatedFrame" }; return NativeCall<int>(this, f); }
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalInventoryComponent.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	void OnRegister() { static NativeFunction f{ "UPrimalInventoryComponent.OnRegister" }; NativeCall<void>(this, f); }
	bool CanEquipItems() { static NativeFunction f{ "UPrimalInventoryComponent.CanEquipItems" }; return NativeCall<bool>(this, f); }
	bool AllowEquippingItemType(EPrimalEquipmentType::Type equipmentType) { static NativeFunction f{ "UPrimalInventoryComponent.AllowEquippingItemType" }; return NativeCall<bool, EPrimalEquipmentType::Type>(this, f, equipmentType); }
	bool CanEquipItem(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.CanEquipItem" }; return NativeCall<bool, UPrimalItem*>(this, f, anItem); }
	bool CanInventoryItems() { static NativeFunction f{ "UPrimalInventoryComponent.CanInventoryItems" }; return NativeCall<bool>(this, f); }
	bool CanInventoryItem(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.CanInventoryItem" }; return NativeCall<bool, UPrimalItem*>(this, f, anItem); }
	bool AllowAddInventoryItem(UPrimalItem* anItem, int* requestedQuantity, bool OnlyAddAll) { static NativeFunction f{ "UPrimalInventoryComponent.AllowAddInventoryItem" }; return NativeCall<bool, UPrimalItem*, int*, bool>(this, f, anItem, requestedQuantity, OnlyAddAll); }
	UPrimalItem* AddItem(FItemNetInfo* theItemInfo, bool bEquipItem, bool AddToSlot, bool bDontStack, FItemNetID* InventoryInsertAfterItemID, bool ShowHUDNotification, bool bDontRecalcSpoilingTime, bool bForceIncompleteStacking, AShooterCharacter* OwnerPlayer, bool bIgnoreAbsoluteMaxInventory, bool bIgnoreMaxInventory = false, bool bForceAddToSlot = false) { static NativeFunction f{ "UPrimalInventoryComponent.AddItem" }; return NativeCall<UPrimalItem*, FItemNetInfo*, bool, bool, bool, FItemNetID*, bool, bool, bool, AShooterCharacter*, bool, bool, bool>(this, f, theItemInfo, bEquipItem, AddToSlot, bDontStack, InventoryInsertAfterItemID, ShowHUDNotification, bDontRecalcSpoilingTime, bForceIncompleteStacking, OwnerPlayer, bIgnoreAbsoluteMaxInventory, bIgnoreMaxInventory, bForceAddToSlot); }
	bool IsLocalInventoryViewer() { static NativeFunction f{ "UPrimalInventoryComponent.IsLocalInventoryViewer" }; return NativeCall<bool>(this, f); }
	void NotifyItemAdded(UPrimalItem* theItem, bool bEquippedItem) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyItemAdded" }; NativeCall<void, UPrimalItem*, bool>(this, f, theItem, bEquippedItem); }
	void NotifyArkItemAdded() { static NativeFunction f{ "UPrimalInventoryComponent.NotifyArkItemAdded" }; NativeCall<void>(this, f); }
	void NotifyItemRemoved(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyItemRemoved" }; NativeCall<void, UPrimalItem*>(this, f, theItem); }
	void RemoveItemSpoilingTimer(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.RemoveItemSpoilingTimer" }; NativeCall<void, UPrimalItem*>(this, f, theItem); }
	bool LoadAdditionalStructureEngrams() { static NativeFunction f{ "UPrimalInventoryComponent.LoadAdditionalStructureEngrams" }; return NativeCall<bool>(this, f); }
	bool RemoveItem(FItemNetID* itemID, bool bDoDrop, bool bSecondryAction, bool bForceRemoval, bool showHUDMessage) { static NativeFunction f{ "UPrimalInventoryComponent.RemoveItem" }; return NativeCall<bool, FItemNetID*, bool, bool, bool, bool>(this, f, itemID, bDoDrop, bSecondryAction, bForceRemoval, showHUDMessage); }
	ADroppedItem* EjectItem(FItemNetID* itemID, bool bPreventImpule, bool bForceEject, bool bSetItemLocation, FVector* LocationOverride, bool showHUDMessage, TSubclassOf<ADroppedItem> TheDroppedTemplateOverride, bool bAssignToTribeForPickup, int AssignedTribeID) { static NativeFunction f{ "UPrimalInventoryComponent.EjectItem" }; return NativeCall<ADroppedItem*, FItemNetID*, bool, bool, bool, FVector*, bool, TSubclassOf<ADroppedItem>, bool, int>(this, f, itemID, bPreventImpule, bForceEject, bSetItemLocation, LocationOverride, showHUDMessage, TheDroppedTemplateOverride, bAssignToTribeForPickup, AssignedTribeID); }
	bool ServerEquipItem(FItemNetID* itemID) { static NativeFunction f{ "UPrimalInventoryComponent.ServerEquipItem" }; return NativeCall<bool, FItemNetID*>(this, f, itemID); }
	void DropItem(FItemNetInfo* theInfo, bool bOverrideSpawnTransform, FVector* LocationOverride, FRotator* RotationOverride, bool bPreventDropImpulse, bool bThrow, bool bSecondryAction, bool bSetItemDropLocation) { static NativeFunction f{ "UPrimalInventoryComponent.DropItem" }; NativeCall<void, FItemNetInfo*, bool, FVector*, FRotator*, bool, bool, bool, bool>(this, f, theInfo, bOverrideSpawnTransform, LocationOverride, RotationOverride, bPreventDropImpulse, bThrow, bSecondryAction, bSetItemDropLocation); }
	static ADroppedItem* StaticDropNewItem(AActor* forActor, TSubclassOf<UPrimalItem> AnItemClass, float ItemQuality, bool bForceNoBlueprint, int QuantityOverride, bool bForceBlueprint, TSubclassOf<ADroppedItem> TheDroppedTemplateOverride, FRotator* DroppedRotationOffset, bool bOverrideSpawnTransform, FVector* LocationOverride, FRotator* RotationOverride, bool bPreventDropImpulse, bool bThrow, bool bSecondaryAction, bool bSetItemDropLocation, UStaticMesh* DroppedMeshOverride, FVector DroppedScaleOverride, UMaterialInterface* DroppedMaterialOverride, float DroppedLifeSpanOverride) { static NativeFunction f{ "UPrimalInventoryComponent.StaticDropNewItem" }; return NativeCall<ADroppedItem*, AActor*, TSubclassOf<UPrimalItem>, float, bool, int, bool, TSubclassOf<ADroppedItem>, FRotator*, bool, FVector*, FRotator*, bool, bool, bool, bool, UStaticMesh*, FVector, UMaterialInterface*, float>(nullptr, f, forActor, AnItemClass, ItemQuality, bForceNoBlueprint, QuantityOverride, bForceBlueprint, TheDroppedTemplateOverride, DroppedRotationOffset, bOverrideSpawnTransform, LocationOverride, RotationOverride, bPreventDropImpulse, bThrow, bSecondaryAction, bSetItemDropLocation, DroppedMeshOverride, DroppedScaleOverride, DroppedMaterialOverride, DroppedLifeSpanOverride); }
	static ADroppedItem* StaticDropNewItemWithInfo(AActor* forActor, FItemNetInfo* ItemInfo, TSubclassOf<ADroppedItem> TheDroppedTemplateOverride, FRotator* DroppedRotationOffset, bool bOverrideSpawnTransform, FVector* LocationOverride, FRotator* RotationOverride, bool bPreventDropImpulse, bool bThrow, bool bSecondaryAction, bool bSetItemDropLocation, UStaticMesh* DroppedMeshOverride, FVector DroppedScaleOverride, UMaterialInterface* DroppedMaterialOverride, float DroppedLifeSpanOverride) { static NativeFunction f{ "UPrimalInventoryComponent.StaticDropNewItemWithInfo" }; return NativeCall<ADroppedItem*, AActor*, FItemNetInfo*, TSubclassOf<ADroppedItem>, FRotator*, bool, FVector*, FRotator*, bool, bool, bool, bool, UStaticMesh*, FVector, UMaterialInterface*, float>(nullptr, f, forActor, ItemInfo, TheDroppedTemplateOverride, DroppedRotationOffset, bOverrideSpawnTransform, LocationOverride, RotationOverride, bPreventDropImpulse, bThrow, bSecondaryAction, bSetItemDropLocation, DroppedMeshOverride, DroppedScaleOverride, DroppedMaterialOverride, DroppedLifeSpanOverride); }
	static ADroppedItem* StaticDropItem(AActor* forActor, FItemNetInfo* theInfo, TSubclassOf<ADroppedItem> TheDroppedTemplateOverride, FRotator* DroppedRotationOffset, bool bOverrideSpawnTransform, FVector* LocationOverride, FRotator* RotationOverride, bool bPreventDropImpulse, bool bThrow, bool bSecondryAction, bool bSetItemDropLocation, UStaticMesh* DroppedMeshOverride, FVector* DroppedScaleOverride, UMaterialInterface* DroppedMaterialOverride, float DroppedLifeSpanOverride) { static NativeFunction f{ "UPrimalInventoryComponent.StaticDropItem" }; return NativeCall<ADroppedItem*, AActor*, FItemNetInfo*, TSubclassOf<ADroppedItem>, FRotator*, bool, FVector*, FRotator*, bool, bool, bool, bool, UStaticMesh*, FVector*, UMaterialInterface*, float>(nullptr, f, forActor, theInfo, TheDroppedTemplateOverride, DroppedRotationOffset, bOverrideSpawnTransform, LocationOverride, RotationOverride, bPreventDropImpulse, bThrow, bSecondryAction, bSetItemDropLocation, DroppedMeshOverride, DroppedScaleOverride, DroppedMaterialOverride, DroppedLifeSpanOverride); }
	AShooterPlayerController* GetOwnerController() { static NativeFunction f{ "UPrimalInventoryComponent.GetOwnerController" }; return NativeCall<AShooterPlayerController*>(this, f); }
	void InventoryViewersPlayLocalSound(USoundBase* aSound, bool bAttach) { static NativeFunction f{ "UPrimalInventoryComponent.InventoryViewersPlayLocalSound" }; NativeCall<void, USoundBase*, bool>(this, f, aSound, bAttach); }
	void InventoryViewersStopLocalSound(USoundBase* aSound) { static NativeFunction f{ "UPrimalInventoryComponent.InventoryViewersStopLocalSound" }; NativeCall<void, USoundBase*>(this, f, aSound); }
	void UpdateNetWeaponClipAmmo(UPrimalItem* anItem, int ammo) { static NativeFunction f{ "UPrimalInventoryComponent.UpdateNetWeaponClipAmmo" }; NativeCall<void, UPrimalItem*, int>(this, f, anItem, ammo); }
	void NotifyClientsItemStatus(UPrimalItem* anItem, bool bEquippedItem, bool bRemovedItem, bool bOnlyUpdateQuantity, bool bOnlyUpdateDurability, bool bOnlyNotifyItemSwap, UPrimalItem* anItem2, FItemNetID* InventoryInsertAfterItemID, bool bUsedItem, bool bNotifyCraftQueue, bool ShowHUDNotification) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyClientsItemStatus" }; NativeCall<void, UPrimalItem*, bool, bool, bool, bool, bool, UPrimalItem*, FItemNetID*, bool, bool, bool>(this, f, anItem, bEquippedItem, bRemovedItem, bOnlyUpdateQuantity, bOnlyUpdateDurability, bOnlyNotifyItemSwap, anItem2, InventoryInsertAfterItemID, bUsedItem, bNotifyCraftQueue, ShowHUDNotification); }
	void NotifyClientsDurabilityChange(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyClientsDurabilityChange" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	void NotifyClientItemArkTributeStatusChanged(UPrimalItem* anItem, bool bRemoved, bool bFromLoad) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyClientItemArkTributeStatusChanged" }; NativeCall<void, UPrimalItem*, bool, bool>(this, f, anItem, bRemoved, bFromLoad); }
	void ServerRequestItems(AShooterPlayerController* forPC, bool bEquippedItems, bool bIsFirstSpawn) { static NativeFunction f{ "UPrimalInventoryComponent.ServerRequestItems" }; NativeCall<void, AShooterPlayerController*, bool, bool>(this, f, forPC, bEquippedItems, bIsFirstSpawn); }
	void ClientStartReceivingItems(bool bEquippedItems) { static NativeFunction f{ "UPrimalInventoryComponent.ClientStartReceivingItems" }; NativeCall<void, bool>(this, f, bEquippedItems); }
	void ClientFinishReceivingItems(bool bEquippedItems) { static NativeFunction f{ "UPrimalInventoryComponent.ClientFinishReceivingItems" }; NativeCall<void, bool>(this, f, bEquippedItems); }
	TArray<UPrimalItem*>* FindColorItem(TArray<UPrimalItem*>* result, FColor theColor, bool bEquippedItems) { static NativeFunction f{ "UPrimalInventoryComponent.FindColorItem" }; return NativeCall<TArray<UPrimalItem*>*, TArray<UPrimalItem*>*, FColor, bool>(this, f, result, theColor, bEquippedItems); }
	TArray<UPrimalItem*>* FindBrushColorItem(TArray<UPrimalItem*>* result, __int16 ArchIndex) { static NativeFunction f{ "UPrimalInventoryComponent.FindBrushColorItem" }; return NativeCall<TArray<UPrimalItem*>*, TArray<UPrimalItem*>*, __int16>(this, f, result, ArchIndex); }
	UPrimalItem* FindItem(FItemNetID* ItemID, bool bEquippedItems, bool bAllItems, int* itemIdx) { static NativeFunction f{ "UPrimalInventoryComponent.FindItem" }; return NativeCall<UPrimalItem*, FItemNetID*, bool, bool, int*>(this, f, ItemID, bEquippedItems, bAllItems, itemIdx); }
	void GiveInitialItems(bool SkipEngrams) { static NativeFunction f{ "UPrimalInventoryComponent.GiveInitialItems" }; NativeCall<void, bool>(this, f, SkipEngrams); }
	void InitDefaultInventory() { static NativeFunction f{ "UPrimalInventoryComponent.InitDefaultInventory" }; NativeCall<void>(this, f); }
	void DeferredDeprecationCheck() { static NativeFunction f{ "UPrimalInventoryComponent.DeferredDeprecationCheck" }; NativeCall<void>(this, f); }
	void InitializeInventory() { static NativeFunction f{ "UPrimalInventoryComponent.InitializeInventory" }; NativeCall<void>(this, f); }
	void CheckRefreshDefaultInventoryItems() { static NativeFunction f{ "UPrimalInventoryComponent.CheckRefreshDefaultInventoryItems" }; NativeCall<void>(this, f); }
	void SetEquippedItemsOwnerNoSee(bool bNewOwnerNoSee, bool bForceHideFirstPerson) { static NativeFunction f{ "UPrimalInventoryComponent.SetEquippedItemsOwnerNoSee" }; NativeCall<void, bool, bool>(this, f, bNewOwnerNoSee, bForceHideFirstPerson); }
	bool RemoteInventoryAllowViewing(AShooterPlayerController* PC, float MaxAllowedDistanceOffset) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteInventoryAllowViewing" }; return NativeCall<bool, AShooterPlayerController*, float>(this, f, PC, MaxAllowedDistanceOffset); }
	bool RemoteInventoryAllowAddItems(AShooterPlayerController* PC, UPrimalItem* anItem, int* anItemQuantityOverride, bool bRequestedByPlayer) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteInventoryAllowAddItems" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*, int*, bool>(this, f, PC, anItem, anItemQuantityOverride, bRequestedByPlayer); }
	bool RemoteInventoryAllowRemoveItems(AShooterPlayerController* PC, UPrimalItem* anItemToTransfer, int* requestedQuantity, bool bRequestedByPlayer, bool bRequestDropping) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteInventoryAllowRemoveItems" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*, int*, bool, bool>(this, f, PC, anItemToTransfer, requestedQuantity, bRequestedByPlayer, bRequestDropping); }
	bool RemoteInventoryAllowCraftingItems(AShooterPlayerController* PC, bool bIgnoreEnabled) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteInventoryAllowCraftingItems" }; return NativeCall<bool, AShooterPlayerController*, bool>(this, f, PC, bIgnoreEnabled); }
	bool RemoteInventoryAllowRepairingItems(AShooterPlayerController* PC, bool bIgnoreEnabled) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteInventoryAllowRepairingItems" }; return NativeCall<bool, AShooterPlayerController*, bool>(this, f, PC, bIgnoreEnabled); }
	bool AllowAddingToArkTribute() { static NativeFunction f{ "UPrimalInventoryComponent.AllowAddingToArkTribute" }; return NativeCall<bool>(this, f); }
	void ServerViewRemoteInventory(AShooterPlayerController* ByPC) { static NativeFunction f{ "UPrimalInventoryComponent.ServerViewRemoteInventory" }; NativeCall<void, AShooterPlayerController*>(this, f, ByPC); }
	void ServerCloseRemoteInventory(AShooterPlayerController* ByPC) { static NativeFunction f{ "UPrimalInventoryComponent.ServerCloseRemoteInventory" }; NativeCall<void, AShooterPlayerController*>(this, f, ByPC); }
	void ClientUpdateFreeCraftingMode_Implementation(bool bNewFreeCraftingModeValue) { static NativeFunction f{ "UPrimalInventoryComponent.ClientUpdateFreeCraftingMode_Implementation" }; NativeCall<void, bool>(this, f, bNewFreeCraftingModeValue); }
	void OnComponentDestroyed() { static NativeFunction f{ "UPrimalInventoryComponent.OnComponentDestroyed" }; NativeCall<void>(this, f); }
	void SwapCustomFolder(FString CFolder1, FString CFolder2, int DataListType) { static NativeFunction f{ "UPrimalInventoryComponent.SwapCustomFolder" }; NativeCall<void, FString, FString, int>(this, f, CFolder1, CFolder2, DataListType); }
	bool AddToFolders(TArray<FString>* FoldersFound, UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.AddToFolders" }; return NativeCall<bool, TArray<FString>*, UPrimalItem*>(this, f, FoldersFound, anItem); }
	UObject* GetObjectW() { static NativeFunction f{ "UPrimalInventoryComponent.GetObjectW" }; return NativeCall<UObject*>(this, f); }
	FString* GetInventoryName(FString* result, bool bIsEquipped) { static NativeFunction f{ "UPrimalInventoryComponent.GetInventoryName" }; return NativeCall<FString*, FString*, bool>(this, f, result, bIsEquipped); }
	int GetFirstUnoccupiedSlot(AShooterPlayerState* forPlayerState, UPrimalItem* forItem) { static NativeFunction f{ "UPrimalInventoryComponent.GetFirstUnoccupiedSlot" }; return NativeCall<int, AShooterPlayerState*, UPrimalItem*>(this, f, forPlayerState, forItem); }
	void ServerMakeRecipeItem_Implementation(APrimalStructureItemContainer* Container, FItemNetID NoteToConsume, TSubclassOf<UPrimalItem> RecipeItemTemplate, FString* CustomName, FString* CustomDescription, TArray<FColor>* CustomColors, TArray<FCraftingResourceRequirement>* CustomRequirements) { static NativeFunction f{ "UPrimalInventoryComponent.ServerMakeRecipeItem_Implementation" }; NativeCall<void, APrimalStructureItemContainer*, FItemNetID, TSubclassOf<UPrimalItem>, FString*, FString*, TArray<FColor>*, TArray<FCraftingResourceRequirement>*>(this, f, Container, NoteToConsume, RecipeItemTemplate, CustomName, CustomDescription, CustomColors, CustomRequirements); }
	void ServerRemoveItemFromSlot_Implementation(FItemNetID ItemID) { static NativeFunction f{ "UPrimalInventoryComponent.ServerRemoveItemFromSlot_Implementation" }; NativeCall<void, FItemNetID>(this, f, ItemID); }
	void ServerAddItemToSlot_Implementation(FItemNetID ItemID, int SlotIndex) { static NativeFunction f{ "UPrimalInventoryComponent.ServerAddItemToSlot_Implementation" }; NativeCall<void, FItemNetID, int>(this, f, ItemID, SlotIndex); }
	UPrimalItem* GetEquippedItemOfType(EPrimalEquipmentType::Type aType) { static NativeFunction f{ "UPrimalInventoryComponent.GetEquippedItemOfType" }; return NativeCall<UPrimalItem*, EPrimalEquipmentType::Type>(this, f, aType); }
	UPrimalItem* GetEquippedItemOfClass(TSubclassOf<UPrimalItem> ItemClass) { static NativeFunction f{ "UPrimalInventoryComponent.GetEquippedItemOfClass" }; return NativeCall<UPrimalItem*, TSubclassOf<UPrimalItem>>(this, f, ItemClass); }
	int IncrementItemTemplateQuantity(TSubclassOf<UPrimalItem> ItemTemplate, int amount, bool bReplicateToClient, bool bIsBlueprint, UPrimalItem** UseSpecificItem, UPrimalItem** IncrementedItem, bool bRequireExactClassMatch, bool bIsCraftingResourceConsumption, bool bIsFromUseConsumption, bool bIsArkTributeItem, bool ShowHUDNotification, bool bDontRecalcSpoilingTime, bool bDontExceedMaxItems) { static NativeFunction f{ "UPrimalInventoryComponent.IncrementItemTemplateQuantity" }; return NativeCall<int, TSubclassOf<UPrimalItem>, int, bool, bool, UPrimalItem**, UPrimalItem**, bool, bool, bool, bool, bool, bool, bool>(this, f, ItemTemplate, amount, bReplicateToClient, bIsBlueprint, UseSpecificItem, IncrementedItem, bRequireExactClassMatch, bIsCraftingResourceConsumption, bIsFromUseConsumption, bIsArkTributeItem, ShowHUDNotification, bDontRecalcSpoilingTime, bDontExceedMaxItems); }
	bool IncrementArkTributeItemQuantity(UPrimalItem* NewItem, UPrimalItem** IncrementedItem) { static NativeFunction f{ "UPrimalInventoryComponent.IncrementArkTributeItemQuantity" }; return NativeCall<bool, UPrimalItem*, UPrimalItem**>(this, f, NewItem, IncrementedItem); }
	UPrimalItem* GetItemOfTemplate(TSubclassOf<UPrimalItem> ItemTemplate, bool bOnlyInventoryItems, bool bOnlyEquippedItems, bool IgnoreItemsWithFullQuantity, bool bFavorSlotItems, bool bIsBlueprint, UPrimalItem* CheckCanStackWithItem, bool bRequiresExactClassMatch, int* CheckCanStackWithItemQuantityOverride, bool bIgnoreSlotItems, bool bOnlyArkTributeItems, bool bPreferEngram, bool bIsForCraftingConsumption) { static NativeFunction f{ "UPrimalInventoryComponent.GetItemOfTemplate" }; return NativeCall<UPrimalItem*, TSubclassOf<UPrimalItem>, bool, bool, bool, bool, bool, UPrimalItem*, bool, int*, bool, bool, bool, bool>(this, f, ItemTemplate, bOnlyInventoryItems, bOnlyEquippedItems, IgnoreItemsWithFullQuantity, bFavorSlotItems, bIsBlueprint, CheckCanStackWithItem, bRequiresExactClassMatch, CheckCanStackWithItemQuantityOverride, bIgnoreSlotItems, bOnlyArkTributeItems, bPreferEngram, bIsForCraftingConsumption); }
	TArray<UPrimalItem*>* FindAllItemsOfType(TArray<UPrimalItem*>* result, TSubclassOf<UPrimalItem> ItemTemplate, bool bRequiresExactClassMatch, bool bIncludeInventoryItems, bool bIncludeEquippedItems, bool bIncludeArkTributeItems, bool bIncludeSlotItems, bool bIncludeBlueprints, bool bIncludeEngrams) { static NativeFunction f{ "UPrimalInventoryComponent.FindAllItemsOfType" }; return NativeCall<TArray<UPrimalItem*>*, TArray<UPrimalItem*>*, TSubclassOf<UPrimalItem>, bool, bool, bool, bool, bool, bool, bool>(this, f, result, ItemTemplate, bRequiresExactClassMatch, bIncludeInventoryItems, bIncludeEquippedItems, bIncludeArkTributeItems, bIncludeSlotItems, bIncludeBlueprints, bIncludeEngrams); }
	int GetCraftQueueResourceCost(TSubclassOf<UPrimalItem> ItemTemplate, UPrimalItem* IgnoreFirstItem) { static NativeFunction f{ "UPrimalInventoryComponent.GetCraftQueueResourceCost" }; return NativeCall<int, TSubclassOf<UPrimalItem>, UPrimalItem*>(this, f, ItemTemplate, IgnoreFirstItem); }
	int GetItemTemplateQuantity(TSubclassOf<UPrimalItem> ItemTemplate, UPrimalItem* IgnoreItem, bool bIgnoreBlueprints, bool bCheckValidForCrafting, bool bRequireExactClassMatch, bool bForceCheckForDupes) { static NativeFunction f{ "UPrimalInventoryComponent.GetItemTemplateQuantity" }; return NativeCall<int, TSubclassOf<UPrimalItem>, UPrimalItem*, bool, bool, bool, bool>(this, f, ItemTemplate, IgnoreItem, bIgnoreBlueprints, bCheckValidForCrafting, bRequireExactClassMatch, bForceCheckForDupes); }
	float GetTotalDurabilityOfTemplate(TSubclassOf<UPrimalItem> ItemTemplate) { static NativeFunction f{ "UPrimalInventoryComponent.GetTotalDurabilityOfTemplate" }; return NativeCall<float, TSubclassOf<UPrimalItem>>(this, f, ItemTemplate); }
	void LocalUseItemSlot(int slotIndex, bool bForceCraft) { static NativeFunction f{ "UPrimalInventoryComponent.LocalUseItemSlot" }; NativeCall<void, int, bool>(this, f, slotIndex, bForceCraft); }
	void ShowBeforeUsingConfirmationDialog(UPrimalItem* Item) { static NativeFunction f{ "UPrimalInventoryComponent.ShowBeforeUsingConfirmationDialog" }; NativeCall<void, UPrimalItem*>(this, f, Item); }
	float GetTotalEquippedItemStat(EPrimalItemStat::Type statType) { static NativeFunction f{ "UPrimalInventoryComponent.GetTotalEquippedItemStat" }; return NativeCall<float, EPrimalItemStat::Type>(this, f, statType); }
	float GetEquippedArmorRating(EPrimalEquipmentType::Type equipmentType) { static NativeFunction f{ "UPrimalInventoryComponent.GetEquippedArmorRating" }; return NativeCall<float, EPrimalEquipmentType::Type>(this, f, equipmentType); }
	void ConsumeArmorDurability(float ConsumptionAmount, bool bAllArmorTypes, EPrimalEquipmentType::Type SpecificArmorType) { static NativeFunction f{ "UPrimalInventoryComponent.ConsumeArmorDurability" }; NativeCall<void, float, bool, EPrimalEquipmentType::Type>(this, f, ConsumptionAmount, bAllArmorTypes, SpecificArmorType); }
	void ServerCraftItem(FItemNetID* itemID, AShooterPlayerController* ByPC) { static NativeFunction f{ "UPrimalInventoryComponent.ServerCraftItem" }; NativeCall<void, FItemNetID*, AShooterPlayerController*>(this, f, itemID, ByPC); }
	void AddToCraftQueue(UPrimalItem* anItem, AShooterPlayerController* ByPC, bool bIsRepair, bool bRepairIgnoreInventoryRequirement, float RepairPercentage, float RepairSpeedMultiplier) { static NativeFunction f{ "UPrimalInventoryComponent.AddToCraftQueue" }; NativeCall<void, UPrimalItem*, AShooterPlayerController*, bool, bool, float, float>(this, f, anItem, ByPC, bIsRepair, bRepairIgnoreInventoryRequirement, RepairPercentage, RepairSpeedMultiplier); }
	void ClearCraftQueue(bool bForceClearActiveCraftRepair) { static NativeFunction f{ "UPrimalInventoryComponent.ClearCraftQueue" }; NativeCall<void, bool>(this, f, bForceClearActiveCraftRepair); }
	void ServerRepairItem(FItemNetID* itemID, AShooterPlayerController* ByPC, bool bRepairIgnoreInventoryRequirement, float RepairPercentage, float RepairSpeedMultiplier) { static NativeFunction f{ "UPrimalInventoryComponent.ServerRepairItem" }; NativeCall<void, FItemNetID*, AShooterPlayerController*, bool, float, float>(this, f, itemID, ByPC, bRepairIgnoreInventoryRequirement, RepairPercentage, RepairSpeedMultiplier); }
	void ServerUseInventoryItem(FItemNetID* itemID, AShooterPlayerController* ByPC) { static NativeFunction f{ "UPrimalInventoryComponent.ServerUseInventoryItem" }; NativeCall<void, FItemNetID*, AShooterPlayerController*>(this, f, itemID, ByPC); }
	void ServerUseItemWithItem(FItemNetID* itemID1, FItemNetID* itemID2, int AdditionalData) { static NativeFunction f{ "UPrimalInventoryComponent.ServerUseItemWithItem" }; NativeCall<void, FItemNetID*, FItemNetID*, int>(this, f, itemID1, itemID2, AdditionalData); }
	void SwapInventoryItems(FItemNetID* itemID1, FItemNetID* itemID2) { static NativeFunction f{ "UPrimalInventoryComponent.SwapInventoryItems" }; NativeCall<void, FItemNetID*, FItemNetID*>(this, f, itemID1, itemID2); }
	void AddItemCrafting(UPrimalItem* craftingItem) { static NativeFunction f{ "UPrimalInventoryComponent.AddItemCrafting" }; NativeCall<void, UPrimalItem*>(this, f, craftingItem); }
	void RemoveItemCrafting(UPrimalItem* craftingItem) { static NativeFunction f{ "UPrimalInventoryComponent.RemoveItemCrafting" }; NativeCall<void, UPrimalItem*>(this, f, craftingItem); }
	void StopAllCraftingRepairing() { static NativeFunction f{ "UPrimalInventoryComponent.StopAllCraftingRepairing" }; NativeCall<void>(this, f); }
	void TickCraftQueue(float DeltaTime, AShooterGameState* theGameState) { static NativeFunction f{ "UPrimalInventoryComponent.TickCraftQueue" }; NativeCall<void, float, AShooterGameState*>(this, f, DeltaTime, theGameState); }
	float GetCraftingSpeed() { static NativeFunction f{ "UPrimalInventoryComponent.GetCraftingSpeed" }; return NativeCall<float>(this, f); }
	AShooterHUD* GetLocalOwnerHUD() { static NativeFunction f{ "UPrimalInventoryComponent.GetLocalOwnerHUD" }; return NativeCall<AShooterHUD*>(this, f); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "UPrimalInventoryComponent.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	bool AllowOwnerStasis() { static NativeFunction f{ "UPrimalInventoryComponent.AllowOwnerStasis" }; return NativeCall<bool>(this, f); }
	bool IsLocal() { static NativeFunction f{ "UPrimalInventoryComponent.IsLocal" }; return NativeCall<bool>(this, f); }
	bool IsLocalToPlayer(AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalInventoryComponent.IsLocalToPlayer" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	int GetMaxInventoryItems(bool bIgnoreHiddenDefaultInventory) { static NativeFunction f{ "UPrimalInventoryComponent.GetMaxInventoryItems" }; return NativeCall<int, bool>(this, f, bIgnoreHiddenDefaultInventory); }
	int GetCurrentNumInventoryItems() { static NativeFunction f{ "UPrimalInventoryComponent.GetCurrentNumInventoryItems" }; return NativeCall<int>(this, f); }
	void Unstasised() { static NativeFunction f{ "UPrimalInventoryComponent.Unstasised" }; NativeCall<void>(this, f); }
	void CheckForAutoCraftBlueprints() { static NativeFunction f{ "UPrimalInventoryComponent.CheckForAutoCraftBlueprints" }; NativeCall<void>(this, f); }
	bool IsCraftingAllowed(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.IsCraftingAllowed" }; return NativeCall<bool, UPrimalItem*>(this, f, anItem); }
	void SetCraftingEnabled(bool bEnable) { static NativeFunction f{ "UPrimalInventoryComponent.SetCraftingEnabled" }; NativeCall<void, bool>(this, f, bEnable); }
	bool IsRepairingAllowed() { static NativeFunction f{ "UPrimalInventoryComponent.IsRepairingAllowed" }; return NativeCall<bool>(this, f); }
	float GetInventoryWeight() { static NativeFunction f{ "UPrimalInventoryComponent.GetInventoryWeight" }; return NativeCall<float>(this, f); }
	void ServerSplitItemStack_Implementation(FItemNetID ItemID, int AmountToSplit) { static NativeFunction f{ "UPrimalInventoryComponent.ServerSplitItemStack_Implementation" }; NativeCall<void, FItemNetID, int>(this, f, ItemID, AmountToSplit); }
	void ServerMergeItemStack_Implementation(FItemNetID ItemID) { static NativeFunction f{ "UPrimalInventoryComponent.ServerMergeItemStack_Implementation" }; NativeCall<void, FItemNetID>(this, f, ItemID); }
	void GrindItem(FItemNetID ItemID, const bool grindStack, AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalInventoryComponent.GrindItem" }; NativeCall<void, FItemNetID, const bool, AShooterPlayerController*>(this, f, ItemID, grindStack, PC); }
	void OnGrindItem() { static NativeFunction f{ "UPrimalInventoryComponent.OnGrindItem" }; NativeCall<void>(this, f); }
	void ServerForceMergeItemStack_Implementation(FItemNetID Item1ID, FItemNetID Item2ID) { static NativeFunction f{ "UPrimalInventoryComponent.ServerForceMergeItemStack_Implementation" }; NativeCall<void, FItemNetID, FItemNetID>(this, f, Item1ID, Item2ID); }
	void RemoteDeleteCustomFolder(FString* CFolderName, int InventoryCompType) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteDeleteCustomFolder" }; NativeCall<void, FString*, int>(this, f, CFolderName, InventoryCompType); }
	void RemoteAddItemToCustomFolder(FString* CFolderName, int InventoryCompType, FItemNetID ItemId) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteAddItemToCustomFolder" }; NativeCall<void, FString*, int, FItemNetID>(this, f, CFolderName, InventoryCompType, ItemId); }
	void RemoteDeleteItemFromCustomFolder(AShooterPlayerController* PC, FString* CFolderName, int InventoryCompType, FItemNetID ItemId) { static NativeFunction f{ "UPrimalInventoryComponent.RemoteDeleteItemFromCustomFolder" }; NativeCall<void, AShooterPlayerController*, FString*, int, FItemNetID>(this, f, PC, CFolderName, InventoryCompType, ItemId); }
	UPrimalItem* FindInventoryStackableItemCompareQuantity(TSubclassOf<UPrimalItem> ItemClass, bool bFindLeastQuantity, UPrimalItem* StacksWithAndIgnoreItem) { static NativeFunction f{ "UPrimalInventoryComponent.FindInventoryStackableItemCompareQuantity" }; return NativeCall<UPrimalItem*, TSubclassOf<UPrimalItem>, bool, UPrimalItem*>(this, f, ItemClass, bFindLeastQuantity, StacksWithAndIgnoreItem); }
	UPrimalCharacterStatusComponent* GetCharacterStatusComponent() { static NativeFunction f{ "UPrimalInventoryComponent.GetCharacterStatusComponent" }; return NativeCall<UPrimalCharacterStatusComponent*>(this, f); }
	void ClientMultiUse(APlayerController* ForPC, int UseIndex, int hitBodyIndex) { static NativeFunction f{ "UPrimalInventoryComponent.ClientMultiUse" }; NativeCall<void, APlayerController*, int, int>(this, f, ForPC, UseIndex, hitBodyIndex); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex, int hitBodyIndex) { static NativeFunction f{ "UPrimalInventoryComponent.TryMultiUse" }; return NativeCall<bool, APlayerController*, int, int>(this, f, ForPC, UseIndex, hitBodyIndex); }
	void GetGrinderSettings_Implementation(int* MaxQuantityToGrind, float* GrindGiveItemsPercent, int* MaxItemsToGivePerGrind) { static NativeFunction f{ "UPrimalInventoryComponent.GetGrinderSettings_Implementation" }; NativeCall<void, int*, float*, int*>(this, f, MaxQuantityToGrind, GrindGiveItemsPercent, MaxItemsToGivePerGrind); }
	bool IsAllowedInventoryAccess(APlayerController* ForPC) { static NativeFunction f{ "UPrimalInventoryComponent.IsAllowedInventoryAccess" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	void ActivePlayerInventoryTick(float DeltaTime) { static NativeFunction f{ "UPrimalInventoryComponent.ActivePlayerInventoryTick" }; NativeCall<void, float>(this, f, DeltaTime); }
	void InventoryRefresh() { static NativeFunction f{ "UPrimalInventoryComponent.InventoryRefresh" }; NativeCall<void>(this, f); }
	void RefreshItemSpoilingTimes() { static NativeFunction f{ "UPrimalInventoryComponent.RefreshItemSpoilingTimes" }; NativeCall<void>(this, f); }
	void NotifyCraftingItemConsumption(TSubclassOf<UPrimalItem> ItemTemplate, int amount) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyCraftingItemConsumption" }; NativeCall<void, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, amount); }
	float GetSpoilingTimeMultiplier(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.GetSpoilingTimeMultiplier" }; return NativeCall<float, UPrimalItem*>(this, f, anItem); }
	long double GetLatestItemClassUseTime(TSubclassOf<UPrimalItem> ItemClass) { static NativeFunction f{ "UPrimalInventoryComponent.GetLatestItemClassUseTime" }; return NativeCall<long double, TSubclassOf<UPrimalItem>>(this, f, ItemClass); }
	void UsedItem(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.UsedItem" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	void RegisterComponentTickFunctions(bool bRegister, bool bSaveAndRestoreComponentTickState) { static NativeFunction f{ "UPrimalInventoryComponent.RegisterComponentTickFunctions" }; NativeCall<void, bool, bool>(this, f, bRegister, bSaveAndRestoreComponentTickState); }
	void UpdatedCraftQueue() { static NativeFunction f{ "UPrimalInventoryComponent.UpdatedCraftQueue" }; NativeCall<void>(this, f); }
	void LoadedFromSaveGame() { static NativeFunction f{ "UPrimalInventoryComponent.LoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void ClientItemMessageNotification_Implementation(FItemNetID ItemID, EPrimalItemMessage::Type ItemMessageType) { static NativeFunction f{ "UPrimalInventoryComponent.ClientItemMessageNotification_Implementation" }; NativeCall<void, FItemNetID, EPrimalItemMessage::Type>(this, f, ItemID, ItemMessageType); }
	bool IsOwnedByPlayer() { static NativeFunction f{ "UPrimalInventoryComponent.IsOwnedByPlayer" }; return NativeCall<bool>(this, f); }
	void OwnerDied() { static NativeFunction f{ "UPrimalInventoryComponent.OwnerDied" }; NativeCall<void>(this, f); }
	bool DropInventoryDeposit(long double DestroyAtTime, bool bDoPreventSendingData, bool bIgnorEquippedItems, TSubclassOf<APrimalStructureItemContainer> OverrideInventoryDepositClass, APrimalStructureItemContainer* CopyStructureValues, APrimalStructureItemContainer** DepositStructureResult, AActor* GroundIgnoreActor, FString CurrentCustomFolderFilter, FString CurrentNameFilter, unsigned __int64 DeathCacheCharacterID, float DropInventoryOnGroundTraceDistance, bool bForceDrop, int OverrideMaxItemsDropped, bool bOverrideDepositLocation, FVector* DepositLocationOverride, bool bForceLocation, bool bSkipDeathCache = false) { static NativeFunction f{ "UPrimalInventoryComponent.DropInventoryDeposit" }; return NativeCall<bool, long double, bool, bool, TSubclassOf<APrimalStructureItemContainer>, APrimalStructureItemContainer*, APrimalStructureItemContainer**, AActor*, FString, FString, unsigned __int64, float, bool, int, bool, FVector*, bool, bool>(this, f, DestroyAtTime, bDoPreventSendingData, bIgnorEquippedItems, OverrideInventoryDepositClass, CopyStructureValues, DepositStructureResult, GroundIgnoreActor, CurrentCustomFolderFilter, CurrentNameFilter, DeathCacheCharacterID, DropInventoryOnGroundTraceDistance, bForceDrop, OverrideMaxItemsDropped, bOverrideDepositLocation, DepositLocationOverride, bForceLocation, bSkipDeathCache); }
	bool DropNotReadyInventoryDeposit(long double DestroyAtTime) { static NativeFunction f{ "UPrimalInventoryComponent.DropNotReadyInventoryDeposit" }; return NativeCall<bool, long double>(this, f, DestroyAtTime); }
	bool GetGroundLocation(FVector* theGroundLoc, FVector* OffsetUp, FVector* OffsetDown, APrimalStructure** LandedOnStructure, AActor* IgnoreActor, bool bCheckAnyStationary, UPrimitiveComponent** LandedOnComponent, bool bUseInputGroundLocAsBase) { static NativeFunction f{ "UPrimalInventoryComponent.GetGroundLocation" }; return NativeCall<bool, FVector*, FVector*, FVector*, APrimalStructure**, AActor*, bool, UPrimitiveComponent**, bool>(this, f, theGroundLoc, OffsetUp, OffsetDown, LandedOnStructure, IgnoreActor, bCheckAnyStationary, LandedOnComponent, bUseInputGroundLocAsBase); }
	AActor* CraftedBlueprintSpawnActor(TSubclassOf<UPrimalItem> ForItemClass, TSubclassOf<AActor> ActorClassToSpawn) { static NativeFunction f{ "UPrimalInventoryComponent.CraftedBlueprintSpawnActor" }; return NativeCall<AActor*, TSubclassOf<UPrimalItem>, TSubclassOf<AActor>>(this, f, ForItemClass, ActorClassToSpawn); }
	void NotifyCraftedItem(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyCraftedItem" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	bool GenerateCrateItems(float MinQualityMultiplier, float MaxQualityMultiplier, int NumPasses, float QuantityMultiplier, float SetPowerWeight, float MaxItemDifficultyClamp) { static NativeFunction f{ "UPrimalInventoryComponent.GenerateCrateItems" }; return NativeCall<bool, float, float, int, float, float, float>(this, f, MinQualityMultiplier, MaxQualityMultiplier, NumPasses, QuantityMultiplier, SetPowerWeight, MaxItemDifficultyClamp); }
	bool GenerateCustomCrateItems(TSubclassOf<UObject> SourceClass, TArray<FSupplyCrateItemSet> CustomItemSets, float CustomMinItemSets, float CustomMaxItemSets, float CustomNumItemSetsPower, bool bCustomSetsRandomWithoutReplacement, TArray<UPrimalItem*>* GeneratedItems, float MinQualityMultiplier, float MaxQualityMultiplier, int NumPasses, float QuantityMultiplier, float SetPowerWeight, float MaxItemDifficultyClamp, bool bIsMissionReward) { static NativeFunction f{ "UPrimalInventoryComponent.GenerateCustomCrateItems" }; return NativeCall<bool, TSubclassOf<UObject>, TArray<FSupplyCrateItemSet>, float, float, float, bool, TArray<UPrimalItem*>*, float, float, int, float, float, float, bool>(this, f, SourceClass, CustomItemSets, CustomMinItemSets, CustomMaxItemSets, CustomNumItemSetsPower, bCustomSetsRandomWithoutReplacement, GeneratedItems, MinQualityMultiplier, MaxQualityMultiplier, NumPasses, QuantityMultiplier, SetPowerWeight, MaxItemDifficultyClamp, bIsMissionReward); }
	UPrimalItem* FindArkTributeItem(FItemNetID* ItemID) { static NativeFunction f{ "UPrimalInventoryComponent.FindArkTributeItem" }; return NativeCall<UPrimalItem*, FItemNetID*>(this, f, ItemID); }
	void SetNextItemSpoilingID_Implementation(FItemNetID NextItemID) { static NativeFunction f{ "UPrimalInventoryComponent.SetNextItemSpoilingID_Implementation" }; NativeCall<void, FItemNetID>(this, f, NextItemID); }
	void SetNextItemConsumptionID_Implementation(FItemNetID NextItemID) { static NativeFunction f{ "UPrimalInventoryComponent.SetNextItemConsumptionID_Implementation" }; NativeCall<void, FItemNetID>(this, f, NextItemID); }
	void CheckReplenishSlotIndex(int slotIndex, TSubclassOf<UPrimalItem> ClassCheckOverride) { static NativeFunction f{ "UPrimalInventoryComponent.CheckReplenishSlotIndex" }; NativeCall<void, int, TSubclassOf<UPrimalItem>>(this, f, slotIndex, ClassCheckOverride); }
	void OnArkTributeItemsRemoved(bool Success, TArray<FItemNetInfo>* RemovedItems, TArray<FItemNetInfo>* NotFoundItems, int FailureResponseCode, FString* FailureResponseMessage, bool bAllowForcedItemDownload) { static NativeFunction f{ "UPrimalInventoryComponent.OnArkTributeItemsRemoved" }; NativeCall<void, bool, TArray<FItemNetInfo>*, TArray<FItemNetInfo>*, int, FString*, bool>(this, f, Success, RemovedItems, NotFoundItems, FailureResponseCode, FailureResponseMessage, bAllowForcedItemDownload); }
	void ClientOnArkTributeItemsAdded_Implementation() { static NativeFunction f{ "UPrimalInventoryComponent.ClientOnArkTributeItemsAdded_Implementation" }; NativeCall<void>(this, f); }
	void OnArkTributeItemsAdded(bool Success, TArray<FItemNetInfo>* AddedItems) { static NativeFunction f{ "UPrimalInventoryComponent.OnArkTributeItemsAdded" }; NativeCall<void, bool, TArray<FItemNetInfo>*>(this, f, Success, AddedItems); }
	bool RemoveArkTributeItem(FItemNetID* itemID, unsigned int Quantity) { static NativeFunction f{ "UPrimalInventoryComponent.RemoveArkTributeItem" }; return NativeCall<bool, FItemNetID*, unsigned int>(this, f, itemID, Quantity); }
	bool ServerAddToArkTributeInventory(FItemNetID* itemID, TArray<unsigned __int64> SteamItemUserIds, FItemNetInfo* AlternateItemInfo) { static NativeFunction f{ "UPrimalInventoryComponent.ServerAddToArkTributeInventory" }; return NativeCall<bool, FItemNetID*, TArray<unsigned __int64>, FItemNetInfo*>(this, f, itemID, SteamItemUserIds, AlternateItemInfo); }
	UPrimalItem* AddAfterRemovingFromArkTributeInventory(UPrimalItem* Item, FItemNetInfo* MyItem, bool bAllowForcedItemDownload) { static NativeFunction f{ "UPrimalInventoryComponent.AddAfterRemovingFromArkTributeInventory" }; return NativeCall<UPrimalItem*, UPrimalItem*, FItemNetInfo*, bool>(this, f, Item, MyItem, bAllowForcedItemDownload); }
	bool ServerAddFromArkTributeInventory(FItemNetID* itemID, int Quantity) { static NativeFunction f{ "UPrimalInventoryComponent.ServerAddFromArkTributeInventory" }; return NativeCall<bool, FItemNetID*, int>(this, f, itemID, Quantity); }
	void RequestAddArkTributeItem(FItemNetInfo* theItemInfo, bool bFromLoad) { static NativeFunction f{ "UPrimalInventoryComponent.RequestAddArkTributeItem" }; NativeCall<void, FItemNetInfo*, bool>(this, f, theItemInfo, bFromLoad); }
	void AddArkTributeItem(FItemNetInfo* theItemInfo, bool bFromLoad) { static NativeFunction f{ "UPrimalInventoryComponent.AddArkTributeItem" }; NativeCall<void, FItemNetInfo*, bool>(this, f, theItemInfo, bFromLoad); }
	void LoadArkTriuteItems(TArray<FItemNetInfo>* ItemInfos, bool bClear, bool bFinalBatch) { static NativeFunction f{ "UPrimalInventoryComponent.LoadArkTriuteItems" }; NativeCall<void, TArray<FItemNetInfo>*, bool, bool>(this, f, ItemInfos, bClear, bFinalBatch); }
	void FinishedLoadingArkItems() { static NativeFunction f{ "UPrimalInventoryComponent.FinishedLoadingArkItems" }; NativeCall<void>(this, f); }
	void NotifyItemQuantityUpdated(UPrimalItem* anItem, int amount) { static NativeFunction f{ "UPrimalInventoryComponent.NotifyItemQuantityUpdated" }; NativeCall<void, UPrimalItem*, int>(this, f, anItem, amount); }
	bool IsServerCustomFolder(int InventoryCompType) { static NativeFunction f{ "UPrimalInventoryComponent.IsServerCustomFolder" }; return NativeCall<bool, int>(this, f, InventoryCompType); }
	void AddCustomFolder(FString CFolder, int InventoryCompType) { static NativeFunction f{ "UPrimalInventoryComponent.AddCustomFolder" }; NativeCall<void, FString, int>(this, f, CFolder, InventoryCompType); }
	void RemoveCustomFolder(AShooterPlayerController* PC, FString FolderName, int InventoryCompType) { static NativeFunction f{ "UPrimalInventoryComponent.RemoveCustomFolder" }; NativeCall<void, AShooterPlayerController*, FString, int>(this, f, PC, FolderName, InventoryCompType); }
	TArray<FString>* GetCustomFolders(TArray<FString>* result, int InventoryCompType) { static NativeFunction f{ "UPrimalInventoryComponent.GetCustomFolders" }; return NativeCall<TArray<FString>*, TArray<FString>*, int>(this, f, result, InventoryCompType); }
	void DeleteItemFromCustomFolder(AShooterPlayerController* PC, FString CFolder, FItemNetID ItemId, int InventoryCompType) { static NativeFunction f{ "UPrimalInventoryComponent.DeleteItemFromCustomFolder" }; NativeCall<void, AShooterPlayerController*, FString, FItemNetID, int>(this, f, PC, CFolder, ItemId, InventoryCompType); }
	int BPIncrementItemTemplateQuantity(TSubclassOf<UPrimalItem> ItemTemplate, int amount, bool bReplicateToClient, bool bIsBlueprint, bool bRequireExactClassMatch, bool bIsCraftingResourceConsumption, bool bIsFromUseConsumption, bool bIsArkTributeItem, UPrimalItem* UseSpecificItem, bool bDontExceedMaxItems) { static NativeFunction f{ "UPrimalInventoryComponent.BPIncrementItemTemplateQuantity" }; return NativeCall<int, TSubclassOf<UPrimalItem>, int, bool, bool, bool, bool, bool, bool, UPrimalItem*, bool>(this, f, ItemTemplate, amount, bReplicateToClient, bIsBlueprint, bRequireExactClassMatch, bIsCraftingResourceConsumption, bIsFromUseConsumption, bIsArkTributeItem, UseSpecificItem, bDontExceedMaxItems); }
	UPrimalItem* BPGetItemOfTemplate(TSubclassOf<UPrimalItem> ItemTemplate, bool bOnlyInventoryItems, bool bOnlyEquippedItems, bool IgnoreItemsWithFullQuantity, bool bFavorSlotItems, bool bIsBlueprint, bool bRequiresExactClassMatch, bool bIgnoreSlotItems, bool bOnlyArkItems, bool bPreferEngram, bool bIsForCraftingConsumption) { static NativeFunction f{ "UPrimalInventoryComponent.BPGetItemOfTemplate" }; return NativeCall<UPrimalItem*, TSubclassOf<UPrimalItem>, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool>(this, f, ItemTemplate, bOnlyInventoryItems, bOnlyEquippedItems, IgnoreItemsWithFullQuantity, bFavorSlotItems, bIsBlueprint, bRequiresExactClassMatch, bIgnoreSlotItems, bOnlyArkItems, bPreferEngram, bIsForCraftingConsumption); }
	bool HasItemsEquipped(TArray<TSubclassOf<UPrimalItem>>* ItemTemplates, bool bRequiresExactClassMatch, bool bOnlyArkItems, bool bEnsureAllItems) { static NativeFunction f{ "UPrimalInventoryComponent.HasItemsEquipped" }; return NativeCall<bool, TArray<TSubclassOf<UPrimalItem>>*, bool, bool, bool>(this, f, ItemTemplates, bRequiresExactClassMatch, bOnlyArkItems, bEnsureAllItems); }
	bool OverrideBlueprintCraftingRequirement(TSubclassOf<UPrimalItem> ItemTemplate, int ItemQuantity) { static NativeFunction f{ "UPrimalInventoryComponent.OverrideBlueprintCraftingRequirement" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, ItemQuantity); }
	bool AllowBlueprintCraftingRequirement(TSubclassOf<UPrimalItem> ItemTemplate, int ItemQuantity) { static NativeFunction f{ "UPrimalInventoryComponent.AllowBlueprintCraftingRequirement" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, ItemQuantity); }
	bool AllowCraftingResourceConsumption(TSubclassOf<UPrimalItem> ItemTemplate, int ItemQuantity) { static NativeFunction f{ "UPrimalInventoryComponent.AllowCraftingResourceConsumption" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, ItemQuantity); }
	float GetDamageTorpidityIncreaseMultiplierScale() { static NativeFunction f{ "UPrimalInventoryComponent.GetDamageTorpidityIncreaseMultiplierScale" }; return NativeCall<float>(this, f); }
	float GetIndirectTorpidityIncreaseMultiplierScale() { static NativeFunction f{ "UPrimalInventoryComponent.GetIndirectTorpidityIncreaseMultiplierScale" }; return NativeCall<float>(this, f); }
	float GetItemWeightMultiplier(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.GetItemWeightMultiplier" }; return NativeCall<float, UPrimalItem*>(this, f, anItem); }
	void UpdateTribeGroupInventoryRank_Implementation(char NewRank) { static NativeFunction f{ "UPrimalInventoryComponent.UpdateTribeGroupInventoryRank_Implementation" }; NativeCall<void, char>(this, f, NewRank); }
	void BPDropInventoryDeposit(long double DestroyAtTime, int OverrideMaxItemsDropped, bool bOverrideCacheLocation, FVector CacheLocationOverride) { static NativeFunction f{ "UPrimalInventoryComponent.BPDropInventoryDeposit" }; NativeCall<void, long double, int, bool, FVector>(this, f, DestroyAtTime, OverrideMaxItemsDropped, bOverrideCacheLocation, CacheLocationOverride); }
	void BPDropForceLocationInventoryDeposit(long double DestroyAtTime, int OverrideMaxItemsDropped, FVector CacheLocationOverride, int DeadPlayerID) { static NativeFunction f{ "UPrimalInventoryComponent.BPDropForceLocationInventoryDeposit" }; NativeCall<void, long double, int, FVector, int>(this, f, DestroyAtTime, OverrideMaxItemsDropped, CacheLocationOverride, DeadPlayerID); }
	float OverrideItemMinimumUseInterval(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.OverrideItemMinimumUseInterval" }; return NativeCall<float, UPrimalItem*>(this, f, theItem); }
	UPrimalItem* AddItemObject(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.AddItemObject" }; return NativeCall<UPrimalItem*, UPrimalItem*>(this, f, anItem); }
	UPrimalItem* AddItemObjectEx(UPrimalItem* anItem, bool bEquipItem, bool AddToSlot, bool bDontStack, bool ShowHUDNotification, bool bDontRecalcSpoilingTime, bool bForceIncompleteStacking, AShooterCharacter* OwnerPlayer, bool bClampStats, UPrimalItem* InsertAfterItem, bool bInsertAtItemInstead) { static NativeFunction f{ "UPrimalInventoryComponent.AddItemObjectEx" }; return NativeCall<UPrimalItem*, UPrimalItem*, bool, bool, bool, bool, bool, bool, AShooterCharacter*, bool, UPrimalItem*, bool>(this, f, anItem, bEquipItem, AddToSlot, bDontStack, ShowHUDNotification, bDontRecalcSpoilingTime, bForceIncompleteStacking, OwnerPlayer, bClampStats, InsertAfterItem, bInsertAtItemInstead); }
	UPrimalItem* BPFindItemWithID(int ItemID1, int ItemID2) { static NativeFunction f{ "UPrimalInventoryComponent.BPFindItemWithID" }; return NativeCall<UPrimalItem*, int, int>(this, f, ItemID1, ItemID2); }
	bool AllowAddInventoryItem_OnlyAddAll(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.AllowAddInventoryItem_OnlyAddAll" }; return NativeCall<bool, UPrimalItem*>(this, f, anItem); }
	bool AllowAddInventoryItem_MaxQuantity(UPrimalItem* anItem, const int* requestedQuantityIn, int* requestedQuantityOut) { static NativeFunction f{ "UPrimalInventoryComponent.AllowAddInventoryItem_MaxQuantity" }; return NativeCall<bool, UPrimalItem*, const int*, int*>(this, f, anItem, requestedQuantityIn, requestedQuantityOut); }
	bool AllowAddInventoryItem_AnyQuantity(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.AllowAddInventoryItem_AnyQuantity" }; return NativeCall<bool, UPrimalItem*>(this, f, anItem); }
	bool BPRemoteInventoryAllowAddItems(AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryAllowAddItems" }; return NativeCall<bool, AShooterPlayerController*>(this, f, PC); }
	bool BPRemoteInventoryAllowAddItem(AShooterPlayerController* PC, UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryAllowAddItem" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*>(this, f, PC, anItem); }
	bool BPRemoteInventoryAllowAddItem_SpecificQuantity(AShooterPlayerController* PC, UPrimalItem* anItem, const int* SpecificQuantityIn, int* SpecificQuantityOut) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryAllowAddItem_SpecificQuantity" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*, const int*, int*>(this, f, PC, anItem, SpecificQuantityIn, SpecificQuantityOut); }
	bool IsValidCraftingResource(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.IsValidCraftingResource" }; return NativeCall<bool, UPrimalItem*>(this, f, theItem); }
	void OnComponentCreated() { static NativeFunction f{ "UPrimalInventoryComponent.OnComponentCreated" }; NativeCall<void>(this, f); }
	void Serialize(FArchive* Ar) { static NativeFunction f{ "UPrimalInventoryComponent.Serialize" }; NativeCall<void, FArchive*>(this, f, Ar); }
	bool IsAtMaxInventoryItems() { static NativeFunction f{ "UPrimalInventoryComponent.IsAtMaxInventoryItems" }; return NativeCall<bool>(this, f); }
	void TransferAllItemsToInventory(UPrimalInventoryComponent* ToInventory) { static NativeFunction f{ "UPrimalInventoryComponent.TransferAllItemsToInventory" }; NativeCall<void, UPrimalInventoryComponent*>(this, f, ToInventory); }
	static void StaticRegisterNativesUPrimalInventoryComponent() { static NativeFunction f{ "UPrimalInventoryComponent.StaticRegisterNativesUPrimalInventoryComponent" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "UPrimalInventoryComponent.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	void BPAccessedInventory(AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalInventoryComponent.BPAccessedInventory" }; NativeCall<void, AShooterPlayerController*>(this, f, ForPC); }
	bool BPAllowAddInventoryItem(UPrimalItem* Item, int RequestedQuantity, bool bOnlyAddAll) { static NativeFunction f{ "UPrimalInventoryComponent.BPAllowAddInventoryItem" }; return NativeCall<bool, UPrimalItem*, int, bool>(this, f, Item, RequestedQuantity, bOnlyAddAll); }
	bool BPAllowUseInInventory(UPrimalItem* theItem, bool bIsRemoteInventory, AShooterPlayerController* ByPC) { static NativeFunction f{ "UPrimalInventoryComponent.BPAllowUseInInventory" }; return NativeCall<bool, UPrimalItem*, bool, AShooterPlayerController*>(this, f, theItem, bIsRemoteInventory, ByPC); }
	void BPCraftingFinishedNotification(UPrimalItem* itemToBeCrafted) { static NativeFunction f{ "UPrimalInventoryComponent.BPCraftingFinishedNotification" }; NativeCall<void, UPrimalItem*>(this, f, itemToBeCrafted); }
	bool BPCustomRemoteInventoryAllowAddItems(AShooterPlayerController* PC, UPrimalItem* anItem, int anItemQuantityOverride, bool bRequestedByPlayer) { static NativeFunction f{ "UPrimalInventoryComponent.BPCustomRemoteInventoryAllowAddItems" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*, int, bool>(this, f, PC, anItem, anItemQuantityOverride, bRequestedByPlayer); }
	bool BPCustomRemoteInventoryAllowRemoveItems(AShooterPlayerController* PC, UPrimalItem* anItemToTransfer, int requestedQuantity, bool bRequestedByPlayer, bool bIsRepairing = false) { static NativeFunction f{ "UPrimalInventoryComponent.BPCustomRemoteInventoryAllowRemoveItems" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*, int, bool, bool>(this, f, PC, anItemToTransfer, requestedQuantity, bRequestedByPlayer, bIsRepairing); }
	void BPGetExtraItemDisplay(bool* bShowExtraItem, FString* Description, FString* CustomString, UTexture2D** EntryIcon, UMaterialInterface** EntryMaterial) { static NativeFunction f{ "UPrimalInventoryComponent.BPGetExtraItemDisplay" }; NativeCall<void, bool*, FString*, FString*, UTexture2D**, UMaterialInterface**>(this, f, bShowExtraItem, Description, CustomString, EntryIcon, EntryMaterial); }
	void BPInitializeInventory() { static NativeFunction f{ "UPrimalInventoryComponent.BPInitializeInventory" }; NativeCall<void>(this, f); }
	void BPInventoryRefresh() { static NativeFunction f{ "UPrimalInventoryComponent.BPInventoryRefresh" }; NativeCall<void>(this, f); }
	bool BPIsCraftingAllowed(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPIsCraftingAllowed" }; return NativeCall<bool, UPrimalItem*>(this, f, anItem); }
	bool BPIsValidCraftingResource(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPIsValidCraftingResource" }; return NativeCall<bool, UPrimalItem*>(this, f, theItem); }
	void BPNotifyItemAdded(UPrimalItem* anItem, bool bEquipItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPNotifyItemAdded" }; NativeCall<void, UPrimalItem*, bool>(this, f, anItem, bEquipItem); }
	void BPNotifyItemQuantityUpdated(UPrimalItem* anItem, int amount) { static NativeFunction f{ "UPrimalInventoryComponent.BPNotifyItemQuantityUpdated" }; NativeCall<void, UPrimalItem*, int>(this, f, anItem, amount); }
	void BPNotifyItemRemoved(UPrimalItem* anItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPNotifyItemRemoved" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	float BPOverrideItemMinimumUseInterval(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPOverrideItemMinimumUseInterval" }; return NativeCall<float, UPrimalItem*>(this, f, theItem); }
	void BPPostInitDefaultInventory() { static NativeFunction f{ "UPrimalInventoryComponent.BPPostInitDefaultInventory" }; NativeCall<void>(this, f); }
	void BPPreInitDefaultInventory() { static NativeFunction f{ "UPrimalInventoryComponent.BPPreInitDefaultInventory" }; NativeCall<void>(this, f); }
	bool BPPreventEquipItem(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.BPPreventEquipItem" }; return NativeCall<bool, UPrimalItem*>(this, f, theItem); }
	bool BPPreventEquipItemType(EPrimalEquipmentType::Type equipmentType) { static NativeFunction f{ "UPrimalInventoryComponent.BPPreventEquipItemType" }; return NativeCall<bool, EPrimalEquipmentType::Type>(this, f, equipmentType); }
	bool BPRemoteInventoryAllowCrafting(AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryAllowCrafting" }; return NativeCall<bool, AShooterPlayerController*>(this, f, PC); }
	bool BPRemoteInventoryAllowRemoveItems(AShooterPlayerController* PC, UPrimalItem* anItemToTransfer) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryAllowRemoveItems" }; return NativeCall<bool, AShooterPlayerController*, UPrimalItem*>(this, f, PC, anItemToTransfer); }
	bool BPRemoteInventoryAllowViewing(AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryAllowViewing" }; return NativeCall<bool, AShooterPlayerController*>(this, f, PC); }
	int BPRemoteInventoryGetMaxVisibleSlots(int NumItems, AShooterPlayerController* PC, bool bIsLocal) { static NativeFunction f{ "UPrimalInventoryComponent.BPRemoteInventoryGetMaxVisibleSlots" }; return NativeCall<int, int, AShooterPlayerController*, bool>(this, f, NumItems, PC, bIsLocal); }
	void BPRequestedInventoryItems(AShooterPlayerController* forPC) { static NativeFunction f{ "UPrimalInventoryComponent.BPRequestedInventoryItems" }; NativeCall<void, AShooterPlayerController*>(this, f, forPC); }
	bool CanGrindItem(UPrimalItem* item) { static NativeFunction f{ "UPrimalInventoryComponent.CanGrindItem" }; return NativeCall<bool, UPrimalItem*>(this, f, item); }
	bool CanGrindItems(AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalInventoryComponent.CanGrindItems" }; return NativeCall<bool, AShooterPlayerController*>(this, f, PC); }
	void ClientItemMessageNotification(FItemNetID ItemID, EPrimalItemMessage::Type ItemMessageType) { static NativeFunction f{ "UPrimalInventoryComponent.ClientItemMessageNotification" }; NativeCall<void, FItemNetID, EPrimalItemMessage::Type>(this, f, ItemID, ItemMessageType); }
	void ClientOnArkTributeItemsAdded() { static NativeFunction f{ "UPrimalInventoryComponent.ClientOnArkTributeItemsAdded" }; NativeCall<void>(this, f); }
	void ClientUpdateFreeCraftingMode(bool bNewFreeCraftingModeValue) { static NativeFunction f{ "UPrimalInventoryComponent.ClientUpdateFreeCraftingMode" }; NativeCall<void, bool>(this, f, bNewFreeCraftingModeValue); }
	void GetGrinderSettings(int* MaxQuantityToGrind, float* GrindGiveItemsPercent, int* MaxItemsToGivePerGrind) { static NativeFunction f{ "UPrimalInventoryComponent.GetGrinderSettings" }; NativeCall<void, int*, float*, int*>(this, f, MaxQuantityToGrind, GrindGiveItemsPercent, MaxItemsToGivePerGrind); }
	bool OverrideUseItem(UPrimalItem* theItem) { static NativeFunction f{ "UPrimalInventoryComponent.OverrideUseItem" }; return NativeCall<bool, UPrimalItem*>(this, f, theItem); }
	void ServerAddItemToSlot(FItemNetID ItemID, int SlotIndex) { static NativeFunction f{ "UPrimalInventoryComponent.ServerAddItemToSlot" }; NativeCall<void, FItemNetID, int>(this, f, ItemID, SlotIndex); }
	void ServerForceMergeItemStack(FItemNetID Item1ID, FItemNetID Item2ID) { static NativeFunction f{ "UPrimalInventoryComponent.ServerForceMergeItemStack" }; NativeCall<void, FItemNetID, FItemNetID>(this, f, Item1ID, Item2ID); }
	void ServerMakeRecipeItem(APrimalStructureItemContainer* Container, FItemNetID NoteToConsume, TSubclassOf<UPrimalItem> RecipeItemTemplate, FString* CustomName, FString* CustomDescription, TArray<FColor>* CustomColors, TArray<FCraftingResourceRequirement>* CustomRequirements) { static NativeFunction f{ "UPrimalInventoryComponent.ServerMakeRecipeItem" }; NativeCall<void, APrimalStructureItemContainer*, FItemNetID, TSubclassOf<UPrimalItem>, FString*, FString*, TArray<FColor>*, TArray<FCraftingResourceRequirement>*>(this, f, Container, NoteToConsume, RecipeItemTemplate, CustomName, CustomDescription, CustomColors, CustomRequirements); }
	void ServerRemoveItemFromSlot(FItemNetID ItemID) { static NativeFunction f{ "UPrimalInventoryComponent.ServerRemoveItemFromSlot" }; NativeCall<void, FItemNetID>(this, f, ItemID); }
	void ServerSplitItemStack(FItemNetID ItemID, int AmountToSplit) { static NativeFunction f{ "UPrimalInventoryComponent.ServerSplitItemStack" }; NativeCall<void, FItemNetID, int>(this, f, ItemID, AmountToSplit); }
	void SetNextItemConsumptionID(FItemNetID NextItemID) { static NativeFunction f{ "UPrimalInventoryComponent.SetNextItemConsumptionID" }; NativeCall<void, FItemNetID>(this, f, NextItemID); }
	void SetNextItemSpoilingID(FItemNetID NextItemID) { static NativeFunction f{ "UPrimalInventoryComponent.SetNextItemSpoilingID" }; NativeCall<void, FItemNetID>(this, f, NextItemID); }
	void UpdateTribeGroupInventoryRank(char NewRank) { static NativeFunction f{ "UPrimalInventoryComponent.UpdateTribeGroupInventoryRank" }; NativeCall<void, char>(this, f, NewRank); }
};

struct UPrimalItem : UObject
{
	float& DinoAutoHealingThresholdPercentField() { static NativeFieldOffset f{ "UPrimalItem.DinoAutoHealingThresholdPercent" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoAutoHealingUseTimeIntervalField() { static NativeFieldOffset f{ "UPrimalItem.DinoAutoHealingUseTimeInterval" }; return *GetNativePointerField<float*>(this, f); }
	int& ArkTributeVersionField() { static NativeFieldOffset f{ "UPrimalItem.ArkTributeVersion" }; return *GetNativePointerField<int*>(this, f); }
	TArray<TSubclassOf<AActor>>& EquipRequiresExplicitOwnerClassesField() { static NativeFieldOffset f{ "UPrimalItem.EquipRequiresExplicitOwnerClasses" }; return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, f); }
	TArray<FName>& EquipRequiresExplicitOwnerTagsField() { static NativeFieldOffset f{ "UPrimalItem.EquipRequiresExplicitOwnerTags" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	TSubclassOf<APrimalBuff>& BuffToGiveOwnerWhenEquippedField() { static NativeFieldOffset f{ "UPrimalItem.BuffToGiveOwnerWhenEquipped" }; return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, f); }
	FString& BuffToGiveOwnerWhenEquipped_BlueprintPathField() { static NativeFieldOffset f{ "UPrimalItem.BuffToGiveOwnerWhenEquipped_BlueprintPath" }; return *GetNativePointerField<FString*>(this, f); }
	bool& bBuffToGiveOwnerWhenEquipped_SoftRefCachedField() { static NativeFieldOffset f{ "UPrimalItem.bBuffToGiveOwnerWhenEquipped_SoftRefCached" }; return *GetNativePointerField<bool*>(this, f); }
	unsigned int& ExpirationTimeUTCField() { static NativeFieldOffset f{ "UPrimalItem.ExpirationTimeUTC" }; return *GetNativePointerField<unsigned int*>(this, f); }
	int& BlueprintAllowMaxCraftingsField() { static NativeFieldOffset f{ "UPrimalItem.BlueprintAllowMaxCraftings" }; return *GetNativePointerField<int*>(this, f); }
	FString& AbstractItemCraftingDescriptionField() { static NativeFieldOffset f{ "UPrimalItem.AbstractItemCraftingDescription" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& ItemSkinUseOnItemClassesField() { static NativeFieldOffset f{ "UPrimalItem.ItemSkinUseOnItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& ItemSkinPreventOnItemClassesField() { static NativeFieldOffset f{ "UPrimalItem.ItemSkinPreventOnItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	USoundBase* ItemBrokenSoundField() { static NativeFieldOffset f{ "UPrimalItem.ItemBrokenSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundCue* UseItemSoundField() { static NativeFieldOffset f{ "UPrimalItem.UseItemSound" }; return *GetNativePointerField<USoundCue**>(this, f); }
	USoundBase* EquipSoundField() { static NativeFieldOffset f{ "UPrimalItem.EquipSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* UnEquipSoundField() { static NativeFieldOffset f{ "UPrimalItem.UnEquipSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* UsedOnOtherItemSoundField() { static NativeFieldOffset f{ "UPrimalItem.UsedOnOtherItemSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* RemovedFromOtherItemSoundField() { static NativeFieldOffset f{ "UPrimalItem.RemovedFromOtherItemSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	float& RandomChanceToBeBlueprintField() { static NativeFieldOffset f{ "UPrimalItem.RandomChanceToBeBlueprint" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FActorClassAttachmentInfo>& ActorClassAttachmentInfosField() { static NativeFieldOffset f{ "UPrimalItem.ActorClassAttachmentInfos" }; return *GetNativePointerField<TArray<FActorClassAttachmentInfo>*>(this, f); }
	TArray<FItemAttachmentInfo>* ItemAttachmentInfosField() { static NativeFieldOffset f{ "UPrimalItem.ItemAttachmentInfos" }; return *GetNativePointerField<TArray<FItemAttachmentInfo>**>(this, f); }
	TArray<FItemAttachmentInfo>& DynamicItemAttachmentInfosField() { static NativeFieldOffset f{ "UPrimalItem.DynamicItemAttachmentInfos" }; return *GetNativePointerField<TArray<FItemAttachmentInfo>*>(this, f); }
	TArray<FItemAttachmentInfo>& ItemSkinAddItemAttachmentsField() { static NativeFieldOffset f{ "UPrimalItem.ItemSkinAddItemAttachments" }; return *GetNativePointerField<TArray<FItemAttachmentInfo>*>(this, f); }
	TEnumAsByte<enum EPrimalItemType::Type>& MyItemTypeField() { static NativeFieldOffset f{ "UPrimalItem.MyItemType" }; return *GetNativePointerField<TEnumAsByte<enum EPrimalItemType::Type>*>(this, f); }
	TEnumAsByte<enum EPrimalConsumableType::Type>& MyConsumableTypeField() { static NativeFieldOffset f{ "UPrimalItem.MyConsumableType" }; return *GetNativePointerField<TEnumAsByte<enum EPrimalConsumableType::Type>*>(this, f); }
	TEnumAsByte<enum EPrimalEquipmentType::Type>& MyEquipmentTypeField() { static NativeFieldOffset f{ "UPrimalItem.MyEquipmentType" }; return *GetNativePointerField<TEnumAsByte<enum EPrimalEquipmentType::Type>*>(this, f); }
	int& ExtraItemCategoryFlagsField() { static NativeFieldOffset f{ "UPrimalItem.ExtraItemCategoryFlags" }; return *GetNativePointerField<int*>(this, f); }
	float& ItemIconScaleField() { static NativeFieldOffset f{ "UPrimalItem.ItemIconScale" }; return *GetNativePointerField<float*>(this, f); }
	FVector& BlockingShieldFPVTranslationField() { static NativeFieldOffset f{ "UPrimalItem.BlockingShieldFPVTranslation" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& BlockingShieldFPVRotationField() { static NativeFieldOffset f{ "UPrimalItem.BlockingShieldFPVRotation" }; return *GetNativePointerField<FRotator*>(this, f); }
	float& ShieldBlockDamagePercentageField() { static NativeFieldOffset f{ "UPrimalItem.ShieldBlockDamagePercentage" }; return *GetNativePointerField<float*>(this, f); }
	float& ShieldDamageToDurabilityRatioField() { static NativeFieldOffset f{ "UPrimalItem.ShieldDamageToDurabilityRatio" }; return *GetNativePointerField<float*>(this, f); }
	UAnimMontage* PlayAnimationOnUseField() { static NativeFieldOffset f{ "UPrimalItem.PlayAnimationOnUse" }; return *GetNativePointerField<UAnimMontage**>(this, f); }
	int& CraftingMinLevelRequirementField() { static NativeFieldOffset f{ "UPrimalItem.CraftingMinLevelRequirement" }; return *GetNativePointerField<int*>(this, f); }
	float& CraftingCooldownIntervalField() { static NativeFieldOffset f{ "UPrimalItem.CraftingCooldownInterval" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<AActor>& CraftingActorToSpawnField() { static NativeFieldOffset f{ "UPrimalItem.CraftingActorToSpawn" }; return *GetNativePointerField<TSubclassOf<AActor>*>(this, f); }
	UTexture2D* BlueprintBackgroundOverrideTextureField() { static NativeFieldOffset f{ "UPrimalItem.BlueprintBackgroundOverrideTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	FString& CraftItemButtonStringOverrideField() { static NativeFieldOffset f{ "UPrimalItem.CraftItemButtonStringOverride" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<AActor>& UseSpawnActorClassField() { static NativeFieldOffset f{ "UPrimalItem.UseSpawnActorClass" }; return *GetNativePointerField<TSubclassOf<AActor>*>(this, f); }
	FVector& UseSpawnActorLocOffsetField() { static NativeFieldOffset f{ "UPrimalItem.UseSpawnActorLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	int& SlotIndexField() { static NativeFieldOffset f{ "UPrimalItem.SlotIndex" }; return *GetNativePointerField<int*>(this, f); }
	FItemNetID& ItemIDField() { static NativeFieldOffset f{ "UPrimalItem.ItemID" }; return *GetNativePointerField<FItemNetID*>(this, f); }
	int& ItemCustomDataField() { static NativeFieldOffset f{ "UPrimalItem.ItemCustomData" }; return *GetNativePointerField<int*>(this, f); }
	TSubclassOf<UPrimalItem>& ItemCustomClassField() { static NativeFieldOffset f{ "UPrimalItem.ItemCustomClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	int& ItemSkinTemplateIndexField() { static NativeFieldOffset f{ "UPrimalItem.ItemSkinTemplateIndex" }; return *GetNativePointerField<int*>(this, f); }
	TSubclassOf<UPrimalItem>& ItemSkinTemplateField() { static NativeFieldOffset f{ "UPrimalItem.ItemSkinTemplate" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& ItemRatingField() { static NativeFieldOffset f{ "UPrimalItem.ItemRating" }; return *GetNativePointerField<float*>(this, f); }
	unsigned __int16& CraftQueueField() { static NativeFieldOffset f{ "UPrimalItem.CraftQueue" }; return *GetNativePointerField<unsigned __int16*>(this, f); }
	float& CraftingSkillField() { static NativeFieldOffset f{ "UPrimalItem.CraftingSkill" }; return *GetNativePointerField<float*>(this, f); }
	FString& CustomItemNameField() { static NativeFieldOffset f{ "UPrimalItem.CustomItemName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CustomItemDescriptionField() { static NativeFieldOffset f{ "UPrimalItem.CustomItemDescription" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FColor>& CustomColorsField() { static NativeFieldOffset f{ "UPrimalItem.CustomColors" }; return *GetNativePointerField<TArray<FColor>*>(this, f); }
	TArray<FCraftingResourceRequirement>& CustomResourceRequirementsField() { static NativeFieldOffset f{ "UPrimalItem.CustomResourceRequirements" }; return *GetNativePointerField<TArray<FCraftingResourceRequirement>*>(this, f); }
	long double& NextCraftCompletionTimeField() { static NativeFieldOffset f{ "UPrimalItem.NextCraftCompletionTime" }; return *GetNativePointerField<long double*>(this, f); }
	TWeakObjectPtr<UPrimalInventoryComponent>& OwnerInventoryField() { static NativeFieldOffset f{ "UPrimalItem.OwnerInventory" }; return *GetNativePointerField<TWeakObjectPtr<UPrimalInventoryComponent>*>(this, f); }
	unsigned char& ItemQualityIndexField() { static NativeFieldOffset f{ "UPrimalItem.ItemQualityIndex" }; return *GetNativePointerField<unsigned char*>(this, f); }
	TSubclassOf<UPrimalItem>& SupportDragOntoItemClassField() { static NativeFieldOffset f{ "UPrimalItem.SupportDragOntoItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& SupportDragOntoItemClassesField() { static NativeFieldOffset f{ "UPrimalItem.SupportDragOntoItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<AShooterWeapon>>& SkinWeaponTemplatesField() { static NativeFieldOffset f{ "UPrimalItem.SkinWeaponTemplates" }; return *GetNativePointerField<TArray<TSubclassOf<AShooterWeapon>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& SupportAmmoItemForWeaponSkinField() { static NativeFieldOffset f{ "UPrimalItem.SupportAmmoItemForWeaponSkin" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<AShooterWeapon>>& SkinWeaponTemplatesForAmmoField() { static NativeFieldOffset f{ "UPrimalItem.SkinWeaponTemplatesForAmmo" }; return *GetNativePointerField<TArray<TSubclassOf<AShooterWeapon>>*>(this, f); }
	TSubclassOf<AShooterWeapon>& AmmoSupportDragOntoWeaponItemWeaponTemplateField() { static NativeFieldOffset f{ "UPrimalItem.AmmoSupportDragOntoWeaponItemWeaponTemplate" }; return *GetNativePointerField<TSubclassOf<AShooterWeapon>*>(this, f); }
	TArray<TSubclassOf<AShooterWeapon>>& AmmoSupportDragOntoWeaponItemWeaponTemplatesField() { static NativeFieldOffset f{ "UPrimalItem.AmmoSupportDragOntoWeaponItemWeaponTemplates" }; return *GetNativePointerField<TArray<TSubclassOf<AShooterWeapon>>*>(this, f); }
	TArray<FUseItemAddCharacterStatusValue>& UseItemAddCharacterStatusValuesField() { static NativeFieldOffset f{ "UPrimalItem.UseItemAddCharacterStatusValues" }; return *GetNativePointerField<TArray<FUseItemAddCharacterStatusValue>*>(this, f); }
	float& Ingredient_WeightIncreasePerQuantityField() { static NativeFieldOffset f{ "UPrimalItem.Ingredient_WeightIncreasePerQuantity" }; return *GetNativePointerField<float*>(this, f); }
	float& Ingredient_FoodIncreasePerQuantityField() { static NativeFieldOffset f{ "UPrimalItem.Ingredient_FoodIncreasePerQuantity" }; return *GetNativePointerField<float*>(this, f); }
	float& Ingredient_HealthIncreasePerQuantityField() { static NativeFieldOffset f{ "UPrimalItem.Ingredient_HealthIncreasePerQuantity" }; return *GetNativePointerField<float*>(this, f); }
	float& Ingredient_WaterIncreasePerQuantityField() { static NativeFieldOffset f{ "UPrimalItem.Ingredient_WaterIncreasePerQuantity" }; return *GetNativePointerField<float*>(this, f); }
	float& Ingredient_StaminaIncreasePerQuantityField() { static NativeFieldOffset f{ "UPrimalItem.Ingredient_StaminaIncreasePerQuantity" }; return *GetNativePointerField<float*>(this, f); }
	FString& DescriptiveNameBaseField() { static NativeFieldOffset f{ "UPrimalItem.DescriptiveNameBase" }; return *GetNativePointerField<FString*>(this, f); }
	FString& ItemDescriptionField() { static NativeFieldOffset f{ "UPrimalItem.ItemDescription" }; return *GetNativePointerField<FString*>(this, f); }
	FString& DurabilityStringShortField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityStringShort" }; return *GetNativePointerField<FString*>(this, f); }
	FString& DurabilityStringField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityString" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CustomRepairTextField() { static NativeFieldOffset f{ "UPrimalItem.CustomRepairText" }; return *GetNativePointerField<FString*>(this, f); }
	float& DroppedItemLifeSpanOverrideField() { static NativeFieldOffset f{ "UPrimalItem.DroppedItemLifeSpanOverride" }; return *GetNativePointerField<float*>(this, f); }
	UStaticMesh* DroppedMeshOverrideField() { static NativeFieldOffset f{ "UPrimalItem.DroppedMeshOverride" }; return *GetNativePointerField<UStaticMesh**>(this, f); }
	UMaterialInterface* DroppedMeshMaterialOverrideField() { static NativeFieldOffset f{ "UPrimalItem.DroppedMeshMaterialOverride" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	FVector& DroppedMeshOverrideScale3DField() { static NativeFieldOffset f{ "UPrimalItem.DroppedMeshOverrideScale3D" }; return *GetNativePointerField<FVector*>(this, f); }
	TSubclassOf<UPrimalItem>& SpoilingItemField() { static NativeFieldOffset f{ "UPrimalItem.SpoilingItem" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<TSubclassOf<AActor>>& UseRequiresOwnerActorClassesField() { static NativeFieldOffset f{ "UPrimalItem.UseRequiresOwnerActorClasses" }; return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, f); }
	TSubclassOf<UPrimalItem>& PreservingItemClassField() { static NativeFieldOffset f{ "UPrimalItem.PreservingItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& PreservingItemSpoilingTimeMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.PreservingItemSpoilingTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& SpoilingTimeField() { static NativeFieldOffset f{ "UPrimalItem.SpoilingTime" }; return *GetNativePointerField<float*>(this, f); }
	int& CraftingConsumesDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.CraftingConsumesDurability" }; return *GetNativePointerField<int*>(this, f); }
	float& RepairResourceRequirementMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.RepairResourceRequirementMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& BaseItemWeightField() { static NativeFieldOffset f{ "UPrimalItem.BaseItemWeight" }; return *GetNativePointerField<float*>(this, f); }
	float& DurabilityIncreaseMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityIncreaseMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& NewItemDurabilityOverrideField() { static NativeFieldOffset f{ "UPrimalItem.NewItemDurabilityOverride" }; return *GetNativePointerField<float*>(this, f); }
	float& DurabilityDecreaseMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityDecreaseMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& UseDecreaseDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.UseDecreaseDurability" }; return *GetNativePointerField<float*>(this, f); }
	float& AutoDurabilityDecreaseIntervalField() { static NativeFieldOffset f{ "UPrimalItem.AutoDurabilityDecreaseInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& AutoDecreaseMinDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.AutoDecreaseMinDurability" }; return *GetNativePointerField<float*>(this, f); }
	float& AutoDecreaseDurabilityAmountPerIntervalField() { static NativeFieldOffset f{ "UPrimalItem.AutoDecreaseDurabilityAmountPerInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& UseDecreaseDurabilityMinField() { static NativeFieldOffset f{ "UPrimalItem.UseDecreaseDurabilityMin" }; return *GetNativePointerField<float*>(this, f); }
	float& UseMinDurabilityRequirementField() { static NativeFieldOffset f{ "UPrimalItem.UseMinDurabilityRequirement" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourceRarityField() { static NativeFieldOffset f{ "UPrimalItem.ResourceRarity" }; return *GetNativePointerField<float*>(this, f); }
	float& BlueprintTimeToCraftField() { static NativeFieldOffset f{ "UPrimalItem.BlueprintTimeToCraft" }; return *GetNativePointerField<float*>(this, f); }
	float& MinBlueprintTimeToCraftField() { static NativeFieldOffset f{ "UPrimalItem.MinBlueprintTimeToCraft" }; return *GetNativePointerField<float*>(this, f); }
	float& BlueprintWeightField() { static NativeFieldOffset f{ "UPrimalItem.BlueprintWeight" }; return *GetNativePointerField<float*>(this, f); }
	float& MinimumUseIntervalField() { static NativeFieldOffset f{ "UPrimalItem.MinimumUseInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& TimeForFullRepairField() { static NativeFieldOffset f{ "UPrimalItem.TimeForFullRepair" }; return *GetNativePointerField<float*>(this, f); }
	float& BaseCraftingXPField() { static NativeFieldOffset f{ "UPrimalItem.BaseCraftingXP" }; return *GetNativePointerField<float*>(this, f); }
	float& BaseRepairingXPField() { static NativeFieldOffset f{ "UPrimalItem.BaseRepairingXP" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FCraftingResourceRequirement>& BaseCraftingResourceRequirementsField() { static NativeFieldOffset f{ "UPrimalItem.BaseCraftingResourceRequirements" }; return *GetNativePointerField<TArray<FCraftingResourceRequirement>*>(this, f); }
	TArray<FCraftingResourceRequirement>& OverrideRepairingRequirementsField() { static NativeFieldOffset f{ "UPrimalItem.OverrideRepairingRequirements" }; return *GetNativePointerField<TArray<FCraftingResourceRequirement>*>(this, f); }
	FieldArray<FItemStatInfo, 8> ItemStatInfosField() { static NativeFieldOffset f{ "UPrimalItem.ItemStatInfos" }; return { this, f }; }
	FieldArray<unsigned __int16, 8> ItemStatValuesField() { static NativeFieldOffset f{ "UPrimalItem.ItemStatValues" }; return { this, f }; }
	unsigned int& WeaponClipAmmoField() { static NativeFieldOffset f{ "UPrimalItem.WeaponClipAmmo" }; return *GetNativePointerField<unsigned int*>(this, f); }
	float& WeaponFrequencyField() { static NativeFieldOffset f{ "UPrimalItem.WeaponFrequency" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastTimeToShowInfoField() { static NativeFieldOffset f{ "UPrimalItem.LastTimeToShowInfo" }; return *GetNativePointerField<long double*>(this, f); }
	unsigned char& ItemVersionField() { static NativeFieldOffset f{ "UPrimalItem.ItemVersion" }; return *GetNativePointerField<unsigned char*>(this, f); }
	float& ItemDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.ItemDurability" }; return *GetNativePointerField<float*>(this, f); }
	float& MinItemDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.MinItemDurability" }; return *GetNativePointerField<float*>(this, f); }
	float& SavedDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.SavedDurability" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<AShooterWeapon>& WeaponTemplateField() { static NativeFieldOffset f{ "UPrimalItem.WeaponTemplate" }; return *GetNativePointerField<TSubclassOf<AShooterWeapon>*>(this, f); }
	UTexture2D* BrokenIconField() { static NativeFieldOffset f{ "UPrimalItem.BrokenIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* ItemIconField() { static NativeFieldOffset f{ "UPrimalItem.ItemIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* AlternateItemIconBelowDurabilityField() { static NativeFieldOffset f{ "UPrimalItem.AlternateItemIconBelowDurability" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	float& AlternateItemIconBelowDurabilityValueField() { static NativeFieldOffset f{ "UPrimalItem.AlternateItemIconBelowDurabilityValue" }; return *GetNativePointerField<float*>(this, f); }
	float& DurabilityNotifyThresholdValueField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityNotifyThresholdValue" }; return *GetNativePointerField<float*>(this, f); }
	UMaterialInterface* ItemIconMaterialParentField() { static NativeFieldOffset f{ "UPrimalItem.ItemIconMaterialParent" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	FieldArray<__int16, 6> ItemColorIDField() { static NativeFieldOffset f{ "UPrimalItem.ItemColorID" }; return { this, f }; }
	FieldArray<__int16, 6> PreSkinItemColorIDField() { static NativeFieldOffset f{ "UPrimalItem.PreSkinItemColorID" }; return { this, f }; }
	FieldArray<unsigned char, 6> bUseItemColorField() { static NativeFieldOffset f{ "UPrimalItem.bUseItemColor" }; return { this, f }; }
	TSubclassOf<UPrimalColorSet>& RandomColorSetField() { static NativeFieldOffset f{ "UPrimalItem.RandomColorSet" }; return *GetNativePointerField<TSubclassOf<UPrimalColorSet>*>(this, f); }
	int& ItemQuantityField() { static NativeFieldOffset f{ "UPrimalItem.ItemQuantity" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxItemQuantityField() { static NativeFieldOffset f{ "UPrimalItem.MaxItemQuantity" }; return *GetNativePointerField<int*>(this, f); }
	TArray<unsigned __int64>& SteamItemUserIDsField() { static NativeFieldOffset f{ "UPrimalItem.SteamItemUserIDs" }; return *GetNativePointerField<TArray<unsigned __int64>*>(this, f); }
	TSubclassOf<APrimalStructure>& StructureToBuildField() { static NativeFieldOffset f{ "UPrimalItem.StructureToBuild" }; return *GetNativePointerField<TSubclassOf<APrimalStructure>*>(this, f); }
	TSubclassOf<UPrimalItem>& GiveItemWhenUsedField() { static NativeFieldOffset f{ "UPrimalItem.GiveItemWhenUsed" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<TSubclassOf<UPrimalInventoryComponent>>& CraftingRequiresInventoryComponentField() { static NativeFieldOffset f{ "UPrimalItem.CraftingRequiresInventoryComponent" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalInventoryComponent>>*>(this, f); }
	TSubclassOf<ADroppedItem>& DroppedItemTemplateOverrideField() { static NativeFieldOffset f{ "UPrimalItem.DroppedItemTemplateOverride" }; return *GetNativePointerField<TSubclassOf<ADroppedItem>*>(this, f); }
	TSubclassOf<ADroppedItem>& DroppedItemTemplateForSecondryActionField() { static NativeFieldOffset f{ "UPrimalItem.DroppedItemTemplateForSecondryAction" }; return *GetNativePointerField<TSubclassOf<ADroppedItem>*>(this, f); }
	TSubclassOf<APrimalBuff>& BuffToGiveOwnerCharacterField() { static NativeFieldOffset f{ "UPrimalItem.BuffToGiveOwnerCharacter" }; return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, f); }
	FRotator& PreviewCameraRotationField() { static NativeFieldOffset f{ "UPrimalItem.PreviewCameraRotation" }; return *GetNativePointerField<FRotator*>(this, f); }
	FVector& PreviewCameraPivotOffsetField() { static NativeFieldOffset f{ "UPrimalItem.PreviewCameraPivotOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& PreviewCameraDistanceScaleFactorField() { static NativeFieldOffset f{ "UPrimalItem.PreviewCameraDistanceScaleFactor" }; return *GetNativePointerField<float*>(this, f); }
	float& PreviewCameraDefaultZoomMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.PreviewCameraDefaultZoomMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PreviewCameraMaxZoomMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.PreviewCameraMaxZoomMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FName& PlayerMeshTextureMaskParamNameField() { static NativeFieldOffset f{ "UPrimalItem.PlayerMeshTextureMaskParamName" }; return *GetNativePointerField<FName*>(this, f); }
	UTexture2D* PlayerMeshTextureMaskField() { static NativeFieldOffset f{ "UPrimalItem.PlayerMeshTextureMask" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* PlayerMeshNoItemDefaultTextureMaskField() { static NativeFieldOffset f{ "UPrimalItem.PlayerMeshNoItemDefaultTextureMask" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	int& PlayerMeshTextureMaskMaterialIndexField() { static NativeFieldOffset f{ "UPrimalItem.PlayerMeshTextureMaskMaterialIndex" }; return *GetNativePointerField<int*>(this, f); }
	FName& FPVHandsMeshTextureMaskParamNameField() { static NativeFieldOffset f{ "UPrimalItem.FPVHandsMeshTextureMaskParamName" }; return *GetNativePointerField<FName*>(this, f); }
	UTexture2D* FPVHandsMeshTextureMaskField() { static NativeFieldOffset f{ "UPrimalItem.FPVHandsMeshTextureMask" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	int& FPVHandsMeshTextureMaskMaterialIndexField() { static NativeFieldOffset f{ "UPrimalItem.FPVHandsMeshTextureMaskMaterialIndex" }; return *GetNativePointerField<int*>(this, f); }
	int& FPVHandsMeshTextureMaskMaterialIndex2Field() { static NativeFieldOffset f{ "UPrimalItem.FPVHandsMeshTextureMaskMaterialIndex2" }; return *GetNativePointerField<int*>(this, f); }
	UPrimalItem* WeaponAmmoOverrideItemCDOField() { static NativeFieldOffset f{ "UPrimalItem.WeaponAmmoOverrideItemCDO" }; return *GetNativePointerField<UPrimalItem**>(this, f); }
	long double& CreationTimeField() { static NativeFieldOffset f{ "UPrimalItem.CreationTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastAutoDurabilityDecreaseTimeField() { static NativeFieldOffset f{ "UPrimalItem.LastAutoDurabilityDecreaseTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastUseTimeField() { static NativeFieldOffset f{ "UPrimalItem.LastUseTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastLocalUseTimeField() { static NativeFieldOffset f{ "UPrimalItem.LastLocalUseTime" }; return *GetNativePointerField<long double*>(this, f); }
	int& MaxCustomItemDescriptionLengthField() { static NativeFieldOffset f{ "UPrimalItem.MaxCustomItemDescriptionLength" }; return *GetNativePointerField<int*>(this, f); }
	int& TempSlotIndexField() { static NativeFieldOffset f{ "UPrimalItem.TempSlotIndex" }; return *GetNativePointerField<int*>(this, f); }
	TWeakObjectPtr<AShooterWeapon>& AssociatedWeaponField() { static NativeFieldOffset f{ "UPrimalItem.AssociatedWeapon" }; return *GetNativePointerField<TWeakObjectPtr<AShooterWeapon>*>(this, f); }
	UPrimalItem* MyItemSkinField() { static NativeFieldOffset f{ "UPrimalItem.MyItemSkin" }; return *GetNativePointerField<UPrimalItem**>(this, f); }
	TWeakObjectPtr<AShooterCharacter>& LastOwnerPlayerField() { static NativeFieldOffset f{ "UPrimalItem.LastOwnerPlayer" }; return *GetNativePointerField<TWeakObjectPtr<AShooterCharacter>*>(this, f); }
	TArray<FCropItemPhaseData>& CropPhasesDataField() { static NativeFieldOffset f{ "UPrimalItem.CropPhasesData" }; return *GetNativePointerField<TArray<FCropItemPhaseData>*>(this, f); }
	float& CropGrowingFertilizerConsumptionRateField() { static NativeFieldOffset f{ "UPrimalItem.CropGrowingFertilizerConsumptionRate" }; return *GetNativePointerField<float*>(this, f); }
	float& CropMaxFruitFertilizerConsumptionRateField() { static NativeFieldOffset f{ "UPrimalItem.CropMaxFruitFertilizerConsumptionRate" }; return *GetNativePointerField<float*>(this, f); }
	float& CropGrowingWaterConsumptionRateField() { static NativeFieldOffset f{ "UPrimalItem.CropGrowingWaterConsumptionRate" }; return *GetNativePointerField<float*>(this, f); }
	float& CropMaxFruitWaterConsumptionRateField() { static NativeFieldOffset f{ "UPrimalItem.CropMaxFruitWaterConsumptionRate" }; return *GetNativePointerField<float*>(this, f); }
	int& CropMaxFruitsField() { static NativeFieldOffset f{ "UPrimalItem.CropMaxFruits" }; return *GetNativePointerField<int*>(this, f); }
	float& CropNoFertilizerOrWaterCacheReductionRateField() { static NativeFieldOffset f{ "UPrimalItem.CropNoFertilizerOrWaterCacheReductionRate" }; return *GetNativePointerField<float*>(this, f); }
	float& FertilizerEffectivenessMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.FertilizerEffectivenessMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& EggAlertDinosAggroAmountField() { static NativeFieldOffset f{ "UPrimalItem.EggAlertDinosAggroAmount" }; return *GetNativePointerField<float*>(this, f); }
	float& EggAlertDinosAggroRadiusField() { static NativeFieldOffset f{ "UPrimalItem.EggAlertDinosAggroRadius" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FName>& EggAlertDinosAggroTagsField() { static NativeFieldOffset f{ "UPrimalItem.EggAlertDinosAggroTags" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	float& EggAlertDinosForcedAggroTimeField() { static NativeFieldOffset f{ "UPrimalItem.EggAlertDinosForcedAggroTime" }; return *GetNativePointerField<float*>(this, f); }
	float& EggMaximumDistanceFromOriginalDropToAlertDinosField() { static NativeFieldOffset f{ "UPrimalItem.EggMaximumDistanceFromOriginalDropToAlertDinos" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<UPrimalItem>& BrokenGiveItemClassField() { static NativeFieldOffset f{ "UPrimalItem.BrokenGiveItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& ClearColorDurabilityThresholdField() { static NativeFieldOffset f{ "UPrimalItem.ClearColorDurabilityThreshold" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<UPrimalItem>& ItemClassToUseAsInitialCustomDataField() { static NativeFieldOffset f{ "UPrimalItem.ItemClassToUseAsInitialCustomData" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	FVector& OriginalItemDropLocationField() { static NativeFieldOffset f{ "UPrimalItem.OriginalItemDropLocation" }; return *GetNativePointerField<FVector*>(this, f); }
	FLinearColor& DurabilityBarColorForegroundField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityBarColorForeground" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor& DurabilityBarColorBackgroundField() { static NativeFieldOffset f{ "UPrimalItem.DurabilityBarColorBackground" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	TSubclassOf<UPrimalItem>& OverrideCooldownTimeItemClassField() { static NativeFieldOffset f{ "UPrimalItem.OverrideCooldownTimeItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& MinDurabilityForCraftingResourceField() { static NativeFieldOffset f{ "UPrimalItem.MinDurabilityForCraftingResource" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourceRequirementIncreaseRatingPowerField() { static NativeFieldOffset f{ "UPrimalItem.ResourceRequirementIncreaseRatingPower" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourceRequirementRatingScaleField() { static NativeFieldOffset f{ "UPrimalItem.ResourceRequirementRatingScale" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourceRequirementRatingIncreasePercentageField() { static NativeFieldOffset f{ "UPrimalItem.ResourceRequirementRatingIncreasePercentage" }; return *GetNativePointerField<float*>(this, f); }
	long double& NextSpoilingTimeField() { static NativeFieldOffset f{ "UPrimalItem.NextSpoilingTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastSpoilingTimeField() { static NativeFieldOffset f{ "UPrimalItem.LastSpoilingTime" }; return *GetNativePointerField<long double*>(this, f); }
	TArray<FString>& DefaultFolderPathsField() { static NativeFieldOffset f{ "UPrimalItem.DefaultFolderPaths" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	FString& ItemRatingStringField() { static NativeFieldOffset f{ "UPrimalItem.ItemRatingString" }; return *GetNativePointerField<FString*>(this, f); }
	FName& DefaultWeaponMeshNameField() { static NativeFieldOffset f{ "UPrimalItem.DefaultWeaponMeshName" }; return *GetNativePointerField<FName*>(this, f); }
	int& LastCalculatedTotalAmmoInvUpdatedFrameField() { static NativeFieldOffset f{ "UPrimalItem.LastCalculatedTotalAmmoInvUpdatedFrame" }; return *GetNativePointerField<int*>(this, f); }
	int& WeaponTotalAmmoField() { static NativeFieldOffset f{ "UPrimalItem.WeaponTotalAmmo" }; return *GetNativePointerField<int*>(this, f); }
	TSubclassOf<UPrimalItem>& EngramRequirementItemClassOverrideField() { static NativeFieldOffset f{ "UPrimalItem.EngramRequirementItemClassOverride" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<unsigned short>& CraftingResourceRequirementsField() { static NativeFieldOffset f{ "UPrimalItem.CraftingResourceRequirements" }; return *GetNativePointerField<TArray<unsigned short>*>(this, f); }
	USoundBase* ExtraThrowItemSoundField() { static NativeFieldOffset f{ "UPrimalItem.ExtraThrowItemSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	FVector& SpawnOnWaterEncroachmentBoxExtentField() { static NativeFieldOffset f{ "UPrimalItem.SpawnOnWaterEncroachmentBoxExtent" }; return *GetNativePointerField<FVector*>(this, f); }
	TArray<TSubclassOf<AActor>>& OnlyUsableOnSpecificClassesField() { static NativeFieldOffset f{ "UPrimalItem.OnlyUsableOnSpecificClasses" }; return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, f); }
	TArray<FSaddlePassengerSeatDefinition>& SaddlePassengerSeatsField() { static NativeFieldOffset f{ "UPrimalItem.SaddlePassengerSeats" }; return *GetNativePointerField<TArray<FSaddlePassengerSeatDefinition>*>(this, f); }
	FName& SaddleOverrideRiderSocketNameField() { static NativeFieldOffset f{ "UPrimalItem.SaddleOverrideRiderSocketName" }; return *GetNativePointerField<FName*>(this, f); }
	TSubclassOf<APrimalDinoCharacter>& EggDinoClassToSpawnField() { static NativeFieldOffset f{ "UPrimalItem.EggDinoClassToSpawn" }; return *GetNativePointerField<TSubclassOf<APrimalDinoCharacter>*>(this, f); }
	FieldArray<unsigned char, 12> EggNumberOfLevelUpPointsAppliedField() { static NativeFieldOffset f{ "UPrimalItem.EggNumberOfLevelUpPointsApplied" }; return { this, f }; }
	float& EggTamedIneffectivenessModifierField() { static NativeFieldOffset f{ "UPrimalItem.EggTamedIneffectivenessModifier" }; return *GetNativePointerField<float*>(this, f); }
	FieldArray<unsigned char, 6> EggColorSetIndicesField() { static NativeFieldOffset f{ "UPrimalItem.EggColorSetIndices" }; return { this, f }; }
	float& EggLoseDurabilityPerSecondField() { static NativeFieldOffset f{ "UPrimalItem.EggLoseDurabilityPerSecond" }; return *GetNativePointerField<float*>(this, f); }
	float& ExtraEggLoseDurabilityPerSecondMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.ExtraEggLoseDurabilityPerSecondMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& EggMinTemperatureField() { static NativeFieldOffset f{ "UPrimalItem.EggMinTemperature" }; return *GetNativePointerField<float*>(this, f); }
	float& EggMaxTemperatureField() { static NativeFieldOffset f{ "UPrimalItem.EggMaxTemperature" }; return *GetNativePointerField<float*>(this, f); }
	float& EggDroppedInvalidTempLoseItemRatingSpeedField() { static NativeFieldOffset f{ "UPrimalItem.EggDroppedInvalidTempLoseItemRatingSpeed" }; return *GetNativePointerField<float*>(this, f); }
	USoundBase* ShieldHitSoundField() { static NativeFieldOffset f{ "UPrimalItem.ShieldHitSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	float& RecipeCraftingSkillScaleField() { static NativeFieldOffset f{ "UPrimalItem.RecipeCraftingSkillScale" }; return *GetNativePointerField<float*>(this, f); }
	int& CustomItemIDField() { static NativeFieldOffset f{ "UPrimalItem.CustomItemID" }; return *GetNativePointerField<int*>(this, f); }
	float& AddDinoTargetingRangeField() { static NativeFieldOffset f{ "UPrimalItem.AddDinoTargetingRange" }; return *GetNativePointerField<float*>(this, f); }
	float& DamageTorpidityArmorRatingField() { static NativeFieldOffset f{ "UPrimalItem.DamageTorpidityArmorRating" }; return *GetNativePointerField<float*>(this, f); }
	float& IndirectTorpidityArmorRatingField() { static NativeFieldOffset f{ "UPrimalItem.IndirectTorpidityArmorRating" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& UseParticleEffectField() { static NativeFieldOffset f{ "UPrimalItem.UseParticleEffect" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	FName& UseParticleEffectSocketNameField() { static NativeFieldOffset f{ "UPrimalItem.UseParticleEffectSocketName" }; return *GetNativePointerField<FName*>(this, f); }
	float& UseGiveDinoTameAffinityPercentField() { static NativeFieldOffset f{ "UPrimalItem.UseGiveDinoTameAffinityPercent" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& CraftingAdditionalItemsToGiveField() { static NativeFieldOffset f{ "UPrimalItem.CraftingAdditionalItemsToGive" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	int& LastValidItemVersionField() { static NativeFieldOffset f{ "UPrimalItem.LastValidItemVersion" }; return *GetNativePointerField<int*>(this, f); }
	float& GlobalTameAffinityMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.GlobalTameAffinityMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	int& CraftingGiveItemCountField() { static NativeFieldOffset f{ "UPrimalItem.CraftingGiveItemCount" }; return *GetNativePointerField<int*>(this, f); }
	int& CraftingGivesItemQuantityOverrideField() { static NativeFieldOffset f{ "UPrimalItem.CraftingGivesItemQuantityOverride" }; return *GetNativePointerField<int*>(this, f); }
	USoundBase* UseItemOnItemSoundField() { static NativeFieldOffset f{ "UPrimalItem.UseItemOnItemSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	FName& UseUnlocksEmoteNameField() { static NativeFieldOffset f{ "UPrimalItem.UseUnlocksEmoteName" }; return *GetNativePointerField<FName*>(this, f); }
	long double& ClusterSpoilingTimeUTCField() { static NativeFieldOffset f{ "UPrimalItem.ClusterSpoilingTimeUTC" }; return *GetNativePointerField<long double*>(this, f); }
	TArray<FDinoAncestorsEntry>& EggDinoAncestorsField() { static NativeFieldOffset f{ "UPrimalItem.EggDinoAncestors" }; return *GetNativePointerField<TArray<FDinoAncestorsEntry>*>(this, f); }
	TArray<FDinoAncestorsEntry>& EggDinoAncestorsMaleField() { static NativeFieldOffset f{ "UPrimalItem.EggDinoAncestorsMale" }; return *GetNativePointerField<TArray<FDinoAncestorsEntry>*>(this, f); }
	int& EggRandomMutationsFemaleField() { static NativeFieldOffset f{ "UPrimalItem.EggRandomMutationsFemale" }; return *GetNativePointerField<int*>(this, f); }
	int& EggRandomMutationsMaleField() { static NativeFieldOffset f{ "UPrimalItem.EggRandomMutationsMale" }; return *GetNativePointerField<int*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& EquippingRequiresEngramsField() { static NativeFieldOffset f{ "UPrimalItem.EquippingRequiresEngrams" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<FCustomItemData>& CustomItemDatasField() { static NativeFieldOffset f{ "UPrimalItem.CustomItemDatas" }; return *GetNativePointerField<TArray<FCustomItemData>*>(this, f); }
	FString& OverrideUseStringField() { static NativeFieldOffset f{ "UPrimalItem.OverrideUseString" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<UPrimalItem>& SendToClientClassOverrideField() { static NativeFieldOffset f{ "UPrimalItem.SendToClientClassOverride" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	FString& CrafterCharacterNameField() { static NativeFieldOffset f{ "UPrimalItem.CrafterCharacterName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CrafterTribeNameField() { static NativeFieldOffset f{ "UPrimalItem.CrafterTribeName" }; return *GetNativePointerField<FString*>(this, f); }
	float& CraftedSkillBonusField() { static NativeFieldOffset f{ "UPrimalItem.CraftedSkillBonus" }; return *GetNativePointerField<float*>(this, f); }
	float& CraftingSkillQualityMultiplierMinField() { static NativeFieldOffset f{ "UPrimalItem.CraftingSkillQualityMultiplierMin" }; return *GetNativePointerField<float*>(this, f); }
	float& CraftingSkillQualityMultiplierMaxField() { static NativeFieldOffset f{ "UPrimalItem.CraftingSkillQualityMultiplierMax" }; return *GetNativePointerField<float*>(this, f); }
	float& SinglePlayerCraftingSpeedMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.SinglePlayerCraftingSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	int& NoLevelEngramSortingPriorityField() { static NativeFieldOffset f{ "UPrimalItem.NoLevelEngramSortingPriority" }; return *GetNativePointerField<int*>(this, f); }
	int& CustomFlagsField() { static NativeFieldOffset f{ "UPrimalItem.CustomFlags" }; return *GetNativePointerField<int*>(this, f); }
	FName& CustomTagField() { static NativeFieldOffset f{ "UPrimalItem.CustomTag" }; return *GetNativePointerField<FName*>(this, f); }
	float& EquippedReduceDurabilityIntervalField() { static NativeFieldOffset f{ "UPrimalItem.EquippedReduceDurabilityInterval" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastEquippedReduceDurabilityTimeField() { static NativeFieldOffset f{ "UPrimalItem.LastEquippedReduceDurabilityTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& EquippedReduceDurabilityPerIntervalField() { static NativeFieldOffset f{ "UPrimalItem.EquippedReduceDurabilityPerInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& ItemStatClampsMultiplierField() { static NativeFieldOffset f{ "UPrimalItem.ItemStatClampsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxDurabiltiyOverrideField() { static NativeFieldOffset f{ "UPrimalItem.MaxDurabiltiyOverride" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastItemAdditionTimeField() { static NativeFieldOffset f{ "UPrimalItem.LastItemAdditionTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& UploadEarliestValidTimeField() { static NativeFieldOffset f{ "UPrimalItem.UploadEarliestValidTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& NextRepairPercentageField() { static NativeFieldOffset f{ "UPrimalItem.NextRepairPercentage" }; return *GetNativePointerField<float*>(this, f); }
	UStaticMesh* NetDroppedMeshOverrideField() { static NativeFieldOffset f{ "UPrimalItem.NetDroppedMeshOverride" }; return *GetNativePointerField<UStaticMesh**>(this, f); }
	UMaterialInterface* NetDroppedMeshMaterialOverrideField() { static NativeFieldOffset f{ "UPrimalItem.NetDroppedMeshMaterialOverride" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	FVector& NetDroppedMeshOverrideScale3DField() { static NativeFieldOffset f{ "UPrimalItem.NetDroppedMeshOverrideScale3D" }; return *GetNativePointerField<FVector*>(this, f); }
	UStaticMesh* DyePreviewMeshOverrideSMField() { static NativeFieldOffset f{ "UPrimalItem.DyePreviewMeshOverrideSM" }; return *GetNativePointerField<UStaticMesh**>(this, f); }
	UTexture2D* AccessoryActivatedIconOverrideField() { static NativeFieldOffset f{ "UPrimalItem.AccessoryActivatedIconOverride" }; return *GetNativePointerField<UTexture2D**>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bCanBuildStructures() { static NativeBitField f{ "UPrimalItem.bCanBuildStructures" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowEquppingItem() { static NativeBitField f{ "UPrimalItem.bAllowEquppingItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventEquipOnTaxidermyBase() { static NativeBitField f{ "UPrimalItem.bPreventEquipOnTaxidermyBase" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowInventoryItem() { static NativeBitField f{ "UPrimalItem.bAllowInventoryItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsRepairing() { static NativeBitField f{ "UPrimalItem.bIsRepairing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquippedItem() { static NativeBitField f{ "UPrimalItem.bEquippedItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanSlot() { static NativeBitField f{ "UPrimalItem.bCanSlot" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseItemColors() { static NativeBitField f{ "UPrimalItem.bUseItemColors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInitItemColors() { static NativeBitField f{ "UPrimalItem.bUseBPInitItemColors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRefreshOnDyeUsed() { static NativeBitField f{ "UPrimalItem.bRefreshOnDyeUsed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPostAddBuffToGiveOwnerCharacter() { static NativeBitField f{ "UPrimalItem.bUseBPPostAddBuffToGiveOwnerCharacter" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceDediAttachments() { static NativeBitField f{ "UPrimalItem.bForceDediAttachments" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowCustomColors() { static NativeBitField f{ "UPrimalItem.bAllowCustomColors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowRemovalWhenDead() { static NativeBitField f{ "UPrimalItem.bForceAllowRemovalWhenDead" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoCraftBlueprint() { static NativeBitField f{ "UPrimalItem.bAutoCraftBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideFromInventoryDisplay() { static NativeBitField f{ "UPrimalItem.bHideFromInventoryDisplay" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseItemStats() { static NativeBitField f{ "UPrimalItem.bUseItemStats" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSpawnActorWhenRiding() { static NativeBitField f{ "UPrimalItem.bUseSpawnActorWhenRiding" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSpawnActor() { static NativeBitField f{ "UPrimalItem.bUseSpawnActor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowDefaultCharacterAttachment() { static NativeBitField f{ "UPrimalItem.bAllowDefaultCharacterAttachment" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseItemDurability() { static NativeBitField f{ "UPrimalItem.bUseItemDurability" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNewWeaponAutoFillClipAmmo() { static NativeBitField f{ "UPrimalItem.bNewWeaponAutoFillClipAmmo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyBrokenItem() { static NativeBitField f{ "UPrimalItem.bDestroyBrokenItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bThrowOnHotKeyUse() { static NativeBitField f{ "UPrimalItem.bThrowOnHotKeyUse" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsBlueprint() { static NativeBitField f{ "UPrimalItem.bIsBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanBeBlueprint() { static NativeBitField f{ "UPrimalItem.bCanBeBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUpload() { static NativeBitField f{ "UPrimalItem.bPreventUpload" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsEngram() { static NativeBitField f{ "UPrimalItem.bIsEngram" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsCustomRecipe() { static NativeBitField f{ "UPrimalItem.bIsCustomRecipe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFoodRecipe() { static NativeBitField f{ "UPrimalItem.bIsFoodRecipe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTekItem() { static NativeBitField f{ "UPrimalItem.bTekItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowUseInInventory() { static NativeBitField f{ "UPrimalItem.bAllowUseInInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemoteUseInInventory() { static NativeBitField f{ "UPrimalItem.bAllowRemoteUseInInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBlueprintEquippedNotifications() { static NativeBitField f{ "UPrimalItem.bUseBlueprintEquippedNotifications" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseInWaterRestoreDurability() { static NativeBitField f{ "UPrimalItem.bUseInWaterRestoreDurability" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bValidCraftingResource() { static NativeBitField f{ "UPrimalItem.bValidCraftingResource" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPSetupHUDIconMaterial() { static NativeBitField f{ "UPrimalItem.bUseBPSetupHUDIconMaterial" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipRequiresDLC_ScorchedEarth() { static NativeBitField f{ "UPrimalItem.bEquipRequiresDLC_ScorchedEarth" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipRequiresDLC_Aberration() { static NativeBitField f{ "UPrimalItem.bEquipRequiresDLC_Aberration" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipRequiresDLC_Extinction() { static NativeBitField f{ "UPrimalItem.bEquipRequiresDLC_Extinction" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipRequiresDLC_Genesis() { static NativeBitField f{ "UPrimalItem.bEquipRequiresDLC_Genesis" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDurabilityRequirementIgnoredInWater() { static NativeBitField f{ "UPrimalItem.bDurabilityRequirementIgnoredInWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRepair() { static NativeBitField f{ "UPrimalItem.bAllowRepair" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCustomBrokenIcon() { static NativeBitField f{ "UPrimalItem.bCustomBrokenIcon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemovalFromInventory() { static NativeBitField f{ "UPrimalItem.bAllowRemovalFromInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bFromSteamInventory() { static NativeBitField f{ "UPrimalItem.bFromSteamInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFromAllClustersInventory() { static NativeBitField f{ "UPrimalItem.bIsFromAllClustersInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bConsumeItemOnUse() { static NativeBitField f{ "UPrimalItem.bConsumeItemOnUse" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bConfirmBeforeUsing() { static NativeBitField f{ "UPrimalItem.bConfirmBeforeUsing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyCanUseInWater() { static NativeBitField f{ "UPrimalItem.bOnlyCanUseInWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanUseSwimming() { static NativeBitField f{ "UPrimalItem.bCanUseSwimming" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsDescriptionOnlyItem() { static NativeBitField f{ "UPrimalItem.bIsDescriptionOnlyItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRestoreDurabilityWhenColorized() { static NativeBitField f{ "UPrimalItem.bRestoreDurabilityWhenColorized" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAppendPrimaryColorToName() { static NativeBitField f{ "UPrimalItem.bAppendPrimaryColorToName" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseScaleStatEffectivenessByDurability() { static NativeBitField f{ "UPrimalItem.bUseScaleStatEffectivenessByDurability" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsesCreationTime() { static NativeBitField f{ "UPrimalItem.bUsesCreationTime" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowUseWhileRiding() { static NativeBitField f{ "UPrimalItem.bAllowUseWhileRiding" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventCraftingResourceAtFullDurability() { static NativeBitField f{ "UPrimalItem.bPreventCraftingResourceAtFullDurability" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bGiveItemWhenUsedCopyItemStats() { static NativeBitField f{ "UPrimalItem.bGiveItemWhenUsedCopyItemStats" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideFromRemoteInventoryDisplay() { static NativeBitField f{ "UPrimalItem.bHideFromRemoteInventoryDisplay" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoDecreaseDurabilityOverTime() { static NativeBitField f{ "UPrimalItem.bAutoDecreaseDurabilityOverTime" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventDragOntoOtherItemIfSameCustomData() { static NativeBitField f{ "UPrimalItem.bPreventDragOntoOtherItemIfSameCustomData" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseOnItemWeaponRemoveClipAmmo() { static NativeBitField f{ "UPrimalItem.bUseOnItemWeaponRemoveClipAmmo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseOnItemSetIndexAsDestinationItemCustomData() { static NativeBitField f{ "UPrimalItem.bUseOnItemSetIndexAsDestinationItemCustomData" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupportDragOntoOtherItem() { static NativeBitField f{ "UPrimalItem.bSupportDragOntoOtherItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsItemSkin() { static NativeBitField f{ "UPrimalItem.bIsItemSkin" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDontResetAttachmentIfNotUpdatingItem() { static NativeBitField f{ "UPrimalItem.bDontResetAttachmentIfNotUpdatingItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinIgnoreSkinIcon() { static NativeBitField f{ "UPrimalItem.bItemSkinIgnoreSkinIcon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPickupEggAlertsDinos() { static NativeBitField f{ "UPrimalItem.bPickupEggAlertsDinos" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideCustomDescription() { static NativeBitField f{ "UPrimalItem.bHideCustomDescription" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCopyCustomDescriptionIntoSpoiledItem() { static NativeBitField f{ "UPrimalItem.bCopyCustomDescriptionIntoSpoiledItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCopyDurabilityIntoSpoiledItem() { static NativeBitField f{ "UPrimalItem.bCopyDurabilityIntoSpoiledItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCraftedRequestCustomItemDescription() { static NativeBitField f{ "UPrimalItem.bCraftedRequestCustomItemDescription" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowCustomItemDescription() { static NativeBitField f{ "UPrimalItem.bForceAllowCustomItemDescription" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInitializedItem() { static NativeBitField f{ "UPrimalItem.bInitializedItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsDroppedItem() { static NativeBitField f{ "UPrimalItem.bIsDroppedItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEggIsTooCold() { static NativeBitField f{ "UPrimalItem.bEggIsTooCold" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEggIsTooHot() { static NativeBitField f{ "UPrimalItem.bEggIsTooHot" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventUseOntoItem() { static NativeBitField f{ "UPrimalItem.bUseBPPreventUseOntoItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSkinDisableWhenSubmerged() { static NativeBitField f{ "UPrimalItem.bSkinDisableWhenSubmerged" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsAbstractItem() { static NativeBitField f{ "UPrimalItem.bIsAbstractItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventItemSkins() { static NativeBitField f{ "UPrimalItem.bPreventItemSkins" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyCanUseInFalling() { static NativeBitField f{ "UPrimalItem.bOnlyCanUseInFalling" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceDropDestruction() { static NativeBitField f{ "UPrimalItem.bForceDropDestruction" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanBeArkTributeItem() { static NativeBitField f{ "UPrimalItem.bCanBeArkTributeItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowInvalidItemVersion() { static NativeBitField f{ "UPrimalItem.bAllowInvalidItemVersion" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSpawnActorRelativeLoc() { static NativeBitField f{ "UPrimalItem.bUseSpawnActorRelativeLoc" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSpawnActorTakeOwnerRotation() { static NativeBitField f{ "UPrimalItem.bUseSpawnActorTakeOwnerRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseEquippedItemBlueprintTick() { static NativeBitField f{ "UPrimalItem.bUseEquippedItemBlueprintTick" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseEquippedItemNativeTick() { static NativeBitField f{ "UPrimalItem.bUseEquippedItemNativeTick" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSpawnActorOnWaterOnly() { static NativeBitField f{ "UPrimalItem.bSpawnActorOnWaterOnly" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoTameSpawnedActor() { static NativeBitField f{ "UPrimalItem.bAutoTameSpawnedActor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bShowItemRatingAsPercent() { static NativeBitField f{ "UPrimalItem.bShowItemRatingAsPercent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventArmorDurabiltyConsumption() { static NativeBitField f{ "UPrimalItem.bPreventArmorDurabiltyConsumption" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsEgg() { static NativeBitField f{ "UPrimalItem.bIsEgg" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsCookingIngredient() { static NativeBitField f{ "UPrimalItem.bIsCookingIngredient" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDragClearDyedItem() { static NativeBitField f{ "UPrimalItem.bDragClearDyedItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDeprecateItem() { static NativeBitField f{ "UPrimalItem.bDeprecateItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInitializedRecipeStats() { static NativeBitField f{ "UPrimalItem.bInitializedRecipeStats" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinKeepOriginalWeaponTemplate() { static NativeBitField f{ "UPrimalItem.bItemSkinKeepOriginalWeaponTemplate" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinKeepOriginalIcon() { static NativeBitField f{ "UPrimalItem.bItemSkinKeepOriginalIcon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinReceiveOwnerEquippedBlueprintEvents() { static NativeBitField f{ "UPrimalItem.bItemSkinReceiveOwnerEquippedBlueprintEvents" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinReceiveOwnerEquippedBlueprintTick() { static NativeBitField f{ "UPrimalItem.bItemSkinReceiveOwnerEquippedBlueprintTick" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinAllowEquipping() { static NativeBitField f{ "UPrimalItem.bItemSkinAllowEquipping" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceDisplayInInventory() { static NativeBitField f{ "UPrimalItem.bForceDisplayInInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDroppedItemAllowDinoPickup() { static NativeBitField f{ "UPrimalItem.bDroppedItemAllowDinoPickup" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCraftDontActuallyGiveItem() { static NativeBitField f{ "UPrimalItem.bCraftDontActuallyGiveItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUseWhenSleeping() { static NativeBitField f{ "UPrimalItem.bPreventUseWhenSleeping" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOverrideRepairingRequirements() { static NativeBitField f{ "UPrimalItem.bOverrideRepairingRequirements" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bScaleOverridenRepairingRequirements() { static NativeBitField f{ "UPrimalItem.bScaleOverridenRepairingRequirements" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceUseItemAddCharacterStatsOnDinos() { static NativeBitField f{ "UPrimalItem.bForceUseItemAddCharacterStatsOnDinos" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyEquipWhenUnconscious() { static NativeBitField f{ "UPrimalItem.bOnlyEquipWhenUnconscious" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventConsumableWhileHandcuffed() { static NativeBitField f{ "UPrimalItem.bForcePreventConsumableWhileHandcuffed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOverrideExactClassCraftingRequirement() { static NativeBitField f{ "UPrimalItem.bOverrideExactClassCraftingRequirement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventConsumeItemOnDrag() { static NativeBitField f{ "UPrimalItem.bPreventConsumeItemOnDrag" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowGrinding() { static NativeBitField f{ "UPrimalItem.bForceAllowGrinding" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventGrinding() { static NativeBitField f{ "UPrimalItem.bForcePreventGrinding" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDeprecateBlueprint() { static NativeBitField f{ "UPrimalItem.bDeprecateBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventDinoAutoConsume() { static NativeBitField f{ "UPrimalItem.bPreventDinoAutoConsume" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsDinoAutoHealingItem() { static NativeBitField f{ "UPrimalItem.bIsDinoAutoHealingItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPAllowRemoteAddToInventory() { static NativeBitField f{ "UPrimalItem.bBPAllowRemoteAddToInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPAllowRemoteRemoveFromInventory() { static NativeBitField f{ "UPrimalItem.bBPAllowRemoteRemoveFromInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipmentHatHideItemHeadHair() { static NativeBitField f{ "UPrimalItem.bEquipmentHatHideItemHeadHair" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipmentHatHideItemFacialHair() { static NativeBitField f{ "UPrimalItem.bEquipmentHatHideItemFacialHair" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEquipmentForceHairHiding() { static NativeBitField f{ "UPrimalItem.bEquipmentForceHairHiding" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemoveFromSteamInventory() { static NativeBitField f{ "UPrimalItem.bAllowRemoveFromSteamInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPInventoryNotifyCraftingFinished() { static NativeBitField f{ "UPrimalItem.bBPInventoryNotifyCraftingFinished" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCheckBPAllowCrafting() { static NativeBitField f{ "UPrimalItem.bCheckBPAllowCrafting" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAllowAddToInventory() { static NativeBitField f{ "UPrimalItem.bUseBPAllowAddToInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventItemBlueprint() { static NativeBitField f{ "UPrimalItem.bPreventItemBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUseByDinos() { static NativeBitField f{ "UPrimalItem.bPreventUseByDinos" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUseByHumans() { static NativeBitField f{ "UPrimalItem.bPreventUseByHumans" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPCanUse() { static NativeBitField f{ "UPrimalItem.bBPCanUse" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowOverrideItemAutoDecreaseDurability() { static NativeBitField f{ "UPrimalItem.bAllowOverrideItemAutoDecreaseDurability" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCopyItemDurabilityFromCraftingResource() { static NativeBitField f{ "UPrimalItem.bCopyItemDurabilityFromCraftingResource" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsInitialItem() { static NativeBitField f{ "UPrimalItem.bIsInitialItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPickupEggForceAggro() { static NativeBitField f{ "UPrimalItem.bPickupEggForceAggro" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bClearSkinOnInventoryRemoval() { static NativeBitField f{ "UPrimalItem.bClearSkinOnInventoryRemoval" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCustomAutoDecreaseDurabilityPerInterval() { static NativeBitField f{ "UPrimalItem.bUseBPCustomAutoDecreaseDurabilityPerInterval" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCustomInventoryWidgetText() { static NativeBitField f{ "UPrimalItem.bUseBPCustomInventoryWidgetText" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCustomInventoryWidgetTextColor() { static NativeBitField f{ "UPrimalItem.bUseBPCustomInventoryWidgetTextColor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCustomInventoryWidgetTextForBlueprint() { static NativeBitField f{ "UPrimalItem.bUseBPCustomInventoryWidgetTextForBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSkinnedBPCustomInventoryWidgetText() { static NativeBitField f{ "UPrimalItem.bUseSkinnedBPCustomInventoryWidgetText" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCustomDurabilityText() { static NativeBitField f{ "UPrimalItem.bUseBPCustomDurabilityText" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCustomDurabilityTextColor() { static NativeBitField f{ "UPrimalItem.bUseBPCustomDurabilityTextColor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInitFromItemNetInfo() { static NativeBitField f{ "UPrimalItem.bUseBPInitFromItemNetInfo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInitializeItem() { static NativeBitField f{ "UPrimalItem.bUseBPInitializeItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetItemNetInfo() { static NativeBitField f{ "UPrimalItem.bUseBPGetItemNetInfo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bItemSkinKeepOriginalItemName() { static NativeBitField f{ "UPrimalItem.bItemSkinKeepOriginalItemName" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUploadingWeaponClipAmmo() { static NativeBitField f{ "UPrimalItem.bPreventUploadingWeaponClipAmmo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventNativeItemBroken() { static NativeBitField f{ "UPrimalItem.bPreventNativeItemBroken" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bResourcePreventGivingFromDemolition() { static NativeBitField f{ "UPrimalItem.bResourcePreventGivingFromDemolition" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNameForceNoStatQualityRank() { static NativeBitField f{ "UPrimalItem.bNameForceNoStatQualityRank" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysLearnedEngram() { static NativeBitField f{ "UPrimalItem.bAlwaysLearnedEngram" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreMinimumUseIntervalForDinoAutoEatingFood() { static NativeBitField f{ "UPrimalItem.bIgnoreMinimumUseIntervalForDinoAutoEatingFood" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUnappliedItemSkinIgnoreItemAttachments() { static NativeBitField f{ "UPrimalItem.bUnappliedItemSkinIgnoreItemAttachments" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideMoreOptionsIfNonRemovable() { static NativeBitField f{ "UPrimalItem.bHideMoreOptionsIfNonRemovable" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetItemDescription() { static NativeBitField f{ "UPrimalItem.bUseBPGetItemDescription" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCrafted() { static NativeBitField f{ "UPrimalItem.bUseBPCrafted" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetItemName() { static NativeBitField f{ "UPrimalItem.bUseBPGetItemName" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventUseAtTameLimit() { static NativeBitField f{ "UPrimalItem.bPreventUseAtTameLimit" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDivideTimeToCraftByGlobalCropGrowthSpeed() { static NativeBitField f{ "UPrimalItem.bDivideTimeToCraftByGlobalCropGrowthSpeed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventCheatGive() { static NativeBitField f{ "UPrimalItem.bPreventCheatGive" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsingRequiresStandingOnSolidGround() { static NativeBitField f{ "UPrimalItem.bUsingRequiresStandingOnSolidGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAddedAttachments() { static NativeBitField f{ "UPrimalItem.bUseBPAddedAttachments" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPConsumeProjectileImpact() { static NativeBitField f{ "UPrimalItem.bUseBPConsumeProjectileImpact" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideProjectileType() { static NativeBitField f{ "UPrimalItem.bUseBPOverrideProjectileType" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsableWithTekGrenadeLauncher() { static NativeBitField f{ "UPrimalItem.bUsableWithTekGrenadeLauncher" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyDropped() { static NativeBitField f{ "UPrimalItem.bUseBPNotifyDropped" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bThrowUsesSecondaryActionDrop() { static NativeBitField f{ "UPrimalItem.bThrowUsesSecondaryActionDrop" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetItemIcon() { static NativeBitField f{ "UPrimalItem.bUseBPGetItemIcon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSlottedTick() { static NativeBitField f{ "UPrimalItem.bUseSlottedTick" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPDrawItemIcon() { static NativeBitField f{ "UPrimalItem.bUseBPDrawItemIcon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPForceAllowRemoteAddToInventory() { static NativeBitField f{ "UPrimalItem.bUseBPForceAllowRemoteAddToInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSkinAddWeightToSkinnedItem() { static NativeBitField f{ "UPrimalItem.bSkinAddWeightToSkinnedItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPIsValidForCrafting() { static NativeBitField f{ "UPrimalItem.bUseBPIsValidForCrafting" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideCraftingConsumption() { static NativeBitField f{ "UPrimalItem.bUseBPOverrideCraftingConsumption" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreDrawingItemButtonIcon() { static NativeBitField f{ "UPrimalItem.bIgnoreDrawingItemButtonIcon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCensoredItemSkin() { static NativeBitField f{ "UPrimalItem.bCensoredItemSkin" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetItemDurabilityPercentage() { static NativeBitField f{ "UPrimalItem.bUseBPGetItemDurabilityPercentage" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPEquippedItemOnXPEarning() { static NativeBitField f{ "UPrimalItem.bUseBPEquippedItemOnXPEarning" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysTriggerTributeDownloaded() { static NativeBitField f{ "UPrimalItem.bAlwaysTriggerTributeDownloaded" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDeferWeaponBeginPlayToAssociatedItemSetTime() { static NativeBitField f{ "UPrimalItem.bDeferWeaponBeginPlayToAssociatedItemSetTime" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsSPlusItem() { static NativeBitField f{ "UPrimalItem.bIsSPlusItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventRemovingClipAmmo() { static NativeBitField f{ "UPrimalItem.bPreventRemovingClipAmmo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNonBlockingShield() { static NativeBitField f{ "UPrimalItem.bNonBlockingShield" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNetInfoFromClient() { static NativeBitField f{ "UPrimalItem.bNetInfoFromClient" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAddedToWorldItemMap() { static NativeBitField f{ "UPrimalItem.bAddedToWorldItemMap" }; return { this, f }; }

	// Functions

	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "UPrimalItem.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalItem.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	FItemNetInfo* GetItemNetInfo(FItemNetInfo* result, bool bIsForSendingToClient) { static NativeFunction f{ "UPrimalItem.GetItemNetInfo" }; return NativeCall<FItemNetInfo*, FItemNetInfo*, bool>(this, f, result, bIsForSendingToClient); }
	void InitFromNetInfo(FItemNetInfo* theInfo) { static NativeFunction f{ "UPrimalItem.InitFromNetInfo" }; NativeCall<void, FItemNetInfo*>(this, f, theInfo); }
	UWorld* GetWorldHelper(UObject* WorldContextObject) { static NativeFunction f{ "UPrimalItem.GetWorldHelper" }; return NativeCall<UWorld*, UObject*>(this, f, WorldContextObject); }
	int GetMaxItemQuantity(UObject* WorldContextObject) { static NativeFunction f{ "UPrimalItem.GetMaxItemQuantity" }; return NativeCall<int, UObject*>(this, f, WorldContextObject); }
	void AddItemDurability(float durabilityToAdd) { static NativeFunction f{ "UPrimalItem.AddItemDurability" }; NativeCall<void, float>(this, f, durabilityToAdd); }
	void InitNewItem(float ItemQuality, UPrimalInventoryComponent* toInventory, float MaxItemDifficultyClamp, float MinRandomQuality) { static NativeFunction f{ "UPrimalItem.InitNewItem" }; NativeCall<void, float, UPrimalInventoryComponent*, float, float>(this, f, ItemQuality, toInventory, MaxItemDifficultyClamp, MinRandomQuality); }
	bool AllowEquipItem(UPrimalInventoryComponent* toInventory) { static NativeFunction f{ "UPrimalItem.AllowEquipItem" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, toInventory); }
	bool AllowInventoryItem(UPrimalInventoryComponent* toInventory) { static NativeFunction f{ "UPrimalItem.AllowInventoryItem" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, toInventory); }
	void CacheFolderPath() { static NativeFunction f{ "UPrimalItem.CacheFolderPath" }; NativeCall<void>(this, f); }
	void AddToInventory(UPrimalInventoryComponent* toInventory, bool bEquipItem, bool AddToSlotItems, FItemNetID* InventoryInsertAfterItemID, bool ShowHUDNotification, bool bDontRecalcSpoilingTime, bool bIgnoreAbsoluteMaxInventory, bool bForceAdd = false) { static NativeFunction f{ "UPrimalItem.AddToInventory" }; NativeCall<void, UPrimalInventoryComponent*, bool, bool, FItemNetID*, bool, bool, bool, bool>(this, f, toInventory, bEquipItem, AddToSlotItems, InventoryInsertAfterItemID, ShowHUDNotification, bDontRecalcSpoilingTime, bIgnoreAbsoluteMaxInventory, bForceAdd); }
	bool RemoveItemFromArkTributeInventory() { static NativeFunction f{ "UPrimalItem.RemoveItemFromArkTributeInventory" }; return NativeCall<bool>(this, f); }
	bool RemoveItemFromInventory(bool bForceRemoval, bool showHUDMessage) { static NativeFunction f{ "UPrimalItem.RemoveItemFromInventory" }; return NativeCall<bool, bool, bool>(this, f, bForceRemoval, showHUDMessage); }
	float GetSpoilingTime() { static NativeFunction f{ "UPrimalItem.GetSpoilingTime" }; return NativeCall<float>(this, f); }
	void GetItemBytes(TArray<unsigned char>* Bytes) { static NativeFunction f{ "UPrimalItem.GetItemBytes" }; NativeCall<void, TArray<unsigned char>*>(this, f, Bytes); }
	static UPrimalItem* CreateFromBytes(TArray<unsigned char>* Bytes) { static NativeFunction f{ "UPrimalItem.CreateFromBytes" }; return NativeCall<UPrimalItem*, TArray<unsigned char>*>(nullptr, f, Bytes); }
	static UPrimalItem* AddNewItem(TSubclassOf<UPrimalItem> ItemArchetype, UPrimalInventoryComponent* GiveToInventory, bool bEquipItem, bool bDontStack, float ItemQuality, bool bForceNoBlueprint, int quantityOverride, bool bForceBlueprint, float MaxItemDifficultyClamp, bool CreateOnClient, TSubclassOf<UPrimalItem> ApplyItemSkin, float MinRandomQuality, bool clampStats, bool bIgnoreAbsolueMaxInventory) { static NativeFunction f{ "UPrimalItem.AddNewItem" }; return NativeCall<UPrimalItem*, TSubclassOf<UPrimalItem>, UPrimalInventoryComponent*, bool, bool, float, bool, int, bool, float, bool, TSubclassOf<UPrimalItem>, float, bool, bool>(nullptr, f, ItemArchetype, GiveToInventory, bEquipItem, bDontStack, ItemQuality, bForceNoBlueprint, quantityOverride, bForceBlueprint, MaxItemDifficultyClamp, CreateOnClient, ApplyItemSkin, MinRandomQuality, clampStats, bIgnoreAbsolueMaxInventory); }
	static UPrimalItem* CreateItemFromNetInfo(FItemNetInfo* newItemInfo) { static NativeFunction f{ "UPrimalItem.CreateItemFromNetInfo" }; return NativeCall<UPrimalItem*, FItemNetInfo*>(nullptr, f, newItemInfo); }
	FString* GetItemName(FString* result, bool bIncludeQuantity, bool bShortName, AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.GetItemName" }; return NativeCall<FString*, FString*, bool, bool, AShooterPlayerController*>(this, f, result, bIncludeQuantity, bShortName, ForPC); }
	FLinearColor* GetItemQualityColor(FLinearColor* result) { static NativeFunction f{ "UPrimalItem.GetItemQualityColor" }; return NativeCall<FLinearColor*, FLinearColor*>(this, f, result); }
	FString* GetItemDescription(FString* result, bool bGetLongDescription, AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.GetItemDescription" }; return NativeCall<FString*, FString*, bool, AShooterPlayerController*>(this, f, result, bGetLongDescription, ForPC); }
	UTexture2D* GetItemIcon(AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.GetItemIcon" }; return NativeCall<UTexture2D*, AShooterPlayerController*>(this, f, ForPC); }
	void EquippedItem() { static NativeFunction f{ "UPrimalItem.EquippedItem" }; NativeCall<void>(this, f); }
	void UnequippedItem() { static NativeFunction f{ "UPrimalItem.UnequippedItem" }; NativeCall<void>(this, f); }
	void UpdatedItem(bool ResetUploadTime) { static NativeFunction f{ "UPrimalItem.UpdatedItem" }; NativeCall<void, bool>(this, f, ResetUploadTime); }
	FString* GetItemShortName(FString* result) { static NativeFunction f{ "UPrimalItem.GetItemShortName" }; return NativeCall<FString*, FString*>(this, f, result); }
	static bool StaticGetItemNameAndIcon(TSubclassOf<UPrimalItem> ItemType, FString* OutItemName, UTexture2D** OutItemIcon, bool bShortName, AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.StaticGetItemNameAndIcon" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, FString*, UTexture2D**, bool, AShooterPlayerController*>(nullptr, f, ItemType, OutItemName, OutItemIcon, bShortName, ForPC); }
	void RefreshAttachments(bool bRefreshDefaultAttachments, bool isShieldSpecificRefresh, bool bIsFromUpdateItem) { static NativeFunction f{ "UPrimalItem.RefreshAttachments" }; NativeCall<void, bool, bool, bool>(this, f, bRefreshDefaultAttachments, isShieldSpecificRefresh, bIsFromUpdateItem); }
	void ApplyColorsToMesh(UMeshComponent* mComp) { static NativeFunction f{ "UPrimalItem.ApplyColorsToMesh" }; NativeCall<void, UMeshComponent*>(this, f, mComp); }
	void SetOwnerNoSee(bool bNoSee, bool bForceHideFirstPerson) { static NativeFunction f{ "UPrimalItem.SetOwnerNoSee" }; NativeCall<void, bool, bool>(this, f, bNoSee, bForceHideFirstPerson); }
	void RemoveAttachments(AActor* UseOtherActor, bool bRefreshDefaultAttachments, bool isShieldSpecificRefresh) { static NativeFunction f{ "UPrimalItem.RemoveAttachments" }; NativeCall<void, AActor*, bool, bool>(this, f, UseOtherActor, bRefreshDefaultAttachments, isShieldSpecificRefresh); }
	int GetAttachedComponentsNum() { static NativeFunction f{ "UPrimalItem.GetAttachedComponentsNum" }; return NativeCall<int>(this, f); }
	UActorComponent* GetAttachedComponent(int attachmentIndex, AActor* UseOtherActor) { static NativeFunction f{ "UPrimalItem.GetAttachedComponent" }; return NativeCall<UActorComponent*, int, AActor*>(this, f, attachmentIndex, UseOtherActor); }
	UActorComponent* GetComponentToAttach(int attachmentIndex, AActor* UseOtherActor) { static NativeFunction f{ "UPrimalItem.GetComponentToAttach" }; return NativeCall<UActorComponent*, int, AActor*>(this, f, attachmentIndex, UseOtherActor); }
	AActor* GetOwnerActor() { static NativeFunction f{ "UPrimalItem.GetOwnerActor" }; return NativeCall<AActor*>(this, f); }
	AShooterCharacter* GetOwnerPlayer() { static NativeFunction f{ "UPrimalItem.GetOwnerPlayer" }; return NativeCall<AShooterCharacter*>(this, f); }
	UTexture2D* GetEntryIcon(UObject* AssociatedDataObject, bool bIsEnabled) { static NativeFunction f{ "UPrimalItem.GetEntryIcon" }; return NativeCall<UTexture2D*, UObject*, bool>(this, f, AssociatedDataObject, bIsEnabled); }
	FString* GetEntryString(FString* result) { static NativeFunction f{ "UPrimalItem.GetEntryString" }; return NativeCall<FString*, FString*>(this, f, result); }
	float GetItemWeight(bool bJustOneQuantity, bool bForceNotBlueprintWeight) { static NativeFunction f{ "UPrimalItem.GetItemWeight" }; return NativeCall<float, bool, bool>(this, f, bJustOneQuantity, bForceNotBlueprintWeight); }
	void AddToSlot(int theSlotIndex, bool bForce) { static NativeFunction f{ "UPrimalItem.AddToSlot" }; NativeCall<void, int, bool>(this, f, theSlotIndex, bForce); }
	void RemoveFromSlot(bool bForce) { static NativeFunction f{ "UPrimalItem.RemoveFromSlot" }; NativeCall<void, bool>(this, f, bForce); }
	bool AllowSlotting(UPrimalInventoryComponent* toInventory, bool bForce) { static NativeFunction f{ "UPrimalItem.AllowSlotting" }; return NativeCall<bool, UPrimalInventoryComponent*, bool>(this, f, toInventory, bForce); }
	bool IsBroken() { static NativeFunction f{ "UPrimalItem.IsBroken" }; return NativeCall<bool>(this, f); }
	int GetExplicitEntryIndexType(bool bGetBaseValue) { static NativeFunction f{ "UPrimalItem.GetExplicitEntryIndexType" }; return NativeCall<int, bool>(this, f, bGetBaseValue); }
	float GetUseItemAddCharacterStatusValue(EPrimalCharacterStatusValue::Type valueType) { static NativeFunction f{ "UPrimalItem.GetUseItemAddCharacterStatusValue" }; return NativeCall<float, EPrimalCharacterStatusValue::Type>(this, f, valueType); }
	void Use(bool bOverridePlayerInput) { static NativeFunction f{ "UPrimalItem.Use" }; NativeCall<void, bool>(this, f, bOverridePlayerInput); }
	float GetRemainingCooldownTime() { static NativeFunction f{ "UPrimalItem.GetRemainingCooldownTime" }; return NativeCall<float>(this, f); }
	bool CanSpawnOverWater(AActor* ownerActor, FTransform* SpawnTransform) { static NativeFunction f{ "UPrimalItem.CanSpawnOverWater" }; return NativeCall<bool, AActor*, FTransform*>(this, f, ownerActor, SpawnTransform); }
	bool IsCooldownReadyForUse() { static NativeFunction f{ "UPrimalItem.IsCooldownReadyForUse" }; return NativeCall<bool>(this, f); }
	FString* GetInventoryIconDisplayText_Implementation(FString* result) { static NativeFunction f{ "UPrimalItem.GetInventoryIconDisplayText_Implementation" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool CanUse(bool bIgnoreCooldown) { static NativeFunction f{ "UPrimalItem.CanUse" }; return NativeCall<bool, bool>(this, f, bIgnoreCooldown); }
	void LocalUse(AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.LocalUse" }; NativeCall<void, AShooterPlayerController*>(this, f, ForPC); }
	void UnequipWeapon(bool bDelayedUnequip) { static NativeFunction f{ "UPrimalItem.UnequipWeapon" }; NativeCall<void, bool>(this, f, bDelayedUnequip); }
	FString* GetEntryDescription(FString* result) { static NativeFunction f{ "UPrimalItem.GetEntryDescription" }; return NativeCall<FString*, FString*>(this, f, result); }
	void AddedToInventory() { static NativeFunction f{ "UPrimalItem.AddedToInventory" }; NativeCall<void>(this, f); }
	void InitializeItem(bool bForceReinit, UWorld* OptionalInitWorld) { static NativeFunction f{ "UPrimalItem.InitializeItem" }; NativeCall<void, bool, UWorld*>(this, f, bForceReinit, OptionalInitWorld); }
	void ClearItemIcon() { static NativeFunction f{ "UPrimalItem.ClearItemIcon" }; NativeCall<void>(this, f); }
	void InitItemIcon() { static NativeFunction f{ "UPrimalItem.InitItemIcon" }; NativeCall<void>(this, f); }
	void ApplyColorsFromStructure(APrimalStructure* theStructure) { static NativeFunction f{ "UPrimalItem.ApplyColorsFromStructure" }; NativeCall<void, APrimalStructure*>(this, f, theStructure); }
	void EquippedWeapon() { static NativeFunction f{ "UPrimalItem.EquippedWeapon" }; NativeCall<void>(this, f); }
	void UnequippedWeapon() { static NativeFunction f{ "UPrimalItem.UnequippedWeapon" }; NativeCall<void>(this, f); }
	unsigned __int16 calcResourceQuantityRequired(TSubclassOf<UPrimalItem> itemType, const float baseRequiredAmount, UPrimalInventoryComponent* inventory, bool isCrafting) { static NativeFunction f{ "UPrimalItem.calcResourceQuantityRequired" }; return NativeCall<unsigned __int16, TSubclassOf<UPrimalItem>, const float, UPrimalInventoryComponent*, bool>(this, f, itemType, baseRequiredAmount, inventory, isCrafting); }
	FLinearColor* GetColorForItemColorID(FLinearColor* result, int SetNum, int ID) { static NativeFunction f{ "UPrimalItem.GetColorForItemColorID" }; return NativeCall<FLinearColor*, FLinearColor*, int, int>(this, f, result, SetNum, ID); }
	static FLinearColor* StaticGetColorForItemColorID(FLinearColor* result, int ID) { static NativeFunction f{ "UPrimalItem.StaticGetColorForItemColorID" }; return NativeCall<FLinearColor*, FLinearColor*, int>(nullptr, f, result, ID); }
	static int StaticGetDinoColorSetIndexForItemColorID(int ID) { static NativeFunction f{ "UPrimalItem.StaticGetDinoColorSetIndexForItemColorID" }; return NativeCall<int, int>(nullptr, f, ID); }
	static int GetItemColorIDFromDyeItemID(int MasterItemListIndex) { static NativeFunction f{ "UPrimalItem.GetItemColorIDFromDyeItemID" }; return NativeCall<int, int>(nullptr, f, MasterItemListIndex); }
	UMaterialInterface* GetEntryIconMaterial(UObject* AssociatedDataObject, bool bIsEnabled) { static NativeFunction f{ "UPrimalItem.GetEntryIconMaterial" }; return NativeCall<UMaterialInterface*, UObject*, bool>(this, f, AssociatedDataObject, bIsEnabled); }
	int GetItemQuantity() { static NativeFunction f{ "UPrimalItem.GetItemQuantity" }; return NativeCall<int>(this, f); }
	float GetMiscInfoFontScale() { static NativeFunction f{ "UPrimalItem.GetMiscInfoFontScale" }; return NativeCall<float>(this, f); }
	FString* GetMiscInfoString(FString* result) { static NativeFunction f{ "UPrimalItem.GetMiscInfoString" }; return NativeCall<FString*, FString*>(this, f, result); }
	FItemStatInfo* GetItemStatInfo(FItemStatInfo* result, int idx) { static NativeFunction f{ "UPrimalItem.GetItemStatInfo" }; return NativeCall<FItemStatInfo*, FItemStatInfo*, int>(this, f, result, idx); }
	void SetItemStatInfo(int idx, FItemStatInfo* val) { static NativeFunction f{ "UPrimalItem.SetItemStatInfo" }; NativeCall<void, int, FItemStatInfo*>(this, f, idx, val); }
	float BPGetItemStatModifier(int idx, int ItemStatValue) { static NativeFunction f{ "UPrimalItem.BPGetItemStatModifier" }; return NativeCall<float, int, int>(this, f, idx, ItemStatValue); }
	int BPGetItemStatRandomValue(float QualityLevel, int idx) { static NativeFunction f{ "UPrimalItem.BPGetItemStatRandomValue" }; return NativeCall<int, float, int>(this, f, QualityLevel, idx); }
	int GetItemStatValues(int idx) { static NativeFunction f{ "UPrimalItem.GetItemStatValues" }; return NativeCall<int, int>(this, f, idx); }
	void SetItemStatValues(int idx, int val) { static NativeFunction f{ "UPrimalItem.SetItemStatValues" }; NativeCall<void, int, int>(this, f, idx, val); }
	TEnumAsByte<enum EPrimalEquipmentType::Type>* GetActualEquipmentType(TEnumAsByte<enum EPrimalEquipmentType::Type>* result, bool bGetBaseValue) { static NativeFunction f{ "UPrimalItem.GetActualEquipmentType" }; return NativeCall<TEnumAsByte<enum EPrimalEquipmentType::Type>*, TEnumAsByte<enum EPrimalEquipmentType::Type>*, bool>(this, f, result, bGetBaseValue); }
	UClass* GetBuffToGiveOwnerWhenEquipped(bool bForceResolveSoftRef) { static NativeFunction f{ "UPrimalItem.GetBuffToGiveOwnerWhenEquipped" }; return NativeCall<UClass*, bool>(this, f, bForceResolveSoftRef); }
	bool HasBuffToGiveOwnerWhenEquipped() { static NativeFunction f{ "UPrimalItem.HasBuffToGiveOwnerWhenEquipped" }; return NativeCall<bool>(this, f); }
	int IncrementItemQuantity(int amount, bool bReplicateToClient, bool bDontUpdateWeight, bool bIsFromUseConsumption, bool bIsArkTributeItem, bool bIsFromCraftingConsumption) { static NativeFunction f{ "UPrimalItem.IncrementItemQuantity" }; return NativeCall<int, int, bool, bool, bool, bool, bool>(this, f, amount, bReplicateToClient, bDontUpdateWeight, bIsFromUseConsumption, bIsArkTributeItem, bIsFromCraftingConsumption); }
	void OverrideItemRating(float rating) { static NativeFunction f{ "UPrimalItem.OverrideItemRating" }; NativeCall<void, float>(this, f, rating); }
	FString* GetItemTypeString(FString* result) { static NativeFunction f{ "UPrimalItem.GetItemTypeString" }; return NativeCall<FString*, FString*>(this, f, result); }
	FString* GetItemSubtypeString(FString* result) { static NativeFunction f{ "UPrimalItem.GetItemSubtypeString" }; return NativeCall<FString*, FString*>(this, f, result); }
	FString* GetItemStatsString(FString* result) { static NativeFunction f{ "UPrimalItem.GetItemStatsString" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool MeetBlueprintCraftingRequirements(UPrimalInventoryComponent* compareInventoryComp, int CraftAmountOverride, AShooterPlayerController* ForPlayer, bool bIsForCraftQueueAddition, bool bTestFullQueue) { static NativeFunction f{ "UPrimalItem.MeetBlueprintCraftingRequirements" }; return NativeCall<bool, UPrimalInventoryComponent*, int, AShooterPlayerController*, bool, bool>(this, f, compareInventoryComp, CraftAmountOverride, ForPlayer, bIsForCraftQueueAddition, bTestFullQueue); }
	bool TestMeetsCraftingRequirementsPercent(UPrimalInventoryComponent* invComp, float Percent) { static NativeFunction f{ "UPrimalItem.TestMeetsCraftingRequirementsPercent" }; return NativeCall<bool, UPrimalInventoryComponent*, float>(this, f, invComp, Percent); }
	void ConsumeCraftingRequirementsPercent(UPrimalInventoryComponent* invComp, float Percent) { static NativeFunction f{ "UPrimalItem.ConsumeCraftingRequirementsPercent" }; NativeCall<void, UPrimalInventoryComponent*, float>(this, f, invComp, Percent); }
	FString* GetCraftingRequirementsString(FString* result, UPrimalInventoryComponent* compareInventoryComp) { static NativeFunction f{ "UPrimalItem.GetCraftingRequirementsString" }; return NativeCall<FString*, FString*, UPrimalInventoryComponent*>(this, f, result, compareInventoryComp); }
	bool MeetRepairingRequirements(UPrimalInventoryComponent* compareInventoryComp, bool bIsForCraftQueueAddition) { static NativeFunction f{ "UPrimalItem.MeetRepairingRequirements" }; return NativeCall<bool, UPrimalInventoryComponent*, bool>(this, f, compareInventoryComp, bIsForCraftQueueAddition); }
	FString* GetRepairingRequirementsString(FString* result, UPrimalInventoryComponent* compareInventoryComp, bool bUseBaseRequeriments, float OverrideRepairPercent) { static NativeFunction f{ "UPrimalItem.GetRepairingRequirementsString" }; return NativeCall<FString*, FString*, UPrimalInventoryComponent*, bool, float>(this, f, result, compareInventoryComp, bUseBaseRequeriments, OverrideRepairPercent); }
	float GetItemStatModifier(EPrimalItemStat::Type statType) { static NativeFunction f{ "UPrimalItem.GetItemStatModifier" }; return NativeCall<float, EPrimalItemStat::Type>(this, f, statType); }
	FString* GetItemStatString(FString* result, EPrimalItemStat::Type statType) { static NativeFunction f{ "UPrimalItem.GetItemStatString" }; return NativeCall<FString*, FString*, EPrimalItemStat::Type>(this, f, result, statType); }
	bool UsesDurability() { static NativeFunction f{ "UPrimalItem.UsesDurability" }; return NativeCall<bool>(this, f); }
	bool CanRepair(bool bIgnoreInventoryRequirement) { static NativeFunction f{ "UPrimalItem.CanRepair" }; return NativeCall<bool, bool>(this, f, bIgnoreInventoryRequirement); }
	bool CanRepairInInventory(UPrimalInventoryComponent* invComp) { static NativeFunction f{ "UPrimalItem.CanRepairInInventory" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, invComp); }
	float GetDurabilityPercentage() { static NativeFunction f{ "UPrimalItem.GetDurabilityPercentage" }; return NativeCall<float>(this, f); }
	void CraftBlueprint(bool bConsumeResources) { static NativeFunction f{ "UPrimalItem.CraftBlueprint" }; NativeCall<void, bool>(this, f, bConsumeResources); }
	bool CanFullyCraft() { static NativeFunction f{ "UPrimalItem.CanFullyCraft" }; return NativeCall<bool>(this, f); }
	void StopCraftingRepairing(bool bCheckIfCraftingOrRepairing) { static NativeFunction f{ "UPrimalItem.StopCraftingRepairing" }; NativeCall<void, bool>(this, f, bCheckIfCraftingOrRepairing); }
	UPrimalItem* FinishCraftingBlueprint() { static NativeFunction f{ "UPrimalItem.FinishCraftingBlueprint" }; return NativeCall<UPrimalItem*>(this, f); }
	float GetTimeToCraftBlueprint() { static NativeFunction f{ "UPrimalItem.GetTimeToCraftBlueprint" }; return NativeCall<float>(this, f); }
	float GetTimeForFullRepair() { static NativeFunction f{ "UPrimalItem.GetTimeForFullRepair" }; return NativeCall<float>(this, f); }
	static void GenerateItemID(FItemNetID* TheItemID) { static NativeFunction f{ "UPrimalItem.GenerateItemID" }; NativeCall<void, FItemNetID*>(nullptr, f, TheItemID); }
	void TickCraftingItem(float DeltaTime, AShooterGameState* theGameState) { static NativeFunction f{ "UPrimalItem.TickCraftingItem" }; NativeCall<void, float, AShooterGameState*>(this, f, DeltaTime, theGameState); }
	float GetCraftingPercent() { static NativeFunction f{ "UPrimalItem.GetCraftingPercent" }; return NativeCall<float>(this, f); }
	float GetRepairingPercent() { static NativeFunction f{ "UPrimalItem.GetRepairingPercent" }; return NativeCall<float>(this, f); }
	void SetQuantity(int NewQuantity, bool ShowHUDNotification) { static NativeFunction f{ "UPrimalItem.SetQuantity" }; NativeCall<void, int, bool>(this, f, NewQuantity, ShowHUDNotification); }
	void RepairItem(bool bIgnoreInventoryRequirement, float UseNextRepairPercentage, float RepairSpeedMultiplier) { static NativeFunction f{ "UPrimalItem.RepairItem" }; NativeCall<void, bool, float, float>(this, f, bIgnoreInventoryRequirement, UseNextRepairPercentage, RepairSpeedMultiplier); }
	void FinishRepairing() { static NativeFunction f{ "UPrimalItem.FinishRepairing" }; NativeCall<void>(this, f); }
	void Used(UPrimalItem* DestinationItem, int AdditionalData) { static NativeFunction f{ "UPrimalItem.Used" }; NativeCall<void, UPrimalItem*, int>(this, f, DestinationItem, AdditionalData); }
	void RemoveWeaponAccessory() { static NativeFunction f{ "UPrimalItem.RemoveWeaponAccessory" }; NativeCall<void>(this, f); }
	void ServerRemoveItemSkin() { static NativeFunction f{ "UPrimalItem.ServerRemoveItemSkin" }; NativeCall<void>(this, f); }
	void ServerRemoveItemSkinOnly() { static NativeFunction f{ "UPrimalItem.ServerRemoveItemSkinOnly" }; NativeCall<void>(this, f); }
	void ServerRemoveWeaponAccessoryOnly() { static NativeFunction f{ "UPrimalItem.ServerRemoveWeaponAccessoryOnly" }; NativeCall<void>(this, f); }
	void RemoveClipAmmo(bool bDontUpdateItem) { static NativeFunction f{ "UPrimalItem.RemoveClipAmmo" }; NativeCall<void, bool>(this, f, bDontUpdateItem); }
	bool CanStackWithItem(UPrimalItem* otherItem, int* QuantityOverride) { static NativeFunction f{ "UPrimalItem.CanStackWithItem" }; return NativeCall<bool, UPrimalItem*, int*>(this, f, otherItem, QuantityOverride); }
	bool CheckAutoCraftBlueprint() { static NativeFunction f{ "UPrimalItem.CheckAutoCraftBlueprint" }; return NativeCall<bool>(this, f); }
	bool CanCraft() { static NativeFunction f{ "UPrimalItem.CanCraft" }; return NativeCall<bool>(this, f); }
	bool CanCraftInInventory(UPrimalInventoryComponent* invComp) { static NativeFunction f{ "UPrimalItem.CanCraftInInventory" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, invComp); }
	FString* GetCraftRepairInvReqString(FString* result, int* OutNumMissing = nullptr, AShooterPlayerController* ForPC = nullptr) { static NativeFunction f{ "UPrimalItem.GetCraftRepairInvReqString" }; return NativeCall<FString*, FString*, int*, AShooterPlayerController*>(this, f, result, OutNumMissing, ForPC); }
	bool AllowUseInInventory(bool bIsRemoteInventory, AShooterPlayerController* ByPC, bool DontCheckActor) { static NativeFunction f{ "UPrimalItem.AllowUseInInventory" }; return NativeCall<bool, bool, AShooterPlayerController*, bool>(this, f, bIsRemoteInventory, ByPC, DontCheckActor); }
	bool CanBeArkTributeItem() { static NativeFunction f{ "UPrimalItem.CanBeArkTributeItem" }; return NativeCall<bool>(this, f); }
	void SetEngramBlueprint() { static NativeFunction f{ "UPrimalItem.SetEngramBlueprint" }; NativeCall<void>(this, f); }
	bool CanSpoil() { static NativeFunction f{ "UPrimalItem.CanSpoil" }; return NativeCall<bool>(this, f); }
	void RecalcSpoilingTime(long double TimeSeconds, float SpoilPercent, UPrimalInventoryComponent* forComp) { static NativeFunction f{ "UPrimalItem.RecalcSpoilingTime" }; NativeCall<void, long double, float, UPrimalInventoryComponent*>(this, f, TimeSeconds, SpoilPercent, forComp); }
	void InventoryRefreshCheckItem() { static NativeFunction f{ "UPrimalItem.InventoryRefreshCheckItem" }; NativeCall<void>(this, f); }
	bool IsValidForCrafting() { static NativeFunction f{ "UPrimalItem.IsValidForCrafting" }; return NativeCall<bool>(this, f); }
	bool IsOwnerInWater() { static NativeFunction f{ "UPrimalItem.IsOwnerInWater" }; return NativeCall<bool>(this, f); }
	bool IsOwnerInNoPainWater() { static NativeFunction f{ "UPrimalItem.IsOwnerInNoPainWater" }; return NativeCall<bool>(this, f); }
	bool AllowRemoteAddToInventory(UPrimalInventoryComponent* invComp, AShooterPlayerController* ByPC, bool bRequestedByPlayer) { static NativeFunction f{ "UPrimalItem.AllowRemoteAddToInventory" }; return NativeCall<bool, UPrimalInventoryComponent*, AShooterPlayerController*, bool>(this, f, invComp, ByPC, bRequestedByPlayer); }
	bool CanDrop() { static NativeFunction f{ "UPrimalItem.CanDrop" }; return NativeCall<bool>(this, f); }
	void PickupAlertDinos(AActor* groundItem) { static NativeFunction f{ "UPrimalItem.PickupAlertDinos" }; NativeCall<void, AActor*>(this, f, groundItem); }
	void GetItemAttachmentInfos(AActor* OwnerActor) { static NativeFunction f{ "UPrimalItem.GetItemAttachmentInfos" }; NativeCall<void, AActor*>(this, f, OwnerActor); }
	void SetAttachedMeshesMaterialScalarParamValue(FName ParamName, float Value) { static NativeFunction f{ "UPrimalItem.SetAttachedMeshesMaterialScalarParamValue" }; NativeCall<void, FName, float>(this, f, ParamName, Value); }
	bool CanUseWithItemSource(UPrimalItem* DestinationItem) { static NativeFunction f{ "UPrimalItem.CanUseWithItemSource" }; return NativeCall<bool, UPrimalItem*>(this, f, DestinationItem); }
	bool IsDyed() { static NativeFunction f{ "UPrimalItem.IsDyed" }; return NativeCall<bool>(this, f); }
	int GetItemColorID(int theRegion) { static NativeFunction f{ "UPrimalItem.GetItemColorID" }; return NativeCall<int, int>(this, f, theRegion); }
	bool CanUseWithItemDestination(UPrimalItem* SourceItem) { static NativeFunction f{ "UPrimalItem.CanUseWithItemDestination" }; return NativeCall<bool, UPrimalItem*>(this, f, SourceItem); }
	bool UseItemOntoItem(UPrimalItem* DestinationItem, int AdditionalData) { static NativeFunction f{ "UPrimalItem.UseItemOntoItem" }; return NativeCall<bool, UPrimalItem*, int>(this, f, DestinationItem, AdditionalData); }
	void LocalUseItemOntoItem(AShooterPlayerController* ForPC, UPrimalItem* DestinationItem) { static NativeFunction f{ "UPrimalItem.LocalUseItemOntoItem" }; NativeCall<void, AShooterPlayerController*, UPrimalItem*>(this, f, ForPC, DestinationItem); }
	FString* GetPrimaryColorName(FString* result) { static NativeFunction f{ "UPrimalItem.GetPrimaryColorName" }; return NativeCall<FString*, FString*>(this, f, result); }
	void Serialize(FArchive* Ar) { static NativeFunction f{ "UPrimalItem.Serialize" }; NativeCall<void, FArchive*>(this, f, Ar); }
	bool ProcessEditText(AShooterPlayerController* ForPC, FString* TextToUse, bool __formal) { static NativeFunction f{ "UPrimalItem.ProcessEditText" }; return NativeCall<bool, AShooterPlayerController*, FString*, bool>(this, f, ForPC, TextToUse, __formal); }
	void NotifyEditText(AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalItem.NotifyEditText" }; NativeCall<void, AShooterPlayerController*>(this, f, PC); }
	void AddToArkTributeInvenroty(UPrimalInventoryComponent* toInventory, bool bFromLoad) { static NativeFunction f{ "UPrimalItem.AddToArkTributeInvenroty" }; NativeCall<void, UPrimalInventoryComponent*, bool>(this, f, toInventory, bFromLoad); }
	int GetMaximumAdditionalCrafting(UPrimalInventoryComponent* forComp, AShooterPlayerController* PC) { static NativeFunction f{ "UPrimalItem.GetMaximumAdditionalCrafting" }; return NativeCall<int, UPrimalInventoryComponent*, AShooterPlayerController*>(this, f, forComp, PC); }
	void EquippedTick(float DeltaSeconds) { static NativeFunction f{ "UPrimalItem.EquippedTick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	float GetWeaponTemplateMeleeDamageAmount() { static NativeFunction f{ "UPrimalItem.GetWeaponTemplateMeleeDamageAmount" }; return NativeCall<float>(this, f); }
	float GetWeaponTemplateDurabilityToConsumePerMeleeHit() { static NativeFunction f{ "UPrimalItem.GetWeaponTemplateDurabilityToConsumePerMeleeHit" }; return NativeCall<float>(this, f); }
	TSubclassOf<UDamageType>* GetWeaponTemplateMeleeDamageType(TSubclassOf<UDamageType>* result) { static NativeFunction f{ "UPrimalItem.GetWeaponTemplateMeleeDamageType" }; return NativeCall<TSubclassOf<UDamageType>*, TSubclassOf<UDamageType>*>(this, f, result); }
	TSubclassOf<UDamageType>* GetWeaponTemplateHarvestDamageType(TSubclassOf<UDamageType>* result) { static NativeFunction f{ "UPrimalItem.GetWeaponTemplateHarvestDamageType" }; return NativeCall<TSubclassOf<UDamageType>*, TSubclassOf<UDamageType>*>(this, f, result); }
	float GetWeaponTemplateHarvestDamageMultiplier() { static NativeFunction f{ "UPrimalItem.GetWeaponTemplateHarvestDamageMultiplier" }; return NativeCall<float>(this, f); }
	void InventoryLoadedFromSaveGame() { static NativeFunction f{ "UPrimalItem.InventoryLoadedFromSaveGame" }; NativeCall<void>(this, f); }
	bool CheckForInventoryDupes() { static NativeFunction f{ "UPrimalItem.CheckForInventoryDupes" }; return NativeCall<bool>(this, f); }
	void CalcRecipeStats() { static NativeFunction f{ "UPrimalItem.CalcRecipeStats" }; NativeCall<void>(this, f); }
	int GetCraftingResourceRequirement(int CraftingResourceIndex) { static NativeFunction f{ "UPrimalItem.GetCraftingResourceRequirement" }; return NativeCall<int, int>(this, f, CraftingResourceIndex); }
	void BPGetItemID(int* ItemID1, int* ItemID2) { static NativeFunction f{ "UPrimalItem.BPGetItemID" }; NativeCall<void, int*, int*>(this, f, ItemID1, ItemID2); }
	bool BPMatchesItemID(int ItemID1, int ItemID2) { static NativeFunction f{ "UPrimalItem.BPMatchesItemID" }; return NativeCall<bool, int, int>(this, f, ItemID1, ItemID2); }
	bool IsUsableConsumable() { static NativeFunction f{ "UPrimalItem.IsUsableConsumable" }; return NativeCall<bool>(this, f); }
	int GetWeaponClipAmmo() { static NativeFunction f{ "UPrimalItem.GetWeaponClipAmmo" }; return NativeCall<int>(this, f); }
	bool CanEquipWeapon() { static NativeFunction f{ "UPrimalItem.CanEquipWeapon" }; return NativeCall<bool>(this, f); }
	bool HasCustomItemData(FName CustomDataName) { static NativeFunction f{ "UPrimalItem.HasCustomItemData" }; return NativeCall<bool, FName>(this, f, CustomDataName); }
	void RemoveCustomItemData(FName CustomDataName) { static NativeFunction f{ "UPrimalItem.RemoveCustomItemData" }; NativeCall<void, FName>(this, f, CustomDataName); }
	bool GetCustomItemData(FName CustomDataName, FCustomItemData* OutData) { static NativeFunction f{ "UPrimalItem.GetCustomItemData" }; return NativeCall<bool, FName, FCustomItemData*>(this, f, CustomDataName, OutData); }
	void SetCustomItemData(FCustomItemData* InData) { static NativeFunction f{ "UPrimalItem.SetCustomItemData" }; NativeCall<void, FCustomItemData*>(this, f, InData); }
	static FItemNetID BPMakeItemID(int TheItemID1, int TheItemID2) { static NativeFunction f{ "UPrimalItem.BPMakeItemID" }; return NativeCall<FItemNetID, int, int>(nullptr, f, TheItemID1, TheItemID2); }
	UPrimalInventoryComponent* GetInitializeItemOwnerInventory() { static NativeFunction f{ "UPrimalItem.GetInitializeItemOwnerInventory" }; return NativeCall<UPrimalInventoryComponent*>(this, f); }
	int GetEngramRequirementLevel() { static NativeFunction f{ "UPrimalItem.GetEngramRequirementLevel" }; return NativeCall<int>(this, f); }
	void BPSetWeaponClipAmmo(int NewClipAmmo) { static NativeFunction f{ "UPrimalItem.BPSetWeaponClipAmmo" }; NativeCall<void, int>(this, f, NewClipAmmo); }
	USoundBase* OverrideCrouchingSound_Implementation(USoundBase* InSound, bool bIsProne, int soundState) { static NativeFunction f{ "UPrimalItem.OverrideCrouchingSound_Implementation" }; return NativeCall<USoundBase*, USoundBase*, bool, int>(this, f, InSound, bIsProne, soundState); }
	void Crafted_Implementation(bool bWasCraftedFromEngram) { static NativeFunction f{ "UPrimalItem.Crafted_Implementation" }; NativeCall<void, bool>(this, f, bWasCraftedFromEngram); }
	UMaterialInterface* GetHUDIconMaterial() { static NativeFunction f{ "UPrimalItem.GetHUDIconMaterial" }; return NativeCall<UMaterialInterface*>(this, f); }
	bool GetItemCustomColor(int ColorRegion, FLinearColor* outColor) { static NativeFunction f{ "UPrimalItem.GetItemCustomColor" }; return NativeCall<bool, int, FLinearColor*>(this, f, ColorRegion, outColor); }
	float GetEggHatchTimeRemaining(UWorld* theWorld, float TimeOffset = 0.f) { static NativeFunction f{ "UPrimalItem.GetEggHatchTimeRemaining" }; return NativeCall<float, UWorld*, float>(this, f, theWorld, TimeOffset); }
	bool IsReadyToUpload(UWorld* theWorld) { static NativeFunction f{ "UPrimalItem.IsReadyToUpload" }; return NativeCall<bool, UWorld*>(this, f, theWorld); }
	float GetTimeUntilUploadAllowed(UWorld* theWorld) { static NativeFunction f{ "UPrimalItem.GetTimeUntilUploadAllowed" }; return NativeCall<float, UWorld*>(this, f, theWorld); }
	float HandleShieldDamageBlocking_Implementation(AShooterCharacter* ForShooterCharacter, float DamageIn, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "UPrimalItem.HandleShieldDamageBlocking_Implementation" }; return NativeCall<float, AShooterCharacter*, float, FDamageEvent*, AController*, AActor*>(this, f, ForShooterCharacter, DamageIn, DamageEvent, EventInstigator, DamageCauser); }
	TSubclassOf<AShooterProjectile>* BPOverrideProjectileType_Implementation(TSubclassOf<AShooterProjectile>* result) { static NativeFunction f{ "UPrimalItem.BPOverrideProjectileType_Implementation" }; return NativeCall<TSubclassOf<AShooterProjectile>*, TSubclassOf<AShooterProjectile>*>(this, f, result); }
	static TSubclassOf<AShooterProjectile>* GetProjectileType(TSubclassOf<AShooterProjectile>* result, TSubclassOf<UPrimalItem> ItemType) { static NativeFunction f{ "UPrimalItem.GetProjectileType" }; return NativeCall<TSubclassOf<AShooterProjectile>*, TSubclassOf<AShooterProjectile>*, TSubclassOf<UPrimalItem>>(nullptr, f, result, ItemType); }
	TArray<FLinearColor>* GetItemDyeColors(TArray<FLinearColor>* result) { static NativeFunction f{ "UPrimalItem.GetItemDyeColors" }; return NativeCall<TArray<FLinearColor>*, TArray<FLinearColor>*>(this, f, result); }
	bool IsActiveEventItem(UWorld* World) { static NativeFunction f{ "UPrimalItem.IsActiveEventItem" }; return NativeCall<bool, UWorld*>(this, f, World); }
	bool IsDeprecated(UWorld* World) { static NativeFunction f{ "UPrimalItem.IsDeprecated" }; return NativeCall<bool, UWorld*>(this, f, World); }
	void BeginDestroy() { static NativeFunction f{ "UPrimalItem.BeginDestroy" }; NativeCall<void>(this, f); }
	void RemoveFromWorldItemMap() { static NativeFunction f{ "UPrimalItem.RemoveFromWorldItemMap" }; NativeCall<void>(this, f); }
	bool IsBlueprintDeprecated(UWorld* World) { static NativeFunction f{ "UPrimalItem.IsBlueprintDeprecated" }; return NativeCall<bool, UWorld*>(this, f, World); }
	void OnVersionChange(bool* doDestroy, UWorld* World, AShooterGameMode* gameMode) { static NativeFunction f{ "UPrimalItem.OnVersionChange" }; NativeCall<void, bool*, UWorld*, AShooterGameMode*>(this, f, doDestroy, World, gameMode); }
	static void StaticRegisterNativesUPrimalItem() { static NativeFunction f{ "UPrimalItem.StaticRegisterNativesUPrimalItem" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "UPrimalItem.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	void ApplyingSkinOntoItem(UPrimalItem* ToOwnerItem, bool bIsFirstTime) { static NativeFunction f{ "UPrimalItem.ApplyingSkinOntoItem" }; NativeCall<void, UPrimalItem*, bool>(this, f, ToOwnerItem, bIsFirstTime); }
	void BlueprintEquipped(bool bIsFromSaveGame) { static NativeFunction f{ "UPrimalItem.BlueprintEquipped" }; NativeCall<void, bool>(this, f, bIsFromSaveGame); }
	void BlueprintOwnerPosssessed(AController* PossessedByController) { static NativeFunction f{ "UPrimalItem.BlueprintOwnerPosssessed" }; NativeCall<void, AController*>(this, f, PossessedByController); }
	void BlueprintUnequipped() { static NativeFunction f{ "UPrimalItem.BlueprintUnequipped" }; NativeCall<void>(this, f); }
	void BlueprintUsed() { static NativeFunction f{ "UPrimalItem.BlueprintUsed" }; NativeCall<void>(this, f); }
	void BPAddedAttachments() { static NativeFunction f{ "UPrimalItem.BPAddedAttachments" }; NativeCall<void>(this, f); }
	FString* BPAllowCrafting(FString* result, AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.BPAllowCrafting" }; return NativeCall<FString*, FString*, AShooterPlayerController*>(this, f, result, ForPC); }
	bool BPAllowRemoteAddToInventory(UPrimalInventoryComponent* invComp, AShooterPlayerController* ByPC, bool bRequestedByPlayer) { static NativeFunction f{ "UPrimalItem.BPAllowRemoteAddToInventory" }; return NativeCall<bool, UPrimalInventoryComponent*, AShooterPlayerController*, bool>(this, f, invComp, ByPC, bRequestedByPlayer); }
	bool BPAllowRemoteRemoveFromInventory(UPrimalInventoryComponent* invComp, AShooterPlayerController* ByPC, bool bRequestedByPlayer) { static NativeFunction f{ "UPrimalItem.BPAllowRemoteRemoveFromInventory" }; return NativeCall<bool, UPrimalInventoryComponent*, AShooterPlayerController*, bool>(this, f, invComp, ByPC, bRequestedByPlayer); }
	bool BPCanAddToInventory(UPrimalInventoryComponent* toInventory) { static NativeFunction f{ "UPrimalItem.BPCanAddToInventory" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, toInventory); }
	bool BPCanUse(bool bIgnoreCooldown) { static NativeFunction f{ "UPrimalItem.BPCanUse" }; return NativeCall<bool, bool>(this, f, bIgnoreCooldown); }
	bool BPConsumeProjectileImpact(AShooterProjectile* theProjectile, FHitResult* HitResult) { static NativeFunction f{ "UPrimalItem.BPConsumeProjectileImpact" }; return NativeCall<bool, AShooterProjectile*, FHitResult*>(this, f, theProjectile, HitResult); }
	void BPCrafted() { static NativeFunction f{ "UPrimalItem.BPCrafted" }; NativeCall<void>(this, f); }
	void BPEquippedItemOnXPEarning(APrimalCharacter* forChar, float howMuchXP, EXPType::Type TheXPType) { static NativeFunction f{ "UPrimalItem.BPEquippedItemOnXPEarning" }; NativeCall<void, APrimalCharacter*, float, EXPType::Type>(this, f, forChar, howMuchXP, TheXPType); }
	bool BPForceAllowRemoteAddToInventory(UPrimalInventoryComponent* toInventory) { static NativeFunction f{ "UPrimalItem.BPForceAllowRemoteAddToInventory" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, toInventory); }
	float BPGetCustomAutoDecreaseDurabilityPerInterval() { static NativeFunction f{ "UPrimalItem.BPGetCustomAutoDecreaseDurabilityPerInterval" }; return NativeCall<float>(this, f); }
	FString* BPGetCustomDurabilityText(FString* result) { static NativeFunction f{ "UPrimalItem.BPGetCustomDurabilityText" }; return NativeCall<FString*, FString*>(this, f, result); }
	FColor* BPGetCustomDurabilityTextColor(FColor* result) { static NativeFunction f{ "UPrimalItem.BPGetCustomDurabilityTextColor" }; return NativeCall<FColor*, FColor*>(this, f, result); }
	UMaterialInterface* BPGetCustomIconMaterialParent() { static NativeFunction f{ "UPrimalItem.BPGetCustomIconMaterialParent" }; return NativeCall<UMaterialInterface*>(this, f); }
	FString* BPGetCustomInventoryWidgetText(FString* result) { static NativeFunction f{ "UPrimalItem.BPGetCustomInventoryWidgetText" }; return NativeCall<FString*, FString*>(this, f, result); }
	FColor* BPGetCustomInventoryWidgetTextColor(FColor* result) { static NativeFunction f{ "UPrimalItem.BPGetCustomInventoryWidgetTextColor" }; return NativeCall<FColor*, FColor*>(this, f, result); }
	USoundBase* BPGetFuelAudioOverride(APrimalStructure* ForStructure) { static NativeFunction f{ "UPrimalItem.BPGetFuelAudioOverride" }; return NativeCall<USoundBase*, APrimalStructure*>(this, f, ForStructure); }
	FString* BPGetItemDescription(FString* result, FString* InDescription, bool bGetLongDescription, AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.BPGetItemDescription" }; return NativeCall<FString*, FString*, FString*, bool, AShooterPlayerController*>(this, f, result, InDescription, bGetLongDescription, ForPC); }
	float BPGetItemDurabilityPercentage() { static NativeFunction f{ "UPrimalItem.BPGetItemDurabilityPercentage" }; return NativeCall<float>(this, f); }
	UTexture2D* BPGetItemIcon(AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.BPGetItemIcon" }; return NativeCall<UTexture2D*, AShooterPlayerController*>(this, f, ForPC); }
	FString* BPGetItemName(FString* result, FString* ItemNameIn, AShooterPlayerController* ForPC) { static NativeFunction f{ "UPrimalItem.BPGetItemName" }; return NativeCall<FString*, FString*, FString*, AShooterPlayerController*>(this, f, result, ItemNameIn, ForPC); }
	void BPGetItemNetInfo() { static NativeFunction f{ "UPrimalItem.BPGetItemNetInfo" }; NativeCall<void>(this, f); }
	FString* BPGetSkinnedCustomInventoryWidgetText(FString* result) { static NativeFunction f{ "UPrimalItem.BPGetSkinnedCustomInventoryWidgetText" }; return NativeCall<FString*, FString*>(this, f, result); }
	void BPInitFromItemNetInfo() { static NativeFunction f{ "UPrimalItem.BPInitFromItemNetInfo" }; NativeCall<void>(this, f); }
	void BPInitIconMaterial() { static NativeFunction f{ "UPrimalItem.BPInitIconMaterial" }; NativeCall<void>(this, f); }
	void BPInitItemColors(TArray<int>* ColorIDs) { static NativeFunction f{ "UPrimalItem.BPInitItemColors" }; NativeCall<void, TArray<int>*>(this, f, ColorIDs); }
	bool BPIsValidForCrafting() { static NativeFunction f{ "UPrimalItem.BPIsValidForCrafting" }; return NativeCall<bool>(this, f); }
	void BPItemBelowDurabilityThreshold() { static NativeFunction f{ "UPrimalItem.BPItemBelowDurabilityThreshold" }; NativeCall<void>(this, f); }
	void BPItemBroken() { static NativeFunction f{ "UPrimalItem.BPItemBroken" }; NativeCall<void>(this, f); }
	void BPNotifyDropped(APrimalCharacter* FromCharacter, bool bWasThrown) { static NativeFunction f{ "UPrimalItem.BPNotifyDropped" }; NativeCall<void, APrimalCharacter*, bool>(this, f, FromCharacter, bWasThrown); }
	void BPOverrideCraftingConsumption(int AmountToConsume) { static NativeFunction f{ "UPrimalItem.BPOverrideCraftingConsumption" }; NativeCall<void, int>(this, f, AmountToConsume); }
	TSubclassOf<AShooterProjectile>* BPOverrideProjectileType(TSubclassOf<AShooterProjectile>* result) { static NativeFunction f{ "UPrimalItem.BPOverrideProjectileType" }; return NativeCall<TSubclassOf<AShooterProjectile>*, TSubclassOf<AShooterProjectile>*>(this, f, result); }
	void BPPostAddBuffToGiveOwnerCharacter(APrimalCharacter* OwnerCharacter, APrimalBuff* Buff) { static NativeFunction f{ "UPrimalItem.BPPostAddBuffToGiveOwnerCharacter" }; NativeCall<void, APrimalCharacter*, APrimalBuff*>(this, f, OwnerCharacter, Buff); }
	void BPPostInitializeItem(UWorld* OptionalInitWorld) { static NativeFunction f{ "UPrimalItem.BPPostInitializeItem" }; NativeCall<void, UWorld*>(this, f, OptionalInitWorld); }
	void BPPreInitializeItem(UWorld* OptionalInitWorld) { static NativeFunction f{ "UPrimalItem.BPPreInitializeItem" }; NativeCall<void, UWorld*>(this, f, OptionalInitWorld); }
	void BPPreUseItem() { static NativeFunction f{ "UPrimalItem.BPPreUseItem" }; NativeCall<void>(this, f); }
	bool BPPreventEquip(UPrimalInventoryComponent* toInventory) { static NativeFunction f{ "UPrimalItem.BPPreventEquip" }; return NativeCall<bool, UPrimalInventoryComponent*>(this, f, toInventory); }
	bool BPPreventUseOntoItem(UPrimalItem* DestinationItem) { static NativeFunction f{ "UPrimalItem.BPPreventUseOntoItem" }; return NativeCall<bool, UPrimalItem*>(this, f, DestinationItem); }
	bool BPPreventWeaponEquip() { static NativeFunction f{ "UPrimalItem.BPPreventWeaponEquip" }; return NativeCall<bool>(this, f); }
	bool BPProcessEditText(AShooterPlayerController* ForPC, FString* TextToUse) { static NativeFunction f{ "UPrimalItem.BPProcessEditText" }; return NativeCall<bool, AShooterPlayerController*, FString*>(this, f, ForPC, TextToUse); }
	bool BPSupportUseOntoItem(UPrimalItem* DestinationItem) { static NativeFunction f{ "UPrimalItem.BPSupportUseOntoItem" }; return NativeCall<bool, UPrimalItem*>(this, f, DestinationItem); }
	void BPTributeItemDownloaded(UObject* ContextObject) { static NativeFunction f{ "UPrimalItem.BPTributeItemDownloaded" }; NativeCall<void, UObject*>(this, f, ContextObject); }
	void BPTributeItemUploaded(UObject* ContextObject) { static NativeFunction f{ "UPrimalItem.BPTributeItemUploaded" }; NativeCall<void, UObject*>(this, f, ContextObject); }
	void BPUsedOntoItem(UPrimalItem* DestinationItem, int AdditionalData) { static NativeFunction f{ "UPrimalItem.BPUsedOntoItem" }; NativeCall<void, UPrimalItem*, int>(this, f, DestinationItem, AdditionalData); }
	void ClientUpdatedWeaponClipAmmo() { static NativeFunction f{ "UPrimalItem.ClientUpdatedWeaponClipAmmo" }; NativeCall<void>(this, f); }
	void Crafted(bool bWasCraftedFromEngram) { static NativeFunction f{ "UPrimalItem.Crafted" }; NativeCall<void, bool>(this, f, bWasCraftedFromEngram); }
	void EquippedBlueprintTick(float DeltaSeconds) { static NativeFunction f{ "UPrimalItem.EquippedBlueprintTick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	FString* GetInventoryIconDisplayText(FString* result) { static NativeFunction f{ "UPrimalItem.GetInventoryIconDisplayText" }; return NativeCall<FString*, FString*>(this, f, result); }
	float HandleShieldDamageBlocking(AShooterCharacter* ForShooterCharacter, float DamageIn, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "UPrimalItem.HandleShieldDamageBlocking" }; return NativeCall<float, AShooterCharacter*, float, FDamageEvent*, AController*, AActor*>(this, f, ForShooterCharacter, DamageIn, DamageEvent, EventInstigator, DamageCauser); }
	USoundBase* OverrideCrouchingSound(USoundBase* InSound, bool bIsProne, int soundState) { static NativeFunction f{ "UPrimalItem.OverrideCrouchingSound" }; return NativeCall<USoundBase*, USoundBase*, bool, int>(this, f, InSound, bIsProne, soundState); }
	void RemovedSkinFromItem(UPrimalItem* FromOwnerItem, bool bIsFirstTime) { static NativeFunction f{ "UPrimalItem.RemovedSkinFromItem" }; NativeCall<void, UPrimalItem*, bool>(this, f, FromOwnerItem, bIsFirstTime); }
	void ServerUpdatedWeaponClipAmmo() { static NativeFunction f{ "UPrimalItem.ServerUpdatedWeaponClipAmmo" }; NativeCall<void>(this, f); }
	void SkinEquippedBlueprintTick(UPrimalItem* OwnerItem, float DeltaSeconds) { static NativeFunction f{ "UPrimalItem.SkinEquippedBlueprintTick" }; NativeCall<void, UPrimalItem*, float>(this, f, OwnerItem, DeltaSeconds); }
	void SlottedTick(float DeltaSeconds) { static NativeFunction f{ "UPrimalItem.SlottedTick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
};

struct FItemNetInfo
{
	alignas(8) unsigned char __padding[0x1B0];
	TSubclassOf<UPrimalItem>& ItemArchetypeField() { static NativeFieldOffset f{ "FItemNetInfo.ItemArchetype" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	FItemNetID& ItemIDField() { static NativeFieldOffset f{ "FItemNetInfo.ItemID" }; return *GetNativePointerField<FItemNetID*>(this, f); }
	unsigned int& ItemQuantityField() { static NativeFieldOffset f{ "FItemNetInfo.ItemQuantity" }; return *GetNativePointerField<unsigned int*>(this, f); }
	int& CustomItemIDField() { static NativeFieldOffset f{ "FItemNetInfo.CustomItemID" }; return *GetNativePointerField<int*>(this, f); }
	int& SlotIndexField() { static NativeFieldOffset f{ "FItemNetInfo.SlotIndex" }; return *GetNativePointerField<int*>(this, f); }
	long double& CreationTimeField() { static NativeFieldOffset f{ "FItemNetInfo.CreationTime" }; return *GetNativePointerField<long double*>(this, f); }
	FString& CustomItemNameField() { static NativeFieldOffset f{ "FItemNetInfo.CustomItemName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CustomItemDescriptionField() { static NativeFieldOffset f{ "FItemNetInfo.CustomItemDescription" }; return *GetNativePointerField<FString*>(this, f); }
	long double& UploadEarliestValidTimeField() { static NativeFieldOffset f{ "FItemNetInfo.UploadEarliestValidTime" }; return *GetNativePointerField<long double*>(this, f); }
	TArray<unsigned __int64>& SteamUserItemIDField() { static NativeFieldOffset f{ "FItemNetInfo.SteamUserItemID" }; return *GetNativePointerField<TArray<unsigned __int64>*>(this, f); }
	unsigned __int16& CraftQueueField() { static NativeFieldOffset f{ "FItemNetInfo.CraftQueue" }; return *GetNativePointerField<unsigned __int16*>(this, f); }
	long double& NextCraftCompletionTimeField() { static NativeFieldOffset f{ "FItemNetInfo.NextCraftCompletionTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& CraftingSkillField() { static NativeFieldOffset f{ "FItemNetInfo.CraftingSkill" }; return *GetNativePointerField<float*>(this, f); }
	float& CraftedSkillBonusField() { static NativeFieldOffset f{ "FItemNetInfo.CraftedSkillBonus" }; return *GetNativePointerField<float*>(this, f); }
	FString& CrafterCharacterNameField() { static NativeFieldOffset f{ "FItemNetInfo.CrafterCharacterName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CrafterTribeNameField() { static NativeFieldOffset f{ "FItemNetInfo.CrafterTribeName" }; return *GetNativePointerField<FString*>(this, f); }
	unsigned int& WeaponClipAmmoField() { static NativeFieldOffset f{ "FItemNetInfo.WeaponClipAmmo" }; return *GetNativePointerField<unsigned int*>(this, f); }
	float& ItemDurabilityField() { static NativeFieldOffset f{ "FItemNetInfo.ItemDurability" }; return *GetNativePointerField<float*>(this, f); }
	float& ItemRatingField() { static NativeFieldOffset f{ "FItemNetInfo.ItemRating" }; return *GetNativePointerField<float*>(this, f); }
	unsigned int& ExpirationTimeUTCField() { static NativeFieldOffset f{ "FItemNetInfo.ExpirationTimeUTC" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned char& ItemQualityIndexField() { static NativeFieldOffset f{ "FItemNetInfo.ItemQualityIndex" }; return *GetNativePointerField<unsigned char*>(this, f); }
	TSubclassOf<UPrimalItem>& ItemCustomClassField() { static NativeFieldOffset f{ "FItemNetInfo.ItemCustomClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	FieldArray<unsigned __int16, 8> ItemStatValuesField() { static NativeFieldOffset f{ "FItemNetInfo.ItemStatValues" }; return { this, f }; }
	FieldArray<__int16, 6> ItemColorIDField() { static NativeFieldOffset f{ "FItemNetInfo.ItemColorID" }; return { this, f }; }
	TSubclassOf<UPrimalItem>& ItemSkinTemplateField() { static NativeFieldOffset f{ "FItemNetInfo.ItemSkinTemplate" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<FCustomItemData>& CustomItemDatasField() { static NativeFieldOffset f{ "FItemNetInfo.CustomItemDatas" }; return *GetNativePointerField<TArray<FCustomItemData>*>(this, f); }
	TArray<FColor>& CustomItemColorsField() { static NativeFieldOffset f{ "FItemNetInfo.CustomItemColors" }; return *GetNativePointerField<TArray<FColor>*>(this, f); }
	TArray<FCraftingResourceRequirement>& CustomResourceRequirementsField() { static NativeFieldOffset f{ "FItemNetInfo.CustomResourceRequirements" }; return *GetNativePointerField<TArray<FCraftingResourceRequirement>*>(this, f); }
	long double& NextSpoilingTimeField() { static NativeFieldOffset f{ "FItemNetInfo.NextSpoilingTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastSpoilingTimeField() { static NativeFieldOffset f{ "FItemNetInfo.LastSpoilingTime" }; return *GetNativePointerField<long double*>(this, f); }
	unsigned __int64& OwnerPlayerDataIdField() { static NativeFieldOffset f{ "FItemNetInfo.OwnerPlayerDataId" }; return *GetNativePointerField<unsigned __int64*>(this, f); }
	TWeakObjectPtr<AShooterCharacter>& LastOwnerPlayerField() { static NativeFieldOffset f{ "FItemNetInfo.LastOwnerPlayer" }; return *GetNativePointerField<TWeakObjectPtr<AShooterCharacter>*>(this, f); }
	long double& LastAutoDurabilityDecreaseTimeField() { static NativeFieldOffset f{ "FItemNetInfo.LastAutoDurabilityDecreaseTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& ItemStatClampsMultiplierField() { static NativeFieldOffset f{ "FItemNetInfo.ItemStatClampsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FVector& OriginalItemDropLocationField() { static NativeFieldOffset f{ "FItemNetInfo.OriginalItemDropLocation" }; return *GetNativePointerField<FVector*>(this, f); }
	FieldArray<__int16, 6> PreSkinItemColorIDField() { static NativeFieldOffset f{ "FItemNetInfo.PreSkinItemColorID" }; return { this, f }; }
	FieldArray<unsigned char, 12> EggNumberOfLevelUpPointsAppliedField() { static NativeFieldOffset f{ "FItemNetInfo.EggNumberOfLevelUpPointsApplied" }; return { this, f }; }
	float& EggTamedIneffectivenessModifierField() { static NativeFieldOffset f{ "FItemNetInfo.EggTamedIneffectivenessModifier" }; return *GetNativePointerField<float*>(this, f); }
	FieldArray<unsigned char, 6> EggColorSetIndicesField() { static NativeFieldOffset f{ "FItemNetInfo.EggColorSetIndices" }; return { this, f }; }
	unsigned char& ItemVersionField() { static NativeFieldOffset f{ "FItemNetInfo.ItemVersion" }; return *GetNativePointerField<unsigned char*>(this, f); }
	long double& ClusterSpoilingTimeUTCField() { static NativeFieldOffset f{ "FItemNetInfo.ClusterSpoilingTimeUTC" }; return *GetNativePointerField<long double*>(this, f); }
	TArray<FDinoAncestorsEntry>& EggDinoAncestorsField() { static NativeFieldOffset f{ "FItemNetInfo.EggDinoAncestors" }; return *GetNativePointerField<TArray<FDinoAncestorsEntry>*>(this, f); }
	TArray<FDinoAncestorsEntry>& EggDinoAncestorsMaleField() { static NativeFieldOffset f{ "FItemNetInfo.EggDinoAncestorsMale" }; return *GetNativePointerField<TArray<FDinoAncestorsEntry>*>(this, f); }
	int& EggRandomMutationsFemaleField() { static NativeFieldOffset f{ "FItemNetInfo.EggRandomMutationsFemale" }; return *GetNativePointerField<int*>(this, f); }
	int& EggRandomMutationsMaleField() { static NativeFieldOffset f{ "FItemNetInfo.EggRandomMutationsMale" }; return *GetNativePointerField<int*>(this, f); }
	unsigned char& ItemProfileVersionField() { static NativeFieldOffset f{ "FItemNetInfo.ItemProfileVersion" }; return *GetNativePointerField<unsigned char*>(this, f); }
	bool& bNetInfoFromClientField() { static NativeFieldOffset f{ "FItemNetInfo.bNetInfoFromClient" }; return *GetNativePointerField<bool*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bIsBlueprint() { static NativeBitField f{ "FItemNetInfo.bIsBlueprint" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsEngram() { static NativeBitField f{ "FItemNetInfo.bIsEngram" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsCustomRecipe() { static NativeBitField f{ "FItemNetInfo.bIsCustomRecipe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFoodRecipe() { static NativeBitField f{ "FItemNetInfo.bIsFoodRecipe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsRepairing() { static NativeBitField f{ "FItemNetInfo.bIsRepairing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemovalFromInventory() { static NativeBitField f{ "FItemNetInfo.bAllowRemovalFromInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideFromInventoryDisplay() { static NativeBitField f{ "FItemNetInfo.bHideFromInventoryDisplay" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemovalFromSteamInventory() { static NativeBitField f{ "FItemNetInfo.bAllowRemovalFromSteamInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bFromSteamInventory() { static NativeBitField f{ "FItemNetInfo.bFromSteamInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFromAllClustersInventory() { static NativeBitField f{ "FItemNetInfo.bIsFromAllClustersInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventGrinding() { static NativeBitField f{ "FItemNetInfo.bForcePreventGrinding" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsEquipped() { static NativeBitField f{ "FItemNetInfo.bIsEquipped" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsSlot() { static NativeBitField f{ "FItemNetInfo.bIsSlot" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsInitialItem() { static NativeBitField f{ "FItemNetInfo.bIsInitialItem" }; return { this, f }; }

	// Functions

	FItemNetInfo* operator=(FItemNetInfo* __that) { static NativeFunction f{ "FItemNetInfo.operator=" }; return NativeCall<FItemNetInfo*, FItemNetInfo*>(this, f, __that); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FItemNetInfo.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FItemStatInfo
{
	alignas(4) unsigned char __padding[0x24];
	int& DefaultModifierValueField() { static NativeFieldOffset f{ "FItemStatInfo.DefaultModifierValue" }; return *GetNativePointerField<int*>(this, f); }
	int& RandomizerRangeOverrideField() { static NativeFieldOffset f{ "FItemStatInfo.RandomizerRangeOverride" }; return *GetNativePointerField<int*>(this, f); }
	float& RandomizerRangeMultiplierField() { static NativeFieldOffset f{ "FItemStatInfo.RandomizerRangeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& TheRandomizerPowerField() { static NativeFieldOffset f{ "FItemStatInfo.TheRandomizerPower" }; return *GetNativePointerField<float*>(this, f); }
	float& StateModifierScaleField() { static NativeFieldOffset f{ "FItemStatInfo.StateModifierScale" }; return *GetNativePointerField<float*>(this, f); }
	float& InitialValueConstantField() { static NativeFieldOffset f{ "FItemStatInfo.InitialValueConstant" }; return *GetNativePointerField<float*>(this, f); }
	float& RatingValueMultiplierField() { static NativeFieldOffset f{ "FItemStatInfo.RatingValueMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& AbsoluteMaxValueField() { static NativeFieldOffset f{ "FItemStatInfo.AbsoluteMaxValue" }; return *GetNativePointerField<float*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bUsed() { static NativeBitField f{ "FItemStatInfo.bUsed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCalculateAsPercent() { static NativeBitField f{ "FItemStatInfo.bCalculateAsPercent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisplayAsPercent() { static NativeBitField f{ "FItemStatInfo.bDisplayAsPercent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresSubmerged() { static NativeBitField f{ "FItemStatInfo.bRequiresSubmerged" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventIfSubmerged() { static NativeBitField f{ "FItemStatInfo.bPreventIfSubmerged" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideStatFromTooltip() { static NativeBitField f{ "FItemStatInfo.bHideStatFromTooltip" }; return { this, f }; }

	// Functions

	float GetItemStatModifier(unsigned __int16 ItemStatValue) { static NativeFunction f{ "FItemStatInfo.GetItemStatModifier" }; return NativeCall<float, unsigned __int16>(this, f, ItemStatValue); }
	unsigned __int16 GetRandomValue(float QualityLevel, float MinRandomQuality, float* outRandonMultiplier) { static NativeFunction f{ "FItemStatInfo.GetRandomValue" }; return NativeCall<unsigned __int16, float, float, float*>(this, f, QualityLevel, MinRandomQuality, outRandonMultiplier); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FItemStatInfo.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};
