#pragma once

#include "API/UE/UE.h"
#include "API/UE/Containers/Map.h"

#include "Other.h"

struct __declspec(align(8)) FEngramEntryAutoUnlock
{
	FString EngramClassName;
	int LevelToAutoUnlock;
};

struct UGameViewportClient
{
	TArray<UObject *>& ViewPortWidgetsField() { static NativeFieldOffset f{ "UGameViewportClient.ViewPortWidgets" }; return *GetNativePointerField<TArray<UObject *>*>(this, f); }
	int& MaxSplitscreenPlayersField() { static NativeFieldOffset f{ "UGameViewportClient.MaxSplitscreenPlayers" }; return *GetNativePointerField<int*>(this, f); }
	UWorld * WorldField() { static NativeFieldOffset f{ "UGameViewportClient.World" }; return *GetNativePointerField<UWorld **>(this, f); }
	bool& bSuppressTransitionMessageField() { static NativeFieldOffset f{ "UGameViewportClient.bSuppressTransitionMessage" }; return *GetNativePointerField<bool*>(this, f); }
	float& ProgressFadeTimeField() { static NativeFieldOffset f{ "UGameViewportClient.ProgressFadeTime" }; return *GetNativePointerField<float*>(this, f); }
	int& ViewModeIndexField() { static NativeFieldOffset f{ "UGameViewportClient.ViewModeIndex" }; return *GetNativePointerField<int*>(this, f); }
	FName& CurrentBufferVisualizationModeField() { static NativeFieldOffset f{ "UGameViewportClient.CurrentBufferVisualizationMode" }; return *GetNativePointerField<FName*>(this, f); }
	bool& bDisableSplitScreenOverrideField() { static NativeFieldOffset f{ "UGameViewportClient.bDisableSplitScreenOverride" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<bool>& IgnoreInputValuesField() { static NativeFieldOffset f{ "UGameViewportClient.IgnoreInputValues" }; return *GetNativePointerField<TArray<bool>*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bShowTitleSafeZone() { static NativeBitField f{ "UGameViewportClient.bShowTitleSafeZone" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPlayInEditorViewport() { static NativeBitField f{ "UGameViewportClient.bIsPlayInEditorViewport" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisableWorldRendering() { static NativeBitField f{ "UGameViewportClient.bDisableWorldRendering" }; return { this, f }; }

	// Functions

	bool IsStatEnabled(const wchar_t * InName) { static NativeFunction f{ "UGameViewportClient.IsStatEnabled" }; return NativeCall<bool, const wchar_t *>(this, f, InName); }
	void SetEnabledStats(TArray<FString> * InEnabledStats) { static NativeFunction f{ "UGameViewportClient.SetEnabledStats" }; NativeCall<void, TArray<FString> *>(this, f, InEnabledStats); }
	TArray<FString> * GetEnabledStats() { static NativeFunction f{ "UGameViewportClient.GetEnabledStats" }; return NativeCall<TArray<FString> *>(this, f); }
	FGuid * GetEngineShowFlags() { static NativeFunction f{ "UGameViewportClient.GetEngineShowFlags" }; return NativeCall<FGuid *>(this, f); }
	void PostInitProperties() { static NativeFunction f{ "UGameViewportClient.PostInitProperties" }; NativeCall<void>(this, f); }
	void BeginDestroy() { static NativeFunction f{ "UGameViewportClient.BeginDestroy" }; NativeCall<void>(this, f); }
	void DetachViewportClient() { static NativeFunction f{ "UGameViewportClient.DetachViewportClient" }; NativeCall<void>(this, f); }
	FString * ConsoleCommand(FString * result, FString * Command) { static NativeFunction f{ "UGameViewportClient.ConsoleCommand" }; return NativeCall<FString *, FString *, FString *>(this, f, result, Command); }
	void SetIsSimulateInEditorViewport(bool bInIsSimulateInEditorViewport) { static NativeFunction f{ "UGameViewportClient.SetIsSimulateInEditorViewport" }; NativeCall<void, bool>(this, f, bInIsSimulateInEditorViewport); }
	bool GetMousePosition(FVector2D * MousePosition, bool bUseDPIScale = false) { static NativeFunction f{ "UGameViewportClient.GetMousePosition" }; return NativeCall<bool, FVector2D *, bool>(this, f, MousePosition, bUseDPIScale); }
	bool RequiresUncapturedAxisInput() { static NativeFunction f{ "UGameViewportClient.RequiresUncapturedAxisInput" }; return NativeCall<bool>(this, f); }
	void SetDropDetail(float DeltaSeconds) { static NativeFunction f{ "UGameViewportClient.SetDropDetail" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void GetViewportSize(FVector2D * out_ViewportSize) { static NativeFunction f{ "UGameViewportClient.GetViewportSize" }; NativeCall<void, FVector2D *>(this, f, out_ViewportSize); }
	void Precache() { static NativeFunction f{ "UGameViewportClient.Precache" }; NativeCall<void>(this, f); }
	ULocalPlayer * SetupInitialLocalPlayer(FString * OutError) { static NativeFunction f{ "UGameViewportClient.SetupInitialLocalPlayer" }; return NativeCall<ULocalPlayer *, FString *>(this, f, OutError); }
	ULocalPlayer * CreatePlayer(int ControllerId, FString * OutError, bool bSpawnActor) { static NativeFunction f{ "UGameViewportClient.CreatePlayer" }; return NativeCall<ULocalPlayer *, int, FString *, bool>(this, f, ControllerId, OutError, bSpawnActor); }
	bool RemovePlayer(ULocalPlayer * ExPlayer) { static NativeFunction f{ "UGameViewportClient.RemovePlayer" }; return NativeCall<bool, ULocalPlayer *>(this, f, ExPlayer); }
	void UpdateActiveSplitscreenType() { static NativeFunction f{ "UGameViewportClient.UpdateActiveSplitscreenType" }; NativeCall<void>(this, f); }
	void LayoutPlayers() { static NativeFunction f{ "UGameViewportClient.LayoutPlayers" }; NativeCall<void>(this, f); }
	void GetSubtitleRegion(FVector2D * MinPos, FVector2D * MaxPos) { static NativeFunction f{ "UGameViewportClient.GetSubtitleRegion" }; NativeCall<void, FVector2D *, FVector2D *>(this, f, MinPos, MaxPos); }
	void NotifyPlayerAdded(int PlayerIndex, ULocalPlayer * RemovedPlayer) { static NativeFunction f{ "UGameViewportClient.NotifyPlayerAdded" }; NativeCall<void, int, ULocalPlayer *>(this, f, PlayerIndex, RemovedPlayer); }
	void RemoveAllViewportWidgets() { static NativeFunction f{ "UGameViewportClient.RemoveAllViewportWidgets" }; NativeCall<void>(this, f); }
	void VerifyPathRenderingComponents() { static NativeFunction f{ "UGameViewportClient.VerifyPathRenderingComponents" }; NativeCall<void>(this, f); }
	bool RequestBugScreenShot(const wchar_t * Cmd, bool bDisplayHUDInfo) { static NativeFunction f{ "UGameViewportClient.RequestBugScreenShot" }; return NativeCall<bool, const wchar_t *, bool>(this, f, Cmd, bDisplayHUDInfo); }
	void HandleViewportStatCheckEnabled(const wchar_t * InName, bool * bOutCurrentEnabled, bool * bOutOthersEnabled) { static NativeFunction f{ "UGameViewportClient.HandleViewportStatCheckEnabled" }; NativeCall<void, const wchar_t *, bool *, bool *>(this, f, InName, bOutCurrentEnabled, bOutOthersEnabled); }
	void HandleViewportStatEnabled(const wchar_t * InName) { static NativeFunction f{ "UGameViewportClient.HandleViewportStatEnabled" }; NativeCall<void, const wchar_t *>(this, f, InName); }
	void HandleViewportStatDisabled(const wchar_t * InName) { static NativeFunction f{ "UGameViewportClient.HandleViewportStatDisabled" }; NativeCall<void, const wchar_t *>(this, f, InName); }
	void HandleViewportStatDisableAll(const bool bInAnyViewport) { static NativeFunction f{ "UGameViewportClient.HandleViewportStatDisableAll" }; NativeCall<void, const bool>(this, f, bInAnyViewport); }
	void SetIgnoreInput(bool Ignore, int ControllerId) { static NativeFunction f{ "UGameViewportClient.SetIgnoreInput" }; NativeCall<void, bool, int>(this, f, Ignore, ControllerId); }
	bool IgnoreInput(int ControllerId) { static NativeFunction f{ "UGameViewportClient.IgnoreInput" }; return NativeCall<bool, int>(this, f, ControllerId); }
	void OnSplitscreenPlayerJoinFailure(TSharedPtr<FUniqueNetId, 0> * PlayerUniqueNetId, FString * ErrorMsg) { static NativeFunction f{ "UGameViewportClient.OnSplitscreenPlayerJoinFailure" }; NativeCall<void, TSharedPtr<FUniqueNetId, 0> *, FString *>(this, f, PlayerUniqueNetId, ErrorMsg); }
	int SetStatEnabled(const wchar_t * InName, const bool bEnable, const bool bAll) { static NativeFunction f{ "UGameViewportClient.SetStatEnabled" }; return NativeCall<int, const wchar_t *, const bool, const bool>(this, f, InName, bEnable, bAll); }
	static void StaticRegisterNativesUGameViewportClient() { static NativeFunction f{ "UGameViewportClient.StaticRegisterNativesUGameViewportClient" }; NativeCall<void>(nullptr, f); }
};

struct UGameInstance;
struct FChatMessage;

struct UWorld : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "Global.Z_Construct_UClass_UWorld_NoRegister" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	struct InitializationValues
	{
		unsigned __int32 bInitializeScenes : 1;
		unsigned __int32 bAllowAudioPlayback : 1;
		unsigned __int32 bRequiresHitProxies : 1;
		unsigned __int32 bCreatePhysicsScene : 1;
		unsigned __int32 bCreateNavigation : 1;
		unsigned __int32 bCreateAISystem : 1;
		unsigned __int32 bShouldSimulatePhysics : 1;
		unsigned __int32 bEnableTraceCollision : 1;
		unsigned __int32 bTransactional : 1;
		unsigned __int32 bCreateFXSystem : 1;
	};
	
	TArray<TSubclassOf<AActor>> & ActorsClassesAllowedToSaveField() { static NativeFieldOffset f{ "UWorld.ActorsClassesAllowedToSave" }; return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, f); }
	bool& bIsIdleField() { static NativeFieldOffset f{ "UWorld.bIsIdle" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<TWeakObjectPtr<AActor>> & LocalStasisActorsField() { static NativeFieldOffset f{ "UWorld.LocalStasisActors" }; return *GetNativePointerField<TArray<TWeakObjectPtr<AActor>>*>(this, f); }
	TSet<FName,DefaultKeyFuncs<FName,0>,FDefaultSetAllocator> & LevelNameHashField() { static NativeFieldOffset f{ "UWorld.LevelNameHash" }; return *GetNativePointerField<TSet<FName,DefaultKeyFuncs<FName,0>,FDefaultSetAllocator>*>(this, f); }
	ULevel * PersistentLevelField() { static NativeFieldOffset f{ "UWorld.PersistentLevel" }; return *GetNativePointerField<ULevel**>(this, f); }
	AGameState * GameStateField() { static NativeFieldOffset f{ "UWorld.GameState" }; return *GetNativePointerField<AGameState**>(this, f); }
	TArray<UObject*>& ExtraReferencedObjectsField() { static NativeFieldOffset f{ "UWorld.ExtraReferencedObjects" }; return *GetNativePointerField<TArray<UObject*>*>(this, f); }
	FString & StreamingLevelsPrefixField() { static NativeFieldOffset f{ "UWorld.StreamingLevelsPrefix" }; return *GetNativePointerField<FString*>(this, f); }
	ULevel * CurrentLevelPendingVisibilityField() { static NativeFieldOffset f{ "UWorld.CurrentLevelPendingVisibility" }; return *GetNativePointerField<ULevel**>(this, f); }
	TArray<FVector> & ViewLocationsRenderedLastFrameField() { static NativeFieldOffset f{ "UWorld.ViewLocationsRenderedLastFrame" }; return *GetNativePointerField<TArray<FVector>*>(this, f); }
	AGameMode * AuthorityGameModeField() { static NativeFieldOffset f{ "UWorld.AuthorityGameMode" }; return *GetNativePointerField<AGameMode**>(this, f); }
	TArray<ULevel*>& LevelsField() { static NativeFieldOffset f{ "UWorld.Levels" }; return *GetNativePointerField<TArray<ULevel*>*>(this, f); }
	TArray<AActor*>& NetworkActorsField() { static NativeFieldOffset f{ "UWorld.NetworkActors" }; return *GetNativePointerField<TArray<AActor*>*>(this, f); }
	ULevel * CurrentLevelField() { static NativeFieldOffset f{ "UWorld.CurrentLevel" }; return *GetNativePointerField<ULevel**>(this, f); }
	UGameInstance * OwningGameInstanceField() { static NativeFieldOffset f{ "UWorld.OwningGameInstance" }; return *GetNativePointerField<UGameInstance**>(this, f); }
	int& FrameCounterField() { static NativeFieldOffset f{ "UWorld.FrameCounter" }; return *GetNativePointerField<int*>(this, f); }
	bool& GamePreviewField() { static NativeFieldOffset f{ "UWorld.GamePreview" }; return *GetNativePointerField<bool*>(this, f); }
	TMap<FString,TArray<TArray<TArray<unsigned int>>>,FDefaultSetAllocator,TDefaultMapKeyFuncs<FString,TArray<TArray<TArray<unsigned int>>>,0> > & LocalInstancedStaticMeshComponentInstancesVisibilityStateField() { static NativeFieldOffset f{ "UWorld.LocalInstancedStaticMeshComponentInstancesVisibilityState" }; return *GetNativePointerField<TMap<FString,TArray<TArray<TArray<unsigned int>>>,FDefaultSetAllocator,TDefaultMapKeyFuncs<FString,TArray<TArray<TArray<unsigned int>>>,0> >*>(this, f); }
	TMap<FName,TWeakObjectPtr<UClass>,FDefaultSetAllocator,TDefaultMapKeyFuncs<FName,TWeakObjectPtr<UClass>,0> > & PrioritizedObjectMapField() { static NativeFieldOffset f{ "UWorld.PrioritizedObjectMap" }; return *GetNativePointerField<TMap<FName,TWeakObjectPtr<UClass>,FDefaultSetAllocator,TDefaultMapKeyFuncs<FName,TWeakObjectPtr<UClass>,0> >*>(this, f); }
	TArray<TAutoWeakObjectPtr<AController>> & ControllerListField() { static NativeFieldOffset f{ "UWorld.ControllerList" }; return *GetNativePointerField<TArray<TAutoWeakObjectPtr<AController>>*>(this, f); }
	TArray<TAutoWeakObjectPtr<APlayerController>> & PlayerControllerListField() { static NativeFieldOffset f{ "UWorld.PlayerControllerList" }; return *GetNativePointerField<TArray<TAutoWeakObjectPtr<APlayerController>>*>(this, f); }
	TArray<TAutoWeakObjectPtr<APawn>> & PawnListField() { static NativeFieldOffset f{ "UWorld.PawnList" }; return *GetNativePointerField<TArray<TAutoWeakObjectPtr<APawn>>*>(this, f); }
	TSet<TWeakObjectPtr<UActorComponent>,DefaultKeyFuncs<TWeakObjectPtr<UActorComponent>,0>,FDefaultSetAllocator> & ComponentsThatNeedEndOfFrameUpdateField() { static NativeFieldOffset f{ "UWorld.ComponentsThatNeedEndOfFrameUpdate" }; return *GetNativePointerField<TSet<TWeakObjectPtr<UActorComponent>,DefaultKeyFuncs<TWeakObjectPtr<UActorComponent>,0>,FDefaultSetAllocator>*>(this, f); }
	TSet<TWeakObjectPtr<UActorComponent>,DefaultKeyFuncs<TWeakObjectPtr<UActorComponent>,0>,FDefaultSetAllocator> & ComponentsThatNeedEndOfFrameUpdate_OnGameThreadField() { static NativeFieldOffset f{ "UWorld.ComponentsThatNeedEndOfFrameUpdate_OnGameThread" }; return *GetNativePointerField<TSet<TWeakObjectPtr<UActorComponent>,DefaultKeyFuncs<TWeakObjectPtr<UActorComponent>,0>,FDefaultSetAllocator>*>(this, f); }
	TMap<TWeakObjectPtr<UBlueprint>,TWeakObjectPtr<UObject>,FDefaultSetAllocator,TDefaultMapKeyFuncs<TWeakObjectPtr<UBlueprint>,TWeakObjectPtr<UObject>,0> > & BlueprintObjectsBeingDebuggedField() { static NativeFieldOffset f{ "UWorld.BlueprintObjectsBeingDebugged" }; return *GetNativePointerField<TMap<TWeakObjectPtr<UBlueprint>,TWeakObjectPtr<UObject>,FDefaultSetAllocator,TDefaultMapKeyFuncs<TWeakObjectPtr<UBlueprint>,TWeakObjectPtr<UObject>,0> >*>(this, f); }
	bool& bRequiresHitProxiesField() { static NativeFieldOffset f{ "UWorld.bRequiresHitProxies" }; return *GetNativePointerField<bool*>(this, f); }
	long double& BuildStreamingDataTimerField() { static NativeFieldOffset f{ "UWorld.BuildStreamingDataTimer" }; return *GetNativePointerField<long double*>(this, f); }
	bool& bInTickField() { static NativeFieldOffset f{ "UWorld.bInTick" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsBuiltField() { static NativeFieldOffset f{ "UWorld.bIsBuilt" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bTickNewlySpawnedField() { static NativeFieldOffset f{ "UWorld.bTickNewlySpawned" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPostTickComponentUpdateField() { static NativeFieldOffset f{ "UWorld.bPostTickComponentUpdate" }; return *GetNativePointerField<bool*>(this, f); }
	int& PlayerNumField() { static NativeFieldOffset f{ "UWorld.PlayerNum" }; return *GetNativePointerField<int*>(this, f); }
	float& TimeSinceLastPendingKillPurgeField() { static NativeFieldOffset f{ "UWorld.TimeSinceLastPendingKillPurge" }; return *GetNativePointerField<float*>(this, f); }
	bool& FullPurgeTriggeredField() { static NativeFieldOffset f{ "UWorld.FullPurgeTriggered" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bShouldDelayGarbageCollectField() { static NativeFieldOffset f{ "UWorld.bShouldDelayGarbageCollect" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsWorldInitializedField() { static NativeFieldOffset f{ "UWorld.bIsWorldInitialized" }; return *GetNativePointerField<bool*>(this, f); }
	int& AllowLevelLoadOverrideField() { static NativeFieldOffset f{ "UWorld.AllowLevelLoadOverride" }; return *GetNativePointerField<int*>(this, f); }
	int& StreamingVolumeUpdateDelayField() { static NativeFieldOffset f{ "UWorld.StreamingVolumeUpdateDelay" }; return *GetNativePointerField<int*>(this, f); }
	bool& bIsLevelStreamingFrozenField() { static NativeFieldOffset f{ "UWorld.bIsLevelStreamingFrozen" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bShouldForceUnloadStreamingLevelsField() { static NativeFieldOffset f{ "UWorld.bShouldForceUnloadStreamingLevels" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bShouldForceVisibleStreamingLevelsField() { static NativeFieldOffset f{ "UWorld.bShouldForceVisibleStreamingLevels" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDoDelayedUpdateCullDistanceVolumesField() { static NativeFieldOffset f{ "UWorld.bDoDelayedUpdateCullDistanceVolumes" }; return *GetNativePointerField<bool*>(this, f); }
	TEnumAsByte<enum EWorldType::Type> & WorldTypeField() { static NativeFieldOffset f{ "UWorld.WorldType" }; return *GetNativePointerField<TEnumAsByte<enum EWorldType::Type>*>(this, f); }
	bool& bIsRunningConstructionScriptField() { static NativeFieldOffset f{ "UWorld.bIsRunningConstructionScript" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bShouldSimulatePhysicsField() { static NativeFieldOffset f{ "UWorld.bShouldSimulatePhysics" }; return *GetNativePointerField<bool*>(this, f); }
	FName & DebugDrawTraceTagField() { static NativeFieldOffset f{ "UWorld.DebugDrawTraceTag" }; return *GetNativePointerField<FName*>(this, f); }
	long double& LastTimeUnbuiltLightingWasEncounteredField() { static NativeFieldOffset f{ "UWorld.LastTimeUnbuiltLightingWasEncountered" }; return *GetNativePointerField<long double*>(this, f); }
	long double& TimeSecondsField() { static NativeFieldOffset f{ "UWorld.TimeSeconds" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LoadedAtTimeSecondsField() { static NativeFieldOffset f{ "UWorld.LoadedAtTimeSeconds" }; return *GetNativePointerField<long double*>(this, f); }
	long double& RealTimeSecondsField() { static NativeFieldOffset f{ "UWorld.RealTimeSeconds" }; return *GetNativePointerField<long double*>(this, f); }
	long double& AudioTimeSecondsField() { static NativeFieldOffset f{ "UWorld.AudioTimeSeconds" }; return *GetNativePointerField<long double*>(this, f); }
	float& DeltaTimeSecondsField() { static NativeFieldOffset f{ "UWorld.DeltaTimeSeconds" }; return *GetNativePointerField<float*>(this, f); }
	float& PauseDelayField() { static NativeFieldOffset f{ "UWorld.PauseDelay" }; return *GetNativePointerField<float*>(this, f); }
	unsigned int& StasisThisFrameField() { static NativeFieldOffset f{ "UWorld.StasisThisFrame" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& UnStasisThisFrameField() { static NativeFieldOffset f{ "UWorld.UnStasisThisFrame" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& StasisOssilationThisFrameField() { static NativeFieldOffset f{ "UWorld.StasisOssilationThisFrame" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& StasisThisFrameMaxField() { static NativeFieldOffset f{ "UWorld.StasisThisFrameMax" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& UnStasisThisFrameMaxField() { static NativeFieldOffset f{ "UWorld.UnStasisThisFrameMax" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& StasisOssilationThisFrameMaxField() { static NativeFieldOffset f{ "UWorld.StasisOssilationThisFrameMax" }; return *GetNativePointerField<unsigned int*>(this, f); }
	float& StasisThisFrameAvgField() { static NativeFieldOffset f{ "UWorld.StasisThisFrameAvg" }; return *GetNativePointerField<float*>(this, f); }
	float& UnStasisThisFrameAvgField() { static NativeFieldOffset f{ "UWorld.UnStasisThisFrameAvg" }; return *GetNativePointerField<float*>(this, f); }
	float& StasisOssilationThisFrameAvgField() { static NativeFieldOffset f{ "UWorld.StasisOssilationThisFrameAvg" }; return *GetNativePointerField<float*>(this, f); }
	float& StasisMaxResetTimerField() { static NativeFieldOffset f{ "UWorld.StasisMaxResetTimer" }; return *GetNativePointerField<float*>(this, f); }
	unsigned int& LastUnstasisCountField() { static NativeFieldOffset f{ "UWorld.LastUnstasisCount" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& LoadedSaveIncrementorField() { static NativeFieldOffset f{ "UWorld.LoadedSaveIncrementor" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& CurrentSaveIncrementorField() { static NativeFieldOffset f{ "UWorld.CurrentSaveIncrementor" }; return *GetNativePointerField<unsigned int*>(this, f); }
	bool& bBlockAllOnNextLevelStreamingProcessField() { static NativeFieldOffset f{ "UWorld.bBlockAllOnNextLevelStreamingProcess" }; return *GetNativePointerField<bool*>(this, f); }
	FIntVector & OriginLocationField() { static NativeFieldOffset f{ "UWorld.OriginLocation" }; return *GetNativePointerField<FIntVector*>(this, f); }
	FIntVector & RequestedOriginLocationField() { static NativeFieldOffset f{ "UWorld.RequestedOriginLocation" }; return *GetNativePointerField<FIntVector*>(this, f); }
	bool& bOriginOffsetThisFrameField() { static NativeFieldOffset f{ "UWorld.bOriginOffsetThisFrame" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bFlushingLevelStreamingField() { static NativeFieldOffset f{ "UWorld.bFlushingLevelStreaming" }; return *GetNativePointerField<bool*>(this, f); }
	long double& ForceBlockLoadTimeoutField() { static NativeFieldOffset f{ "UWorld.ForceBlockLoadTimeout" }; return *GetNativePointerField<long double*>(this, f); }
	FString & NextURLField() { static NativeFieldOffset f{ "UWorld.NextURL" }; return *GetNativePointerField<FString*>(this, f); }
	float& NextSwitchCountdownField() { static NativeFieldOffset f{ "UWorld.NextSwitchCountdown" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FName> & PreparingLevelNamesField() { static NativeFieldOffset f{ "UWorld.PreparingLevelNames" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	FName & CommittedPersistentLevelNameField() { static NativeFieldOffset f{ "UWorld.CommittedPersistentLevelName" }; return *GetNativePointerField<FName*>(this, f); }
	FString & CurrentDayTimeField() { static NativeFieldOffset f{ "UWorld.CurrentDayTime" }; return *GetNativePointerField<FString*>(this, f); }
	unsigned int& NumLightingUnbuiltObjectsField() { static NativeFieldOffset f{ "UWorld.NumLightingUnbuiltObjects" }; return *GetNativePointerField<unsigned int*>(this, f); }

	// Functions

	UGameInstance * GetGameInstance() { static NativeFunction f{ "UWorld.GetGameInstance" }; return NativeCall<UGameInstance*>(this, f); }
	AGameMode * GetAuthGameMode() { static NativeFunction f{ "UWorld.GetAuthGameMode" }; return NativeCall<AGameMode*>(this, f); }
	AActor * SpawnActor(UClass * Class, FVector * Location, FRotator * Rotation, FActorSpawnParameters * SpawnParameters) { static NativeFunction f{ "UWorld.SpawnActor" }; return NativeCall<AActor*, UClass*, FVector*, FRotator*, FActorSpawnParameters*>(this, f, Class, Location, Rotation, SpawnParameters); }
	bool DestroyActor(AActor * ThisActor, bool bNetForce, bool bShouldModifyLevel) { static NativeFunction f{ "UWorld.DestroyActor" }; return NativeCall<bool, AActor*, bool, bool>(this, f, ThisActor, bNetForce, bShouldModifyLevel); }
	bool FindTeleportSpot(AActor * TestActor, FVector * TestLocation, FRotator TestRotation, FVector * TraceWorldGeometryFromLocation) { static NativeFunction f{ "UWorld.FindTeleportSpot" }; return NativeCall<bool, AActor*, FVector*, FRotator, FVector*>(this, f, TestActor, TestLocation, TestRotation, TraceWorldGeometryFromLocation); }
	bool EncroachingBlockingGeometry(AActor * TestActor, FVector TestLocation, FRotator TestRotation, FVector * ProposedAdjustment, FVector * TraceWorldGeometryFromLocation) { static NativeFunction f{ "UWorld.EncroachingBlockingGeometry" }; return NativeCall<bool, AActor*, FVector, FRotator, FVector*, FVector*>(this, f, TestActor, TestLocation, TestRotation, ProposedAdjustment, TraceWorldGeometryFromLocation); }
	void SetMapNeedsLightingFullyRebuilt(int InNumLightingUnbuiltObjects) { static NativeFunction f{ "UWorld.SetMapNeedsLightingFullyRebuilt" }; NativeCall<void, int>(this, f, InNumLightingUnbuiltObjects); }
	void TickNetClient(float DeltaSeconds) { static NativeFunction f{ "UWorld.TickNetClient" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	bool IsPaused() { static NativeFunction f{ "UWorld.IsPaused" }; return NativeCall<bool>(this, f); }
	void ProcessLevelStreamingVolumes(FVector * OverrideViewLocation) { static NativeFunction f{ "UWorld.ProcessLevelStreamingVolumes" }; NativeCall<void, FVector*>(this, f, OverrideViewLocation); }
	void MarkActorComponentForNeededEndOfFrameUpdate(UActorComponent * Component, bool bForceGameThread) { static NativeFunction f{ "UWorld.MarkActorComponentForNeededEndOfFrameUpdate" }; NativeCall<void, UActorComponent*, bool>(this, f, Component, bForceGameThread); }
	void CleanupActors() { static NativeFunction f{ "UWorld.CleanupActors" }; NativeCall<void>(this, f); }
	void ForceGarbageCollection(bool bForcePurge) { static NativeFunction f{ "UWorld.ForceGarbageCollection" }; NativeCall<void, bool>(this, f, bForcePurge); }
	void UpdateAllReflectionCaptures() { static NativeFunction f{ "UWorld.UpdateAllReflectionCaptures" }; NativeCall<void>(this, f); }
	void Serialize(FArchive * Ar) { static NativeFunction f{ "UWorld.Serialize" }; NativeCall<void, FArchive*>(this, f, Ar); }
	void PostDuplicate(bool bDuplicateForPIE) { static NativeFunction f{ "UWorld.PostDuplicate" }; NativeCall<void, bool>(this, f, bDuplicateForPIE); }
	void FinishDestroy() { static NativeFunction f{ "UWorld.FinishDestroy" }; NativeCall<void>(this, f); }
	void PostLoad() { static NativeFunction f{ "UWorld.PostLoad" }; NativeCall<void>(this, f); }
	bool PreSaveRoot(const wchar_t* Filename, TArray<FString> * AdditionalPackagesToCook) { static NativeFunction f{ "UWorld.PreSaveRoot" }; return NativeCall<bool, const wchar_t*, TArray<FString>*>(this, f, Filename, AdditionalPackagesToCook); }
	void PostSaveRoot(bool bCleanupIsRequired) { static NativeFunction f{ "UWorld.PostSaveRoot" }; NativeCall<void, bool>(this, f, bCleanupIsRequired); }
	void SetupParameterCollectionInstances() { static NativeFunction f{ "UWorld.SetupParameterCollectionInstances" }; NativeCall<void>(this, f); }
	void UpdateParameterCollectionInstances(bool bUpdateInstanceUniformBuffers) { static NativeFunction f{ "UWorld.UpdateParameterCollectionInstances" }; NativeCall<void, bool>(this, f, bUpdateInstanceUniformBuffers); }
	void InitWorld(UWorld::InitializationValues IVS) { static NativeFunction f{ "UWorld.InitWorld" }; NativeCall<void, UWorld::InitializationValues>(this, f, IVS); }
	void InitializeNewWorld(UWorld::InitializationValues IVS) { static NativeFunction f{ "UWorld.InitializeNewWorld" }; NativeCall<void, UWorld::InitializationValues>(this, f, IVS); }
	void RemoveActor(AActor * Actor, bool bShouldModifyLevel) { static NativeFunction f{ "UWorld.RemoveActor" }; NativeCall<void, AActor*, bool>(this, f, Actor, bShouldModifyLevel); }
	bool AllowAudioPlayback() { static NativeFunction f{ "UWorld.AllowAudioPlayback" }; return NativeCall<bool>(this, f); }
	void ClearWorldComponents() { static NativeFunction f{ "UWorld.ClearWorldComponents" }; NativeCall<void>(this, f); }
	void UpdateWorldComponents(bool bRerunConstructionScripts, bool bCurrentLevelOnly) { static NativeFunction f{ "UWorld.UpdateWorldComponents" }; NativeCall<void, bool, bool>(this, f, bRerunConstructionScripts, bCurrentLevelOnly); }
	void UpdateCullDistanceVolumes() { static NativeFunction f{ "UWorld.UpdateCullDistanceVolumes" }; NativeCall<void>(this, f); }
	void EnsureCollisionTreeIsBuilt() { static NativeFunction f{ "UWorld.EnsureCollisionTreeIsBuilt" }; NativeCall<void>(this, f); }
	void AddToWorld(ULevel * Level, FTransform * LevelTransform, bool bAlwaysConsiderTimeLimit) { static NativeFunction f{ "UWorld.AddToWorld" }; NativeCall<void, ULevel*, FTransform*, bool>(this, f, Level, LevelTransform, bAlwaysConsiderTimeLimit); }
	void RemoveFromWorld(ULevel * Level) { static NativeFunction f{ "UWorld.RemoveFromWorld" }; NativeCall<void, ULevel*>(this, f, Level); }
	static FString * ConvertToPIEPackageName(FString * result, FString * PackageName, int PIEInstanceID) { static NativeFunction f{ "UWorld.ConvertToPIEPackageName" }; return NativeCall<FString*, FString*, FString*, int>(nullptr, f, result, PackageName, PIEInstanceID); }
	static FString * StripPIEPrefixFromPackageName(FString * result, FString * PrefixedName, FString * Prefix) { static NativeFunction f{ "UWorld.StripPIEPrefixFromPackageName" }; return NativeCall<FString*, FString*, FString*, FString*>(nullptr, f, result, PrefixedName, Prefix); }
	static FString * BuildPIEPackagePrefix(FString * result, int PIEInstanceID) { static NativeFunction f{ "UWorld.BuildPIEPackagePrefix" }; return NativeCall<FString*, FString*, int>(nullptr, f, result, PIEInstanceID); }
	static UWorld * DuplicateWorldForPIE(FString * PackageName, UWorld * OwningWorld) { static NativeFunction f{ "UWorld.DuplicateWorldForPIE" }; return NativeCall<UWorld*, FString*, UWorld*>(nullptr, f, PackageName, OwningWorld); }
	bool AreAlwaysLoadedLevelsLoaded() { static NativeFunction f{ "UWorld.AreAlwaysLoadedLevelsLoaded" }; return NativeCall<bool>(this, f); }
	bool AllowLevelLoadRequests() { static NativeFunction f{ "UWorld.AllowLevelLoadRequests" }; return NativeCall<bool>(this, f); }
	void CleanupWorld(bool bSessionEnded, bool bCleanupResources, UWorld * NewWorld) { static NativeFunction f{ "UWorld.CleanupWorld" }; NativeCall<void, bool, bool, UWorld*>(this, f, bSessionEnded, bCleanupResources, NewWorld); }
	UGameViewportClient * GetGameViewport() { static NativeFunction f{ "UWorld.GetGameViewport" }; return NativeCall<UGameViewportClient*>(this, f); }
	TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<AController>> const ,TAutoWeakObjectPtr<AController> const ,int> * GetControllerIterator(TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<AController>> const ,TAutoWeakObjectPtr<AController> const ,int> * result) { static NativeFunction f{ "UWorld.GetControllerIterator" }; return NativeCall<TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<AController>> const ,TAutoWeakObjectPtr<AController> const ,int>*, TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<AController>> const ,TAutoWeakObjectPtr<AController> const ,int>*>(this, f, result); }
	TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<APlayerController>> const ,TAutoWeakObjectPtr<APlayerController> const ,int> * GetPlayerControllerIterator(TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<APlayerController>> const ,TAutoWeakObjectPtr<APlayerController> const ,int> * result) { static NativeFunction f{ "UWorld.GetPlayerControllerIterator" }; return NativeCall<TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<APlayerController>> const ,TAutoWeakObjectPtr<APlayerController> const ,int>*, TIndexedContainerIterator<TArray<TAutoWeakObjectPtr<APlayerController>> const ,TAutoWeakObjectPtr<APlayerController> const ,int>*>(this, f, result); }
	APlayerController * GetFirstPlayerController() { static NativeFunction f{ "UWorld.GetFirstPlayerController" }; return NativeCall<APlayerController*>(this, f); }
	ULocalPlayer * GetFirstLocalPlayerFromController() { static NativeFunction f{ "UWorld.GetFirstLocalPlayerFromController" }; return NativeCall<ULocalPlayer*>(this, f); }
	void AddController(AController * Controller) { static NativeFunction f{ "UWorld.AddController" }; NativeCall<void, AController*>(this, f, Controller); }
	void RemoveController(AController * Controller) { static NativeFunction f{ "UWorld.RemoveController" }; NativeCall<void, AController*>(this, f, Controller); }
	void AddNetworkActor(AActor * Actor) { static NativeFunction f{ "UWorld.AddNetworkActor" }; NativeCall<void, AActor*>(this, f, Actor); }
	void RemoveNetworkActor(AActor * Actor) { static NativeFunction f{ "UWorld.RemoveNetworkActor" }; NativeCall<void, AActor*>(this, f, Actor); }
	long double GetTimeSeconds() { static NativeFunction f{ "UWorld.GetTimeSeconds" }; return NativeCall<long double>(this, f); }
	long double GetRealTimeSeconds() { static NativeFunction f{ "UWorld.GetRealTimeSeconds" }; return NativeCall<long double>(this, f); }
	float GetDeltaSeconds() { static NativeFunction f{ "UWorld.GetDeltaSeconds" }; return NativeCall<float>(this, f); }
	long double TimeSince(long double Time) { static NativeFunction f{ "UWorld.TimeSince" }; return NativeCall<long double, long double>(this, f, Time); }
	void CreatePhysicsScene() { static NativeFunction f{ "UWorld.CreatePhysicsScene" }; NativeCall<void>(this, f); }
	AWorldSettings * GetWorldSettings(bool bCheckStreamingPesistent, bool bChecked) { static NativeFunction f{ "UWorld.GetWorldSettings" }; return NativeCall<AWorldSettings*, bool, bool>(this, f, bCheckStreamingPesistent, bChecked); }
	float GetGravityZ() { static NativeFunction f{ "UWorld.GetGravityZ" }; return NativeCall<float>(this, f); }
	float GetDefaultGravityZ() { static NativeFunction f{ "UWorld.GetDefaultGravityZ" }; return NativeCall<float>(this, f); }
	FString * GetMapName(FString * result) { static NativeFunction f{ "UWorld.GetMapName" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool NotifyAcceptingChannel(UChannel * Channel) { static NativeFunction f{ "UWorld.NotifyAcceptingChannel" }; return NativeCall<bool, UChannel*>(this, f, Channel); }
	void WelcomePlayer(UNetConnection * Connection) { static NativeFunction f{ "UWorld.WelcomePlayer" }; NativeCall<void, UNetConnection*>(this, f, Connection); }
	bool DestroySwappedPC(UNetConnection * Connection) { static NativeFunction f{ "UWorld.DestroySwappedPC" }; return NativeCall<bool, UNetConnection*>(this, f, Connection); }
	bool IsPreparingMapChange() { static NativeFunction f{ "UWorld.IsPreparingMapChange" }; return NativeCall<bool>(this, f); }
	bool SetNewWorldOrigin(FIntVector InNewOriginLocation) { static NativeFunction f{ "UWorld.SetNewWorldOrigin" }; return NativeCall<bool, FIntVector>(this, f, InNewOriginLocation); }
	void NavigateTo(FIntVector InLocation) { static NativeFunction f{ "UWorld.NavigateTo" }; NativeCall<void, FIntVector>(this, f, InLocation); }
	void GetMatineeActors(TArray<AMatineeActor*> * OutMatineeActors) { static NativeFunction f{ "UWorld.GetMatineeActors" }; NativeCall<void, TArray<AMatineeActor*>*>(this, f, OutMatineeActors); }
	void SeamlessTravel(FString * SeamlessTravelURL, bool bAbsolute, FGuid MapPackageGuid) { static NativeFunction f{ "UWorld.SeamlessTravel" }; NativeCall<void, FString*, bool, FGuid>(this, f, SeamlessTravelURL, bAbsolute, MapPackageGuid); }
	bool IsInSeamlessTravel() { static NativeFunction f{ "UWorld.IsInSeamlessTravel" }; return NativeCall<bool>(this, f); }
	void UpdateConstraintActors() { static NativeFunction f{ "UWorld.UpdateConstraintActors" }; NativeCall<void>(this, f); }
	int GetActorCount() { static NativeFunction f{ "UWorld.GetActorCount" }; return NativeCall<int>(this, f); }
	int GetNetRelevantActorCount() { static NativeFunction f{ "UWorld.GetNetRelevantActorCount" }; return NativeCall<int>(this, f); }
	bool ContainsLevel(ULevel * InLevel) { static NativeFunction f{ "UWorld.ContainsLevel" }; return NativeCall<bool, ULevel*>(this, f, InLevel); }
	TArray<ULevel*> * GetLevels() { static NativeFunction f{ "UWorld.GetLevels" }; return NativeCall<TArray<ULevel*>*>(this, f); }
	void BroadcastLevelsChanged() { static NativeFunction f{ "UWorld.BroadcastLevelsChanged" }; NativeCall<void>(this, f); }
	bool IsLevelLoadedByName(FName * LevelName) { static NativeFunction f{ "UWorld.IsLevelLoadedByName" }; return NativeCall<bool, FName*>(this, f, LevelName); }
	FString * GetLocalURL(FString * result) { static NativeFunction f{ "UWorld.GetLocalURL" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool IsPlayInEditor() { static NativeFunction f{ "UWorld.IsPlayInEditor" }; return NativeCall<bool>(this, f); }
	bool IsGameWorld() { static NativeFunction f{ "UWorld.IsGameWorld" }; return NativeCall<bool>(this, f); }
	FString * GetAddressURL(FString * result) { static NativeFunction f{ "UWorld.GetAddressURL" }; return NativeCall<FString*, FString*>(this, f, result); }
	static FString * RemovePIEPrefix(FString * result, FString * Source) { static NativeFunction f{ "UWorld.RemovePIEPrefix" }; return NativeCall<FString*, FString*, FString*>(nullptr, f, result, Source); }
	void ServerTravel(FString * FURL, bool bAbsolute, bool bShouldSkipGameNotify) { static NativeFunction f{ "UWorld.ServerTravel" }; NativeCall<void, FString*, bool, bool>(this, f, FURL, bAbsolute, bShouldSkipGameNotify); }
	UClass * GetModPrioritizedClass(FName * NameIn) { static NativeFunction f{ "UWorld.GetModPrioritizedClass" }; return NativeCall<UClass*, FName*>(this, f, NameIn); }
	bool LoadFromFile(FString * filename) { static NativeFunction f{ "UWorld.LoadFromFile" }; return NativeCall<bool, FString*>(this, f, filename); }
	void UpdateInternalOctreeTransform(UPrimitiveComponent * InComponent) { static NativeFunction f{ "UWorld.UpdateInternalOctreeTransform" }; NativeCall<void, UPrimitiveComponent*>(this, f, InComponent); }
	void RemoveFromInternalOctree(UPrimitiveComponent * InComponent) { static NativeFunction f{ "UWorld.RemoveFromInternalOctree" }; NativeCall<void, UPrimitiveComponent*>(this, f, InComponent); }
	bool OverlapMultiInternalOctree(TArray<UPrimitiveComponent*> * OutPrimitives, FBoxCenterAndExtent * InBounds, unsigned int InSearchMask, bool bDontClearOutArray) { static NativeFunction f{ "UWorld.OverlapMultiInternalOctree" }; return NativeCall<bool, TArray<UPrimitiveComponent*>*, FBoxCenterAndExtent*, unsigned int, bool>(this, f, OutPrimitives, InBounds, InSearchMask, bDontClearOutArray); }
	void UpdateInternalSimpleOctreeTransform(FOctreeElementSimple * InElement) { static NativeFunction f{ "UWorld.UpdateInternalSimpleOctreeTransform" }; NativeCall<void, FOctreeElementSimple*>(this, f, InElement); }
	void RemoveFromInternalSimpleOctree(FOctreeElementSimple * InElement) { static NativeFunction f{ "UWorld.RemoveFromInternalSimpleOctree" }; NativeCall<void, FOctreeElementSimple*>(this, f, InElement); }
	int OverlapNumInternalOctree(FBoxCenterAndExtent * InBounds, unsigned int InSearchMask) { static NativeFunction f{ "UWorld.OverlapNumInternalOctree" }; return NativeCall<int, FBoxCenterAndExtent*, unsigned int>(this, f, InBounds, InSearchMask); }
	bool OverlapMultiInternalSimpleOctree(TArray<FOctreeElementSimple*> * OutPrimitives, FBoxCenterAndExtent * InBounds, unsigned int InSearchMask, bool bDontClearOutArray) { static NativeFunction f{ "UWorld.OverlapMultiInternalSimpleOctree" }; return NativeCall<bool, TArray<FOctreeElementSimple*>*, FBoxCenterAndExtent*, unsigned int, bool>(this, f, OutPrimitives, InBounds, InSearchMask, bDontClearOutArray); }
	bool LineTraceSingle(FHitResult * OutHit, FVector * Start, FVector * End, ECollisionChannel TraceChannel, FCollisionQueryParams * Params, FCollisionResponseParams * ResponseParam, bool bUsePostfilter, float NegativeDistanceTolerance) { static NativeFunction f{ "UWorld.LineTraceSingle(FHitResult&,const FVector&,const FVector&,ECollisionChannel,const FCollisionQueryParams&,const FCollisionResponseParams&,bool,float)const" }; return NativeCall<bool, FHitResult*, FVector*, FVector*, ECollisionChannel, FCollisionQueryParams*, FCollisionResponseParams*, bool, float>(this, f, OutHit, Start, End, TraceChannel, Params, ResponseParam, bUsePostfilter, NegativeDistanceTolerance); }
	bool LineTraceMulti(TArray<FHitResult> * OutHits, FVector * Start, FVector * End, ECollisionChannel TraceChannel, FCollisionQueryParams * Params, FCollisionResponseParams * ResponseParam, bool bDoSort, bool bCullBackfaces, bool bUsePostFilter, float NegativeDistanceTolerance) { static NativeFunction f{ "UWorld.LineTraceMulti(TArray<FHitResult,FDefaultAllocator>&,const FVector&,const FVector&,ECollisionChannel,const FCollisionQueryParams&,const FCollisionResponseParams&,bool,bool,bool,float)const" }; return NativeCall<bool, TArray<FHitResult>*, FVector*, FVector*, ECollisionChannel, FCollisionQueryParams*, FCollisionResponseParams*, bool, bool, bool, float>(this, f, OutHits, Start, End, TraceChannel, Params, ResponseParam, bDoSort, bCullBackfaces, bUsePostFilter, NegativeDistanceTolerance); }
	bool LineTraceSingle(FHitResult * OutHit, FVector * Start, FVector * End, FCollisionQueryParams * Params, FCollisionObjectQueryParams * ObjectQueryParams, bool bUsePostFilter, float NegativeDistanceTolerance) { static NativeFunction f{ "UWorld.LineTraceSingle(FHitResult&,const FVector&,const FVector&,const FCollisionQueryParams&,const FCollisionObjectQueryParams&,bool,float)const" }; return NativeCall<bool, FHitResult*, FVector*, FVector*, FCollisionQueryParams*, FCollisionObjectQueryParams*, bool, float>(this, f, OutHit, Start, End, Params, ObjectQueryParams, bUsePostFilter, NegativeDistanceTolerance); }
	bool LineTraceMulti(TArray<FHitResult> * OutHits, FVector * Start, FVector * End, FCollisionQueryParams * Params, FCollisionObjectQueryParams * ObjectQueryParams, bool bDoSort, bool bCullBackfaces, bool bUsePostFilter, float NegativeDistanceTolerance) { static NativeFunction f{ "UWorld.LineTraceMulti(TArray<FHitResult,FDefaultAllocator>&,const FVector&,const FVector&,const FCollisionQueryParams&,const FCollisionObjectQueryParams&,bool,bool,bool,float)const" }; return NativeCall<bool, TArray<FHitResult>*, FVector*, FVector*, FCollisionQueryParams*, FCollisionObjectQueryParams*, bool, bool, bool, float>(this, f, OutHits, Start, End, Params, ObjectQueryParams, bDoSort, bCullBackfaces, bUsePostFilter, NegativeDistanceTolerance); }
	void StartAsyncTrace() { static NativeFunction f{ "UWorld.StartAsyncTrace" }; NativeCall<void>(this, f); }
	void FinishAsyncTrace() { static NativeFunction f{ "UWorld.FinishAsyncTrace" }; NativeCall<void>(this, f); }
	void FinishPhysicsSim() { static NativeFunction f{ "UWorld.FinishPhysicsSim" }; NativeCall<void>(this, f); }
	static void StaticRegisterNativesUWorld() { static NativeFunction f{ "UWorld.StaticRegisterNativesUWorld" }; NativeCall<void>(nullptr, f); }
};

struct UEngine : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UEngine.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	UFont * TinyFontField() { static NativeFieldOffset f{ "UEngine.TinyFont" }; return *GetNativePointerField<UFont**>(this, f); }
	UFont * SmallFontField() { static NativeFieldOffset f{ "UEngine.SmallFont" }; return *GetNativePointerField<UFont**>(this, f); }
	UFont * MediumFontField() { static NativeFieldOffset f{ "UEngine.MediumFont" }; return *GetNativePointerField<UFont**>(this, f); }
	UFont * LargeFontField() { static NativeFieldOffset f{ "UEngine.LargeFont" }; return *GetNativePointerField<UFont**>(this, f); }
	UFont * SubtitleFontField() { static NativeFieldOffset f{ "UEngine.SubtitleFont" }; return *GetNativePointerField<UFont**>(this, f); }
	TArray<UFont*>& AdditionalFontsField() { static NativeFieldOffset f{ "UEngine.AdditionalFonts" }; return *GetNativePointerField<TArray<UFont*>*>(this, f); }
	TWeakObjectPtr<AMatineeActor> & ActiveMatineeField() { static NativeFieldOffset f{ "UEngine.ActiveMatinee" }; return *GetNativePointerField<TWeakObjectPtr<AMatineeActor>*>(this, f); }
	TArray<FString> & AdditionalFontNamesField() { static NativeFieldOffset f{ "UEngine.AdditionalFontNames" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TSubclassOf<UConsole> & ConsoleClassField() { static NativeFieldOffset f{ "UEngine.ConsoleClass" }; return *GetNativePointerField<TSubclassOf<UConsole>*>(this, f); }
	TSubclassOf<UGameViewportClient> & GameViewportClientClassField() { static NativeFieldOffset f{ "UEngine.GameViewportClientClass" }; return *GetNativePointerField<TSubclassOf<UGameViewportClient>*>(this, f); }
	TSubclassOf<ULocalPlayer> & LocalPlayerClassField() { static NativeFieldOffset f{ "UEngine.LocalPlayerClass" }; return *GetNativePointerField<TSubclassOf<ULocalPlayer>*>(this, f); }
	TSubclassOf<AWorldSettings> & WorldSettingsClassField() { static NativeFieldOffset f{ "UEngine.WorldSettingsClass" }; return *GetNativePointerField<TSubclassOf<AWorldSettings>*>(this, f); }
	TSubclassOf<UGameUserSettings> & GameUserSettingsClassField() { static NativeFieldOffset f{ "UEngine.GameUserSettingsClass" }; return *GetNativePointerField<TSubclassOf<UGameUserSettings>*>(this, f); }
	UGameUserSettings * GameUserSettingsField() { static NativeFieldOffset f{ "UEngine.GameUserSettings" }; return *GetNativePointerField<UGameUserSettings**>(this, f); }
	TSubclassOf<ALevelScriptActor> & LevelScriptActorClassField() { static NativeFieldOffset f{ "UEngine.LevelScriptActorClass" }; return *GetNativePointerField<TSubclassOf<ALevelScriptActor>*>(this, f); }
	UObject * GameSingletonField() { static NativeFieldOffset f{ "UEngine.GameSingleton" }; return *GetNativePointerField<UObject**>(this, f); }
	UTireType * DefaultTireTypeField() { static NativeFieldOffset f{ "UEngine.DefaultTireType" }; return *GetNativePointerField<UTireType**>(this, f); }
	TSubclassOf<APawn> & DefaultPreviewPawnClassField() { static NativeFieldOffset f{ "UEngine.DefaultPreviewPawnClass" }; return *GetNativePointerField<TSubclassOf<APawn>*>(this, f); }
	FString & PlayOnConsoleSaveDirField() { static NativeFieldOffset f{ "UEngine.PlayOnConsoleSaveDir" }; return *GetNativePointerField<FString*>(this, f); }
	UTexture2D * DefaultTextureField() { static NativeFieldOffset f{ "UEngine.DefaultTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture * DefaultDiffuseTextureField() { static NativeFieldOffset f{ "UEngine.DefaultDiffuseTexture" }; return *GetNativePointerField<UTexture**>(this, f); }
	UTexture2D * DefaultBSPVertexTextureField() { static NativeFieldOffset f{ "UEngine.DefaultBSPVertexTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D * HighFrequencyNoiseTextureField() { static NativeFieldOffset f{ "UEngine.HighFrequencyNoiseTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D * DefaultBokehTextureField() { static NativeFieldOffset f{ "UEngine.DefaultBokehTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UMaterial * WireframeMaterialField() { static NativeFieldOffset f{ "UEngine.WireframeMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * DebugMeshMaterialField() { static NativeFieldOffset f{ "UEngine.DebugMeshMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * LevelColorationLitMaterialField() { static NativeFieldOffset f{ "UEngine.LevelColorationLitMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * LevelColorationUnlitMaterialField() { static NativeFieldOffset f{ "UEngine.LevelColorationUnlitMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * LightingTexelDensityMaterialField() { static NativeFieldOffset f{ "UEngine.LightingTexelDensityMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * ShadedLevelColorationLitMaterialField() { static NativeFieldOffset f{ "UEngine.ShadedLevelColorationLitMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * ShadedLevelColorationUnlitMaterialField() { static NativeFieldOffset f{ "UEngine.ShadedLevelColorationUnlitMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * RemoveSurfaceMaterialField() { static NativeFieldOffset f{ "UEngine.RemoveSurfaceMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * VertexColorMaterialField() { static NativeFieldOffset f{ "UEngine.VertexColorMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * VertexColorViewModeMaterial_ColorOnlyField() { static NativeFieldOffset f{ "UEngine.VertexColorViewModeMaterial_ColorOnly" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * VertexColorViewModeMaterial_AlphaAsColorField() { static NativeFieldOffset f{ "UEngine.VertexColorViewModeMaterial_AlphaAsColor" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * VertexColorViewModeMaterial_RedOnlyField() { static NativeFieldOffset f{ "UEngine.VertexColorViewModeMaterial_RedOnly" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * VertexColorViewModeMaterial_GreenOnlyField() { static NativeFieldOffset f{ "UEngine.VertexColorViewModeMaterial_GreenOnly" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * VertexColorViewModeMaterial_BlueOnlyField() { static NativeFieldOffset f{ "UEngine.VertexColorViewModeMaterial_BlueOnly" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * ConstraintLimitMaterialField() { static NativeFieldOffset f{ "UEngine.ConstraintLimitMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * InvalidLightmapSettingsMaterialField() { static NativeFieldOffset f{ "UEngine.InvalidLightmapSettingsMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * PreviewShadowsIndicatorMaterialField() { static NativeFieldOffset f{ "UEngine.PreviewShadowsIndicatorMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	UMaterial * ArrowMaterialField() { static NativeFieldOffset f{ "UEngine.ArrowMaterial" }; return *GetNativePointerField<UMaterial**>(this, f); }
	FLinearColor & LightingOnlyBrightnessField() { static NativeFieldOffset f{ "UEngine.LightingOnlyBrightness" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	TArray<FColor> & LightComplexityColorsField() { static NativeFieldOffset f{ "UEngine.LightComplexityColors" }; return *GetNativePointerField<TArray<FColor>*>(this, f); }
	TArray<FLinearColor> & ShaderComplexityColorsField() { static NativeFieldOffset f{ "UEngine.ShaderComplexityColors" }; return *GetNativePointerField<TArray<FLinearColor>*>(this, f); }
	TArray<FLinearColor> & StationaryLightOverlapColorsField() { static NativeFieldOffset f{ "UEngine.StationaryLightOverlapColors" }; return *GetNativePointerField<TArray<FLinearColor>*>(this, f); }
	float& MaxPixelShaderAdditiveComplexityCountField() { static NativeFieldOffset f{ "UEngine.MaxPixelShaderAdditiveComplexityCount" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxES2PixelShaderAdditiveComplexityCountField() { static NativeFieldOffset f{ "UEngine.MaxES2PixelShaderAdditiveComplexityCount" }; return *GetNativePointerField<float*>(this, f); }
	float& MinLightMapDensityField() { static NativeFieldOffset f{ "UEngine.MinLightMapDensity" }; return *GetNativePointerField<float*>(this, f); }
	float& IdealLightMapDensityField() { static NativeFieldOffset f{ "UEngine.IdealLightMapDensity" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxLightMapDensityField() { static NativeFieldOffset f{ "UEngine.MaxLightMapDensity" }; return *GetNativePointerField<float*>(this, f); }
	float& RenderLightMapDensityGrayscaleScaleField() { static NativeFieldOffset f{ "UEngine.RenderLightMapDensityGrayscaleScale" }; return *GetNativePointerField<float*>(this, f); }
	float& RenderLightMapDensityColorScaleField() { static NativeFieldOffset f{ "UEngine.RenderLightMapDensityColorScale" }; return *GetNativePointerField<float*>(this, f); }
	FLinearColor & LightMapDensityVertexMappedColorField() { static NativeFieldOffset f{ "UEngine.LightMapDensityVertexMappedColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor & LightMapDensitySelectedColorField() { static NativeFieldOffset f{ "UEngine.LightMapDensitySelectedColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	TArray<FStatColorMapping> & StatColorMappingsField() { static NativeFieldOffset f{ "UEngine.StatColorMappings" }; return *GetNativePointerField<TArray<FStatColorMapping>*>(this, f); }
	UPhysicalMaterial * DefaultPhysMaterialField() { static NativeFieldOffset f{ "UEngine.DefaultPhysMaterial" }; return *GetNativePointerField<UPhysicalMaterial**>(this, f); }
	TArray<FGameNameRedirect> & ActiveGameNameRedirectsField() { static NativeFieldOffset f{ "UEngine.ActiveGameNameRedirects" }; return *GetNativePointerField<TArray<FGameNameRedirect>*>(this, f); }
	TArray<FClassRedirect> & ActiveClassRedirectsField() { static NativeFieldOffset f{ "UEngine.ActiveClassRedirects" }; return *GetNativePointerField<TArray<FClassRedirect>*>(this, f); }
	TArray<FPluginRedirect> & ActivePluginRedirectsField() { static NativeFieldOffset f{ "UEngine.ActivePluginRedirects" }; return *GetNativePointerField<TArray<FPluginRedirect>*>(this, f); }
	TArray<FStructRedirect> & ActiveStructRedirectsField() { static NativeFieldOffset f{ "UEngine.ActiveStructRedirects" }; return *GetNativePointerField<TArray<FStructRedirect>*>(this, f); }
	UTexture2D * PreIntegratedSkinBRDFTextureField() { static NativeFieldOffset f{ "UEngine.PreIntegratedSkinBRDFTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D * MiniFontTextureField() { static NativeFieldOffset f{ "UEngine.MiniFontTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture * WeightMapPlaceholderTextureField() { static NativeFieldOffset f{ "UEngine.WeightMapPlaceholderTexture" }; return *GetNativePointerField<UTexture**>(this, f); }
	UTexture2D * LightMapDensityTextureField() { static NativeFieldOffset f{ "UEngine.LightMapDensityTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	IEngineLoop * EngineLoopField() { static NativeFieldOffset f{ "UEngine.EngineLoop" }; return *GetNativePointerField<IEngineLoop**>(this, f); }
	UGameViewportClient * GameViewportField() { static NativeFieldOffset f{ "UEngine.GameViewport" }; return *GetNativePointerField<UGameViewportClient**>(this, f); }
	TArray<FString> & DeferredCommandsField() { static NativeFieldOffset f{ "UEngine.DeferredCommands" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	int& TickCyclesField() { static NativeFieldOffset f{ "UEngine.TickCycles" }; return *GetNativePointerField<int*>(this, f); }
	int& GameCyclesField() { static NativeFieldOffset f{ "UEngine.GameCycles" }; return *GetNativePointerField<int*>(this, f); }
	int& ClientCyclesField() { static NativeFieldOffset f{ "UEngine.ClientCycles" }; return *GetNativePointerField<int*>(this, f); }
	float& NearClipPlaneField() { static NativeFieldOffset f{ "UEngine.NearClipPlane" }; return *GetNativePointerField<float*>(this, f); }
	float& TimeBetweenPurgingPendingKillObjectsField() { static NativeFieldOffset f{ "UEngine.TimeBetweenPurgingPendingKillObjects" }; return *GetNativePointerField<float*>(this, f); }
	float& AsyncLoadingTimeLimitField() { static NativeFieldOffset f{ "UEngine.AsyncLoadingTimeLimit" }; return *GetNativePointerField<float*>(this, f); }
	float& PriorityAsyncLoadingExtraTimeField() { static NativeFieldOffset f{ "UEngine.PriorityAsyncLoadingExtraTime" }; return *GetNativePointerField<float*>(this, f); }
	float& LevelStreamingActorsUpdateTimeLimitField() { static NativeFieldOffset f{ "UEngine.LevelStreamingActorsUpdateTimeLimit" }; return *GetNativePointerField<float*>(this, f); }
	int& LevelStreamingComponentsRegistrationGranularityField() { static NativeFieldOffset f{ "UEngine.LevelStreamingComponentsRegistrationGranularity" }; return *GetNativePointerField<int*>(this, f); }
	int& MaximumLoopIterationCountField() { static NativeFieldOffset f{ "UEngine.MaximumLoopIterationCount" }; return *GetNativePointerField<int*>(this, f); }
	int& NumPawnsAllowedToBeSpawnedInAFrameField() { static NativeFieldOffset f{ "UEngine.NumPawnsAllowedToBeSpawnedInAFrame" }; return *GetNativePointerField<int*>(this, f); }
	FColor & C_WorldBoxField() { static NativeFieldOffset f{ "UEngine.C_WorldBox" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_BrushWireField() { static NativeFieldOffset f{ "UEngine.C_BrushWire" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_AddWireField() { static NativeFieldOffset f{ "UEngine.C_AddWire" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_SubtractWireField() { static NativeFieldOffset f{ "UEngine.C_SubtractWire" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_SemiSolidWireField() { static NativeFieldOffset f{ "UEngine.C_SemiSolidWire" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_NonSolidWireField() { static NativeFieldOffset f{ "UEngine.C_NonSolidWire" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_WireBackgroundField() { static NativeFieldOffset f{ "UEngine.C_WireBackground" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_ScaleBoxHiField() { static NativeFieldOffset f{ "UEngine.C_ScaleBoxHi" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_VolumeCollisionField() { static NativeFieldOffset f{ "UEngine.C_VolumeCollision" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_BSPCollisionField() { static NativeFieldOffset f{ "UEngine.C_BSPCollision" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_OrthoBackgroundField() { static NativeFieldOffset f{ "UEngine.C_OrthoBackground" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_VolumeField() { static NativeFieldOffset f{ "UEngine.C_Volume" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor & C_BrushShapeField() { static NativeFieldOffset f{ "UEngine.C_BrushShape" }; return *GetNativePointerField<FColor*>(this, f); }
	float& StreamingDistanceFactorField() { static NativeFieldOffset f{ "UEngine.StreamingDistanceFactor" }; return *GetNativePointerField<float*>(this, f); }
	TEnumAsByte<enum ETransitionType> & TransitionTypeField() { static NativeFieldOffset f{ "UEngine.TransitionType" }; return *GetNativePointerField<TEnumAsByte<enum ETransitionType>*>(this, f); }
	FString & TransitionDescriptionField() { static NativeFieldOffset f{ "UEngine.TransitionDescription" }; return *GetNativePointerField<FString*>(this, f); }
	FString & TransitionGameModeField() { static NativeFieldOffset f{ "UEngine.TransitionGameMode" }; return *GetNativePointerField<FString*>(this, f); }
	float& MeshLODRangeField() { static NativeFieldOffset f{ "UEngine.MeshLODRange" }; return *GetNativePointerField<float*>(this, f); }
	float& CameraRotationThresholdField() { static NativeFieldOffset f{ "UEngine.CameraRotationThreshold" }; return *GetNativePointerField<float*>(this, f); }
	float& CameraTranslationThresholdField() { static NativeFieldOffset f{ "UEngine.CameraTranslationThreshold" }; return *GetNativePointerField<float*>(this, f); }
	float& PrimitiveProbablyVisibleTimeField() { static NativeFieldOffset f{ "UEngine.PrimitiveProbablyVisibleTime" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxOcclusionPixelsFractionField() { static NativeFieldOffset f{ "UEngine.MaxOcclusionPixelsFraction" }; return *GetNativePointerField<float*>(this, f); }
	int& MaxParticleResizeField() { static NativeFieldOffset f{ "UEngine.MaxParticleResize" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxParticleResizeWarnField() { static NativeFieldOffset f{ "UEngine.MaxParticleResizeWarn" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FDropNoteInfo> & PendingDroppedNotesField() { static NativeFieldOffset f{ "UEngine.PendingDroppedNotes" }; return *GetNativePointerField<TArray<FDropNoteInfo>*>(this, f); }
	FRigidBodyErrorCorrection & PhysicErrorCorrectionField() { static NativeFieldOffset f{ "UEngine.PhysicErrorCorrection" }; return *GetNativePointerField<FRigidBodyErrorCorrection*>(this, f); }
	float& NetClientTicksPerSecondField() { static NativeFieldOffset f{ "UEngine.NetClientTicksPerSecond" }; return *GetNativePointerField<float*>(this, f); }
	float& DisplayGammaField() { static NativeFieldOffset f{ "UEngine.DisplayGamma" }; return *GetNativePointerField<float*>(this, f); }
	float& MinDesiredFrameRateField() { static NativeFieldOffset f{ "UEngine.MinDesiredFrameRate" }; return *GetNativePointerField<float*>(this, f); }
	FLinearColor & DefaultSelectedMaterialColorField() { static NativeFieldOffset f{ "UEngine.DefaultSelectedMaterialColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor & SelectedMaterialColorField() { static NativeFieldOffset f{ "UEngine.SelectedMaterialColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor & SelectionOutlineColorField() { static NativeFieldOffset f{ "UEngine.SelectionOutlineColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor & SelectedMaterialColorOverrideField() { static NativeFieldOffset f{ "UEngine.SelectedMaterialColorOverride" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	bool& bIsOverridingSelectedColorField() { static NativeFieldOffset f{ "UEngine.bIsOverridingSelectedColor" }; return *GetNativePointerField<bool*>(this, f); }
	unsigned int& bEnableVisualLogRecordingOnStartField() { static NativeFieldOffset f{ "UEngine.bEnableVisualLogRecordingOnStart" }; return *GetNativePointerField<unsigned int*>(this, f); }
	UDeviceProfileManager * DeviceProfileManagerField() { static NativeFieldOffset f{ "UEngine.DeviceProfileManager" }; return *GetNativePointerField<UDeviceProfileManager**>(this, f); }
	int& ScreenSaverInhibitorSemaphoreField() { static NativeFieldOffset f{ "UEngine.ScreenSaverInhibitorSemaphore" }; return *GetNativePointerField<int*>(this, f); }
	FString & MatineeCaptureNameField() { static NativeFieldOffset f{ "UEngine.MatineeCaptureName" }; return *GetNativePointerField<FString*>(this, f); }
	FString & MatineePackageCaptureNameField() { static NativeFieldOffset f{ "UEngine.MatineePackageCaptureName" }; return *GetNativePointerField<FString*>(this, f); }
	int& MatineeCaptureFPSField() { static NativeFieldOffset f{ "UEngine.MatineeCaptureFPS" }; return *GetNativePointerField<int*>(this, f); }
	bool& bNoTextureStreamingField() { static NativeFieldOffset f{ "UEngine.bNoTextureStreaming" }; return *GetNativePointerField<bool*>(this, f); }
	FString & ParticleEventManagerClassPathField() { static NativeFieldOffset f{ "UEngine.ParticleEventManagerClassPath" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FScreenMessageString> & PriorityScreenMessagesField() { static NativeFieldOffset f{ "UEngine.PriorityScreenMessages" }; return *GetNativePointerField<TArray<FScreenMessageString>*>(this, f); }
	float& SelectionHighlightIntensityField() { static NativeFieldOffset f{ "UEngine.SelectionHighlightIntensity" }; return *GetNativePointerField<float*>(this, f); }
	float& BSPSelectionHighlightIntensityField() { static NativeFieldOffset f{ "UEngine.BSPSelectionHighlightIntensity" }; return *GetNativePointerField<float*>(this, f); }
	float& HoverHighlightIntensityField() { static NativeFieldOffset f{ "UEngine.HoverHighlightIntensity" }; return *GetNativePointerField<float*>(this, f); }
	float& SelectionHighlightIntensityBillboardsField() { static NativeFieldOffset f{ "UEngine.SelectionHighlightIntensityBillboards" }; return *GetNativePointerField<float*>(this, f); }
	FString & LastModDownloadTextField() { static NativeFieldOffset f{ "UEngine.LastModDownloadText" }; return *GetNativePointerField<FString*>(this, f); }
	FString & PrimalNetAuth_MyIPStrField() { static NativeFieldOffset f{ "UEngine.PrimalNetAuth_MyIPStr" }; return *GetNativePointerField<FString*>(this, f); }
	FString & PrimalNetAuth_TokenField() { static NativeFieldOffset f{ "UEngine.PrimalNetAuth_Token" }; return *GetNativePointerField<FString*>(this, f); }
	bool& bIsInitializedField() { static NativeFieldOffset f{ "UEngine.bIsInitialized" }; return *GetNativePointerField<bool*>(this, f); }
	TMap<int,FScreenMessageString,FDefaultSetAllocator,TDefaultMapKeyFuncs<int,FScreenMessageString,0> > & ScreenMessagesField() { static NativeFieldOffset f{ "UEngine.ScreenMessages" }; return *GetNativePointerField<TMap<int,FScreenMessageString,FDefaultSetAllocator,TDefaultMapKeyFuncs<int,FScreenMessageString,0> >*>(this, f); }
	FAudioDevice * AudioDeviceField() { static NativeFieldOffset f{ "UEngine.AudioDevice" }; return *GetNativePointerField<FAudioDevice**>(this, f); }
	TSharedPtr<IStereoRendering,1> & StereoRenderingDeviceField() { static NativeFieldOffset f{ "UEngine.StereoRenderingDevice" }; return *GetNativePointerField<TSharedPtr<IStereoRendering,1>*>(this, f); }
	TSharedPtr<IHeadMountedDisplay,1> & HMDDeviceField() { static NativeFieldOffset f{ "UEngine.HMDDevice" }; return *GetNativePointerField<TSharedPtr<IHeadMountedDisplay,1>*>(this, f); }
	FRunnableThread * ScreenSaverInhibitorField() { static NativeFieldOffset f{ "UEngine.ScreenSaverInhibitor" }; return *GetNativePointerField<FRunnableThread**>(this, f); }
	FScreenSaverInhibitor * ScreenSaverInhibitorRunnableField() { static NativeFieldOffset f{ "UEngine.ScreenSaverInhibitorRunnable" }; return *GetNativePointerField<FScreenSaverInhibitor**>(this, f); }
	bool& bPendingHardwareSurveyResultsField() { static NativeFieldOffset f{ "UEngine.bPendingHardwareSurveyResults" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FNetDriverDefinition> & NetDriverDefinitionsField() { static NativeFieldOffset f{ "UEngine.NetDriverDefinitions" }; return *GetNativePointerField<TArray<FNetDriverDefinition>*>(this, f); }
	TArray<FString> & ServerActorsField() { static NativeFieldOffset f{ "UEngine.ServerActors" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	int& NextWorldContextHandleField() { static NativeFieldOffset f{ "UEngine.NextWorldContextHandle" }; return *GetNativePointerField<int*>(this, f); }

	// Functions

	FAudioDevice * GetAudioDevice() { static NativeFunction f{ "UEngine.GetAudioDevice" }; return NativeCall<FAudioDevice*>(this, f); }
	bool IsInitialized() { static NativeFunction f{ "UEngine.IsInitialized" }; return NativeCall<bool>(this, f); }
	FString * GetLastModDownloadText(FString * result) { static NativeFunction f{ "UEngine.GetLastModDownloadText" }; return NativeCall<FString*, FString*>(this, f, result); }
	void TickFPSChart(float DeltaSeconds) { static NativeFunction f{ "UEngine.TickFPSChart" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void StartFPSChart() { static NativeFunction f{ "UEngine.StartFPSChart" }; NativeCall<void>(this, f); }
	void StopFPSChart() { static NativeFunction f{ "UEngine.StopFPSChart" }; NativeCall<void>(this, f); }
	void DumpFPSChartToLog(float TotalTime, float DeltaTime, int NumFrames, FString * InMapName) { static NativeFunction f{ "UEngine.DumpFPSChartToLog" }; NativeCall<void, float, float, int, FString*>(this, f, TotalTime, DeltaTime, NumFrames, InMapName); }
	void DumpFPSChart(FString * InMapName, bool bForceDump) { static NativeFunction f{ "UEngine.DumpFPSChart" }; NativeCall<void, FString*, bool>(this, f, InMapName, bForceDump); }
	void LoadMapRedrawViewports() { static NativeFunction f{ "UEngine.LoadMapRedrawViewports" }; NativeCall<void>(this, f); }
	void Tick(float DeltaSeconds, bool bIdleMode) { static NativeFunction f{ "UEngine.Tick" }; NativeCall<void, float, bool>(this, f, DeltaSeconds, bIdleMode); }
	bool IsHardwareSurveyRequired() { static NativeFunction f{ "UEngine.IsHardwareSurveyRequired" }; return NativeCall<bool>(this, f); }
	bool IsHardwareSurveyRequired(int) { return IsHardwareSurveyRequired(); }
	[[deprecated("not in this game build")]] void FEngineStatFuncs() { ReportDeprecatedApiUse("UEngine.FEngineStatFuncs"); static NativeFunction f{ "UEngine.FEngineStatFuncs" }; NativeCall<void>(this, f); }
	void Init(IEngineLoop * InEngineLoop) { static NativeFunction f{ "UEngine.Init" }; NativeCall<void, IEngineLoop*>(this, f, InEngineLoop); }
	void RequestAuthTokenThenNotifyPendingNetGame(UPendingNetGame * PendingNetGameToNotify) { static NativeFunction f{ "UEngine.RequestAuthTokenThenNotifyPendingNetGame" }; NativeCall<void, UPendingNetGame*>(this, f, PendingNetGameToNotify); }
	void OnExternalUIChange(bool bInIsOpening) { static NativeFunction f{ "UEngine.OnExternalUIChange" }; NativeCall<void, bool>(this, f, bInIsOpening); }
	void ShutdownAudioDevice() { static NativeFunction f{ "UEngine.ShutdownAudioDevice" }; NativeCall<void>(this, f); }
	void PreExit() { static NativeFunction f{ "UEngine.PreExit" }; NativeCall<void>(this, f); }
	void TickDeferredCommands() { static NativeFunction f{ "UEngine.TickDeferredCommands" }; NativeCall<void>(this, f); }
	void UpdateTimeAndHandleMaxTickRate() { static NativeFunction f{ "UEngine.UpdateTimeAndHandleMaxTickRate" }; NativeCall<void>(this, f); }
	void ParseCommandline() { static NativeFunction f{ "UEngine.ParseCommandline" }; NativeCall<void>(this, f); }
	void InitializeObjectReferences() { static NativeFunction f{ "UEngine.InitializeObjectReferences" }; NativeCall<void>(this, f); }
	void Serialize(FArchive * Ar) { static NativeFunction f{ "UEngine.Serialize" }; NativeCall<void, FArchive*>(this, f, Ar); }
	static UFont * GetSmallFont() { static NativeFunction f{ "UEngine.GetSmallFont" }; return NativeCall<UFont*>(nullptr, f); }
	bool InitializeAudioDevice() { static NativeFunction f{ "UEngine.InitializeAudioDevice" }; return NativeCall<bool>(this, f); }
	bool UseSound() { static NativeFunction f{ "UEngine.UseSound" }; return NativeCall<bool>(this, f); }
	bool InitializeHMDDevice() { static NativeFunction f{ "UEngine.InitializeHMDDevice" }; return NativeCall<bool>(this, f); }
	void RecordHMDAnalytics() { static NativeFunction f{ "UEngine.RecordHMDAnalytics" }; NativeCall<void>(this, f); }
	bool IsSplitScreen(UWorld * InWorld) { static NativeFunction f{ "UEngine.IsSplitScreen" }; return NativeCall<bool, UWorld*>(this, f, InWorld); }
	ULocalPlayer * GetLocalPlayerFromControllerId(UGameViewportClient * InViewport, int ControllerId) { static NativeFunction f{ "UEngine.GetLocalPlayerFromControllerId(const UGameViewportClient*,int)" }; return NativeCall<ULocalPlayer*, UGameViewportClient*, int>(this, f, InViewport, ControllerId); }
	ULocalPlayer * GetLocalPlayerFromControllerId(UWorld * InWorld, int ControllerId) { static NativeFunction f{ "UEngine.GetLocalPlayerFromControllerId(UWorld*,int)" }; return NativeCall<ULocalPlayer*, UWorld*, int>(this, f, InWorld, ControllerId); }
	void SwapControllerId(ULocalPlayer * NewPlayer, int CurrentControllerId, int NewControllerID) { static NativeFunction f{ "UEngine.SwapControllerId" }; NativeCall<void, ULocalPlayer*, int, int>(this, f, NewPlayer, CurrentControllerId, NewControllerID); }
	APlayerController * GetFirstLocalPlayerController(UWorld * InWorld) { static NativeFunction f{ "UEngine.GetFirstLocalPlayerController" }; return NativeCall<APlayerController*, UWorld*>(this, f, InWorld); }
	void GetAllLocalPlayerControllers(TArray<APlayerController*> * PlayerList) { static NativeFunction f{ "UEngine.GetAllLocalPlayerControllers" }; NativeCall<void, TArray<APlayerController*>*>(this, f, PlayerList); }
	void OnLostFocusPause(bool EnablePause) { static NativeFunction f{ "UEngine.OnLostFocusPause" }; NativeCall<void, bool>(this, f, EnablePause); }
	void TickHardwareSurvey() { static NativeFunction f{ "UEngine.TickHardwareSurvey" }; NativeCall<void>(this, f); }
	static FString * HardwareSurveyBucketRAM(FString * result, unsigned int MemoryMB) { static NativeFunction f{ "UEngine.HardwareSurveyBucketRAM" }; return NativeCall<FString*, FString*, unsigned int>(nullptr, f, result, MemoryMB); }
	static FString * HardwareSurveyBucketVRAM(FString * result, unsigned int VidMemoryMB) { static NativeFunction f{ "UEngine.HardwareSurveyBucketVRAM" }; return NativeCall<FString*, FString*, unsigned int>(nullptr, f, result, VidMemoryMB); }
	static FString * HardwareSurveyBucketResolution(FString * result, unsigned int DisplayWidth, unsigned int DisplayHeight) { static NativeFunction f{ "UEngine.HardwareSurveyBucketResolution" }; return NativeCall<FString*, FString*, unsigned int, unsigned int>(nullptr, f, result, DisplayWidth, DisplayHeight); }
	void OnHardwareSurveyComplete(FHardwareSurveyResults * SurveyResults) { static NativeFunction f{ "UEngine.OnHardwareSurveyComplete" }; NativeCall<void, FHardwareSurveyResults*>(this, f, SurveyResults); }
	float GetMaxTickRate(float DeltaTime, bool bAllowFrameRateSmoothing) { static NativeFunction f{ "UEngine.GetMaxTickRate" }; return NativeCall<float, float, bool>(this, f, DeltaTime, bAllowFrameRateSmoothing); }
	void EnableScreenSaver(bool bEnable) { static NativeFunction f{ "UEngine.EnableScreenSaver" }; NativeCall<void, bool>(this, f, bEnable); }
	static FGuid * GetPackageGuid(FGuid * result, FName PackageName) { static NativeFunction f{ "UEngine.GetPackageGuid" }; return NativeCall<FGuid*, FGuid*, FName>(nullptr, f, result, PackageName); }
	void PerformanceCapture(FString * CaptureName) { static NativeFunction f{ "UEngine.PerformanceCapture" }; NativeCall<void, FString*>(this, f, CaptureName); }
	void WorldAdded(UWorld * InWorld) { static NativeFunction f{ "UEngine.WorldAdded" }; NativeCall<void, UWorld*>(this, f, InWorld); }
	void WorldDestroyed(UWorld * InWorld) { static NativeFunction f{ "UEngine.WorldDestroyed" }; NativeCall<void, UWorld*>(this, f, InWorld); }
	UWorld * GetWorldFromContextObject(UObject * Object, bool bChecked) { static NativeFunction f{ "UEngine.GetWorldFromContextObject" }; return NativeCall<UWorld*, UObject*, bool>(this, f, Object, bChecked); }
	TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int> * GetLocalPlayerIterator(TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int> * result, UWorld * World) { static NativeFunction f{ "UEngine.GetLocalPlayerIterator(UWorld*)" }; return NativeCall<TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int>*, TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int>*, UWorld*>(this, f, result, World); }
	TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int> * GetLocalPlayerIterator(TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int> * result, UGameViewportClient * Viewport) { static NativeFunction f{ "UEngine.GetLocalPlayerIterator(const UGameViewportClient*)" }; return NativeCall<TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int>*, TIndexedContainerIterator<TArray<ULocalPlayer*> const ,ULocalPlayer* const,int>*, UGameViewportClient*>(this, f, result, Viewport); }
	TArray<ULocalPlayer*> * GetGamePlayers(UWorld * World) { static NativeFunction f{ "UEngine.GetGamePlayers(UWorld*)" }; return NativeCall<TArray<ULocalPlayer*>*, UWorld*>(this, f, World); }
	TArray<ULocalPlayer*> * GetGamePlayers(UGameViewportClient * Viewport) { static NativeFunction f{ "UEngine.GetGamePlayers(const UGameViewportClient*)" }; return NativeCall<TArray<ULocalPlayer*>*, UGameViewportClient*>(this, f, Viewport); }
	ULocalPlayer * FindFirstLocalPlayerFromControllerId(int ControllerId) { static NativeFunction f{ "UEngine.FindFirstLocalPlayerFromControllerId" }; return NativeCall<ULocalPlayer*, int>(this, f, ControllerId); }
	int GetNumGamePlayers(UWorld * InWorld) { static NativeFunction f{ "UEngine.GetNumGamePlayers" }; return NativeCall<int, UWorld*>(this, f, InWorld); }
	ULocalPlayer * GetFirstGamePlayer(UWorld * InWorld) { static NativeFunction f{ "UEngine.GetFirstGamePlayer(UWorld*)" }; return NativeCall<ULocalPlayer*, UWorld*>(this, f, InWorld); }
	ULocalPlayer * GetFirstGamePlayer(UPendingNetGame * PendingNetGame) { static NativeFunction f{ "UEngine.GetFirstGamePlayer(UPendingNetGame*)" }; return NativeCall<ULocalPlayer*, UPendingNetGame*>(this, f, PendingNetGame); }
	ULocalPlayer * GetDebugLocalPlayer() { static NativeFunction f{ "UEngine.GetDebugLocalPlayer" }; return NativeCall<ULocalPlayer*>(this, f); }
	bool CreateNamedNetDriver(UWorld * InWorld, FName NetDriverName, FName NetDriverDefinition) { static NativeFunction f{ "UEngine.CreateNamedNetDriver" }; return NativeCall<bool, UWorld*, FName, FName>(this, f, InWorld, NetDriverName, NetDriverDefinition); }
	void DestroyNamedNetDriver(UWorld * InWorld, FName NetDriverName) { static NativeFunction f{ "UEngine.DestroyNamedNetDriver" }; NativeCall<void, UWorld*, FName>(this, f, InWorld, NetDriverName); }
	void SpawnServerActors(UWorld * World) { static NativeFunction f{ "UEngine.SpawnServerActors" }; NativeCall<void, UWorld*>(this, f, World); }
	bool MakeSureMapNameIsValid(FString * InOutMapName) { static NativeFunction f{ "UEngine.MakeSureMapNameIsValid" }; return NativeCall<bool, FString*>(this, f, InOutMapName); }
	void CancelPending(FWorldContext * Context) { static NativeFunction f{ "UEngine.CancelPending(FWorldContext&)" }; NativeCall<void, FWorldContext*>(this, f, Context); }
	void CancelPending(UWorld * InWorld, UPendingNetGame * NewPendingNetGame) { static NativeFunction f{ "UEngine.CancelPending(UWorld*,UPendingNetGame*)" }; NativeCall<void, UWorld*, UPendingNetGame*>(this, f, InWorld, NewPendingNetGame); }
	void CancelAllPending() { static NativeFunction f{ "UEngine.CancelAllPending" }; NativeCall<void>(this, f); }
	void BrowseToDefaultMap(FWorldContext * Context) { static NativeFunction f{ "UEngine.BrowseToDefaultMap" }; NativeCall<void, FWorldContext*>(this, f, Context); }
	bool TickWorldTravel(FWorldContext * Context, float DeltaSeconds) { static NativeFunction f{ "UEngine.TickWorldTravel" }; return NativeCall<bool, FWorldContext*, float>(this, f, Context, DeltaSeconds); }
	void TriggerPostLoadMapEvents() { static NativeFunction f{ "UEngine.TriggerPostLoadMapEvents" }; NativeCall<void>(this, f); }
	void CancelPendingMapChange(FWorldContext * Context) { static NativeFunction f{ "UEngine.CancelPendingMapChange" }; NativeCall<void, FWorldContext*>(this, f, Context); }
	void ClearDebugDisplayProperties() { static NativeFunction f{ "UEngine.ClearDebugDisplayProperties" }; NativeCall<void>(this, f); }
	void MovePendingLevel(FWorldContext * Context) { static NativeFunction f{ "UEngine.MovePendingLevel" }; NativeCall<void, FWorldContext*>(this, f, Context); }
	void UpdateTransitionType(UWorld * CurrentWorld) { static NativeFunction f{ "UEngine.UpdateTransitionType" }; NativeCall<void, UWorld*>(this, f, CurrentWorld); }
	FWorldContext * CreateNewWorldContext(EWorldType::Type WorldType) { static NativeFunction f{ "UEngine.CreateNewWorldContext" }; return NativeCall<FWorldContext*, EWorldType::Type>(this, f, WorldType); }
	FWorldContext * GetWorldContextFromHandleChecked(FName WorldContextHandle) { static NativeFunction f{ "UEngine.GetWorldContextFromHandleChecked" }; return NativeCall<FWorldContext*, FName>(this, f, WorldContextHandle); }
	FWorldContext * GetWorldContextFromWorld(UWorld * InWorld) { static NativeFunction f{ "UEngine.GetWorldContextFromWorld" }; return NativeCall<FWorldContext*, UWorld*>(this, f, InWorld); }
	FWorldContext * GetWorldContextFromWorldChecked(UWorld * InWorld) { static NativeFunction f{ "UEngine.GetWorldContextFromWorldChecked" }; return NativeCall<FWorldContext*, UWorld*>(this, f, InWorld); }
	void DestroyWorldContext(UWorld * InWorld) { static NativeFunction f{ "UEngine.DestroyWorldContext" }; NativeCall<void, UWorld*>(this, f, InWorld); }
	void VerifyLoadMapWorldCleanup() { static NativeFunction f{ "UEngine.VerifyLoadMapWorldCleanup" }; NativeCall<void>(this, f); }
	bool PrepareMapChange(FWorldContext * Context, TArray<FName> * LevelNames) { static NativeFunction f{ "UEngine.PrepareMapChange" }; return NativeCall<bool, FWorldContext*, TArray<FName>*>(this, f, Context, LevelNames); }
	void ConditionalCommitMapChange(FWorldContext * Context) { static NativeFunction f{ "UEngine.ConditionalCommitMapChange" }; NativeCall<void, FWorldContext*>(this, f, Context); }
	bool CommitMapChange(FWorldContext * Context) { static NativeFunction f{ "UEngine.CommitMapChange" }; return NativeCall<bool, FWorldContext*>(this, f, Context); }
	FSeamlessTravelHandler * SeamlessTravelHandlerForWorld(UWorld * World) { static NativeFunction f{ "UEngine.SeamlessTravelHandlerForWorld" }; return NativeCall<FSeamlessTravelHandler*, UWorld*>(this, f, World); }
	void CreateGameUserSettings() { static NativeFunction f{ "UEngine.CreateGameUserSettings" }; NativeCall<void>(this, f); }
	UGameUserSettings * GetGameUserSettings() { static NativeFunction f{ "UEngine.GetGameUserSettings" }; return NativeCall<UGameUserSettings*>(this, f); }
	bool ShouldAbsorbAuthorityOnlyEvent() { static NativeFunction f{ "UEngine.ShouldAbsorbAuthorityOnlyEvent" }; return NativeCall<bool>(this, f); }
	bool ShouldAbsorbCosmeticOnlyEvent() { static NativeFunction f{ "UEngine.ShouldAbsorbCosmeticOnlyEvent" }; return NativeCall<bool>(this, f); }
	bool IsEngineStat(FString * InName) { static NativeFunction f{ "UEngine.IsEngineStat" }; return NativeCall<bool, FString*>(this, f, InName); }
	void RenderEngineStats(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int LHSX, int* InOutLHSY, int RHSX, int* InOutRHSY, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderEngineStats" }; NativeCall<void, UWorld*, FViewport*, FCanvas*, int, int*, int, int*, FVector*, FRotator*>(this, f, World, Viewport, Canvas, LHSX, InOutLHSY, RHSX, InOutRHSY, ViewLocation, ViewRotation); }
	int RenderStatFPS(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatFPS" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatTexture(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatTexture" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatHitches(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatHitches" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatSummary(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatSummary" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatNamedEvents(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatNamedEvents" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatColorList(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatColorList" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatLevels(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatLevels" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatUnit(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatUnit" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatSounds(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatSounds" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
	int RenderStatAI(UWorld * World, FViewport * Viewport, FCanvas * Canvas, int X, int Y, FVector * ViewLocation, FRotator * ViewRotation) { static NativeFunction f{ "UEngine.RenderStatAI" }; return NativeCall<int, UWorld*, FViewport*, FCanvas*, int, int, FVector*, FRotator*>(this, f, World, Viewport, Canvas, X, Y, ViewLocation, ViewRotation); }
};

struct UPrimalGlobals : UObject
{
	UPrimalGameData* PrimalGameDataField() { static NativeFieldOffset f{ "UPrimalGlobals.PrimalGameData" }; return *GetNativePointerField<UPrimalGameData**>(this, f); }
	UPrimalGameData* PrimalGameDataOverrideField() { static NativeFieldOffset f{ "UPrimalGlobals.PrimalGameDataOverride" }; return *GetNativePointerField<UPrimalGameData**>(this, f); }
	TSubclassOf<UUI_GenericConfirmationDialog>& GlobalGenericConfirmationDialogField() { static NativeFieldOffset f{ "UPrimalGlobals.GlobalGenericConfirmationDialog" }; return *GetNativePointerField<TSubclassOf<UUI_GenericConfirmationDialog>*>(this, f); }
	bool& bAllowSingleplayerField() { static NativeFieldOffset f{ "UPrimalGlobals.bAllowSingleplayer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowNonDedicatedHostField() { static NativeFieldOffset f{ "UPrimalGlobals.bAllowNonDedicatedHost" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FString>& UIOnlyShowMapFileNamesField() { static NativeFieldOffset f{ "UPrimalGlobals.UIOnlyShowMapFileNames" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TArray<FString>& UIOnlyShowModIDsField() { static NativeFieldOffset f{ "UPrimalGlobals.UIOnlyShowModIDs" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	bool& bTotalConversionShowUnofficialServersField() { static NativeFieldOffset f{ "UPrimalGlobals.bTotalConversionShowUnofficialServers" }; return *GetNativePointerField<bool*>(this, f); }
	FString& CreditStringField() { static NativeFieldOffset f{ "UPrimalGlobals.CreditString" }; return *GetNativePointerField<FString*>(this, f); }
	FLinearColor& AlphaMissionColorField() { static NativeFieldOffset f{ "UPrimalGlobals.AlphaMissionColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor& BetaMissionColorField() { static NativeFieldOffset f{ "UPrimalGlobals.BetaMissionColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor& GammaMissionColorField() { static NativeFieldOffset f{ "UPrimalGlobals.GammaMissionColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	FLinearColor& MissionCompleteMultiUseWheelTextColorField() { static NativeFieldOffset f{ "UPrimalGlobals.MissionCompleteMultiUseWheelTextColor" }; return *GetNativePointerField<FLinearColor*>(this, f); }
	bool& bGameMediaLoadedField() { static NativeFieldOffset f{ "UPrimalGlobals.bGameMediaLoaded" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bStartedAsyncLoadField() { static NativeFieldOffset f{ "UPrimalGlobals.bStartedAsyncLoad" }; return *GetNativePointerField<bool*>(this, f); }
	FStreamableManager& StreamableManagerField() { static NativeFieldOffset f{ "UPrimalGlobals.StreamableManager" }; return *GetNativePointerField<FStreamableManager*>(this, f); }

	// Functions

	void AsyncLoadGameMedia() { static NativeFunction f{ "UPrimalGlobals.AsyncLoadGameMedia" }; NativeCall<void>(this, f); }
	void FinishLoadGameMedia() { static NativeFunction f{ "UPrimalGlobals.FinishLoadGameMedia" }; NativeCall<void>(this, f); }
	void FinishedLoadingGameMedia() { static NativeFunction f{ "UPrimalGlobals.FinishedLoadingGameMedia" }; NativeCall<void>(this, f); }
	void LoadNextTick(UWorld* ForWorld) { static NativeFunction f{ "UPrimalGlobals.LoadNextTick" }; NativeCall<void, UWorld*>(this, f, ForWorld); }
	void OnConfirmationDialogClosed(bool bAccept) { static NativeFunction f{ "UPrimalGlobals.OnConfirmationDialogClosed" }; NativeCall<void, bool>(this, f, bAccept); }
	static ADayCycleManager* GetDayCycleManager(UWorld* World) { static NativeFunction f{ "UPrimalGlobals.GetDayCycleManager" }; return NativeCall<ADayCycleManager*, UWorld*>(nullptr, f, World); }
	static ASOTFNotification* GetSOTFNotificationManager(UWorld* World) { static NativeFunction f{ "UPrimalGlobals.GetSOTFNotificationManager" }; return NativeCall<ASOTFNotification*, UWorld*>(nullptr, f, World); }
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalGlobals.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static void StaticRegisterNativesUPrimalGlobals() { static NativeFunction f{ "UPrimalGlobals.StaticRegisterNativesUPrimalGlobals" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "UPrimalGlobals.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
};


// Level

struct ULevelBase
{
	TArray<AActor *>& GetActorsField() const { static NativeFieldOffset f{ "ULevelBase.Actors" }; return *GetNativePointerField<TArray<AActor *>*>(this, f); }
};

struct ULevel : ULevelBase
{
};

// Game Mode

struct AGameMode : AInfo
{
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	FName& MatchStateField() { static NativeFieldOffset f{ "AGameMode.MatchState" }; return *GetNativePointerField<FName*>(this, f); }
	FString& OptionsStringField() { static NativeFieldOffset f{ "AGameMode.OptionsString" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<APawn>& DefaultPawnClassField() { static NativeFieldOffset f{ "AGameMode.DefaultPawnClass" }; return *GetNativePointerField<TSubclassOf<APawn>*>(this, f); }
	TSubclassOf<AHUD>& HUDClassField() { static NativeFieldOffset f{ "AGameMode.HUDClass" }; return *GetNativePointerField<TSubclassOf<AHUD>*>(this, f); }
	int& NumSpectatorsField() { static NativeFieldOffset f{ "AGameMode.NumSpectators" }; return *GetNativePointerField<int*>(this, f); }
	int& NumPlayersField() { static NativeFieldOffset f{ "AGameMode.NumPlayers" }; return *GetNativePointerField<int*>(this, f); }
	int& NumBotsField() { static NativeFieldOffset f{ "AGameMode.NumBots" }; return *GetNativePointerField<int*>(this, f); }
	float& MinRespawnDelayField() { static NativeFieldOffset f{ "AGameMode.MinRespawnDelay" }; return *GetNativePointerField<float*>(this, f); }
	AGameSession* GameSessionField() { static NativeFieldOffset f{ "AGameMode.GameSession" }; return *GetNativePointerField<AGameSession**>(this, f); }
	int& NumTravellingPlayersField() { static NativeFieldOffset f{ "AGameMode.NumTravellingPlayers" }; return *GetNativePointerField<int*>(this, f); }
	int& CurrentIDField() { static NativeFieldOffset f{ "AGameMode.CurrentID" }; return *GetNativePointerField<int*>(this, f); }
	FString& DefaultPlayerNameField() { static NativeFieldOffset f{ "AGameMode.DefaultPlayerName" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<APlayerStart*>& PlayerStartsField() { static NativeFieldOffset f{ "AGameMode.PlayerStarts" }; return *GetNativePointerField<TArray<APlayerStart*>*>(this, f); }
	TSubclassOf<APlayerController>& PlayerControllerClassField() { static NativeFieldOffset f{ "AGameMode.PlayerControllerClass" }; return *GetNativePointerField<TSubclassOf<APlayerController>*>(this, f); }
	TSubclassOf<ASpectatorPawn>& SpectatorClassField() { static NativeFieldOffset f{ "AGameMode.SpectatorClass" }; return *GetNativePointerField<TSubclassOf<ASpectatorPawn>*>(this, f); }
	TSubclassOf<APlayerState>& PlayerStateClassField() { static NativeFieldOffset f{ "AGameMode.PlayerStateClass" }; return *GetNativePointerField<TSubclassOf<APlayerState>*>(this, f); }
	TSubclassOf<AGameState>& GameStateClassField() { static NativeFieldOffset f{ "AGameMode.GameStateClass" }; return *GetNativePointerField<TSubclassOf<AGameState>*>(this, f); }
	AGameState* GameStateField() { static NativeFieldOffset f{ "AGameMode.GameState" }; return *GetNativePointerField<AGameState**>(this, f); }
	TArray<APlayerState*>& InactivePlayerArrayField() { static NativeFieldOffset f{ "AGameMode.InactivePlayerArray" }; return *GetNativePointerField<TArray<APlayerState*>*>(this, f); }
	UAntiDupeTransactionLog* AntiDupeTransactionLogField() { static NativeFieldOffset f{ "AGameMode.AntiDupeTransactionLog" }; return *GetNativePointerField<UAntiDupeTransactionLog**>(this, f); }
	float& InactivePlayerStateLifeSpanField() { static NativeFieldOffset f{ "AGameMode.InactivePlayerStateLifeSpan" }; return *GetNativePointerField<float*>(this, f); }
	TArray<APlayerStart*>& UsedPlayerStartsField() { static NativeFieldOffset f{ "AGameMode.UsedPlayerStarts" }; return *GetNativePointerField<TArray<APlayerStart*>*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bUseSeamlessTravel() { static NativeBitField f{ "AGameMode.bUseSeamlessTravel" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPauseable() { static NativeBitField f{ "AGameMode.bPauseable" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bStartPlayersAsSpectators() { static NativeBitField f{ "AGameMode.bStartPlayersAsSpectators" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDelayedStart() { static NativeBitField f{ "AGameMode.bDelayedStart" }; return { this, f }; }

	// Functions

	FName* GetMatchState(FName* result) { static NativeFunction f{ "AGameMode.GetMatchState" }; return NativeCall<FName*, FName*>(this, f, result); }
	static UClass* StaticClass() { static NativeStaticClass f{ "AGameMode.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static const wchar_t* StaticConfigName() { static NativeFunction f{ "AGameMode.StaticConfigName" }; return NativeCall<const wchar_t*>(nullptr, f); }
	FString* GetNetworkNumber(FString* result) { static NativeFunction f{ "AGameMode.GetNetworkNumber" }; return NativeCall<FString*, FString*>(this, f, result); }
	void SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC) { static NativeFunction f{ "AGameMode.SwapPlayerControllers" }; NativeCall<void, APlayerController*, APlayerController*>(this, f, OldPC, NewPC); }
	void ForceClearUnpauseDelegates(AActor* PauseActor) { static NativeFunction f{ "AGameMode.ForceClearUnpauseDelegates" }; NativeCall<void, AActor*>(this, f, PauseActor); }
	void InitGame(FString* MapName, FString* Options, FString* ErrorMessage) { static NativeFunction f{ "AGameMode.InitGame" }; NativeCall<void, FString*, FString*, FString*>(this, f, MapName, Options, ErrorMessage); }
	void RestartGame() { static NativeFunction f{ "AGameMode.RestartGame" }; NativeCall<void>(this, f); }
	void ReturnToMainMenuHost() { static NativeFunction f{ "AGameMode.ReturnToMainMenuHost" }; NativeCall<void>(this, f); }
	void PostLogin(APlayerController* NewPlayer) { static NativeFunction f{ "AGameMode.PostLogin" }; NativeCall<void, APlayerController*>(this, f, NewPlayer); }
	bool ShouldStartInCinematicMode(bool* OutHidePlayer, bool* OutHideHUD, bool* OutDisableMovement, bool* OutDisableTurning) { static NativeFunction f{ "AGameMode.ShouldStartInCinematicMode" }; return NativeCall<bool, bool*, bool*, bool*, bool*>(this, f, OutHidePlayer, OutHideHUD, OutDisableMovement, OutDisableTurning); }
	void SetPlayerDefaults(APawn* PlayerPawn) { static NativeFunction f{ "AGameMode.SetPlayerDefaults" }; NativeCall<void, APawn*>(this, f, PlayerPawn); }
	void Logout(AController* Exiting) { static NativeFunction f{ "AGameMode.Logout" }; NativeCall<void, AController*>(this, f, Exiting); }
	void InitGameState() { static NativeFunction f{ "AGameMode.InitGameState" }; NativeCall<void>(this, f); }
	AActor* FindPlayerStart(AController* Player, FString* IncomingName) { static NativeFunction f{ "AGameMode.FindPlayerStart" }; return NativeCall<AActor*, AController*, FString*>(this, f, Player, IncomingName); }
	void PreInitializeComponents() { static NativeFunction f{ "AGameMode.PreInitializeComponents" }; NativeCall<void>(this, f); }
	void RestartPlayer(AController* NewPlayer) { static NativeFunction f{ "AGameMode.RestartPlayer" }; NativeCall<void, AController*>(this, f, NewPlayer); }
	void StartPlay() { static NativeFunction f{ "AGameMode.StartPlay" }; NativeCall<void>(this, f); }
	void HandleMatchIsWaitingToStart() { static NativeFunction f{ "AGameMode.HandleMatchIsWaitingToStart" }; NativeCall<void>(this, f); }
	bool ReadyToStartMatch() { static NativeFunction f{ "AGameMode.ReadyToStartMatch" }; return NativeCall<bool>(this, f); }
	void StartMatch() { static NativeFunction f{ "AGameMode.StartMatch" }; NativeCall<void>(this, f); }
	void HandleMatchHasStarted() { static NativeFunction f{ "AGameMode.HandleMatchHasStarted" }; NativeCall<void>(this, f); }
	void EndMatch() { static NativeFunction f{ "AGameMode.EndMatch" }; NativeCall<void>(this, f); }
	void HandleMatchHasEnded() { static NativeFunction f{ "AGameMode.HandleMatchHasEnded" }; NativeCall<void>(this, f); }
	void StartToLeaveMap() { static NativeFunction f{ "AGameMode.StartToLeaveMap" }; NativeCall<void>(this, f); }
	void AbortMatch() { static NativeFunction f{ "AGameMode.AbortMatch" }; NativeCall<void>(this, f); }
	bool HasMatchStarted() { static NativeFunction f{ "AGameMode.HasMatchStarted" }; return NativeCall<bool>(this, f); }
	bool IsMatchInProgress() { static NativeFunction f{ "AGameMode.IsMatchInProgress" }; return NativeCall<bool>(this, f); }
	bool HasMatchEnded() { static NativeFunction f{ "AGameMode.HasMatchEnded" }; return NativeCall<bool>(this, f); }
	void SetMatchState(FName NewState) { static NativeFunction f{ "AGameMode.SetMatchState" }; NativeCall<void, FName>(this, f, NewState); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "AGameMode.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void ResetLevel() { static NativeFunction f{ "AGameMode.ResetLevel" }; NativeCall<void>(this, f); }
	void HandleSeamlessTravelPlayer(AController** C) { static NativeFunction f{ "AGameMode.HandleSeamlessTravelPlayer" }; NativeCall<void, AController**>(this, f, C); }
	void SetSeamlessTravelViewTarget(APlayerController* PC) { static NativeFunction f{ "AGameMode.SetSeamlessTravelViewTarget" }; NativeCall<void, APlayerController*>(this, f, PC); }
	void ProcessServerTravel(FString* URL, bool bAbsolute) { static NativeFunction f{ "AGameMode.ProcessServerTravel" }; NativeCall<void, FString*, bool>(this, f, URL, bAbsolute); }
	void GetSeamlessTravelActorList(bool bToEntry, TArray<AActor*>* ActorList) { static NativeFunction f{ "AGameMode.GetSeamlessTravelActorList" }; NativeCall<void, bool, TArray<AActor*>*>(this, f, bToEntry, ActorList); }
	void SetBandwidthLimit(float AsyncIOBandwidthLimit) { static NativeFunction f{ "AGameMode.SetBandwidthLimit" }; NativeCall<void, float>(this, f, AsyncIOBandwidthLimit); }
	FString* InitNewPlayer(FString* result, APlayerController* NewPlayerController, TSharedPtr<FUniqueNetId, 0>* UniqueId, FString* Options, FString* Portal) { static NativeFunction f{ "AGameMode.InitNewPlayer" }; return NativeCall<FString*, FString*, APlayerController*, TSharedPtr<FUniqueNetId, 0>*, FString*, FString*>(this, f, result, NewPlayerController, UniqueId, Options, Portal); }
	bool MustSpectate(APlayerController* NewPlayerController) { static NativeFunction f{ "AGameMode.MustSpectate" }; return NativeCall<bool, APlayerController*>(this, f, NewPlayerController); }
	APlayerController* Login(UPlayer* NewPlayer, FString* Portal, FString* Options, TSharedPtr<FUniqueNetId, 0>* UniqueId, FString* ErrorMessage) { static NativeFunction f{ "AGameMode.Login" }; return NativeCall<APlayerController*, UPlayer*, FString*, FString*, TSharedPtr<FUniqueNetId, 0>*, FString*>(this, f, NewPlayer, Portal, Options, UniqueId, ErrorMessage); }
	void Reset() { static NativeFunction f{ "AGameMode.Reset" }; NativeCall<void>(this, f); }
	void RemovePlayerControllerFromPlayerCount(APlayerController* PC) { static NativeFunction f{ "AGameMode.RemovePlayerControllerFromPlayerCount" }; NativeCall<void, APlayerController*>(this, f, PC); }
	int GetNumPlayers() { static NativeFunction f{ "AGameMode.GetNumPlayers" }; return NativeCall<int>(this, f); }
	void ClearPause() { static NativeFunction f{ "AGameMode.ClearPause" }; NativeCall<void>(this, f); }
	bool GrabOption(FString* Options, FString* Result) { static NativeFunction f{ "AGameMode.GrabOption" }; return NativeCall<bool, FString*, FString*>(this, f, Options, Result); }
	void GetKeyValue(FString* Pair, FString* Key, FString* Value) { static NativeFunction f{ "AGameMode.GetKeyValue" }; NativeCall<void, FString*, FString*, FString*>(this, f, Pair, Key, Value); }
	FString* ParseOption(FString* result, FString* Options, FString* InKey) { static NativeFunction f{ "AGameMode.ParseOption" }; return NativeCall<FString*, FString*, FString*, FString*>(this, f, result, Options, InKey); }
	bool HasOption(FString* Options, FString* InKey) { static NativeFunction f{ "AGameMode.HasOption" }; return NativeCall<bool, FString*, FString*>(this, f, Options, InKey); }
	int GetIntOption(FString* Options, FString* ParseString, int CurrentValue) { static NativeFunction f{ "AGameMode.GetIntOption" }; return NativeCall<int, FString*, FString*, int>(this, f, Options, ParseString, CurrentValue); }
	FString* GetDefaultGameClassPath(FString* result, FString* MapName, FString* Options, FString* Portal) { static NativeFunction f{ "AGameMode.GetDefaultGameClassPath" }; return NativeCall<FString*, FString*, FString*, FString*, FString*>(this, f, result, MapName, Options, Portal); }
	TSubclassOf<AGameSession>* GetGameSessionClass(TSubclassOf<AGameSession>* result) { static NativeFunction f{ "AGameMode.GetGameSessionClass" }; return NativeCall<TSubclassOf<AGameSession>*, TSubclassOf<AGameSession>*>(this, f, result); }
	APlayerController* ProcessClientTravel(FString* FURL, FGuid NextMapGuid, bool bSeamless, bool bAbsolute) { static NativeFunction f{ "AGameMode.ProcessClientTravel" }; return NativeCall<APlayerController*, FString*, FGuid, bool, bool>(this, f, FURL, NextMapGuid, bSeamless, bAbsolute); }
	void PreLogin(FString* Options, FString* Address, TSharedPtr<FUniqueNetId, 0>* UniqueId, FString* authToken, FString* ErrorMessage, UNetConnection* Connection = nullptr) { static NativeFunction f{ "AGameMode.PreLogin" }; NativeCall<void, FString*, FString*, TSharedPtr<FUniqueNetId, 0>*, FString*, FString*, UNetConnection*>(this, f, Options, Address, UniqueId, authToken, ErrorMessage, Connection); }
	void RemoveConnectedPlayer(TSharedPtr<FUniqueNetId, 0>* UniqueNetId) { static NativeFunction f{ "AGameMode.RemoveConnectedPlayer" }; NativeCall<void, TSharedPtr<FUniqueNetId, 0>*>(this, f, UniqueNetId); }
	APlayerController* SpawnPlayerController(FVector* SpawnLocation, FRotator* SpawnRotation) { static NativeFunction f{ "AGameMode.SpawnPlayerController" }; return NativeCall<APlayerController*, FVector*, FRotator*>(this, f, SpawnLocation, SpawnRotation); }
	TSubclassOf<UObject>* GetDefaultPawnClassForController_Implementation(TSubclassOf<UObject>* result, AController* InController) { static NativeFunction f{ "AGameMode.GetDefaultPawnClassForController_Implementation" }; return NativeCall<TSubclassOf<UObject>*, TSubclassOf<UObject>*, AController*>(this, f, result, InController); }
	APawn* SpawnDefaultPawnFor(AController* NewPlayer, AActor* StartSpot) { static NativeFunction f{ "AGameMode.SpawnDefaultPawnFor" }; return NativeCall<APawn*, AController*, AActor*>(this, f, NewPlayer, StartSpot); }
	void GenericPlayerInitialization(AController* C) { static NativeFunction f{ "AGameMode.GenericPlayerInitialization" }; NativeCall<void, AController*>(this, f, C); }
	void StartNewPlayer(APlayerController* NewPlayer) { static NativeFunction f{ "AGameMode.StartNewPlayer" }; NativeCall<void, APlayerController*>(this, f, NewPlayer); }
	void ChangeName(AController* Other, FString* S, bool bNameChange) { static NativeFunction f{ "AGameMode.ChangeName" }; NativeCall<void, AController*, FString*, bool>(this, f, Other, S, bNameChange); }
	void SendPlayer(APlayerController* aPlayer, FString* FURL) { static NativeFunction f{ "AGameMode.SendPlayer" }; NativeCall<void, APlayerController*, FString*>(this, f, aPlayer, FURL); }
	void Broadcast(AActor* Sender, FString* Msg, FName Type) { static NativeFunction f{ "AGameMode.Broadcast" }; NativeCall<void, AActor*, FString*, FName>(this, f, Sender, Msg, Type); }
	bool ShouldSpawnAtStartSpot_Implementation(AController* Player) { static NativeFunction f{ "AGameMode.ShouldSpawnAtStartSpot_Implementation" }; return NativeCall<bool, AController*>(this, f, Player); }
	void AddPlayerStart(APlayerStart* NewPlayerStart) { static NativeFunction f{ "AGameMode.AddPlayerStart" }; NativeCall<void, APlayerStart*>(this, f, NewPlayerStart); }
	void RemovePlayerStart(APlayerStart* RemovedPlayerStart) { static NativeFunction f{ "AGameMode.RemovePlayerStart" }; NativeCall<void, APlayerStart*>(this, f, RemovedPlayerStart); }
	AActor* ChoosePlayerStart_Implementation(AController* Player) { static NativeFunction f{ "AGameMode.ChoosePlayerStart_Implementation" }; return NativeCall<AActor*, AController*>(this, f, Player); }
	bool PlayerCanRestart(APlayerController* Player) { static NativeFunction f{ "AGameMode.PlayerCanRestart" }; return NativeCall<bool, APlayerController*>(this, f, Player); }
	void UpdateGameplayMuteList(APlayerController* aPlayer) { static NativeFunction f{ "AGameMode.UpdateGameplayMuteList" }; NativeCall<void, APlayerController*>(this, f, aPlayer); }
	bool AllowPausing(APlayerController* PC) { static NativeFunction f{ "AGameMode.AllowPausing" }; return NativeCall<bool, APlayerController*>(this, f, PC); }
	void AddInactivePlayer(APlayerState* PlayerState, APlayerController* PC) { static NativeFunction f{ "AGameMode.AddInactivePlayer" }; NativeCall<void, APlayerState*, APlayerController*>(this, f, PlayerState, PC); }
	bool FindInactivePlayer(APlayerController* PC) { static NativeFunction f{ "AGameMode.FindInactivePlayer" }; return NativeCall<bool, APlayerController*>(this, f, PC); }
	void OverridePlayerState(APlayerController* PC, APlayerState* OldPlayerState) { static NativeFunction f{ "AGameMode.OverridePlayerState" }; NativeCall<void, APlayerController*, APlayerState*>(this, f, PC, OldPlayerState); }
	void PostSeamlessTravel() { static NativeFunction f{ "AGameMode.PostSeamlessTravel" }; NativeCall<void>(this, f); }
	static FString* StaticGetFullGameClassName(FString* result, FString* Str) { static NativeFunction f{ "AGameMode.StaticGetFullGameClassName" }; return NativeCall<FString*, FString*, FString*>(nullptr, f, result, Str); }
	static void StaticRegisterNativesAGameMode() { static NativeFunction f{ "AGameMode.StaticRegisterNativesAGameMode" }; NativeCall<void>(nullptr, f); }
	AActor* ChoosePlayerStart(AController* Player) { static NativeFunction f{ "AGameMode.ChoosePlayerStart" }; return NativeCall<AActor*, AController*>(this, f, Player); }
	TSubclassOf<UObject>* GetDefaultPawnClassForController(TSubclassOf<UObject>* result, AController* InController) { static NativeFunction f{ "AGameMode.GetDefaultPawnClassForController" }; return NativeCall<TSubclassOf<UObject>*, TSubclassOf<UObject>*, AController*>(this, f, result, InController); }
	void K2_PostLogin(APlayerController* NewPlayer) { static NativeFunction f{ "AGameMode.K2_PostLogin" }; NativeCall<void, APlayerController*>(this, f, NewPlayer); }
};

struct AShooterGameMode : AGameMode
{
	int& LastRepopulationIndexToCheckField() { static NativeFieldOffset f{ "AShooterGameMode.LastRepopulationIndexToCheck" }; return *GetNativePointerField<int*>(this, f); }
	FString& AlarmNotificationKeyField() { static NativeFieldOffset f{ "AShooterGameMode.AlarmNotificationKey" }; return *GetNativePointerField<FString*>(this, f); }
	FString& AlarmNotificationURLField() { static NativeFieldOffset f{ "AShooterGameMode.AlarmNotificationURL" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<TWeakObjectPtr<APrimalStructure>>& PendingStructureDestroysField() { static NativeFieldOffset f{ "AShooterGameMode.PendingStructureDestroys" }; return *GetNativePointerField<TArray<TWeakObjectPtr<APrimalStructure>>*>(this, f); }
	TSet<FString, DefaultKeyFuncs<FString, 0>, FDefaultSetAllocator>& AllowedAdminIPsField() { static NativeFieldOffset f{ "AShooterGameMode.AllowedAdminIPs" }; return *GetNativePointerField<TSet<FString, DefaultKeyFuncs<FString, 0>, FDefaultSetAllocator>*>(this, f); }
	FString& BanFileNameField() { static NativeFieldOffset f{ "AShooterGameMode.BanFileName" }; return *GetNativePointerField<FString*>(this, f); }
	TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >& BannedMapField() { static NativeFieldOffset f{ "AShooterGameMode.BannedMap" }; return *GetNativePointerField<TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >*>(this, f); }
	long double& LastTimeCheckedForSaveBackupField() { static NativeFieldOffset f{ "AShooterGameMode.LastTimeCheckedForSaveBackup" }; return *GetNativePointerField<long double*>(this, f); }
	int& LastDayOfYearBackedUpField() { static NativeFieldOffset f{ "AShooterGameMode.LastDayOfYearBackedUp" }; return *GetNativePointerField<int*>(this, f); }
	long double& TimeLastStartedDoingRemoteBackupField() { static NativeFieldOffset f{ "AShooterGameMode.TimeLastStartedDoingRemoteBackup" }; return *GetNativePointerField<long double*>(this, f); }
	bool& InitiatedArkTributeAvailabilityCheckField() { static NativeFieldOffset f{ "AShooterGameMode.InitiatedArkTributeAvailabilityCheck" }; return *GetNativePointerField<bool*>(this, f); }
	URCONServer* RCONSocketField() { static NativeFieldOffset f{ "AShooterGameMode.RCONSocket" }; return *GetNativePointerField<URCONServer**>(this, f); }
	FString& PlayersJoinNoCheckFilenameField() { static NativeFieldOffset f{ "AShooterGameMode.PlayersJoinNoCheckFilename" }; return *GetNativePointerField<FString*>(this, f); }
	FString& PlayersExclusiveCheckFilenameField() { static NativeFieldOffset f{ "AShooterGameMode.PlayersExclusiveCheckFilename" }; return *GetNativePointerField<FString*>(this, f); }
	UShooterCheatManager* GlobalCommandsCheatManagerField() { static NativeFieldOffset f{ "AShooterGameMode.GlobalCommandsCheatManager" }; return *GetNativePointerField<UShooterCheatManager**>(this, f); }
	long double& LastUpdatedLoginLocksTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastUpdatedLoginLocksTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastLoginLocksConnectedTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastLoginLocksConnectedTime" }; return *GetNativePointerField<long double*>(this, f); }
	FString& CheckGlobalEnablesURLField() { static NativeFieldOffset f{ "AShooterGameMode.CheckGlobalEnablesURL" }; return *GetNativePointerField<FString*>(this, f); }
	int& TerrainGeneratorVersionField() { static NativeFieldOffset f{ "AShooterGameMode.TerrainGeneratorVersion" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FUniqueNetIdUInt64>& PlayersJoinNoCheckField() { static NativeFieldOffset f{ "AShooterGameMode.PlayersJoinNoCheck" }; return *GetNativePointerField<TArray<FUniqueNetIdUInt64>*>(this, f); }
	TArray<FUniqueNetIdUInt64>& PlayersExclusiveListField() { static NativeFieldOffset f{ "AShooterGameMode.PlayersExclusiveList" }; return *GetNativePointerField<TArray<FUniqueNetIdUInt64>*>(this, f); }
	void* GameBackupPipeReadField() { static NativeFieldOffset f{ "AShooterGameMode.GameBackupPipeRead" }; return *GetNativePointerField<void**>(this, f); }
	void* GameBackupPipeWriteField() { static NativeFieldOffset f{ "AShooterGameMode.GameBackupPipeWrite" }; return *GetNativePointerField<void**>(this, f); }
	TSet<unsigned int, DefaultKeyFuncs<unsigned int, 0>, FDefaultSetAllocator>& TribesIdsField() { static NativeFieldOffset f{ "AShooterGameMode.TribesIds" }; return *GetNativePointerField<TSet<unsigned int, DefaultKeyFuncs<unsigned int, 0>, FDefaultSetAllocator>*>(this, f); }
	TMap<int, unsigned __int64, FDefaultSetAllocator, TDefaultMapKeyFuncs<int, unsigned __int64, 0> >& PlayersIdsField() { static NativeFieldOffset f{ "AShooterGameMode.PlayersIds" }; return *GetNativePointerField<TMap<int, unsigned __int64, FDefaultSetAllocator, TDefaultMapKeyFuncs<int, unsigned __int64, 0> >*>(this, f); }
	TMap<unsigned __int64, int, FDefaultSetAllocator, TDefaultMapKeyFuncs<unsigned __int64, int, 0> >& SteamIdsField() { static NativeFieldOffset f{ "AShooterGameMode.SteamIds" }; return *GetNativePointerField<TMap<unsigned __int64, int, FDefaultSetAllocator, TDefaultMapKeyFuncs<unsigned __int64, int, 0> >*>(this, f); }
	bool& bGlobalDisableLoginLockCheckField() { static NativeFieldOffset f{ "AShooterGameMode.bGlobalDisableLoginLockCheck" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bTempDisableLoginLockCheckField() { static NativeFieldOffset f{ "AShooterGameMode.bTempDisableLoginLockCheck" }; return *GetNativePointerField<bool*>(this, f); }
	FString& MyServerIdField() { static NativeFieldOffset f{ "AShooterGameMode.MyServerId" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FString>& PendingLoginLockReleasesField() { static NativeFieldOffset f{ "AShooterGameMode.PendingLoginLockReleases" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TMap<FString, double, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, double, 0> >& ActiveProfilesSavingField() { static NativeFieldOffset f{ "AShooterGameMode.ActiveProfilesSaving" }; return *GetNativePointerField<TMap<FString, double, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, double, 0> >*>(this, f); }
	FString& LaunchOptionsField() { static NativeFieldOffset f{ "AShooterGameMode.LaunchOptions" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FTribeData>& TribesDataField() { static NativeFieldOffset f{ "AShooterGameMode.TribesData" }; return *GetNativePointerField<TArray<FTribeData>*>(this, f); }
	FString& PGMapNameField() { static NativeFieldOffset f{ "AShooterGameMode.PGMapName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& PGTerrainPropertiesStringField() { static NativeFieldOffset f{ "AShooterGameMode.PGTerrainPropertiesString" }; return *GetNativePointerField<FString*>(this, f); }
	TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >& PGTerrainPropertiesField() { static NativeFieldOffset f{ "AShooterGameMode.PGTerrainProperties" }; return *GetNativePointerField<TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >*>(this, f); }
	bool& bAutoCreateNewPlayerDataField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoCreateNewPlayerData" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsRestartingField() { static NativeFieldOffset f{ "AShooterGameMode.bIsRestarting" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bProximityVoiceChatField() { static NativeFieldOffset f{ "AShooterGameMode.bProximityVoiceChat" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bProximityChatField() { static NativeFieldOffset f{ "AShooterGameMode.bProximityChat" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAutoRestoreBackupsField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoRestoreBackups" }; return *GetNativePointerField<bool*>(this, f); }
	float& DifficultyValueField() { static NativeFieldOffset f{ "AShooterGameMode.DifficultyValue" }; return *GetNativePointerField<float*>(this, f); }
	float& DifficultyValueMinField() { static NativeFieldOffset f{ "AShooterGameMode.DifficultyValueMin" }; return *GetNativePointerField<float*>(this, f); }
	float& DifficultyValueMaxField() { static NativeFieldOffset f{ "AShooterGameMode.DifficultyValueMax" }; return *GetNativePointerField<float*>(this, f); }
	float& ProximityRadiusField() { static NativeFieldOffset f{ "AShooterGameMode.ProximityRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& ProximityRadiusUnconsiousScaleField() { static NativeFieldOffset f{ "AShooterGameMode.ProximityRadiusUnconsiousScale" }; return *GetNativePointerField<float*>(this, f); }
	float& YellingRadiusField() { static NativeFieldOffset f{ "AShooterGameMode.YellingRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& WhisperRadiusField() { static NativeFieldOffset f{ "AShooterGameMode.WhisperRadius" }; return *GetNativePointerField<float*>(this, f); }
	unsigned int& VivoxAttenuationModelField() { static NativeFieldOffset f{ "AShooterGameMode.VivoxAttenuationModel" }; return *GetNativePointerField<unsigned int*>(this, f); }
	float& VivoxMinDistanceField() { static NativeFieldOffset f{ "AShooterGameMode.VivoxMinDistance" }; return *GetNativePointerField<float*>(this, f); }
	float& VivoxRolloffField() { static NativeFieldOffset f{ "AShooterGameMode.VivoxRolloff" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<UCheatManager>& CheatClassField() { static NativeFieldOffset f{ "AShooterGameMode.CheatClass" }; return *GetNativePointerField<TSubclassOf<UCheatManager>*>(this, f); }
	bool& bIsOfficialServerField() { static NativeFieldOffset f{ "AShooterGameMode.bIsOfficialServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsConsoleUnOfficialPCServerField() { static NativeFieldOffset f{ "AShooterGameMode.bIsConsoleUnOfficialPCServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerAllowArkDownloadField() { static NativeFieldOffset f{ "AShooterGameMode.bServerAllowArkDownload" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerAllowThirdPersonPlayerField() { static NativeFieldOffset f{ "AShooterGameMode.bServerAllowThirdPersonPlayer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bUseExclusiveListField() { static NativeFieldOffset f{ "AShooterGameMode.bUseExclusiveList" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAlwaysNotifyPlayerLeftField() { static NativeFieldOffset f{ "AShooterGameMode.bAlwaysNotifyPlayerLeft" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAlwaysNotifyPlayerJoinedField() { static NativeFieldOffset f{ "AShooterGameMode.bAlwaysNotifyPlayerJoined" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerHardcoreField() { static NativeFieldOffset f{ "AShooterGameMode.bServerHardcore" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerPVEField() { static NativeFieldOffset f{ "AShooterGameMode.bServerPVE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerCrosshairField() { static NativeFieldOffset f{ "AShooterGameMode.bServerCrosshair" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerForceNoHUDField() { static NativeFieldOffset f{ "AShooterGameMode.bServerForceNoHUD" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bMapPlayerLocationField() { static NativeFieldOffset f{ "AShooterGameMode.bMapPlayerLocation" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowFlyerCarryPvEField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowFlyerCarryPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableStructureDecayPvEField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableStructureDecayPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableDinoDecayPvEField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableDinoDecayPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bEnablePvPGammaField() { static NativeFieldOffset f{ "AShooterGameMode.bEnablePvPGamma" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisablePvEGammaField() { static NativeFieldOffset f{ "AShooterGameMode.bDisablePvEGamma" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bClampResourceHarvestDamageField() { static NativeFieldOffset f{ "AShooterGameMode.bClampResourceHarvestDamage" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventStructurePaintingField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventStructurePainting" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCaveBuildingPvEField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowCaveBuildingPvE" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCaveBuildingPvPField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowCaveBuildingPvP" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAdminLoggingField() { static NativeFieldOffset f{ "AShooterGameMode.bAdminLogging" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvPStructureDecayField() { static NativeFieldOffset f{ "AShooterGameMode.bPvPStructureDecay" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAutoDestroyStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoDestroyStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bForceAllStructureLockingField() { static NativeFieldOffset f{ "AShooterGameMode.bForceAllStructureLocking" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowDeprecatedStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowDeprecatedStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventTribeAlliancesField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventTribeAlliances" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowHitMarkersField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowHitMarkers" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bOnlyAutoDestroyCoreStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bOnlyAutoDestroyCoreStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventMateBoostField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventMateBoost" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bTribeLogDestroyedEnemyStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bTribeLogDestroyedEnemyStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEAllowStructuresAtSupplyDropsField() { static NativeFieldOffset f{ "AShooterGameMode.bPvEAllowStructuresAtSupplyDrops" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerGameLogIncludeTribeLogsField() { static NativeFieldOffset f{ "AShooterGameMode.bServerGameLogIncludeTribeLogs" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerRCONOutputTribeLogsField() { static NativeFieldOffset f{ "AShooterGameMode.bServerRCONOutputTribeLogs" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bUseOptimizedHarvestingHealthField() { static NativeFieldOffset f{ "AShooterGameMode.bUseOptimizedHarvestingHealth" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bClampItemSpoilingTimesField() { static NativeFieldOffset f{ "AShooterGameMode.bClampItemSpoilingTimes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bClampItemStatsField() { static NativeFieldOffset f{ "AShooterGameMode.bClampItemStats" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAutoDestroyDecayedDinosField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoDestroyDecayedDinos" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowMultipleAttachedC4Field() { static NativeFieldOffset f{ "AShooterGameMode.bAllowMultipleAttachedC4" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowFlyingStaminaRecoveryField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowFlyingStaminaRecovery" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bCrossARKAllowForeignDinoDownloadsField() { static NativeFieldOffset f{ "AShooterGameMode.bCrossARKAllowForeignDinoDownloads" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventSpawnAnimationsField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventSpawnAnimations" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsLegacyServerField() { static NativeFieldOffset f{ "AShooterGameMode.bIsLegacyServer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIdlePlayerKickAllowedField() { static NativeFieldOffset f{ "AShooterGameMode.bIdlePlayerKickAllowed" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bEnableVictoryCoreDupeCheckField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableVictoryCoreDupeCheck" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIgnoreLimitMaxStructuresInRangeTypeFlagField() { static NativeFieldOffset f{ "AShooterGameMode.bIgnoreLimitMaxStructuresInRangeTypeFlag" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bEnableOfficialOnlyVersioningCodeField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableOfficialOnlyVersioningCode" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bEnableCryopodNerfField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableCryopodNerf" }; return *GetNativePointerField<bool*>(this, f); }
	int& TheMaxStructuresInRangeField() { static NativeFieldOffset f{ "AShooterGameMode.TheMaxStructuresInRange" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxStructuresInSmallRadiusField() { static NativeFieldOffset f{ "AShooterGameMode.MaxStructuresInSmallRadius" }; return *GetNativePointerField<int*>(this, f); }
	bool& bEnableCryoSicknessPVEField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableCryoSicknessPVE" }; return *GetNativePointerField<bool*>(this, f); }
	float& CryopodNerfDamageMultField() { static NativeFieldOffset f{ "AShooterGameMode.CryopodNerfDamageMult" }; return *GetNativePointerField<float*>(this, f); }
	float& CryopodNerfDurationField() { static NativeFieldOffset f{ "AShooterGameMode.CryopodNerfDuration" }; return *GetNativePointerField<float*>(this, f); }
	bool& bEnableMeshBitingProtectionField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableMeshBitingProtection" }; return *GetNativePointerField<bool*>(this, f); }
	float& CryopodNerfIncomingDamageMultPercentField() { static NativeFieldOffset f{ "AShooterGameMode.CryopodNerfIncomingDamageMultPercent" }; return *GetNativePointerField<float*>(this, f); }
	int& RCONPortField() { static NativeFieldOffset f{ "AShooterGameMode.RCONPort" }; return *GetNativePointerField<int*>(this, f); }
	float& DayCycleSpeedScaleField() { static NativeFieldOffset f{ "AShooterGameMode.DayCycleSpeedScale" }; return *GetNativePointerField<float*>(this, f); }
	float& NightTimeSpeedScaleField() { static NativeFieldOffset f{ "AShooterGameMode.NightTimeSpeedScale" }; return *GetNativePointerField<float*>(this, f); }
	float& DayTimeSpeedScaleField() { static NativeFieldOffset f{ "AShooterGameMode.DayTimeSpeedScale" }; return *GetNativePointerField<float*>(this, f); }
	float& PvEStructureDecayPeriodMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PvEStructureDecayPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& StructurePreventResourceRadiusMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.StructurePreventResourceRadiusMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PvEDinoDecayPeriodMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PvEDinoDecayPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourcesRespawnPeriodMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.ResourcesRespawnPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxTamedDinosField() { static NativeFieldOffset f{ "AShooterGameMode.MaxTamedDinos" }; return *GetNativePointerField<float*>(this, f); }
	float& ListenServerTetherDistanceMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.ListenServerTetherDistanceMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PerPlatformMaxStructuresMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PerPlatformMaxStructuresMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& AutoDestroyOldStructuresMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.AutoDestroyOldStructuresMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& RCONServerGameLogBufferField() { static NativeFieldOffset f{ "AShooterGameMode.RCONServerGameLogBuffer" }; return *GetNativePointerField<float*>(this, f); }
	float& OxygenSwimSpeedStatMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.OxygenSwimSpeedStatMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& ServerAutoForceRespawnWildDinosIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.ServerAutoForceRespawnWildDinosInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& RadiusStructuresInSmallRadiusField() { static NativeFieldOffset f{ "AShooterGameMode.RadiusStructuresInSmallRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& EnableAFKKickPlayerCountPercentField() { static NativeFieldOffset f{ "AShooterGameMode.EnableAFKKickPlayerCountPercent" }; return *GetNativePointerField<float*>(this, f); }
	float& KickIdlePlayersPeriodField() { static NativeFieldOffset f{ "AShooterGameMode.KickIdlePlayersPeriod" }; return *GetNativePointerField<float*>(this, f); }
	float& MateBoostEffectMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.MateBoostEffectMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& AutoSavePeriodMinutesField() { static NativeFieldOffset f{ "AShooterGameMode.AutoSavePeriodMinutes" }; return *GetNativePointerField<float*>(this, f); }
	float& XPMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.XPMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FName& ActiveEventField() { static NativeFieldOffset f{ "AShooterGameMode.ActiveEvent" }; return *GetNativePointerField<FName*>(this, f); }
	float& TribeNameChangeCooldownField() { static NativeFieldOffset f{ "AShooterGameMode.TribeNameChangeCooldown" }; return *GetNativePointerField<float*>(this, f); }
	float& PlatformSaddleBuildAreaBoundsMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlatformSaddleBuildAreaBoundsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAlwaysAllowStructurePickupField() { static NativeFieldOffset f{ "AShooterGameMode.bAlwaysAllowStructurePickup" }; return *GetNativePointerField<bool*>(this, f); }
	float& StructurePickupTimeAfterPlacementField() { static NativeFieldOffset f{ "AShooterGameMode.StructurePickupTimeAfterPlacement" }; return *GetNativePointerField<float*>(this, f); }
	float& StructurePickupHoldDurationField() { static NativeFieldOffset f{ "AShooterGameMode.StructurePickupHoldDuration" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAllowIntegratedSPlusStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowIntegratedSPlusStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowHideDamageSourceFromLogsField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowHideDamageSourceFromLogs" }; return *GetNativePointerField<bool*>(this, f); }
	float& KillXPMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.KillXPMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& HarvestXPMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.HarvestXPMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CraftXPMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CraftXPMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GenericXPMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.GenericXPMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& SpecialXPMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.SpecialXPMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& RandomAutoSaveSpreadField() { static NativeFieldOffset f{ "AShooterGameMode.RandomAutoSaveSpread" }; return *GetNativePointerField<float*>(this, f); }
	FString& SteamAPIKeyField() { static NativeFieldOffset f{ "AShooterGameMode.SteamAPIKey" }; return *GetNativePointerField<FString*>(this, f); }
	FString& LastServerNotificationMessageField() { static NativeFieldOffset f{ "AShooterGameMode.LastServerNotificationMessage" }; return *GetNativePointerField<FString*>(this, f); }
	long double& LastServerNotificationRecievedAtField() { static NativeFieldOffset f{ "AShooterGameMode.LastServerNotificationRecievedAt" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastExecSaveTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastExecSaveTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastTimeSavedWorldField() { static NativeFieldOffset f{ "AShooterGameMode.LastTimeSavedWorld" }; return *GetNativePointerField<long double*>(this, f); }
	FString& LastClaimedGameCodeField() { static NativeFieldOffset f{ "AShooterGameMode.LastClaimedGameCode" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FString>& ArkGameCodesField() { static NativeFieldOffset f{ "AShooterGameMode.ArkGameCodes" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	bool& bIsCurrentlyRequestingKeyField() { static NativeFieldOffset f{ "AShooterGameMode.bIsCurrentlyRequestingKey" }; return *GetNativePointerField<bool*>(this, f); }
	FString& SaveDirectoryNameField() { static NativeFieldOffset f{ "AShooterGameMode.SaveDirectoryName" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<UPrimalPlayerData*>& PlayerDatasField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerDatas" }; return *GetNativePointerField<TArray<UPrimalPlayerData*>*>(this, f); }
	int& NPCZoneManagerModField() { static NativeFieldOffset f{ "AShooterGameMode.NPCZoneManagerMod" }; return *GetNativePointerField<int*>(this, f); }
	bool& bPopulatingSpawnZonesField() { static NativeFieldOffset f{ "AShooterGameMode.bPopulatingSpawnZones" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bRestartedAPlayerField() { static NativeFieldOffset f{ "AShooterGameMode.bRestartedAPlayer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bForceRespawnDinosField() { static NativeFieldOffset f{ "AShooterGameMode.bForceRespawnDinos" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bFirstSaveWorldField() { static NativeFieldOffset f{ "AShooterGameMode.bFirstSaveWorld" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowRaidDinoFeedingField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowRaidDinoFeeding" }; return *GetNativePointerField<bool*>(this, f); }
	FDateTime& LastBackupTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastBackupTime" }; return *GetNativePointerField<FDateTime*>(this, f); }
	FDateTime& LastSaveWorldTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastSaveWorldTime" }; return *GetNativePointerField<FDateTime*>(this, f); }
	float& TamedDinoDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.TamedDinoDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& StructureDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.StructureDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerResistanceMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerResistanceMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoResistanceMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoResistanceMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& TamedDinoResistanceMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.TamedDinoResistanceMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& StructureResistanceMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.StructureResistanceMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bJoinInProgressGamesAsSpectatorField() { static NativeFieldOffset f{ "AShooterGameMode.bJoinInProgressGamesAsSpectator" }; return *GetNativePointerField<bool*>(this, f); }
	float& TamingSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.TamingSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& HarvestAmountMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.HarvestAmountMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& HarvestHealthMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.HarvestHealthMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerCharacterWaterDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerCharacterWaterDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerCharacterFoodDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerCharacterFoodDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoCharacterFoodDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoCharacterFoodDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& RaidDinoCharacterFoodDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.RaidDinoCharacterFoodDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerCharacterStaminaDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerCharacterStaminaDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoCharacterStaminaDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoCharacterStaminaDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerCharacterHealthRecoveryMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerCharacterHealthRecoveryMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoCharacterHealthRecoveryMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoCharacterHealthRecoveryMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CarnivoreNaturalTargetingRangeMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CarnivoreNaturalTargetingRangeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CarnivorePlayerAggroMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CarnivorePlayerAggroMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& HerbivoreNaturalTargetingRangeMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.HerbivoreNaturalTargetingRangeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& HerbivorePlayerAggroMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.HerbivorePlayerAggroMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& AIForceTargetPlayersField() { static NativeFieldOffset f{ "AShooterGameMode.AIForceTargetPlayers" }; return *GetNativePointerField<bool*>(this, f); }
	bool& AIForceOverlapCheckField() { static NativeFieldOffset f{ "AShooterGameMode.AIForceOverlapCheck" }; return *GetNativePointerField<bool*>(this, f); }
	float& DinoCountMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoCountMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bDisableSaveLoadField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableSaveLoad" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableXPField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableXP" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableDynamicMusicField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableDynamicMusic" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<FPlayerDeathReason>& PlayerDeathReasonsField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerDeathReasons" }; return *GetNativePointerField<TArray<FPlayerDeathReason>*>(this, f); }
	TArray<FLevelExperienceRamp>& LevelExperienceRampOverridesField() { static NativeFieldOffset f{ "AShooterGameMode.LevelExperienceRampOverrides" }; return *GetNativePointerField<TArray<FLevelExperienceRamp>*>(this, f); }
	TArray<int>& OverridePlayerLevelEngramPointsField() { static NativeFieldOffset f{ "AShooterGameMode.OverridePlayerLevelEngramPoints" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	TArray<int>& ExcludeItemIndicesField() { static NativeFieldOffset f{ "AShooterGameMode.ExcludeItemIndices" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	TArray<FEngramEntryOverride>& OverrideEngramEntriesField() { static NativeFieldOffset f{ "AShooterGameMode.OverrideEngramEntries" }; return *GetNativePointerField<TArray<FEngramEntryOverride>*>(this, f); }
	TArray<FEngramEntryOverride>& OverrideNamedEngramEntriesField() { static NativeFieldOffset f{ "AShooterGameMode.OverrideNamedEngramEntries" }; return *GetNativePointerField<TArray<FEngramEntryOverride>*>(this, f); }
	TArray<FEngramEntryAutoUnlock>& EngramEntryAutoUnlocksField() { static NativeFieldOffset f{ "AShooterGameMode.EngramEntryAutoUnlocks" }; return *GetNativePointerField<TArray<FEngramEntryAutoUnlock>*>(this, f); }
	TArray<FString>& PreventDinoTameClassNamesField() { static NativeFieldOffset f{ "AShooterGameMode.PreventDinoTameClassNames" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TArray<FDinoSpawnWeightMultiplier>& DinoSpawnWeightMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.DinoSpawnWeightMultipliers" }; return *GetNativePointerField<TArray<FDinoSpawnWeightMultiplier>*>(this, f); }
	TArray<FClassMultiplier>& DinoClassResistanceMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.DinoClassResistanceMultipliers" }; return *GetNativePointerField<TArray<FClassMultiplier>*>(this, f); }
	TArray<FClassMultiplier>& TamedDinoClassResistanceMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.TamedDinoClassResistanceMultipliers" }; return *GetNativePointerField<TArray<FClassMultiplier>*>(this, f); }
	TArray<FClassMultiplier>& DinoClassDamageMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.DinoClassDamageMultipliers" }; return *GetNativePointerField<TArray<FClassMultiplier>*>(this, f); }
	TArray<FClassMultiplier>& TamedDinoClassDamageMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.TamedDinoClassDamageMultipliers" }; return *GetNativePointerField<TArray<FClassMultiplier>*>(this, f); }
	TArray<FClassMultiplier>& HarvestResourceItemAmountClassMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.HarvestResourceItemAmountClassMultipliers" }; return *GetNativePointerField<TArray<FClassMultiplier>*>(this, f); }
	TArray<FClassNameReplacement>& NPCReplacementsField() { static NativeFieldOffset f{ "AShooterGameMode.NPCReplacements" }; return *GetNativePointerField<TArray<FClassNameReplacement>*>(this, f); }
	float& PvPZoneStructureDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PvPZoneStructureDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bOnlyAllowSpecifiedEngramsField() { static NativeFieldOffset f{ "AShooterGameMode.bOnlyAllowSpecifiedEngrams" }; return *GetNativePointerField<bool*>(this, f); }
	int& OverrideMaxExperiencePointsPlayerField() { static NativeFieldOffset f{ "AShooterGameMode.OverrideMaxExperiencePointsPlayer" }; return *GetNativePointerField<int*>(this, f); }
	int& OverrideMaxExperiencePointsDinoField() { static NativeFieldOffset f{ "AShooterGameMode.OverrideMaxExperiencePointsDino" }; return *GetNativePointerField<int*>(this, f); }
	float& GlobalSpoilingTimeMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.GlobalSpoilingTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalItemDecompositionTimeMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.GlobalItemDecompositionTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalCorpseDecompositionTimeMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.GlobalCorpseDecompositionTimeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxFallSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.MaxFallSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAutoPvETimerField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoPvETimer" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAutoPvEUseSystemTimeField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoPvEUseSystemTime" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bUsingStructureDestructionTagField() { static NativeFieldOffset f{ "AShooterGameMode.bUsingStructureDestructionTag" }; return *GetNativePointerField<bool*>(this, f); }
	FName& StructureDestructionTagField() { static NativeFieldOffset f{ "AShooterGameMode.StructureDestructionTag" }; return *GetNativePointerField<FName*>(this, f); }
	float& AutoPvEStartTimeSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.AutoPvEStartTimeSeconds" }; return *GetNativePointerField<float*>(this, f); }
	float& AutoPvEStopTimeSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.AutoPvEStopTimeSeconds" }; return *GetNativePointerField<float*>(this, f); }
	int& TributeItemExpirationSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.TributeItemExpirationSeconds" }; return *GetNativePointerField<int*>(this, f); }
	int& TributeDinoExpirationSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.TributeDinoExpirationSeconds" }; return *GetNativePointerField<int*>(this, f); }
	int& TributeCharacterExpirationSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.TributeCharacterExpirationSeconds" }; return *GetNativePointerField<int*>(this, f); }
	bool& PreventDownloadSurvivorsField() { static NativeFieldOffset f{ "AShooterGameMode.PreventDownloadSurvivors" }; return *GetNativePointerField<bool*>(this, f); }
	bool& PreventDownloadItemsField() { static NativeFieldOffset f{ "AShooterGameMode.PreventDownloadItems" }; return *GetNativePointerField<bool*>(this, f); }
	bool& PreventDownloadDinosField() { static NativeFieldOffset f{ "AShooterGameMode.PreventDownloadDinos" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventUploadSurvivorsField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventUploadSurvivors" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventUploadItemsField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventUploadItems" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventUploadDinosField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventUploadDinos" }; return *GetNativePointerField<bool*>(this, f); }
	int& MaxTributeItemsField() { static NativeFieldOffset f{ "AShooterGameMode.MaxTributeItems" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxTributeDinosField() { static NativeFieldOffset f{ "AShooterGameMode.MaxTributeDinos" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxTributeCharactersField() { static NativeFieldOffset f{ "AShooterGameMode.MaxTributeCharacters" }; return *GetNativePointerField<int*>(this, f); }
	bool& bIncreasePvPRespawnIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.bIncreasePvPRespawnInterval" }; return *GetNativePointerField<bool*>(this, f); }
	float& IncreasePvPRespawnIntervalCheckPeriodField() { static NativeFieldOffset f{ "AShooterGameMode.IncreasePvPRespawnIntervalCheckPeriod" }; return *GetNativePointerField<float*>(this, f); }
	float& IncreasePvPRespawnIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.IncreasePvPRespawnIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& IncreasePvPRespawnIntervalBaseAmountField() { static NativeFieldOffset f{ "AShooterGameMode.IncreasePvPRespawnIntervalBaseAmount" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourceNoReplenishRadiusStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.ResourceNoReplenishRadiusStructures" }; return *GetNativePointerField<float*>(this, f); }
	float& ResourceNoReplenishRadiusPlayersField() { static NativeFieldOffset f{ "AShooterGameMode.ResourceNoReplenishRadiusPlayers" }; return *GetNativePointerField<float*>(this, f); }
	float& CropGrowthSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CropGrowthSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& LayEggIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.LayEggIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PoopIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PoopIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CropDecaySpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CropDecaySpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAllowChatFromDeadNonAdminsField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowChatFromDeadNonAdmins" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowDisablingSpectatorField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowDisablingSpectator" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEDisableFriendlyFireField() { static NativeFieldOffset f{ "AShooterGameMode.bPvEDisableFriendlyFire" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bFlyerPlatformAllowUnalignedDinoBasingField() { static NativeFieldOffset f{ "AShooterGameMode.bFlyerPlatformAllowUnalignedDinoBasing" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowUnclaimDinosField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowUnclaimDinos" }; return *GetNativePointerField<bool*>(this, f); }
	int& MaxPerTribePlatformSaddleStructureLimitField() { static NativeFieldOffset f{ "AShooterGameMode.MaxPerTribePlatformSaddleStructureLimit" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxPlatformSaddleStructureLimitField() { static NativeFieldOffset f{ "AShooterGameMode.MaxPlatformSaddleStructureLimit" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxDinoBaseLevelField() { static NativeFieldOffset f{ "AShooterGameMode.MaxDinoBaseLevel" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxNumberOfPlayersInTribeField() { static NativeFieldOffset f{ "AShooterGameMode.MaxNumberOfPlayersInTribe" }; return *GetNativePointerField<int*>(this, f); }
	float& TribeSlotReuseCooldownField() { static NativeFieldOffset f{ "AShooterGameMode.TribeSlotReuseCooldown" }; return *GetNativePointerField<float*>(this, f); }
	float& MatingIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.MatingIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& EggHatchSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.EggHatchSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& BabyMatureSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BabyMatureSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& BabyFoodConsumptionSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BabyFoodConsumptionSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	int& CurrentPlatformSaddleStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentPlatformSaddleStructures" }; return *GetNativePointerField<int*>(this, f); }
	FieldArray<float, 12> PerLevelStatsMultiplier_PlayerField() { static NativeFieldOffset f{ "AShooterGameMode.PerLevelStatsMultiplier_Player" }; return { this, f }; }
	FieldArray<float, 12> PerLevelStatsMultiplier_DinoTamedField() { static NativeFieldOffset f{ "AShooterGameMode.PerLevelStatsMultiplier_DinoTamed" }; return { this, f }; }
	FieldArray<float, 12> PerLevelStatsMultiplier_DinoTamed_AddField() { static NativeFieldOffset f{ "AShooterGameMode.PerLevelStatsMultiplier_DinoTamed_Add" }; return { this, f }; }
	FieldArray<float, 12> PerLevelStatsMultiplier_DinoTamed_AffinityField() { static NativeFieldOffset f{ "AShooterGameMode.PerLevelStatsMultiplier_DinoTamed_Affinity" }; return { this, f }; }
	FieldArray<float, 12> PerLevelStatsMultiplier_DinoWildField() { static NativeFieldOffset f{ "AShooterGameMode.PerLevelStatsMultiplier_DinoWild" }; return { this, f }; }
	FieldArray<int, 8> ItemStatClampsField() { static NativeFieldOffset f{ "AShooterGameMode.ItemStatClamps" }; return { this, f }; }
	bool& bCustomGameModeAllowSpectatorJoinAfterMatchStartField() { static NativeFieldOffset f{ "AShooterGameMode.bCustomGameModeAllowSpectatorJoinAfterMatchStart" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bGameplayLogEnabledField() { static NativeFieldOffset f{ "AShooterGameMode.bGameplayLogEnabled" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerGameLogEnabledField() { static NativeFieldOffset f{ "AShooterGameMode.bServerGameLogEnabled" }; return *GetNativePointerField<bool*>(this, f); }
	TSubclassOf<UPrimalItem>& BonusSupplyCrateItemClassField() { static NativeFieldOffset f{ "AShooterGameMode.BonusSupplyCrateItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& BonusSupplyCrateItemGiveIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.BonusSupplyCrateItemGiveInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& StructureDamageRepairCooldownField() { static NativeFieldOffset f{ "AShooterGameMode.StructureDamageRepairCooldown" }; return *GetNativePointerField<float*>(this, f); }
	float& CustomRecipeEffectivenessMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CustomRecipeEffectivenessMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CustomRecipeSkillMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CustomRecipeSkillMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FString& BonusSupplyCrateItemStringField() { static NativeFieldOffset f{ "AShooterGameMode.BonusSupplyCrateItemString" }; return *GetNativePointerField<FString*>(this, f); }
	bool& bPvEAllowTribeWarField() { static NativeFieldOffset f{ "AShooterGameMode.bPvEAllowTribeWar" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvEAllowTribeWarCancelField() { static NativeFieldOffset f{ "AShooterGameMode.bPvEAllowTribeWarCancel" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCustomRecipesField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowCustomRecipes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPassiveDefensesDamageRiderlessDinosField() { static NativeFieldOffset f{ "AShooterGameMode.bPassiveDefensesDamageRiderlessDinos" }; return *GetNativePointerField<bool*>(this, f); }
	long double& LastBonusSupplyCrateItemGiveTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastBonusSupplyCrateItemGiveTime" }; return *GetNativePointerField<long double*>(this, f); }
	bool& bEnableDeathTeamSpectatorField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableDeathTeamSpectator" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bTribeStoreCharacterConfigurationField() { static NativeFieldOffset f{ "AShooterGameMode.bTribeStoreCharacterConfiguration" }; return *GetNativePointerField<bool*>(this, f); }
	TMap<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, FDefaultSetAllocator, TDefaultMapKeyFuncs<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, 0> >& PvEActiveTribeWarsField() { static NativeFieldOffset f{ "AShooterGameMode.PvEActiveTribeWars" }; return *GetNativePointerField<TMap<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, FDefaultSetAllocator, TDefaultMapKeyFuncs<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, 0> >*>(this, f); }
	TMap<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, FDefaultSetAllocator, TDefaultMapKeyFuncs<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, 0> >& TribeAlliesField() { static NativeFieldOffset f{ "AShooterGameMode.TribeAllies" }; return *GetNativePointerField<TMap<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, FDefaultSetAllocator, TDefaultMapKeyFuncs<int, TSet<int, DefaultKeyFuncs<int, 0>, FDefaultSetAllocator>, 0> >*>(this, f); }
	TMap<unsigned __int64, UPrimalPlayerData*, FDefaultSetAllocator, TDefaultMapKeyFuncs<unsigned __int64, UPrimalPlayerData*, 0> >& IDtoPlayerDatasField() { static NativeFieldOffset f{ "AShooterGameMode.IDtoPlayerDatas" }; return *GetNativePointerField<TMap<unsigned __int64, UPrimalPlayerData*, FDefaultSetAllocator, TDefaultMapKeyFuncs<unsigned __int64, UPrimalPlayerData*, 0> >*>(this, f); }
	int& MaxTribeLogsField() { static NativeFieldOffset f{ "AShooterGameMode.MaxTribeLogs" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxPersonalTamedDinosField() { static NativeFieldOffset f{ "AShooterGameMode.MaxPersonalTamedDinos" }; return *GetNativePointerField<int*>(this, f); }
	int& PersonalTamedDinosSaddleStructureCostField() { static NativeFieldOffset f{ "AShooterGameMode.PersonalTamedDinosSaddleStructureCost" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FString>& CachedGameLogField() { static NativeFieldOffset f{ "AShooterGameMode.CachedGameLog" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	bool& bDisableFriendlyFireField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableFriendlyFire" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowInactiveTribesField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowInactiveTribes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bForceMapPlayerLocationField() { static NativeFieldOffset f{ "AShooterGameMode.bForceMapPlayerLocation" }; return *GetNativePointerField<bool*>(this, f); }
	float& DinoHarvestingDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoHarvestingDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PlayerHarvestingDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerHarvestingDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DinoTurretDamageMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.DinoTurretDamageMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bDisableLootCratesField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableLootCrates" }; return *GetNativePointerField<bool*>(this, f); }
	float& ExtinctionEventTimeIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.ExtinctionEventTimeInterval" }; return *GetNativePointerField<float*>(this, f); }
	bool& bEnableExtraStructurePreventionVolumesField() { static NativeFieldOffset f{ "AShooterGameMode.bEnableExtraStructurePreventionVolumes" }; return *GetNativePointerField<bool*>(this, f); }
	unsigned int& NextExtinctionEventUTCField() { static NativeFieldOffset f{ "AShooterGameMode.NextExtinctionEventUTC" }; return *GetNativePointerField<unsigned int*>(this, f); }
	bool& bForceAllowCaveFlyersField() { static NativeFieldOffset f{ "AShooterGameMode.bForceAllowCaveFlyers" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDoExtinctionEventField() { static NativeFieldOffset f{ "AShooterGameMode.bDoExtinctionEvent" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPreventOfflinePvPField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventOfflinePvP" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bPvPDinoDecayField() { static NativeFieldOffset f{ "AShooterGameMode.bPvPDinoDecay" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bOverideStructurePlatformPreventionField() { static NativeFieldOffset f{ "AShooterGameMode.bOverideStructurePlatformPrevention" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowAnyoneBabyImprintCuddleField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowAnyoneBabyImprintCuddle" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableImprintDinoBuffField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableImprintDinoBuff" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bOnlyDecayUnsnappedCoreStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bOnlyDecayUnsnappedCoreStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bFastDecayUnsnappedCoreStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bFastDecayUnsnappedCoreStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDestroyUnconnectedWaterPipesField() { static NativeFieldOffset f{ "AShooterGameMode.bDestroyUnconnectedWaterPipes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowCrateSpawnsOnTopOfStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowCrateSpawnsOnTopOfStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bNotifyAdminCommandsInChatField() { static NativeFieldOffset f{ "AShooterGameMode.bNotifyAdminCommandsInChat" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bRandomSupplyCratePointsField() { static NativeFieldOffset f{ "AShooterGameMode.bRandomSupplyCratePoints" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bOfficialDisableGenesisMissionsField() { static NativeFieldOffset f{ "AShooterGameMode.bOfficialDisableGenesisMissions" }; return *GetNativePointerField<bool*>(this, f); }
	float& PreventOfflinePvPIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.PreventOfflinePvPInterval" }; return *GetNativePointerField<float*>(this, f); }
	bool& bShowFloatingDamageTextField() { static NativeFieldOffset f{ "AShooterGameMode.bShowFloatingDamageText" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowTekSuitPowersInGenesisField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowTekSuitPowersInGenesis" }; return *GetNativePointerField<bool*>(this, f); }
	FString& CurrentMerticsURLField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentMerticsURL" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CurrentNotificationURLField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentNotificationURL" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CurrentAdminCommandTrackingAPIKeyField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentAdminCommandTrackingAPIKey" }; return *GetNativePointerField<FString*>(this, f); }
	FString& CurrentAdminCommandTrackingURLField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentAdminCommandTrackingURL" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FItemCraftingCostOverride>& OverrideItemCraftingCostsField() { static NativeFieldOffset f{ "AShooterGameMode.OverrideItemCraftingCosts" }; return *GetNativePointerField<TArray<FItemCraftingCostOverride>*>(this, f); }
	TArray<FConfigItemCraftingCostOverride>& ConfigOverrideItemCraftingCostsField() { static NativeFieldOffset f{ "AShooterGameMode.ConfigOverrideItemCraftingCosts" }; return *GetNativePointerField<TArray<FConfigItemCraftingCostOverride>*>(this, f); }
	TArray<FConfigMaxItemQuantityOverride>& ConfigOverrideItemMaxQuantityField() { static NativeFieldOffset f{ "AShooterGameMode.ConfigOverrideItemMaxQuantity" }; return *GetNativePointerField<TArray<FConfigMaxItemQuantityOverride>*>(this, f); }
	TArray<FConfigSupplyCrateItemsOverride>& ConfigOverrideSupplyCrateItemsField() { static NativeFieldOffset f{ "AShooterGameMode.ConfigOverrideSupplyCrateItems" }; return *GetNativePointerField<TArray<FConfigSupplyCrateItemsOverride>*>(this, f); }
	TArray<FConfigNPCSpawnEntriesContainer>& ConfigOverrideNPCSpawnEntriesContainerField() { static NativeFieldOffset f{ "AShooterGameMode.ConfigOverrideNPCSpawnEntriesContainer" }; return *GetNativePointerField<TArray<FConfigNPCSpawnEntriesContainer>*>(this, f); }
	TArray<FConfigNPCSpawnEntriesContainer>& ConfigAddNPCSpawnEntriesContainerField() { static NativeFieldOffset f{ "AShooterGameMode.ConfigAddNPCSpawnEntriesContainer" }; return *GetNativePointerField<TArray<FConfigNPCSpawnEntriesContainer>*>(this, f); }
	TArray<FConfigNPCSpawnEntriesContainer>& ConfigSubtractNPCSpawnEntriesContainerField() { static NativeFieldOffset f{ "AShooterGameMode.ConfigSubtractNPCSpawnEntriesContainer" }; return *GetNativePointerField<TArray<FConfigNPCSpawnEntriesContainer>*>(this, f); }
	float& BabyImprintingStatScaleMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BabyImprintingStatScaleMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& BabyCuddleIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BabyCuddleIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& BabyCuddleGracePeriodMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BabyCuddleGracePeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& BabyCuddleLoseImprintQualitySpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BabyCuddleLoseImprintQualitySpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& HairGrowthSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.HairGrowthSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bPreventDiseasesField() { static NativeFieldOffset f{ "AShooterGameMode.bPreventDiseases" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bNonPermanentDiseasesField() { static NativeFieldOffset f{ "AShooterGameMode.bNonPermanentDiseases" }; return *GetNativePointerField<bool*>(this, f); }
	UAllClustersInventory* AllClustersInventoryField() { static NativeFieldOffset f{ "AShooterGameMode.AllClustersInventory" }; return *GetNativePointerField<UAllClustersInventory**>(this, f); }
	int& SaveForceRespawnDinosVersionField() { static NativeFieldOffset f{ "AShooterGameMode.SaveForceRespawnDinosVersion" }; return *GetNativePointerField<int*>(this, f); }
	unsigned __int64& ServerIDField() { static NativeFieldOffset f{ "AShooterGameMode.ServerID" }; return *GetNativePointerField<unsigned __int64*>(this, f); }
	int& LoadForceRespawnDinosVersionField() { static NativeFieldOffset f{ "AShooterGameMode.LoadForceRespawnDinosVersion" }; return *GetNativePointerField<int*>(this, f); }
	bool& bIsLoadedServerField() { static NativeFieldOffset f{ "AShooterGameMode.bIsLoadedServer" }; return *GetNativePointerField<bool*>(this, f); }
	TMap<FString, FTributePlayerTribeInfo, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FTributePlayerTribeInfo, 0> >& TributePlayerTribeInfosField() { static NativeFieldOffset f{ "AShooterGameMode.TributePlayerTribeInfos" }; return *GetNativePointerField<TMap<FString, FTributePlayerTribeInfo, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FTributePlayerTribeInfo, 0> >*>(this, f); }
	TArray<int>& SupportedSpawnRegionsField() { static NativeFieldOffset f{ "AShooterGameMode.SupportedSpawnRegions" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	bool& bServerUseDinoListField() { static NativeFieldOffset f{ "AShooterGameMode.bServerUseDinoList" }; return *GetNativePointerField<bool*>(this, f); }
	float& MaxAllowedRespawnIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.MaxAllowedRespawnInterval" }; return *GetNativePointerField<float*>(this, f); }
	bool& bUseDinoLevelUpAnimationsField() { static NativeFieldOffset f{ "AShooterGameMode.bUseDinoLevelUpAnimations" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableDinoTamingField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableDinoTaming" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableDinoRidingField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableDinoRiding" }; return *GetNativePointerField<bool*>(this, f); }
	float& MinimumDinoReuploadIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.MinimumDinoReuploadInterval" }; return *GetNativePointerField<float*>(this, f); }
	int& SaveGameCustomVersionField() { static NativeFieldOffset f{ "AShooterGameMode.SaveGameCustomVersion" }; return *GetNativePointerField<int*>(this, f); }
	float& OverrideOfficialDifficultyField() { static NativeFieldOffset f{ "AShooterGameMode.OverrideOfficialDifficulty" }; return *GetNativePointerField<float*>(this, f); }
	FieldArray<float, 12> PlayerBaseStatMultipliersField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerBaseStatMultipliers" }; return { this, f }; }
	int& NPCActiveCountTamedField() { static NativeFieldOffset f{ "AShooterGameMode.NPCActiveCountTamed" }; return *GetNativePointerField<int*>(this, f); }
	int& NPCActiveCountField() { static NativeFieldOffset f{ "AShooterGameMode.NPCActiveCount" }; return *GetNativePointerField<int*>(this, f); }
	int& NPCCountField() { static NativeFieldOffset f{ "AShooterGameMode.NPCCount" }; return *GetNativePointerField<int*>(this, f); }
	float& MatingSpeedMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.MatingSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& FastDecayIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.FastDecayInterval" }; return *GetNativePointerField<float*>(this, f); }
	bool& bUseSingleplayerSettingsField() { static NativeFieldOffset f{ "AShooterGameMode.bUseSingleplayerSettings" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bUseCorpseLocatorField() { static NativeFieldOffset f{ "AShooterGameMode.bUseCorpseLocator" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableGenesisMissionsField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableGenesisMissions" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableStructurePlacementCollisionField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableStructurePlacementCollision" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bForceUseInventoryAppendsField() { static NativeFieldOffset f{ "AShooterGameMode.bForceUseInventoryAppends" }; return *GetNativePointerField<bool*>(this, f); }
	float& SupplyCrateLootQualityMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.SupplyCrateLootQualityMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& FishingLootQualityMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.FishingLootQualityMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& ItemStackSizeMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.ItemStackSizeMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& CraftingSkillBonusMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.CraftingSkillBonusMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bAllowPlatformSaddleMultiFloorsField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowPlatformSaddleMultiFloors" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowUnlimitedRespecsField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowUnlimitedRespecs" }; return *GetNativePointerField<bool*>(this, f); }
	float& FuelConsumptionIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.FuelConsumptionIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	int& DestroyTamesOverLevelClampField() { static NativeFieldOffset f{ "AShooterGameMode.DestroyTamesOverLevelClamp" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxAlliancesPerTribeField() { static NativeFieldOffset f{ "AShooterGameMode.MaxAlliancesPerTribe" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxTribesPerAllianceField() { static NativeFieldOffset f{ "AShooterGameMode.MaxTribesPerAlliance" }; return *GetNativePointerField<int*>(this, f); }
	bool& bDisableDinoDecayClaimingField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableDinoDecayClaiming" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bDisableNonTribePinAccessField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableNonTribePinAccess" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bUseTameLimitForStructuresOnlyField() { static NativeFieldOffset f{ "AShooterGameMode.bUseTameLimitForStructuresOnly" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bLimitTurretsInRangeField() { static NativeFieldOffset f{ "AShooterGameMode.bLimitTurretsInRange" }; return *GetNativePointerField<bool*>(this, f); }
	float& LimitTurretsRangeField() { static NativeFieldOffset f{ "AShooterGameMode.LimitTurretsRange" }; return *GetNativePointerField<float*>(this, f); }
	int& LimitTurretsNumField() { static NativeFieldOffset f{ "AShooterGameMode.LimitTurretsNum" }; return *GetNativePointerField<int*>(this, f); }
	bool& bHardLimitTurretsInRangeField() { static NativeFieldOffset f{ "AShooterGameMode.bHardLimitTurretsInRange" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAutoUnlockAllEngramsField() { static NativeFieldOffset f{ "AShooterGameMode.bAutoUnlockAllEngrams" }; return *GetNativePointerField<bool*>(this, f); }
	long double& ServerLastForceRespawnWildDinosTimeField() { static NativeFieldOffset f{ "AShooterGameMode.ServerLastForceRespawnWildDinosTime" }; return *GetNativePointerField<long double*>(this, f); }
	FString& UseStructurePreventionVolumeTagStringField() { static NativeFieldOffset f{ "AShooterGameMode.UseStructurePreventionVolumeTagString" }; return *GetNativePointerField<FString*>(this, f); }
	float& BaseTemperatureMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.BaseTemperatureMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bForceAllowAllStructuresField() { static NativeFieldOffset f{ "AShooterGameMode.bForceAllowAllStructures" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bForceAllowAscensionItemDownloadsField() { static NativeFieldOffset f{ "AShooterGameMode.bForceAllowAscensionItemDownloads" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bShowCreativeModeField() { static NativeFieldOffset f{ "AShooterGameMode.bShowCreativeMode" }; return *GetNativePointerField<bool*>(this, f); }
	float& LimitNonPlayerDroppedItemsRangeField() { static NativeFieldOffset f{ "AShooterGameMode.LimitNonPlayerDroppedItemsRange" }; return *GetNativePointerField<float*>(this, f); }
	int& LimitNonPlayerDroppedItemsCountField() { static NativeFieldOffset f{ "AShooterGameMode.LimitNonPlayerDroppedItemsCount" }; return *GetNativePointerField<int*>(this, f); }
	float& GlobalPoweredBatteryDurabilityDecreasePerSecondField() { static NativeFieldOffset f{ "AShooterGameMode.GlobalPoweredBatteryDurabilityDecreasePerSecond" }; return *GetNativePointerField<float*>(this, f); }
	float& SingleplayerSettingsCorpseLifespanMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.SingleplayerSettingsCorpseLifespanMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& UseCorpseLifeSpanMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.UseCorpseLifeSpanMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& TimePeriodToHideDisconnectedPlayersField() { static NativeFieldOffset f{ "AShooterGameMode.TimePeriodToHideDisconnectedPlayers" }; return *GetNativePointerField<float*>(this, f); }
	bool& bUseBPPreSpawnedDinoField() { static NativeFieldOffset f{ "AShooterGameMode.bUseBPPreSpawnedDino" }; return *GetNativePointerField<bool*>(this, f); }
	float& PreventOfflinePvPConnectionInvincibleIntervalField() { static NativeFieldOffset f{ "AShooterGameMode.PreventOfflinePvPConnectionInvincibleInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& TamedDinoCharacterFoodDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.TamedDinoCharacterFoodDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& WildDinoCharacterFoodDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.WildDinoCharacterFoodDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& WildDinoTorporDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.WildDinoTorporDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PassiveTameIntervalMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.PassiveTameIntervalMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& TamedDinoTorporDrainMultiplierField() { static NativeFieldOffset f{ "AShooterGameMode.TamedDinoTorporDrainMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	bool& bDisableWeatherFogField() { static NativeFieldOffset f{ "AShooterGameMode.bDisableWeatherFog" }; return *GetNativePointerField<bool*>(this, f); }
	float& MeshCheckingRayDistanceField() { static NativeFieldOffset f{ "AShooterGameMode.MeshCheckingRayDistance" }; return *GetNativePointerField<float*>(this, f); }
	float& MeshCheckingSubdivisonsField() { static NativeFieldOffset f{ "AShooterGameMode.MeshCheckingSubdivisons" }; return *GetNativePointerField<float*>(this, f); }
	float& MeshCheckingPercentageToFailField() { static NativeFieldOffset f{ "AShooterGameMode.MeshCheckingPercentageToFail" }; return *GetNativePointerField<float*>(this, f); }
	bool& bIgnoreStructuresPreventionVolumesField() { static NativeFieldOffset f{ "AShooterGameMode.bIgnoreStructuresPreventionVolumes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bGenesisUseStructuresPreventionVolumesField() { static NativeFieldOffset f{ "AShooterGameMode.bGenesisUseStructuresPreventionVolumes" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bServerEnableMeshCheckingField() { static NativeFieldOffset f{ "AShooterGameMode.bServerEnableMeshChecking" }; return *GetNativePointerField<bool*>(this, f); }
	FString& ArkServerMetricsKeyField() { static NativeFieldOffset f{ "AShooterGameMode.ArkServerMetricsKey" }; return *GetNativePointerField<FString*>(this, f); }
	FString& ArkServerMetricsURLField() { static NativeFieldOffset f{ "AShooterGameMode.ArkServerMetricsURL" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FString>& CachedArkMetricsPayloadsField() { static NativeFieldOffset f{ "AShooterGameMode.CachedArkMetricsPayloads" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	bool& bCollectArkMetricsField() { static NativeFieldOffset f{ "AShooterGameMode.bCollectArkMetrics" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bLogChatMessagesField() { static NativeFieldOffset f{ "AShooterGameMode.bLogChatMessages" }; return *GetNativePointerField<bool*>(this, f); }
	int& ChatLogFlushIntervalSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.ChatLogFlushIntervalSeconds" }; return *GetNativePointerField<int*>(this, f); }
	int& ChatLogFileSplitIntervalSecondsField() { static NativeFieldOffset f{ "AShooterGameMode.ChatLogFileSplitIntervalSeconds" }; return *GetNativePointerField<int*>(this, f); }
	int& ChatLogMaxAgeInDaysField() { static NativeFieldOffset f{ "AShooterGameMode.ChatLogMaxAgeInDays" }; return *GetNativePointerField<int*>(this, f); }
	TArray<TSharedPtr<FJsonObject, 0>>& ChatMessageBufferField() { static NativeFieldOffset f{ "AShooterGameMode.ChatMessageBuffer" }; return *GetNativePointerField<TArray<TSharedPtr<FJsonObject, 0>>*>(this, f); }
	FString& CurrentChatLogFilenameField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentChatLogFilename" }; return *GetNativePointerField<FString*>(this, f); }
	FDateTime& LastChatLogFlushTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastChatLogFlushTime" }; return *GetNativePointerField<FDateTime*>(this, f); }
	FDateTime& LastChatLogFileCreateTimeField() { static NativeFieldOffset f{ "AShooterGameMode.LastChatLogFileCreateTime" }; return *GetNativePointerField<FDateTime*>(this, f); }
	bool& bDamageEventLoggingEnabledField() { static NativeFieldOffset f{ "AShooterGameMode.bDamageEventLoggingEnabled" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bIsGenesisMapField() { static NativeFieldOffset f{ "AShooterGameMode.bIsGenesisMap" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<TSharedPtr<FJsonObject, 0>>& DamageEventBufferField() { static NativeFieldOffset f{ "AShooterGameMode.DamageEventBuffer" }; return *GetNativePointerField<TArray<TSharedPtr<FJsonObject, 0>>*>(this, f); }
	FString& CurrentDamageEventLogFilenameField() { static NativeFieldOffset f{ "AShooterGameMode.CurrentDamageEventLogFilename" }; return *GetNativePointerField<FString*>(this, f); }
	TMap<FName, int, FDefaultSetAllocator, TDefaultMapKeyFuncs<FName, int, 0> >& MissionTagToLeaderboardEntryField() { static NativeFieldOffset f{ "AShooterGameMode.MissionTagToLeaderboardEntry" }; return *GetNativePointerField<TMap<FName, int, FDefaultSetAllocator, TDefaultMapKeyFuncs<FName, int, 0> >*>(this, f); }
	FName& UseStructurePreventionVolumeTagField() { static NativeFieldOffset f{ "AShooterGameMode.UseStructurePreventionVolumeTag" }; return *GetNativePointerField<FName*>(this, f); }
	bool& bHasCovertedToStoreField() { static NativeFieldOffset f{ "AShooterGameMode.bHasCovertedToStore" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowStoredDatasField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowStoredDatas" }; return *GetNativePointerField<bool*>(this, f); }
	FDataStore<unsigned int>& TribeDataStoreField() { static NativeFieldOffset f{ "AShooterGameMode.TribeDataStore" }; return *GetNativePointerField<FDataStore<unsigned int>*>(this, f); }
	FDataStore<unsigned __int64>& PlayerDataStoreField() { static NativeFieldOffset f{ "AShooterGameMode.PlayerDataStore" }; return *GetNativePointerField<FDataStore<unsigned __int64>*>(this, f); }
	AOceanDinoManager* TheOceanDinoManagerField() { static NativeFieldOffset f{ "AShooterGameMode.TheOceanDinoManager" }; return *GetNativePointerField<AOceanDinoManager**>(this, f); }
	bool& bCheckedForOceanDinoManagerField() { static NativeFieldOffset f{ "AShooterGameMode.bCheckedForOceanDinoManager" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bParseServerToJsonField() { static NativeFieldOffset f{ "AShooterGameMode.bParseServerToJson" }; return *GetNativePointerField<bool*>(this, f); }
	bool& bAllowFlyerSpeedLevelingField() { static NativeFieldOffset f{ "AShooterGameMode.bAllowFlyerSpeedLeveling" }; return *GetNativePointerField<bool*>(this, f); }

	// Functions

	static UClass* StaticClass() { static NativeStaticClass f{ "AShooterGameMode.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	bool AllowAddXP(UPrimalCharacterStatusComponent* forComp) { static NativeFunction f{ "AShooterGameMode.AllowAddXP" }; return NativeCall<bool, UPrimalCharacterStatusComponent*>(this, f, forComp); }
	void CheckArkTributeAvailability() { static NativeFunction f{ "AShooterGameMode.CheckArkTributeAvailability" }; NativeCall<void>(this, f); }
	void ArkTributeAvailabilityRequestComplete(TSharedPtr<IHttpRequest, 0> HttpRequest, TSharedPtr<IHttpResponse, 1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameMode.ArkTributeAvailabilityRequestComplete" }; NativeCall<void, TSharedPtr<IHttpRequest, 0>, TSharedPtr<IHttpResponse, 1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	void IncrementPreLoginMetric() { static NativeFunction f{ "AShooterGameMode.IncrementPreLoginMetric" }; NativeCall<void>(this, f); }
	void InitGame(FString* MapName, FString* Options, FString* ErrorMessage) { static NativeFunction f{ "AShooterGameMode.InitGame" }; NativeCall<void, FString*, FString*, FString*>(this, f, MapName, Options, ErrorMessage); }
	void InitOptionBool(FString Commandline, FString Section, FString Option, bool bDefaultValue) { static NativeFunction f{ "AShooterGameMode.InitOptionBool" }; NativeCall<void, FString, FString, FString, bool>(this, f, Commandline, Section, Option, bDefaultValue); }
	void InitOptionString(FString Commandline, FString Section, FString Option) { static NativeFunction f{ "AShooterGameMode.InitOptionString" }; NativeCall<void, FString, FString, FString>(this, f, Commandline, Section, Option); }
	void InitOptionFloat(FString Commandline, FString Section, FString Option, float CurrentValue) { static NativeFunction f{ "AShooterGameMode.InitOptionFloat" }; NativeCall<void, FString, FString, FString, float>(this, f, Commandline, Section, Option, CurrentValue); }
	bool GetServerSettingsFloat(FString* Keyvalue, float* OutFloat) { static NativeFunction f{ "AShooterGameMode.GetServerSettingsFloat" }; return NativeCall<bool, FString*, float*>(this, f, Keyvalue, OutFloat); }
	void SingleplayerSetupValues() { static NativeFunction f{ "AShooterGameMode.SingleplayerSetupValues" }; NativeCall<void>(this, f); }
	void InitOptionInteger(FString Commandline, FString Section, FString Option, int CurrentValue) { static NativeFunction f{ "AShooterGameMode.InitOptionInteger" }; NativeCall<void, FString, FString, FString, int>(this, f, Commandline, Section, Option, CurrentValue); }
	bool GetBoolOption(FString* Options, FString* ParseString, bool CurrentValue) { static NativeFunction f{ "AShooterGameMode.GetBoolOption" }; return NativeCall<bool, FString*, FString*, bool>(this, f, Options, ParseString, CurrentValue); }
	float GetFloatOption(FString* Options, FString* ParseString, float CurrentValue) { static NativeFunction f{ "AShooterGameMode.GetFloatOption" }; return NativeCall<float, FString*, FString*, float>(this, f, Options, ParseString, CurrentValue); }
	int GetIntOption(FString* Options, FString* ParseString, int CurrentValue) { static NativeFunction f{ "AShooterGameMode.GetIntOption" }; return NativeCall<int, FString*, FString*, int>(this, f, Options, ParseString, CurrentValue); }
	void InitOptions(FString Options) { static NativeFunction f{ "AShooterGameMode.InitOptions" }; NativeCall<void, FString>(this, f, Options); }
	bool GetBoolOptionIni(FString Section, FString OptionName, bool bDefaultValue) { static NativeFunction f{ "AShooterGameMode.GetBoolOptionIni" }; return NativeCall<bool, FString, FString, bool>(this, f, Section, OptionName, bDefaultValue); }
	float GetFloatOptionIni(FString Section, FString OptionName) { static NativeFunction f{ "AShooterGameMode.GetFloatOptionIni" }; return NativeCall<float, FString, FString>(this, f, Section, OptionName); }
	int GetIntOptionIni(FString Section, FString OptionName) { static NativeFunction f{ "AShooterGameMode.GetIntOptionIni" }; return NativeCall<int, FString, FString>(this, f, Section, OptionName); }
	FString* GetStringOption(FString* result, FString Section, FString OptionName) { static NativeFunction f{ "AShooterGameMode.GetStringOption" }; return NativeCall<FString*, FString*, FString, FString>(this, f, result, Section, OptionName); }
	void SaveWorld(bool bForceWaitOnSaveToComplete) { static NativeFunction f{ "AShooterGameMode.SaveWorld" }; NativeCall<void, bool>(this, f, bForceWaitOnSaveToComplete); }
	void ClearSavesAndRestart() { static NativeFunction f{ "AShooterGameMode.ClearSavesAndRestart" }; NativeCall<void>(this, f); }
	bool LoadWorld() { static NativeFunction f{ "AShooterGameMode.LoadWorld" }; return NativeCall<bool>(this, f); }
	TSubclassOf<AGameSession>* GetGameSessionClass(TSubclassOf<AGameSession>* result) { static NativeFunction f{ "AShooterGameMode.GetGameSessionClass" }; return NativeCall<TSubclassOf<AGameSession>*, TSubclassOf<AGameSession>*>(this, f, result); }
	bool ReadyToStartMatch() { static NativeFunction f{ "AShooterGameMode.ReadyToStartMatch" }; return NativeCall<bool>(this, f); }
	void HandleMatchHasStarted() { static NativeFunction f{ "AShooterGameMode.HandleMatchHasStarted" }; NativeCall<void>(this, f); }
	void EndPlay(EEndPlayReason::Type EndPlayReason) { static NativeFunction f{ "AShooterGameMode.EndPlay" }; NativeCall<void, EEndPlayReason::Type>(this, f, EndPlayReason); }
	void HandleLeavingMap() { static NativeFunction f{ "AShooterGameMode.HandleLeavingMap" }; NativeCall<void>(this, f); }
	void RequestFinishAndExitToMainMenu() { static NativeFunction f{ "AShooterGameMode.RequestFinishAndExitToMainMenu" }; NativeCall<void>(this, f); }
	void PreLogin(FString* Options, FString* Address, TSharedPtr<FUniqueNetId, 0>* UniqueId, FString* authToken, FString* ErrorMessage, UNetConnection* Connection = nullptr) { static NativeFunction f{ "AShooterGameMode.PreLogin" }; NativeCall<void, FString*, FString*, TSharedPtr<FUniqueNetId, 0>*, FString*, FString*, UNetConnection*>(this, f, Options, Address, UniqueId, authToken, ErrorMessage, Connection); }
	bool ExtraPreLoginChecksBeforeWelcomePlayer(UNetConnection* Connection) { static NativeFunction f{ "AShooterGameMode.ExtraPreLoginChecksBeforeWelcomePlayer" }; return NativeCall<bool, UNetConnection*>(this, f, Connection); }
	void PostLogin(APlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.PostLogin" }; NativeCall<void, APlayerController*>(this, f, NewPlayer); }
	void RemoveLoginLock(TSharedPtr<FUniqueNetId, 0>* UniqueNetId) { static NativeFunction f{ "AShooterGameMode.RemoveLoginLock" }; NativeCall<void, TSharedPtr<FUniqueNetId, 0>*>(this, f, UniqueNetId); }
	TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >* GetBannedMap(TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >* result) { static NativeFunction f{ "AShooterGameMode.GetBannedMap" }; return NativeCall<TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >*, TMap<FString, FString, FDefaultSetAllocator, TDefaultMapKeyFuncs<FString, FString, 0> >*>(this, f, result); }
	TArray<FString>* GetWhiteListedMap(TArray<FString>* result) { static NativeFunction f{ "AShooterGameMode.GetWhiteListedMap" }; return NativeCall<TArray<FString>*, TArray<FString>*>(this, f, result); }
	void Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, UDamageType* DamageType) { static NativeFunction f{ "AShooterGameMode.Killed" }; NativeCall<void, AController*, AController*, APawn*, UDamageType*>(this, f, Killer, KilledPlayer, KilledPawn, DamageType); }
	float ModifyDamage(float Damage, AActor* DamagedActor, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "AShooterGameMode.ModifyDamage" }; return NativeCall<float, float, AActor*, FDamageEvent*, AController*, AActor*>(this, f, Damage, DamagedActor, DamageEvent, EventInstigator, DamageCauser); }
	bool CanDealDamage(AShooterPlayerState* DamageCauserPlayerState, AShooterPlayerState* DamagedPlayerState) { static NativeFunction f{ "AShooterGameMode.CanDealDamage" }; return NativeCall<bool, AShooterPlayerState*, AShooterPlayerState*>(this, f, DamageCauserPlayerState, DamagedPlayerState); }
	template <typename S, typename P, std::enable_if_t<std::is_same_v<S, APlayerStart> && std::is_base_of_v<AController, P>, int> = 0>
	[[deprecated("not in this game build, use CanDealDamage(AShooterPlayerState*, AShooterPlayerState*)")]] bool CanDealDamage(S*, P*) { ReportDeprecatedApiUse("AShooterGameMode.CanDealDamage(APlayerStart*, AController*)"); return false; }
	TSubclassOf<UObject>* GetDefaultPawnClassForController_Implementation(TSubclassOf<UObject>* result, AController* InController) { static NativeFunction f{ "AShooterGameMode.GetDefaultPawnClassForController_Implementation" }; return NativeCall<TSubclassOf<UObject>*, TSubclassOf<UObject>*, AController*>(this, f, result, InController); }
	AActor* ChoosePlayerStart_Implementation(AController* Player) { static NativeFunction f{ "AShooterGameMode.ChoosePlayerStart_Implementation" }; return NativeCall<AActor*, AController*>(this, f, Player); }
	bool CheckJoinInProgress_Implementation(bool bIsFromLogin, APlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.CheckJoinInProgress_Implementation" }; return NativeCall<bool, bool, APlayerController*>(this, f, bIsFromLogin, NewPlayer); }
	bool IsSpawnpointPreferred(APlayerStart* SpawnPoint, AController* Player) { static NativeFunction f{ "AShooterGameMode.IsSpawnpointPreferred" }; return NativeCall<bool, APlayerStart*, AController*>(this, f, SpawnPoint, Player); }
	bool IsFirstPlayerSpawn(APlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.IsFirstPlayerSpawn" }; return NativeCall<bool, APlayerController*>(this, f, NewPlayer); }
	void IncrementNumDeaths(FString* PlayerDataID) { static NativeFunction f{ "AShooterGameMode.IncrementNumDeaths" }; NativeCall<void, FString*>(this, f, PlayerDataID); }
	int GetNumDeaths(FString* PlayerDataID) { static NativeFunction f{ "AShooterGameMode.GetNumDeaths" }; return NativeCall<int, FString*>(this, f, PlayerDataID); }
	UPrimalPlayerData* GetPlayerData(FString* PlayerDataID) { static NativeFunction f{ "AShooterGameMode.GetPlayerData" }; return NativeCall<UPrimalPlayerData*, FString*>(this, f, PlayerDataID); }
	void StartNewPlayer(APlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.StartNewPlayer" }; NativeCall<void, APlayerController*>(this, f, NewPlayer); }
	void StartNewShooterPlayer(APlayerController* NewPlayer, bool bForceCreateNewPlayerData, bool bIsFromLogin, FPrimalPlayerCharacterConfigStruct* charConfig, UPrimalPlayerData* ArkPlayerData) { static NativeFunction f{ "AShooterGameMode.StartNewShooterPlayer" }; NativeCall<void, APlayerController*, bool, bool, FPrimalPlayerCharacterConfigStruct*, UPrimalPlayerData*>(this, f, NewPlayer, bForceCreateNewPlayerData, bIsFromLogin, charConfig, ArkPlayerData); }
	void HandleTransferCharacterDialogResult(bool bAccept, AShooterPlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.HandleTransferCharacterDialogResult" }; NativeCall<void, bool, AShooterPlayerController*>(this, f, bAccept, NewPlayer); }
	void Logout(AController* Exiting) { static NativeFunction f{ "AShooterGameMode.Logout" }; NativeCall<void, AController*>(this, f, Exiting); }
	FVector* GetTracedSpawnLocation(FVector* result, FVector* SpawnLoc, float CharHalfHeight) { static NativeFunction f{ "AShooterGameMode.GetTracedSpawnLocation" }; return NativeCall<FVector*, FVector*, FVector*, float>(this, f, result, SpawnLoc, CharHalfHeight); }
	void SetMessageOfTheDay(FString* Message) { static NativeFunction f{ "AShooterGameMode.SetMessageOfTheDay" }; NativeCall<void, FString*>(this, f, Message); }
	void ShowMessageOfTheDay() { static NativeFunction f{ "AShooterGameMode.ShowMessageOfTheDay" }; NativeCall<void>(this, f); }
	APawn* SpawnDefaultPawnFor(AController* NewPlayer, AActor* StartSpot) { static NativeFunction f{ "AShooterGameMode.SpawnDefaultPawnFor" }; return NativeCall<APawn*, AController*, AActor*>(this, f, NewPlayer, StartSpot); }
	FPrimalPlayerCharacterConfigStruct* ValidateCharacterConfig(FPrimalPlayerCharacterConfigStruct* result, FPrimalPlayerCharacterConfigStruct* charConfig) { static NativeFunction f{ "AShooterGameMode.ValidateCharacterConfig" }; return NativeCall<FPrimalPlayerCharacterConfigStruct*, FPrimalPlayerCharacterConfigStruct*, FPrimalPlayerCharacterConfigStruct*>(this, f, result, charConfig); }
	FString* GenerateProfileFileName(FString* result, FUniqueNetIdRepl* UniqueId, FString* NetworkAddresss, FString* PlayerName) { static NativeFunction f{ "AShooterGameMode.GenerateProfileFileName" }; return NativeCall<FString*, FString*, FUniqueNetIdRepl*, FString*, FString*>(this, f, result, UniqueId, NetworkAddresss, PlayerName); }
	UPrimalPlayerData* LoadPlayerData(AShooterPlayerState* PlayerState, bool bIsLoadingBackup) { static NativeFunction f{ "AShooterGameMode.LoadPlayerData" }; return NativeCall<UPrimalPlayerData*, AShooterPlayerState*, bool>(this, f, PlayerState, bIsLoadingBackup); }
	void DeletePlayerData(AShooterPlayerState* PlayerState) { static NativeFunction f{ "AShooterGameMode.DeletePlayerData" }; NativeCall<void, AShooterPlayerState*>(this, f, PlayerState); }
	bool GetOrLoadTribeData(int TribeID, FTribeData* LoadedTribeData) { static NativeFunction f{ "AShooterGameMode.GetOrLoadTribeData" }; return NativeCall<bool, int, FTribeData*>(this, f, TribeID, LoadedTribeData); }
	bool LoadTribeData(int TribeID, FTribeData* LoadedTribeData, bool bIsLoadingBackup, bool bDontCheckDirtyTribeWar) { static NativeFunction f{ "AShooterGameMode.LoadTribeData" }; return NativeCall<bool, int, FTribeData*, bool, bool>(this, f, TribeID, LoadedTribeData, bIsLoadingBackup, bDontCheckDirtyTribeWar); }
	UPrimalPlayerData* GetPlayerDataFor(AShooterPlayerController* PC, bool* bCreatedNewPlayerData, bool bForceCreateNewPlayerData, FPrimalPlayerCharacterConfigStruct* charConfig, bool bAutoCreateNewData, bool bDontSaveNewData) { static NativeFunction f{ "AShooterGameMode.GetPlayerDataFor" }; return NativeCall<UPrimalPlayerData*, AShooterPlayerController*, bool*, bool, FPrimalPlayerCharacterConfigStruct*, bool, bool>(this, f, PC, bCreatedNewPlayerData, bForceCreateNewPlayerData, charConfig, bAutoCreateNewData, bDontSaveNewData); }
	void CheckForRepopulation() { static NativeFunction f{ "AShooterGameMode.CheckForRepopulation" }; NativeCall<void>(this, f); }
	void ForceRepopulateFoliageAtPoint(FVector AtPoint, float MaxRangeFromPoint, int MaxNumFoliages, TSubclassOf<APrimalEmitterSpawnable> RepopulatedEmitter, FVector* StructureDownTraceVector, FVector* StructureUpTraceVector, bool bDontCheckForOverlaps, int TriggeredByTeamID, bool bForce, float MinRangeFromPoint = 0.f) { static NativeFunction f{ "AShooterGameMode.ForceRepopulateFoliageAtPoint" }; NativeCall<void, FVector, float, int, TSubclassOf<APrimalEmitterSpawnable>, FVector*, FVector*, bool, int, bool, float>(this, f, AtPoint, MaxRangeFromPoint, MaxNumFoliages, RepopulatedEmitter, StructureDownTraceVector, StructureUpTraceVector, bDontCheckForOverlaps, TriggeredByTeamID, bForce, MinRangeFromPoint); }
	[[deprecated("not in this game build")]] void AddToPendingStructureDestroys(APrimalStructure* theStructure) { ReportDeprecatedApiUse("AShooterGameMode.AddToPendingStructureDestroys"); static NativeFunction f{ "AShooterGameMode.AddToPendingStructureDestroys" }; NativeCall<void, APrimalStructure*>(this, f, theStructure); }
	void TickLoginLocks() { static NativeFunction f{ "AShooterGameMode.TickLoginLocks" }; NativeCall<void>(this, f); }
	bool IsLoginLockDisabled() { static NativeFunction f{ "AShooterGameMode.IsLoginLockDisabled" }; return NativeCall<bool>(this, f); }
	void CheckGlobalEnables() { static NativeFunction f{ "AShooterGameMode.CheckGlobalEnables" }; NativeCall<void>(this, f); }
	void HttpCheckGlobalEnablesComplete(TSharedPtr<IHttpRequest, 0> HttpRequest, TSharedPtr<IHttpResponse, 1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameMode.HttpCheckGlobalEnablesComplete" }; NativeCall<void, TSharedPtr<IHttpRequest, 0>, TSharedPtr<IHttpResponse, 1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "AShooterGameMode.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	bool StartSaveBackup() { static NativeFunction f{ "AShooterGameMode.StartSaveBackup" }; return NativeCall<bool>(this, f); }
	void SendDatadogMetricEvent(FString* Title, FString* Message) { static NativeFunction f{ "AShooterGameMode.SendDatadogMetricEvent" }; NativeCall<void, FString*, FString*>(this, f, Title, Message); }
	void TickSaveBackup() { static NativeFunction f{ "AShooterGameMode.TickSaveBackup" }; NativeCall<void>(this, f); }
	float TimeSinceMissionDeactivated(TSubclassOf<AMissionType> MissionType) { static NativeFunction f{ "AShooterGameMode.TimeSinceMissionDeactivated" }; return NativeCall<float, TSubclassOf<AMissionType>>(this, f, MissionType); }
	bool IsTimeSinceMissionDeactivated(TSubclassOf<AMissionType> MissionType, float CheckTimeSince, bool bForceTrueAtZeroTime) { static NativeFunction f{ "AShooterGameMode.IsTimeSinceMissionDeactivated" }; return NativeCall<bool, TSubclassOf<AMissionType>, float, bool>(this, f, MissionType, CheckTimeSince, bForceTrueAtZeroTime); }
	void ClearLastMissionDeactivatedTime(TSubclassOf<AMissionType> MissionType) { static NativeFunction f{ "AShooterGameMode.ClearLastMissionDeactivatedTime" }; NativeCall<void, TSubclassOf<AMissionType>>(this, f, MissionType); }
	long double GetLastMissionDeactivatedUtcTime(TSubclassOf<AMissionType> MissionType) { static NativeFunction f{ "AShooterGameMode.GetLastMissionDeactivatedUtcTime" }; return NativeCall<long double, TSubclassOf<AMissionType>>(this, f, MissionType); }
	void SetLastMissionDeactivatedUtcTime(TSubclassOf<AMissionType> MissionType, long double UtcTime) { static NativeFunction f{ "AShooterGameMode.SetLastMissionDeactivatedUtcTime" }; NativeCall<void, TSubclassOf<AMissionType>, long double>(this, f, MissionType, UtcTime); }
	unsigned __int64 AddNewTribe(AShooterPlayerState* PlayerOwner, FString* TribeName, FTribeGovernment* TribeGovernment) { static NativeFunction f{ "AShooterGameMode.AddNewTribe" }; return NativeCall<unsigned __int64, AShooterPlayerState*, FString*, FTribeGovernment*>(this, f, PlayerOwner, TribeName, TribeGovernment); }
	void RemoveTribe(unsigned __int64 TribeID) { static NativeFunction f{ "AShooterGameMode.RemoveTribe" }; NativeCall<void, unsigned __int64>(this, f, TribeID); }
	void UpdateTribeData(FTribeData* NewTribeData) { static NativeFunction f{ "AShooterGameMode.UpdateTribeData" }; NativeCall<void, FTribeData*>(this, f, NewTribeData); }
	void RemovePlayerFromTribe(unsigned __int64 TribeID, unsigned __int64 PlayerDataID, bool bDontUpdatePlayerState) { static NativeFunction f{ "AShooterGameMode.RemovePlayerFromTribe" }; NativeCall<void, unsigned __int64, unsigned __int64, bool>(this, f, TribeID, PlayerDataID, bDontUpdatePlayerState); }
	int GetTribeIDOfPlayerID(unsigned __int64 PlayerDataID) { static NativeFunction f{ "AShooterGameMode.GetTribeIDOfPlayerID" }; return NativeCall<int, unsigned __int64>(this, f, PlayerDataID); }
	FTribeData* GetTribeDataBlueprint(FTribeData* result, int TribeID) { static NativeFunction f{ "AShooterGameMode.GetTribeDataBlueprint" }; return NativeCall<FTribeData*, FTribeData*, int>(this, f, result, TribeID); }
	FTribeData* GetTribeData(FTribeData* result, unsigned __int64 TribeID) { static NativeFunction f{ "AShooterGameMode.GetTribeData" }; return NativeCall<FTribeData*, FTribeData*, unsigned __int64>(this, f, result, TribeID); }
	void ArkGlobalCommand(FString Command) { static NativeFunction f{ "AShooterGameMode.ArkGlobalCommand" }; NativeCall<void, FString>(this, f, Command); }
	void InitializeDatabaseRefs() { static NativeFunction f{ "AShooterGameMode.InitializeDatabaseRefs" }; NativeCall<void>(this, f); }
	void BeginPlay() { static NativeFunction f{ "AShooterGameMode.BeginPlay" }; NativeCall<void>(this, f); }
	void Serialize(FArchive* Ar) { static NativeFunction f{ "AShooterGameMode.Serialize" }; NativeCall<void, FArchive*>(this, f, Ar); }
	FLeaderboardEntry* GetOrCreateLeaderboardEntry(FName MissionTag) { static NativeFunction f{ "AShooterGameMode.GetOrCreateLeaderboardEntry" }; return NativeCall<FLeaderboardEntry*, FName>(this, f, MissionTag); }
	void GetActorSaveGameTypes(TArray<TSubclassOf<AActor>>* saveGameTypes) { static NativeFunction f{ "AShooterGameMode.GetActorSaveGameTypes" }; NativeCall<void, TArray<TSubclassOf<AActor>>*>(this, f, saveGameTypes); }
	FString* InitNewPlayer(FString* result, APlayerController* NewPlayerController, TSharedPtr<FUniqueNetId, 0>* UniqueId, FString* Options, FString* Portal) { static NativeFunction f{ "AShooterGameMode.InitNewPlayer" }; return NativeCall<FString*, FString*, APlayerController*, TSharedPtr<FUniqueNetId, 0>*, FString*, FString*>(this, f, result, NewPlayerController, UniqueId, Options, Portal); }
	void SendServerDirectMessage(FString* PlayerSteamID, FString* MessageText, FLinearColor MessageColor, bool bIsBold, int ReceiverTeamId, int ReceiverPlayerID, FString* PlayerName) { static NativeFunction f{ "AShooterGameMode.SendServerDirectMessage" }; NativeCall<void, FString*, FString*, FLinearColor, bool, int, int, FString*>(this, f, PlayerSteamID, MessageText, MessageColor, bIsBold, ReceiverTeamId, ReceiverPlayerID, PlayerName); }
	void SendServerChatMessage(FString* MessageText, FLinearColor MessageColor, bool bIsBold, int ReceiverTeamId, int ReceiverPlayerID) { static NativeFunction f{ "AShooterGameMode.SendServerChatMessage" }; NativeCall<void, FString*, FLinearColor, bool, int, int>(this, f, MessageText, MessageColor, bIsBold, ReceiverTeamId, ReceiverPlayerID); }
	void SendServerNotification(FString* MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D* MessageIcon, USoundBase* SoundToPlay, int ReceiverTeamId, int ReceiverPlayerID, bool bDoBillboard) { static NativeFunction f{ "AShooterGameMode.SendServerNotification" }; NativeCall<void, FString*, FLinearColor, float, float, UTexture2D*, USoundBase*, int, int, bool>(this, f, MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay, ReceiverTeamId, ReceiverPlayerID, bDoBillboard); }
	void RemovePlayerData(AShooterPlayerState* PlayerState) { static NativeFunction f{ "AShooterGameMode.RemovePlayerData" }; NativeCall<void, AShooterPlayerState*>(this, f, PlayerState); }
	void InitGameState() { static NativeFunction f{ "AShooterGameMode.InitGameState" }; NativeCall<void>(this, f); }
	void PreInitializeComponents() { static NativeFunction f{ "AShooterGameMode.PreInitializeComponents" }; NativeCall<void>(this, f); }
	void CheckIsOfficialServer() { static NativeFunction f{ "AShooterGameMode.CheckIsOfficialServer" }; NativeCall<void>(this, f); }
	void BeginUnloadingWorld() { static NativeFunction f{ "AShooterGameMode.BeginUnloadingWorld" }; NativeCall<void>(this, f); }
	static FString* GetLiveTuningOverloadsDirectory(FString* result, bool bEnsureDirectoryExists) { static NativeFunction f{ "AShooterGameState.GetLiveTuningOverloadsDirectory" }; return NativeCall<FString*, FString*, bool>(nullptr, f, result, bEnsureDirectoryExists); }
	static bool IsSupportedLiveTuningProperty(UProperty* Property, bool bIgnoreLiveTuningFlag) { static NativeFunction f{ "AShooterGameState.IsSupportedLiveTuningProperty" }; return NativeCall<bool, UProperty*, bool>(nullptr, f, Property, bIgnoreLiveTuningFlag); }
	bool DumpAssetProperties(FString* Asset, FString* OutFilename) { static NativeFunction f{ "AShooterGameMode.DumpAssetProperties" }; return NativeCall<bool, FString*, FString*>(this, f, Asset, OutFilename); }
	void GetServerNotification() { static NativeFunction f{ "AShooterGameMode.GetServerNotification" }; NativeCall<void>(this, f); }
	void HttpServerNotificationRequestComplete(TSharedPtr<IHttpRequest, 0> HttpRequest, TSharedPtr<IHttpResponse, 1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameMode.HttpServerNotificationRequestComplete" }; NativeCall<void, TSharedPtr<IHttpRequest, 0>, TSharedPtr<IHttpResponse, 1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	void GetDynamicConfig() { static NativeFunction f{ "AShooterGameMode.GetDynamicConfig" }; NativeCall<void>(this, f); }
	void HttpGetDynamicConfigComplete(TSharedPtr<IHttpRequest, 0> HttpRequest, TSharedPtr<IHttpResponse, 1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameMode.HttpGetDynamicConfigComplete" }; NativeCall<void, TSharedPtr<IHttpRequest, 0>, TSharedPtr<IHttpResponse, 1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	void HttpGetLiveTuningOverloadsComplete(TSharedPtr<IHttpRequest, 0> HttpRequest, TSharedPtr<IHttpResponse, 1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameMode.HttpGetLiveTuningOverloadsComplete" }; NativeCall<void, TSharedPtr<IHttpRequest, 0>, TSharedPtr<IHttpResponse, 1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	[[deprecated("not in this game build, use AShooterGameState::ApplyLiveTuningOverloads")]] void ApplyLiveTuningOverloads(TSharedPtr<FJsonObject, 0> Overloads) { ReportDeprecatedApiUse("AShooterGameMode.ApplyLiveTuningOverloads"); static NativeFunction f{ "AShooterGameMode.ApplyLiveTuningOverloads" }; NativeCall<void, TSharedPtr<FJsonObject, 0>>(this, f, Overloads); }
	[[deprecated("not in this game build, use AShooterGameState::ResetLiveTuningOverloads")]] void ResetLiveTuningOverloads() { ReportDeprecatedApiUse("AShooterGameMode.ResetLiveTuningOverloads"); static NativeFunction f{ "AShooterGameMode.ResetLiveTuningOverloads" }; NativeCall<void>(this, f); }
	void PostAlarmNotification(FUniqueNetId* SteamID, FString* Title, FString* Message) { static NativeFunction f{ "AShooterGameMode.PostAlarmNotification(const FUniqueNetId&,const FString&,const FString&)" }; NativeCall<void, FUniqueNetId*, FString*, FString*>(this, f, SteamID, Title, Message); }
	void PostAlarmNotification(unsigned __int64 SteamID, FString* Title, FString* Message) { static NativeFunction f{ "AShooterGameMode.PostAlarmNotification(unsigned __int64,const FString&,const FString&)" }; NativeCall<void, unsigned __int64, FString*, FString*>(this, f, SteamID, Title, Message); }
	void PostAlarmNotification(FString SteamID, FString* Title, FString* Message) { static NativeFunction f{ "AShooterGameMode.PostAlarmNotification(FString,const FString&,const FString&)" }; NativeCall<void, FString, FString*, FString*>(this, f, SteamID, Title, Message); }
	void PostServerMetrics() { static NativeFunction f{ "AShooterGameMode.PostServerMetrics" }; NativeCall<void>(this, f); }
	void AddTrackedAdminCommand(APlayerController* Controller, FString* CommandType, FString* Command) { static NativeFunction f{ "AShooterGameMode.AddTrackedAdminCommand" }; NativeCall<void, APlayerController*, FString*, FString*>(this, f, Controller, CommandType, Command); }
	void PostAdminTrackedCommands() { static NativeFunction f{ "AShooterGameMode.PostAdminTrackedCommands" }; NativeCall<void>(this, f); }
	void AllowPlayerToJoinNoCheck(FUniqueNetIdUInt64* PlayerId) { static NativeFunction f{ "AShooterGameMode.AllowPlayerToJoinNoCheck" }; NativeCall<void, FUniqueNetIdUInt64*>(this, f, PlayerId); }
	void DisallowPlayerToJoinNoCheck(FUniqueNetIdUInt64* PlayerId) { static NativeFunction f{ "AShooterGameMode.DisallowPlayerToJoinNoCheck" }; NativeCall<void, FUniqueNetIdUInt64*>(this, f, PlayerId); }
	void SavePlayersJoinNoCheckList() { static NativeFunction f{ "AShooterGameMode.SavePlayersJoinNoCheckList" }; NativeCall<void>(this, f); }
	void LoadPlayersJoinNoCheckList() { static NativeFunction f{ "AShooterGameMode.LoadPlayersJoinNoCheckList" }; NativeCall<void>(this, f); }
	bool IsPlayerAllowedToJoinNoCheck(FUniqueNetIdUInt64* PlayerId) { static NativeFunction f{ "AShooterGameMode.IsPlayerAllowedToJoinNoCheck" }; return NativeCall<bool, FUniqueNetIdUInt64*>(this, f, PlayerId); }
	bool IsPlayerControllerAllowedToJoinNoCheck(AShooterPlayerController* ForPlayer) { static NativeFunction f{ "AShooterGameMode.IsPlayerControllerAllowedToJoinNoCheck" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPlayer); }
	bool IsPlayerControllerAllowedToExclusiveJoin(AShooterPlayerController* ForPlayer) { static NativeFunction f{ "AShooterGameMode.IsPlayerControllerAllowedToExclusiveJoin" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPlayer); }
	bool KickPlayer(FString PlayerSteamName, FString PlayerSteamID) { static NativeFunction f{ "AShooterGameMode.KickPlayer" }; return NativeCall<bool, FString, FString>(this, f, PlayerSteamName, PlayerSteamID); }
	void KickPlayerController(APlayerController* thePC, FString* KickMessage) { static NativeFunction f{ "AShooterGameMode.KickPlayerController" }; NativeCall<void, APlayerController*, FString*>(this, f, thePC, KickMessage); }
	bool BanPlayer(FString PlayerSteamName, FString PlayerSteamID) { static NativeFunction f{ "AShooterGameMode.BanPlayer" }; return NativeCall<bool, FString, FString>(this, f, PlayerSteamName, PlayerSteamID); }
	bool UnbanPlayer(FString PlayerSteamName, FString PlayerSteamID) { static NativeFunction f{ "AShooterGameMode.UnbanPlayer" }; return NativeCall<bool, FString, FString>(this, f, PlayerSteamName, PlayerSteamID); }
	void SaveBannedList() { static NativeFunction f{ "AShooterGameMode.SaveBannedList" }; NativeCall<void>(this, f); }
	void LoadBannedList() { static NativeFunction f{ "AShooterGameMode.LoadBannedList" }; NativeCall<void>(this, f); }
	FString* GetMapName(FString* result) { static NativeFunction f{ "AShooterGameMode.GetMapName" }; return NativeCall<FString*, FString*>(this, f, result); }
	void UpdateSaveBackupFiles() { static NativeFunction f{ "AShooterGameMode.UpdateSaveBackupFiles" }; NativeCall<void>(this, f); }
	void LoadTribeIds_Process(unsigned int theTribeID) { static NativeFunction f{ "AShooterGameMode.LoadTribeIds_Process" }; NativeCall<void, unsigned int>(this, f, theTribeID); }
	void LoadTribeIds() { static NativeFunction f{ "AShooterGameMode.LoadTribeIds" }; NativeCall<void>(this, f); }
	void LoadPlayerIds_Process(unsigned __int64 InPlayerID, TArray<unsigned char>* ReadBytes) { static NativeFunction f{ "AShooterGameMode.LoadPlayerIds_Process" }; NativeCall<void, unsigned __int64, TArray<unsigned char>*>(this, f, InPlayerID, ReadBytes); }
	void LoadPlayerDataIds() { static NativeFunction f{ "AShooterGameMode.LoadPlayerDataIds" }; NativeCall<void>(this, f); }
	void AddPlayerID(int playerDataID, unsigned __int64 netUniqueID) { static NativeFunction f{ "AShooterGameMode.AddPlayerID" }; NativeCall<void, int, unsigned __int64>(this, f, playerDataID, netUniqueID); }
	unsigned __int64 GetSteamIDForPlayerID(int playerDataID) { static NativeFunction f{ "AShooterGameMode.GetSteamIDForPlayerID" }; return NativeCall<unsigned __int64, int>(this, f, playerDataID); }
	int GetPlayerIDForSteamID(unsigned __int64 steamID) { static NativeFunction f{ "AShooterGameMode.GetPlayerIDForSteamID" }; return NativeCall<int, unsigned __int64>(this, f, steamID); }
	unsigned int GenerateTribeId() { static NativeFunction f{ "AShooterGameMode.GenerateTribeId" }; return NativeCall<unsigned int>(this, f); }
	unsigned int GeneratePlayerDataId(unsigned __int64 NetUniqueID) { static NativeFunction f{ "AShooterGameMode.GeneratePlayerDataId" }; return NativeCall<unsigned int, unsigned __int64>(this, f, NetUniqueID); }
	float ModifyNPCSpawnLimits(FName DinoNameTag, float CurrentLimit) { static NativeFunction f{ "AShooterGameMode.ModifyNPCSpawnLimits" }; return NativeCall<float, FName, float>(this, f, DinoNameTag, CurrentLimit); }
	float GetExtraDinoSpawnWeight(FName DinoNameTag) { static NativeFunction f{ "AShooterGameMode.GetExtraDinoSpawnWeight" }; return NativeCall<float, FName>(this, f, DinoNameTag); }
	float GetHarvestResourceItemAmountMultiplier(TSubclassOf<UPrimalItem> HarvestItemClass) { static NativeFunction f{ "AShooterGameMode.GetHarvestResourceItemAmountMultiplier" }; return NativeCall<float, TSubclassOf<UPrimalItem>>(this, f, HarvestItemClass); }
	float GetDinoDamageMultiplier(APrimalDinoCharacter* ForDino) { static NativeFunction f{ "AShooterGameMode.GetDinoDamageMultiplier" }; return NativeCall<float, APrimalDinoCharacter*>(this, f, ForDino); }
	float GetDinoResistanceMultiplier(APrimalDinoCharacter* ForDino) { static NativeFunction f{ "AShooterGameMode.GetDinoResistanceMultiplier" }; return NativeCall<float, APrimalDinoCharacter*>(this, f, ForDino); }
	bool IsEngramClassHidden(TSubclassOf<UPrimalItem> ForItemClass) { static NativeFunction f{ "AShooterGameMode.IsEngramClassHidden" }; return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, f, ForItemClass); }
	bool IsEngramClassGiveToPlayer(TSubclassOf<UPrimalItem> ForItemClass) { static NativeFunction f{ "AShooterGameMode.IsEngramClassGiveToPlayer" }; return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, f, ForItemClass); }
	void ListenServerClampPlayerLocations() { static NativeFunction f{ "AShooterGameMode.ListenServerClampPlayerLocations" }; NativeCall<void>(this, f); }
	FString* ValidateTribeName(FString* result, FString theTribeName) { static NativeFunction f{ "AShooterGameMode.ValidateTribeName" }; return NativeCall<FString*, FString*, FString>(this, f, result, theTribeName); }
	void AdjustDamage(AActor* Victim, float* Damage, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "AShooterGameMode.AdjustDamage" }; NativeCall<void, AActor*, float*, FDamageEvent*, AController*, AActor*>(this, f, Victim, Damage, DamageEvent, EventInstigator, DamageCauser); }
	void NotifyDamage(AActor* Victim, float DamageAmount, FDamageEvent* Event, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "AShooterGameMode.NotifyDamage" }; NativeCall<void, AActor*, float, FDamageEvent*, AController*, AActor*>(this, f, Victim, DamageAmount, Event, EventInstigator, DamageCauser); }
	void DamageEventLogFlush() { static NativeFunction f{ "AShooterGameMode.DamageEventLogFlush" }; NativeCall<void>(this, f); }
	void SetDamageEventLoggingEnabled(bool bEnabled) { static NativeFunction f{ "AShooterGameMode.SetDamageEventLoggingEnabled" }; NativeCall<void, bool>(this, f, bEnabled); }
	bool AllowRenameTribe(AShooterPlayerState* ForPlayerState, FString* TribeName) { static NativeFunction f{ "AShooterGameMode.AllowRenameTribe" }; return NativeCall<bool, AShooterPlayerState*, FString*>(this, f, ForPlayerState, TribeName); }
	void SetTimeOfDay(FString* timeString) { static NativeFunction f{ "AShooterGameMode.SetTimeOfDay" }; NativeCall<void, FString*>(this, f, timeString); }
	void KickAllPlayersAndReload() { static NativeFunction f{ "AShooterGameMode.KickAllPlayersAndReload" }; NativeCall<void>(this, f); }
	void RestartServer() { static NativeFunction f{ "AShooterGameMode.RestartServer" }; NativeCall<void>(this, f); }
	void SerializeForSaveFile(int SaveVersion, FArchive* InArchive) { static NativeFunction f{ "AShooterGameMode.SerializeForSaveFile" }; NativeCall<void, int, FArchive*>(this, f, SaveVersion, InArchive); }
	bool PlayerCanRestart(APlayerController* Player) { static NativeFunction f{ "AShooterGameMode.PlayerCanRestart" }; return NativeCall<bool, APlayerController*>(this, f, Player); }
	bool HandleNewPlayer_Implementation(AShooterPlayerController* NewPlayer, UPrimalPlayerData* PlayerData, AShooterCharacter* PlayerCharacter, bool bIsFromLogin) { static NativeFunction f{ "AShooterGameMode.HandleNewPlayer_Implementation" }; return NativeCall<bool, AShooterPlayerController*, UPrimalPlayerData*, AShooterCharacter*, bool>(this, f, NewPlayer, PlayerData, PlayerCharacter, bIsFromLogin); }
	bool IsPlayerAllowedToCheat(AShooterPlayerController* ForPlayer) { static NativeFunction f{ "AShooterGameMode.IsPlayerAllowedToCheat" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPlayer); }
	void PrintToGameplayLog(FString* InString) { static NativeFunction f{ "AShooterGameMode.PrintToGameplayLog" }; NativeCall<void, FString*>(this, f, InString); }
	void PrintToServerGameLog(FString* InString, bool bSendChatToAllAdmins) { static NativeFunction f{ "AShooterGameMode.PrintToServerGameLog" }; NativeCall<void, FString*, bool>(this, f, InString, bSendChatToAllAdmins); }
	void LoadedFromSaveGame() { static NativeFunction f{ "AShooterGameMode.LoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void RemoveInactivePlayersAndTribes() { static NativeFunction f{ "AShooterGameMode.RemoveInactivePlayersAndTribes" }; NativeCall<void>(this, f); }
	void DDoSDetected() { static NativeFunction f{ "AShooterGameMode.DDoSDetected" }; NativeCall<void>(this, f); }
	FString* GetSessionTimeString_Implementation(FString* result) { static NativeFunction f{ "AShooterGameMode.GetSessionTimeString_Implementation" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool GetLaunchOptionFloat(FString* LaunchOptionKey, float* ReturnVal) { static NativeFunction f{ "AShooterGameMode.GetLaunchOptionFloat" }; return NativeCall<bool, FString*, float*>(this, f, LaunchOptionKey, ReturnVal); }
	static bool AllowDamage(UWorld* ForWorld, int TargetingTeam1, int TargetingTeam2, bool bIgnoreDamageIfAllied) { static NativeFunction f{ "AShooterGameMode.AllowDamage" }; return NativeCall<bool, UWorld*, int, int, bool>(nullptr, f, ForWorld, TargetingTeam1, TargetingTeam2, bIgnoreDamageIfAllied); }
	bool IsTribeWar(int TribeID1, int TribeID2) { static NativeFunction f{ "AShooterGameMode.IsTribeWar" }; return NativeCall<bool, int, int>(this, f, TribeID1, TribeID2); }
	void UpdateTribeWars() { static NativeFunction f{ "AShooterGameMode.UpdateTribeWars" }; NativeCall<void>(this, f); }
	void AddToTribeLog(int TribeId, FString* NewLog) { static NativeFunction f{ "AShooterGameMode.AddToTribeLog" }; NativeCall<void, int, FString*>(this, f, TribeId, NewLog); }
	TArray<APrimalDinoCharacter*>* GetOverlappingDinoCharactersOfTeamAndClass(TArray<APrimalDinoCharacter*>* result, FVector* AtLocation, float OverlapRange, TSubclassOf<APrimalDinoCharacter> DinoClass, int DinoTeam, bool bExactClassMatch, bool bIgnoreClass) { static NativeFunction f{ "AShooterGameMode.GetOverlappingDinoCharactersOfTeamAndClass" }; return NativeCall<TArray<APrimalDinoCharacter*>*, TArray<APrimalDinoCharacter*>*, FVector*, float, TSubclassOf<APrimalDinoCharacter>, int, bool, bool>(this, f, result, AtLocation, OverlapRange, DinoClass, DinoTeam, bExactClassMatch, bIgnoreClass); }
	int CountOverlappingDinoCharactersOfTeamAndClass(FVector* AtLocation, float OverlapRange, TSubclassOf<APrimalDinoCharacter> DinoClass, int DinoTeam, bool bExactClassMatch, bool bIgnoreClass) { static NativeFunction f{ "AShooterGameMode.CountOverlappingDinoCharactersOfTeamAndClass" }; return NativeCall<int, FVector*, float, TSubclassOf<APrimalDinoCharacter>, int, bool, bool>(this, f, AtLocation, OverlapRange, DinoClass, DinoTeam, bExactClassMatch, bIgnoreClass); }
	void IncrementNumDinos(int ForTeam, int ByAmount) { static NativeFunction f{ "AShooterGameMode.IncrementNumDinos" }; NativeCall<void, int, int>(this, f, ForTeam, ByAmount); }
	int GetNumDinosOnTeam(int OnTeam) { static NativeFunction f{ "AShooterGameMode.GetNumDinosOnTeam" }; return NativeCall<int, int>(this, f, OnTeam); }
	bool AllowTaming(int ForTeam) { static NativeFunction f{ "AShooterGameMode.AllowTaming" }; return NativeCall<bool, int>(this, f, ForTeam); }
	int ForceAddPlayerToTribe(AShooterPlayerState* ForPlayerState, FString* TribeName) { static NativeFunction f{ "AShooterGameMode.ForceAddPlayerToTribe" }; return NativeCall<int, AShooterPlayerState*, FString*>(this, f, ForPlayerState, TribeName); }
	int ForceCreateTribe(FString* TribeName, int TeamOverride) { static NativeFunction f{ "AShooterGameMode.ForceCreateTribe" }; return NativeCall<int, FString*, int>(this, f, TribeName, TeamOverride); }
	int GetNumberOfLivePlayersOnTribe(FString* TribeName) { static NativeFunction f{ "AShooterGameMode.GetNumberOfLivePlayersOnTribe" }; return NativeCall<int, FString*>(this, f, TribeName); }
	static bool TriggerLevelCustomEvents(UWorld* InWorld, FString* EventName, int Param = 0) { static NativeFunction f{ "AShooterGameMode.TriggerLevelCustomEvents" }; return NativeCall<bool, UWorld*, FString*, int>(nullptr, f, InWorld, EventName, Param); }
	void UpdateTribeAllianceData(FTribeAlliance* TribeAllianceData, TArray<unsigned int>* OldMembersArray, bool bIsAdd) { static NativeFunction f{ "AShooterGameMode.UpdateTribeAllianceData" }; NativeCall<void, FTribeAlliance*, TArray<unsigned int>*, bool>(this, f, TribeAllianceData, OldMembersArray, bIsAdd); }
	bool AreTribesAllied(int TribeID1, int TribeID2) { static NativeFunction f{ "AShooterGameMode.AreTribesAllied" }; return NativeCall<bool, int, int>(this, f, TribeID1, TribeID2); }
	void AddTribeWar(int MyTribeID, int EnemyTeamID, int StartDayNum, int EndDayNumber, float WarStartTime, float WarEndTime, bool bForceApprove) { static NativeFunction f{ "AShooterGameMode.AddTribeWar" }; NativeCall<void, int, int, int, int, float, float, bool>(this, f, MyTribeID, EnemyTeamID, StartDayNum, EndDayNumber, WarStartTime, WarEndTime, bForceApprove); }
	void PostAlarmNotificationPlayerID(int PlayerID, FString* Title, FString* Message) { static NativeFunction f{ "AShooterGameMode.PostAlarmNotificationPlayerID" }; NativeCall<void, int, FString*, FString*>(this, f, PlayerID, Title, Message); }
	void PostAlarmNotificationTribe(int TribeID, FString Title, FString Message) { static NativeFunction f{ "AShooterGameMode.PostAlarmNotificationTribe" }; NativeCall<void, int, FString, FString>(this, f, TribeID, Title, Message); }
	void SpawnedPawnFor(AController* PC, APawn* SpawnedPawn) { static NativeFunction f{ "AShooterGameMode.SpawnedPawnFor" }; NativeCall<void, AController*, APawn*>(this, f, PC, SpawnedPawn); }
	void SaveTributePlayerDatas(FString UniqueID) { static NativeFunction f{ "AShooterGameMode.SaveTributePlayerDatas" }; NativeCall<void, FString>(this, f, UniqueID); }
	void LoadTributePlayerDatas(FString UniqueID) { static NativeFunction f{ "AShooterGameMode.LoadTributePlayerDatas" }; NativeCall<void, FString>(this, f, UniqueID); }
	void DownloadTransferredPlayer(AShooterPlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.DownloadTransferredPlayer" }; NativeCall<void, AShooterPlayerController*>(this, f, NewPlayer); }
	void CheckForDupedDinos() { static NativeFunction f{ "AShooterGameMode.CheckForDupedDinos" }; NativeCall<void>(this, f); }
	void ArkMetricsAppend(FString* Type, TSharedPtr<FJsonObject, 0> Payload) { static NativeFunction f{ "AShooterGameMode.ArkMetricsAppend" }; NativeCall<void, FString*, TSharedPtr<FJsonObject, 0>>(this, f, Type, Payload); }
	void FlushPrimalStats(AShooterPlayerController* ForPC) { static NativeFunction f{ "AShooterGameMode.FlushPrimalStats" }; NativeCall<void, AShooterPlayerController*>(this, f, ForPC); }
	void ReassertColorization() { static NativeFunction f{ "AShooterGameMode.ReassertColorization" }; NativeCall<void>(this, f); }
	void SendAllCachedArkMetrics() { static NativeFunction f{ "AShooterGameMode.SendAllCachedArkMetrics" }; NativeCall<void>(this, f); }
	void HttpSendAllCachedArkMetricsRequestComplete(TSharedPtr<IHttpRequest, 0> HttpRequest, TSharedPtr<IHttpResponse, 1> HttpResponse, bool bSucceeded) { static NativeFunction f{ "AShooterGameMode.HttpSendAllCachedArkMetricsRequestComplete" }; NativeCall<void, TSharedPtr<IHttpRequest, 0>, TSharedPtr<IHttpResponse, 1>, bool>(this, f, HttpRequest, HttpResponse, bSucceeded); }
	FString* GetServerName(FString* result, bool bNumbersAndLettersOnly) { static NativeFunction f{ "AShooterGameMode.GetServerName" }; return NativeCall<FString*, FString*, bool>(this, f, result, bNumbersAndLettersOnly); }
	void ChatLogAppend(AShooterPlayerController* SenderController, FChatMessage* Msg) { static NativeFunction f{ "AShooterGameMode.ChatLogAppend" }; NativeCall<void, AShooterPlayerController*, FChatMessage*>(this, f, SenderController, Msg); }
	void ChatLogFlush(bool bFinalize) { static NativeFunction f{ "AShooterGameMode.ChatLogFlush" }; NativeCall<void, bool>(this, f, bFinalize); }
	bool BPIsSpawnpointAllowed_Implementation(APlayerStart* SpawnPoint, AController* Player) { static NativeFunction f{ "AShooterGameMode.BPIsSpawnpointAllowed_Implementation" }; return NativeCall<bool, APlayerStart*, AController*>(this, f, SpawnPoint, Player); }
	bool BPIsSpawnpointPreferred_Implementation(APlayerStart* SpawnPoint, AController* Player) { static NativeFunction f{ "AShooterGameMode.BPIsSpawnpointPreferred_Implementation" }; return NativeCall<bool, APlayerStart*, AController*>(this, f, SpawnPoint, Player); }
	AOceanDinoManager* GetOceanDinoManager() { static NativeFunction f{ "AShooterGameMode.GetOceanDinoManager" }; return NativeCall<AOceanDinoManager*>(this, f); }
	void ReloadAdminIPs() { static NativeFunction f{ "AShooterGameMode.ReloadAdminIPs" }; NativeCall<void>(this, f); }
	void ChatLogFlushOnTick() { static NativeFunction f{ "AShooterGameMode.ChatLogFlushOnTick" }; NativeCall<void>(this, f); }
	static void StaticRegisterNativesAShooterGameMode() { static NativeFunction f{ "AShooterGameMode.StaticRegisterNativesAShooterGameMode" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "AShooterGameMode.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	void BPPreSpawnedDino(APrimalDinoCharacter* theDino) { static NativeFunction f{ "AShooterGameMode.BPPreSpawnedDino" }; NativeCall<void, APrimalDinoCharacter*>(this, f, theDino); }
	bool CheckJoinInProgress(bool bIsFromLogin, APlayerController* NewPlayer) { static NativeFunction f{ "AShooterGameMode.CheckJoinInProgress" }; return NativeCall<bool, bool, APlayerController*>(this, f, bIsFromLogin, NewPlayer); }
	bool HandleNewPlayer(AShooterPlayerController* NewPlayer, UPrimalPlayerData* PlayerData, AShooterCharacter* PlayerCharacter, bool bIsFromLogin) { static NativeFunction f{ "AShooterGameMode.HandleNewPlayer" }; return NativeCall<bool, AShooterPlayerController*, UPrimalPlayerData*, AShooterCharacter*, bool>(this, f, NewPlayer, PlayerData, PlayerCharacter, bIsFromLogin); }
	void OnLogout(AController* Exiting) { static NativeFunction f{ "AShooterGameMode.OnLogout" }; NativeCall<void, AController*>(this, f, Exiting); }
	FString* GetSaveDirectoryName(FString* result, ESaveType::Type SaveType) { static NativeFunction f{ "AShooterGameMode.GetSaveDirectoryName" }; return NativeCall<FString*, FString*, ESaveType::Type>(this, f, result, SaveType); }
};

struct UPrimalGameData : UObject
{
	FString& ModNameField() { static NativeFieldOffset f{ "UPrimalGameData.ModName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& ModDescriptionField() { static NativeFieldOffset f{ "UPrimalGameData.ModDescription" }; return *GetNativePointerField<FString*>(this, f); }
	FieldArray<FPrimalCharacterStatusValueDefinition, 12> StatusValueDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.StatusValueDefinitions" }; return { this, f }; }
	FieldArray<FPrimalCharacterStatusStateDefinition, 14> StatusStateDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.StatusStateDefinitions" }; return { this, f }; }
	FieldArray<FPrimalItemStatDefinition, 8> ItemStatDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.ItemStatDefinitions" }; return { this, f }; }
	FieldArray<FPrimalItemDefinition, 9> ItemTypeDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.ItemTypeDefinitions" }; return { this, f }; }
	FieldArray<FPrimalEquipmentDefinition, 11> EquipmentTypeDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.EquipmentTypeDefinitions" }; return { this, f }; }
	TArray<TSubclassOf<UPrimalItem>>& MasterItemListField() { static NativeFieldOffset f{ "UPrimalGameData.MasterItemList" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<FPrimalItemQuality>& ItemQualityDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.ItemQualityDefinitions" }; return *GetNativePointerField<TArray<FPrimalItemQuality>*>(this, f); }
	TArray<TSubclassOf<UPrimalEngramEntry>>& EngramBlueprintClassesField() { static NativeFieldOffset f{ "UPrimalGameData.EngramBlueprintClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalEngramEntry>>*>(this, f); }
	TArray<TSubclassOf<UPrimalEngramEntry>>& AdditionalEngramBlueprintClassesField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalEngramBlueprintClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalEngramEntry>>*>(this, f); }
	TArray<TSubclassOf<UPrimalEngramEntry>>& RemoveEngramBlueprintClassesField() { static NativeFieldOffset f{ "UPrimalGameData.RemoveEngramBlueprintClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalEngramEntry>>*>(this, f); }
	TArray<FStatusValueModifierDescription>& StatusValueModifierDescriptionsField() { static NativeFieldOffset f{ "UPrimalGameData.StatusValueModifierDescriptions" }; return *GetNativePointerField<TArray<FStatusValueModifierDescription>*>(this, f); }
	TArray<FString>& PlayerSpawnRegionsField() { static NativeFieldOffset f{ "UPrimalGameData.PlayerSpawnRegions" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	USoundBase* TutorialDisplaySoundField() { static NativeFieldOffset f{ "UPrimalGameData.TutorialDisplaySound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_StartItemDragField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_StartItemDrag" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_StopItemDragField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_StopItemDrag" }; return *GetNativePointerField<USoundBase**>(this, f); }
	UTexture2D* PreventGrindingIconField() { static NativeFieldOffset f{ "UPrimalGameData.PreventGrindingIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	USoundBase* Sound_CancelPlacingStructureField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_CancelPlacingStructure" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ChooseStructureRotationField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ChooseStructureRotation" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_FailPlacingStructureField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_FailPlacingStructure" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ConfirmPlacingStructureField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ConfirmPlacingStructure" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_StartPlacingStructureField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_StartPlacingStructure" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_CorpseDecomposeField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_CorpseDecompose" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ApplyLevelUpField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ApplyLevelUp" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ApplyLevelPointField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ApplyLevelPoint" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_LearnedEngramField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_LearnedEngram" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ReconnectToCharacterField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ReconnectToCharacter" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_DropAllItemsField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_DropAllItems" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_TransferAllItemsToRemoteField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TransferAllItemsToRemote" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_TransferAllItemsFromRemoteField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TransferAllItemsFromRemote" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_TransferItemToRemoteField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TransferItemToRemote" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_TransferItemFromRemoteField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TransferItemFromRemote" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_AddItemToSlotField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_AddItemToSlot" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_RemoveItemFromSlotField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_RemoveItemFromSlot" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ClearCraftQueueField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ClearCraftQueue" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_AddToCraftQueueField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_AddToCraftQueue" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_SetRadioFrequencyField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_SetRadioFrequency" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_AddPinToMapField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_AddPinToMap" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_RemovePinFromMapField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_RemovePinFromMap" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ApplyDyeField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ApplyDye" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ApplyPaintField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ApplyPaint" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_SetTextGenericField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_SetTextGeneric" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_SplitItemStackField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_SplitItemStack" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_MergeItemStackField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_MergeItemStack" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_InputPinDigitField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_InputPinDigit" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_PinValidatedField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_PinValidated" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_PinRejectedField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_PinRejected" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_TribeWarBeginField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TribeWarBegin" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_TribeWarEndField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TribeWarEnd" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_DropInventoryItemField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_DropInventoryItem" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_RefillWaterContainerField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_RefillWaterContainer" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TArray<FAppIDItem>& CoreAppIDItemsField() { static NativeFieldOffset f{ "UPrimalGameData.CoreAppIDItems" }; return *GetNativePointerField<TArray<FAppIDItem>*>(this, f); }
	TArray<FAppIDItem>& AppIDItemsField() { static NativeFieldOffset f{ "UPrimalGameData.AppIDItems" }; return *GetNativePointerField<TArray<FAppIDItem>*>(this, f); }
	TArray<UPrimalEngramEntry*>& EngramBlueprintEntriesField() { static NativeFieldOffset f{ "UPrimalGameData.EngramBlueprintEntries" }; return *GetNativePointerField<TArray<UPrimalEngramEntry*>*>(this, f); }
	TArray<UGenericDataListEntry*>& ExplorerNoteEntriesObjectsField() { static NativeFieldOffset f{ "UPrimalGameData.ExplorerNoteEntriesObjects" }; return *GetNativePointerField<TArray<UGenericDataListEntry*>*>(this, f); }
	TArray<UGenericDataListEntry*>& HeadHairStylesEntriesObjectsField() { static NativeFieldOffset f{ "UPrimalGameData.HeadHairStylesEntriesObjects" }; return *GetNativePointerField<TArray<UGenericDataListEntry*>*>(this, f); }
	TArray<UGenericDataListEntry*>& FacialHairStylesEntriesObjectsField() { static NativeFieldOffset f{ "UPrimalGameData.FacialHairStylesEntriesObjects" }; return *GetNativePointerField<TArray<UGenericDataListEntry*>*>(this, f); }
	TSubclassOf<UToolTipWidget>& DefaultToolTipWidgetField() { static NativeFieldOffset f{ "UPrimalGameData.DefaultToolTipWidget" }; return *GetNativePointerField<TSubclassOf<UToolTipWidget>*>(this, f); }
	TSubclassOf<UPrimalItem>& StarterNoteItemField() { static NativeFieldOffset f{ "UPrimalGameData.StarterNoteItem" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& PrimaryResourcesField() { static NativeFieldOffset f{ "UPrimalGameData.PrimaryResources" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TSubclassOf<ADroppedItem>& GenericDroppedItemTemplateField() { static NativeFieldOffset f{ "UPrimalGameData.GenericDroppedItemTemplate" }; return *GetNativePointerField<TSubclassOf<ADroppedItem>*>(this, f); }
	UMaterialInterface* PostProcess_KnockoutBlurField() { static NativeFieldOffset f{ "UPrimalGameData.PostProcess_KnockoutBlur" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	UMaterialInterface* AdditionalDeathPostProcessEffectField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalDeathPostProcessEffect" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	TArray<UMaterialInterface*>& BuffPostProcessEffectsField() { static NativeFieldOffset f{ "UPrimalGameData.BuffPostProcessEffects" }; return *GetNativePointerField<TArray<UMaterialInterface*>*>(this, f); }
	TArray<UMaterialInterface*>& AdditionalBuffPostProcessEffectsField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalBuffPostProcessEffects" }; return *GetNativePointerField<TArray<UMaterialInterface*>*>(this, f); }
	TSubclassOf<ADroppedItemLowQuality>& GenericDroppedItemTemplateLowQualityField() { static NativeFieldOffset f{ "UPrimalGameData.GenericDroppedItemTemplateLowQuality" }; return *GetNativePointerField<TSubclassOf<ADroppedItemLowQuality>*>(this, f); }
	TArray<FTutorialDefinition>& TutorialDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.TutorialDefinitions" }; return *GetNativePointerField<TArray<FTutorialDefinition>*>(this, f); }
	UTexture2D* UnknownIconField() { static NativeFieldOffset f{ "UPrimalGameData.UnknownIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UMaterialInterface* UnknownMaterialField() { static NativeFieldOffset f{ "UPrimalGameData.UnknownMaterial" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	UTexture2D* WhiteTextureField() { static NativeFieldOffset f{ "UPrimalGameData.WhiteTexture" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* BlueprintBackgroundField() { static NativeFieldOffset f{ "UPrimalGameData.BlueprintBackground" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* BabyCuddleIconField() { static NativeFieldOffset f{ "UPrimalGameData.BabyCuddleIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* ImprintedRiderIconField() { static NativeFieldOffset f{ "UPrimalGameData.ImprintedRiderIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* WeaponAccessoryActivatedIconField() { static NativeFieldOffset f{ "UPrimalGameData.WeaponAccessoryActivatedIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* EngramBackgroundField() { static NativeFieldOffset f{ "UPrimalGameData.EngramBackground" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* VoiceChatIconField() { static NativeFieldOffset f{ "UPrimalGameData.VoiceChatIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* VoiceChatYellingIconField() { static NativeFieldOffset f{ "UPrimalGameData.VoiceChatYellingIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* VoiceChatWhisperingIconField() { static NativeFieldOffset f{ "UPrimalGameData.VoiceChatWhisperingIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* ItemButtonRecentlySelectedBackgroundField() { static NativeFieldOffset f{ "UPrimalGameData.ItemButtonRecentlySelectedBackground" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	float& GlobalGeneralArmorDegradationMultiplierField() { static NativeFieldOffset f{ "UPrimalGameData.GlobalGeneralArmorDegradationMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalSpecificArmorDegradationMultiplierField() { static NativeFieldOffset f{ "UPrimalGameData.GlobalSpecificArmorDegradationMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalSpecificArmorRatingMultiplierField() { static NativeFieldOffset f{ "UPrimalGameData.GlobalSpecificArmorRatingMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GlobalGeneralArmorRatingMultiplierField() { static NativeFieldOffset f{ "UPrimalGameData.GlobalGeneralArmorRatingMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& EnemyFoundationPreventionRadiusField() { static NativeFieldOffset f{ "UPrimalGameData.EnemyFoundationPreventionRadius" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FColorDefinition>& ColorDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.ColorDefinitions" }; return *GetNativePointerField<TArray<FColorDefinition>*>(this, f); }
	TArray<UObject*>& ExtraResourcesField() { static NativeFieldOffset f{ "UPrimalGameData.ExtraResources" }; return *GetNativePointerField<TArray<UObject*>*>(this, f); }
	TArray<UObject*>& BaseExtraResourcesField() { static NativeFieldOffset f{ "UPrimalGameData.BaseExtraResources" }; return *GetNativePointerField<TArray<UObject*>*>(this, f); }
	USoundBase* CombatMusicDayField() { static NativeFieldOffset f{ "UPrimalGameData.CombatMusicDay" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* CombatMusicNightField() { static NativeFieldOffset f{ "UPrimalGameData.CombatMusicNight" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* CombatMusicDay_HeavyField() { static NativeFieldOffset f{ "UPrimalGameData.CombatMusicDay_Heavy" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* CombatMusicNight_HeavyField() { static NativeFieldOffset f{ "UPrimalGameData.CombatMusicNight_Heavy" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* LevelUpStingerSoundField() { static NativeFieldOffset f{ "UPrimalGameData.LevelUpStingerSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* TrackMissionSoundField() { static NativeFieldOffset f{ "UPrimalGameData.TrackMissionSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* UntrackMissionSoundField() { static NativeFieldOffset f{ "UPrimalGameData.UntrackMissionSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	FieldArray<FPlayerCharacterGenderDefinition, 2> PlayerCharacterGenderDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.PlayerCharacterGenderDefinitions" }; return { this, f }; }
	TSubclassOf<AGameMode>& DefaultGameModeField() { static NativeFieldOffset f{ "UPrimalGameData.DefaultGameMode" }; return *GetNativePointerField<TSubclassOf<AGameMode>*>(this, f); }
	FieldArray<FLevelExperienceRamp, 4> LevelExperienceRampsField() { static NativeFieldOffset f{ "UPrimalGameData.LevelExperienceRamps" }; return { this, f }; }
	FieldArray<FLevelExperienceRamp, 4> SinglePlayerLevelExperienceRampsField() { static NativeFieldOffset f{ "UPrimalGameData.SinglePlayerLevelExperienceRamps" }; return { this, f }; }
	TArray<FNamedTeamDefinition>& NamedTeamDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.NamedTeamDefinitions" }; return *GetNativePointerField<TArray<FNamedTeamDefinition>*>(this, f); }
	TArray<int>& PlayerLevelEngramPointsField() { static NativeFieldOffset f{ "UPrimalGameData.PlayerLevelEngramPoints" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	TArray<int>& PlayerLevelEngramPointsSPField() { static NativeFieldOffset f{ "UPrimalGameData.PlayerLevelEngramPointsSP" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	TArray<FString>& PreventBuildStructureReasonStringsField() { static NativeFieldOffset f{ "UPrimalGameData.PreventBuildStructureReasonStrings" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TArray<FExplorerNoteAchievement>& ExplorerNoteAchievementsField() { static NativeFieldOffset f{ "UPrimalGameData.ExplorerNoteAchievements" }; return *GetNativePointerField<TArray<FExplorerNoteAchievement>*>(this, f); }
	TArray<FClassRemapping>& Remap_NPCField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_NPC" }; return *GetNativePointerField<TArray<FClassRemapping>*>(this, f); }
	TArray<FClassRemapping>& Remap_SupplyCratesField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_SupplyCrates" }; return *GetNativePointerField<TArray<FClassRemapping>*>(this, f); }
	TArray<FActiveEventSupplyCrateWeight>& Remap_ActiveEventSupplyCratesField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_ActiveEventSupplyCrates" }; return *GetNativePointerField<TArray<FActiveEventSupplyCrateWeight>*>(this, f); }
	TArray<FClassRemapping>& Remap_ResourceComponentsField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_ResourceComponents" }; return *GetNativePointerField<TArray<FClassRemapping>*>(this, f); }
	TArray<FClassRemapping>& Remap_NPCSpawnEntriesField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_NPCSpawnEntries" }; return *GetNativePointerField<TArray<FClassRemapping>*>(this, f); }
	TArray<FClassRemapping>& Remap_EngramsField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_Engrams" }; return *GetNativePointerField<TArray<FClassRemapping>*>(this, f); }
	TArray<FClassRemapping>& Remap_ItemsField() { static NativeFieldOffset f{ "UPrimalGameData.Remap_Items" }; return *GetNativePointerField<TArray<FClassRemapping>*>(this, f); }
	TArray<FClassAddition>& AdditionalStructureEngramsField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalStructureEngrams" }; return *GetNativePointerField<TArray<FClassAddition>*>(this, f); }
	TArray<FBuffAddition>& AdditionalDefaultBuffsField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalDefaultBuffs" }; return *GetNativePointerField<TArray<FBuffAddition>*>(this, f); }
	TArray<FAvailableMission>& AvailableMissionsField() { static NativeFieldOffset f{ "UPrimalGameData.AvailableMissions" }; return *GetNativePointerField<TArray<FAvailableMission>*>(this, f); }
	TSubclassOf<AActor>& ActorToSpawnUponEnemyCoreStructureDeathField() { static NativeFieldOffset f{ "UPrimalGameData.ActorToSpawnUponEnemyCoreStructureDeath" }; return *GetNativePointerField<TSubclassOf<AActor>*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& AdditionalStructuresToPlaceField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalStructuresToPlace" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem_Dye>>& MasterDyeListField() { static NativeFieldOffset f{ "UPrimalGameData.MasterDyeList" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem_Dye>>*>(this, f); }
	TArray<FColor>& MasterColorTableField() { static NativeFieldOffset f{ "UPrimalGameData.MasterColorTable" }; return *GetNativePointerField<TArray<FColor>*>(this, f); }
	float& EnemyCoreStructureDeathActorRadiusBuildCheckField() { static NativeFieldOffset f{ "UPrimalGameData.EnemyCoreStructureDeathActorRadiusBuildCheck" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<APrimalStructureItemContainer>& DeathDestructionDepositInventoryClassField() { static NativeFieldOffset f{ "UPrimalGameData.DeathDestructionDepositInventoryClass" }; return *GetNativePointerField<TSubclassOf<APrimalStructureItemContainer>*>(this, f); }
	UTexture2D* MateBoostIconField() { static NativeFieldOffset f{ "UPrimalGameData.MateBoostIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* EggBoostIconField() { static NativeFieldOffset f{ "UPrimalGameData.EggBoostIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* MatingIconField() { static NativeFieldOffset f{ "UPrimalGameData.MatingIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* NearFeedIconField() { static NativeFieldOffset f{ "UPrimalGameData.NearFeedIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* BuffedIconField() { static NativeFieldOffset f{ "UPrimalGameData.BuffedIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* TethererdIconField() { static NativeFieldOffset f{ "UPrimalGameData.TethererdIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* GamepadFaceButtonTopField() { static NativeFieldOffset f{ "UPrimalGameData.GamepadFaceButtonTop" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* GamepadFaceButtonBottomField() { static NativeFieldOffset f{ "UPrimalGameData.GamepadFaceButtonBottom" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* GamepadFaceButtonLeftField() { static NativeFieldOffset f{ "UPrimalGameData.GamepadFaceButtonLeft" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* GamepadFaceButtonRightField() { static NativeFieldOffset f{ "UPrimalGameData.GamepadFaceButtonRight" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	TSubclassOf<UUI_XBoxFooter>& FooterTemplateField() { static NativeFieldOffset f{ "UPrimalGameData.FooterTemplate" }; return *GetNativePointerField<TSubclassOf<UUI_XBoxFooter>*>(this, f); }
	float& TribeXPSharePercentField() { static NativeFieldOffset f{ "UPrimalGameData.TribeXPSharePercent" }; return *GetNativePointerField<float*>(this, f); }
	int& OverrideServerPhysXSubstepsField() { static NativeFieldOffset f{ "UPrimalGameData.OverrideServerPhysXSubsteps" }; return *GetNativePointerField<int*>(this, f); }
	float& OverrideServerPhysXSubstepsDeltaTimeField() { static NativeFieldOffset f{ "UPrimalGameData.OverrideServerPhysXSubstepsDeltaTime" }; return *GetNativePointerField<float*>(this, f); }
	bool& bInitializedField() { static NativeFieldOffset f{ "UPrimalGameData.bInitialized" }; return *GetNativePointerField<bool*>(this, f); }
	FieldArray<USoundBase*, 3> Sound_TamedDinosField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_TamedDinos" }; return { this, f }; }
	USoundBase* Sound_ItemStartCraftingField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ItemStartCrafting" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ItemFinishCraftingField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ItemFinishCrafting" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ItemStartRepairingField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ItemStartRepairing" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ItemFinishRepairingField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ItemFinishRepairing" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TSubclassOf<UUI_Notification>& NotifClassField() { static NativeFieldOffset f{ "UPrimalGameData.NotifClass" }; return *GetNativePointerField<TSubclassOf<UUI_Notification>*>(this, f); }
	TSubclassOf<UPrimalStructureToolTipWidget>& StructureDefaultOverlayToolTipWidgetField() { static NativeFieldOffset f{ "UPrimalGameData.StructureDefaultOverlayToolTipWidget" }; return *GetNativePointerField<TSubclassOf<UPrimalStructureToolTipWidget>*>(this, f); }
	float& MinPaintDurationConsumptionField() { static NativeFieldOffset f{ "UPrimalGameData.MinPaintDurationConsumption" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxPaintDurationConsumptionField() { static NativeFieldOffset f{ "UPrimalGameData.MaxPaintDurationConsumption" }; return *GetNativePointerField<float*>(this, f); }
	float& MinDinoRadiusForPaintConsumptionField() { static NativeFieldOffset f{ "UPrimalGameData.MinDinoRadiusForPaintConsumption" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxDinoRadiusForPaintConsumptionField() { static NativeFieldOffset f{ "UPrimalGameData.MaxDinoRadiusForPaintConsumption" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FDinoBabySetup>& DinoBabySetupsField() { static NativeFieldOffset f{ "UPrimalGameData.DinoBabySetups" }; return *GetNativePointerField<TArray<FDinoBabySetup>*>(this, f); }
	TArray<FDinoBabySetup>& DinoGestationSetupsField() { static NativeFieldOffset f{ "UPrimalGameData.DinoGestationSetups" }; return *GetNativePointerField<TArray<FDinoBabySetup>*>(this, f); }
	TSubclassOf<UPrimalItem>& SoapItemTemplateField() { static NativeFieldOffset f{ "UPrimalGameData.SoapItemTemplate" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	UTexture2D* NameTagWildcardAdminField() { static NativeFieldOffset f{ "UPrimalGameData.NameTagWildcardAdmin" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* NameTagServerAdminField() { static NativeFieldOffset f{ "UPrimalGameData.NameTagServerAdmin" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* NameTagTribeAdminField() { static NativeFieldOffset f{ "UPrimalGameData.NameTagTribeAdmin" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	TArray<UTexture2D*>& BadgeGroupsNameTagField() { static NativeFieldOffset f{ "UPrimalGameData.BadgeGroupsNameTag" }; return *GetNativePointerField<TArray<UTexture2D*>*>(this, f); }
	TArray<FString>& AchievementIDsField() { static NativeFieldOffset f{ "UPrimalGameData.AchievementIDs" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	TSet<FString, DefaultKeyFuncs<FString, 0>, FDefaultSetAllocator>& AchievementIDSetField() { static NativeFieldOffset f{ "UPrimalGameData.AchievementIDSet" }; return *GetNativePointerField<TSet<FString, DefaultKeyFuncs<FString, 0>, FDefaultSetAllocator>*>(this, f); }
	TArray<float>& AdditionalEggWeightsToSpawnField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalEggWeightsToSpawn" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& AdditionalEggItemsToSpawnField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalEggItemsToSpawn" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<float>& FertilizedAdditionalEggWeightsToSpawnField() { static NativeFieldOffset f{ "UPrimalGameData.FertilizedAdditionalEggWeightsToSpawn" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& FertilizedAdditionalEggItemsToSpawnField() { static NativeFieldOffset f{ "UPrimalGameData.FertilizedAdditionalEggItemsToSpawn" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	FString& ItemAchievementsNameField() { static NativeFieldOffset f{ "UPrimalGameData.ItemAchievementsName" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& ItemAchievementsListField() { static NativeFieldOffset f{ "UPrimalGameData.ItemAchievementsList" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& GlobalCuddleFoodListField() { static NativeFieldOffset f{ "UPrimalGameData.GlobalCuddleFoodList" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<FMultiAchievement>& MultiAchievementsField() { static NativeFieldOffset f{ "UPrimalGameData.MultiAchievements" }; return *GetNativePointerField<TArray<FMultiAchievement>*>(this, f); }
	USoundBase* DinoIncrementedImprintingSoundField() { static NativeFieldOffset f{ "UPrimalGameData.DinoIncrementedImprintingSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* HitMarkerCharacterSoundField() { static NativeFieldOffset f{ "UPrimalGameData.HitMarkerCharacterSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* HitMarkerStructureSoundField() { static NativeFieldOffset f{ "UPrimalGameData.HitMarkerStructureSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TArray<FNPCSpawnEntriesContainerAdditions>& TheNPCSpawnEntriesContainerAdditionsField() { static NativeFieldOffset f{ "UPrimalGameData.TheNPCSpawnEntriesContainerAdditions" }; return *GetNativePointerField<TArray<FNPCSpawnEntriesContainerAdditions>*>(this, f); }
	UMaterialInterface* PostProcess_ColorLUTField() { static NativeFieldOffset f{ "UPrimalGameData.PostProcess_ColorLUT" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	TSubclassOf<UPrimalStructureSettings>& DefaultStructureSettingsField() { static NativeFieldOffset f{ "UPrimalGameData.DefaultStructureSettings" }; return *GetNativePointerField<TSubclassOf<UPrimalStructureSettings>*>(this, f); }
	USoundBase* Sound_DossierUnlockedField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_DossierUnlocked" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_ItemUseOnItemField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_ItemUseOnItem" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_RemoveItemSkinField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_RemoveItemSkin" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_RemoveClipAmmoField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_RemoveClipAmmo" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TArray<FExplorerNoteEntry>& ExplorerNoteEntriesField() { static NativeFieldOffset f{ "UPrimalGameData.ExplorerNoteEntries" }; return *GetNativePointerField<TArray<FExplorerNoteEntry>*>(this, f); }
	float& ExplorerNoteXPGainField() { static NativeFieldOffset f{ "UPrimalGameData.ExplorerNoteXPGain" }; return *GetNativePointerField<float*>(this, f); }
	FieldArray<UTexture2D*, 3> BuffTypeBackgroundsField() { static NativeFieldOffset f{ "UPrimalGameData.BuffTypeBackgrounds" }; return { this, f }; }
	FieldArray<UTexture2D*, 3> BuffTypeForegroundsField() { static NativeFieldOffset f{ "UPrimalGameData.BuffTypeForegrounds" }; return { this, f }; }
	TSubclassOf<APrimalBuff>& ExplorerNoteXPBuffField() { static NativeFieldOffset f{ "UPrimalGameData.ExplorerNoteXPBuff" }; return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, f); }
	TSubclassOf<APrimalBuff>& SpecialExplorerNoteXPBuffField() { static NativeFieldOffset f{ "UPrimalGameData.SpecialExplorerNoteXPBuff" }; return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, f); }
	UTexture2D* PerMapExplorerNoteLockedIconField() { static NativeFieldOffset f{ "UPrimalGameData.PerMapExplorerNoteLockedIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* TamedDinoUnlockedIconField() { static NativeFieldOffset f{ "UPrimalGameData.TamedDinoUnlockedIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* TamedDinoLockedIconField() { static NativeFieldOffset f{ "UPrimalGameData.TamedDinoLockedIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	TArray<FUnlockableEmoteEntry>& UnlockableEmotesField() { static NativeFieldOffset f{ "UPrimalGameData.UnlockableEmotes" }; return *GetNativePointerField<TArray<FUnlockableEmoteEntry>*>(this, f); }
	TArray<FClassRemappingWeight>& GlobalNPCRandomSpawnClassWeightsField() { static NativeFieldOffset f{ "UPrimalGameData.GlobalNPCRandomSpawnClassWeights" }; return *GetNativePointerField<TArray<FClassRemappingWeight>*>(this, f); }
	UTexture2D* DinoOrderIconField() { static NativeFieldOffset f{ "UPrimalGameData.DinoOrderIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& DinoOrderEffect_MoveToField() { static NativeFieldOffset f{ "UPrimalGameData.DinoOrderEffect_MoveTo" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& DinoOrderEffect_AttackTargetField() { static NativeFieldOffset f{ "UPrimalGameData.DinoOrderEffect_AttackTarget" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	TArray<FObjectCorrelation>& AdditionalHumanMaleAnimSequenceOverridesField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalHumanMaleAnimSequenceOverrides" }; return *GetNativePointerField<TArray<FObjectCorrelation>*>(this, f); }
	TArray<FObjectCorrelation>& AdditionalHumanFemaleAnimSequenceOverridesField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalHumanFemaleAnimSequenceOverrides" }; return *GetNativePointerField<TArray<FObjectCorrelation>*>(this, f); }
	TArray<FObjectCorrelation>& AdditionalHumanMaleAnimMontagesOverridesField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalHumanMaleAnimMontagesOverrides" }; return *GetNativePointerField<TArray<FObjectCorrelation>*>(this, f); }
	TArray<FObjectCorrelation>& AdditionalHumanFemaleAnimMontagesOverridesField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalHumanFemaleAnimMontagesOverrides" }; return *GetNativePointerField<TArray<FObjectCorrelation>*>(this, f); }
	TArray<TSubclassOf<AActor>>& ServerExtraWorldSingletonActorClassesField() { static NativeFieldOffset f{ "UPrimalGameData.ServerExtraWorldSingletonActorClasses" }; return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, f); }
	bool& bForceServerUseDinoListField() { static NativeFieldOffset f{ "UPrimalGameData.bForceServerUseDinoList" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<TSubclassOf<UPrimalGameData>>& ExtraStackedGameDataClassesField() { static NativeFieldOffset f{ "UPrimalGameData.ExtraStackedGameDataClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalGameData>>*>(this, f); }
	TArray<FHairStyleDefinition>& HeadHairStyleDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.HeadHairStyleDefinitions" }; return *GetNativePointerField<TArray<FHairStyleDefinition>*>(this, f); }
	TArray<FHairStyleDefinition>& FacialHairStyleDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.FacialHairStyleDefinitions" }; return *GetNativePointerField<TArray<FHairStyleDefinition>*>(this, f); }
	TArray<FHairStyleDefinition>& AdditionalHeadHairStyleDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalHeadHairStyleDefinitions" }; return *GetNativePointerField<TArray<FHairStyleDefinition>*>(this, f); }
	TArray<FHairStyleDefinition>& AdditionalFacialHairStyleDefinitionsField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalFacialHairStyleDefinitions" }; return *GetNativePointerField<TArray<FHairStyleDefinition>*>(this, f); }
	USoundBase* GenericWaterPostprocessAmbientSoundField() { static NativeFieldOffset f{ "UPrimalGameData.GenericWaterPostprocessAmbientSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TSubclassOf<UPrimalPlayerData>& OverridePlayerDataClassField() { static NativeFieldOffset f{ "UPrimalGameData.OverridePlayerDataClass" }; return *GetNativePointerField<TSubclassOf<UPrimalPlayerData>*>(this, f); }
	TArray<FName>& AllDinosAchievementNameTagsField() { static NativeFieldOffset f{ "UPrimalGameData.AllDinosAchievementNameTags" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	USoundBase* GenericArrowPickedUpSoundField() { static NativeFieldOffset f{ "UPrimalGameData.GenericArrowPickedUpSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	UTexture2D* UnlockIconField() { static NativeFieldOffset f{ "UPrimalGameData.UnlockIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	FColor& WheelFolderColorField() { static NativeFieldOffset f{ "UPrimalGameData.WheelFolderColor" }; return *GetNativePointerField<FColor*>(this, f); }
	FColor& WheelBackColorField() { static NativeFieldOffset f{ "UPrimalGameData.WheelBackColor" }; return *GetNativePointerField<FColor*>(this, f); }
	UTexture2D* MaxInventoryIconField() { static NativeFieldOffset f{ "UPrimalGameData.MaxInventoryIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	UTexture2D* ItemSkinIconField() { static NativeFieldOffset f{ "UPrimalGameData.ItemSkinIcon" }; return *GetNativePointerField<UTexture2D**>(this, f); }
	TArray<TEnumAsByte<enum ECollisionChannel>>& SkeletalPhysCustomBodyAdditionalIgnoresField() { static NativeFieldOffset f{ "UPrimalGameData.SkeletalPhysCustomBodyAdditionalIgnores" }; return *GetNativePointerField<TArray<TEnumAsByte<enum ECollisionChannel>>*>(this, f); }
	USoundBase* ActionWheelClickSoundField() { static NativeFieldOffset f{ "UPrimalGameData.ActionWheelClickSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_GenericBoardPassengerField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_GenericBoardPassenger" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_GenericUnboardPassengerField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_GenericUnboardPassenger" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* Sound_CraftingTabToggleField() { static NativeFieldOffset f{ "UPrimalGameData.Sound_CraftingTabToggle" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TSubclassOf<UPrimalItem>& GenericBatteryItemClassField() { static NativeFieldOffset f{ "UPrimalGameData.GenericBatteryItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TMap<UClass*, UPrimalEngramEntry*, FDefaultSetAllocator, TDefaultMapKeyFuncs<UClass*, UPrimalEngramEntry*, 0> >& ItemEngramMapField() { static NativeFieldOffset f{ "UPrimalGameData.ItemEngramMap" }; return *GetNativePointerField<TMap<UClass*, UPrimalEngramEntry*, FDefaultSetAllocator, TDefaultMapKeyFuncs<UClass*, UPrimalEngramEntry*, 0> >*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& GenesisSeasonPassItemsField() { static NativeFieldOffset f{ "UPrimalGameData.GenesisSeasonPassItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<TSubclassOf<UHexagonTradableOption>>& DefaultTradableOptionsField() { static NativeFieldOffset f{ "UPrimalGameData.DefaultTradableOptions" }; return *GetNativePointerField<TArray<TSubclassOf<UHexagonTradableOption>>*>(this, f); }
	TArray<TSubclassOf<UHexagonTradableOption>>& AdditionalTradableOptionsField() { static NativeFieldOffset f{ "UPrimalGameData.AdditionalTradableOptions" }; return *GetNativePointerField<TArray<TSubclassOf<UHexagonTradableOption>>*>(this, f); }
	bool& bWantsToRunMissionsField() { static NativeFieldOffset f{ "UPrimalGameData.bWantsToRunMissions" }; return *GetNativePointerField<bool*>(this, f); }

	// Functions

	int GetItemQualityIndex(float ItemRating) { static NativeFunction f{ "UPrimalGameData.GetItemQualityIndex" }; return NativeCall<int, float>(this, f, ItemRating); }
	void Initialize() { static NativeFunction f{ "UPrimalGameData.Initialize" }; NativeCall<void>(this, f); }
	FLinearColor* GetColorForDefinition(FLinearColor* result, int DefinitionIndex) { static NativeFunction f{ "UPrimalGameData.GetColorForDefinition" }; return NativeCall<FLinearColor*, FLinearColor*, int>(this, f, result, DefinitionIndex); }
	int GetDefinitionIndexForColorName(FName ColorName) { static NativeFunction f{ "UPrimalGameData.GetDefinitionIndexForColorName" }; return NativeCall<int, FName>(this, f, ColorName); }
	bool CanTeamTarget(int attackerTeam, int victimTeam, int originalVictimTargetingTeam, AActor* Attacker, AActor* Victim) { static NativeFunction f{ "UPrimalGameData.CanTeamTarget" }; return NativeCall<bool, int, int, int, AActor*, AActor*>(this, f, attackerTeam, victimTeam, originalVictimTargetingTeam, Attacker, Victim); }
	bool CanTeamDamage(int attackerTeam, int victimTeam, AActor* Attacker) { static NativeFunction f{ "UPrimalGameData.CanTeamDamage" }; return NativeCall<bool, int, int, AActor*>(this, f, attackerTeam, victimTeam, Attacker); }
	int GetNamedTargetingTeamIndex(FName TargetingTeamName) { static NativeFunction f{ "UPrimalGameData.GetNamedTargetingTeamIndex" }; return NativeCall<int, FName>(this, f, TargetingTeamName); }
	float GetTeamTargetingDesirabilityMultiplier(int attackerTeam, int victimTeam) { static NativeFunction f{ "UPrimalGameData.GetTeamTargetingDesirabilityMultiplier" }; return NativeCall<float, int, int>(this, f, attackerTeam, victimTeam); }
	TSubclassOf<UObject>* GetRedirectedClass(TSubclassOf<UObject>* result, FString* key, UObject* WorldContextObject = nullptr) { static NativeFunction f{ "UPrimalGameData.GetRedirectedClass" }; return NativeCall<TSubclassOf<UObject>*, TSubclassOf<UObject>*, FString*, UObject*>(this, f, result, key, WorldContextObject); }
	USoundBase* GetGenericCombatMusic_Implementation(APrimalCharacter* forCharacter, APrimalCharacter* forEnemy) { static NativeFunction f{ "UPrimalGameData.GetGenericCombatMusic_Implementation" }; return NativeCall<USoundBase*, APrimalCharacter*, APrimalCharacter*>(this, f, forCharacter, forEnemy); }
	FLevelExperienceRamp* GetLevelExperienceRamp(ELevelExperienceRampType::Type levelType) { static NativeFunction f{ "UPrimalGameData.GetLevelExperienceRamp" }; return NativeCall<FLevelExperienceRamp*, ELevelExperienceRampType::Type>(this, f, levelType); }
	TArray<int>* GetPlayerLevelEngramPoints() { static NativeFunction f{ "UPrimalGameData.GetPlayerLevelEngramPoints" }; return NativeCall<TArray<int>*>(this, f); }
	static TSubclassOf<UObject>* GetRemappedClass(TSubclassOf<UObject>* result, TArray<FClassRemapping>* RemappedClasses, TSubclassOf<UObject> ForClass) { static NativeFunction f{ "UPrimalGameData.GetRemappedClass" }; return NativeCall<TSubclassOf<UObject>*, TSubclassOf<UObject>*, TArray<FClassRemapping>*, TSubclassOf<UObject>>(nullptr, f, result, RemappedClasses, ForClass); }
	static void GetClassAdditions(TArray<TSubclassOf<UObject>>* TheClassAdditions, TArray<FClassAddition>* ClassAdditions, TSubclassOf<UObject> ForClass) { static NativeFunction f{ "UPrimalGameData.GetClassAdditions" }; NativeCall<void, TArray<TSubclassOf<UObject>>*, TArray<FClassAddition>*, TSubclassOf<UObject>>(nullptr, f, TheClassAdditions, ClassAdditions, ForClass); }
	TArray<FString>* GetPlayerSpawnRegions(UWorld* ForWorld) { static NativeFunction f{ "UPrimalGameData.GetPlayerSpawnRegions" }; return NativeCall<TArray<FString>*, UWorld*>(this, f, ForWorld); }
	bool MergeModData(UPrimalGameData* InMergeCanidate) { static NativeFunction f{ "UPrimalGameData.MergeModData" }; return NativeCall<bool, UPrimalGameData*>(this, f, InMergeCanidate); }
	TArray<FColor>* GetGlobalColorTable(TArray<FColor>* result) { static NativeFunction f{ "UPrimalGameData.GetGlobalColorTable" }; return NativeCall<TArray<FColor>*, TArray<FColor>*>(this, f, result); }
	FDinoBabySetup* GetDinoBabySetup(FName DinoNameTag) { static NativeFunction f{ "UPrimalGameData.GetDinoBabySetup" }; return NativeCall<FDinoBabySetup*, FName>(this, f, DinoNameTag); }
	FDinoBabySetup* GetDinoGestationSetup(FName DinoNameTag) { static NativeFunction f{ "UPrimalGameData.GetDinoGestationSetup" }; return NativeCall<FDinoBabySetup*, FName>(this, f, DinoNameTag); }
	static bool LocalIsPerMapExplorerNoteUnlocked(int ExplorerNoteIndex) { static NativeFunction f{ "UPrimalGameData.LocalIsPerMapExplorerNoteUnlocked" }; return NativeCall<bool, int>(nullptr, f, ExplorerNoteIndex); }
	bool LocalIsTamedDinoTagUnlocked(FName DinoNameTag) { static NativeFunction f{ "UPrimalGameData.LocalIsTamedDinoTagUnlocked" }; return NativeCall<bool, FName>(this, f, DinoNameTag); }
	int GetEngramRequirementLevel(UClass* ItemClass) { static NativeFunction f{ "UPrimalGameData.GetEngramRequirementLevel" }; return NativeCall<int, UClass*>(this, f, ItemClass); }
	static bool LocalIsGlobalExplorerNoteUnlocked(int ExplorerNoteIndex) { static NativeFunction f{ "UPrimalGameData.LocalIsGlobalExplorerNoteUnlocked" }; return NativeCall<bool, int>(nullptr, f, ExplorerNoteIndex); }
	static UPrimalGameData* BPGetGameData() { static NativeFunction f{ "UPrimalGameData.BPGetGameData" }; return NativeCall<UPrimalGameData*>(nullptr, f); }
	int BPGetItemQualityIndex(float ItemRating) { static NativeFunction f{ "UPrimalGameData.BPGetItemQualityIndex" }; return NativeCall<int, float>(this, f, ItemRating); }
	FString* GetExplorerNoteDescription(FString* result, int ExplorerNoteIndex) { static NativeFunction f{ "UPrimalGameData.GetExplorerNoteDescription" }; return NativeCall<FString*, FString*, int>(this, f, result, ExplorerNoteIndex); }
	int GetLevelMax(ELevelExperienceRampType::Type levelType) { static NativeFunction f{ "UPrimalGameData.GetLevelMax" }; return NativeCall<int, ELevelExperienceRampType::Type>(this, f, levelType); }
	float GetXPMax(ELevelExperienceRampType::Type levelType) { static NativeFunction f{ "UPrimalGameData.GetXPMax" }; return NativeCall<float, ELevelExperienceRampType::Type>(this, f, levelType); }
	float GetLevelXP(ELevelExperienceRampType::Type levelType, int forLevel) { static NativeFunction f{ "UPrimalGameData.GetLevelXP" }; return NativeCall<float, ELevelExperienceRampType::Type, int>(this, f, levelType, forLevel); }
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalGameData.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static void StaticRegisterNativesUPrimalGameData() { static NativeFunction f{ "UPrimalGameData.StaticRegisterNativesUPrimalGameData" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "UPrimalGameData.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	void BPInitializeGameData() { static NativeFunction f{ "UPrimalGameData.BPInitializeGameData" }; NativeCall<void>(this, f); }
	void BPMergeModGameData(UPrimalGameData* AnotherGameData) { static NativeFunction f{ "UPrimalGameData.BPMergeModGameData" }; NativeCall<void, UPrimalGameData*>(this, f, AnotherGameData); }
	USoundBase* GetGenericCombatMusic(APrimalCharacter* forCharacter, APrimalCharacter* forEnemy) { static NativeFunction f{ "UPrimalGameData.GetGenericCombatMusic" }; return NativeCall<USoundBase*, APrimalCharacter*, APrimalCharacter*>(this, f, forCharacter, forEnemy); }
	void LoadedWorld(UWorld* TheWorld) { static NativeFunction f{ "UPrimalGameData.LoadedWorld" }; NativeCall<void, UWorld*>(this, f, TheWorld); }
	void TickedWorld(UWorld* TheWorld, float DeltaTime) { static NativeFunction f{ "UPrimalGameData.TickedWorld" }; NativeCall<void, UWorld*, float>(this, f, TheWorld, DeltaTime); }
};

struct ACustomGameMode : AShooterGameMode
{
	static UClass* StaticClass() { static NativeStaticClass f{ "ACustomGameMode.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "ACustomGameMode.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
};

struct UGameInstance : UObject //, FExec
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UGameInstance.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { return StaticClass(); }
	/*FWorldContext *WorldContext;
	TArray<ULocalPlayer *, FDefaultAllocator> LocalPlayers;
	FString PIEMapName;*/
};

struct ACustomActorList : AInfo
{
	static UClass* StaticClass() { static NativeStaticClass f{ "ACustomActorList.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "ACustomActorList.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	char __padding[0x468];
	TArray<AActor*> ActorList;
	bool bDestroyIfEmpty;
};
