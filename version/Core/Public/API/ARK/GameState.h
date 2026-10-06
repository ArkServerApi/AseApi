#pragma once

#include "API/Base.h"

struct AGameState : AInfo
{
	static UClass* StaticClass() { static NativeStaticClass f{ "AGameState.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	TSubclassOf<AGameMode>& GameModeClassField() { static NativeFieldOffset f{ "AGameState.GameModeClass" }; return *GetNativePointerField<TSubclassOf<AGameMode>*>(this, f); }
	AGameMode* AuthorityGameModeField() { static NativeFieldOffset f{ "AGameState.AuthorityGameMode" }; return *GetNativePointerField<AGameMode**>(this, f); }
	TSubclassOf<ASpectatorPawn>& SpectatorClassField() { static NativeFieldOffset f{ "AGameState.SpectatorClass" }; return *GetNativePointerField<TSubclassOf<ASpectatorPawn>*>(this, f); }
	FName& MatchStateField() { static NativeFieldOffset f{ "AGameState.MatchState" }; return *GetNativePointerField<FName*>(this, f); }
	FName& PreviousMatchStateField() { static NativeFieldOffset f{ "AGameState.PreviousMatchState" }; return *GetNativePointerField<FName*>(this, f); }
	int& ElapsedTimeField() { static NativeFieldOffset f{ "AGameState.ElapsedTime" }; return *GetNativePointerField<int*>(this, f); }
	TArray<APlayerState*>& PlayerArrayField() { static NativeFieldOffset f{ "AGameState.PlayerArray" }; return *GetNativePointerField<TArray<APlayerState*>*>(this, f); }
	TArray<APlayerState*>& InactivePlayerArrayField() { static NativeFieldOffset f{ "AGameState.InactivePlayerArray" }; return *GetNativePointerField<TArray<APlayerState*>*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bServerAllowsAnsel() { static NativeBitField f{ "AGameState.bServerAllowsAnsel" }; return { this, f }; }

	// Functions

	bool TeleportTo(FVector* DestLocation, FRotator* DestRotation, bool bIsATest, bool bNoCheck) { static NativeFunction f{ "AGameState.TeleportTo" }; return NativeCall<bool, FVector*, FRotator*, bool, bool>(this, f, DestLocation, DestRotation, bIsATest, bNoCheck); }
	void DefaultTimer() { static NativeFunction f{ "AGameState.DefaultTimer" }; NativeCall<void>(this, f); }
	void PostInitializeComponents() { static NativeFunction f{ "AGameState.PostInitializeComponents" }; NativeCall<void>(this, f); }
	void OnRep_GameModeClass() { static NativeFunction f{ "AGameState.OnRep_GameModeClass" }; NativeCall<void>(this, f); }
	void ReceivedGameModeClass() { static NativeFunction f{ "AGameState.ReceivedGameModeClass" }; NativeCall<void>(this, f); }
	void ReceivedSpectatorClass() { static NativeFunction f{ "AGameState.ReceivedSpectatorClass" }; NativeCall<void>(this, f); }
	void SeamlessTravelTransitionCheckpoint(bool bToTransitionMap) { static NativeFunction f{ "AGameState.SeamlessTravelTransitionCheckpoint" }; NativeCall<void, bool>(this, f, bToTransitionMap); }
	void AddPlayerState(APlayerState* PlayerState) { static NativeFunction f{ "AGameState.AddPlayerState" }; NativeCall<void, APlayerState*>(this, f, PlayerState); }
	void RemovePlayerState(APlayerState* PlayerState) { static NativeFunction f{ "AGameState.RemovePlayerState" }; NativeCall<void, APlayerState*>(this, f, PlayerState); }
	void HandleMatchIsWaitingToStart() { static NativeFunction f{ "AGameState.HandleMatchIsWaitingToStart" }; NativeCall<void>(this, f); }
	void HandleMatchHasStarted() { static NativeFunction f{ "AGameState.HandleMatchHasStarted" }; NativeCall<void>(this, f); }
	bool HasMatchStarted() { static NativeFunction f{ "AGameState.HasMatchStarted" }; return NativeCall<bool>(this, f); }
	bool IsMatchInProgress() { static NativeFunction f{ "AGameState.IsMatchInProgress" }; return NativeCall<bool>(this, f); }
	bool HasMatchEnded() { static NativeFunction f{ "AGameState.HasMatchEnded" }; return NativeCall<bool>(this, f); }
	void InitializedGameState() { static NativeFunction f{ "AGameState.InitializedGameState" }; NativeCall<void>(this, f); }
	void OnRep_MatchState() { static NativeFunction f{ "AGameState.OnRep_MatchState" }; NativeCall<void>(this, f); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "AGameState.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	void NetSpawnActorAtLocation(TSubclassOf<AActor> AnActorClass, FVector_NetQuantize AtLocation, FRotator_NetQuantize AtRotation, AActor* EffectOwnerToIgnore, float MaxRangeToReplicate, USceneComponent* attachToComponent, int dataIndex, FName attachSocketName, bool bOnlySendToEffectOwner) { static NativeFunction f{ "AGameState.NetSpawnActorAtLocation" }; NativeCall<void, TSubclassOf<AActor>, FVector_NetQuantize, FRotator_NetQuantize, AActor*, float, USceneComponent*, int, FName, bool>(this, f, AnActorClass, AtLocation, AtRotation, EffectOwnerToIgnore, MaxRangeToReplicate, attachToComponent, dataIndex, attachSocketName, bOnlySendToEffectOwner); }
	bool Semaphore_TryGrab(FName SemaphoreName, AActor* InObject, float PriorityWeight, int MaxToAllocate) { static NativeFunction f{ "AGameState.Semaphore_TryGrab" }; return NativeCall<bool, FName, AActor*, float, int>(this, f, SemaphoreName, InObject, PriorityWeight, MaxToAllocate); }
	bool Semaphore_Release(FName SemaphoreName, AActor* InObject) { static NativeFunction f{ "AGameState.Semaphore_Release" }; return NativeCall<bool, FName, AActor*>(this, f, SemaphoreName, InObject); }
};

struct AShooterGameState : AGameState
{
	int& NumNPCField() { static NativeFieldOffset f{ "AShooterGameState.NumNPC" }; return *GetNativePointerField<int*>(this, f); }
	int& NumHibernatedNPCField() { static NativeFieldOffset f{ "AShooterGameState.NumHibernatedNPC" }; return *GetNativePointerField<int*>(this, f); }
	int& NumActiveNPCField() { static NativeFieldOffset f{ "AShooterGameState.NumActiveNPC" }; return *GetNativePointerField<int*>(this, f); }
	int& NumDeadNPCField() { static NativeFieldOffset f{ "AShooterGameState.NumDeadNPC" }; return *GetNativePointerField<int*>(this, f); }
	int& NumPlayerActorsField() { static NativeFieldOffset f{ "AShooterGameState.NumPlayerActors" }; return *GetNativePointerField<int*>(this, f); }
	int& NumPlayerConnectedField() { static NativeFieldOffset f{ "AShooterGameState.NumPlayerConnected" }; return *GetNativePointerField<int*>(this, f); }
	bool& bServerUseLocalizedChatField() { static NativeFieldOffset f{ "AShooterGameState.bServerUseLocalizedChat" }; return *GetNativePointerField<bool*>(this, f); }
	float& LocalizedChatRadiusField() { static NativeFieldOffset f{ "AShooterGameState.LocalizedChatRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& VoiceSuperRangeRadiusField() { static NativeFieldOffset f{ "AShooterGameState.VoiceSuperRangeRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& VoiceWhisperRangeRadiusField() { static NativeFieldOffset f{ "AShooterGameState.VoiceWhisperRangeRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& LocalizedChatRadiusUnconsiousScaleField() { static NativeFieldOffset f{ "AShooterGameState.LocalizedChatRadiusUnconsiousScale" }; return *GetNativePointerField<float*>(this, f); }
	unsigned int& VivoxAttenuationModelField() { static NativeFieldOffset f{ "AShooterGameState.VivoxAttenuationModel" }; return *GetNativePointerField<unsigned int*>(this, f); }
	float& VivoxMinDistanceField() { static NativeFieldOffset f{ "AShooterGameState.VivoxMinDistance" }; return *GetNativePointerField<float*>(this, f); }
	float& VivoxRolloffField() { static NativeFieldOffset f{ "AShooterGameState.VivoxRolloff" }; return *GetNativePointerField<float*>(this, f); }
	float& ServerFramerateField() { static NativeFieldOffset f{ "AShooterGameState.ServerFramerate" }; return *GetNativePointerField<float*>(this, f); }
	FString & NewStructureDestructionTagField() { static NativeFieldOffset f{ "AShooterGameState.NewStructureDestructionTag" }; return *GetNativePointerField<FString*>(this, f); }
	int& DayNumberField() { static NativeFieldOffset f{ "AShooterGameState.DayNumber" }; return *GetNativePointerField<int*>(this, f); }
	float& DayTimeField() { static NativeFieldOffset f{ "AShooterGameState.DayTime" }; return *GetNativePointerField<float*>(this, f); }
	long double& NetworkTimeField() { static NativeFieldOffset f{ "AShooterGameState.NetworkTime" }; return *GetNativePointerField<long double*>(this, f); }
	unsigned int& TimeUTCField() { static NativeFieldOffset f{ "AShooterGameState.TimeUTC" }; return *GetNativePointerField<unsigned int*>(this, f); }
	bool& bIsOfficialServerField() { static NativeFieldOffset f{ "AShooterGameState.bIsOfficialServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsListenServerField() { static NativeFieldOffset f{ "AShooterGameState.bIsListenServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsDediServerField() { static NativeFieldOffset f{ "AShooterGameState.bIsDediServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsArkTributeAvailableField() { static NativeFieldOffset f{ "AShooterGameState.bIsArkTributeAvailable" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsArkDownloadsAllowedField() { static NativeFieldOffset f{ "AShooterGameState.bIsArkDownloadsAllowed" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowThirdPersonPlayerField() { static NativeFieldOffset f{ "AShooterGameState.bAllowThirdPersonPlayer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerHardcoreField() { static NativeFieldOffset f{ "AShooterGameState.bServerHardcore" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerPVEField() { static NativeFieldOffset f{ "AShooterGameState.bServerPVE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAutoPvEField() { static NativeFieldOffset f{ "AShooterGameState.bAutoPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerCrosshairField() { static NativeFieldOffset f{ "AShooterGameState.bServerCrosshair" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerForceNoHUDField() { static NativeFieldOffset f{ "AShooterGameState.bServerForceNoHUD" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bFlyerPlatformAllowUnalignedDinoBasingField() { static NativeFieldOffset f{ "AShooterGameState.bFlyerPlatformAllowUnalignedDinoBasing" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bMapPlayerLocationField() { static NativeFieldOffset f{ "AShooterGameState.bMapPlayerLocation" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEDisableFriendlyFireField() { static NativeFieldOffset f{ "AShooterGameState.bPvEDisableFriendlyFire" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEAllowTribeWarField() { static NativeFieldOffset f{ "AShooterGameState.bPvEAllowTribeWar" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEAllowTribeWarCancelField() { static NativeFieldOffset f{ "AShooterGameState.bPvEAllowTribeWarCancel" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bEnablePvPGammaField() { static NativeFieldOffset f{ "AShooterGameState.bEnablePvPGamma" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisablePvEGammaField() { static NativeFieldOffset f{ "AShooterGameState.bDisablePvEGamma" }; return *GetNativePointerField<bool*>(this, f); }
	int& NumTamedDinosField() { static NativeFieldOffset f{ "AShooterGameState.NumTamedDinos" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxStructuresInRangeField() { static NativeFieldOffset f{ "AShooterGameState.MaxStructuresInRange" }; return *GetNativePointerField<int*>(this, f); }
	float& DayCycleSpeedScaleField() { static NativeFieldOffset f{ "AShooterGameState.DayCycleSpeedScale" }; return *GetNativePointerField<float*>(this, f); }
	float& DayTimeSpeedScaleField() { static NativeFieldOffset f{ "AShooterGameState.DayTimeSpeedScale" }; return *GetNativePointerField<float*>(this, f); }
	float& NightTimeSpeedScaleField() { static NativeFieldOffset f{ "AShooterGameState.NightTimeSpeedScale" }; return *GetNativePointerField<float*>(this, f); }
	float& PvEStructureDecayPeriodMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.PvEStructureDecayPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PvEDinoDecayPeriodMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.PvEDinoDecayPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PerPlatformMaxStructuresMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.PerPlatformMaxStructuresMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bDisableStructureDecayPvEField() { static NativeFieldOffset f{ "AShooterGameState.bDisableStructureDecayPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableDinoDecayPvEField() { static NativeFieldOffset f{ "AShooterGameState.bDisableDinoDecayPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCaveBuildingPvEField() { static NativeFieldOffset f{ "AShooterGameState.bAllowCaveBuildingPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCaveBuildingPvPField() { static NativeFieldOffset f{ "AShooterGameState.bAllowCaveBuildingPvP" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventDownloadSurvivorsField() { static NativeFieldOffset f{ "AShooterGameState.bPreventDownloadSurvivors" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bReachedPlatformStructureLimitField() { static NativeFieldOffset f{ "AShooterGameState.bReachedPlatformStructureLimit" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAdminLoggingField() { static NativeFieldOffset f{ "AShooterGameState.bAdminLogging" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvPStructureDecayField() { static NativeFieldOffset f{ "AShooterGameState.bPvPStructureDecay" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventDownloadDinosField() { static NativeFieldOffset f{ "AShooterGameState.bPreventDownloadDinos" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventDownloadItemsField() { static NativeFieldOffset f{ "AShooterGameState.bPreventDownloadItems" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventUploadDinosField() { static NativeFieldOffset f{ "AShooterGameState.bPreventUploadDinos" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventUploadItemsField() { static NativeFieldOffset f{ "AShooterGameState.bPreventUploadItems" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventUploadSurvivorsField() { static NativeFieldOffset f{ "AShooterGameState.bPreventUploadSurvivors" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventMateBoostField() { static NativeFieldOffset f{ "AShooterGameState.bPreventMateBoost" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventStructurePaintingField() { static NativeFieldOffset f{ "AShooterGameState.bPreventStructurePainting" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCharacterCreationField() { static NativeFieldOffset f{ "AShooterGameState.bAllowCharacterCreation" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowSpawnPointSelectionField() { static NativeFieldOffset f{ "AShooterGameState.bAllowSpawnPointSelection" }; return *GetNativePointerField<bool*>(this, f); }
	int& MaxTamedDinosField() { static NativeFieldOffset f{ "AShooterGameState.MaxTamedDinos" }; return *GetNativePointerField<int*>(this, f); }
	bool& bDisableSpawnAnimationsField() { static NativeFieldOffset f{ "AShooterGameState.bDisableSpawnAnimations" }; return *GetNativePointerField<bool*>(this, f); }
	FString & PlayerListStringField() { static NativeFieldOffset f{ "AShooterGameState.PlayerListString" }; return *GetNativePointerField<FString*>(this, f); }
	float& GlobalSpoilingTimeMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.GlobalSpoilingTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalItemDecompositionTimeMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.GlobalItemDecompositionTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	int& MaxNumberOfPlayersInTribeField() { static NativeFieldOffset f{ "AShooterGameState.MaxNumberOfPlayersInTribe" }; return *GetNativePointerField<int*>(this, f); }
	float& TribeSlotReuseCooldownField() { static NativeFieldOffset f{ "AShooterGameState.TribeSlotReuseCooldown" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalCorpseDecompositionTimeMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.GlobalCorpseDecompositionTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& EggHatchSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.EggHatchSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FName & ActiveEventField() { static NativeFieldOffset f{ "AShooterGameState.ActiveEvent" }; return *GetNativePointerField<FName*>(this, f); }
	bool& bAllowPaintingWithoutResourcesField() { static NativeFieldOffset f{ "AShooterGameState.bAllowPaintingWithoutResources" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bEnableExtraStructurePreventionVolumesField() { static NativeFieldOffset f{ "AShooterGameState.bEnableExtraStructurePreventionVolumes" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FItemCraftingCostOverride> & OverrideItemCraftingCostsField() { static NativeFieldOffset f{ "AShooterGameState.OverrideItemCraftingCosts" }; return *GetNativePointerField<TArray<FItemCraftingCostOverride>*>(this, f); }
	TArray<FItemMaxItemQuantityOverride> & OverrideItemMaxQuantityField() { static NativeFieldOffset f{ "AShooterGameState.OverrideItemMaxQuantity" }; return *GetNativePointerField<TArray<FItemMaxItemQuantityOverride>*>(this, f); }
	long double& LastServerSaveTimeField() { static NativeFieldOffset f{ "AShooterGameState.LastServerSaveTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& ServerSaveIntervalField() { static NativeFieldOffset f{ "AShooterGameState.ServerSaveInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& TribeNameChangeCooldownField() { static NativeFieldOffset f{ "AShooterGameState.TribeNameChangeCooldown" }; return *GetNativePointerField<float*>(this, f); }
	float& PlatformSaddleBuildAreaBoundsMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.PlatformSaddleBuildAreaBoundsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAlwaysAllowStructurePickupField() { static NativeFieldOffset f{ "AShooterGameState.bAlwaysAllowStructurePickup" }; return *GetNativePointerField<bool*>(this, f); }
	float& StructurePickupTimeAfterPlacementField() { static NativeFieldOffset f{ "AShooterGameState.StructurePickupTimeAfterPlacement" }; return *GetNativePointerField<float*>(this, f); }
	float& StructurePickupHoldDurationField() { static NativeFieldOffset f{ "AShooterGameState.StructurePickupHoldDuration" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAllowIntegratedSPlusStructuresField() { static NativeFieldOffset f{ "AShooterGameState.bAllowIntegratedSPlusStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowHideDamageSourceFromLogsField() { static NativeFieldOffset f{ "AShooterGameState.bAllowHideDamageSourceFromLogs" }; return *GetNativePointerField<bool*>(this, f); }
	UAudioComponent * DynamicMusicAudioComponentField() { static NativeFieldOffset f{ "AShooterGameState.DynamicMusicAudioComponent" }; return *GetNativePointerField<UAudioComponent**>(this, f); }
	UAudioComponent * DynamicMusicAudioComponent2Field() { static NativeFieldOffset f{ "AShooterGameState.DynamicMusicAudioComponent2" }; return *GetNativePointerField<UAudioComponent**>(this, f); }
	bool& bPlayingDynamicMusicField() { static NativeFieldOffset f{ "AShooterGameState.bPlayingDynamicMusic" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPlayingDynamicMusic1Field() { static NativeFieldOffset f{ "AShooterGameState.bPlayingDynamicMusic1" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPlayingDynamicMusic2Field() { static NativeFieldOffset f{ "AShooterGameState.bPlayingDynamicMusic2" }; return *GetNativePointerField<bool*>(this, f); }
	float& LastHadMusicTimeField() { static NativeFieldOffset f{ "AShooterGameState.LastHadMusicTime" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FLevelExperienceRamp> & LevelExperienceRampOverridesField() { static NativeFieldOffset f{ "AShooterGameState.LevelExperienceRampOverrides" }; return *GetNativePointerField<TArray<FLevelExperienceRamp>*>(this, f); }
	TArray<FEngramEntryOverride> & OverrideEngramEntriesField() { static NativeFieldOffset f{ "AShooterGameState.OverrideEngramEntries" }; return *GetNativePointerField<TArray<FEngramEntryOverride>*>(this, f); }
	TArray<FString> & PreventDinoTameClassNamesField() { static NativeFieldOffset f{ "AShooterGameState.PreventDinoTameClassNames" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	float& ListenServerTetherDistanceMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.ListenServerTetherDistanceMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FString & PGMapNameField() { static NativeFieldOffset f{ "AShooterGameState.PGMapName" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<int> & SupportedSpawnRegionsField() { static NativeFieldOffset f{ "AShooterGameState.SupportedSpawnRegions" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	UPaintingCache * PaintingCacheField() { static NativeFieldOffset f{ "AShooterGameState.PaintingCache" }; return *GetNativePointerField<UPaintingCache**>(this, f); }
	USoundBase * StaticOverrideMusicField() { static NativeFieldOffset f{ "AShooterGameState.StaticOverrideMusic" }; return *GetNativePointerField<USoundBase**>(this, f); }
	bool& bEnableDeathTeamSpectatorField() { static NativeFieldOffset f{ "AShooterGameState.bEnableDeathTeamSpectator" }; return *GetNativePointerField<bool*>(this, f); }
	FVector & PlayerFloatingHUDOffsetField() { static NativeFieldOffset f{ "AShooterGameState.PlayerFloatingHUDOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& PlayerFloatingHUDOffsetScreenYField() { static NativeFieldOffset f{ "AShooterGameState.PlayerFloatingHUDOffsetScreenY" }; return *GetNativePointerField<float*>(this, f); }
	float& StructureDamageRepairCooldownField() { static NativeFieldOffset f{ "AShooterGameState.StructureDamageRepairCooldown" }; return *GetNativePointerField<float*>(this, f); }
	bool& bForceAllStructureLockingField() { static NativeFieldOffset f{ "AShooterGameState.bForceAllStructureLocking" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCustomRecipesField() { static NativeFieldOffset f{ "AShooterGameState.bAllowCustomRecipes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowRaidDinoFeedingField() { static NativeFieldOffset f{ "AShooterGameState.bAllowRaidDinoFeeding" }; return *GetNativePointerField<bool*>(this, f); }
	float& CustomRecipeEffectivenessMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.CustomRecipeEffectivenessMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CustomRecipeSkillMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.CustomRecipeSkillMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	USoundBase * OverrideAreaMusicField() { static NativeFieldOffset f{ "AShooterGameState.OverrideAreaMusic" }; return *GetNativePointerField<USoundBase**>(this, f); }
	FVector & OverrideAreaMusicPositionField() { static NativeFieldOffset f{ "AShooterGameState.OverrideAreaMusicPosition" }; return *GetNativePointerField<FVector*>(this, f); }
	float& OverrideAreaMusicRangeField() { static NativeFieldOffset f{ "AShooterGameState.OverrideAreaMusicRange" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAllowUnclaimDinosField() { static NativeFieldOffset f{ "AShooterGameState.bAllowUnclaimDinos" }; return *GetNativePointerField<bool*>(this, f); }
	float& FloatingHUDRangeField() { static NativeFieldOffset f{ "AShooterGameState.FloatingHUDRange" }; return *GetNativePointerField<float*>(this, f); }
	float& FloatingChatRangeField() { static NativeFieldOffset f{ "AShooterGameState.FloatingChatRange" }; return *GetNativePointerField<float*>(this, f); }
	int& ExtinctionEventTimeIntervalField() { static NativeFieldOffset f{ "AShooterGameState.ExtinctionEventTimeInterval" }; return *GetNativePointerField<int*>(this, f); }
	float& ExtinctionEventPercentField() { static NativeFieldOffset f{ "AShooterGameState.ExtinctionEventPercent" }; return *GetNativePointerField<float*>(this, f); }
	int& ExtinctionEventSecondsRemainingField() { static NativeFieldOffset f{ "AShooterGameState.ExtinctionEventSecondsRemaining" }; return *GetNativePointerField<int*>(this, f); }
	bool& bDoExtinctionEventField() { static NativeFieldOffset f{ "AShooterGameState.bDoExtinctionEvent" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FInventoryComponentDefaultItemsAppend> & InventoryComponentAppendsField() { static NativeFieldOffset f{ "AShooterGameState.InventoryComponentAppends" }; return *GetNativePointerField<TArray<FInventoryComponentDefaultItemsAppend>*>(this, f); }
	bool& bPreventOfflinePvPField() { static NativeFieldOffset f{ "AShooterGameState.bPreventOfflinePvP" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvPDinoDecayField() { static NativeFieldOffset f{ "AShooterGameState.bPvPDinoDecay" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowUnclaimDinosConfigField() { static NativeFieldOffset f{ "AShooterGameState.bAllowUnclaimDinosConfig" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bForceUseInventoryAppendsField() { static NativeFieldOffset f{ "AShooterGameState.bForceUseInventoryAppends" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bOverideStructurePlatformPreventionField() { static NativeFieldOffset f{ "AShooterGameState.bOverideStructurePlatformPrevention" }; return *GetNativePointerField<bool*>(this, f); }
	float& ItemStackSizeMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.ItemStackSizeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	TArray<int> & PreventOfflinePvPLiveTeamsField() { static NativeFieldOffset f{ "AShooterGameState.PreventOfflinePvPLiveTeams" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	TArray<int> & PreventOfflinePvPExpiringTeamsField() { static NativeFieldOffset f{ "AShooterGameState.PreventOfflinePvPExpiringTeams" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	TArray<double> & PreventOfflinePvPExpiringTimesField() { static NativeFieldOffset f{ "AShooterGameState.PreventOfflinePvPExpiringTimes" }; return *GetNativePointerField<TArray<double>*>(this, f); }
	TMap<int,double,FDefaultSetAllocator,TDefaultMapKeyFuncs<int,double,0> > & PreventOfflinePvPLiveTimesField() { static NativeFieldOffset f{ "AShooterGameState.PreventOfflinePvPLiveTimes" }; return *GetNativePointerField<TMap<int,double,FDefaultSetAllocator,TDefaultMapKeyFuncs<int,double,0> >*>(this, f); }
	TMap<int,double,FDefaultSetAllocator,TDefaultMapKeyFuncs<int,double,0> > & PreventOfflinePvPFirstLiveTimeField() { static NativeFieldOffset f{ "AShooterGameState.PreventOfflinePvPFirstLiveTime" }; return *GetNativePointerField<TMap<int,double,FDefaultSetAllocator,TDefaultMapKeyFuncs<int,double,0> >*>(this, f); }
	bool& bAllowAnyoneBabyImprintCuddleField() { static NativeFieldOffset f{ "AShooterGameState.bAllowAnyoneBabyImprintCuddle" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableImprintDinoBuffField() { static NativeFieldOffset f{ "AShooterGameState.bDisableImprintDinoBuff" }; return *GetNativePointerField<bool*>(this, f); }
	int& MaxPersonalTamedDinosField() { static NativeFieldOffset f{ "AShooterGameState.MaxPersonalTamedDinos" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FFloatingTextEntry> & FloatingTextEntriesField() { static NativeFieldOffset f{ "AShooterGameState.FloatingTextEntries" }; return *GetNativePointerField<TArray<FFloatingTextEntry>*>(this, f); }
	bool& bIsCustomMapField() { static NativeFieldOffset f{ "AShooterGameState.bIsCustomMap" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsClientField() { static NativeFieldOffset f{ "AShooterGameState.bIsClient" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsDedicatedServerField() { static NativeFieldOffset f{ "AShooterGameState.bIsDedicatedServer" }; return *GetNativePointerField<bool*>(this, f); }
	FString & ClusterIdField() { static NativeFieldOffset f{ "AShooterGameState.ClusterId" }; return *GetNativePointerField<FString*>(this, f); }
	FString & AmazonS3AccessKeyIDField() { static NativeFieldOffset f{ "AShooterGameState.AmazonS3AccessKeyID" }; return *GetNativePointerField<FString*>(this, f); }
	FString & AmazonS3SecretAccessKeyField() { static NativeFieldOffset f{ "AShooterGameState.AmazonS3SecretAccessKey" }; return *GetNativePointerField<FString*>(this, f); }
	FString & AmazonS3BucketNameField() { static NativeFieldOffset f{ "AShooterGameState.AmazonS3BucketName" }; return *GetNativePointerField<FString*>(this, f); }
	FString & ServerSessionNameField() { static NativeFieldOffset f{ "AShooterGameState.ServerSessionName" }; return *GetNativePointerField<FString*>(this, f); }
	bool& bPreventTribeAlliancesField() { static NativeFieldOffset f{ "AShooterGameState.bPreventTribeAlliances" }; return *GetNativePointerField<bool*>(this, f); }
	FString & LoadForceRespawnDinosTagField() { static NativeFieldOffset f{ "AShooterGameState.LoadForceRespawnDinosTag" }; return *GetNativePointerField<FString*>(this, f); }
	bool& bOnlyDecayUnsnappedCoreStructuresField() { static NativeFieldOffset f{ "AShooterGameState.bOnlyDecayUnsnappedCoreStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bFastDecayUnsnappedCoreStructuresField() { static NativeFieldOffset f{ "AShooterGameState.bFastDecayUnsnappedCoreStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerUseDinoListField() { static NativeFieldOffset f{ "AShooterGameState.bServerUseDinoList" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEAllowStructuresAtSupplyDropsField() { static NativeFieldOffset f{ "AShooterGameState.bPvEAllowStructuresAtSupplyDrops" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowForceNetUpdateField() { static NativeFieldOffset f{ "AShooterGameState.bAllowForceNetUpdate" }; return *GetNativePointerField<bool*>(this, f); }
	float& MinimumDinoReuploadIntervalField() { static NativeFieldOffset f{ "AShooterGameState.MinimumDinoReuploadInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& HairGrowthSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.HairGrowthSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& FastDecayIntervalField() { static NativeFieldOffset f{ "AShooterGameState.FastDecayInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& OxygenSwimSpeedStatMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.OxygenSwimSpeedStatMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FOnHTTPGetProcessed & OnHTTPGetResponseField() { static NativeFieldOffset f{ "AShooterGameState.OnHTTPGetResponse" }; return *GetNativePointerField<FOnHTTPGetProcessed*>(this, f); }
	FOnHTTPPostResponse & OnHTTPPostResponseField() { static NativeFieldOffset f{ "AShooterGameState.OnHTTPPostResponse" }; return *GetNativePointerField<FOnHTTPPostResponse*>(this, f); }
	bool& bAllowMultipleAttachedC4Field() { static NativeFieldOffset f{ "AShooterGameState.bAllowMultipleAttachedC4" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bCrossARKAllowForeignDinoDownloadsField() { static NativeFieldOffset f{ "AShooterGameState.bCrossARKAllowForeignDinoDownloads" }; return *GetNativePointerField<bool*>(this, f); }
	long double& LastPlayedDynamicMusic1Field() { static NativeFieldOffset f{ "AShooterGameState.LastPlayedDynamicMusic1" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastPlayedDynamicMusic2Field() { static NativeFieldOffset f{ "AShooterGameState.LastPlayedDynamicMusic2" }; return *GetNativePointerField<long double*>(this, f); }
	bool& bUseCorpseLocatorField() { static NativeFieldOffset f{ "AShooterGameState.bUseCorpseLocator" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableStructurePlacementCollisionField() { static NativeFieldOffset f{ "AShooterGameState.bDisableStructurePlacementCollision" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bUseSingleplayerSettingsField() { static NativeFieldOffset f{ "AShooterGameState.bUseSingleplayerSettings" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowPlatformSaddleMultiFloorsField() { static NativeFieldOffset f{ "AShooterGameState.bAllowPlatformSaddleMultiFloors" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventSpawnAnimationsField() { static NativeFieldOffset f{ "AShooterGameState.bPreventSpawnAnimations" }; return *GetNativePointerField<bool*>(this, f); }
	int& MaxAlliancesPerTribeField() { static NativeFieldOffset f{ "AShooterGameState.MaxAlliancesPerTribe" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxTribesPerAllianceField() { static NativeFieldOffset f{ "AShooterGameState.MaxTribesPerAlliance" }; return *GetNativePointerField<int*>(this, f); }
	bool& bIsLegacyServerField() { static NativeFieldOffset f{ "AShooterGameState.bIsLegacyServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableDinoDecayClaimingField() { static NativeFieldOffset f{ "AShooterGameState.bDisableDinoDecayClaiming" }; return *GetNativePointerField<bool*>(this, f); }
	FName & UseStructurePreventionVolumeTagField() { static NativeFieldOffset f{ "AShooterGameState.UseStructurePreventionVolumeTag" }; return *GetNativePointerField<FName*>(this, f); }
	int& MaxStructuresInSmallRadiusField() { static NativeFieldOffset f{ "AShooterGameState.MaxStructuresInSmallRadius" }; return *GetNativePointerField<int*>(this, f); }
	float& RadiusStructuresInSmallRadiusField() { static NativeFieldOffset f{ "AShooterGameState.RadiusStructuresInSmallRadius" }; return *GetNativePointerField<float*>(this, f); }
	bool& bUseTameLimitForStructuresOnlyField() { static NativeFieldOffset f{ "AShooterGameState.bUseTameLimitForStructuresOnly" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bLimitTurretsInRangeField() { static NativeFieldOffset f{ "AShooterGameState.bLimitTurretsInRange" }; return *GetNativePointerField<bool*>(this, f); }
	float& LimitTurretsRangeField() { static NativeFieldOffset f{ "AShooterGameState.LimitTurretsRange" }; return *GetNativePointerField<float*>(this, f); }
	int& LimitTurretsNumField() { static NativeFieldOffset f{ "AShooterGameState.LimitTurretsNum" }; return *GetNativePointerField<int*>(this, f); }
	bool& bForceAllowAllStructuresField() { static NativeFieldOffset f{ "AShooterGameState.bForceAllowAllStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bShowCreativeModeField() { static NativeFieldOffset f{ "AShooterGameState.bShowCreativeMode" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FPlayerLocatorEffectMap> & PlayerLocatorEffectMapsField() { static NativeFieldOffset f{ "AShooterGameState.PlayerLocatorEffectMaps" }; return *GetNativePointerField<TArray<FPlayerLocatorEffectMap>*>(this, f); }
	int& AmbientSoundCheckIncrementField() { static NativeFieldOffset f{ "AShooterGameState.AmbientSoundCheckIncrement" }; return *GetNativePointerField<int*>(this, f); }
	int& ThrottledTicksModField() { static NativeFieldOffset f{ "AShooterGameState.ThrottledTicksMod" }; return *GetNativePointerField<int*>(this, f); }
	int& PerformanceThrottledTicksModField() { static NativeFieldOffset f{ "AShooterGameState.PerformanceThrottledTicksMod" }; return *GetNativePointerField<int*>(this, f); }
	float& PreventOfflinePvPConnectionInvincibleIntervalField() { static NativeFieldOffset f{ "AShooterGameState.PreventOfflinePvPConnectionInvincibleInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& PassiveTameIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameState.PassiveTameIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TSubclassOf<APrimalDinoCharacter>> & UniqueDinosField() { static NativeFieldOffset f{ "AShooterGameState.UniqueDinos" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalDinoCharacter>>*>(this, f); }
	unsigned int& MinimumUniqueDownloadIntervalField() { static NativeFieldOffset f{ "AShooterGameState.MinimumUniqueDownloadInterval" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& MaximumUniqueDownloadIntervalField() { static NativeFieldOffset f{ "AShooterGameState.MaximumUniqueDownloadInterval" }; return *GetNativePointerField<unsigned int*>(this, f); }
	bool& bIgnoreStructuresPreventionVolumesField() { static NativeFieldOffset f{ "AShooterGameState.bIgnoreStructuresPreventionVolumes" }; return *GetNativePointerField<bool*>(this, f); }
	UPrimalWorldSettingsEventOverrides * ActiveEventOverridesField() { static NativeFieldOffset f{ "AShooterGameState.ActiveEventOverrides" }; return *GetNativePointerField<UPrimalWorldSettingsEventOverrides**>(this, f); }
	bool& bIgnoreLimitMaxStructuresInRangeTypeFlagField() { static NativeFieldOffset f{ "AShooterGameState.bIgnoreLimitMaxStructuresInRangeTypeFlag" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FMassTeleportData> & MassTeleportQueueField() { static NativeFieldOffset f{ "AShooterGameState.MassTeleportQueue" }; return *GetNativePointerField<TArray<FMassTeleportData>*>(this, f); }
	TArray<AActor*>& MassTeleportQueueToRemoveField() { static NativeFieldOffset f{ "AShooterGameState.MassTeleportQueueToRemove" }; return *GetNativePointerField<TArray<AActor*>*>(this, f); }
	TArray<FMassTeleportData> & MassTeleportQueueToAddField() { static NativeFieldOffset f{ "AShooterGameState.MassTeleportQueueToAdd" }; return *GetNativePointerField<TArray<FMassTeleportData>*>(this, f); }
	bool& bAllowLowGravitySpinField() { static NativeFieldOffset f{ "AShooterGameState.bAllowLowGravitySpin" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FName> & BiomeBuffTagsField() { static NativeFieldOffset f{ "AShooterGameState.BiomeBuffTags" }; return *GetNativePointerField<TArray<FName>*>(this, f); }

	// Functions

	static UClass * StaticClass() { static NativeStaticClass f{ "AShooterGameState.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	UObject * GetUObjectInterfaceHUDInterface() { static NativeFunction f{ "AShooterGameState.GetUObjectInterfaceHUDInterface" }; return NativeCall<UObject*>(this, f); }
	static void BaseDrawTileOnCanvas(AShooterHUD * HUD, UTexture * Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, FColor DrawColor) { static NativeFunction f{ "AShooterGameState.BaseDrawTileOnCanvas" }; NativeCall<void, AShooterHUD*, UTexture*, float, float, float, float, float, float, float, float, FColor>(nullptr, f, HUD, Tex, X, Y, XL, YL, U, V, UL, VL, DrawColor); }
	static APrimalBuff * BaseSpawnBuffAndAttachToCharacter(UClass * Buff, APrimalCharacter * PrimalCharacter, float ExperiencePoints) { static NativeFunction f{ "AShooterGameState.BaseSpawnBuffAndAttachToCharacter" }; return NativeCall<APrimalBuff*, UClass*, APrimalCharacter*, float>(nullptr, f, Buff, PrimalCharacter, ExperiencePoints); }
	void Destroyed() { static NativeFunction f{ "AShooterGameState.Destroyed" }; NativeCall<void>(this, f); }
	bool IsClusterServer() { static NativeFunction f{ "AShooterGameState.IsClusterServer" }; return NativeCall<bool>(this, f); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { static NativeFunction f{ "AShooterGameState.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	bool GetItemMaxQuantityOverride(TSubclassOf<UPrimalItem> ForClass, FMaxItemQuantityOverride * OutMaxQuantity) { static NativeFunction f{ "AShooterGameState.GetItemMaxQuantityOverride" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, FMaxItemQuantityOverride*>(this, f, ForClass, OutMaxQuantity); }
	void OnRep_SupportedSpawnRegions() { static NativeFunction f{ "AShooterGameState.OnRep_SupportedSpawnRegions" }; NativeCall<void>(this, f); }
	void OnRep_ReplicateLocalizedChatRadius() { static NativeFunction f{ "AShooterGameState.OnRep_ReplicateLocalizedChatRadius" }; NativeCall<void>(this, f); }
	void RequestFinishAndExitToMainMenu() { static NativeFunction f{ "AShooterGameState.RequestFinishAndExitToMainMenu" }; NativeCall<void>(this, f); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "AShooterGameState.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	FVector * GetLocalPlayerLocation(FVector * result) { static NativeFunction f{ "AShooterGameState.GetLocalPlayerLocation" }; return NativeCall<FVector*, FVector*>(this, f, result); }
	float GetServerFramerate() { static NativeFunction f{ "AShooterGameState.GetServerFramerate" }; return NativeCall<float>(this, f); }
	void UpdateDynamicMusic(float DeltaSeconds) { static NativeFunction f{ "AShooterGameState.UpdateDynamicMusic" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void CreateCustomGameUI(AShooterPlayerController * SceneOwner) { static NativeFunction f{ "AShooterGameState.CreateCustomGameUI" }; NativeCall<void, AShooterPlayerController*>(this, f, SceneOwner); }
	void DrawHUD(AShooterHUD * HUD) { static NativeFunction f{ "AShooterGameState.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	void PostInitializeComponents() { static NativeFunction f{ "AShooterGameState.PostInitializeComponents" }; NativeCall<void>(this, f); }
	void UpdateFunctionExpense(int FunctionType) { static NativeFunction f{ "AShooterGameState.UpdateFunctionExpense" }; NativeCall<void, int>(this, f, FunctionType); }
	float GetClientReplicationRateFor(UNetConnection * InConnection, AActor * InActor) { static NativeFunction f{ "AShooterGameState.GetClientReplicationRateFor" }; return NativeCall<float, UNetConnection*, AActor*>(this, f, InConnection, InActor); }
	static long double GetNetworkTimeDelta(AShooterGameState * gameState, long double netTime, bool bTimeUntil) { static NativeFunction f{ "AShooterGameState.GetNetworkTimeDelta" }; return NativeCall<long double, AShooterGameState*, long double, bool>(nullptr, f, gameState, netTime, bTimeUntil); }
	void LoadedFromSaveGame() { static NativeFunction f{ "AShooterGameState.LoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void Serialize(FArchive * Ar) { static NativeFunction f{ "AShooterGameState.Serialize" }; NativeCall<void, FArchive*>(this, f, Ar); }
	void BeginPlay() { static NativeFunction f{ "AShooterGameState.BeginPlay" }; NativeCall<void>(this, f); }
	float GetMatineePlayRate(AActor * forMatineeActor) { static NativeFunction f{ "AShooterGameState.GetMatineePlayRate" }; return NativeCall<float, AActor*>(this, f, forMatineeActor); }
	void NotifyPlayerDied(AShooterCharacter * theShooterChar, AShooterPlayerController * prevController, APawn * InstigatingPawn, AActor * DamageCauser) { static NativeFunction f{ "AShooterGameState.NotifyPlayerDied" }; NativeCall<void, AShooterCharacter*, AShooterPlayerController*, APawn*, AActor*>(this, f, theShooterChar, prevController, InstigatingPawn, DamageCauser); }
	bool AllowDinoTame(APrimalDinoCharacter * DinoChar, AShooterPlayerController * ForPC) { static NativeFunction f{ "AShooterGameState.AllowDinoTame" }; return NativeCall<bool, APrimalDinoCharacter*, AShooterPlayerController*>(this, f, DinoChar, ForPC); }
	bool AllowDinoClassTame(TSubclassOf<APrimalDinoCharacter> DinoCharClass, AShooterPlayerController * ForPC) { static NativeFunction f{ "AShooterGameState.AllowDinoClassTame" }; return NativeCall<bool, TSubclassOf<APrimalDinoCharacter>, AShooterPlayerController*>(this, f, DinoCharClass, ForPC); }
	FString * GetDayTimeString(FString * result) { static NativeFunction f{ "AShooterGameState.GetDayTimeString" }; return NativeCall<FString*, FString*>(this, f, result); }
	TArray<AShooterPlayerController*> * BaseGetAllShooterControllers(TArray<AShooterPlayerController*> * result) { static NativeFunction f{ "AShooterGameState.BaseGetAllShooterControllers" }; return NativeCall<TArray<AShooterPlayerController*>*, TArray<AShooterPlayerController*>*>(this, f, result); }
	TArray<AShooterCharacter*> * BaseGetAllShooterCharactersOfTeam(TArray<AShooterCharacter*> * result, int Team) { static NativeFunction f{ "AShooterGameState.BaseGetAllShooterCharactersOfTeam" }; return NativeCall<TArray<AShooterCharacter*>*, TArray<AShooterCharacter*>*, int>(this, f, result, Team); }
	TArray<AShooterCharacter*> * BaseGetAllShooterCharacters(TArray<AShooterCharacter*> * result) { static NativeFunction f{ "AShooterGameState.BaseGetAllShooterCharacters" }; return NativeCall<TArray<AShooterCharacter*>*, TArray<AShooterCharacter*>*>(this, f, result); }
	TArray<APrimalDinoCharacter*> * BaseGetAllDinoCharactersOfTeam(TArray<APrimalDinoCharacter*> * result, int Team) { static NativeFunction f{ "AShooterGameState.BaseGetAllDinoCharactersOfTeam" }; return NativeCall<TArray<APrimalDinoCharacter*>*, TArray<APrimalDinoCharacter*>*, int>(this, f, result, Team); }
	void InitializedGameState() { static NativeFunction f{ "AShooterGameState.InitializedGameState" }; NativeCall<void>(this, f); }
	bool IsTeamIDInvincible(int TargetingTeamID, bool bInvincibleOnlyWhenOffline) { static NativeFunction f{ "AShooterGameState.IsTeamIDInvincible" }; return NativeCall<bool, int, bool>(this, f, TargetingTeamID, bInvincibleOnlyWhenOffline); }
	long double GetOfflineDamagePreventionTime(int TargetingTeamID) { static NativeFunction f{ "AShooterGameState.GetOfflineDamagePreventionTime" }; return NativeCall<long double, int>(this, f, TargetingTeamID); }
	void NetUpdateOfflinePvPLiveTeams_Implementation(TArray<int> * NewPreventOfflinePvPLiveTeams) { static NativeFunction f{ "AShooterGameState.NetUpdateOfflinePvPLiveTeams_Implementation" }; NativeCall<void, TArray<int>*>(this, f, NewPreventOfflinePvPLiveTeams); }
	void NetUpdateOfflinePvPExpiringTeams_Implementation(TArray<int> * NewPreventOfflinePvPExpiringTeams, TArray<double> * NewPreventOfflinePvPExpiringTimes) { static NativeFunction f{ "AShooterGameState.NetUpdateOfflinePvPExpiringTeams_Implementation" }; NativeCall<void, TArray<int>*, TArray<double>*>(this, f, NewPreventOfflinePvPExpiringTeams, NewPreventOfflinePvPExpiringTimes); }
	void UpdatePreventOfflinePvPStatus() { static NativeFunction f{ "AShooterGameState.UpdatePreventOfflinePvPStatus" }; NativeCall<void>(this, f); }
	void AddFloatingText(FVector AtLocation, FString FloatingTextString, FColor FloatingTextColor, float ScaleX, float ScaleY, float TextLifeSpan, FVector TextVelocity, float MinScale, float FadeInTime, float FadeOutTime) { static NativeFunction f{ "AShooterGameState.AddFloatingText" }; NativeCall<void, FVector, FString, FColor, float, float, float, FVector, float, float, float>(this, f, AtLocation, FloatingTextString, FloatingTextColor, ScaleX, ScaleY, TextLifeSpan, TextVelocity, MinScale, FadeInTime, FadeOutTime); }
	void AddFloatingDamageText(FVector AtLocation, int DamageAmount, int FromTeamID) { static NativeFunction f{ "AShooterGameState.AddFloatingDamageText" }; NativeCall<void, FVector, int, int>(this, f, AtLocation, DamageAmount, FromTeamID); }
	void NetAddFloatingDamageText(FVector AtLocation, int DamageAmount, int FromTeamID, int OnlySendToTeamID) { static NativeFunction f{ "AShooterGameState.NetAddFloatingDamageText" }; NativeCall<void, FVector, int, int, int>(this, f, AtLocation, DamageAmount, FromTeamID, OnlySendToTeamID); }
	void NetAddFloatingText(FVector AtLocation, FString FloatingTextString, FColor FloatingTextColor, float ScaleX, float ScaleY, float TextLifeSpan, FVector TextVelocity, float MinScale, float FadeInTime, float FadeOutTime, int OnlySendToTeamID) { static NativeFunction f{ "AShooterGameState.NetAddFloatingText" }; NativeCall<void, FVector, FString, FColor, float, float, float, FVector, float, float, float, int>(this, f, AtLocation, FloatingTextString, FloatingTextColor, ScaleX, ScaleY, TextLifeSpan, TextVelocity, MinScale, FadeInTime, FadeOutTime, OnlySendToTeamID); }
	FString * GetCleanServerSessionName(FString * result) { static NativeFunction f{ "AShooterGameState.GetCleanServerSessionName" }; return NativeCall<FString*, FString*>(this, f, result); }
	void ForceNetUpdate(bool bDormantDontReplicateProperties, bool bAbsoluteForceNetUpdate, bool bDontUpdateChannel) { static NativeFunction f{ "AShooterGameState.ForceNetUpdate" }; NativeCall<void, bool, bool, bool>(this, f, bDormantDontReplicateProperties, bAbsoluteForceNetUpdate, bDontUpdateChannel); }
	void WorldCompositionRescan() { static NativeFunction f{ "AShooterGameState.WorldCompositionRescan" }; NativeCall<void>(this, f); }
	void HTTPGetRequest(FString InURL) { static NativeFunction f{ "AShooterGameState.HTTPGetRequest" }; NativeCall<void, FString>(this, f, InURL); }
	void HTTPGetRequestCompleted(TSharedPtr<IHttpRequest,0> HttpRequest, TSharedPtr<IHttpResponse,1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameState.HTTPGetRequestCompleted" }; NativeCall<void, TSharedPtr<IHttpRequest,0>, TSharedPtr<IHttpResponse,1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	void HTTPPostRequest(FString InURL, FString Content) { static NativeFunction f{ "AShooterGameState.HTTPPostRequest" }; NativeCall<void, FString, FString>(this, f, InURL, Content); }
	void HTTPPostRequestCompleted(TSharedPtr<IHttpRequest,0> HttpRequest, TSharedPtr<IHttpResponse,1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameState.HTTPPostRequestCompleted" }; NativeCall<void, TSharedPtr<IHttpRequest,0>, TSharedPtr<IHttpResponse,1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	void LevelAddedToWorld(ULevel * addedLevel) { static NativeFunction f{ "AShooterGameState.LevelAddedToWorld" }; NativeCall<void, ULevel*>(this, f, addedLevel); }
	TArray<FGameIniData> * GetIniArray(TArray<FGameIniData> * result, FString SectionName) { static NativeFunction f{ "AShooterGameState.GetIniArray" }; return NativeCall<TArray<FGameIniData>*, TArray<FGameIniData>*, FString>(this, f, result, SectionName); }
	bool AllowDownloadDino_Implementation(TSubclassOf<APrimalDinoCharacter> TheDinoClass) { static NativeFunction f{ "AShooterGameState.AllowDownloadDino_Implementation" }; return NativeCall<bool, TSubclassOf<APrimalDinoCharacter>>(this, f, TheDinoClass); }
	void DinoDownloaded(TSubclassOf<APrimalDinoCharacter> TheDinoClass) { static NativeFunction f{ "AShooterGameState.DinoDownloaded" }; NativeCall<void, TSubclassOf<APrimalDinoCharacter>>(this, f, TheDinoClass); }
	bool IsEngramClassHidden(TSubclassOf<UPrimalItem> ForItemClass) { static NativeFunction f{ "AShooterGameState.IsEngramClassHidden" }; return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, f, ForItemClass); }
	void Multi_SpawnCosmeticActor_Implementation(TSubclassOf<AActor> SpawnActorOfClass, FVector SpawnAtLocation, FRotator SpawnWithRotation) { static NativeFunction f{ "AShooterGameState.Multi_SpawnCosmeticActor_Implementation" }; NativeCall<void, TSubclassOf<AActor>, FVector, FRotator>(this, f, SpawnActorOfClass, SpawnAtLocation, SpawnWithRotation); }
	bool StartMassTeleport(FMassTeleportData * NewMassTeleportData, FTeleportDestination * TeleportDestination, AActor * InitiatingActor, TArray<AActor*> TeleportActors, TSubclassOf<APrimalBuff> BuffToApply, const float TeleportDuration, const float TeleportRadius, const bool bTeleportingSnapsToGround, const bool bMaintainRotation) { static NativeFunction f{ "AShooterGameState.StartMassTeleport" }; return NativeCall<bool, FMassTeleportData*, FTeleportDestination*, AActor*, TArray<AActor*>, TSubclassOf<APrimalBuff>, const float, const float, const bool, const bool>(this, f, NewMassTeleportData, TeleportDestination, InitiatingActor, TeleportActors, BuffToApply, TeleportDuration, TeleportRadius, bTeleportingSnapsToGround, bMaintainRotation); }
	bool CancelMassTeleport(AActor * WithInitiatingActor) { static NativeFunction f{ "AShooterGameState.CancelMassTeleport" }; return NativeCall<bool, AActor*>(this, f, WithInitiatingActor); }
	bool ShouldMassTeleportMoveActor(AActor * ForActor, FMassTeleportData * WithMassTeleportData) { static NativeFunction f{ "AShooterGameState.ShouldMassTeleportMoveActor" }; return NativeCall<bool, AActor*, FMassTeleportData*>(this, f, ForActor, WithMassTeleportData); }
	void Tick_MassTeleport(float DeltaTime) { static NativeFunction f{ "AShooterGameState.Tick_MassTeleport" }; NativeCall<void, float>(this, f, DeltaTime); }
	void RemoveIrrelevantBiomeBuffs(APrimalCharacter * PrimalChar) { static NativeFunction f{ "AShooterGameState.RemoveIrrelevantBiomeBuffs" }; NativeCall<void, APrimalCharacter*>(this, f, PrimalChar); }
	static bool IsValidMassTeleportData(FMassTeleportData * CheckData) { static NativeFunction f{ "AShooterGameState.IsValidMassTeleportData" }; return NativeCall<bool, FMassTeleportData*>(nullptr, f, CheckData); }
	void PrepareActorForMassTeleport(AActor * PrepareActor, FMassTeleportData * WithMassTeleportData) { static NativeFunction f{ "AShooterGameState.PrepareActorForMassTeleport" }; NativeCall<void, AActor*, FMassTeleportData*>(this, f, PrepareActor, WithMassTeleportData); }
	void ApplyLiveTuningOverloads(TSharedPtr<FJsonObject, 0> Overloads) { static NativeFunction f{ "AShooterGameState.ApplyLiveTuningOverloads" }; NativeCall<void, TSharedPtr<FJsonObject, 0>>(this, f, Overloads); }
	void ResetLiveTuningOverloads() { static NativeFunction f{ "AShooterGameState.ResetLiveTuningOverloads" }; NativeCall<void>(this, f); }
	static FString* GetLiveTuningOverloadsDirectory(FString* result, bool bEnsureDirectoryExists) { static NativeFunction f{ "AShooterGameState.GetLiveTuningOverloadsDirectory" }; return NativeCall<FString*, FString*, bool>(nullptr, f, result, bEnsureDirectoryExists); }
	static bool IsSupportedLiveTuningProperty(UProperty* Property, bool bIgnoreLiveTuningFlag) { static NativeFunction f{ "AShooterGameState.IsSupportedLiveTuningProperty" }; return NativeCall<bool, UProperty*, bool>(nullptr, f, Property, bIgnoreLiveTuningFlag); }
	static void StaticRegisterNativesAShooterGameState() { static NativeFunction f{ "AShooterGameState.StaticRegisterNativesAShooterGameState" }; NativeCall<void>(nullptr, f); }
	static UClass * GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "AShooterGameState.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	bool AllowDownloadDino(TSubclassOf<APrimalDinoCharacter> TheDinoClass) { static NativeFunction f{ "AShooterGameState.AllowDownloadDino" }; return NativeCall<bool, TSubclassOf<APrimalDinoCharacter>>(this, f, TheDinoClass); }
	void NetUpdateOfflinePvPExpiringTeams(TArray<int> * NewPreventOfflinePvPExpiringTeams, TArray<double> * NewPreventOfflinePvPExpiringTimes) { static NativeFunction f{ "AShooterGameState.NetUpdateOfflinePvPExpiringTeams" }; NativeCall<void, TArray<int>*, TArray<double>*>(this, f, NewPreventOfflinePvPExpiringTeams, NewPreventOfflinePvPExpiringTimes); }
	void NetUpdateOfflinePvPLiveTeams(TArray<int> * NewPreventOfflinePvPLiveTeams) { static NativeFunction f{ "AShooterGameState.NetUpdateOfflinePvPLiveTeams" }; NativeCall<void, TArray<int>*>(this, f, NewPreventOfflinePvPLiveTeams); }
};

struct AGameSession 
{
	int& MaxSpectatorsField() { static NativeFieldOffset f{ "AGameSession.MaxSpectators" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxPlayersField() { static NativeFieldOffset f{ "AGameSession.MaxPlayers" }; return *GetNativePointerField<int*>(this, f); }
	unsigned char& MaxSplitscreensPerConnectionField() { static NativeFieldOffset f{ "AGameSession.MaxSplitscreensPerConnection" }; return *GetNativePointerField<unsigned char*>(this, f); }
	bool& bRequiresPushToTalkField() { static NativeFieldOffset f{ "AGameSession.bRequiresPushToTalk" }; return *GetNativePointerField<bool*>(this, f); }
	FName& SessionNameField() { static NativeFieldOffset f{ "AGameSession.SessionName" }; return *GetNativePointerField<FName*>(this, f); }

	// Functions

	bool RequiresPushToTalk() { static NativeFunction f{ "AGameSession.RequiresPushToTalk" }; return NativeCall<bool>(this, f); }
	void InitOptions(FString* Options) { static NativeFunction f{ "AGameSession.InitOptions" }; NativeCall<void, FString*>(this, f, Options); }
	bool ProcessAutoLogin() { static NativeFunction f{ "AGameSession.ProcessAutoLogin" }; return NativeCall<bool>(this, f); }
	void OnLoginComplete(int LocalUserNum, bool bWasSuccessful, FUniqueNetId* UserId, FString* Error) { static NativeFunction f{ "AGameSession.OnLoginComplete" }; NativeCall<void, int, bool, FUniqueNetId*, FString*>(this, f, LocalUserNum, bWasSuccessful, UserId, Error); }
	FString* ApproveLogin(FString* result, FString* Options, FString* authToken, UNetConnection* Connection = nullptr) { static NativeFunction f{ "AGameSession.ApproveLogin" }; return NativeCall<FString*, FString*, FString*, FString*, UNetConnection*>(this, f, result, Options, authToken, Connection); }
	void RegisterPlayer(APlayerController* NewPlayer, TSharedPtr<FUniqueNetId, 0>* UniqueId, bool bWasFromInvite) { static NativeFunction f{ "AGameSession.RegisterPlayer" }; NativeCall<void, APlayerController*, TSharedPtr<FUniqueNetId, 0>*, bool>(this, f, NewPlayer, UniqueId, bWasFromInvite); }
	void UnregisterPlayer(APlayerController* ExitingPlayer) { static NativeFunction f{ "AGameSession.UnregisterPlayer" }; NativeCall<void, APlayerController*>(this, f, ExitingPlayer); }
	bool AtCapacity(bool bSpectator, FString* AuthToken, UNetConnection* Connection = nullptr) { static NativeFunction f{ "AGameSession.AtCapacity" }; return NativeCall<bool, bool, FString*, UNetConnection*>(this, f, bSpectator, AuthToken, Connection); }
	void NotifyLogout(APlayerController* PC) { static NativeFunction f{ "AGameSession.NotifyLogout" }; NativeCall<void, APlayerController*>(this, f, PC); }
	bool KickPlayer(APlayerController* KickedPlayer, FText* KickReason) { static NativeFunction f{ "AGameSession.KickPlayer" }; return NativeCall<bool, APlayerController*, FText*>(this, f, KickedPlayer, KickReason); }
	bool BanPlayer(APlayerController* BannedPlayer, FText* BanReason) { static NativeFunction f{ "AGameSession.BanPlayer" }; return NativeCall<bool, APlayerController*, FText*>(this, f, BannedPlayer, BanReason); }
	[[deprecated("not in this game build, use BanPlayer(BannedPlayer, BanReason)")]] void BanPlayer() { ReportDeprecatedApiUse("AGameSession.BanPlayer()"); }
	void ReturnToMainMenuHost() { static NativeFunction f{ "AGameSession.ReturnToMainMenuHost" }; NativeCall<void>(this, f); }
	bool TravelToSession(int ControllerId, FName InSessionName) { static NativeFunction f{ "AGameSession.TravelToSession" }; return NativeCall<bool, int, FName>(this, f, ControllerId, InSessionName); }
	void UpdateSessionJoinability(FName InSessionName, bool bPublicSearchable, bool bAllowInvites, bool bJoinViaPresence, bool bJoinViaPresenceFriendsOnly) { static NativeFunction f{ "AGameSession.UpdateSessionJoinability" }; NativeCall<void, FName, bool, bool, bool, bool>(this, f, InSessionName, bPublicSearchable, bAllowInvites, bJoinViaPresence, bJoinViaPresenceFriendsOnly); }
};

struct AShooterGameSession : AGameSession
{
	TArray<FInstalledItemInfo>& CachedModsField() { static NativeFieldOffset f{ "AShooterGameSession.CachedMods" }; return *GetNativePointerField<TArray<FInstalledItemInfo>*>(this, f); }
	TArray<FShooterSessionData>& ThreadSafeSearchResultsField() { static NativeFieldOffset f{ "AShooterGameSession.ThreadSafeSearchResults" }; return *GetNativePointerField<TArray<FShooterSessionData>*>(this, f); }
	TArray<UNetConnection*>& FailedAuthTokenClientConnectionsField() { static NativeFieldOffset f{ "AShooterGameSession.FailedAuthTokenClientConnections" }; return *GetNativePointerField<TArray<UNetConnection*>*>(this, f); }
	TArray<FUniqueNetIdUInt64>& FailedAuthTokenClientUniqueIDsField() { static NativeFieldOffset f{ "AShooterGameSession.FailedAuthTokenClientUniqueIDs" }; return *GetNativePointerField<TArray<FUniqueNetIdUInt64>*>(this, f); }
	FShooterGameSessionParams& CurrentSessionParamsField() { static NativeFieldOffset f{ "AShooterGameSession.CurrentSessionParams" }; return *GetNativePointerField<FShooterGameSessionParams*>(this, f); }
	TSharedPtr<FShooterOnlineSessionSettings, 0>& HostSettingsField() { static NativeFieldOffset f{ "AShooterGameSession.HostSettings" }; return *GetNativePointerField<TSharedPtr<FShooterOnlineSessionSettings, 0>*>(this, f); }
	TSharedPtr<FShooterOnlineSearchSettings, 0>& SearchSettingsField() { static NativeFieldOffset f{ "AShooterGameSession.SearchSettings" }; return *GetNativePointerField<TSharedPtr<FShooterOnlineSearchSettings, 0>*>(this, f); }
	bool& bFoundSessionField() { static NativeFieldOffset f{ "AShooterGameSession.bFoundSession" }; return *GetNativePointerField<bool*>(this, f); }

	// Functions

	static UClass* StaticClass() { static NativeStaticClass f{ "AShooterGameSession.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful) { static NativeFunction f{ "AShooterGameSession.OnStartOnlineGameComplete" }; NativeCall<void, FName, bool>(this, f, SessionName, bWasSuccessful); }
	void HandleMatchHasStarted() { static NativeFunction f{ "AShooterGameSession.HandleMatchHasStarted" }; NativeCall<void>(this, f); }
	void HandleMatchHasEnded() { static NativeFunction f{ "AShooterGameSession.HandleMatchHasEnded" }; NativeCall<void>(this, f); }
	TArray<FOnlineSessionSearchResult>* GetSearchResults() { static NativeFunction f{ "AShooterGameSession.GetSearchResults" }; return NativeCall<TArray<FOnlineSessionSearchResult>*>(this, f); }
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful) { static NativeFunction f{ "AShooterGameSession.OnCreateSessionComplete" }; NativeCall<void, FName, bool>(this, f, SessionName, bWasSuccessful); }
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful) { static NativeFunction f{ "AShooterGameSession.OnDestroySessionComplete" }; NativeCall<void, FName, bool>(this, f, SessionName, bWasSuccessful); }
	void DelayedSessionDelete() { static NativeFunction f{ "AShooterGameSession.DelayedSessionDelete" }; NativeCall<void>(this, f); }
	void InitOptions(FString* Options) { static NativeFunction f{ "AShooterGameSession.InitOptions" }; NativeCall<void, FString*>(this, f, Options); }
	void RegisterServer() { static NativeFunction f{ "AShooterGameSession.RegisterServer" }; NativeCall<void>(this, f); }
	void UpdatePublishedSession() { static NativeFunction f{ "AShooterGameSession.UpdatePublishedSession" }; NativeCall<void>(this, f); }
	FString* ApproveLogin(FString* result, FString* Options, FString* authToken, UNetConnection* Connection = nullptr) { static NativeFunction f{ "AShooterGameSession.ApproveLogin" }; return NativeCall<FString*, FString*, FString*, FString*, UNetConnection*>(this, f, result, Options, authToken, Connection); }
	void OnCheckAuthTokenComplete(bool bWasSuccessful, FUniqueNetId* UserId) { static NativeFunction f{ "AShooterGameSession.OnCheckAuthTokenComplete" }; NativeCall<void, bool, FUniqueNetId*>(this, f, bWasSuccessful, UserId); }
	void OnNumConnectedPlayersChanged(int NewPlayersCount) { static NativeFunction f{ "AShooterGameSession.OnNumConnectedPlayersChanged" }; NativeCall<void, int>(this, f, NewPlayersCount); }
	void Tick(float __formal) { static NativeFunction f{ "AShooterGameSession.Tick" }; NativeCall<void, float>(this, f, __formal); }
	void OnFindSessionsComplete(bool bWasSuccessful) { static NativeFunction f{ "AShooterGameSession.OnFindSessionsComplete(bool)" }; NativeCall<void, bool>(this, f, bWasSuccessful); }
	void OnFoundSession() { static NativeFunction f{ "AShooterGameSession.OnFoundSession" }; NativeCall<void>(this, f); }
	void BroadcastFoundSessionEvent() { static NativeFunction f{ "AShooterGameSession.BroadcastFoundSessionEvent" }; NativeCall<void>(this, f); }
	void CancelFindSessions() { static NativeFunction f{ "AShooterGameSession.CancelFindSessions" }; NativeCall<void>(this, f); }
	bool JoinSession(TSharedPtr<FUniqueNetId, 0> UserId, FName SessionName, int SessionIndexInSearchResults) { static NativeFunction f{ "AShooterGameSession.JoinSession(TSharedPtr<FUniqueNetId,0>,FName,int)" }; return NativeCall<bool, TSharedPtr<FUniqueNetId, 0>, FName, int>(this, f, UserId, SessionName, SessionIndexInSearchResults); }
	bool JoinSession(TSharedPtr<FUniqueNetId, 0> UserId, FName SessionName, FOnlineSessionSearchResult* SearchResult) { static NativeFunction f{ "AShooterGameSession.JoinSession(TSharedPtr<FUniqueNetId,0>,FName,const FOnlineSessionSearchResult&)" }; return NativeCall<bool, TSharedPtr<FUniqueNetId, 0>, FName, FOnlineSessionSearchResult*>(this, f, UserId, SessionName, SearchResult); }
	bool TravelToSession(int ControllerId, FName SessionName) { static NativeFunction f{ "AShooterGameSession.TravelToSession" }; return NativeCall<bool, int, FName>(this, f, ControllerId, SessionName); }
	void Restart() { static NativeFunction f{ "AShooterGameSession.Restart" }; NativeCall<void>(this, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "AShooterGameSession.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
};
