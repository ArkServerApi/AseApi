#pragma once

struct FAvailableMission
{
	alignas(8) unsigned char __padding[0x18];
	TSubclassOf<AMissionType>& MissionClassField() { static NativeFieldOffset f{ "FAvailableMission.MissionClass" }; return *GetNativePointerField<TSubclassOf<AMissionType>*>(this, f); }
	FVector& DispatcherLocationField() { static NativeFieldOffset f{ "FAvailableMission.DispatcherLocation" }; return *GetNativePointerField<FVector*>(this, f); }

	// Functions

	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FAvailableMission.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
	[[deprecated("not in this game build")]] void FScriptStruct_ShooterGame_StaticRegisterNativesFAvailableMission() { ReportDeprecatedApiUse("FAvailableMission.FScriptStruct_ShooterGame_StaticRegisterNativesFAvailableMission"); static NativeFunction f{ "FAvailableMission.FScriptStruct_ShooterGame_StaticRegisterNativesFAvailableMission" }; NativeCall<void>(this, f); }
};

struct FDamageEvent
{
	alignas(8) unsigned char __padding[0x20];
	//FDamageEventVtbl* vfptrField() { return *GetNativePointerField<FDamageEventVtbl**>(this, "FDamageEvent.vfptr"); }
	float& ImpulseField() { static NativeFieldOffset f{ "FDamageEvent.Impulse" }; return *GetNativePointerField<float*>(this, f); }
	float& OriginalDamageField() { static NativeFieldOffset f{ "FDamageEvent.OriginalDamage" }; return *GetNativePointerField<float*>(this, f); }
	int& InstanceBodyIndexField() { static NativeFieldOffset f{ "FDamageEvent.InstanceBodyIndex" }; return *GetNativePointerField<int*>(this, f); }
	TSubclassOf<UDamageType>& DamageTypeClassField() { static NativeFieldOffset f{ "FDamageEvent.DamageTypeClass" }; return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, f); }

	// Functions

	void GetBestHitInfo(AActor* HitActor, AActor* HitInstigator, FHitResult* OutHitInfo, FVector* OutImpulseDir) { static NativeFunction f{ "FDamageEvent.GetBestHitInfo" }; NativeCall<void, AActor*, AActor*, FHitResult*, FVector*>(this, f, HitActor, HitInstigator, OutHitInfo, OutImpulseDir); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FDamageEvent.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct UPhysicalMaterial
{
};
struct FBodyInstance
{
};

struct FHitResult
{
	alignas(8) unsigned char __padding[0x88];
	float& TimeField() { static NativeFieldOffset f{ "FHitResult.Time" }; return *GetNativePointerField<float*>(this, f); }
	FVector_NetQuantize& LocationField() { static NativeFieldOffset f{ "FHitResult.Location" }; return *GetNativePointerField<FVector_NetQuantize*>(this, f); }
	FVector_NetQuantizeNormal& NormalField() { static NativeFieldOffset f{ "FHitResult.Normal" }; return *GetNativePointerField<FVector_NetQuantizeNormal*>(this, f); }
	FVector_NetQuantize& ImpactPointField() { static NativeFieldOffset f{ "FHitResult.ImpactPoint" }; return *GetNativePointerField<FVector_NetQuantize*>(this, f); }
	FVector_NetQuantizeNormal& ImpactNormalField() { static NativeFieldOffset f{ "FHitResult.ImpactNormal" }; return *GetNativePointerField<FVector_NetQuantizeNormal*>(this, f); }
	FVector_NetQuantize& TraceStartField() { static NativeFieldOffset f{ "FHitResult.TraceStart" }; return *GetNativePointerField<FVector_NetQuantize*>(this, f); }
	FVector_NetQuantize& TraceEndField() { static NativeFieldOffset f{ "FHitResult.TraceEnd" }; return *GetNativePointerField<FVector_NetQuantize*>(this, f); }
	float& PenetrationDepthField() { static NativeFieldOffset f{ "FHitResult.PenetrationDepth" }; return *GetNativePointerField<float*>(this, f); }
	int& ItemField() { static NativeFieldOffset f{ "FHitResult.Item" }; return *GetNativePointerField<int*>(this, f); }
	TWeakObjectPtr<UPhysicalMaterial>& PhysMaterialField() { static NativeFieldOffset f{ "FHitResult.PhysMaterial" }; return *GetNativePointerField<TWeakObjectPtr<UPhysicalMaterial>*>(this, f); }
	TWeakObjectPtr<AActor>& ActorField() { static NativeFieldOffset f{ "FHitResult.Actor" }; return *GetNativePointerField<TWeakObjectPtr<AActor>*>(this, f); }
	TWeakObjectPtr<UPrimitiveComponent>& ComponentField() { static NativeFieldOffset f{ "FHitResult.Component" }; return *GetNativePointerField<TWeakObjectPtr<UPrimitiveComponent>*>(this, f); }
	FBodyInstance* BodyInstanceField() { static NativeFieldOffset f{ "FHitResult.BodyInstance" }; return *GetNativePointerField<FBodyInstance**>(this, f); }
	FName& BoneNameField() { static NativeFieldOffset f{ "FHitResult.BoneName" }; return *GetNativePointerField<FName*>(this, f); }
	int& FaceIndexField() { static NativeFieldOffset f{ "FHitResult.FaceIndex" }; return *GetNativePointerField<int*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bBlockingHit() { static NativeBitField f{ "FHitResult.bBlockingHit" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bStartPenetrating() { static NativeBitField f{ "FHitResult.bStartPenetrating" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bVolatileCollision() { static NativeBitField f{ "FHitResult.bVolatileCollision" }; return { this, f }; }

	// Functions

	FHitResult* operator=(FHitResult* __that) { static NativeFunction f{ "FHitResult.operator=" }; return NativeCall<FHitResult*, FHitResult*>(this, f, __that); }
	AActor* GetActor() { static NativeFunction f{ "FHitResult.GetActor" }; return NativeCall<AActor*>(this, f); }
	UPrimitiveComponent* GetComponent() { static NativeFunction f{ "FHitResult.GetComponent" }; return NativeCall<UPrimitiveComponent*>(this, f); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FHitResult.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FOverlapInfo
{
	alignas(8) unsigned char __padding[0x98];
	bool& bFromSweepField() { static NativeFieldOffset f{ "FOverlapInfo.bFromSweep" }; return *GetNativePointerField<bool*>(this, f); }
	FHitResult& OverlapInfoField() { static NativeFieldOffset f{ "FOverlapInfo.OverlapInfo" }; return *GetNativePointerField<FHitResult*>(this, f); }
	void* CachedCompPtrField() { static NativeFieldOffset f{ "FOverlapInfo.CachedCompPtr" }; return *GetNativePointerField<void**>(this, f); }

	// Functions
};

struct FInternetAddr
{
};

struct FSocket
{
	ESocketType& SocketTypeField() { static NativeFieldOffset f{ "FSocket.SocketType" }; return *GetNativePointerField<ESocketType*>(this, f); }
	FString& SocketDescriptionField() { static NativeFieldOffset f{ "FSocket.SocketDescription" }; return *GetNativePointerField<FString*>(this, f); }
};

struct FMultiUseEntry
{
	UActorComponent* ForComponent;
	FString UseString;
	int UseIndex;
	int Priority;
	unsigned __int32 bHideFromUI : 1;
	unsigned __int32 bDisableUse : 1;
	unsigned __int32 bHideActivationKey : 1;
	unsigned __int32 bRepeatMultiUse : 1;
	unsigned __int32 bDisplayOnInventoryUI : 1;
	unsigned __int32 bDisplayOnInventoryUISecondary : 1;
	unsigned __int32 bHarvestable : 1;
	unsigned __int32 bIsSecondaryUse : 1;
	unsigned __int32 bPersistWheelOnActivation : 1;
	unsigned __int32 bOverrideUseTextColor : 1;
	unsigned __int32 bDisplayOnInventoryUITertiary : 1;
	unsigned __int32 bClientSideOnly : 1;
	unsigned __int32 bPersistWheelRequiresDirectActivation : 1;
	unsigned __int32 bDrawTooltip : 1;
	int WheelCategory;
	FColor DisableUseColor;
	FColor UseTextColor;
	float EntryActivationTimer;
	float DefaultEntryActivationTimer;
	USoundBase* ActivationSound;
	int UseInventoryButtonStyleOverrideIndex;
	int AdditionalButtonsIndex;
};

struct URCONServer : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "URCONServer.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "URCONServer.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	TPointerField<FSocket> SocketField() { static NativeFieldOffset f{ "URCONServer.Socket" }; return { GetNativePointerField<FSocket**>(this, f), "URCONServer::SocketField" }; }
	TSharedPtr<FInternetAddr>& ListenAddrField() { static NativeFieldOffset f{ "URCONServer.ListenAddr" }; return *GetNativePointerField<TSharedPtr<FInternetAddr>*>(this, f); }
	TArray<RCONClientConnection*>& ConnectionsField() { static NativeFieldOffset f{ "URCONServer.Connections" }; return *GetNativePointerField<TArray<RCONClientConnection*>*>(this, f); }
	TPointerField<UShooterCheatManager> CheatManagerField() { static NativeFieldOffset f{ "URCONServer.CheatManager" }; return { GetNativePointerField<UShooterCheatManager**>(this, f), "URCONServer::CheatManagerField" }; }
	FString& ServerPasswordField() { static NativeFieldOffset f{ "URCONServer.ServerPassword" }; return *GetNativePointerField<FString*>(this, f); }
};

struct FSocketBSD : FSocket
{
	unsigned __int64& SocketField() { static NativeFieldOffset f{ "FSocketBSD.Socket" }; return *GetNativePointerField<unsigned __int64*>(this, f); }
	FDateTime& LastActivityTimeField() { static NativeFieldOffset f{ "FSocketBSD.LastActivityTime" }; return *GetNativePointerField<FDateTime*>(this, f); }

	// Functions

	bool Close() { static NativeFunction f{ "FSocketBSD.Close" }; return NativeCall<bool>(this, f); }
	bool Bind(FInternetAddr* Addr) { static NativeFunction f{ "FSocketBSD.Bind" }; return NativeCall<bool, FInternetAddr*>(this, f, Addr); }
	bool Connect(FInternetAddr* Addr) { static NativeFunction f{ "FSocketBSD.Connect" }; return NativeCall<bool, FInternetAddr*>(this, f, Addr); }
	bool Listen(int MaxBacklog) { static NativeFunction f{ "FSocketBSD.Listen" }; return NativeCall<bool, int>(this, f, MaxBacklog); }
	bool HasPendingConnection(bool* bHasPendingConnection) { static NativeFunction f{ "FSocketBSD.HasPendingConnection" }; return NativeCall<bool, bool*>(this, f, bHasPendingConnection); }
	bool HasPendingData(unsigned int* PendingDataSize) { static NativeFunction f{ "FSocketBSD.HasPendingData" }; return NativeCall<bool, unsigned int*>(this, f, PendingDataSize); }
	FSocket* Accept(FString* SocketDescription) { static NativeFunction f{ "FSocketBSD.Accept(const FString&)" }; return NativeCall<FSocket*, FString*>(this, f, SocketDescription); }
	FSocket* Accept(FInternetAddr* OutAddr, FString* SocketDescription) { static NativeFunction f{ "FSocketBSD.Accept(FInternetAddr&,const FString&)" }; return NativeCall<FSocket*, FInternetAddr*, FString*>(this, f, OutAddr, SocketDescription); }
	bool SendTo(const char* Data, int Count, int* BytesSent, FInternetAddr* Destination) { static NativeFunction f{ "FSocketBSD.SendTo" }; return NativeCall<bool, const char*, int, int*, FInternetAddr*>(this, f, Data, Count, BytesSent, Destination); }
	bool Send(const char* Data, int Count, int* BytesSent) { static NativeFunction f{ "FSocketBSD.Send" }; return NativeCall<bool, const char*, int, int*>(this, f, Data, Count, BytesSent); }
	bool RecvFrom(char* Data, int BufferSize, int* BytesRead, FInternetAddr* Source, ESocketReceiveFlags::Type Flags) { static NativeFunction f{ "FSocketBSD.RecvFrom" }; return NativeCall<bool, char*, int, int*, FInternetAddr*, ESocketReceiveFlags::Type>(this, f, Data, BufferSize, BytesRead, Source, Flags); }
	bool Recv(char* Data, int BufferSize, int* BytesRead, ESocketReceiveFlags::Type Flags) { static NativeFunction f{ "FSocketBSD.Recv" }; return NativeCall<bool, char*, int, int*, ESocketReceiveFlags::Type>(this, f, Data, BufferSize, BytesRead, Flags); }
	ESocketConnectionState GetConnectionState() { static NativeFunction f{ "FSocketBSD.GetConnectionState" }; return NativeCall<ESocketConnectionState>(this, f); }
	void GetAddress(FInternetAddr* OutAddr) { static NativeFunction f{ "FSocketBSD.GetAddress" }; NativeCall<void, FInternetAddr*>(this, f, OutAddr); }
	bool SetNonBlocking(bool bIsNonBlocking) { static NativeFunction f{ "FSocketBSD.SetNonBlocking" }; return NativeCall<bool, bool>(this, f, bIsNonBlocking); }
	bool SetBroadcast(bool bAllowBroadcast) { static NativeFunction f{ "FSocketBSD.SetBroadcast" }; return NativeCall<bool, bool>(this, f, bAllowBroadcast); }
	bool JoinMulticastGroup(FInternetAddr* GroupAddress) { static NativeFunction f{ "FSocketBSD.JoinMulticastGroup" }; return NativeCall<bool, FInternetAddr*>(this, f, GroupAddress); }
	bool LeaveMulticastGroup(FInternetAddr* GroupAddress) { static NativeFunction f{ "FSocketBSD.LeaveMulticastGroup" }; return NativeCall<bool, FInternetAddr*>(this, f, GroupAddress); }
	bool SetMulticastLoopback(bool bLoopback) { static NativeFunction f{ "FSocketBSD.SetMulticastLoopback" }; return NativeCall<bool, bool>(this, f, bLoopback); }
	bool SetMulticastTtl(char TimeToLive) { static NativeFunction f{ "FSocketBSD.SetMulticastTtl" }; return NativeCall<bool, char>(this, f, TimeToLive); }
	bool SetReuseAddr(bool bAllowReuse) { static NativeFunction f{ "FSocketBSD.SetReuseAddr" }; return NativeCall<bool, bool>(this, f, bAllowReuse); }
	bool SetLinger(bool bShouldLinger, int Timeout) { static NativeFunction f{ "FSocketBSD.SetLinger" }; return NativeCall<bool, bool, int>(this, f, bShouldLinger, Timeout); }
	bool SetSendBufferSize(int Size, int* NewSize) { static NativeFunction f{ "FSocketBSD.SetSendBufferSize" }; return NativeCall<bool, int, int*>(this, f, Size, NewSize); }
	bool SetReceiveBufferSize(int Size, int* NewSize) { static NativeFunction f{ "FSocketBSD.SetReceiveBufferSize" }; return NativeCall<bool, int, int*>(this, f, Size, NewSize); }
	int GetPortNo() { static NativeFunction f{ "FSocketBSD.GetPortNo" }; return NativeCall<int>(this, f); }
};

struct RCONClientConnection
{
	FSocket* SocketField() { static NativeFieldOffset f{ "RCONClientConnection.Socket" }; return *GetNativePointerField<FSocket**>(this, f); }
	UShooterCheatManager* CheatManagerField() { static NativeFieldOffset f{ "RCONClientConnection.CheatManager" }; return *GetNativePointerField<UShooterCheatManager**>(this, f); }
	bool& IsAuthenticatedField() { static NativeFieldOffset f{ "RCONClientConnection.IsAuthenticated" }; return *GetNativePointerField<bool*>(this, f); }
	bool& IsClosedField() { static NativeFieldOffset f{ "RCONClientConnection.IsClosed" }; return *GetNativePointerField<bool*>(this, f); }
	TArray<signed char>& DataBufferField() { static NativeFieldOffset f{ "RCONClientConnection.DataBuffer" }; return *GetNativePointerField<TArray<signed char>*>(this, f); }
	unsigned int& CurrentPacketSizeField() { static NativeFieldOffset f{ "RCONClientConnection.CurrentPacketSize" }; return *GetNativePointerField<unsigned int*>(this, f); }
	long double& LastReceiveTimeField() { static NativeFieldOffset f{ "RCONClientConnection.LastReceiveTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastSendKeepAliveTimeField() { static NativeFieldOffset f{ "RCONClientConnection.LastSendKeepAliveTime" }; return *GetNativePointerField<long double*>(this, f); }
	FString& ServerPasswordField() { static NativeFieldOffset f{ "RCONClientConnection.ServerPassword" }; return *GetNativePointerField<FString*>(this, f); }

	// Functions

	void Tick(long double WorldTime, UWorld* InWorld) { static NativeFunction f{ "RCONClientConnection.Tick" }; NativeCall<void, long double, UWorld*>(this, f, WorldTime, InWorld); }
	void ProcessRCONPacket(RCONPacket* Packet, UWorld* InWorld) { static NativeFunction f{ "RCONClientConnection.ProcessRCONPacket" }; NativeCall<void, RCONPacket*, UWorld*>(this, f, Packet, InWorld); }
	void SendMessageW(int Id, int Type, FString* OutGoingMessage) { static NativeFunction f{ "RCONClientConnection.SendMessageW" }; NativeCall<void, int, int, FString*>(this, f, Id, Type, OutGoingMessage); }
	void Close() { static NativeFunction f{ "RCONClientConnection.Close" }; NativeCall<void>(this, f); }
};

struct RCONPacket
{
	int Length;
	int Id;
	int Type;
	FString Body;
};

struct UGameInstance;

struct UGameplayStatics
{
	// Functions

	static APlayerController* GetPlayerController(UObject* WorldContextObject, int PlayerIndex) { static NativeFunction f{ "UGameplayStatics.GetPlayerController" }; return NativeCall<APlayerController*, UObject*, int>(nullptr, f, WorldContextObject, PlayerIndex); }
	static APlayerController* CreatePlayer(UObject* WorldContextObject, int ControllerId, bool bSpawnPawn) { static NativeFunction f{ "UGameplayStatics.CreatePlayer" }; return NativeCall<APlayerController*, UObject*, int, bool>(nullptr, f, WorldContextObject, ControllerId, bSpawnPawn); }
	static void SetGlobalTimeDilation(UObject* WorldContextObject, float TimeDilation) { static NativeFunction f{ "UGameplayStatics.SetGlobalTimeDilation" }; NativeCall<void, UObject*, float>(nullptr, f, WorldContextObject, TimeDilation); }
	static bool SetGamePaused(UObject* WorldContextObject, bool bPaused) { static NativeFunction f{ "UGameplayStatics.SetGamePaused" }; return NativeCall<bool, UObject*, bool>(nullptr, f, WorldContextObject, bPaused); }
	static bool ApplyRadialDamage(UObject* WorldContextObject, float BaseDamage, FVector* Origin, float DamageRadius, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor*>* IgnoreActors, AActor* DamageCauser, AController* InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel, float Impulse) { static NativeFunction f{ "UGameplayStatics.ApplyRadialDamage" }; return NativeCall<bool, UObject*, float, FVector*, float, TSubclassOf<UDamageType>, TArray<AActor*>*, AActor*, AController*, bool, ECollisionChannel, float>(nullptr, f, WorldContextObject, BaseDamage, Origin, DamageRadius, DamageTypeClass, IgnoreActors, DamageCauser, InstigatedByController, bDoFullDamage, DamagePreventionChannel, Impulse); }
	static bool ApplyRadialDamageIgnoreDamageActors(UObject* WorldContextObject, float BaseDamage, FVector* Origin, float DamageRadius, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor*>* IgnoreActors, TArray<AActor*>* IgnoreDamageActors, AActor* DamageCauser, AController* InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel, float Impulse) { static NativeFunction f{ "UGameplayStatics.ApplyRadialDamageIgnoreDamageActors" }; return NativeCall<bool, UObject*, float, FVector*, float, TSubclassOf<UDamageType>, TArray<AActor*>*, TArray<AActor*>*, AActor*, AController*, bool, ECollisionChannel, float>(nullptr, f, WorldContextObject, BaseDamage, Origin, DamageRadius, DamageTypeClass, IgnoreActors, IgnoreDamageActors, DamageCauser, InstigatedByController, bDoFullDamage, DamagePreventionChannel, Impulse); }
	static bool ApplyRadialDamageWithFalloff(UObject* WorldContextObject, float BaseDamage, float MinimumDamage, FVector* Origin, float DamageInnerRadius, float DamageOuterRadius, float DamageFalloff, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor*>* IgnoreActors, AActor* DamageCauser, AController* InstigatedByController, ECollisionChannel DamagePreventionChannel, float Impulse, TArray<AActor*>* IgnoreDamageActors, int NumAdditionalAttempts) { static NativeFunction f{ "UGameplayStatics.ApplyRadialDamageWithFalloff" }; return NativeCall<bool, UObject*, float, float, FVector*, float, float, float, TSubclassOf<UDamageType>, TArray<AActor*>*, AActor*, AController*, ECollisionChannel, float, TArray<AActor*>*, int>(nullptr, f, WorldContextObject, BaseDamage, MinimumDamage, Origin, DamageInnerRadius, DamageOuterRadius, DamageFalloff, DamageTypeClass, IgnoreActors, DamageCauser, InstigatedByController, DamagePreventionChannel, Impulse, IgnoreDamageActors, NumAdditionalAttempts); }
	static void ApplyPointDamage(AActor* DamagedActor, float BaseDamage, FVector* HitFromDirection, FHitResult* HitInfo, AController* EventInstigator, AActor* DamageCauser, TSubclassOf<UDamageType> DamageTypeClass, float Impulse, bool bForceCollisionCheck, ECollisionChannel ForceCollisionCheckTraceChannel) { static NativeFunction f{ "UGameplayStatics.ApplyPointDamage" }; NativeCall<void, AActor*, float, FVector*, FHitResult*, AController*, AActor*, TSubclassOf<UDamageType>, float, bool, ECollisionChannel>(nullptr, f, DamagedActor, BaseDamage, HitFromDirection, HitInfo, EventInstigator, DamageCauser, DamageTypeClass, Impulse, bForceCollisionCheck, ForceCollisionCheckTraceChannel); }
	static void ApplyDamage(AActor* DamagedActor, float BaseDamage, AController* EventInstigator, AActor* DamageCauser, TSubclassOf<UDamageType> DamageTypeClass = TSubclassOf<UDamageType>(), float Impulse = 0.f) { static NativeFunction f{ "UGameplayStatics.ApplyDamage" }; NativeCall<void, AActor*, float, AController*, AActor*, TSubclassOf<UDamageType>, float>(nullptr, f, DamagedActor, BaseDamage, EventInstigator, DamageCauser, DamageTypeClass, Impulse); }
	static AActor* BeginSpawningActorFromBlueprint(UObject* WorldContextObject, UBlueprint* Blueprint, FTransform* SpawnTransform, bool bNoCollisionFail) { static NativeFunction f{ "UGameplayStatics.BeginSpawningActorFromBlueprint" }; return NativeCall<AActor*, UObject*, UBlueprint*, FTransform*, bool>(nullptr, f, WorldContextObject, Blueprint, SpawnTransform, bNoCollisionFail); }
	static AActor* BeginSpawningActorFromClass(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FTransform* SpawnTransform, bool bNoCollisionFail) { static NativeFunction f{ "UGameplayStatics.BeginSpawningActorFromClass" }; return NativeCall<AActor*, UObject*, TSubclassOf<AActor>, FTransform*, bool>(nullptr, f, WorldContextObject, ActorClass, SpawnTransform, bNoCollisionFail); }
	static AActor* FinishSpawningActor(AActor* Actor, FTransform* SpawnTransform) { static NativeFunction f{ "UGameplayStatics.FinishSpawningActor" }; return NativeCall<AActor*, AActor*, FTransform*>(nullptr, f, Actor, SpawnTransform); }
	static void LoadStreamLevel(UObject* WorldContextObject, FName LevelName, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FLatentActionInfo* LatentInfo) { static NativeFunction f{ "UGameplayStatics.LoadStreamLevel" }; NativeCall<void, UObject*, FName, bool, bool, FLatentActionInfo*>(nullptr, f, WorldContextObject, LevelName, bMakeVisibleAfterLoad, bShouldBlockOnLoad, LatentInfo); }
	[[deprecated("pass a pointer")]] static void LoadStreamLevel(UObject* WorldContextObject, FName LevelName, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FLatentActionInfo& LatentInfo) { ReportDeprecatedApiUse("UGameplayStatics.LoadStreamLevel(by value)"); LoadStreamLevel(WorldContextObject, LevelName, bMakeVisibleAfterLoad, bShouldBlockOnLoad, &LatentInfo); }
	static void UnloadStreamLevel(UObject* WorldContextObject, FName LevelName, FLatentActionInfo* LatentInfo) { static NativeFunction f{ "UGameplayStatics.UnloadStreamLevel" }; NativeCall<void, UObject*, FName, FLatentActionInfo*>(nullptr, f, WorldContextObject, LevelName, LatentInfo); }
	[[deprecated("pass a pointer")]] static void UnloadStreamLevel(UObject* WorldContextObject, FName LevelName, FLatentActionInfo& LatentInfo) { ReportDeprecatedApiUse("UGameplayStatics.UnloadStreamLevel(by value)"); UnloadStreamLevel(WorldContextObject, LevelName, &LatentInfo); }
	static void OpenLevel(UObject* WorldContextObject, FName LevelName, bool bAbsolute, FString Options) { static NativeFunction f{ "UGameplayStatics.OpenLevel" }; NativeCall<void, UObject*, FName, bool, FString>(nullptr, f, WorldContextObject, LevelName, bAbsolute, Options); }
	static FVector* GetActorArrayAverageLocation(FVector* result, TArray<AActor*>* Actors) { static NativeFunction f{ "UGameplayStatics.GetActorArrayAverageLocation" }; return NativeCall<FVector*, FVector*, TArray<AActor*>*>(nullptr, f, result, Actors); }
	static void GetActorArrayBounds(TArray<AActor*>* Actors, bool bOnlyCollidingComponents, FVector* Center, FVector* BoxExtent) { static NativeFunction f{ "UGameplayStatics.GetActorArrayBounds" }; NativeCall<void, TArray<AActor*>*, bool, FVector*, FVector*>(nullptr, f, Actors, bOnlyCollidingComponents, Center, BoxExtent); }
	static void GetAllActorsOfClass(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, TArray<AActor*>* OutActors) { static NativeFunction f{ "UGameplayStatics.GetAllActorsOfClass" }; NativeCall<void, UObject*, TSubclassOf<AActor>, TArray<AActor*>*>(nullptr, f, WorldContextObject, ActorClass, OutActors); }
	static void GetAllActorsWithInterface(UObject* WorldContextObject, TSubclassOf<UInterface> Interface, TArray<AActor*>* OutActors) { static NativeFunction f{ "UGameplayStatics.GetAllActorsWithInterface" }; NativeCall<void, UObject*, TSubclassOf<UInterface>, TArray<AActor*>*>(nullptr, f, WorldContextObject, Interface, OutActors); }
	static void BreakHitResult(FHitResult* Hit, FVector* Location, FVector* Normal, FVector* ImpactPoint, FVector* ImpactNormal, UPhysicalMaterial** PhysMat, AActor** HitActor, UPrimitiveComponent** HitComponent, FName* HitBoneName, int* HitItem, bool* BlockingHit) { static NativeFunction f{ "UGameplayStatics.BreakHitResult" }; NativeCall<void, FHitResult*, FVector*, FVector*, FVector*, FVector*, UPhysicalMaterial**, AActor**, UPrimitiveComponent**, FName*, int*, bool*>(nullptr, f, Hit, Location, Normal, ImpactPoint, ImpactNormal, PhysMat, HitActor, HitComponent, HitBoneName, HitItem, BlockingHit); }
	static void BreakHitResult_OLD(FHitResult* Hit, FVector* Location, FVector* Normal, FVector* ImpactPoint, FVector* ImpactNormal, UPhysicalMaterial** PhysMat, AActor** HitActor, UPrimitiveComponent** HitComponent, FName* HitBoneName, int* HitItem) { static NativeFunction f{ "UGameplayStatics.BreakHitResult_OLD" }; NativeCall<void, FHitResult*, FVector*, FVector*, FVector*, FVector*, UPhysicalMaterial**, AActor**, UPrimitiveComponent**, FName*, int*>(nullptr, f, Hit, Location, Normal, ImpactPoint, ImpactNormal, PhysMat, HitActor, HitComponent, HitBoneName, HitItem); }
	static EPhysicalSurface GetSurfaceType(FHitResult* Hit) { static NativeFunction f{ "UGameplayStatics.GetSurfaceType" }; return NativeCall<EPhysicalSurface, FHitResult*>(nullptr, f, Hit); }
	static bool AreAnyListenersWithinRange(FVector Location, float MaximumRange) { static NativeFunction f{ "UGameplayStatics.AreAnyListenersWithinRange" }; return NativeCall<bool, FVector, float>(nullptr, f, Location, MaximumRange); }
	static void PlayDialogueAtLocation(UObject* WorldContextObject, UDialogueWave* Dialogue, FDialogueContext* Context, FVector Location, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings) { static NativeFunction f{ "UGameplayStatics.PlayDialogueAtLocation" }; NativeCall<void, UObject*, UDialogueWave*, FDialogueContext*, FVector, float, float, float, USoundAttenuation*>(nullptr, f, WorldContextObject, Dialogue, Context, Location, VolumeMultiplier, PitchMultiplier, StartTime, AttenuationSettings); }
	static UAudioComponent* PlayDialogueAttached(UDialogueWave* Dialogue, FDialogueContext* Context, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, EAttachLocation::Type LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings) { static NativeFunction f{ "UGameplayStatics.PlayDialogueAttached" }; return NativeCall<UAudioComponent*, UDialogueWave*, FDialogueContext*, USceneComponent*, FName, FVector, EAttachLocation::Type, bool, float, float, float, USoundAttenuation*>(nullptr, f, Dialogue, Context, AttachToComponent, AttachPointName, Location, LocationType, bStopWhenAttachedToDestroyed, VolumeMultiplier, PitchMultiplier, StartTime, AttenuationSettings); }
	static void PlaySound(UObject* WorldContextObject, USoundCue* InSoundCue, USceneComponent* AttachComponent, FName AttachName, bool bFollow, float VolumeMultiplier, float PitchMultiplier) { static NativeFunction f{ "UGameplayStatics.PlaySound" }; NativeCall<void, UObject*, USoundCue*, USceneComponent*, FName, bool, float, float>(nullptr, f, WorldContextObject, InSoundCue, AttachComponent, AttachName, bFollow, VolumeMultiplier, PitchMultiplier); }
	//static USaveGame* CreateSaveGameObject(TSubclassOf<USaveGame> SaveGameClass) { return NativeCall<USaveGame*, TSubclassOf<USaveGame>>(nullptr, "UGameplayStatics.CreateSaveGameObject", SaveGameClass); }
	//static USaveGame* CreateSaveGameObjectFromBlueprint(UBlueprint* SaveGameBlueprint) { return NativeCall<USaveGame*, UBlueprint*>(nullptr, "UGameplayStatics.CreateSaveGameObjectFromBlueprint", SaveGameBlueprint); }
	//static bool SaveGameToSlot(USaveGame* SaveGameObject, FString* SlotName, const int UserIndex) { return NativeCall<bool, USaveGame*, FString*, const int>(nullptr, "UGameplayStatics.SaveGameToSlot", SaveGameObject, SlotName, UserIndex); }
	//static USaveGame* LoadGameFromSlot(FString* SlotName, const int UserIndex) { return NativeCall<USaveGame*, FString*, const int>(nullptr, "UGameplayStatics.LoadGameFromSlot", SlotName, UserIndex); }
	static void GetAccurateRealTime(UObject* WorldContextObject, int* Seconds, float* PartialSeconds) { static NativeFunction f{ "UGameplayStatics.GetAccurateRealTime" }; NativeCall<void, UObject*, int*, float*>(nullptr, f, WorldContextObject, Seconds, PartialSeconds); }
	static FString* GetPlatformName(FString* result) { static NativeFunction f{ "UGameplayStatics.GetPlatformName" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	//static bool SuggestProjectileVelocity(UObject* WorldContextObject, FVector* OutTossVelocity, FVector Start, FVector End, float TossSpeed, bool bFavorHighArc, float CollisionRadius, float OverrideGravityZ, ESuggestProjVelocityTraceOption::Type TraceOption, FCollisionResponseParams* ResponseParam, TArray<AActor*>* ActorsToIgnore, bool bDrawDebug) { return NativeCall<bool, UObject*, FVector*, FVector, FVector, float, bool, float, float, ESuggestProjVelocityTraceOption::Type, FCollisionResponseParams*, TArray<AActor*>*, bool>(nullptr, "UGameplayStatics.SuggestProjectileVelocity", WorldContextObject, OutTossVelocity, Start, End, TossSpeed, bFavorHighArc, CollisionRadius, OverrideGravityZ, TraceOption, ResponseParam, ActorsToIgnore, bDrawDebug); }
	static void StaticRegisterNativesUGameplayStatics() { static NativeFunction f{ "UGameplayStatics.StaticRegisterNativesUGameplayStatics" }; NativeCall<void>(nullptr, f); }
};

struct FItemMultiplier
{
	TSubclassOf<UPrimalItem> ItemClass;
	float ItemMultiplier;
};

struct UPrimalEngramEntry : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalEngramEntry.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "UPrimalEngramEntry.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	int& RequiredCharacterLevelField() { static NativeFieldOffset f{ "UPrimalEngramEntry.RequiredCharacterLevel" }; return *GetNativePointerField<int*>(this, f); }
	int& RequiredEngramPointsField() { static NativeFieldOffset f{ "UPrimalEngramEntry.RequiredEngramPoints" }; return *GetNativePointerField<int*>(this, f); }
	TSubclassOf<UPrimalItem>& BluePrintEntryField() { static NativeFieldOffset f{ "UPrimalEngramEntry.BluePrintEntry" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	FString& ExtraEngramDescriptionField() { static NativeFieldOffset f{ "UPrimalEngramEntry.ExtraEngramDescription" }; return *GetNativePointerField<FString*>(this, f); }
	TArray<FEngramEntries>& EngramRequirementSetsField() { static NativeFieldOffset f{ "UPrimalEngramEntry.EngramRequirementSets" }; return *GetNativePointerField<TArray<FEngramEntries>*>(this, f); }
	int& MyEngramIndexField() { static NativeFieldOffset f{ "UPrimalEngramEntry.MyEngramIndex" }; return *GetNativePointerField<int*>(this, f); }
	TEnumAsByte<enum EEngramGroup::Type>& EngramGroupField() { static NativeFieldOffset f{ "UPrimalEngramEntry.EngramGroup" }; return *GetNativePointerField<TEnumAsByte<enum EEngramGroup::Type>*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bGiveBlueprintToPlayerInventory() { static NativeBitField f{ "UPrimalEngramEntry.bGiveBlueprintToPlayerInventory" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanBeManuallyUnlocked() { static NativeBitField f{ "UPrimalEngramEntry.bCanBeManuallyUnlocked" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsSPlusEngram() { static NativeBitField f{ "UPrimalEngramEntry.bIsSPlusEngram" }; return { this, f }; }

	// Functions

	UObject* GetObjectW() { static NativeFunction f{ "UPrimalEngramEntry.GetObjectW" }; return NativeCall<UObject*>(this, f); }
	FString* GetEntryString(FString* result) { static NativeFunction f{ "UPrimalEngramEntry.GetEntryString" }; return NativeCall<FString*, FString*>(this, f, result); }
	UTexture2D* GetEntryIcon(UObject* AssociatedDataObject, bool bIsEnabled) { static NativeFunction f{ "UPrimalEngramEntry.GetEntryIcon" }; return NativeCall<UTexture2D*, UObject*, bool>(this, f, AssociatedDataObject, bIsEnabled); }
	bool MeetsEngramRequirements(AShooterPlayerState* aPlayerState, bool bOnlyCheckLevel, bool bDontCheckEngramPreRequirements) { static NativeFunction f{ "UPrimalEngramEntry.MeetsEngramRequirements" }; return NativeCall<bool, AShooterPlayerState*, bool, bool>(this, f, aPlayerState, bOnlyCheckLevel, bDontCheckEngramPreRequirements); }
	bool MeetsEngramChainRequirements(AShooterPlayerState* aPlayerState) { static NativeFunction f{ "UPrimalEngramEntry.MeetsEngramChainRequirements" }; return NativeCall<bool, AShooterPlayerState*>(this, f, aPlayerState); }
	FString* GetEngramDescription(FString* result, AShooterPlayerState* aPlayerState) { static NativeFunction f{ "UPrimalEngramEntry.GetEngramDescription" }; return NativeCall<FString*, FString*, AShooterPlayerState*>(this, f, result, aPlayerState); }
	FString* GetEngramName(FString* result) { static NativeFunction f{ "UPrimalEngramEntry.GetEngramName" }; return NativeCall<FString*, FString*>(this, f, result); }
	int GetRequiredEngramPoints() { static NativeFunction f{ "UPrimalEngramEntry.GetRequiredEngramPoints" }; return NativeCall<int>(this, f); }
	int GetRequiredLevel() { static NativeFunction f{ "UPrimalEngramEntry.GetRequiredLevel" }; return NativeCall<int>(this, f); }
	bool UseEngramRequirementSets() { static NativeFunction f{ "UPrimalEngramEntry.UseEngramRequirementSets" }; return NativeCall<bool>(this, f); }
	bool IsEngramClassHidden(TSubclassOf<UPrimalItem> ForItemClass) { static NativeFunction f{ "UPrimalEngramEntry.IsEngramClassHidden" }; return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, f, ForItemClass); }
	void GetAllChainedPreReqs(AShooterPlayerState* aPlayerState, TArray<TSubclassOf<UPrimalEngramEntry>>* TestedEntries) { static NativeFunction f{ "UPrimalEngramEntry.GetAllChainedPreReqs" }; NativeCall<void, AShooterPlayerState*, TArray<TSubclassOf<UPrimalEngramEntry>>*>(this, f, aPlayerState, TestedEntries); }
	int GetChainRequiredEngramPoints(TArray<TSubclassOf<UPrimalEngramEntry>>* TestedEntries) { static NativeFunction f{ "UPrimalEngramEntry.GetChainRequiredEngramPoints" }; return NativeCall<int, TArray<TSubclassOf<UPrimalEngramEntry>>*>(this, f, TestedEntries); }
	void ClearHiddenEngramRequirements() { static NativeFunction f{ "UPrimalEngramEntry.ClearHiddenEngramRequirements" }; NativeCall<void>(this, f); }
};

struct FDinoAncestorsEntry
{
	FString MaleName;
	unsigned int MaleDinoID1;
	unsigned int MaleDinoID2;
	FString FemaleName;
	unsigned int FemaleDinoID1;
	unsigned int FemaleDinoID2;
};

struct FCraftingResourceRequirement
{
	float BaseResourceRequirement;
	TSubclassOf<UPrimalItem> ResourceItemType;
	bool bCraftingRequireExactResourceType;
};

struct UKismetSystemLibrary
{
	// Functions

	static FString* MakeLiteralString(FString* result, FString* Value) { static NativeFunction f{ "UKismetSystemLibrary.MakeLiteralString" }; return NativeCall<FString*, FString*, FString*>(nullptr, f, result, Value); }
	static FString* GetDisplayName(FString* result, UObject* Object) { static NativeFunction f{ "UKismetSystemLibrary.GetDisplayName" }; return NativeCall<FString*, FString*, UObject*>(nullptr, f, result, Object); }
	static FString* GetClassDisplayName(FString* result, UClass* Class) { static NativeFunction f{ "UKismetSystemLibrary.GetClassDisplayName" }; return NativeCall<FString*, FString*, UClass*>(nullptr, f, result, Class); }
	static FString* GetEngineVersion(FString* result) { static NativeFunction f{ "UKismetSystemLibrary.GetEngineVersion" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static FString* GetGameName(FString* result) { static NativeFunction f{ "UKismetSystemLibrary.GetGameName" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static FString* GetPlatformUserName(FString* result) { static NativeFunction f{ "UKismetSystemLibrary.GetPlatformUserName" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static bool DoesImplementInterface(UObject* TestObject, TSubclassOf<UInterface> Interface) { static NativeFunction f{ "UKismetSystemLibrary.DoesImplementInterface" }; return NativeCall<bool, UObject*, TSubclassOf<UInterface>>(nullptr, f, TestObject, Interface); }
	static FString* GetUniqueDeviceId(FString* result) { static NativeFunction f{ "UKismetSystemLibrary.GetUniqueDeviceId" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	//static FText* MakeLiteralText(FText* result, FText Value) { return NativeCall<FText*, FText*, FText>(nullptr, "UKismetSystemLibrary.MakeLiteralText", result, Value); }
	//static void QuitGame(UObject* WorldContextObject, APlayerController* SpecificPlayer, TEnumAsByte<enum EQuitPreference::Type> QuitPreference) { NativeCall<void, UObject*, APlayerController*, TEnumAsByte<enum EQuitPreference::Type>>(nullptr, "UKismetSystemLibrary.QuitGame", WorldContextObject, SpecificPlayer, QuitPreference); }
	static void K2_SetTimer(UObject* Object, FString FunctionName, float Time, bool bLooping) { static NativeFunction f{ "UKismetSystemLibrary.K2_SetTimer" }; NativeCall<void, UObject*, FString, float, bool>(nullptr, f, Object, FunctionName, Time, bLooping); }
	static void K2_SetTimerForNextTick(UObject* Object, FString FunctionName, bool bLooping) { static NativeFunction f{ "UKismetSystemLibrary.K2_SetTimerForNextTick" }; NativeCall<void, UObject*, FString, bool>(nullptr, f, Object, FunctionName, bLooping); }
	static void K2_SetTimerDelegate(FBlueprintTimerDynamicDelegate* Delegate, float Time, bool bLooping) { static NativeFunction f{ "UKismetSystemLibrary.K2_SetTimerDelegate" }; NativeCall<void, FBlueprintTimerDynamicDelegate*, float, bool>(nullptr, f, Delegate, Time, bLooping); }
	[[deprecated("pass a pointer")]] static void K2_SetTimerDelegate(FBlueprintTimerDynamicDelegate& Delegate, float Time, bool bLooping) { ReportDeprecatedApiUse("UKismetSystemLibrary.K2_SetTimerDelegate(by value)"); K2_SetTimerDelegate(&Delegate, Time, bLooping); }
	static void K2_SetTimerForNextTickDelegate(FBlueprintTimerDynamicDelegate* Delegate, bool bLooping) { static NativeFunction f{ "UKismetSystemLibrary.K2_SetTimerForNextTickDelegate" }; NativeCall<void, FBlueprintTimerDynamicDelegate*, bool>(nullptr, f, Delegate, bLooping); }
	[[deprecated("pass a pointer")]] static void K2_SetTimerForNextTickDelegate(FBlueprintTimerDynamicDelegate& Delegate, bool bLooping) { ReportDeprecatedApiUse("UKismetSystemLibrary.K2_SetTimerForNextTickDelegate(by value)"); K2_SetTimerForNextTickDelegate(&Delegate, bLooping); }
	static void K2_ClearTimer(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_ClearTimer" }; NativeCall<void, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static void K2_PauseTimer(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_PauseTimer" }; NativeCall<void, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static void K2_UnPauseTimer(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_UnPauseTimer" }; NativeCall<void, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static bool K2_IsTimerActive(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_IsTimerActive" }; return NativeCall<bool, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static bool K2_IsTimerPaused(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_IsTimerPaused" }; return NativeCall<bool, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static bool K2_TimerExists(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_TimerExists" }; return NativeCall<bool, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static float K2_GetTimerElapsedTime(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_GetTimerElapsedTime" }; return NativeCall<float, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static float K2_GetTimerRemainingTime(UObject* Object, FString FunctionName) { static NativeFunction f{ "UKismetSystemLibrary.K2_GetTimerRemainingTime" }; return NativeCall<float, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static void SetClassPropertyByName(UObject* Object, FName PropertyName, TSubclassOf<UObject> Value) { static NativeFunction f{ "UKismetSystemLibrary.SetClassPropertyByName" }; NativeCall<void, UObject*, FName, TSubclassOf<UObject>>(nullptr, f, Object, PropertyName, Value); }
	static void SetVectorPropertyByName(UObject* Object, FName PropertyName, FVector* Value) { static NativeFunction f{ "UKismetSystemLibrary.SetVectorPropertyByName" }; NativeCall<void, UObject*, FName, FVector*>(nullptr, f, Object, PropertyName, Value); }
	static void SetRotatorPropertyByName(UObject* Object, FName PropertyName, FRotator* Value) { static NativeFunction f{ "UKismetSystemLibrary.SetRotatorPropertyByName" }; NativeCall<void, UObject*, FName, FRotator*>(nullptr, f, Object, PropertyName, Value); }
	static void SetLinearColorPropertyByName(UObject* Object, FName PropertyName, FLinearColor* Value) { static NativeFunction f{ "UKismetSystemLibrary.SetLinearColorPropertyByName" }; NativeCall<void, UObject*, FName, FLinearColor*>(nullptr, f, Object, PropertyName, Value); }
	static void SetTransformPropertyByName(UObject* Object, FName PropertyName, FTransform* Value) { static NativeFunction f{ "UKismetSystemLibrary.SetTransformPropertyByName" }; NativeCall<void, UObject*, FName, FTransform*>(nullptr, f, Object, PropertyName, Value); }
	static void GetActorListFromComponentList(TArray<UPrimitiveComponent*>* ComponentList, UClass* ActorClassFilter, TArray<AActor*>* OutActorList) { static NativeFunction f{ "UKismetSystemLibrary.GetActorListFromComponentList" }; NativeCall<void, TArray<UPrimitiveComponent*>*, UClass*, TArray<AActor*>*>(nullptr, f, ComponentList, ActorClassFilter, OutActorList); }
	static bool SphereOverlapActors_NEW(UObject* WorldContextObject, FVector SpherePos, float SphereRadius, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ActorClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<AActor*>* OutActors) { static NativeFunction f{ "UKismetSystemLibrary.SphereOverlapActors_NEW" }; return NativeCall<bool, UObject*, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<AActor*>*>(nullptr, f, WorldContextObject, SpherePos, SphereRadius, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool SphereOverlapActorsSimple(UObject* WorldContextObject, FVector SpherePos, float SphereRadius, TEnumAsByte<enum EObjectTypeQuery> ObjectType, UClass* ActorClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<AActor*>* OutActors) { static NativeFunction f{ "UKismetSystemLibrary.SphereOverlapActorsSimple" }; return NativeCall<bool, UObject*, FVector, float, TEnumAsByte<enum EObjectTypeQuery>, UClass*, TArray<AActor*>*, TArray<AActor*>*>(nullptr, f, WorldContextObject, SpherePos, SphereRadius, ObjectType, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool SphereOverlapComponents_NEW(UObject* WorldContextObject, FVector SpherePos, float SphereRadius, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ComponentClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<UPrimitiveComponent*>* OutComponents) { static NativeFunction f{ "UKismetSystemLibrary.SphereOverlapComponents_NEW" }; return NativeCall<bool, UObject*, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<UPrimitiveComponent*>*>(nullptr, f, WorldContextObject, SpherePos, SphereRadius, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool BoxOverlapComponents_NEW(UObject* WorldContextObject, FVector BoxPos, FVector BoxExtent, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ComponentClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<UPrimitiveComponent*>* OutComponents) { static NativeFunction f{ "UKismetSystemLibrary.BoxOverlapComponents_NEW" }; return NativeCall<bool, UObject*, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<UPrimitiveComponent*>*>(nullptr, f, WorldContextObject, BoxPos, BoxExtent, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	[[deprecated("not in this game build")]] static bool BoxOverlapActors_NEW(UObject* WorldContextObject, FVector BoxPos, FVector BoxExtent, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ActorClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<AActor*>* OutActors) { ReportDeprecatedApiUse("UKismetSystemLibrary.BoxOverlapActors_NEW"); static NativeFunction f{ "UKismetSystemLibrary.BoxOverlapActors_NEW" }; return NativeCall<bool, UObject*, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<AActor*>*>(nullptr, f, WorldContextObject, BoxPos, BoxExtent, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool CapsuleOverlapActors_NEW(UObject* WorldContextObject, FVector CapsulePos, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ActorClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<AActor*>* OutActors) { static NativeFunction f{ "UKismetSystemLibrary.CapsuleOverlapActors_NEW" }; return NativeCall<bool, UObject*, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<AActor*>*>(nullptr, f, WorldContextObject, CapsulePos, Radius, HalfHeight, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool CapsuleOverlapComponents_NEW(UObject* WorldContextObject, FVector CapsulePos, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ComponentClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<UPrimitiveComponent*>* OutComponents) { static NativeFunction f{ "UKismetSystemLibrary.CapsuleOverlapComponents_NEW" }; return NativeCall<bool, UObject*, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<UPrimitiveComponent*>*>(nullptr, f, WorldContextObject, CapsulePos, Radius, HalfHeight, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool ComponentOverlapActors_NEW(UPrimitiveComponent* Component, FTransform* ComponentTransform, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ActorClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<AActor*>* OutActors) { static NativeFunction f{ "UKismetSystemLibrary.ComponentOverlapActors_NEW" }; return NativeCall<bool, UPrimitiveComponent*, FTransform*, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<AActor*>*>(nullptr, f, Component, ComponentTransform, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool ComponentOverlapComponents_NEW(UPrimitiveComponent* Component, FTransform* ComponentTransform, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, UClass* ComponentClassFilter, TArray<AActor*>* ActorsToIgnore, TArray<UPrimitiveComponent*>* OutComponents) { static NativeFunction f{ "UKismetSystemLibrary.ComponentOverlapComponents_NEW" }; return NativeCall<bool, UPrimitiveComponent*, FTransform*, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, UClass*, TArray<AActor*>*, TArray<UPrimitiveComponent*>*>(nullptr, f, Component, ComponentTransform, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool BoxTraceSingle(UObject* WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult* OutHit, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.BoxTraceSingle" }; return NativeCall<bool, UObject*, FVector, FVector, FVector, FRotator, ETraceTypeQuery, bool, TArray<AActor*>*, EDrawDebugTrace::Type, FHitResult*, bool>(nullptr, f, WorldContextObject, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool BoxTraceMulti(UObject* WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult>* OutHits, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.BoxTraceMulti" }; return NativeCall<bool, UObject*, FVector, FVector, FVector, FRotator, ETraceTypeQuery, bool, TArray<AActor*>*, EDrawDebugTrace::Type, TArray<FHitResult>*, bool>(nullptr, f, WorldContextObject, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool LineTraceSingleForObjects(UObject* WorldContextObject, FVector Start, FVector End, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult* OutHit, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.LineTraceSingleForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, FHitResult*, bool>(nullptr, f, WorldContextObject, Start, End, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool LineTraceMultiForObjects(UObject* WorldContextObject, FVector Start, FVector End, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult>* OutHits, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.LineTraceMultiForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, TArray<FHitResult>*, bool>(nullptr, f, WorldContextObject, Start, End, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool SphereTraceSingleForObjects(UObject* WorldContextObject, FVector Start, FVector End, float Radius, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult* OutHit, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.SphereTraceSingleForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, FHitResult*, bool>(nullptr, f, WorldContextObject, Start, End, Radius, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool SphereTraceMultiForObjects(UObject* WorldContextObject, FVector Start, FVector End, float Radius, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult>* OutHits, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.SphereTraceMultiForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, TArray<FHitResult>*, bool>(nullptr, f, WorldContextObject, Start, End, Radius, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool BoxTraceSingleForObjects(UObject* WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult* OutHit, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.BoxTraceSingleForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, FVector, FRotator, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, FHitResult*, bool>(nullptr, f, WorldContextObject, Start, End, HalfSize, Orientation, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool BoxTraceMultiForObjects(UObject* WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult>* OutHits, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.BoxTraceMultiForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, FVector, FRotator, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, TArray<FHitResult>*, bool>(nullptr, f, WorldContextObject, Start, End, HalfSize, Orientation, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool CapsuleTraceSingleForObjects(UObject* WorldContextObject, FVector Start, FVector End, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult* OutHit, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.CapsuleTraceSingleForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, FHitResult*, bool>(nullptr, f, WorldContextObject, Start, End, Radius, HalfHeight, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool CapsuleTraceMultiForObjects(UObject* WorldContextObject, FVector Start, FVector End, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>>* ObjectTypes, bool bTraceComplex, TArray<AActor*>* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult>* OutHits, bool bIgnoreSelf) { static NativeFunction f{ "UKismetSystemLibrary.CapsuleTraceMultiForObjects" }; return NativeCall<bool, UObject*, FVector, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>>*, bool, TArray<AActor*>*, EDrawDebugTrace::Type, TArray<FHitResult>*, bool>(nullptr, f, WorldContextObject, Start, End, Radius, HalfHeight, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static void DrawDebugFrustum(UObject* WorldContextObject, FTransform* FrustumTransform, FLinearColor FrustumColor, float Duration, bool bPersistentLines = false) { static NativeFunction f{ "UKismetSystemLibrary.DrawDebugFrustum" }; NativeCall<void, UObject*, FTransform*, FLinearColor, float, bool>(nullptr, f, WorldContextObject, FrustumTransform, FrustumColor, Duration, bPersistentLines); }
	[[deprecated("not in this game build")]] static void Delay(UObject* WorldContextObject, float Duration, FLatentActionInfo LatentInfo) { ReportDeprecatedApiUse("UKismetSystemLibrary.Delay"); static NativeFunction f{ "UKismetSystemLibrary.Delay" }; NativeCall<void, UObject*, float, FLatentActionInfo>(nullptr, f, WorldContextObject, Duration, LatentInfo); }
	[[deprecated("not in this game build")]] static void RetriggerableDelay(UObject* WorldContextObject, float Duration, FLatentActionInfo LatentInfo) { ReportDeprecatedApiUse("UKismetSystemLibrary.RetriggerableDelay"); static NativeFunction f{ "UKismetSystemLibrary.RetriggerableDelay" }; NativeCall<void, UObject*, float, FLatentActionInfo>(nullptr, f, WorldContextObject, Duration, LatentInfo); }
	static void DrawDebugFloatHistoryLocation(UObject* WorldContextObject, FDebugFloatHistory* FloatHistory, FVector DrawLocation, FVector2D DrawSize, FLinearColor DrawColor, float LifeTime, bool bPersistentLines = false) { static NativeFunction f{ "UKismetSystemLibrary.DrawDebugFloatHistoryLocation" }; NativeCall<void, UObject*, FDebugFloatHistory*, FVector, FVector2D, FLinearColor, float, bool>(nullptr, f, WorldContextObject, FloatHistory, DrawLocation, DrawSize, DrawColor, LifeTime, bPersistentLines); }
	static FDebugFloatHistory* AddFloatHistorySample(FDebugFloatHistory* result, float Value, FDebugFloatHistory* FloatHistory) { static NativeFunction f{ "UKismetSystemLibrary.AddFloatHistorySample" }; return NativeCall<FDebugFloatHistory*, FDebugFloatHistory*, float, FDebugFloatHistory*>(nullptr, f, result, Value, FloatHistory); }
	static void GetActorBounds(AActor* Actor, FVector* Origin, FVector* BoxExtent) { static NativeFunction f{ "UKismetSystemLibrary.GetActorBounds" }; NativeCall<void, AActor*, FVector*, FVector*>(nullptr, f, Actor, Origin, BoxExtent); }
	//static void MoveComponentTo(USceneComponent* Component, FVector TargetRelativeLocation, FRotator TargetRelativeRotation, bool bEaseOut, bool bEaseIn, float OverTime, TEnumAsByte<enum EMoveComponentAction::Type> MoveAction, FLatentActionInfo LatentInfo, bool bSweep) { NativeCall<void, USceneComponent*, FVector, FRotator, bool, bool, float, TEnumAsByte<enum EMoveComponentAction::Type>, FLatentActionInfo, bool>(nullptr, "UKismetSystemLibrary.MoveComponentTo", Component, TargetRelativeLocation, TargetRelativeRotation, bEaseOut, bEaseIn, OverTime, MoveAction, LatentInfo, bSweep); }
	static int GetRenderingDetailMode() { static NativeFunction f{ "UKismetSystemLibrary.GetRenderingDetailMode" }; return NativeCall<int>(nullptr, f); }
	static int GetRenderingMaterialQualityLevel() { static NativeFunction f{ "UKismetSystemLibrary.GetRenderingMaterialQualityLevel" }; return NativeCall<int>(nullptr, f); }
	static void ShowPlatformSpecificAchievementsScreen(APlayerController* SpecificPlayer) { static NativeFunction f{ "UKismetSystemLibrary.ShowPlatformSpecificAchievementsScreen" }; NativeCall<void, APlayerController*>(nullptr, f, SpecificPlayer); }
	static void StaticRegisterNativesUKismetSystemLibrary() { static NativeFunction f{ "UKismetSystemLibrary.StaticRegisterNativesUKismetSystemLibrary" }; NativeCall<void>(nullptr, f); }
};

struct FOverlapResult
{
	TWeakObjectPtr<AActor> Actor;
	TWeakObjectPtr<UPrimitiveComponent> Component;
	int ItemIndex;
	unsigned __int32 bBlockingHit : 1;

	// Functions

	AActor* GetActor() { static NativeFunction f{ "FOverlapResult.GetActor" }; return NativeCall<AActor*>(this, f); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FOverlapResult.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FOverlappedFoliageElement
{
	AActor* HarvestActor;
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
	UPrimalHarvestingComponent* HarvestingComponent;
	FVector HarvestLocation;
	int HitBodyIndex;
	float MaxHarvestHealth;
	float CurrentHarvestHealth;
	__int8 bIsUnharvestable : 1;
	__int8 bIsVisibleAndActive : 1;
};

struct UVictoryCore
{
	// Functions

	static bool OverlappingActors(UWorld* theWorld, TArray<FOverlapResult>* Overlaps, FVector Origin, float Radius, int CollisionGroups, AActor* InIgnoreActor, FName TraceName, bool bComplexOverlapTest) { static NativeFunction f{ "UVictoryCore.OverlappingActors" }; return NativeCall<bool, UWorld*, TArray<FOverlapResult>*, FVector, float, int, AActor*, FName, bool>(nullptr, f, theWorld, Overlaps, Origin, Radius, CollisionGroups, InIgnoreActor, TraceName, bComplexOverlapTest); }
	static FRotator* RLerp(FRotator* result, FRotator A, FRotator B, float Alpha, bool bShortestPath) { static NativeFunction f{ "UVictoryCore.RLerp" }; return NativeCall<FRotator*, FRotator*, FRotator, FRotator, float, bool>(nullptr, f, result, A, B, Alpha, bShortestPath); }
	static FVector2D* ProjectWorldToScreenPosition(FVector2D* result, FVector* WorldLocation, APlayerController* ThePC) { static NativeFunction f{ "UVictoryCore.ProjectWorldToScreenPosition" }; return NativeCall<FVector2D*, FVector2D*, FVector*, APlayerController*>(nullptr, f, result, WorldLocation, ThePC); }
	static FString* FormatSecondsAsHoursMinutesSeconds(FString* result, unsigned int Seconds) { static NativeFunction f{ "UVictoryCore.FormatSecondsAsHoursMinutesSeconds" }; return NativeCall<FString*, FString*, unsigned int>(nullptr, f, result, Seconds); }
	static bool OverlappingActorsTrace(UWorld* theWorld, TArray<FOverlapResult>* Overlaps, FVector Origin, float Radius, ECollisionChannel TraceChannel, AActor* InIgnoreActor, FName TraceName, bool bComplexOverlapTest) { static NativeFunction f{ "UVictoryCore.OverlappingActorsTrace" }; return NativeCall<bool, UWorld*, TArray<FOverlapResult>*, FVector, float, ECollisionChannel, AActor*, FName, bool>(nullptr, f, theWorld, Overlaps, Origin, Radius, TraceChannel, InIgnoreActor, TraceName, bComplexOverlapTest); }
	static int GetWeightedRandomIndex(TArray<float>* pArray, float ForceRand) { static NativeFunction f{ "UVictoryCore.GetWeightedRandomIndex" }; return NativeCall<int, TArray<float>*, float>(nullptr, f, pArray, ForceRand); }
	static FVector2D* ProjectWorldToScreenPositionRaw(FVector2D* result, FVector* WorldLocation, APlayerController* ThePC) { static NativeFunction f{ "UVictoryCore.ProjectWorldToScreenPositionRaw(const FVector&,APlayerController*)" }; return NativeCall<FVector2D*, FVector2D*, FVector*, APlayerController*>(nullptr, f, result, WorldLocation, ThePC); }
	static FName* GetObjectPath(FName* result, UObject* Obj) { static NativeFunction f{ "UVictoryCore.GetObjectPath" }; return NativeCall<FName*, FName*, UObject*>(nullptr, f, result, Obj); }
	static UPhysicalMaterial* TracePhysMaterial(UWorld* theWorld, FVector StartPos, FVector EndPos, AActor* IgnoreActor) { static NativeFunction f{ "UVictoryCore.TracePhysMaterial" }; return NativeCall<UPhysicalMaterial*, UWorld*, FVector, FVector, AActor*>(nullptr, f, theWorld, StartPos, EndPos, IgnoreActor); }
	static FString* GetKeyNameFromActionName(FString* result, FName ActionName) { static NativeFunction f{ "UVictoryCore.GetKeyNameFromActionName" }; return NativeCall<FString*, FString*, FName>(nullptr, f, result, ActionName); }
	static float ClampRotAxis(float BaseAxis, float DesiredAxis, float MaxDiff) { static NativeFunction f{ "UVictoryCore.ClampRotAxis" }; return NativeCall<float, float, float, float>(nullptr, f, BaseAxis, DesiredAxis, MaxDiff); }
	static FVector* ClampLocation(FVector* result, FVector BaseLocation, FVector DesiredLocation, float MaxDiff, bool bTraceClampLocation, UWorld* TraceWorld, FVector* TraceFromLocation) { static NativeFunction f{ "UVictoryCore.ClampLocation" }; return NativeCall<FVector*, FVector*, FVector, FVector, float, bool, UWorld*, FVector*>(nullptr, f, result, BaseLocation, DesiredLocation, MaxDiff, bTraceClampLocation, TraceWorld, TraceFromLocation); }
	static int BPGetWeightedRandomIndex(TArray<float>* pArray, float ForceRand) { static NativeFunction f{ "UVictoryCore.BPGetWeightedRandomIndex" }; return NativeCall<int, TArray<float>*, float>(nullptr, f, pArray, ForceRand); }
	static bool ComponentBoundsEncompassesPoint(UPrimitiveComponent* Comp, FVector* Point, float BoundsMultiplier) { static NativeFunction f{ "UVictoryCore.ComponentBoundsEncompassesPoint" }; return NativeCall<bool, UPrimitiveComponent*, FVector*, float>(nullptr, f, Comp, Point, BoundsMultiplier); }
	static bool SphereOverlapFast(UObject* WorldContextObject, FVector* Loc, const float Radius) { static NativeFunction f{ "UVictoryCore.SphereOverlapFast" }; return NativeCall<bool, UObject*, FVector*, const float>(nullptr, f, WorldContextObject, Loc, Radius); }
	static bool CapsuleOverlapFast(UObject* WorldContextObject, AActor** OutFirstOverlappedActor, FVector* Origin, FRotator* CapsuleRotation, float Radius, float HalfHeight, TEnumAsByte<enum ECollisionChannel> CollisionChannel, bool bTraceComplex, bool bIgnoreSelf, AActor* IgnoreActor, bool bDebugDraw, float DebugDrawDuration, bool bBlockingOnly) { static NativeFunction f{ "UVictoryCore.CapsuleOverlapFast" }; return NativeCall<bool, UObject*, AActor**, FVector*, FRotator*, float, float, TEnumAsByte<enum ECollisionChannel>, bool, bool, AActor*, bool, float, bool>(nullptr, f, WorldContextObject, OutFirstOverlappedActor, Origin, CapsuleRotation, Radius, HalfHeight, CollisionChannel, bTraceComplex, bIgnoreSelf, IgnoreActor, bDebugDraw, DebugDrawDuration, bBlockingOnly); }
	static bool CapsuleSweepFast(UObject* WorldContextObject, FHitResult* OutHit, FVector* Start, FVector* End, FRotator* CapsuleRot, float Radius, float HalfHeight, TEnumAsByte<enum ECollisionChannel> CollisionChannel, bool bTraceComplex, bool bIgnoreSelf, TArray<AActor*>* IgnoreActors, bool bDebugDraw, float DebugDrawDuration) { static NativeFunction f{ "UVictoryCore.CapsuleSweepFast(UObject*,FHitResult&,const FVector&,const FVector&,const FRotator&,float,float,TEnumAsByte<enum ECollisionChannel>,bool,bool,const TArray<AActor*,FDefaultAllocator>&,bool,float)" }; return NativeCall<bool, UObject*, FHitResult*, FVector*, FVector*, FRotator*, float, float, TEnumAsByte<enum ECollisionChannel>, bool, bool, TArray<AActor*>*, bool, float>(nullptr, f, WorldContextObject, OutHit, Start, End, CapsuleRot, Radius, HalfHeight, CollisionChannel, bTraceComplex, bIgnoreSelf, IgnoreActors, bDebugDraw, DebugDrawDuration); }
	static bool CapsuleSweepFast(UObject* WorldContextObject, FHitResult* OutHit, FVector* Start, FVector* End, FRotator* CapsuleRot, float Radius, float HalfHeight, TEnumAsByte<enum ECollisionChannel> CollisionChannel, bool bTraceComplex, bool bIgnoreSelf, AActor* IgnoreActor, bool bDebugDraw, float DebugDrawDuration) { static NativeFunction f{ "UVictoryCore.CapsuleSweepFast(UObject*,FHitResult&,const FVector&,const FVector&,const FRotator&,float,float,TEnumAsByte<enum ECollisionChannel>,bool,bool,AActor*,bool,float)" }; return NativeCall<bool, UObject*, FHitResult*, FVector*, FVector*, FRotator*, float, float, TEnumAsByte<enum ECollisionChannel>, bool, bool, AActor*, bool, float>(nullptr, f, WorldContextObject, OutHit, Start, End, CapsuleRot, Radius, HalfHeight, CollisionChannel, bTraceComplex, bIgnoreSelf, IgnoreActor, bDebugDraw, DebugDrawDuration); }
	static bool CapsuleSweepMulti(UObject* WorldContextObject, TArray<FHitResult>* OutHits, FVector* Start, FVector* End, FRotator* CapsuleRot, float Radius, float HalfHeight, TArray<AActor*>* IgnoreActors, bool bIgnoreSelf, TEnumAsByte<enum ECollisionChannel> CollisionChannel, bool bTraceComplex, bool bDebugDraw, float DebugDrawDuration, bool bFindInitialOverlaps) { static NativeFunction f{ "UVictoryCore.CapsuleSweepMulti" }; return NativeCall<bool, UObject*, TArray<FHitResult>*, FVector*, FVector*, FRotator*, float, float, TArray<AActor*>*, bool, TEnumAsByte<enum ECollisionChannel>, bool, bool, float, bool>(nullptr, f, WorldContextObject, OutHits, Start, End, CapsuleRot, Radius, HalfHeight, IgnoreActors, bIgnoreSelf, CollisionChannel, bTraceComplex, bDebugDraw, DebugDrawDuration, bFindInitialOverlaps); }
	static void MultiTraceProjectSphere(UObject* WorldContextObject, TArray<FHitResult>* OutResults, FVector* Origin, ECollisionChannel TraceChannel, int HorizResolution, int VertResolution, float StartDistance, float EndDistance, float NorthConeSubtractAngle, float SouthConeSubtractAngle, int PctChanceToTrace, int MaxTraceCount, bool bDrawDebugLines, float DebugDrawDuration, bool bTraceComplex = false) { static NativeFunction f{ "UVictoryCore.MultiTraceProjectSphere" }; NativeCall<void, UObject*, TArray<FHitResult>*, FVector*, ECollisionChannel, int, int, float, float, float, float, int, int, bool, float, bool>(nullptr, f, WorldContextObject, OutResults, Origin, TraceChannel, HorizResolution, VertResolution, StartDistance, EndDistance, NorthConeSubtractAngle, SouthConeSubtractAngle, PctChanceToTrace, MaxTraceCount, bDrawDebugLines, DebugDrawDuration, bTraceComplex); }
	//static float GetProjectileArcPeakTime(UObject* WorldContextObject, FProjectileArc* Arc) { return NativeCall<float, UObject*, FProjectileArc*>(nullptr, "UVictoryCore.GetProjectileArcPeakTime", WorldContextObject, Arc); }
	//static FVector* EvalProjectileArc(FVector* result, UObject* WorldContextObject, FProjectileArc* Arc, float Time) { return NativeCall<FVector*, FVector*, UObject*, FProjectileArc*, float>(nullptr, "UVictoryCore.EvalProjectileArc", result, WorldContextObject, Arc, Time); }
	//static void DebugDrawProjectileArc(UObject* WorldContextObject, FProjectileArc* Arc, float MaxArcTime, float ArcTimeStep, FLinearColor LineColor, float LineThickness, float DebugDrawDuration) { NativeCall<void, UObject*, FProjectileArc*, float, float, FLinearColor, float, float>(nullptr, "UVictoryCore.DebugDrawProjectileArc", WorldContextObject, Arc, MaxArcTime, ArcTimeStep, LineColor, LineThickness, DebugDrawDuration); }
	//static bool TraceProjectileArc(UObject* WorldContextObject, FProjectileArc* Arc, FHitResult* OutHitResult, FVector* OutEndLocation, float* OutEndArcTime, FVector* OutArcPeakLocation, float MaxArcLength, TArray<AActor*>* ActorsToIgnore, float ArcTimeStep, ECollisionChannel CollisionChannel, bool bTraceObjectTypeOnly, bool bDrawDebug, float DebugDrawDuration) { return NativeCall<bool, UObject*, FProjectileArc*, FHitResult*, FVector*, float*, FVector*, float, TArray<AActor*>*, float, ECollisionChannel, bool, bool, float>(nullptr, "UVictoryCore.TraceProjectileArc", WorldContextObject, Arc, OutHitResult, OutEndLocation, OutEndArcTime, OutArcPeakLocation, MaxArcLength, ActorsToIgnore, ArcTimeStep, CollisionChannel, bTraceObjectTypeOnly, bDrawDebug, DebugDrawDuration); }
	//static bool CapsuleSweepProjectileArc(UObject* WorldContextObject, FProjectileArc* Arc, FRotator* CapsuleRotation, float CapsuleRadius, float CapsuleHalfHeight, bool bRotateCapsuleAlongPath, bool bTraceComplex, FHitResult* OutHitResult, FVector* OutEndLocation, float* OutEndArcTime, float MaxArcLength, TArray<AActor*>* ActorsToIgnore, bool bIgnoreSelf, float ArcTimeStep, TEnumAsByte<enum ECollisionChannel> CollisionChannel, bool bDrawDebug, float DebugDrawDuration) { return NativeCall<bool, UObject*, FProjectileArc*, FRotator*, float, float, bool, bool, FHitResult*, FVector*, float*, float, TArray<AActor*>*, bool, float, TEnumAsByte<enum ECollisionChannel>, bool, float>(nullptr, "UVictoryCore.CapsuleSweepProjectileArc", WorldContextObject, Arc, CapsuleRotation, CapsuleRadius, CapsuleHalfHeight, bRotateCapsuleAlongPath, bTraceComplex, OutHitResult, OutEndLocation, OutEndArcTime, MaxArcLength, ActorsToIgnore, bIgnoreSelf, ArcTimeStep, CollisionChannel, bDrawDebug, DebugDrawDuration); }
	static void MultiLinePenetrationTraceByChannel(UObject* WorldContextObject, TArray<FPenetrationTraceHit>* OutResults, FVector* Start, FVector* End, ECollisionChannel TraceChannel, TArray<AActor*>* ActorsToIgnore, bool bTraceComplex, bool bIgnoreSelf, bool bDrawDebugLines, float DebugDrawDuration) { static NativeFunction f{ "UVictoryCore.MultiLinePenetrationTraceByChannel" }; NativeCall<void, UObject*, TArray<FPenetrationTraceHit>*, FVector*, FVector*, ECollisionChannel, TArray<AActor*>*, bool, bool, bool, float>(nullptr, f, WorldContextObject, OutResults, Start, End, TraceChannel, ActorsToIgnore, bTraceComplex, bIgnoreSelf, bDrawDebugLines, DebugDrawDuration); }
	static bool FindValidLocationNextToTarget(UObject* WorldContextObject, FVector* OutLocation, APrimalCharacter* SourceCharacter, APrimalCharacter* TargetCharacter, float DistanceMargin, int MaxTraceCount, AActor* ActorToIgnore, bool bTraceComplex, bool bDrawDebug, float DebugDrawDuration) { static NativeFunction f{ "UVictoryCore.FindValidLocationNextToTarget" }; return NativeCall<bool, UObject*, FVector*, APrimalCharacter*, APrimalCharacter*, float, int, AActor*, bool, bool, float>(nullptr, f, WorldContextObject, OutLocation, SourceCharacter, TargetCharacter, DistanceMargin, MaxTraceCount, ActorToIgnore, bTraceComplex, bDrawDebug, DebugDrawDuration); }
	static FRotator* BPRotatorLerp(FRotator* result, FRotator* A, FRotator* B, const float* Alpha) { static NativeFunction f{ "UVictoryCore.BPRotatorLerp" }; return NativeCall<FRotator*, FRotator*, FRotator*, FRotator*, const float*>(nullptr, f, result, A, B, Alpha); }
	//static float SimpleCurveEval(float Value, TEnumAsByte<enum ESimpleCurve::Type> CurveType) { return NativeCall<float, float, TEnumAsByte<enum ESimpleCurve::Type>>(nullptr, "UVictoryCore.SimpleCurveEval", Value, CurveType); }
	//static FRotator* SimpleCurveInterpClampedRotator(FRotator* result, FRotator A, FRotator B, float Alpha, bool bShortestPath, TEnumAsByte<enum ESimpleCurve::Type> CurveType) { return NativeCall<FRotator*, FRotator*, FRotator, FRotator, float, bool, TEnumAsByte<enum ESimpleCurve::Type>>(nullptr, "UVictoryCore.SimpleCurveInterpClampedRotator", result, A, B, Alpha, bShortestPath, CurveType); }
	//static FTransform* SimpleCurveInterpClampedTransform(FTransform* result, FTransform A, FTransform B, float Alpha, TEnumAsByte<enum ESimpleCurve::Type> CurveType) { return NativeCall<FTransform*, FTransform*, FTransform, FTransform, float, TEnumAsByte<enum ESimpleCurve::Type>>(nullptr, "UVictoryCore.SimpleCurveInterpClampedTransform", result, A, B, Alpha, CurveType); }
	//static float MapRangeToCurveClamped(float Value, float InRangeA, float InRangeB, float OutRangeA, float OutRangeB, TEnumAsByte<enum ESimpleCurve::Type> CurveType) { return NativeCall<float, float, float, float, float, float, TEnumAsByte<enum ESimpleCurve::Type>>(nullptr, "UVictoryCore.MapRangeToCurveClamped", Value, InRangeA, InRangeB, OutRangeA, OutRangeB, CurveType); }
	//static float MapAngleRangeToCurveClamped(float AngleDegrees, float InRangeA, float InRangeB, float OutRangeA, float OutRangeB, TEnumAsByte<enum ESimpleCurve::Type> CurveType) { return NativeCall<float, float, float, float, float, float, TEnumAsByte<enum ESimpleCurve::Type>>(nullptr, "UVictoryCore.MapAngleRangeToCurveClamped", AngleDegrees, InRangeA, InRangeB, OutRangeA, OutRangeB, CurveType); }
	static FVector* ViewDirectionAngleOffset(FVector* result, FVector ViewDirection, FVector RightVector, float AngleOffsetDegrees, float MaxAngleDegreesBeforeInterpToUp) { static NativeFunction f{ "UVictoryCore.ViewDirectionAngleOffset" }; return NativeCall<FVector*, FVector*, FVector, FVector, float, float>(nullptr, f, result, ViewDirection, RightVector, AngleOffsetDegrees, MaxAngleDegreesBeforeInterpToUp); }
	static FVector* FlattenDirectionVector(FVector* result, FVector Direction) { static NativeFunction f{ "UVictoryCore.FlattenDirectionVector" }; return NativeCall<FVector*, FVector*, FVector>(nullptr, f, result, Direction); }
	static FVector* FlattenDirectionVectorInLocalSpace(FVector* result, FVector Direction, FRotator Rotation) { static NativeFunction f{ "UVictoryCore.FlattenDirectionVectorInLocalSpace" }; return NativeCall<FVector*, FVector*, FVector, FRotator>(nullptr, f, result, Direction, Rotation); }
	static bool BPFastTrace(UWorld* theWorld, FVector TraceEnd, FVector TraceStart, AActor* ActorToIgnore, float DebugDrawDuration) { static NativeFunction f{ "UVictoryCore.BPFastTrace" }; return NativeCall<bool, UWorld*, FVector, FVector, AActor*, float>(nullptr, f, theWorld, TraceEnd, TraceStart, ActorToIgnore, DebugDrawDuration); }
	static bool VTraceIgnoreFoliage(UWorld* theWorld, FVector* Start, FVector* End, FHitResult* HitOut, AActor* ActorToIgnore, ECollisionChannel Channel, int CollisionGroups, bool bReturnPhysMaterial, bool bTraceComplex, FVector* BoxExtent, FName TraceTag, AActor* OtherActorToIgnore, TArray<AActor*>* OtherActorsToIgnore, FQuat* Rot, AActor* AnotherActorToIgnore, bool bIgnoreFoliage) { static NativeFunction f{ "UVictoryCore.VTraceIgnoreFoliage" }; return NativeCall<bool, UWorld*, FVector*, FVector*, FHitResult*, AActor*, ECollisionChannel, int, bool, bool, FVector*, FName, AActor*, TArray<AActor*>*, FQuat*, AActor*, bool>(nullptr, f, theWorld, Start, End, HitOut, ActorToIgnore, Channel, CollisionGroups, bReturnPhysMaterial, bTraceComplex, BoxExtent, TraceTag, OtherActorToIgnore, OtherActorsToIgnore, Rot, AnotherActorToIgnore, bIgnoreFoliage); }
	static void SteamOverlayOpenURL(FString* ToURL) { static NativeFunction f{ "UVictoryCore.SteamOverlayOpenURL" }; NativeCall<void, FString*>(nullptr, f, ToURL); }
	static void SetSessionPrefix(FString* InPrefix) { static NativeFunction f{ "UVictoryCore.SetSessionPrefix" }; NativeCall<void, FString*>(nullptr, f, InPrefix); }
	static FColor* GetTeamColor(FColor* result, const int TargetingTeam) { static NativeFunction f{ "UVictoryCore.GetTeamColor" }; return NativeCall<FColor*, FColor*, const int>(nullptr, f, result, TargetingTeam); }
	static FString* BPFormatAsTime(FString* result, int InTime, bool UseLeadingZero, bool bForceLeadingZeroHour, bool bShowSeconds) { static NativeFunction f{ "UVictoryCore.BPFormatAsTime" }; return NativeCall<FString*, FString*, int, bool, bool, bool>(nullptr, f, result, InTime, UseLeadingZero, bForceLeadingZeroHour, bShowSeconds); }
	static FString* FormatAsTime(FString* result, int InTime, bool UseLeadingZero, bool bForceLeadingZeroHour, bool bShowSeconds) { static NativeFunction f{ "UVictoryCore.FormatAsTime" }; return NativeCall<FString*, FString*, int, bool, bool, bool>(nullptr, f, result, InTime, UseLeadingZero, bForceLeadingZeroHour, bShowSeconds); }
	static FString* BPFormatAsTimeLong(FString* result, int InTime) { static NativeFunction f{ "UVictoryCore.BPFormatAsTimeLong" }; return NativeCall<FString*, FString*, int>(nullptr, f, result, InTime); }
	static FString* FormatAsTimeLong(FString* result, int InTime) { static NativeFunction f{ "UVictoryCore.FormatAsTimeLong" }; return NativeCall<FString*, FString*, int>(nullptr, f, result, InTime); }
	static bool CalculateInterceptPosition(FVector* StartPosition, FVector* StartVelocity, float ProjectileVelocity, FVector* TargetPosition, FVector* TargetVelocity, FVector* InterceptPosition) { static NativeFunction f{ "UVictoryCore.CalculateInterceptPosition" }; return NativeCall<bool, FVector*, FVector*, float, FVector*, FVector*, FVector*>(nullptr, f, StartPosition, StartVelocity, ProjectileVelocity, TargetPosition, TargetVelocity, InterceptPosition); }
	static int GetSecondsIntoDay() { static NativeFunction f{ "UVictoryCore.GetSecondsIntoDay" }; return NativeCall<int>(nullptr, f); }
	static FString* ConsumeBonusItemCode(FString* result) { static NativeFunction f{ "UVictoryCore.ConsumeBonusItemCode" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static bool StaticCheckForCommand(FString CommandName) { static NativeFunction f{ "UVictoryCore.StaticCheckForCommand" }; return NativeCall<bool, FString>(nullptr, f, CommandName); }
	static bool GetGroundLocation(UWorld* forWorld, FVector* theGroundLoc, FVector* StartLoc, FVector* OffsetUp, FVector* OffsetDown) { static NativeFunction f{ "UVictoryCore.GetGroundLocation" }; return NativeCall<bool, UWorld*, FVector*, FVector*, FVector*, FVector*>(nullptr, f, forWorld, theGroundLoc, StartLoc, OffsetUp, OffsetDown); }
	static void CallGlobalLevelEvent(UWorld* forWorld, FName EventName) { static NativeFunction f{ "UVictoryCore.CallGlobalLevelEvent" }; NativeCall<void, UWorld*, FName>(nullptr, f, forWorld, EventName); }
	static FVector2D* BPProjectWorldToScreenPosition(FVector2D* result, FVector* WorldLocation, APlayerController* ThePC) { static NativeFunction f{ "UVictoryCore.BPProjectWorldToScreenPosition" }; return NativeCall<FVector2D*, FVector2D*, FVector*, APlayerController*>(nullptr, f, result, WorldLocation, ThePC); }
	static TArray<AActor*>* ServerOctreeOverlapActors(TArray<AActor*>* result, UWorld* theWorld, FVector AtLoc, float Radius, EServerOctreeGroup::Type OctreeType, bool bForceActorLocationDistanceCheck) { static NativeFunction f{ "UVictoryCore.ServerOctreeOverlapActors" }; return NativeCall<TArray<AActor*>*, TArray<AActor*>*, UWorld*, FVector, float, EServerOctreeGroup::Type, bool>(nullptr, f, result, theWorld, AtLoc, Radius, OctreeType, bForceActorLocationDistanceCheck); }
	static TArray<AActor*>* ServerOctreeOverlapActorsBitMask(TArray<AActor*>* result, UWorld* theWorld, FVector AtLoc, float Radius, int OctreeTypeBitMask, bool bForceActorLocationDistanceCheck) { static NativeFunction f{ "UVictoryCore.ServerOctreeOverlapActorsBitMask" }; return NativeCall<TArray<AActor*>*, TArray<AActor*>*, UWorld*, FVector, float, int, bool>(nullptr, f, result, theWorld, AtLoc, Radius, OctreeTypeBitMask, bForceActorLocationDistanceCheck); }
	static TArray<AActor*>* ServerOctreeOverlapActorsClass(TArray<AActor*>* result, UWorld* theWorld, FVector AtLoc, float Radius, EServerOctreeGroup::Type OctreeType, TSubclassOf<AActor> ActorClass, bool bForceActorLocationDistanceCheck) { static NativeFunction f{ "UVictoryCore.ServerOctreeOverlapActorsClass" }; return NativeCall<TArray<AActor*>*, TArray<AActor*>*, UWorld*, FVector, float, EServerOctreeGroup::Type, TSubclassOf<AActor>, bool>(nullptr, f, result, theWorld, AtLoc, Radius, OctreeType, ActorClass, bForceActorLocationDistanceCheck); }
	static TArray<AActor*>* ServerOctreeOverlapActorsClassBitMask(TArray<AActor*>* result, UWorld* theWorld, FVector AtLoc, float Radius, int OctreeTypeBitMask, TSubclassOf<AActor> ActorClass, bool bForceActorLocationDistanceCheck) { static NativeFunction f{ "UVictoryCore.ServerOctreeOverlapActorsClassBitMask" }; return NativeCall<TArray<AActor*>*, TArray<AActor*>*, UWorld*, FVector, float, int, TSubclassOf<AActor>, bool>(nullptr, f, result, theWorld, AtLoc, Radius, OctreeTypeBitMask, ActorClass, bForceActorLocationDistanceCheck); }
	static FRotator* BPRTransform(FRotator* result, FRotator* R, FRotator* RBasis) { static NativeFunction f{ "UVictoryCore.BPRTransform" }; return NativeCall<FRotator*, FRotator*, FRotator*, FRotator*>(nullptr, f, result, R, RBasis); }
	static FRotator* BPRTransformInverse(FRotator* result, FRotator* R, FRotator* RBasis) { static NativeFunction f{ "UVictoryCore.BPRTransformInverse" }; return NativeCall<FRotator*, FRotator*, FRotator*, FRotator*>(nullptr, f, result, R, RBasis); }
	static TArray<AActor*>* SortActorsByTag(TArray<AActor*>* result, int tagIndex, TArray<AActor*>* actors) { static NativeFunction f{ "UVictoryCore.SortActorsByTag" }; return NativeCall<TArray<AActor*>*, TArray<AActor*>*, int, TArray<AActor*>*>(nullptr, f, result, tagIndex, actors); }
	static TArray<int>* GetArrayIndicesSorted_Float(TArray<int>* result, TArray<float>* Array, bool bSortLowToHigh) { static NativeFunction f{ "UVictoryCore.GetArrayIndicesSorted_Float" }; return NativeCall<TArray<int>*, TArray<int>*, TArray<float>*, bool>(nullptr, f, result, Array, bSortLowToHigh); }
	static TArray<int>* GetArrayIndicesSorted_Double(TArray<int>* result, TArray<double>* Array, bool bSortLowToHigh) { static NativeFunction f{ "UVictoryCore.GetArrayIndicesSorted_Double" }; return NativeCall<TArray<int>*, TArray<int>*, TArray<double>*, bool>(nullptr, f, result, Array, bSortLowToHigh); }
	static TArray<int>* GetArrayIndicesSorted_Int(TArray<int>* result, TArray<int>* Array, bool bSortLowToHigh) { static NativeFunction f{ "UVictoryCore.GetArrayIndicesSorted_Int" }; return NativeCall<TArray<int>*, TArray<int>*, TArray<int>*, bool>(nullptr, f, result, Array, bSortLowToHigh); }
	static bool FindWorldActors(UWorld* fWorld, TArray<AActor*>* fContainer, TSubclassOf<AActor> fType, FName fTag) { static NativeFunction f{ "UVictoryCore.FindWorldActors" }; return NativeCall<bool, UWorld*, TArray<AActor*>*, TSubclassOf<AActor>, FName>(nullptr, f, fWorld, fContainer, fType, fTag); }
	static TArray<TWeakObjectPtr<APrimalDinoCharacter>>* RemoveInvalidObjectsInContainer(TArray<TWeakObjectPtr<APrimalDinoCharacter>>* result, TArray<TWeakObjectPtr<APrimalDinoCharacter>> fContainer) { static NativeFunction f{ "UVictoryCore.RemoveInvalidObjectsInContainer" }; return NativeCall<TArray<TWeakObjectPtr<APrimalDinoCharacter>>*, TArray<TWeakObjectPtr<APrimalDinoCharacter>>*, TArray<TWeakObjectPtr<APrimalDinoCharacter>>>(nullptr, f, result, fContainer); }
	static void FinishSpawning(AActor* Actor) { static NativeFunction f{ "UVictoryCore.FinishSpawning" }; NativeCall<void, AActor*>(nullptr, f, Actor); }
	static bool KillTargetCharacterOrStructure(AActor* ActorToKill, AActor* DamageCauser, bool bTryDestroyActor) { static NativeFunction f{ "UVictoryCore.KillTargetCharacterOrStructure" }; return NativeCall<bool, AActor*, AActor*, bool>(nullptr, f, ActorToKill, DamageCauser, bTryDestroyActor); }
	template <typename B, std::enable_if_t<std::is_same_v<B, bool>, int> = 0>
	[[deprecated("use KillTargetCharacterOrStructure(ActorToKill, DamageCauser, bTryDestroyActor)")]] static bool KillTargetCharacterOrStructure(AActor* ActorToKill, B bTryDestroyActor) { ReportDeprecatedApiUse("UVictoryCore.KillTargetCharacterOrStructure(ActorToKill, bTryDestroyActor)"); return KillTargetCharacterOrStructure(ActorToKill, nullptr, bTryDestroyActor); }
	static int GetWeightedRandomIndexFromArray(TArray<float> pArray, float ForceRand) { static NativeFunction f{ "UVictoryCore.GetWeightedRandomIndexFromArray" }; return NativeCall<int, TArray<float>, float>(nullptr, f, pArray, ForceRand); }
	static AActor* GetClosestActorArray(FVector ToPoint, TArray<AActor*>* ActorArray) { static NativeFunction f{ "UVictoryCore.GetClosestActorArray" }; return NativeCall<AActor*, FVector, TArray<AActor*>*>(nullptr, f, ToPoint, ActorArray); }
	static ACustomActorList* GetCustomActorList(UWorld* ForWorld, FName SearchCustomTag) { static NativeFunction f{ "UVictoryCore.GetCustomActorList" }; return NativeCall<ACustomActorList*, UWorld*, FName>(nullptr, f, ForWorld, SearchCustomTag); }
	static long double GetNetworkTimeInSeconds(UObject* WorldContextObject) { static NativeFunction f{ "UVictoryCore.GetNetworkTimeInSeconds" }; return NativeCall<long double, UObject*>(nullptr, f, WorldContextObject); }
	static long double GetRealWorldUtcTimeInSeconds() { static NativeFunction f{ "UVictoryCore.GetRealWorldUtcTimeInSeconds" }; return NativeCall<long double>(nullptr, f); }
	static AShooterCharacter* GetShooterCharacterFromPawn(APawn* Pawn) { static NativeFunction f{ "UVictoryCore.GetShooterCharacterFromPawn" }; return NativeCall<AShooterCharacter*, APawn*>(nullptr, f, Pawn); }
	static bool VTraceSingleBP(UWorld* theWorld, FHitResult* OutHit, FVector* Start, FVector* End, ECollisionChannel TraceChannel, int CollisionGroups, FName TraceTag, bool bTraceComplex, AActor* ActorToIgnore, float DebugDrawDuration = 0.f) { static NativeFunction f{ "UVictoryCore.VTraceSingleBP" }; return NativeCall<bool, UWorld*, FHitResult*, FVector*, FVector*, ECollisionChannel, int, FName, bool, AActor*, float>(nullptr, f, theWorld, OutHit, Start, End, TraceChannel, CollisionGroups, TraceTag, bTraceComplex, ActorToIgnore, DebugDrawDuration); }
	static bool VTraceSingleBP_IgnoreActorsArray(UWorld* theWorld, FHitResult* OutHit, FVector* Start, FVector* End, TArray<AActor*, FDefaultAllocator>* ExtraIgnoreActors, AActor* InIgnoreActor, ECollisionChannel TraceChannel, int CollisionGroups, FName TraceTag, bool bReturnPhysMaterial, bool bTraceComplex, float DebugDrawDuration) { static NativeFunction f{ "UVictoryCore.VTraceSingleBP_IgnoreActorsArray" }; return NativeCall<bool, UWorld*, FHitResult*, FVector*, FVector*, TArray<AActor*>*, AActor*, ECollisionChannel, int, FName, bool, bool, float>(nullptr, f, theWorld, OutHit, Start, End, ExtraIgnoreActors, InIgnoreActor, TraceChannel, CollisionGroups, TraceTag, bReturnPhysMaterial, bTraceComplex, DebugDrawDuration); }
	static bool VTraceSphereBP(UWorld* theWorld, FVector* Start, FVector* End, FHitResult* HitOut, float Radius, AActor* ActorToIgnore, ECollisionChannel Channel, int CollisionGroups, bool bReturnPhysMaterial, bool bTraceComplex, FName TraceTag, AActor* OtherActorToIgnore, AActor* AnotherActorToIgnore, float DebugDrawDuration = 0.f) { static NativeFunction f{ "UVictoryCore.VTraceSphereBP" }; return NativeCall<bool, UWorld*, FVector*, FVector*, FHitResult*, float, AActor*, ECollisionChannel, int, bool, bool, FName, AActor*, AActor*, float>(nullptr, f, theWorld, Start, End, HitOut, Radius, ActorToIgnore, Channel, CollisionGroups, bReturnPhysMaterial, bTraceComplex, TraceTag, OtherActorToIgnore, AnotherActorToIgnore, DebugDrawDuration); }
	static bool VTraceMulti(UWorld* theWorld, TArray<FHitResult>* OutHits, FVector* Start, FVector* End, AActor* InIgnoreActor, int CollisionGroups, float SphereRadius, FVector* BoxExtent, bool bReturnPhysMaterial, ECollisionChannel TraceChannel, bool bTraceComplex, FName TraceTag, bool bTraceChannelForceOverlap, bool bDoSort, AActor* AdditionalIgnoreActor, AActor* AnotherIgnoreActor, bool bJustDoSphereOverlapAtStartLoc, TArray<AActor*>* ExtraIgnoreActors) { static NativeFunction f{ "UVictoryCore.VTraceMulti" }; return NativeCall<bool, UWorld*, TArray<FHitResult>*, FVector*, FVector*, AActor*, int, float, FVector*, bool, ECollisionChannel, bool, FName, bool, bool, AActor*, AActor*, bool, TArray<AActor*>*>(nullptr, f, theWorld, OutHits, Start, End, InIgnoreActor, CollisionGroups, SphereRadius, BoxExtent, bReturnPhysMaterial, TraceChannel, bTraceComplex, TraceTag, bTraceChannelForceOverlap, bDoSort, AdditionalIgnoreActor, AnotherIgnoreActor, bJustDoSphereOverlapAtStartLoc, ExtraIgnoreActors); }
	static FString* GetKeyName(FString* result, FKey* key) { static NativeFunction f{ "UVictoryCore.GetKeyName" }; return NativeCall<FString*, FString*, FKey*>(nullptr, f, result, key); }
	[[deprecated("pass a pointer")]] static FString* GetKeyName(FString* result, FKey& key) { ReportDeprecatedApiUse("UVictoryCore.GetKeyName(by value)"); return GetKeyName(result, &key); }
	static bool IsGamePadConnected() { static NativeFunction f{ "UVictoryCore.IsGamePadConnected" }; return NativeCall<bool>(nullptr, f); }
	static int IsChildOfClasses(TSubclassOf<UObject> childClass, TArray<TSubclassOf<UObject>>* ParentClassesArray) { static NativeFunction f{ "UVictoryCore.IsChildOfClasses" }; return NativeCall<int, TSubclassOf<UObject>, TArray<TSubclassOf<UObject>>*>(nullptr, f, childClass, ParentClassesArray); }
	static bool IsPVEServer(UObject* WorldContextObject) { static NativeFunction f{ "UVictoryCore.IsPVEServer" }; return NativeCall<bool, UObject*>(nullptr, f, WorldContextObject); }
	static bool IsCooldownComplete(UObject* WorldContextObject, long double CooldownClock, float NumSeconds) { static NativeFunction f{ "UVictoryCore.IsCooldownComplete" }; return NativeCall<bool, UObject*, long double, float>(nullptr, f, WorldContextObject, CooldownClock, NumSeconds); }
	static float CooldownTimeRemaining(UObject* WorldContextObject, long double CooldownClock, float CooldownDuration) { static NativeFunction f{ "UVictoryCore.CooldownTimeRemaining" }; return NativeCall<float, UObject*, long double, float>(nullptr, f, WorldContextObject, CooldownClock, CooldownDuration); }
	static void PauseTimer(UObject* Object, FString FunctionName) { static NativeFunction f{ "UVictoryCore.PauseTimer" }; NativeCall<void, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static void UnPauseTimer(UObject* Object, FString FunctionName) { static NativeFunction f{ "UVictoryCore.UnPauseTimer" }; NativeCall<void, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static bool IsTimerActive(UObject* Object, FString FunctionName) { static NativeFunction f{ "UVictoryCore.IsTimerActive" }; return NativeCall<bool, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static bool IsTimerPaused(UObject* Object, FString FunctionName) { static NativeFunction f{ "UVictoryCore.IsTimerPaused" }; return NativeCall<bool, UObject*, FString>(nullptr, f, Object, FunctionName); }
	static FString* GetLastMapPlayed(FString* result) { static NativeFunction f{ "UVictoryCore.GetLastMapPlayed" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static FString* GetLastHostedMapPlayed(FString* result) { static NativeFunction f{ "UVictoryCore.GetLastHostedMapPlayed" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static void SetLastHostedMapPlayed(FString* NewLastHostedMapPlayed) { static NativeFunction f{ "UVictoryCore.SetLastHostedMapPlayed" }; NativeCall<void, FString*>(nullptr, f, NewLastHostedMapPlayed); }
	static bool OwnsScorchedEarth() { static NativeFunction f{ "UVictoryCore.OwnsScorchedEarth" }; return NativeCall<bool>(nullptr, f); }
	static bool OwnsAberration() { static NativeFunction f{ "UVictoryCore.OwnsAberration" }; return NativeCall<bool>(nullptr, f); }
	static bool OwnsExtinction() { static NativeFunction f{ "UVictoryCore.OwnsExtinction" }; return NativeCall<bool>(nullptr, f); }
	static bool OwnsGenesisSeasonPass() { static NativeFunction f{ "UVictoryCore.OwnsGenesisSeasonPass" }; return NativeCall<bool>(nullptr, f); }
	static bool OwnsDLC(FString DLCName) { static NativeFunction f{ "UVictoryCore.OwnsDLC" }; return NativeCall<bool, FString>(nullptr, f, DLCName); }
	static bool OwnsSteamAppID(int AppID) { static NativeFunction f{ "UVictoryCore.OwnsSteamAppID" }; return NativeCall<bool, int>(nullptr, f, AppID); }
	static void OpenStorePageForDLC(FString DLCName) { static NativeFunction f{ "UVictoryCore.OpenStorePageForDLC" }; NativeCall<void, FString>(nullptr, f, DLCName); }
	static FVector* LeadTargetPosition(FVector* result, FVector* ProjLocation, float ProjSpeed, FVector* TargetLocation, FVector* TargetVelocity) { static NativeFunction f{ "UVictoryCore.LeadTargetPosition" }; return NativeCall<FVector*, FVector*, FVector*, float, FVector*, FVector*>(nullptr, f, result, ProjLocation, ProjSpeed, TargetLocation, TargetVelocity); }
	static TArray<AActor*>* SortActorsByDistance(TArray<AActor*>* result, FVector* fromLoc, TArray<AActor*>* actors) { static NativeFunction f{ "UVictoryCore.SortActorsByDistance" }; return NativeCall<TArray<AActor*>*, TArray<AActor*>*, FVector*, TArray<AActor*>*>(nullptr, f, result, fromLoc, actors); }
	static void AddToActorList(UWorld* ForWorld, int ActorListNum, AActor* ActorRef) { static NativeFunction f{ "UVictoryCore.AddToActorList" }; NativeCall<void, UWorld*, int, AActor*>(nullptr, f, ForWorld, ActorListNum, ActorRef); }
	static FLinearColor* ChangeSaturation(FLinearColor* result, FLinearColor* InColor, float NewSaturation) { static NativeFunction f{ "UVictoryCore.ChangeSaturation" }; return NativeCall<FLinearColor*, FLinearColor*, FLinearColor*, float>(nullptr, f, result, InColor, NewSaturation); }
	static FString* SimpleFloatString(FString* result, float inputVal) { static NativeFunction f{ "UVictoryCore.SimpleFloatString" }; return NativeCall<FString*, FString*, float>(nullptr, f, result, inputVal); }
	static bool IsWorkshopIDSubscribed(FString* WorkshopID) { static NativeFunction f{ "UVictoryCore.IsWorkshopIDSubscribed" }; return NativeCall<bool, FString*>(nullptr, f, WorkshopID); }
	static FTransform* InverseTransform(FTransform* result, FTransform* TransformIn) { static NativeFunction f{ "UVictoryCore.InverseTransform" }; return NativeCall<FTransform*, FTransform*, FTransform*>(nullptr, f, result, TransformIn); }
	static UClass* BPLoadClass(FString* PathName) { static NativeFunction f{ "UVictoryCore.BPLoadClass" }; return NativeCall<UClass*, FString*>(nullptr, f, PathName); }
	static UClass* BPLoadClass(const FString& PathName) { static NativeFunction f{ "UVictoryCore.BPLoadClass" }; return NativeCall<UClass*, const FString&>(nullptr, f, PathName); } /* Manual Definition */
	static UObject* BPLoadObject(FString* PathName) { static NativeFunction f{ "UVictoryCore.BPLoadObject" }; return NativeCall<UObject*, FString*>(nullptr, f, PathName); }
	static bool VTraceAgainstActorExpensive(UWorld* theWorld, FVector* Start, FVector* End, FHitResult* HitOut, AActor* ActorToTraceAgainst, ECollisionChannel Channel, int CollisionGroups, float SphereRadius, bool bReturnPhysMaterial, bool bTraceComplex, FVector* BoxExtent, FName TraceTag, bool bSort) { static NativeFunction f{ "UVictoryCore.VTraceAgainstActorExpensive" }; return NativeCall<bool, UWorld*, FVector*, FVector*, FHitResult*, AActor*, ECollisionChannel, int, float, bool, bool, FVector*, FName, bool>(nullptr, f, theWorld, Start, End, HitOut, ActorToTraceAgainst, Channel, CollisionGroups, SphereRadius, bReturnPhysMaterial, bTraceComplex, BoxExtent, TraceTag, bSort); }
	static FString* GetClassString(FString* result, UClass* ForClass) { static NativeFunction f{ "UVictoryCore.GetClassString" }; return NativeCall<FString*, FString*, UClass*>(nullptr, f, result, ForClass); }
	template <typename T, std::enable_if_t<std::is_base_of_v<UObject, T> && !std::is_base_of_v<UClass, T>, int> = 0>
	[[deprecated("use GetClassString(result, UClass*)")]] static FString* GetClassString(FString* result, T* ForObject)
	{
		ReportDeprecatedApiUse("UVictoryCore.GetClassString(result, UObject*)");
		if (ForObject != nullptr && ForObject->IsA(UClass::StaticClass()))
			return GetClassString(result, reinterpret_cast<UClass*>(ForObject));
		new (result) FString();
		return result;
	}
	static FString* GetClassPathName(FString* result, UObject* ForObject) { static NativeFunction f{ "UVictoryCore.GetClassPathName" }; return NativeCall<FString*, FString*, UObject*>(nullptr, f, result, ForObject); }
	static FString* GetNewlineCharacter(FString* result) { static NativeFunction f{ "UVictoryCore.GetNewlineCharacter" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static FString* IntToStringAscii(FString* result, int CharValue) { static NativeFunction f{ "UVictoryCore.IntToStringAscii" }; return NativeCall<FString*, FString*, int>(nullptr, f, result, CharValue); }
	static int StringToIntAscii(FString SourceString, int Index) { static NativeFunction f{ "UVictoryCore.StringToIntAscii" }; return NativeCall<int, FString, int>(nullptr, f, SourceString, Index); }
	static FString* JoinStringArrayWithNewlines(FString* result, TArray<FString>* SourceArray) { static NativeFunction f{ "UVictoryCore.JoinStringArrayWithNewlines" }; return NativeCall<FString*, FString*, TArray<FString>*>(nullptr, f, result, SourceArray); }
	static FString* GetTwoLetterISOLanguageName(FString* result) { static NativeFunction f{ "UVictoryCore.GetTwoLetterISOLanguageName" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static FString* GetTotalCoversionIdAsString(FString* result) { static NativeFunction f{ "UVictoryCore.GetTotalCoversionIdAsString" }; return NativeCall<FString*, FString*>(nullptr, f, result); }
	static AActor* SpawnActorInWorld(UWorld* ForWorld, TSubclassOf<AActor> AnActorClass, FVector AtLocation, FRotator AtRotation, USceneComponent* attachToComponent, int dataIndex, FName attachSocketName, AActor* OwnerActor, APawn* InstigatorPawn) { static NativeFunction f{ "UVictoryCore.SpawnActorInWorld" }; return NativeCall<AActor*, UWorld*, TSubclassOf<AActor>, FVector, FRotator, USceneComponent*, int, FName, AActor*, APawn*>(nullptr, f, ForWorld, AnActorClass, AtLocation, AtRotation, attachToComponent, dataIndex, attachSocketName, OwnerActor, InstigatorPawn); }
	//static UClass* GetItemClassFromItemSetup(FItemSetup* ItemSetup) { return NativeCall<UClass*, FItemSetup*>(nullptr, "UVictoryCore.GetItemClassFromItemSetup", ItemSetup); }
	static bool GetCharacterCapsuleSize(TSubclassOf<APrimalCharacter> CharClass, float* OutCapsuleRadius, float* OutCapsuleHalfHeight) { static NativeFunction f{ "UVictoryCore.GetCharacterCapsuleSize" }; return NativeCall<bool, TSubclassOf<APrimalCharacter>, float*, float*>(nullptr, f, CharClass, OutCapsuleRadius, OutCapsuleHalfHeight); }
	//static UClass* GetDinoStaticClass(FDinoSetup* DinoSetup) { return NativeCall<UClass*, FDinoSetup*>(nullptr, "UVictoryCore.GetDinoStaticClass", DinoSetup); }
	//static FVector* GetCustomDinoSpawnLocation(FVector* result, UWorld* World, FVector* SpawnLocation, FRotator* SpawnRotation, FDinoSetup* DinoSetup, float DebugDrawDuration, bool bApplyRotationToSpawnOffset) { return NativeCall<FVector*, FVector*, UWorld*, FVector*, FRotator*, FDinoSetup*, float, bool>(nullptr, "UVictoryCore.GetCustomDinoSpawnLocation", result, World, SpawnLocation, SpawnRotation, DinoSetup, DebugDrawDuration, bApplyRotationToSpawnOffset); }
	//static APrimalDinoCharacter* SpawnCustomDino(UWorld* World, FVector* SpawnLocation, FRotator* SpawnRotation, FDinoSetup* DinoSetup, AShooterPlayerController* OwnerPlayerController, float DebugDrawDuration, bool bApplyRotationToSpawnOffset) { return NativeCall<APrimalDinoCharacter*, UWorld*, FVector*, FRotator*, FDinoSetup*, AShooterPlayerController*, float, bool>(nullptr, "UVictoryCore.SpawnCustomDino", World, SpawnLocation, SpawnRotation, DinoSetup, OwnerPlayerController, DebugDrawDuration, bApplyRotationToSpawnOffset); }
	//static bool CanSpawnCustomDino(UWorld* World, FVector* OutCalculatedSpawnLocation, FVector* PlayerLocation, FVector* SpawnLocation, FRotator* SpawnRotation, FDinoSetup* DinoSetup, float DebugDrawDuration) { return NativeCall<bool, UWorld*, FVector*, FVector*, FVector*, FRotator*, FDinoSetup*, float>(nullptr, "UVictoryCore.CanSpawnCustomDino", World, OutCalculatedSpawnLocation, PlayerLocation, SpawnLocation, SpawnRotation, DinoSetup, DebugDrawDuration); }
	static void GetObjectsReferencedBy(UObject* ForObject, TArray<UObject*>* OutReferencedObjects, bool bIgnoreTransient) { static NativeFunction f{ "UVictoryCore.GetObjectsReferencedBy" }; NativeCall<void, UObject*, TArray<UObject*>*, bool>(nullptr, f, ForObject, OutReferencedObjects, bIgnoreTransient); }
	static bool GetOverlappedHarvestActors(UWorld* ForWorld, FVector* AtLoc, float AtRadius, TArray<AActor*>* OutHarvestActors, TArray<UActorComponent*>* OutHarvestComponents, TArray<FVector>* OutHarvestLocations, TArray<int>* OutHitBodyIndices) { static NativeFunction f{ "UVictoryCore.GetOverlappedHarvestActors" }; return NativeCall<bool, UWorld*, FVector*, float, TArray<AActor*>*, TArray<UActorComponent*>*, TArray<FVector>*, TArray<int>*>(nullptr, f, ForWorld, AtLoc, AtRadius, OutHarvestActors, OutHarvestComponents, OutHarvestLocations, OutHitBodyIndices); }
	static FName* GetHitBoneNameFromDamageEvent(FName* result, APrimalCharacter* Character, AController* HitInstigator, FDamageEvent* DamageEvent, bool bIsPointDamage, FHitResult* PointHitResult, FName MatchCollisionPresetName) { static NativeFunction f{ "UVictoryCore.GetHitBoneNameFromDamageEvent" }; return NativeCall<FName*, FName*, APrimalCharacter*, AController*, FDamageEvent*, bool, FHitResult*, FName>(nullptr, f, result, Character, HitInstigator, DamageEvent, bIsPointDamage, PointHitResult, MatchCollisionPresetName); }
	static float GetAngleBetweenVectors(FVector* VectorA, FVector* VectorB, FVector* AroundAxis) { static NativeFunction f{ "UVictoryCore.GetAngleBetweenVectors" }; return NativeCall<float, FVector*, FVector*, FVector*>(nullptr, f, VectorA, VectorB, AroundAxis); }
	static float GetAngleBetweenVectorsPure(FVector VectorA, FVector VectorB, FVector AroundAxis) { static NativeFunction f{ "UVictoryCore.GetAngleBetweenVectorsPure" }; return NativeCall<float, FVector, FVector, FVector>(nullptr, f, VectorA, VectorB, AroundAxis); }
	static bool AreRotatorsNearlyEqual(FRotator* RotatorA, FRotator* RotatorB, float WithinError) { static NativeFunction f{ "UVictoryCore.AreRotatorsNearlyEqual" }; return NativeCall<bool, FRotator*, FRotator*, float>(nullptr, f, RotatorA, RotatorB, WithinError); }
	static void SetBoolArrayElemTrue(TArray<bool>* TheArray, int TheIndex) { static NativeFunction f{ "UVictoryCore.SetBoolArrayElemTrue" }; NativeCall<void, TArray<bool>*, int>(nullptr, f, TheArray, TheIndex); }
	static void SetBoolArrayElemFalse(TArray<bool>* TheArray, int TheIndex) { static NativeFunction f{ "UVictoryCore.SetBoolArrayElemFalse" }; NativeCall<void, TArray<bool>*, int>(nullptr, f, TheArray, TheIndex); }
	static void MulticastDrawDebugLine(AActor* ReplicatedActor, FVector LineStart, FVector LineEnd, FLinearColor LineColor, float Duration, float Thickness, bool bPersistent = false) { static NativeFunction f{ "UVictoryCore.MulticastDrawDebugLine" }; NativeCall<void, AActor*, FVector, FVector, FLinearColor, float, float, bool>(nullptr, f, ReplicatedActor, LineStart, LineEnd, LineColor, Duration, Thickness, bPersistent); }
	static void MulticastDrawDebugSphere(AActor* ReplicatedActor, FVector Center, float Radius, int Segments, FLinearColor LineColor, float Duration) { static NativeFunction f{ "UVictoryCore.MulticastDrawDebugSphere" }; NativeCall<void, AActor*, FVector, float, int, FLinearColor, float>(nullptr, f, ReplicatedActor, Center, Radius, Segments, LineColor, Duration); }
	static AShooterCharacter* GetPlayerCharacterByController(APlayerController* PC) { static NativeFunction f{ "UVictoryCore.GetPlayerCharacterByController" }; return NativeCall<AShooterCharacter*, APlayerController*>(nullptr, f, PC); }
	static APrimalDinoCharacter* GetDinoCharacterByID(UObject* WorldContextObject, const int DinoID1, const int DinoID2, const bool bSearchTamedOnly) { static NativeFunction f{ "UVictoryCore.GetDinoCharacterByID" }; return NativeCall<APrimalDinoCharacter*, UObject*, const int, const int, const bool>(nullptr, f, WorldContextObject, DinoID1, DinoID2, bSearchTamedOnly); }
	static void GetAllClassesOfType(TArray<TSubclassOf<UObject>>* Subclasses, TSubclassOf<UObject> ParentClass, bool bAllowAbstract, FString Path) { static NativeFunction f{ "UVictoryCore.GetAllClassesOfType" }; NativeCall<void, TArray<TSubclassOf<UObject>>*, TSubclassOf<UObject>, bool, FString>(nullptr, f, Subclasses, ParentClass, bAllowAbstract, Path); }
	static FVector2D* InverseTransformVectorByScreenProjectionGlobalTransform(FVector2D* result, FVector2D vec) { static NativeFunction f{ "UVictoryCore.InverseTransformVectorByScreenProjectionGlobalTransform" }; return NativeCall<FVector2D*, FVector2D*, FVector2D>(nullptr, f, result, vec); }
	static float GetScreenPercentage() { static NativeFunction f{ "UVictoryCore.GetScreenPercentage" }; return NativeCall<float>(nullptr, f); }
	static bool ProjectWorldLocationToScreenOrScreenEdgePosition(APlayerController* playerController, FVector WorldLocation, FVector2D* ScreenPosition, const float screenMarginPercent, bool widgetSpace, bool* OnScreen, bool bAllowOffScreen = false) { static NativeFunction f{ "UVictoryCore.ProjectWorldLocationToScreenOrScreenEdgePosition" }; return NativeCall<bool, APlayerController*, FVector, FVector2D*, const float, bool, bool*, bool>(nullptr, f, playerController, WorldLocation, ScreenPosition, screenMarginPercent, widgetSpace, OnScreen, bAllowOffScreen); }
	//static bool GetLocaleSpecificAudio(TArray<FLocalizedSoundCueEntry>* LocalizedSoundCues, FLocalizedSoundCueEntry* OutLocalizedAudio, FString* LanguageOverride) { return NativeCall<bool, TArray<FLocalizedSoundCueEntry>*, FLocalizedSoundCueEntry*, FString*>(nullptr, "UVictoryCore.GetLocaleSpecificAudio", LocalizedSoundCues, OutLocalizedAudio, LanguageOverride); }
	static TArray<AShooterPlayerController*>* GetAllLocalPlayerControllers(TArray<AShooterPlayerController*>* result, UObject* WorldContextObject) { static NativeFunction f{ "UVictoryCore.GetAllLocalPlayerControllers" }; return NativeCall<TArray<AShooterPlayerController*>*, TArray<AShooterPlayerController*>*, UObject*>(nullptr, f, result, WorldContextObject); }
	static bool IsPointStuckWithinMesh(UWorld* theWorld, FVector TestPoint, int hemisphereSubdivisions, float rayDistance, float percentageConsideredStuck, AActor* ActorToIgnore) { static NativeFunction f{ "UVictoryCore.IsPointStuckWithinMesh" }; return NativeCall<bool, UWorld*, FVector, int, float, float, AActor*>(nullptr, f, theWorld, TestPoint, hemisphereSubdivisions, rayDistance, percentageConsideredStuck, ActorToIgnore); }
	static bool ServerCheckMeshingOnActor(AActor* OnActor, bool bForceUseActorCenterBounds) { static NativeFunction f{ "UVictoryCore.ServerCheckMeshingOnActor" }; return NativeCall<bool, AActor*, bool>(nullptr, f, OnActor, bForceUseActorCenterBounds); }
	static TArray<AShooterCharacter*>* GetAllLocalPlayerCharacters(TArray<AShooterCharacter*>* result, UObject* WorldContextObject) { static NativeFunction f{ "UVictoryCore.GetAllLocalPlayerCharacters" }; return NativeCall<TArray<AShooterCharacter*>*, TArray<AShooterCharacter*>*, UObject*>(nullptr, f, result, WorldContextObject); }
	static bool IsDinoDuped(UWorld* WorldContext, const unsigned int id1, const unsigned int id2) { static NativeFunction f{ "UVictoryCore.IsDinoDuped" }; return NativeCall<bool, UWorld*, const unsigned int, const unsigned int>(nullptr, f, WorldContext, id1, id2); }
	static bool IsUnderMesh(APrimalCharacter* Character, FVector* CheckSevenHitLocation, bool* bOverlapping, UActorComponent** CheckSevenResult, bool DebugDraw, float DebugDrawSeconds) { static NativeFunction f{ "UVictoryCore.IsUnderMesh" }; return NativeCall<bool, APrimalCharacter*, FVector*, bool*, UActorComponent**, bool, float>(nullptr, f, Character, CheckSevenHitLocation, bOverlapping, CheckSevenResult, DebugDraw, DebugDrawSeconds); }
	static FString* BPGetPrimaryMapName(FString* result, UWorld* WorldContext) { static NativeFunction f{ "UVictoryCore.BPGetPrimaryMapName" }; return NativeCall<FString*, FString*, UWorld*>(nullptr, f, result, WorldContext); }
	static bool OverlappingStationaryObjectsTrace(UWorld* theWorld, APrimalCharacter* SourceCharacter, TArray<FOverlapResult>* Overlaps, FVector Origin, float Radius, ECollisionChannel TraceChannel, AActor* InIgnoreActor, FName TraceName, bool bComplexOverlapTest) { static NativeFunction f{ "UVictoryCore.OverlappingStationaryObjectsTrace" }; return NativeCall<bool, UWorld*, APrimalCharacter*, TArray<FOverlapResult>*, FVector, float, ECollisionChannel, AActor*, FName, bool>(nullptr, f, theWorld, SourceCharacter, Overlaps, Origin, Radius, TraceChannel, InIgnoreActor, TraceName, bComplexOverlapTest); }
	static void StaticRegisterNativesUVictoryCore() { static NativeFunction f{ "UVictoryCore.StaticRegisterNativesUVictoryCore" }; NativeCall<void>(nullptr, f); }
	static FString* ClassToStringReference(FString* result, TSubclassOf<UObject> obj) { static NativeFunction f{ "UVictoryCore.ClassToStringReference" }; return NativeCall<FString*, FString*, TSubclassOf<UObject>>(nullptr, f, result, obj); }
	static TSubclassOf<UObject>* StringReferenceToClass(TSubclassOf<UObject>* result, FString* StringReference) { static NativeFunction f{ "UVictoryCore.StringReferenceToClass" }; return NativeCall<TSubclassOf<UObject>*, TSubclassOf<UObject>*, FString*>(nullptr, f, result, StringReference); }
	static void ServerSearchFoliage(UObject* WorldContextObject, FVector* Origin, float Radius, TArray<FOverlappedFoliageElement>* OutFoliage, bool bVisibleAndActiveOnly, bool bIncludeUsableFoliage, bool bIncludeMeshFoliage, bool bSortByDistance, bool bReverseSort) { static NativeFunction f{ "UVictoryCore.ServerSearchFoliage" }; NativeCall<void, UObject*, FVector*, float, TArray<FOverlappedFoliageElement>*, bool, bool, bool, bool, bool>(nullptr, f, WorldContextObject, Origin, Radius, OutFoliage, bVisibleAndActiveOnly, bIncludeUsableFoliage, bIncludeMeshFoliage, bSortByDistance, bReverseSort); }
};

struct UDamageType
{
	float& ImpulseMinimumZPercentField() { static NativeFieldOffset f{ "UDamageType.ImpulseMinimumZPercent" }; return *GetNativePointerField<float*>(this, f); }
	float& DestructibleImpulseScaleField() { static NativeFieldOffset f{ "UDamageType.DestructibleImpulseScale" }; return *GetNativePointerField<float*>(this, f); }
	float& ImpulseRagdollScaleField() { static NativeFieldOffset f{ "UDamageType.ImpulseRagdollScale" }; return *GetNativePointerField<float*>(this, f); }
	float& DefaultImpulseField() { static NativeFieldOffset f{ "UDamageType.DefaultImpulse" }; return *GetNativePointerField<float*>(this, f); }
	float& PointDamageArmorEffectivenessField() { static NativeFieldOffset f{ "UDamageType.PointDamageArmorEffectiveness" }; return *GetNativePointerField<float*>(this, f); }
	float& GeneralDamageArmorEffectivenessField() { static NativeFieldOffset f{ "UDamageType.GeneralDamageArmorEffectiveness" }; return *GetNativePointerField<float*>(this, f); }
	float& ArmorDurabilityDegradationMultiplierField() { static NativeFieldOffset f{ "UDamageType.ArmorDurabilityDegradationMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& RadialPartiallyObstructedDamagePercentField() { static NativeFieldOffset f{ "UDamageType.RadialPartiallyObstructedDamagePercent" }; return *GetNativePointerField<float*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bIsPhysicalDamage() { static NativeBitField f{ "UDamageType.bIsPhysicalDamage" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowPerBoneDamageAdjustment() { static NativeBitField f{ "UDamageType.bAllowPerBoneDamageAdjustment" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCausedByWorld() { static NativeBitField f{ "UDamageType.bCausedByWorld" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bScaleMomentumByMass() { static NativeBitField f{ "UDamageType.bScaleMomentumByMass" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPassiveDamage() { static NativeBitField f{ "UDamageType.bIsPassiveDamage" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRadialDamageVelChange() { static NativeBitField f{ "UDamageType.bRadialDamageVelChange" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bImpulseAffectsLivePawns() { static NativeBitField f{ "UDamageType.bImpulseAffectsLivePawns" }; return { this, f }; }

	// Functions

	static UClass* StaticClass() { static NativeStaticClass f{ "UDamageType.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t*) { return StaticClass(); }
	static void StaticRegisterNativesUDamageType() { static NativeFunction f{ "UDamageType.StaticRegisterNativesUDamageType" }; NativeCall<void>(nullptr, f); }
};

struct FDinoAttackInfo
{
	alignas(8) unsigned char __padding[0x130];
	FName& AttackNameField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackName" }; return *GetNativePointerField<FName*>(this, f); }
	float& AttackWeightField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackWeight" }; return *GetNativePointerField<float*>(this, f); }
	float& AttackRangeField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackRange" }; return *GetNativePointerField<float*>(this, f); }
	float& MinAttackRangeField() { static NativeFieldOffset f{ "FDinoAttackInfo.MinAttackRange" }; return *GetNativePointerField<float*>(this, f); }
	float& ActivateAttackRangeField() { static NativeFieldOffset f{ "FDinoAttackInfo.ActivateAttackRange" }; return *GetNativePointerField<float*>(this, f); }
	float& AttackIntervalField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackInterval" }; return *GetNativePointerField<float*>(this, f); }
	TArray<int>& ChildStateIndexesField() { static NativeFieldOffset f{ "FDinoAttackInfo.ChildStateIndexes" }; return *GetNativePointerField<TArray<int>*>(this, f); }
	float& AttackWithJumpChanceField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackWithJumpChance" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastAttackTimeField() { static NativeFieldOffset f{ "FDinoAttackInfo.LastAttackTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& RiderLastAttackTimeField() { static NativeFieldOffset f{ "FDinoAttackInfo.RiderLastAttackTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& AttackSelectionExpirationTimeField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackSelectionExpirationTime" }; return *GetNativePointerField<float*>(this, f); }
	long double& AttackSelectionTimeField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackSelectionTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& AttackRotationRangeDegreesField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackRotationRangeDegrees" }; return *GetNativePointerField<float*>(this, f); }
	float& AttackRotationGroundSpeedMultiplierField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackRotationGroundSpeedMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FRotator& AttackRotationRateField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackRotationRate" }; return *GetNativePointerField<FRotator*>(this, f); }
	TArray<FName>& MeleeSwingSocketsField() { static NativeFieldOffset f{ "FDinoAttackInfo.MeleeSwingSockets" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	FName& RangedSocketField() { static NativeFieldOffset f{ "FDinoAttackInfo.RangedSocket" }; return *GetNativePointerField<FName*>(this, f); }
	int& MeleeDamageAmountField() { static NativeFieldOffset f{ "FDinoAttackInfo.MeleeDamageAmount" }; return *GetNativePointerField<int*>(this, f); }
	float& MeleeDamageImpulseField() { static NativeFieldOffset f{ "FDinoAttackInfo.MeleeDamageImpulse" }; return *GetNativePointerField<float*>(this, f); }
	float& MeleeSwingRadiusField() { static NativeFieldOffset f{ "FDinoAttackInfo.MeleeSwingRadius" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<UDamageType>& MeleeDamageTypeField() { static NativeFieldOffset f{ "FDinoAttackInfo.MeleeDamageType" }; return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, f); }
	float& AttackOffsetField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackOffset" }; return *GetNativePointerField<float*>(this, f); }
	float& StaminaCostField() { static NativeFieldOffset f{ "FDinoAttackInfo.StaminaCost" }; return *GetNativePointerField<float*>(this, f); }
	float& RiderAttackIntervalField() { static NativeFieldOffset f{ "FDinoAttackInfo.RiderAttackInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& DotProductCheckMinField() { static NativeFieldOffset f{ "FDinoAttackInfo.DotProductCheckMin" }; return *GetNativePointerField<float*>(this, f); }
	float& DotProductCheckMaxField() { static NativeFieldOffset f{ "FDinoAttackInfo.DotProductCheckMax" }; return *GetNativePointerField<float*>(this, f); }
	TArray<UAnimMontage*>& AttackAnimationsField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackAnimations" }; return *GetNativePointerField<TArray<UAnimMontage*>*>(this, f); }
	TArray<float>& AttackAnimationWeightsField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackAnimationWeights" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	TArray<float>& AttackAnimationsTimeFromEndToConsiderFinishedField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackAnimationsTimeFromEndToConsiderFinished" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	float& AttackRunningSpeedModifierField() { static NativeFieldOffset f{ "FDinoAttackInfo.AttackRunningSpeedModifier" }; return *GetNativePointerField<float*>(this, f); }
	float& SwimmingAttackRunningSpeedModifierField() { static NativeFieldOffset f{ "FDinoAttackInfo.SwimmingAttackRunningSpeedModifier" }; return *GetNativePointerField<float*>(this, f); }
	float& SetAttackTargetTimeField() { static NativeFieldOffset f{ "FDinoAttackInfo.SetAttackTargetTime" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FVector>& LastSocketPositionsField() { static NativeFieldOffset f{ "FDinoAttackInfo.LastSocketPositions" }; return *GetNativePointerField<TArray<FVector>*>(this, f); }
	long double& LastProjectileSpawnTimeField() { static NativeFieldOffset f{ "FDinoAttackInfo.LastProjectileSpawnTime" }; return *GetNativePointerField<long double*>(this, f); }

	// Functions

	FDinoAttackInfo* operator=(FDinoAttackInfo* __that) { static NativeFunction f{ "FDinoAttackInfo.operator=" }; return NativeCall<FDinoAttackInfo*, FDinoAttackInfo*>(this, f, __that); }
	static UScriptStruct* StaticStruct() { static NativeFunction f{ "FDinoAttackInfo.StaticStruct" }; return NativeCall<UScriptStruct*>(nullptr, f); }
};

struct FHordeCrateNPCGroup {};
struct FHordeCrateWave {};
struct __declspec(align(8)) FHordeCrateDifficultyLevel
{
	alignas(8) unsigned char __padding[0xB0];
	int& DifficultyLevelField() { static NativeFieldOffset f{ "FHordeCrateDifficultyLevel.DifficultyLevel" }; return *GetNativePointerField<int*>(this, f); }
};


struct FActiveEventUndeprecatedStructures
{
	alignas(8) unsigned char __padding[0x18];
	//FName ActiveEvent;
	FName& ActiveEventField() { static NativeFieldOffset f{ "FActiveEventUndeprecatedStructures.ActiveEvent" }; return *GetNativePointerField<FName*>(this, f); }
	//TArray<TSubclassOf<APrimalStructure>,FDefaultAllocator> UndeprecatedStructuresDuringEvent;
	TArray<TSubclassOf<APrimalStructure>>& UndeprecatedStructuresDuringEventField() { static NativeFieldOffset f{ "FActiveEventUndeprecatedStructures.UndeprecatedStructuresDuringEvent" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); };
};

struct FActiveEventUndeprecatedItems
{
	alignas(8) unsigned char __padding[0x18];
	//FName ActiveEvent;
	FName& ActiveEventField() { static NativeFieldOffset f{ "FActiveEventUndeprecatedItems.ActiveEvent" }; return *GetNativePointerField<FName*>(this, f); }
	//TArray<TSubclassOf<UPrimalItem>,FDefaultAllocator> UndeprecatedItemsDuringEvent;
	TArray<TSubclassOf<UPrimalItem>>& UndeprecatedItemsDuringEventField() { static NativeFieldOffset f{ "FActiveEventUndeprecatedItems.UndeprecatedItemsDuringEvent" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); };
};

struct FActiveEventUndeprecatedDinos
{
	alignas(8) unsigned char __padding[0x18];
	//FName ActiveEvent;
	FName& ActiveEventField() { static NativeFieldOffset f{ "FActiveEventUndeprecatedDinos.ActiveEvent" }; return *GetNativePointerField<FName*>(this, f); }
	//TArray<TSubclassOf<APrimalDinoCharacter>,FDefaultAllocator> UndeprecatedDinosDuringEvent;
	TArray<TSubclassOf<APrimalDinoCharacter>>& UndeprecatedDinosDuringEventField() { static NativeFieldOffset f{ "FActiveEventUndeprecatedDinos.UndeprecatedDinosDuringEvent" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalDinoCharacter>>*>(this, f); };
};

struct FActiveEventGlobalStatusAdjustments
{
	alignas(8) unsigned char __padding[0x68];
	//FName ActiveEvent;
	FName& ActiveEventField() { static NativeFieldOffset f{ "FActiveEventGlobalStatusAdjustments.ActiveEvent" }; return *GetNativePointerField<FName*>( this, f); }
	//float GlobalStatusAdjustmentRateMultipliersPositive[12];
	FieldArray<float, 12> GlobalStatusAdjustmentRateMultipliersPositiveField() { static NativeFieldOffset f{ "FActiveEventGlobalStatusAdjustments.GlobalStatusAdjustmentRateMultipliersPositive" }; return { this, f }; };
	//float GlobalStatusAdjustmentRateMultipliersNegative[12];
	FieldArray<float, 12> GlobalStatusAdjustmentRateMultipliersNegativeField() { static NativeFieldOffset f{ "FActiveEventGlobalStatusAdjustments.GlobalStatusAdjustmentRateMultipliersNegative" }; return { this, f }; };
};

struct UPrimalWorldSettingsEventOverrides : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalWorldSettingsEventOverrides.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "UPrimalWorldSettingsEventOverrides.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	//TArray<FClassRemappingWeight> NPCRandomSpawnClassWeights;
	TArray<FClassRemappingWeight>& NPCRandomSpawnClassWeightsField() { static NativeFieldOffset f{ "UPrimalWorldSettingsEventOverrides.NPCRandomSpawnClassWeights" }; return *GetNativePointerField<TArray<FClassRemappingWeight>*>(this, f); };
	//TArray<FClassRemappingWeight> SinglePlayerNPCRandomSpawnClassWeights;
	TArray<FClassRemappingWeight>& SinglePlayerNPCRandomSpawnClassWeightsField() { static NativeFieldOffset f{ "UPrimalWorldSettingsEventOverrides.SinglePlayerNPCRandomSpawnClassWeights" }; return *GetNativePointerField<TArray<FClassRemappingWeight>*>(this, f); };
	//TArray<FActiveEventUndeprecatedStructures> UndeprecatedStructuresDuringEvent;
	TArray<FActiveEventUndeprecatedStructures>& UndeprecatedStructuresDuringEventField() { static NativeFieldOffset f{ "UPrimalWorldSettingsEventOverrides.UndeprecatedStructuresDuringEvent" }; return *GetNativePointerField<TArray<FActiveEventUndeprecatedStructures>*>(this, f); };
	//TArray<FActiveEventUndeprecatedItems> UndeprecatedItemsDuringEvent;
	TArray<FActiveEventUndeprecatedItems>& UndeprecatedItemsDuringEventField() { static NativeFieldOffset f{ "UPrimalWorldSettingsEventOverrides.UndeprecatedItemsDuringEvent" }; return *GetNativePointerField<TArray<FActiveEventUndeprecatedItems>*>(this, f); };
	//TArray<FActiveEventUndeprecatedDinos> UndeprecatedDinosDuringEvent;
	TArray<FActiveEventUndeprecatedDinos>& UndeprecatedDinosDuringEventField() { static NativeFieldOffset f{ "UPrimalWorldSettingsEventOverrides.UndeprecatedDinosDuringEvent" }; return *GetNativePointerField<TArray<FActiveEventUndeprecatedDinos>*>(this, f); };
	//TArray<FActiveEventGlobalStatusAdjustments> AdditionalGlobalStatusAdjustmentsDuringEvent;
	TArray<FActiveEventGlobalStatusAdjustments>& AdditionalGlobalStatusAdjustmentsDuringEventField() { static NativeFieldOffset f{ "UPrimalWorldSettingsEventOverrides.AdditionalGlobalStatusAdjustmentsDuringEvent" }; return *GetNativePointerField<TArray<FActiveEventGlobalStatusAdjustments>*>(this, f); };
};
