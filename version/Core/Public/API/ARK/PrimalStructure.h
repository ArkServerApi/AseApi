#pragma once

struct APrimalTargetableActor : AActor
{
	float& LowHealthPercentageField() { static NativeFieldOffset f{ "APrimalTargetableActor.LowHealthPercentage" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<AActor>& DestructionActorTemplateField() { static NativeFieldOffset f{ "APrimalTargetableActor.DestructionActorTemplate" }; return *GetNativePointerField<TSubclassOf<AActor>*>(this, f); }
	float& LifeSpanAfterDeathField() { static NativeFieldOffset f{ "APrimalTargetableActor.LifeSpanAfterDeath" }; return *GetNativePointerField<float*>(this, f); }
	USoundCue* DeathSoundField() { static NativeFieldOffset f{ "APrimalTargetableActor.DeathSound" }; return *GetNativePointerField<USoundCue**>(this, f); }
	float& PassiveDamageHealthReplicationPercentIntervalField() { static NativeFieldOffset f{ "APrimalTargetableActor.PassiveDamageHealthReplicationPercentInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& DamageNotifyTeamAggroMultiplierField() { static NativeFieldOffset f{ "APrimalTargetableActor.DamageNotifyTeamAggroMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DamageNotifyTeamAggroRangeField() { static NativeFieldOffset f{ "APrimalTargetableActor.DamageNotifyTeamAggroRange" }; return *GetNativePointerField<float*>(this, f); }
	float& DamageNotifyTeamAggroRangeFalloffField() { static NativeFieldOffset f{ "APrimalTargetableActor.DamageNotifyTeamAggroRangeFalloff" }; return *GetNativePointerField<float*>(this, f); }
	FVector& DestructibleMeshLocationOffsetField() { static NativeFieldOffset f{ "APrimalTargetableActor.DestructibleMeshLocationOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& DestructibleMeshScaleOverrideField() { static NativeFieldOffset f{ "APrimalTargetableActor.DestructibleMeshScaleOverride" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& DestructibleMeshRotationOffsetField() { static NativeFieldOffset f{ "APrimalTargetableActor.DestructibleMeshRotationOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	FString& DescriptiveNameField() { static NativeFieldOffset f{ "APrimalTargetableActor.DescriptiveName" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<ADestroyedMeshActor>& DestroyedMeshActorClassField() { static NativeFieldOffset f{ "APrimalTargetableActor.DestroyedMeshActorClass" }; return *GetNativePointerField<TSubclassOf<ADestroyedMeshActor>*>(this, f); }
	float& ReplicatedHealthField() { static NativeFieldOffset f{ "APrimalTargetableActor.ReplicatedHealth" }; return *GetNativePointerField<float*>(this, f); }
	float& HealthField() { static NativeFieldOffset f{ "APrimalTargetableActor.Health" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxHealthField() { static NativeFieldOffset f{ "APrimalTargetableActor.MaxHealth" }; return *GetNativePointerField<float*>(this, f); }
	float& DestructibleMeshDeathImpulseScaleField() { static NativeFieldOffset f{ "APrimalTargetableActor.DestructibleMeshDeathImpulseScale" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FBoneDamageAdjuster>& BoneDamageAdjustersField() { static NativeFieldOffset f{ "APrimalTargetableActor.BoneDamageAdjusters" }; return *GetNativePointerField<TArray<FBoneDamageAdjuster>*>(this, f); }
	float& LastReplicatedHealthValueField() { static NativeFieldOffset f{ "APrimalTargetableActor.LastReplicatedHealthValue" }; return *GetNativePointerField<float*>(this, f); }
	UPrimalHarvestingComponent* MyHarvestingComponentField() { static NativeFieldOffset f{ "APrimalTargetableActor.MyHarvestingComponent" }; return *GetNativePointerField<UPrimalHarvestingComponent**>(this, f); }
	TEnumAsByte<enum EShooterPhysMaterialType::Type>& TargetableDamageFXDefaultPhysMaterialField() { static NativeFieldOffset f{ "APrimalTargetableActor.TargetableDamageFXDefaultPhysMaterial" }; return *GetNativePointerField<TEnumAsByte<enum EShooterPhysMaterialType::Type>*>(this, f); }
	TSubclassOf<UPrimalStructureSettings>& StructureSettingsClassField() { static NativeFieldOffset f{ "APrimalTargetableActor.StructureSettingsClass" }; return *GetNativePointerField<TSubclassOf<UPrimalStructureSettings>*>(this, f); }
	UPrimalStructureSettings* MyStructureSettingsCDOField() { static NativeFieldOffset f{ "APrimalTargetableActor.MyStructureSettingsCDO" }; return *GetNativePointerField<UPrimalStructureSettings**>(this, f); }
	float& LastHealthBeforeTakeDamageField() { static NativeFieldOffset f{ "APrimalTargetableActor.LastHealthBeforeTakeDamage" }; return *GetNativePointerField<float*>(this, f); }
	long double& NextAllowRepairTimeField() { static NativeFieldOffset f{ "APrimalTargetableActor.NextAllowRepairTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& LastPreBlueprintAdjustmentActualDamageField() { static NativeFieldOffset f{ "APrimalTargetableActor.LastPreBlueprintAdjustmentActualDamage" }; return *GetNativePointerField<float*>(this, f); }
	float& LastReplicatedHealthField() { static NativeFieldOffset f{ "APrimalTargetableActor.LastReplicatedHealth" }; return *GetNativePointerField<float*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bDestructionActorTemplateServerOnly() { static NativeBitField f{ "APrimalTargetableActor.bDestructionActorTemplateServerOnly" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyedMeshUseSkeletalMeshComponent() { static NativeBitField f{ "APrimalTargetableActor.bDestroyedMeshUseSkeletalMeshComponent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventZeroDamageInstigatorSelfDamage() { static NativeBitField f{ "APrimalTargetableActor.bPreventZeroDamageInstigatorSelfDamage" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsDead() { static NativeBitField f{ "APrimalTargetableActor.bIsDead" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDamageNotifyTeamAggroAI() { static NativeBitField f{ "APrimalTargetableActor.bDamageNotifyTeamAggroAI" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSetWithinPreventionVolume() { static NativeBitField f{ "APrimalTargetableActor.bSetWithinPreventionVolume" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bWithinPreventionVolume() { static NativeBitField f{ "APrimalTargetableActor.bWithinPreventionVolume" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowDamageByFriendlyDinos() { static NativeBitField f{ "APrimalTargetableActor.bAllowDamageByFriendlyDinos" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAdjustDamage() { static NativeBitField f{ "APrimalTargetableActor.bUseBPAdjustDamage" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceZeroDamageProcessing() { static NativeBitField f{ "APrimalTargetableActor.bForceZeroDamageProcessing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceFloatingDamageNumbers() { static NativeBitField f{ "APrimalTargetableActor.bForceFloatingDamageNumbers" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDoAllowRadialDamageWithoutVisiblityTrace() { static NativeBitField f{ "APrimalTargetableActor.bDoAllowRadialDamageWithoutVisiblityTrace" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreDestructionEffects() { static NativeBitField f{ "APrimalTargetableActor.bIgnoreDestructionEffects" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreDamageRepairCooldown() { static NativeBitField f{ "APrimalTargetableActor.bIgnoreDamageRepairCooldown" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseHarvestingComponent() { static NativeBitField f{ "APrimalTargetableActor.bUseHarvestingComponent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPDied() { static NativeBitField f{ "APrimalTargetableActor.bUseBPDied" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> BPOverrideDestroyedMeshTextures() { static NativeBitField f{ "APrimalTargetableActor.BPOverrideDestroyedMeshTextures" }; return { this, f }; }

	// Functions

	UObject* GetUObjectInterfaceTargetableInterface() { static NativeFunction f{ "APrimalTargetableActor.GetUObjectInterfaceTargetableInterface" }; return NativeCall<UObject*>(this, f); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalTargetableActor.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	void PostInitializeComponents() { static NativeFunction f{ "APrimalTargetableActor.PostInitializeComponents" }; NativeCall<void>(this, f); }
	void Destroyed() { static NativeFunction f{ "APrimalTargetableActor.Destroyed" }; NativeCall<void>(this, f); }
	void BeginPlay() { static NativeFunction f{ "APrimalTargetableActor.BeginPlay" }; NativeCall<void>(this, f); }
	void FellOutOfWorld(UDamageType* dmgType) { static NativeFunction f{ "APrimalTargetableActor.FellOutOfWorld" }; NativeCall<void, UDamageType*>(this, f, dmgType); }
	bool IsDead() { static NativeFunction f{ "APrimalTargetableActor.IsDead" }; return NativeCall<bool>(this, f); }
	void AdjustDamage(float* Damage, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.AdjustDamage" }; NativeCall<void, float*, FDamageEvent*, AController*, AActor*>(this, f, Damage, DamageEvent, EventInstigator, DamageCauser); }
	float TakeDamage(float Damage, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.TakeDamage" }; return NativeCall<float, float, FDamageEvent*, AController*, AActor*>(this, f, Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool Die(float KillingDamage, FDamageEvent* DamageEvent, AController* Killer, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.Die" }; return NativeCall<bool, float, FDamageEvent*, AController*, AActor*>(this, f, KillingDamage, DamageEvent, Killer, DamageCauser); }
	void PlayDyingGeneric_Implementation(float KillingDamage, FDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.PlayDyingGeneric_Implementation" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	[[deprecated("pass FDamageEvent*")]] void PlayDyingGeneric_Implementation(float KillingDamage, FPointDamageEvent& DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { ReportDeprecatedApiUse("APrimalTargetableActor.PlayDyingGeneric_Implementation(by value)"); PlayDyingGeneric_Implementation(KillingDamage, reinterpret_cast<FDamageEvent*>(&DamageEvent), InstigatingPawn, DamageCauser); }
	void PlayDyingRadial_Implementation(float KillingDamage, FRadialDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.PlayDyingRadial_Implementation" }; NativeCall<void, float, FRadialDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	[[deprecated("pass a pointer")]] void PlayDyingRadial_Implementation(float KillingDamage, FRadialDamageEvent& DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { ReportDeprecatedApiUse("APrimalTargetableActor.PlayDyingRadial_Implementation(by value)"); PlayDyingRadial_Implementation(KillingDamage, &DamageEvent, InstigatingPawn, DamageCauser); }
	void GetDestructionEffectTransform(FVector* OutEffectLoc, FRotator* OutEffectRot) { static NativeFunction f{ "APrimalTargetableActor.GetDestructionEffectTransform" }; NativeCall<void, FVector*, FRotator*>(this, f, OutEffectLoc, OutEffectRot); }
	void PlayDying(float KillingDamage, FDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.PlayDying" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void PlayHitEffectPoint_Implementation(float DamageTaken, FPointDamageEvent* DamageEvent, APawn* PawnInstigator, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.PlayHitEffectPoint_Implementation" }; NativeCall<void, float, FPointDamageEvent*, APawn*, AActor*>(this, f, DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	[[deprecated("pass a pointer")]] void PlayHitEffectPoint_Implementation(float DamageTaken, FPointDamageEvent& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser) { ReportDeprecatedApiUse("APrimalTargetableActor.PlayHitEffectPoint_Implementation(by value)"); PlayHitEffectPoint_Implementation(DamageTaken, &DamageEvent, PawnInstigator, DamageCauser); }
	void PlayHitEffectRadial_Implementation(float DamageTaken, FRadialDamageEvent* DamageEvent, APawn* PawnInstigator, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.PlayHitEffectRadial_Implementation" }; NativeCall<void, float, FRadialDamageEvent*, APawn*, AActor*>(this, f, DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	[[deprecated("pass a pointer")]] void PlayHitEffectRadial_Implementation(float DamageTaken, FRadialDamageEvent& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser) { ReportDeprecatedApiUse("APrimalTargetableActor.PlayHitEffectRadial_Implementation(by value)"); PlayHitEffectRadial_Implementation(DamageTaken, &DamageEvent, PawnInstigator, DamageCauser); }
	void PlayHitEffect(float DamageTaken, FDamageEvent* DamageEvent, APawn* PawnInstigator, AActor* DamageCauser, bool bIsLocalPath) { static NativeFunction f{ "APrimalTargetableActor.PlayHitEffect" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*, bool>(this, f, DamageTaken, DamageEvent, PawnInstigator, DamageCauser, bIsLocalPath); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalTargetableActor.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalTargetableActor.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	float GetMaxHealth() { static NativeFunction f{ "APrimalTargetableActor.GetMaxHealth" }; return NativeCall<float>(this, f); }
	float GetLowHealthPercentage() { static NativeFunction f{ "APrimalTargetableActor.GetLowHealthPercentage" }; return NativeCall<float>(this, f); }
	bool IsAlive() { static NativeFunction f{ "APrimalTargetableActor.IsAlive" }; return NativeCall<bool>(this, f); }
	FString* GetDescriptiveName(FString* result) { static NativeFunction f{ "APrimalTargetableActor.GetDescriptiveName" }; return NativeCall<FString*, FString*>(this, f, result); }
	FString* GetShortName(FString* result) { static NativeFunction f{ "APrimalTargetableActor.GetShortName" }; return NativeCall<FString*, FString*>(this, f, result); }
	float GetHealth() { static NativeFunction f{ "APrimalTargetableActor.GetHealth" }; return NativeCall<float>(this, f); }
	float GetHealthPercentage() { static NativeFunction f{ "APrimalTargetableActor.GetHealthPercentage" }; return NativeCall<float>(this, f); }
	float SetHealth(float newHealth) { static NativeFunction f{ "APrimalTargetableActor.SetHealth" }; return NativeCall<float, float>(this, f, newHealth); }
	void SetMaxHealth(float newMaxHealth) { static NativeFunction f{ "APrimalTargetableActor.SetMaxHealth" }; NativeCall<void, float>(this, f, newMaxHealth); }
	bool IsOfTribe(int ID) { static NativeFunction f{ "APrimalTargetableActor.IsOfTribe" }; return NativeCall<bool, int>(this, f, ID); }
	void NetUpdatedHealth_Implementation(int NewHealth) { static NativeFunction f{ "APrimalTargetableActor.NetUpdatedHealth_Implementation" }; NativeCall<void, int>(this, f, NewHealth); }
	bool IsTargetableDead() { static NativeFunction f{ "APrimalTargetableActor.IsTargetableDead" }; return NativeCall<bool>(this, f); }
	EShooterPhysMaterialType::Type GetTargetableDamageFXDefaultPhysMaterial() { static NativeFunction f{ "APrimalTargetableActor.GetTargetableDamageFXDefaultPhysMaterial" }; return NativeCall<EShooterPhysMaterialType::Type>(this, f); }
	void Suicide() { static NativeFunction f{ "APrimalTargetableActor.Suicide" }; NativeCall<void>(this, f); }
	bool NetExecCommand(FName CommandName, FNetExecParams* ExecParams) { static NativeFunction f{ "APrimalTargetableActor.NetExecCommand" }; return NativeCall<bool, FName, FNetExecParams*>(this, f, CommandName, ExecParams); }
	void UpdatedHealth(bool bDoReplication) { static NativeFunction f{ "APrimalTargetableActor.UpdatedHealth" }; NativeCall<void, bool>(this, f, bDoReplication); }
	void OnRep_ReplicatedHealth() { static NativeFunction f{ "APrimalTargetableActor.OnRep_ReplicatedHealth" }; NativeCall<void>(this, f); }
	bool AllowRadialDamageWithoutVisiblityTrace() { static NativeFunction f{ "APrimalTargetableActor.AllowRadialDamageWithoutVisiblityTrace" }; return NativeCall<bool>(this, f); }
	bool IsInvincible() { static NativeFunction f{ "APrimalTargetableActor.IsInvincible" }; return NativeCall<bool>(this, f); }
	void HarvestingDepleted(UPrimalHarvestingComponent* fromComponent) { static NativeFunction f{ "APrimalTargetableActor.HarvestingDepleted" }; NativeCall<void, UPrimalHarvestingComponent*>(this, f, fromComponent); }
	static void StaticRegisterNativesAPrimalTargetableActor() { static NativeFunction f{ "APrimalTargetableActor.StaticRegisterNativesAPrimalTargetableActor" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalTargetableActor.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	void BPDied(float KillingDamage, FDamageEvent* DamageEvent, AController* Killer, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.BPDied" }; NativeCall<void, float, FDamageEvent*, AController*, AActor*>(this, f, KillingDamage, DamageEvent, Killer, DamageCauser); }
	void BPHitEffect(float DamageTaken, FDamageEvent* DamageEvent, APawn* PawnInstigator, AActor* DamageCauser, bool bIsLocalPath, UPrimitiveComponent* HitComponent, FVector DamageLoc, FRotator HitNormal) { static NativeFunction f{ "APrimalTargetableActor.BPHitEffect" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*, bool, UPrimitiveComponent*, FVector, FRotator>(this, f, DamageTaken, DamageEvent, PawnInstigator, DamageCauser, bIsLocalPath, HitComponent, DamageLoc, HitNormal); }
	bool BPSupressImpactEffects(float DamageTaken, FDamageEvent* DamageEvent, APawn* PawnInstigator, AActor* DamageCauser, bool bIsLocalPath, UPrimitiveComponent* HitComponent) { static NativeFunction f{ "APrimalTargetableActor.BPSupressImpactEffects" }; return NativeCall<bool, float, FDamageEvent*, APawn*, AActor*, bool, UPrimitiveComponent*>(this, f, DamageTaken, DamageEvent, PawnInstigator, DamageCauser, bIsLocalPath, HitComponent); }
	void OverrideDestroyedMeshTextures(UMeshComponent* meshComp) { static NativeFunction f{ "APrimalTargetableActor.OverrideDestroyedMeshTextures" }; NativeCall<void, UMeshComponent*>(this, f, meshComp); }
	void PlayHitEffectGeneric(float DamageTaken, FDamageEvent* DamageEvent, APawn* PawnInstigator, AActor* DamageCauser) { static NativeFunction f{ "APrimalTargetableActor.PlayHitEffectGeneric" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	[[deprecated("pass a pointer")]] void PlayHitEffectGeneric(float DamageTaken, FDamageEvent& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser) { ReportDeprecatedApiUse("APrimalTargetableActor.PlayHitEffectGeneric(by value)"); PlayHitEffectGeneric(DamageTaken, &DamageEvent, PawnInstigator, DamageCauser); }
};

struct APrimalStructure : APrimalTargetableActor
{
	FVector2D& OverlayTooltipPaddingField() { static NativeFieldOffset f{ "APrimalStructure.OverlayTooltipPadding" }; return *GetNativePointerField<FVector2D*>(this, f); }
	FVector2D& OverlayTooltipScaleField() { static NativeFieldOffset f{ "APrimalStructure.OverlayTooltipScale" }; return *GetNativePointerField<FVector2D*>(this, f); }
	FName& StructureTagField() { static NativeFieldOffset f{ "APrimalStructure.StructureTag" }; return *GetNativePointerField<FName*>(this, f); }
	TSubclassOf<UPrimalItem>& ConsumesPrimalItemField() { static NativeFieldOffset f{ "APrimalStructure.ConsumesPrimalItem" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& ScaleFactorField() { static NativeFieldOffset f{ "APrimalStructure.ScaleFactor" }; return *GetNativePointerField<float*>(this, f); }
	int& StructureSnapTypeFlagsField() { static NativeFieldOffset f{ "APrimalStructure.StructureSnapTypeFlags" }; return *GetNativePointerField<int*>(this, f); }
	TArray<FPrimalStructureSnapPoint>& SnapPointsField() { static NativeFieldOffset f{ "APrimalStructure.SnapPoints" }; return *GetNativePointerField<TArray<FPrimalStructureSnapPoint>*>(this, f); }
	TArray<FStructureVariant>& VariantsField() { static NativeFieldOffset f{ "APrimalStructure.Variants" }; return *GetNativePointerField<TArray<FStructureVariant>*>(this, f); }
	int& CurrentVariantField() { static NativeFieldOffset f{ "APrimalStructure.CurrentVariant" }; return *GetNativePointerField<int*>(this, f); }
	float& PlacementOffsetForVerticalGroundField() { static NativeFieldOffset f{ "APrimalStructure.PlacementOffsetForVerticalGround" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementInitialTracePointOffsetForVerticalGroundField() { static NativeFieldOffset f{ "APrimalStructure.PlacementInitialTracePointOffsetForVerticalGround" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& StructuresAllowedToBeVerticalGroundField() { static NativeFieldOffset f{ "APrimalStructure.StructuresAllowedToBeVerticalGround" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	float& TraceDistanceFromActorToWallVerticalGroundField() { static NativeFieldOffset f{ "APrimalStructure.TraceDistanceFromActorToWallVerticalGround" }; return *GetNativePointerField<float*>(this, f); }
	FVector& PlacementHitLocOffsetField() { static NativeFieldOffset f{ "APrimalStructure.PlacementHitLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& PlacementEncroachmentCheckOffsetField() { static NativeFieldOffset f{ "APrimalStructure.PlacementEncroachmentCheckOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& PlacementEncroachmentBoxExtentField() { static NativeFieldOffset f{ "APrimalStructure.PlacementEncroachmentBoxExtent" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& PlacementTraceScaleField() { static NativeFieldOffset f{ "APrimalStructure.PlacementTraceScale" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& SnapAlternatePlacementTraceScaleField() { static NativeFieldOffset f{ "APrimalStructure.SnapAlternatePlacementTraceScale" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& PlacementRotOffsetField() { static NativeFieldOffset f{ "APrimalStructure.PlacementRotOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	FRotator& PlacementTraceRotOffsetField() { static NativeFieldOffset f{ "APrimalStructure.PlacementTraceRotOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	FRotator& SnappingRotationOffsetField() { static NativeFieldOffset f{ "APrimalStructure.SnappingRotationOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	float& RepairAmountRemainingField() { static NativeFieldOffset f{ "APrimalStructure.RepairAmountRemaining" }; return *GetNativePointerField<float*>(this, f); }
	float& RepairCheckIntervalField() { static NativeFieldOffset f{ "APrimalStructure.RepairCheckInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementFloorCheckZExtentUpField() { static NativeFieldOffset f{ "APrimalStructure.PlacementFloorCheckZExtentUp" }; return *GetNativePointerField<float*>(this, f); }
	float& RepairPercentPerIntervalField() { static NativeFieldOffset f{ "APrimalStructure.RepairPercentPerInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& DecayDestructionPeriodField() { static NativeFieldOffset f{ "APrimalStructure.DecayDestructionPeriod" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& PreventPlacingOnFloorClassesField() { static NativeFieldOffset f{ "APrimalStructure.PreventPlacingOnFloorClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& AllowPlacingOnFloorClassesField() { static NativeFieldOffset f{ "APrimalStructure.AllowPlacingOnFloorClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	TSubobjectPtr<USceneComponent>& MyRootTransformField() { static NativeFieldOffset f{ "APrimalStructure.MyRootTransform" }; return *GetNativePointerField<TSubobjectPtr<USceneComponent>*>(this, f); }
	int& TraceIgnoreStructuresWithTypeFlagsField() { static NativeFieldOffset f{ "APrimalStructure.TraceIgnoreStructuresWithTypeFlags" }; return *GetNativePointerField<int*>(this, f); }
	int& bTraceCheckOnlyUseStructuresWithTypeFlagsField() { static NativeFieldOffset f{ "APrimalStructure.bTraceCheckOnlyUseStructuresWithTypeFlags" }; return *GetNativePointerField<int*>(this, f); }
	FieldArray<unsigned char, 6> AllowStructureColorSetsField() { static NativeFieldOffset f{ "APrimalStructure.AllowStructureColorSets" }; return { this, f }; }
	FVector& WaterVolumeCheckPointOffsetField() { static NativeFieldOffset f{ "APrimalStructure.WaterVolumeCheckPointOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& WaterPlacementMinimumWaterHeightField() { static NativeFieldOffset f{ "APrimalStructure.WaterPlacementMinimumWaterHeight" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementMaxZDeltaField() { static NativeFieldOffset f{ "APrimalStructure.PlacementMaxZDelta" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementChooseRotationMaxRangeOverrideField() { static NativeFieldOffset f{ "APrimalStructure.PlacementChooseRotationMaxRangeOverride" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementMaxRangeField() { static NativeFieldOffset f{ "APrimalStructure.PlacementMaxRange" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxSnapLocRangeField() { static NativeFieldOffset f{ "APrimalStructure.MaxSnapLocRange" }; return *GetNativePointerField<float*>(this, f); }
	float& SnapOverlapCheckRadiusField() { static NativeFieldOffset f{ "APrimalStructure.SnapOverlapCheckRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& MaximumFoundationSupport2DBuildDistanceField() { static NativeFieldOffset f{ "APrimalStructure.MaximumFoundationSupport2DBuildDistance" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementFloorCheckZExtentField() { static NativeFieldOffset f{ "APrimalStructure.PlacementFloorCheckZExtent" }; return *GetNativePointerField<float*>(this, f); }
	float& LastHealthPercentageField() { static NativeFieldOffset f{ "APrimalStructure.LastHealthPercentage" }; return *GetNativePointerField<float*>(this, f); }
	FRotator& TakeGroundNormalRotationOffsetField() { static NativeFieldOffset f{ "APrimalStructure.TakeGroundNormalRotationOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	float& DemolishGiveItemCraftingResourcePercentageField() { static NativeFieldOffset f{ "APrimalStructure.DemolishGiveItemCraftingResourcePercentage" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<APrimalStructure>& AllowReplacementByStructureClassTypeField() { static NativeFieldOffset f{ "APrimalStructure.AllowReplacementByStructureClassType" }; return *GetNativePointerField<TSubclassOf<APrimalStructure>*>(this, f); }
	TSubclassOf<APrimalStructure>& PreventReplacementOfStructureClassTypeField() { static NativeFieldOffset f{ "APrimalStructure.PreventReplacementOfStructureClassType" }; return *GetNativePointerField<TSubclassOf<APrimalStructure>*>(this, f); }
	float& MaximumHeightAboveWorldGroundField() { static NativeFieldOffset f{ "APrimalStructure.MaximumHeightAboveWorldGround" }; return *GetNativePointerField<float*>(this, f); }
	float& MaximumHeightUnderWorldMaxKillZField() { static NativeFieldOffset f{ "APrimalStructure.MaximumHeightUnderWorldMaxKillZ" }; return *GetNativePointerField<float*>(this, f); }
	FRotator& PreviewCameraRotationField() { static NativeFieldOffset f{ "APrimalStructure.PreviewCameraRotation" }; return *GetNativePointerField<FRotator*>(this, f); }
	FVector& PreviewCameraPivotOffsetField() { static NativeFieldOffset f{ "APrimalStructure.PreviewCameraPivotOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& PreviewCameraDistanceScaleFactorField() { static NativeFieldOffset f{ "APrimalStructure.PreviewCameraDistanceScaleFactor" }; return *GetNativePointerField<float*>(this, f); }
	float& PreviewCameraDefaultZoomMultiplierField() { static NativeFieldOffset f{ "APrimalStructure.PreviewCameraDefaultZoomMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PreviewCameraMaxZoomMultiplierField() { static NativeFieldOffset f{ "APrimalStructure.PreviewCameraMaxZoomMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& ReturnDamageAmountField() { static NativeFieldOffset f{ "APrimalStructure.ReturnDamageAmount" }; return *GetNativePointerField<float*>(this, f); }
	int& StructureRangeTypeFlagField() { static NativeFieldOffset f{ "APrimalStructure.StructureRangeTypeFlag" }; return *GetNativePointerField<int*>(this, f); }
	int& LimitMaxStructuresInRangeTypeFlagField() { static NativeFieldOffset f{ "APrimalStructure.LimitMaxStructuresInRangeTypeFlag" }; return *GetNativePointerField<int*>(this, f); }
	float& ReturnDamageImpulseField() { static NativeFieldOffset f{ "APrimalStructure.ReturnDamageImpulse" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<UDamageType>& ReturnDamageTypeField() { static NativeFieldOffset f{ "APrimalStructure.ReturnDamageType" }; return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, f); }
	TArray<TSubclassOf<UDamageType>>& ReturnDamageExcludeIncomingTypesField() { static NativeFieldOffset f{ "APrimalStructure.ReturnDamageExcludeIncomingTypes" }; return *GetNativePointerField<TArray<TSubclassOf<UDamageType>>*>(this, f); }
	TArray<TSubclassOf<UDamageType>>& ReturnDamageOnlyForIncomingTypesField() { static NativeFieldOffset f{ "APrimalStructure.ReturnDamageOnlyForIncomingTypes" }; return *GetNativePointerField<TArray<TSubclassOf<UDamageType>>*>(this, f); }
	int& OwningPlayerIDField() { static NativeFieldOffset f{ "APrimalStructure.OwningPlayerID" }; return *GetNativePointerField<int*>(this, f); }
	FString& OwningPlayerNameField() { static NativeFieldOffset f{ "APrimalStructure.OwningPlayerName" }; return *GetNativePointerField<FString*>(this, f); }
	long double& LastInAllyRangeTimeField() { static NativeFieldOffset f{ "APrimalStructure.LastInAllyRangeTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& PickupAllowedBeforeNetworkTimeField() { static NativeFieldOffset f{ "APrimalStructure.PickupAllowedBeforeNetworkTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& DecayDestructionPeriodMultiplierField() { static NativeFieldOffset f{ "APrimalStructure.DecayDestructionPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	TWeakObjectPtr<APrimalDinoCharacter>& SaddleDinoField() { static NativeFieldOffset f{ "APrimalStructure.SaddleDino" }; return *GetNativePointerField<TWeakObjectPtr<APrimalDinoCharacter>*>(this, f); }
	TArray<APrimalDinoCharacter*>& LatchedDinosField() { static NativeFieldOffset f{ "APrimalStructure.LatchedDinos" }; return *GetNativePointerField<TArray<APrimalDinoCharacter*>*>(this, f); }
	UMaterialInterface* PreviewMaterialField() { static NativeFieldOffset f{ "APrimalStructure.PreviewMaterial" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	FName& PreviewMaterialColorParamNameField() { static NativeFieldOffset f{ "APrimalStructure.PreviewMaterialColorParamName" }; return *GetNativePointerField<FName*>(this, f); }
	TArray<FVector>& PlacementTraceDirectionsField() { static NativeFieldOffset f{ "APrimalStructure.PlacementTraceDirections" }; return *GetNativePointerField<TArray<FVector>*>(this, f); }
	TArray<APrimalStructure*>& LinkedStructuresField() { static NativeFieldOffset f{ "APrimalStructure.LinkedStructures" }; return *GetNativePointerField<TArray<APrimalStructure*>*>(this, f); }
	TArray<unsigned int>& LinkedStructuresIDField() { static NativeFieldOffset f{ "APrimalStructure.LinkedStructuresID" }; return *GetNativePointerField<TArray<unsigned int>*>(this, f); }
	TArray<APrimalStructure*>& StructuresPlacedOnFloorField() { static NativeFieldOffset f{ "APrimalStructure.StructuresPlacedOnFloor" }; return *GetNativePointerField<TArray<APrimalStructure*>*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& SnapToStructureTypesToExcludeField() { static NativeFieldOffset f{ "APrimalStructure.SnapToStructureTypesToExclude" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& SnapFromStructureTypesToExcludeField() { static NativeFieldOffset f{ "APrimalStructure.SnapFromStructureTypesToExclude" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	TArray<FName>& SnapToStructureTagsToExcludeField() { static NativeFieldOffset f{ "APrimalStructure.SnapToStructureTagsToExclude" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	TArray<FName>& SnapFromStructureTagsToExcludeField() { static NativeFieldOffset f{ "APrimalStructure.SnapFromStructureTagsToExclude" }; return *GetNativePointerField<TArray<FName>*>(this, f); }
	APrimalStructure*& PlacedOnFloorStructureField() { static NativeFieldOffset f{ "APrimalStructure.PlacedOnFloorStructure" }; return *GetNativePointerField<APrimalStructure**>(this, f); }
	APrimalStructure* PrimarySnappedStructureChildField() { static NativeFieldOffset f{ "APrimalStructure.PrimarySnappedStructureChild" }; return *GetNativePointerField<APrimalStructure**>(this, f); }
	APrimalStructure* PrimarySnappedStructureParentField() { static NativeFieldOffset f{ "APrimalStructure.PrimarySnappedStructureParent" }; return *GetNativePointerField<APrimalStructure**>(this, f); }
	FString& OwnerNameField() { static NativeFieldOffset f{ "APrimalStructure.OwnerName" }; return *GetNativePointerField<FString*>(this, f); }
	FieldArray<__int16, 6> StructureColorsField() { static NativeFieldOffset f{ "APrimalStructure.StructureColors" }; return { this, f }; }
	APawn* AttachedToField() { static NativeFieldOffset f{ "APrimalStructure.AttachedTo" }; return *GetNativePointerField<APawn**>(this, f); }
	APrimalStructureExplosiveTransGPS* AttachedTransponderField() { static NativeFieldOffset f{ "APrimalStructure.AttachedTransponder" }; return *GetNativePointerField<APrimalStructureExplosiveTransGPS**>(this, f); }
	unsigned int& StructureIDField() { static NativeFieldOffset f{ "APrimalStructure.StructureID" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& AttachedToDinoID1Field() { static NativeFieldOffset f{ "APrimalStructure.AttachedToDinoID1" }; return *GetNativePointerField<unsigned int*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& OnlyAllowStructureClassesToAttachField() { static NativeFieldOffset f{ "APrimalStructure.OnlyAllowStructureClassesToAttach" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& OnlyAllowStructureClassesFromAttachField() { static NativeFieldOffset f{ "APrimalStructure.OnlyAllowStructureClassesFromAttach" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	unsigned int& TaggedIndexField() { static NativeFieldOffset f{ "APrimalStructure.TaggedIndex" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& TaggedIndexTwoField() { static NativeFieldOffset f{ "APrimalStructure.TaggedIndexTwo" }; return *GetNativePointerField<unsigned int*>(this, f); }
	unsigned int& ProcessTreeTagField() { static NativeFieldOffset f{ "APrimalStructure.ProcessTreeTag" }; return *GetNativePointerField<unsigned int*>(this, f); }
	long double& LastStructureStasisTimeField() { static NativeFieldOffset f{ "APrimalStructure.LastStructureStasisTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastColorizationTimeField() { static NativeFieldOffset f{ "APrimalStructure.LastColorizationTime" }; return *GetNativePointerField<long double*>(this, f); }
	UMaterialInterface* StructureIconMaterialField() { static NativeFieldOffset f{ "APrimalStructure.StructureIconMaterial" }; return *GetNativePointerField<UMaterialInterface**>(this, f); }
	FVector& AdvancedRotationPlacementOffsetField() { static NativeFieldOffset f{ "APrimalStructure.AdvancedRotationPlacementOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& SpawnEmitterField() { static NativeFieldOffset f{ "APrimalStructure.SpawnEmitter" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	FVector& SpawnEmitterLocationOffsetField() { static NativeFieldOffset f{ "APrimalStructure.SpawnEmitterLocationOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& SpawnEmitterRotationOffsetField() { static NativeFieldOffset f{ "APrimalStructure.SpawnEmitterRotationOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	TSubclassOf<UPrimalItem>& PickupGivesItemField() { static NativeFieldOffset f{ "APrimalStructure.PickupGivesItem" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	float& ExcludeInStructuresRadiusField() { static NativeFieldOffset f{ "APrimalStructure.ExcludeInStructuresRadius" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& ExcludeInStructuresRadiusClassesField() { static NativeFieldOffset f{ "APrimalStructure.ExcludeInStructuresRadiusClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	float& LastFadeOpacityField() { static NativeFieldOffset f{ "APrimalStructure.LastFadeOpacity" }; return *GetNativePointerField<float*>(this, f); }
	bool& bClientAddedToStructuresArrayField() { static NativeFieldOffset f{ "APrimalStructure.bClientAddedToStructuresArray" }; return *GetNativePointerField<bool*>(this, f); }
	long double& LastFailedPinTimeField() { static NativeFieldOffset f{ "APrimalStructure.LastFailedPinTime" }; return *GetNativePointerField<long double*>(this, f); }
	TWeakObjectPtr<UMeshComponent>& PrimaryMeshComponentField() { static NativeFieldOffset f{ "APrimalStructure.PrimaryMeshComponent" }; return *GetNativePointerField<TWeakObjectPtr<UMeshComponent>*>(this, f); }
	UStructurePaintingComponent* PaintingComponentField() { static NativeFieldOffset f{ "APrimalStructure.PaintingComponent" }; return *GetNativePointerField<UStructurePaintingComponent**>(this, f); }
	TArray<FString>& PreventBuildStructureReasonStringOverridesField() { static NativeFieldOffset f{ "APrimalStructure.PreventBuildStructureReasonStringOverrides" }; return *GetNativePointerField<TArray<FString>*>(this, f); }
	FVector& FloatingHudLocTextOffsetField() { static NativeFieldOffset f{ "APrimalStructure.FloatingHudLocTextOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& LastBumpedDamageTimeField() { static NativeFieldOffset f{ "APrimalStructure.LastBumpedDamageTime" }; return *GetNativePointerField<float*>(this, f); }
	int& ForceLimitStructuresInRangeField() { static NativeFieldOffset f{ "APrimalStructure.ForceLimitStructuresInRange" }; return *GetNativePointerField<int*>(this, f); }
	int& PlacementMaterialForwardDirIndexField() { static NativeFieldOffset f{ "APrimalStructure.PlacementMaterialForwardDirIndex" }; return *GetNativePointerField<int*>(this, f); }
	float& ForcePreventPlacingInOfflineRaidStructuresRadiusField() { static NativeFieldOffset f{ "APrimalStructure.ForcePreventPlacingInOfflineRaidStructuresRadius" }; return *GetNativePointerField<float*>(this, f); }
	FName& AttachToStaticMeshSocketNameBaseField() { static NativeFieldOffset f{ "APrimalStructure.AttachToStaticMeshSocketNameBase" }; return *GetNativePointerField<FName*>(this, f); }
	TSubclassOf<UPrimalHarvestingComponent>& StructureHarvestingComponentField() { static NativeFieldOffset f{ "APrimalStructure.StructureHarvestingComponent" }; return *GetNativePointerField<TSubclassOf<UPrimalHarvestingComponent>*>(this, f); }
	UPrimalHarvestingComponent* MyStructureHarvestingComponentField() { static NativeFieldOffset f{ "APrimalStructure.MyStructureHarvestingComponent" }; return *GetNativePointerField<UPrimalHarvestingComponent**>(this, f); }
	TSubclassOf<AActor>& ItemsUseAlternateActorClassAttachmentField() { static NativeFieldOffset f{ "APrimalStructure.ItemsUseAlternateActorClassAttachment" }; return *GetNativePointerField<TSubclassOf<AActor>*>(this, f); }
	float& UnstasisAutoDestroyAfterTimeField() { static NativeFieldOffset f{ "APrimalStructure.UnstasisAutoDestroyAfterTime" }; return *GetNativePointerField<float*>(this, f); }
	unsigned char& TribeGroupStructureRankField() { static NativeFieldOffset f{ "APrimalStructure.TribeGroupStructureRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& TribeRankHUDYOffsetField() { static NativeFieldOffset f{ "APrimalStructure.TribeRankHUDYOffset" }; return *GetNativePointerField<unsigned char*>(this, f); }
	TArray<TSubclassOf<APrimalDinoCharacter>>& PreventSaddleDinoClassesField() { static NativeFieldOffset f{ "APrimalStructure.PreventSaddleDinoClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalDinoCharacter>>*>(this, f); }
	TArray<TSubclassOf<APrimalDinoCharacter>>& AllowSaddleDinoClassesField() { static NativeFieldOffset f{ "APrimalStructure.AllowSaddleDinoClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalDinoCharacter>>*>(this, f); }
	FName& PlaceOnWallUseStaticMeshTagField() { static NativeFieldOffset f{ "APrimalStructure.PlaceOnWallUseStaticMeshTag" }; return *GetNativePointerField<FName*>(this, f); }
	TSubclassOf<APrimalStructure>& SnapStructureClassField() { static NativeFieldOffset f{ "APrimalStructure.SnapStructureClass" }; return *GetNativePointerField<TSubclassOf<APrimalStructure>*>(this, f); }
	float& DemolishActivationTimeField() { static NativeFieldOffset f{ "APrimalStructure.DemolishActivationTime" }; return *GetNativePointerField<float*>(this, f); }
	FVector& GroundEncroachmentCheckLocationOffsetField() { static NativeFieldOffset f{ "APrimalStructure.GroundEncroachmentCheckLocationOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	int& StructureMinAllowedVersionField() { static NativeFieldOffset f{ "APrimalStructure.StructureMinAllowedVersion" }; return *GetNativePointerField<int*>(this, f); }
	int& SavedStructureMinAllowedVersionField() { static NativeFieldOffset f{ "APrimalStructure.SavedStructureMinAllowedVersion" }; return *GetNativePointerField<int*>(this, f); }
	float& OverrideEnemyFoundationPreventionRadiusField() { static NativeFieldOffset f{ "APrimalStructure.OverrideEnemyFoundationPreventionRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& ExpandEnemyFoundationPreventionRadiusField() { static NativeFieldOffset f{ "APrimalStructure.ExpandEnemyFoundationPreventionRadius" }; return *GetNativePointerField<float*>(this, f); }
	int& BedIDField() { static NativeFieldOffset f{ "APrimalStructure.BedID" }; return *GetNativePointerField<int*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& ForceAllowWallAttachmentClassesField() { static NativeFieldOffset f{ "APrimalStructure.ForceAllowWallAttachmentClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	float& LimitMaxStructuresInRangeRadiusField() { static NativeFieldOffset f{ "APrimalStructure.LimitMaxStructuresInRangeRadius" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TSubclassOf<APrimalStructure>>& FastDecayLinkedStructureClassesField() { static NativeFieldOffset f{ "APrimalStructure.FastDecayLinkedStructureClasses" }; return *GetNativePointerField<TArray<TSubclassOf<APrimalStructure>>*>(this, f); }
	float& PlacementMaxZAbovePlayerHeightField() { static NativeFieldOffset f{ "APrimalStructure.PlacementMaxZAbovePlayerHeight" }; return *GetNativePointerField<float*>(this, f); }
	TArray<USceneComponent*>& OverrideTargetComponentsField() { static NativeFieldOffset f{ "APrimalStructure.OverrideTargetComponents" }; return *GetNativePointerField<TArray<USceneComponent*>*>(this, f); }
	float& OverrideApproachRadiusField() { static NativeFieldOffset f{ "APrimalStructure.OverrideApproachRadius" }; return *GetNativePointerField<float*>(this, f); }
	AMissionType* OwnerMissionField() { static NativeFieldOffset f{ "APrimalStructure.OwnerMission" }; return *GetNativePointerField<AMissionType**>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bIsFlippable() { static NativeBitField f{ "APrimalStructure.bIsFlippable" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFlipped() { static NativeBitField f{ "APrimalStructure.bIsFlipped" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bShowInPlaceableList() { static NativeBitField f{ "APrimalStructure.bShowInPlaceableList" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsRepairing() { static NativeBitField f{ "APrimalStructure.bIsRepairing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInitializedMaterials() { static NativeBitField f{ "APrimalStructure.bInitializedMaterials" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowWallAttachments() { static NativeBitField f{ "APrimalStructure.bForceAllowWallAttachments" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPRefreshedStructureColors() { static NativeBitField f{ "APrimalStructure.bUseBPRefreshedStructureColors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsBed() { static NativeBitField f{ "APrimalStructure.bIsBed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bClientAddPlacedOnFloorStructures() { static NativeBitField f{ "APrimalStructure.bClientAddPlacedOnFloorStructures" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventStasis() { static NativeBitField f{ "APrimalStructure.bUseBPPreventStasis" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOnStasis() { static NativeBitField f{ "APrimalStructure.bDestroyOnStasis" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTriggerBPStasis() { static NativeBitField f{ "APrimalStructure.bTriggerBPStasis" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPostLoadedFromSaveGame() { static NativeBitField f{ "APrimalStructure.bUseBPPostLoadedFromSaveGame" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPlacementUsesWeaponClipAmmo() { static NativeBitField f{ "APrimalStructure.bPlacementUsesWeaponClipAmmo" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreDyingWhenDemolished() { static NativeBitField f{ "APrimalStructure.bIgnoreDyingWhenDemolished" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAbsoluteTakeAnythingAsGround() { static NativeBitField f{ "APrimalStructure.bAbsoluteTakeAnythingAsGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisablePlacementOnDynamicsFoliageAndDoors() { static NativeBitField f{ "APrimalStructure.bDisablePlacementOnDynamicsFoliageAndDoors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSeatedDisableCollisionCheck() { static NativeBitField f{ "APrimalStructure.bSeatedDisableCollisionCheck" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPIsAllowedToBuildEx() { static NativeBitField f{ "APrimalStructure.bUseBPIsAllowedToBuildEx" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPHandleStructureEnabled() { static NativeBitField f{ "APrimalStructure.bUseBPHandleStructureEnabled" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePlacingOnVerticalGround() { static NativeBitField f{ "APrimalStructure.bForcePlacingOnVerticalGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPlacementShouldNotBeHorizontal() { static NativeBitField f{ "APrimalStructure.bPlacementShouldNotBeHorizontal" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresGroundedPlacement() { static NativeBitField f{ "APrimalStructure.bRequiresGroundedPlacement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowPlacingOnOtherTeamStructuresPvPOnly() { static NativeBitField f{ "APrimalStructure.bAllowPlacingOnOtherTeamStructuresPvPOnly" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceUseSkeletalMeshComponent() { static NativeBitField f{ "APrimalStructure.bForceUseSkeletalMeshComponent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> UseBPOverrideTargetLocation() { static NativeBitField f{ "APrimalStructure.UseBPOverrideTargetLocation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOverrideFoundationSupportDistance() { static NativeBitField f{ "APrimalStructure.bOverrideFoundationSupportDistance" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceDisableFootSound() { static NativeBitField f{ "APrimalStructure.bForceDisableFootSound" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTraceThruEncroachmentPoints() { static NativeBitField f{ "APrimalStructure.bTraceThruEncroachmentPoints" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDidSpawnEffects() { static NativeBitField f{ "APrimalStructure.bDidSpawnEffects" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventDinoPlacementDistanceIncrease() { static NativeBitField f{ "APrimalStructure.bPreventDinoPlacementDistanceIncrease" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPendingRemoval() { static NativeBitField f{ "APrimalStructure.bPendingRemoval" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDontOverrideCollisionProfile() { static NativeBitField f{ "APrimalStructure.bDontOverrideCollisionProfile" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseAdvancedRotationPlacement() { static NativeBitField f{ "APrimalStructure.bUseAdvancedRotationPlacement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPlacingPlayerStructure() { static NativeBitField f{ "APrimalStructure.bIsPlacingPlayerStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRootFoundationLimitBuildArea() { static NativeBitField f{ "APrimalStructure.bRootFoundationLimitBuildArea" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCenterOffscreenFloatingHUDWidgets() { static NativeBitField f{ "APrimalStructure.bCenterOffscreenFloatingHUDWidgets" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowAttachToPawn() { static NativeBitField f{ "APrimalStructure.bAllowAttachToPawn" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowAttachToSaddle() { static NativeBitField f{ "APrimalStructure.bAllowAttachToSaddle" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPlacementTraceIgnorePawns() { static NativeBitField f{ "APrimalStructure.bPlacementTraceIgnorePawns" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequireFreePrimarySnappedStructure() { static NativeBitField f{ "APrimalStructure.bRequireFreePrimarySnappedStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyAllowPlacementInWater() { static NativeBitField f{ "APrimalStructure.bOnlyAllowPlacementInWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePlacingOnGround() { static NativeBitField f{ "APrimalStructure.bForcePlacingOnGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTakeAnythingAsGround() { static NativeBitField f{ "APrimalStructure.bTakeAnythingAsGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFoundation() { static NativeBitField f{ "APrimalStructure.bIsFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceCheckNearbyEnemyFoundation() { static NativeBitField f{ "APrimalStructure.bForceCheckNearbyEnemyFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFloor() { static NativeBitField f{ "APrimalStructure.bIsFloor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceFloorCollisionGroup() { static NativeBitField f{ "APrimalStructure.bForceFloorCollisionGroup" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsWall() { static NativeBitField f{ "APrimalStructure.bIsWall" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisallowPreventCropsBiomes() { static NativeBitField f{ "APrimalStructure.bDisallowPreventCropsBiomes" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanBeRepaired() { static NativeBitField f{ "APrimalStructure.bCanBeRepaired" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReturnDamageOnHitFromPawn() { static NativeBitField f{ "APrimalStructure.bReturnDamageOnHitFromPawn" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventStasis() { static NativeBitField f{ "APrimalStructure.bPreventStasis" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowUseFromRidingDino() { static NativeBitField f{ "APrimalStructure.bAllowUseFromRidingDino" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsFenceFoundation() { static NativeBitField f{ "APrimalStructure.bIsFenceFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseFenceFoundation() { static NativeBitField f{ "APrimalStructure.bUseFenceFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseOnlyBlockSelfTraceChannel() { static NativeBitField f{ "APrimalStructure.bUseOnlyBlockSelfTraceChannel" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bWasPlacementSnapped() { static NativeBitField f{ "APrimalStructure.bWasPlacementSnapped" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsCoreStructure() { static NativeBitField f{ "APrimalStructure.bIsCoreStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDeprecateStructure() { static NativeBitField f{ "APrimalStructure.bDeprecateStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresToBeInsideZoneVolume() { static NativeBitField f{ "APrimalStructure.bRequiresToBeInsideZoneVolume" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowLoadBearing() { static NativeBitField f{ "APrimalStructure.bAllowLoadBearing" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsEnvironmentStructure() { static NativeBitField f{ "APrimalStructure.bIsEnvironmentStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDemolished() { static NativeBitField f{ "APrimalStructure.bDemolished" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSetStaticMobility() { static NativeBitField f{ "APrimalStructure.bSetStaticMobility" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPvE() { static NativeBitField f{ "APrimalStructure.bIsPvE" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBeginPlayIgnoreApplyScale() { static NativeBitField f{ "APrimalStructure.bBeginPlayIgnoreApplyScale" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnVariantSwitch() { static NativeBitField f{ "APrimalStructure.bUseBPOnVariantSwitch" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresPlacementOnStructureFloors() { static NativeBitField f{ "APrimalStructure.bRequiresPlacementOnStructureFloors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisablePlacementOnStructureFloors() { static NativeBitField f{ "APrimalStructure.bDisablePlacementOnStructureFloors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyStructureIfFloorDestroyed() { static NativeBitField f{ "APrimalStructure.bDestroyStructureIfFloorDestroyed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsePlacementCollisionCheck() { static NativeBitField f{ "APrimalStructure.bUsePlacementCollisionCheck" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresSnapping() { static NativeBitField f{ "APrimalStructure.bRequiresSnapping" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSnappingRequiresNearbyFoundation() { static NativeBitField f{ "APrimalStructure.bSnappingRequiresNearbyFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowSnapRotation() { static NativeBitField f{ "APrimalStructure.bAllowSnapRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAllowSnapRotationForStructure() { static NativeBitField f{ "APrimalStructure.bUseBPAllowSnapRotationForStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPlacementChooseRotation() { static NativeBitField f{ "APrimalStructure.bPlacementChooseRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresPlacingOnWall() { static NativeBitField f{ "APrimalStructure.bRequiresPlacingOnWall" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSnapRequiresPlacementOnGround() { static NativeBitField f{ "APrimalStructure.bSnapRequiresPlacementOnGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowSnapOntoSameLocation() { static NativeBitField f{ "APrimalStructure.bAllowSnapOntoSameLocation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyFoundationIfSnappedToFoundation() { static NativeBitField f{ "APrimalStructure.bOnlyFoundationIfSnappedToFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bFoundationRequiresGroundTrace() { static NativeBitField f{ "APrimalStructure.bFoundationRequiresGroundTrace" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPlacingOnGroundRequiresNoStructure() { static NativeBitField f{ "APrimalStructure.bPlacingOnGroundRequiresNoStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTakeGroundNormal() { static NativeBitField f{ "APrimalStructure.bTakeGroundNormal" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTakeGroundNormalDirectly() { static NativeBitField f{ "APrimalStructure.bTakeGroundNormalDirectly" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bFinalPlacementDontAdjustForMaxRange() { static NativeBitField f{ "APrimalStructure.bFinalPlacementDontAdjustForMaxRange" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowStructureColors() { static NativeBitField f{ "APrimalStructure.bAllowStructureColors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDebug() { static NativeBitField f{ "APrimalStructure.bDebug" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseFadeInEffect() { static NativeBitField f{ "APrimalStructure.bUseFadeInEffect" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsingStructureColors() { static NativeBitField f{ "APrimalStructure.bUsingStructureColors" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventDefaultVariant() { static NativeBitField f{ "APrimalStructure.bPreventDefaultVariant" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsSPlusStructure() { static NativeBitField f{ "APrimalStructure.bIsSPlusStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowPickingUpStructureAfterPlacement() { static NativeBitField f{ "APrimalStructure.bAllowPickingUpStructureAfterPlacement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisablePickingUpStructureAfterPlacementOnTryMultiUse() { static NativeBitField f{ "APrimalStructure.bDisablePickingUpStructureAfterPlacementOnTryMultiUse" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsesHealth() { static NativeBitField f{ "APrimalStructure.bUsesHealth" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreSnappedToOtherFloorStructures() { static NativeBitField f{ "APrimalStructure.bIgnoreSnappedToOtherFloorStructures" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bEnforceStructureLinkExactRotation() { static NativeBitField f{ "APrimalStructure.bEnforceStructureLinkExactRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceSnappedStructureToGround() { static NativeBitField f{ "APrimalStructure.bForceSnappedStructureToGround" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceBlockIK() { static NativeBitField f{ "APrimalStructure.bForceBlockIK" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bStationaryStructure() { static NativeBitField f{ "APrimalStructure.bStationaryStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnorePawns() { static NativeBitField f{ "APrimalStructure.bIgnorePawns" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanDemolish() { static NativeBitField f{ "APrimalStructure.bCanDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowPlacingOnOtherTeamStructures() { static NativeBitField f{ "APrimalStructure.bAllowPlacingOnOtherTeamStructures" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventPlacementInWater() { static NativeBitField f{ "APrimalStructure.bPreventPlacementInWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowInRegularStructurePreventionZones() { static NativeBitField f{ "APrimalStructure.bAllowInRegularStructurePreventionZones" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDontSetStructureCollisionChannels() { static NativeBitField f{ "APrimalStructure.bDontSetStructureCollisionChannels" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventEnemyStructuresNearby() { static NativeBitField f{ "APrimalStructure.bForcePreventEnemyStructuresNearby" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowEnemyDemolish() { static NativeBitField f{ "APrimalStructure.bAllowEnemyDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDontActuallySnapJustPlacement() { static NativeBitField f{ "APrimalStructure.bDontActuallySnapJustPlacement" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreMaxStructuresInRange() { static NativeBitField f{ "APrimalStructure.bIgnoreMaxStructuresInRange" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPaintingUseSkeletalMesh() { static NativeBitField f{ "APrimalStructure.bPaintingUseSkeletalMesh" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsesPaintingComponent() { static NativeBitField f{ "APrimalStructure.bUsesPaintingComponent" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanBuildUpon() { static NativeBitField f{ "APrimalStructure.bCanBuildUpon" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHasResetDecayTime() { static NativeBitField f{ "APrimalStructure.bHasResetDecayTime" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowInPreventionVolumes() { static NativeBitField f{ "APrimalStructure.bForceAllowInPreventionVolumes" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceCreateDynamicMaterials() { static NativeBitField f{ "APrimalStructure.bForceCreateDynamicMaterials" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetInfoFromConsumedItemForPlacedStructure() { static NativeBitField f{ "APrimalStructure.bUseBPGetInfoFromConsumedItemForPlacedStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bImmuneToAutoDemolish() { static NativeBitField f{ "APrimalStructure.bImmuneToAutoDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreMaxStructuresInSmallRadius() { static NativeBitField f{ "APrimalStructure.bIgnoreMaxStructuresInSmallRadius" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowTargetingByCorruptDinos() { static NativeBitField f{ "APrimalStructure.bAllowTargetingByCorruptDinos" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPTreatAsFoundationForSnappedStructure() { static NativeBitField f{ "APrimalStructure.bUseBPTreatAsFoundationForSnappedStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnStructurePickup() { static NativeBitField f{ "APrimalStructure.bUseBPOnStructurePickup" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPerInstanceSnapPoints() { static NativeBitField f{ "APrimalStructure.bPerInstanceSnapPoints" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSnapToWaterSurface() { static NativeBitField f{ "APrimalStructure.bSnapToWaterSurface" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOnStasisUnlessPrevented() { static NativeBitField f{ "APrimalStructure.bDestroyOnStasisUnlessPrevented" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventAttachToSaddle() { static NativeBitField f{ "APrimalStructure.bPreventAttachToSaddle" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePersonalStructureOwnership() { static NativeBitField f{ "APrimalStructure.bForcePersonalStructureOwnership" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideAllowStructureAccess() { static NativeBitField f{ "APrimalStructure.bBPOverrideAllowStructureAccess" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverideDemolish() { static NativeBitField f{ "APrimalStructure.bBPOverideDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnDemolish() { static NativeBitField f{ "APrimalStructure.bUseBPOnDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideAllowSnappingWith() { static NativeBitField f{ "APrimalStructure.bBPOverrideAllowSnappingWith" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideAllowSnappingWithButAlsoCallSuper() { static NativeBitField f{ "APrimalStructure.bBPOverrideAllowSnappingWithButAlsoCallSuper" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnLinkedStructureDestroyed() { static NativeBitField f{ "APrimalStructure.bUseBPOnLinkedStructureDestroyed" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseTribeGroupStructureRank() { static NativeBitField f{ "APrimalStructure.bUseTribeGroupStructureRank" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceBlockStationaryTraces() { static NativeBitField f{ "APrimalStructure.bForceBlockStationaryTraces" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAttachToStaticMeshSocket() { static NativeBitField f{ "APrimalStructure.bAttachToStaticMeshSocket" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAttachToStaticMeshSocketRotation() { static NativeBitField f{ "APrimalStructure.bAttachToStaticMeshSocketRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceGroundForFoundation() { static NativeBitField f{ "APrimalStructure.bForceGroundForFoundation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideSnappedToTransform() { static NativeBitField f{ "APrimalStructure.bBPOverrideSnappedToTransform" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideSnappedFromTransform() { static NativeBitField f{ "APrimalStructure.bBPOverrideSnappedFromTransform" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOverridePlacementRotation() { static NativeBitField f{ "APrimalStructure.bBPOverridePlacementRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisableStructureOnElectricStorm() { static NativeBitField f{ "APrimalStructure.bDisableStructureOnElectricStorm" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bNoCollision() { static NativeBitField f{ "APrimalStructure.bNoCollision" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCreatedDynamicMaterials() { static NativeBitField f{ "APrimalStructure.bCreatedDynamicMaterials" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPreviewStructure() { static NativeBitField f{ "APrimalStructure.bIsPreviewStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bStructureUseAltCollisionChannel() { static NativeBitField f{ "APrimalStructure.bStructureUseAltCollisionChannel" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDemolishJustDestroy() { static NativeBitField f{ "APrimalStructure.bDemolishJustDestroy" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHighPriorityDemolish() { static NativeBitField f{ "APrimalStructure.bHighPriorityDemolish" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisableSnapStructure() { static NativeBitField f{ "APrimalStructure.bDisableSnapStructure" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bTriggerBPUnstasis() { static NativeBitField f{ "APrimalStructure.bTriggerBPUnstasis" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBlueprintDrawHUD() { static NativeBitField f{ "APrimalStructure.bBlueprintDrawHUD" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBlueprintDrawPreviewHUD() { static NativeBitField f{ "APrimalStructure.bBlueprintDrawPreviewHUD" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUsesWorldSpaceMaterial() { static NativeBitField f{ "APrimalStructure.bUsesWorldSpaceMaterial" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceIgnoreStationaryObjectTrace() { static NativeBitField f{ "APrimalStructure.bForceIgnoreStationaryObjectTrace" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowNearSupplyCrateSpawns() { static NativeBitField f{ "APrimalStructure.bForceAllowNearSupplyCrateSpawns" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPPostSetStructureCollisionChannels() { static NativeBitField f{ "APrimalStructure.bBPPostSetStructureCollisionChannels" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPickupGiveItemRequiresAccess() { static NativeBitField f{ "APrimalStructure.bPickupGiveItemRequiresAccess" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAllowPickupGiveItem() { static NativeBitField f{ "APrimalStructure.bUseBPAllowPickupGiveItem" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventAttachedChildStructures() { static NativeBitField f{ "APrimalStructure.bPreventAttachedChildStructures" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventPreviewIfWeaponPlaced() { static NativeBitField f{ "APrimalStructure.bPreventPreviewIfWeaponPlaced" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bStructuresInRangeTypeFlagUseAltCollisionChannel() { static NativeBitField f{ "APrimalStructure.bStructuresInRangeTypeFlagUseAltCollisionChannel" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsDrawingHUDPickupTimer() { static NativeBitField f{ "APrimalStructure.bIsDrawingHUDPickupTimer" }; return { this, f }; }

	// Functions

	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructure.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructure.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	UObject* GetUObjectInterfaceDataListEntryInterface() { static NativeFunction f{ "APrimalStructure.GetUObjectInterfaceDataListEntryInterface" }; return NativeCall<UObject*>(this, f); }
	FRotator* GetPlayerSpawnRotation(FRotator* result) { static NativeFunction f{ "APrimalStructure.GetPlayerSpawnRotation" }; return NativeCall<FRotator*, FRotator*>(this, f, result); }
	void SetBoundsScale(float NewScale) { static NativeFunction f{ "APrimalStructure.SetBoundsScale" }; NativeCall<void, float>(this, f, NewScale); }
	void SetContainerActive(bool reset) { static NativeFunction f{ "APrimalStructure.SetContainerActive" }; NativeCall<void, bool>(this, f, reset); }
	int GetHitPawnCollisionGroup() { static NativeFunction f{ "APrimalStructure.GetHitPawnCollisionGroup" }; return NativeCall<int>(this, f); }
	void PreInitializeComponents() { static NativeFunction f{ "APrimalStructure.PreInitializeComponents" }; NativeCall<void>(this, f); }
	void BeginPlay() { static NativeFunction f{ "APrimalStructure.BeginPlay" }; NativeCall<void>(this, f); }
	void DestroyByMeshing() { static NativeFunction f{ "APrimalStructure.DestroyByMeshing" }; NativeCall<void>(this, f); }
	void ApplyPrimalItemSettingsToStructure(UMeshComponent* meshToColorize, UPrimalItem* AssociatedPrimalItem) { static NativeFunction f{ "APrimalStructure.ApplyPrimalItemSettingsToStructure" }; NativeCall<void, UMeshComponent*, UPrimalItem*>(this, f, meshToColorize, AssociatedPrimalItem); }
	void SetLinkedIDs() { static NativeFunction f{ "APrimalStructure.SetLinkedIDs" }; NativeCall<void>(this, f); }
	void ApplyLinkedIDs(bool bRelinkParents) { static NativeFunction f{ "APrimalStructure.ApplyLinkedIDs" }; NativeCall<void, bool>(this, f, bRelinkParents); }
	static APrimalStructure* GetFromID(UWorld* World, unsigned int TheStructureID) { static NativeFunction f{ "APrimalStructure.GetFromID" }; return NativeCall<APrimalStructure*, UWorld*, unsigned int>(nullptr, f, World, TheStructureID); }
	static APrimalStructure* BPGetFromID(UWorld* World, int TheStructureID) { static NativeFunction f{ "APrimalStructure.BPGetFromID" }; return NativeCall<APrimalStructure*, UWorld*, int>(nullptr, f, World, TheStructureID); }
	static int BPGetStructureID(APrimalStructure* PrimalStructure) { static NativeFunction f{ "APrimalStructure.BPGetStructureID" }; return NativeCall<int, APrimalStructure*>(nullptr, f, PrimalStructure); }
	void OnRep_AttachmentReplication() { static NativeFunction f{ "APrimalStructure.OnRep_AttachmentReplication" }; NativeCall<void>(this, f); }
	void SetDinoSaddleAttachment(APrimalDinoCharacter* myDino, FName BoneName, FVector RelLoc, FRotator RelRot, bool bMaintainWorldPosition) { static NativeFunction f{ "APrimalStructure.SetDinoSaddleAttachment" }; NativeCall<void, APrimalDinoCharacter*, FName, FVector, FRotator, bool>(this, f, myDino, BoneName, RelLoc, RelRot, bMaintainWorldPosition); }
	void PostSpawnInitialize() { static NativeFunction f{ "APrimalStructure.PostSpawnInitialize()" }; NativeCall<void>(this, f); }
	void LoadedFromSaveGame() { static NativeFunction f{ "APrimalStructure.LoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void SetStructureCollisionChannels() { static NativeFunction f{ "APrimalStructure.SetStructureCollisionChannels" }; NativeCall<void>(this, f); }
	void ApplyScale(bool bOnlyInitPhysics) { static NativeFunction f{ "APrimalStructure.ApplyScale" }; NativeCall<void, bool>(this, f, bOnlyInitPhysics); }
	void PostSpawnInitialize(FVector* SpawnLocation, FRotator* SpawnRotation, AActor* InOwner, APawn* InInstigator, bool bRemoteOwned, bool bNoFail, bool bDeferConstruction, bool bDeferBeginPlay) { static NativeFunction f{ "APrimalStructure.PostSpawnInitialize(const FVector&,const FRotator&,AActor*,APawn*,bool,bool,bool,bool)" }; NativeCall<void, FVector*, FRotator*, AActor*, APawn*, bool, bool, bool, bool>(this, f, SpawnLocation, SpawnRotation, InOwner, InInstigator, bRemoteOwned, bNoFail, bDeferConstruction, bDeferBeginPlay); }
	bool UseDynamicMobility() { static NativeFunction f{ "APrimalStructure.UseDynamicMobility" }; return NativeCall<bool>(this, f); }
	void SetStaticMobility() { static NativeFunction f{ "APrimalStructure.SetStaticMobility" }; NativeCall<void>(this, f); }
	bool IsLinkedToWaterOrPowerSource() { static NativeFunction f{ "APrimalStructure.IsLinkedToWaterOrPowerSource" }; return NativeCall<bool>(this, f); }
	void PrepareAsPlacementPreview() { static NativeFunction f{ "APrimalStructure.PrepareAsPlacementPreview" }; NativeCall<void>(this, f); }
	bool TickPlacingStructure(APrimalStructurePlacer* PlacerActor, float DeltaTime) { static NativeFunction f{ "APrimalStructure.TickPlacingStructure" }; return NativeCall<bool, APrimalStructurePlacer*, float>(this, f, PlacerActor, DeltaTime); }
	FString* GetDebugInfoString(FString* result) { static NativeFunction f{ "APrimalStructure.GetDebugInfoString" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool ShouldInstance(UProperty* Property) { static NativeFunction f{ "APrimalStructure.ShouldInstance" }; return NativeCall<bool, UProperty*>(this, f, Property); }
	int IsAllowedToBuild(APlayerController* PC, FVector AtLocation, FRotator AtRotation, FPlacementData* OutPlacementData, bool bDontAdjustForMaxRange, FRotator PlayerViewRotation, bool bFinalPlacement) { static NativeFunction f{ "APrimalStructure.IsAllowedToBuild" }; return NativeCall<int, APlayerController*, FVector, FRotator, FPlacementData*, bool, FRotator, bool>(this, f, PC, AtLocation, AtRotation, OutPlacementData, bDontAdjustForMaxRange, PlayerViewRotation, bFinalPlacement); }
	static bool IsPointNearSupplyCrateSpawn(UWorld* theWorld, FVector AtPoint) { static NativeFunction f{ "APrimalStructure.IsPointNearSupplyCrateSpawn" }; return NativeCall<bool, UWorld*, FVector>(nullptr, f, theWorld, AtPoint); }
	TSubclassOf<APrimalStructure>* GetBedFilterClass_Implementation(TSubclassOf<APrimalStructure>* result) { static NativeFunction f{ "APrimalStructure.GetBedFilterClass_Implementation" }; return NativeCall<TSubclassOf<APrimalStructure>*, TSubclassOf<APrimalStructure>*>(this, f, result); }
	FSpawnPointInfo* GetSpawnPointInfo(FSpawnPointInfo* result) { static NativeFunction f{ "APrimalStructure.GetSpawnPointInfo" }; return NativeCall<FSpawnPointInfo*, FSpawnPointInfo*>(this, f, result); }
	void PostInitializeComponents() { static NativeFunction f{ "APrimalStructure.PostInitializeComponents" }; NativeCall<void>(this, f); }
	bool AllowSpawnForPlayer(AShooterPlayerController* PC, bool bCheckCooldownTime, APrimalStructure* FromStructure) { static NativeFunction f{ "APrimalStructure.AllowSpawnForPlayer" }; return NativeCall<bool, AShooterPlayerController*, bool, APrimalStructure*>(this, f, PC, bCheckCooldownTime, FromStructure); }
	void NetUpdateOriginalOwnerNameAndID_Implementation(int NewOriginalOwnerID, FString* NewOriginalOwnerName) { static NativeFunction f{ "APrimalStructure.NetUpdateOriginalOwnerNameAndID_Implementation" }; NativeCall<void, int, FString*>(this, f, NewOriginalOwnerID, NewOriginalOwnerName); }
	void LinkStructure(APrimalStructure* NewLinkedStructure) { static NativeFunction f{ "APrimalStructure.LinkStructure" }; NativeCall<void, APrimalStructure*>(this, f, NewLinkedStructure); }
	void NonPlayerFinalStructurePlacement(int PlacementTargetingTeam, int PlacementOwningPlayerID, FString* PlacementOwningPlayerName, APrimalStructure* ForcePrimaryParent) { static NativeFunction f{ "APrimalStructure.NonPlayerFinalStructurePlacement" }; NativeCall<void, int, int, FString*, APrimalStructure*>(this, f, PlacementTargetingTeam, PlacementOwningPlayerID, PlacementOwningPlayerName, ForcePrimaryParent); }
	bool FinalStructurePlacement(APlayerController* PC, FVector AtLocation, FRotator AtRotation, FRotator PlayerViewRotation, APawn* AttachToPawn, FName BoneName, bool bIsFlipped) { static NativeFunction f{ "APrimalStructure.FinalStructurePlacement" }; return NativeCall<bool, APlayerController*, FVector, FRotator, FRotator, APawn*, FName, bool>(this, f, PC, AtLocation, AtRotation, PlayerViewRotation, AttachToPawn, BoneName, bIsFlipped); }
	FVector* GetSnapPointLocation(FVector* result, int SnapPointIndex, bool bOverrideTransform, FVector OverrideLoc, FRotator OverrideRot) { static NativeFunction f{ "APrimalStructure.GetSnapPointLocation" }; return NativeCall<FVector*, FVector*, int, bool, FVector, FRotator>(this, f, result, SnapPointIndex, bOverrideTransform, OverrideLoc, OverrideRot); }
	bool GetSnapToLocation(FVector* AtLoc, FRotator* AtRotation, FPlacementData* OutPlacementData, APrimalStructure** OutParentStructure, int* OutSnapToIndex, APlayerController* PC, bool bFinalPlacement, int SnapPointCycle) { static NativeFunction f{ "APrimalStructure.GetSnapToLocation" }; return NativeCall<bool, FVector*, FRotator*, FPlacementData*, APrimalStructure**, int*, APlayerController*, bool, int>(this, f, AtLoc, AtRotation, OutPlacementData, OutParentStructure, OutSnapToIndex, PC, bFinalPlacement, SnapPointCycle); }
	void GetSnapToParentStructures(FVector AtLocation, FRotator AtRotation, int InitialMySnapIndex, APrimalStructure* InitialParent, TArray<APrimalStructure*>* SnapToParentStructures, APlayerController* PC) { static NativeFunction f{ "APrimalStructure.GetSnapToParentStructures" }; NativeCall<void, FVector, FRotator, int, APrimalStructure*, TArray<APrimalStructure*>*, APlayerController*>(this, f, AtLocation, AtRotation, InitialMySnapIndex, InitialParent, SnapToParentStructures, PC); }
	bool GetPlacingGroundLocation(AActor** OutHitActor, FPlacementData* OutPlacementData, APlayerController* PC, bool bFinalPlacement, int SnapPointCycle, UPrimitiveComponent** OutComponent) { static NativeFunction f{ "APrimalStructure.GetPlacingGroundLocation" }; return NativeCall<bool, AActor**, FPlacementData*, APlayerController*, bool, int, UPrimitiveComponent**>(this, f, OutHitActor, OutPlacementData, PC, bFinalPlacement, SnapPointCycle, OutComponent); }
	bool ClampBuildLocation(FVector FromLocation, AActor** OutHitActor, FPlacementData* OutPlacementData, bool bDontAdjustForMaxRange, APlayerController* PC) { static NativeFunction f{ "APrimalStructure.ClampBuildLocation" }; return NativeCall<bool, FVector, AActor**, FPlacementData*, bool, APlayerController*>(this, f, FromLocation, OutHitActor, OutPlacementData, bDontAdjustForMaxRange, PC); }
	bool CheckNotEncroaching(FVector PlacementLocation, FRotator PlacementRotation, AActor* DinoCharacter, APrimalStructure* SnappedToParentStructure, APrimalStructure* ReplacesStructure, bool bUseAlternatePlacementTraceScale) { static NativeFunction f{ "APrimalStructure.CheckNotEncroaching" }; return NativeCall<bool, FVector, FRotator, AActor*, APrimalStructure*, APrimalStructure*, bool>(this, f, PlacementLocation, PlacementRotation, DinoCharacter, SnappedToParentStructure, ReplacesStructure, bUseAlternatePlacementTraceScale); }
	APrimalStructure* GetNearbyFoundation(FPlacementData* PlacementData, APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.GetNearbyFoundation" }; return NativeCall<APrimalStructure*, FPlacementData*, APlayerController*>(this, f, PlacementData, ForPC); }
	void NetSpawnCoreStructureDeathActor_Implementation() { static NativeFunction f{ "APrimalStructure.NetSpawnCoreStructureDeathActor_Implementation" }; NativeCall<void>(this, f); }
	float TakeDamage(float Damage, FDamageEvent* DamageEvent, AController* EventInstigator, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.TakeDamage" }; return NativeCall<float, float, FDamageEvent*, AController*, AActor*>(this, f, Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool Die(float KillingDamage, FDamageEvent* DamageEvent, AController* Killer, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.Die" }; return NativeCall<bool, float, FDamageEvent*, AController*, AActor*>(this, f, KillingDamage, DamageEvent, Killer, DamageCauser); }
	void PlayDying(float KillingDamage, FDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.PlayDying" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void DestroyStructuresPlacedOnFloor() { static NativeFunction f{ "APrimalStructure.DestroyStructuresPlacedOnFloor" }; NativeCall<void>(this, f); }
	static void ReprocessTree(TArray<APrimalStructure*>* StartingStructures, AController* InstigatorController, AActor* DamageCauser, bool bForceDestroy = false) { static NativeFunction f{ "APrimalStructure.ReprocessTree" }; NativeCall<void, TArray<APrimalStructure*>*, AController*, AActor*, bool>(nullptr, f, StartingStructures, InstigatorController, DamageCauser, bForceDestroy); }
	static void FindFoundations(TArray<APrimalStructure*>* StartingStructures, TArray<APrimalStructure*>* Foundations) { static NativeFunction f{ "APrimalStructure.FindFoundations(TArray<APrimalStructure*,FDefaultAllocator>&,TArray<APrimalStructure*,FDefaultAllocator>&)" }; NativeCall<void, TArray<APrimalStructure*>*, TArray<APrimalStructure*>*>(nullptr, f, StartingStructures, Foundations); }
	static void FindFoundations(APrimalStructure* StartingStructure, TArray<APrimalStructure*>* Foundations) { static NativeFunction f{ "APrimalStructure.FindFoundations(APrimalStructure*,TArray<APrimalStructure*,FDefaultAllocator>&)" }; NativeCall<void, APrimalStructure*, TArray<APrimalStructure*>*>(nullptr, f, StartingStructure, Foundations); }
	static void CullAgainstFoundations(TArray<APrimalStructure*>* StartingStructures, TArray<APrimalStructure*>* Foundations) { static NativeFunction f{ "APrimalStructure.CullAgainstFoundations(TArray<APrimalStructure*,FDefaultAllocator>&,TArray<APrimalStructure*,FDefaultAllocator>&)" }; NativeCall<void, TArray<APrimalStructure*>*, TArray<APrimalStructure*>*>(nullptr, f, StartingStructures, Foundations); }
	static bool CullAgainstFoundations(APrimalStructure** StartingStructure, TArray<APrimalStructure*>* Foundations) { static NativeFunction f{ "APrimalStructure.CullAgainstFoundations(APrimalStructure*&,TArray<APrimalStructure*,FDefaultAllocator>&)" }; return NativeCall<bool, APrimalStructure**, TArray<APrimalStructure*>*>(nullptr, f, StartingStructure, Foundations); }
	static void FlagConnectionsLessThan(TArray<APrimalStructure*>* Structures, int Connections, TArray<APrimalStructure*>* StructuresToDestroy) { static NativeFunction f{ "APrimalStructure.FlagConnectionsLessThan(TArray<APrimalStructure*,FDefaultAllocator>&,int,TArray<APrimalStructure*,FDefaultAllocator>&)" }; NativeCall<void, TArray<APrimalStructure*>*, int, TArray<APrimalStructure*>*>(nullptr, f, Structures, Connections, StructuresToDestroy); }
	static void FlagConnectionsLessThan(APrimalStructure** StartingStructure, int Connections, TArray<APrimalStructure*>* StructuresToDestroy) { static NativeFunction f{ "APrimalStructure.FlagConnectionsLessThan(APrimalStructure*&,int,TArray<APrimalStructure*,FDefaultAllocator>&)" }; NativeCall<void, APrimalStructure**, int, TArray<APrimalStructure*>*>(nullptr, f, StartingStructure, Connections, StructuresToDestroy); }
	static void FlagReachable(TArray<APrimalStructure*>* Foundations) { static NativeFunction f{ "APrimalStructure.FlagReachable(TArray<APrimalStructure*,FDefaultAllocator>&)" }; NativeCall<void, TArray<APrimalStructure*>*>(nullptr, f, Foundations); }
	static void FlagReachable(APrimalStructure* StartingStructure) { static NativeFunction f{ "APrimalStructure.FlagReachable(APrimalStructure*)" }; NativeCall<void, APrimalStructure*>(nullptr, f, StartingStructure); }
	static void CleanUpTree(TArray<APrimalStructure*>* StartingStructures, AController* InstigatorController, AActor* DamageCauser, bool bForceDestroy = false) { static NativeFunction f{ "APrimalStructure.CleanUpTree(TArray<APrimalStructure*,FDefaultAllocator>&,AController*,AActor*,bool)" }; NativeCall<void, TArray<APrimalStructure*>*, AController*, AActor*, bool>(nullptr, f, StartingStructures, InstigatorController, DamageCauser, bForceDestroy); }
	static void CleanUpTree(APrimalStructure* StartingStructure, AController* InstigatorController, AActor* DamageCauser, unsigned int Depth = 0, bool bForceDestroy = false) { static NativeFunction f{ "APrimalStructure.CleanUpTree(APrimalStructure*,AController*,AActor*,unsigned int,bool)" }; NativeCall<void, APrimalStructure*, AController*, AActor*, unsigned int, bool>(nullptr, f, StartingStructure, InstigatorController, DamageCauser, Depth, bForceDestroy); }
	void RemoveLinkedStructure(APrimalStructure* Structure, AController* InstigatorController, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.RemoveLinkedStructure" }; NativeCall<void, APrimalStructure*, AController*, AActor*>(this, f, Structure, InstigatorController, DamageCauser); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructure.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	void OnRep_CurrentVariant() { static NativeFunction f{ "APrimalStructure.OnRep_CurrentVariant" }; NativeCall<void>(this, f); }
	void OnRep_StructureColors() { static NativeFunction f{ "APrimalStructure.OnRep_StructureColors" }; NativeCall<void>(this, f); }
	void RefreshStructureColors(UMeshComponent* ForceRefreshComponent) { static NativeFunction f{ "APrimalStructure.RefreshStructureColors" }; NativeCall<void, UMeshComponent*>(this, f, ForceRefreshComponent); }
	FLinearColor* GetStructureColorForID(FLinearColor* result, int SetNum, int ID) { static NativeFunction f{ "APrimalStructure.GetStructureColorForID" }; return NativeCall<FLinearColor*, FLinearColor*, int, int>(this, f, result, SetNum, ID); }
	bool Internal_IsInSnapChain(APrimalStructure* theStructure) { static NativeFunction f{ "APrimalStructure.Internal_IsInSnapChain" }; return NativeCall<bool, APrimalStructure*>(this, f, theStructure); }
	void GetAllLinkedStructures(TArray<APrimalStructure*>* OutLinkedStructures) { static NativeFunction f{ "APrimalStructure.GetAllLinkedStructures" }; NativeCall<void, TArray<APrimalStructure*>*>(this, f, OutLinkedStructures); }
	void BPGetAllLinkedStructures(TArray<APrimalStructure*>* OutLinkedStructures) { static NativeFunction f{ "APrimalStructure.BPGetAllLinkedStructures" }; NativeCall<void, TArray<APrimalStructure*>*>(this, f, OutLinkedStructures); }
	long double GetForceDemolishTime() { static NativeFunction f{ "APrimalStructure.GetForceDemolishTime" }; return NativeCall<long double>(this, f); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructure.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void ClientMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructure.ClientMultiUse" }; NativeCall<void, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void Demolish(APlayerController* ForPC, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.Demolish" }; NativeCall<void, APlayerController*, AActor*>(this, f, ForPC, DamageCauser); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalStructure.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	bool DoAnyTribePermissionsRestrict(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.DoAnyTribePermissionsRestrict" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	void DrawStructureTooltip(AShooterHUD* HUD, bool bForMultiUseSelector) { static NativeFunction f{ "APrimalStructure.DrawStructureTooltip" }; NativeCall<void, AShooterHUD*, bool>(this, f, HUD, bForMultiUseSelector); }
	void ChangeActorTeam(int NewTeam) { static NativeFunction f{ "APrimalStructure.ChangeActorTeam" }; NativeCall<void, int>(this, f, NewTeam); }
	void NetUpdateTeamAndOwnerName_Implementation(int NewTeam, FString* NewOwnerName) { static NativeFunction f{ "APrimalStructure.NetUpdateTeamAndOwnerName_Implementation" }; NativeCall<void, int, FString*>(this, f, NewTeam, NewOwnerName); }
	FString* GetDescriptiveName(FString* result) { static NativeFunction f{ "APrimalStructure.GetDescriptiveName" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool AllowSnapRotationForStructure(int ThisSnapPointIndex, APrimalStructure* OtherStructure, int OtherStructureSnapPointIndex) { static NativeFunction f{ "APrimalStructure.AllowSnapRotationForStructure" }; return NativeCall<bool, int, APrimalStructure*, int>(this, f, ThisSnapPointIndex, OtherStructure, OtherStructureSnapPointIndex); }
	void PlacedStructure(AShooterPlayerController* PC) { static NativeFunction f{ "APrimalStructure.PlacedStructure" }; NativeCall<void, AShooterPlayerController*>(this, f, PC); }
	void UpdatedHealth(bool bDoReplication) { static NativeFunction f{ "APrimalStructure.UpdatedHealth" }; NativeCall<void, bool>(this, f, bDoReplication); }
	void SetupDynamicMeshMaterials(UMeshComponent* meshComp) { static NativeFunction f{ "APrimalStructure.SetupDynamicMeshMaterials" }; NativeCall<void, UMeshComponent*>(this, f, meshComp); }
	void StartRepair() { static NativeFunction f{ "APrimalStructure.StartRepair" }; NativeCall<void>(this, f); }
	void RepairCheckTimer() { static NativeFunction f{ "APrimalStructure.RepairCheckTimer" }; NativeCall<void>(this, f); }
	void EndPlay(EEndPlayReason::Type EndPlayReason) { static NativeFunction f{ "APrimalStructure.EndPlay" }; NativeCall<void, EEndPlayReason::Type>(this, f, EndPlayReason); }
	void Stasis() { static NativeFunction f{ "APrimalStructure.Stasis" }; NativeCall<void>(this, f); }
	void Destroyed() { static NativeFunction f{ "APrimalStructure.Destroyed" }; NativeCall<void>(this, f); }
	void Unstasis() { static NativeFunction f{ "APrimalStructure.Unstasis" }; NativeCall<void>(this, f); }
	UPrimitiveComponent* GetPrimaryHitComponent() { static NativeFunction f{ "APrimalStructure.GetPrimaryHitComponent" }; return NativeCall<UPrimitiveComponent*>(this, f); }
	static void GetNearbyStructuresOfClass(UWorld* World, TSubclassOf<APrimalStructure> StructureClass, FVector* Location, float Range, TArray<APrimalStructure*>* Structures) { static NativeFunction f{ "APrimalStructure.GetNearbyStructuresOfClass" }; NativeCall<void, UWorld*, TSubclassOf<APrimalStructure>, FVector*, float, TArray<APrimalStructure*>*>(nullptr, f, World, StructureClass, Location, Range, Structures); }
	void ForceReplicateLinkedStructures() { static NativeFunction f{ "APrimalStructure.ForceReplicateLinkedStructures" }; NativeCall<void>(this, f); }
	void ClientUpdateLinkedStructures_Implementation(TArray<unsigned int>* NewLinkedStructures) { static NativeFunction f{ "APrimalStructure.ClientUpdateLinkedStructures_Implementation" }; NativeCall<void, TArray<unsigned int>*>(this, f, NewLinkedStructures); }
	bool AllowColoringBy(APlayerController* ForPC, UObject* anItem) { static NativeFunction f{ "APrimalStructure.AllowColoringBy" }; return NativeCall<bool, APlayerController*, UObject*>(this, f, ForPC, anItem); }
	void ServerRequestUseItemWithActor(APlayerController* ForPC, UObject* anItem, int AdditionalData) { static NativeFunction f{ "APrimalStructure.ServerRequestUseItemWithActor" }; NativeCall<void, APlayerController*, UObject*, int>(this, f, ForPC, anItem, AdditionalData); }
	void ApplyColorToRegions(__int16 CustomColorID, bool* ApplyToRegions) { static NativeFunction f{ "APrimalStructure.ApplyColorToRegions" }; NativeCall<void, __int16, bool*>(this, f, CustomColorID, ApplyToRegions); }
	bool IsNetRelevantFor(APlayerController* RealViewer, AActor* Viewer, FVector* SrcLocation) { static NativeFunction f{ "APrimalStructure.IsNetRelevantFor" }; return NativeCall<bool, APlayerController*, AActor*, FVector*>(this, f, RealViewer, Viewer, SrcLocation); }
	void NetDoSpawnEffects_Implementation() { static NativeFunction f{ "APrimalStructure.NetDoSpawnEffects_Implementation" }; NativeCall<void>(this, f); }
	void FadeInEffectTick() { static NativeFunction f{ "APrimalStructure.FadeInEffectTick" }; NativeCall<void>(this, f); }
	void ProcessEditText(AShooterPlayerController* ForPC, FString* TextToUse, bool bCheckedBox) { static NativeFunction f{ "APrimalStructure.ProcessEditText" }; NativeCall<void, AShooterPlayerController*, FString*, bool>(this, f, ForPC, TextToUse, bCheckedBox); }
	float AddAggroOnBump(APrimalDinoCharacter* BumpedBy) { static NativeFunction f{ "APrimalStructure.AddAggroOnBump" }; return NativeCall<float, APrimalDinoCharacter*>(this, f, BumpedBy); }
	int GetNumStructuresInRange(FVector AtLocation, float WithinRange) { static NativeFunction f{ "APrimalStructure.GetNumStructuresInRange" }; return NativeCall<int, FVector, float>(this, f, AtLocation, WithinRange); }
	static void GetStructuresInRange(UWorld* theWorld, FVector AtLocation, float WithinRange, TSubclassOf<APrimalStructure> StructureClass, TArray<APrimalStructure*>* StructuresOut, bool bUseInternalOctree, APrimalStructure* IgnoreStructure) { static NativeFunction f{ "APrimalStructure.GetStructuresInRange" }; NativeCall<void, UWorld*, FVector, float, TSubclassOf<APrimalStructure>, TArray<APrimalStructure*>*, bool, APrimalStructure*>(nullptr, f, theWorld, AtLocation, WithinRange, StructureClass, StructuresOut, bUseInternalOctree, IgnoreStructure); }
	static int GetNumStructuresInRangeStructureTypeFlag(UWorld* theWorld, FVector AtLocation, int TypeFlag, float WithinRange, bool bCheckBPCountStructureInRange, bool bUseInternalOctree, APrimalStructure* IgnoreStructure, bool bCheckWithAltCollisionChannel) { static NativeFunction f{ "APrimalStructure.GetNumStructuresInRangeStructureTypeFlag" }; return NativeCall<int, UWorld*, FVector, int, float, bool, bool, APrimalStructure*, bool>(nullptr, f, theWorld, AtLocation, TypeFlag, WithinRange, bCheckBPCountStructureInRange, bUseInternalOctree, IgnoreStructure, bCheckWithAltCollisionChannel); }
	bool AllowPickupForItem(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.AllowPickupForItem" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	bool CanPickupStructureFromRecentPlacement() { static NativeFunction f{ "APrimalStructure.CanPickupStructureFromRecentPlacement" }; return NativeCall<bool>(this, f); }
	void DisableStructurePickup() { static NativeFunction f{ "APrimalStructure.DisableStructurePickup" }; NativeCall<void>(this, f); }
	void MultiSetPickupAllowedBeforeNetworkTime_Implementation(long double NewTime) { static NativeFunction f{ "APrimalStructure.MultiSetPickupAllowedBeforeNetworkTime_Implementation" }; NativeCall<void, long double>(this, f, NewTime); }
	bool AllowSnappingWith(APrimalStructure* OtherStructure, APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.AllowSnappingWith" }; return NativeCall<bool, APrimalStructure*, APlayerController*>(this, f, OtherStructure, ForPC); }
	bool SetVariant(int VariantIndex, bool bForceSet) { static NativeFunction f{ "APrimalStructure.SetVariant" }; return NativeCall<bool, int, bool>(this, f, VariantIndex, bForceSet); }
	void RefreshVariantSettings(int NewVariantIndex) { static NativeFunction f{ "APrimalStructure.RefreshVariantSettings" }; NativeCall<void, int>(this, f, NewVariantIndex); }
	void MultiRefreshVariantSettings_Implementation(int NewVariantIndex) { static NativeFunction f{ "APrimalStructure.MultiRefreshVariantSettings_Implementation" }; NativeCall<void, int>(this, f, NewVariantIndex); }
	FStructureVariant* GetDefaultVariant(FStructureVariant* result) { static NativeFunction f{ "APrimalStructure.GetDefaultVariant" }; return NativeCall<FStructureVariant*, FStructureVariant*>(this, f, result); }
	bool AllowStructureAccess(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.AllowStructureAccess" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	static bool IsPointObstructedByWorldGeometry(UWorld* ForWorld, FVector ThePoint, bool bIgnoreTerrain, bool bOnlyCheckTerrain, bool bIgnoreFoliage, float OBSTRUCTION_CHECK_DIST) { static NativeFunction f{ "APrimalStructure.IsPointObstructedByWorldGeometry" }; return NativeCall<bool, UWorld*, FVector, bool, bool, bool, float>(nullptr, f, ForWorld, ThePoint, bIgnoreTerrain, bOnlyCheckTerrain, bIgnoreFoliage, OBSTRUCTION_CHECK_DIST); }
	bool CanBePainted() { static NativeFunction f{ "APrimalStructure.CanBePainted" }; return NativeCall<bool>(this, f); }
	UPaintingTexture* GetPaintingTexture() { static NativeFunction f{ "APrimalStructure.GetPaintingTexture" }; return NativeCall<UPaintingTexture*>(this, f); }
	APrimalStructureDoor* GetLinkedDoor() { static NativeFunction f{ "APrimalStructure.GetLinkedDoor" }; return NativeCall<APrimalStructureDoor*>(this, f); }
	FString* GetEntryString(FString* result) { static NativeFunction f{ "APrimalStructure.GetEntryString" }; return NativeCall<FString*, FString*>(this, f, result); }
	UTexture2D* GetEntryIcon(UObject* AssociatedDataObject, bool bIsEnabled) { static NativeFunction f{ "APrimalStructure.GetEntryIcon" }; return NativeCall<UTexture2D*, UObject*, bool>(this, f, AssociatedDataObject, bIsEnabled); }
	UMaterialInterface* GetEntryIconMaterial(UObject* AssociatedDataObject, bool bIsEnabled) { static NativeFunction f{ "APrimalStructure.GetEntryIconMaterial" }; return NativeCall<UMaterialInterface*, UObject*, bool>(this, f, AssociatedDataObject, bIsEnabled); }
	bool CanBeBaseForCharacter(APawn* Pawn) { static NativeFunction f{ "APrimalStructure.CanBeBaseForCharacter" }; return NativeCall<bool, APawn*>(this, f, Pawn); }
	UObject* GetObjectW() { static NativeFunction f{ "APrimalStructure.GetObjectW" }; return NativeCall<UObject*>(this, f); }
	FString* GetEntryDescription(FString* result) { static NativeFunction f{ "APrimalStructure.GetEntryDescription" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool PreventCharacterBasing(AActor* OtherActor, UPrimitiveComponent* BasedOnComponent) { static NativeFunction f{ "APrimalStructure.PreventCharacterBasing" }; return NativeCall<bool, AActor*, UPrimitiveComponent*>(this, f, OtherActor, BasedOnComponent); }
	void ClearCustomColors_Implementation() { static NativeFunction f{ "APrimalStructure.ClearCustomColors_Implementation" }; NativeCall<void>(this, f); }
	bool PreventPlacingOnFloorClass(TSubclassOf<APrimalStructure> FloorClass) { static NativeFunction f{ "APrimalStructure.PreventPlacingOnFloorClass" }; return NativeCall<bool, TSubclassOf<APrimalStructure>>(this, f, FloorClass); }
	void UpdateTribeGroupStructureRank_Implementation(char NewRank) { static NativeFunction f{ "APrimalStructure.UpdateTribeGroupStructureRank_Implementation" }; NativeCall<void, char>(this, f, NewRank); }
	bool AllowPlacingOnSaddleParentClass(APrimalDinoCharacter* theDino, bool bForcePrevent, int* OutReasonCode = nullptr, AShooterPlayerController* ForPC = nullptr) { static NativeFunction f{ "APrimalStructure.AllowPlacingOnSaddleParentClass" }; return NativeCall<bool, APrimalDinoCharacter*, bool, int*, AShooterPlayerController*>(this, f, theDino, bForcePrevent, OutReasonCode, ForPC); }
	static APrimalStructure* GetClosestStructureToPoint(UWorld* ForWorld, FVector AtPoint, float OverlapRadius) { static NativeFunction f{ "APrimalStructure.GetClosestStructureToPoint" }; return NativeCall<APrimalStructure*, UWorld*, FVector, float>(nullptr, f, ForWorld, AtPoint, OverlapRadius); }
	float GetStructureDemolishTime() { static NativeFunction f{ "APrimalStructure.GetStructureDemolishTime" }; return NativeCall<float>(this, f); }
	bool IsOnlyLinkedToFastDecayStructures() { static NativeFunction f{ "APrimalStructure.IsOnlyLinkedToFastDecayStructures" }; return NativeCall<bool>(this, f); }
	bool IsOnlyLinkedToFastDecayStructuresInternal(TSet<APrimalStructure*, DefaultKeyFuncs<APrimalStructure*, 0>, FDefaultSetAllocator>* TestedStructures) { static NativeFunction f{ "APrimalStructure.IsOnlyLinkedToFastDecayStructuresInternal" }; return NativeCall<bool, TSet<APrimalStructure*, DefaultKeyFuncs<APrimalStructure*, 0>, FDefaultSetAllocator>*>(this, f, TestedStructures); }
	bool CanAutoDemolish() { static NativeFunction f{ "APrimalStructure.CanAutoDemolish" }; return NativeCall<bool>(this, f); }
	bool IsValidSnapPointFrom_Implementation(APrimalStructure* ChildStructure, int MySnapPointToIndex) { static NativeFunction f{ "APrimalStructure.IsValidSnapPointFrom_Implementation" }; return NativeCall<bool, APrimalStructure*, int>(this, f, ChildStructure, MySnapPointToIndex); }
	FName* GetSnapPointName(FName* result, int SnapPointIndex) { static NativeFunction f{ "APrimalStructure.GetSnapPointName" }; return NativeCall<FName*, FName*, int>(this, f, result, SnapPointIndex); }
	ADayCycleManager* GetDayCycleManager() { static NativeFunction f{ "APrimalStructure.GetDayCycleManager" }; return NativeCall<ADayCycleManager*>(this, f); }
	void DelayedDisableSnapParent() { static NativeFunction f{ "APrimalStructure.DelayedDisableSnapParent" }; NativeCall<void>(this, f); }
	void SetEnabledPrimarySnappedStructureParent_Implementation(bool bEnabled) { static NativeFunction f{ "APrimalStructure.SetEnabledPrimarySnappedStructureParent_Implementation" }; NativeCall<void, bool>(this, f, bEnabled); }
	void SetEnabled(bool bEnabled) { static NativeFunction f{ "APrimalStructure.SetEnabled" }; NativeCall<void, bool>(this, f, bEnabled); }
	bool AllowCreateDynamicMaterials() { static NativeFunction f{ "APrimalStructure.AllowCreateDynamicMaterials" }; return NativeCall<bool>(this, f); }
	void CreateDynamicMaterials(UMeshComponent* ForceCreateForComponent) { static NativeFunction f{ "APrimalStructure.CreateDynamicMaterials" }; NativeCall<void, UMeshComponent*>(this, f, ForceCreateForComponent); }
	FLinearColor* GetStructureColor(FLinearColor* result, int ColorRegionIndex) { static NativeFunction f{ "APrimalStructure.GetStructureColor" }; return NativeCall<FLinearColor*, FLinearColor*, int>(this, f, result, ColorRegionIndex); }
	void FinalLoadedFromSaveGame() { static NativeFunction f{ "APrimalStructure.FinalLoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void UpdateStencilValues() { static NativeFunction f{ "APrimalStructure.UpdateStencilValues" }; NativeCall<void>(this, f); }
	int GetStructureColorValue(int ColorRegionIndex) { static NativeFunction f{ "APrimalStructure.GetStructureColorValue" }; return NativeCall<int, int>(this, f, ColorRegionIndex); }
	void SetStructureColorValue(int ColorRegionIndex, int SetVal) { static NativeFunction f{ "APrimalStructure.SetStructureColorValue" }; NativeCall<void, int, int>(this, f, ColorRegionIndex, SetVal); }
	void StructureHarvestingDepleted(UPrimalHarvestingComponent* fromComponent) { static NativeFunction f{ "APrimalStructure.StructureHarvestingDepleted" }; NativeCall<void, UPrimalHarvestingComponent*>(this, f, fromComponent); }
	void SetHarvestingActive(bool bActive, bool bOverrideBaseHealth, float BaseHarvestHealthMult, bool bAssignToTribe, int AssignedToTribeID) { static NativeFunction f{ "APrimalStructure.SetHarvestingActive" }; NativeCall<void, bool, bool, float, bool, int>(this, f, bActive, bOverrideBaseHealth, BaseHarvestHealthMult, bAssignToTribe, AssignedToTribeID); }
	FVector* GetTargetPathfindingLocation(FVector* result, AActor* Attacker) { static NativeFunction f{ "APrimalStructure.GetTargetPathfindingLocation" }; return NativeCall<FVector*, FVector*, AActor*>(this, f, result, Attacker); }
	FVector* GetTargetingLocation(FVector* result, AActor* Attacker) { static NativeFunction f{ "APrimalStructure.GetTargetingLocation" }; return NativeCall<FVector*, FVector*, AActor*>(this, f, result, Attacker); }
	bool GetClosestTargetOverride(FVector* attackPos, FVector* targetPos) { static NativeFunction f{ "APrimalStructure.GetClosestTargetOverride" }; return NativeCall<bool, FVector*, FVector*>(this, f, attackPos, targetPos); }
	bool IsDeprecated() { static NativeFunction f{ "APrimalStructure.IsDeprecated" }; return NativeCall<bool>(this, f); }
	bool IsActiveEventStructure() { static NativeFunction f{ "APrimalStructure.IsActiveEventStructure" }; return NativeCall<bool>(this, f); }
	void DeferredDeprecationCheck() { static NativeFunction f{ "APrimalStructure.DeferredDeprecationCheck" }; NativeCall<void>(this, f); }
	static void StaticRegisterNativesAPrimalStructure() { static NativeFunction f{ "APrimalStructure.StaticRegisterNativesAPrimalStructure" }; NativeCall<void>(nullptr, f); }
	void BlueprintDrawHUD(AShooterHUD* HUD, float CenterX, float CenterY) { static NativeFunction f{ "APrimalStructure.BlueprintDrawHUD" }; NativeCall<void, AShooterHUD*, float, float>(this, f, HUD, CenterX, CenterY); }
	void BlueprintDrawPreviewHUD(AShooterHUD* HUD, float CenterX, float CenterY) { static NativeFunction f{ "APrimalStructure.BlueprintDrawPreviewHUD" }; NativeCall<void, AShooterHUD*, float, float>(this, f, HUD, CenterX, CenterY); }
	bool BPAllowPickupGiveItem(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.BPAllowPickupGiveItem" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	bool BPAllowSnappingWith(APrimalStructure* OtherStructure, APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.BPAllowSnappingWith" }; return NativeCall<bool, APrimalStructure*, APlayerController*>(this, f, OtherStructure, ForPC); }
	bool BPAllowSnapRotationForStructure(int ThisSnapPointIndex, FName ThisSnapPointName, APrimalStructure* OtherStructure, int OtherStructureSnapPointIndex, FName OtherStructureSnapPointName) { static NativeFunction f{ "APrimalStructure.BPAllowSnapRotationForStructure" }; return NativeCall<bool, int, FName, APrimalStructure*, int, FName>(this, f, ThisSnapPointIndex, ThisSnapPointName, OtherStructure, OtherStructureSnapPointIndex, OtherStructureSnapPointName); }
	bool BPAllowSwitchToVariant(int VariantIndex) { static NativeFunction f{ "APrimalStructure.BPAllowSwitchToVariant" }; return NativeCall<bool, int>(this, f, VariantIndex); }
	void BPApplyCustomDurabilityOnPickup(UPrimalItem* pickedup) { static NativeFunction f{ "APrimalStructure.BPApplyCustomDurabilityOnPickup" }; NativeCall<void, UPrimalItem*>(this, f, pickedup); }
	void BPBeginPreview() { static NativeFunction f{ "APrimalStructure.BPBeginPreview" }; NativeCall<void>(this, f); }
	void BPDefaultProcessEditText(AShooterPlayerController* ForPC, FString* TextToUse, bool checkedBox) { static NativeFunction f{ "APrimalStructure.BPDefaultProcessEditText" }; NativeCall<void, AShooterPlayerController*, FString*, bool>(this, f, ForPC, TextToUse, checkedBox); }
	bool BPForceConsideredEnemyFoundation(APlayerController* PC, APrimalStructure* ForNewStructure, FVector* TestAtLocation) { static NativeFunction f{ "APrimalStructure.BPForceConsideredEnemyFoundation" }; return NativeCall<bool, APlayerController*, APrimalStructure*, FVector*>(this, f, PC, ForNewStructure, TestAtLocation); }
	void BPGetInfoFromConsumedItemForPlacedStructure(UPrimalItem* ItemToConsumed) { static NativeFunction f{ "APrimalStructure.BPGetInfoFromConsumedItemForPlacedStructure" }; NativeCall<void, UPrimalItem*>(this, f, ItemToConsumed); }
	bool BPHandleBedFastTravel(AShooterPlayerController* ForPC, APrimalStructure* ToBed) { static NativeFunction f{ "APrimalStructure.BPHandleBedFastTravel" }; return NativeCall<bool, AShooterPlayerController*, APrimalStructure*>(this, f, ForPC, ToBed); }
	void BPHandleStructureEnabled(bool bEnabled) { static NativeFunction f{ "APrimalStructure.BPHandleStructureEnabled" }; NativeCall<void, bool>(this, f, bEnabled); }
	bool BPImpactEffect(FHitResult* HitRes, FVector* ShootDirection) { static NativeFunction f{ "APrimalStructure.BPImpactEffect" }; return NativeCall<bool, FHitResult*, FVector*>(this, f, HitRes, ShootDirection); }
	int BPIsAllowedToBuild(FPlacementData* OutPlacementData, int CurrentAllowedReason) { static NativeFunction f{ "APrimalStructure.BPIsAllowedToBuild" }; return NativeCall<int, FPlacementData*, int>(this, f, OutPlacementData, CurrentAllowedReason); }
	int BPIsAllowedToBuildEx(FPlacementData* OutPlacementData, int CurrentAllowedReason, APlayerController* PC, bool bFinalPlacement, bool bChoosingRotation) { static NativeFunction f{ "APrimalStructure.BPIsAllowedToBuildEx" }; return NativeCall<int, FPlacementData*, int, APlayerController*, bool, bool>(this, f, OutPlacementData, CurrentAllowedReason, PC, bFinalPlacement, bChoosingRotation); }
	void BPOnDemolish(APlayerController* ForPC, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.BPOnDemolish" }; NativeCall<void, APlayerController*, AActor*>(this, f, ForPC, DamageCauser); }
	void BPOnStructurePickup(APlayerController* PlayerController, TSubclassOf<UPrimalItem> ItemType, UPrimalItem* NewlyPickedUpItem, bool bIsQuickPickup) { static NativeFunction f{ "APrimalStructure.BPOnStructurePickup" }; NativeCall<void, APlayerController*, TSubclassOf<UPrimalItem>, UPrimalItem*, bool>(this, f, PlayerController, ItemType, NewlyPickedUpItem, bIsQuickPickup); }
	void BPOnVariantSwitch(int NewVariantIndex) { static NativeFunction f{ "APrimalStructure.BPOnVariantSwitch" }; NativeCall<void, int>(this, f, NewVariantIndex); }
	bool BPOverrideAllowStructureAccess(AShooterPlayerController* ForPC, bool bIsAccessAllowed, bool bIsFromPinCode = false) { static NativeFunction f{ "APrimalStructure.BPOverrideAllowStructureAccess" }; return NativeCall<bool, AShooterPlayerController*, bool, bool>(this, f, ForPC, bIsAccessAllowed, bIsFromPinCode); }
	FString* BPOverrideCantBuildReasonString(FString* result, int CantBuildReason) { static NativeFunction f{ "APrimalStructure.BPOverrideCantBuildReasonString" }; return NativeCall<FString*, FString*, int>(this, f, result, CantBuildReason); }
	bool BPOverrideDemolish(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.BPOverrideDemolish" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	FRotator* BPOverridePlacementRotation(FRotator* result, FVector ViewPos, FRotator ViewRot) { static NativeFunction f{ "APrimalStructure.BPOverridePlacementRotation" }; return NativeCall<FRotator*, FRotator*, FVector, FRotator>(this, f, result, ViewPos, ViewRot); }
	bool BPOverrideSnappedFromTransform(APrimalStructure* parentStructure, int ParentSnapFromIndex, FName ParentSnapFromName, FVector UnsnappedPlacementPos, FRotator UnsnappedPlacementRot, FVector SnappedPlacementPos, FRotator SnappedPlacementRot, int SnapToIndex, FName SnapToName, FVector* OutLocation, FRotator* OutRotation, int* bForceInvalidateSnap) { static NativeFunction f{ "APrimalStructure.BPOverrideSnappedFromTransform" }; return NativeCall<bool, APrimalStructure*, int, FName, FVector, FRotator, FVector, FRotator, int, FName, FVector*, FRotator*, int*>(this, f, parentStructure, ParentSnapFromIndex, ParentSnapFromName, UnsnappedPlacementPos, UnsnappedPlacementRot, SnappedPlacementPos, SnappedPlacementRot, SnapToIndex, SnapToName, OutLocation, OutRotation, bForceInvalidateSnap); }
	bool BPOverrideSnappedToTransform(APrimalStructure* childStructure, int ChildSnapFromIndex, FName ChildSnapFromName, FVector UnsnappedPlacementPos, FRotator UnsnappedPlacementRot, FVector SnappedPlacementPos, FRotator SnappedPlacementRot, int SnapToIndex, FName SnapToName, FVector* OutLocation, FRotator* OutRotation, int* bForceInvalidateSnap) { static NativeFunction f{ "APrimalStructure.BPOverrideSnappedToTransform" }; return NativeCall<bool, APrimalStructure*, int, FName, FVector, FRotator, FVector, FRotator, int, FName, FVector*, FRotator*, int*>(this, f, childStructure, ChildSnapFromIndex, ChildSnapFromName, UnsnappedPlacementPos, UnsnappedPlacementRot, SnappedPlacementPos, SnappedPlacementRot, SnapToIndex, SnapToName, OutLocation, OutRotation, bForceInvalidateSnap); }
	FVector* BPOverrideTargetLocation(FVector* result, FVector* attackPos) { static NativeFunction f{ "APrimalStructure.BPOverrideTargetLocation" }; return NativeCall<FVector*, FVector*, FVector*>(this, f, result, attackPos); }
	void BPPlacedStructure(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.BPPlacedStructure" }; NativeCall<void, APlayerController*>(this, f, ForPC); }
	void BPPlayDying(float KillingDamage, FDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructure.BPPlayDying" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void BPPostLoadedFromSaveGame() { static NativeFunction f{ "APrimalStructure.BPPostLoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void BPPostSetStructureCollisionChannels() { static NativeFunction f{ "APrimalStructure.BPPostSetStructureCollisionChannels" }; NativeCall<void>(this, f); }
	bool BPPreventPlacementOnPawn(APlayerController* PC, APrimalCharacter* ForCharacter, FName ForBone) { static NativeFunction f{ "APrimalStructure.BPPreventPlacementOnPawn" }; return NativeCall<bool, APlayerController*, APrimalCharacter*, FName>(this, f, PC, ForCharacter, ForBone); }
	bool BPPreventPlacingOnFloorStructure(FPlacementData* theOutPlacementData, APrimalStructure* FloorStructure) { static NativeFunction f{ "APrimalStructure.BPPreventPlacingOnFloorStructure" }; return NativeCall<bool, FPlacementData*, APrimalStructure*>(this, f, theOutPlacementData, FloorStructure); }
	bool BPPreventPlacingStructureOntoMe(APlayerController* PC, APrimalStructure* ForNewStructure, FHitResult* ForHitResult) { static NativeFunction f{ "APrimalStructure.BPPreventPlacingStructureOntoMe" }; return NativeCall<bool, APlayerController*, APrimalStructure*, FHitResult*>(this, f, PC, ForNewStructure, ForHitResult); }
	bool BPPreventSpawnForPlayer(AShooterPlayerController* PC, bool bCheckCooldownTime, APrimalStructure* FromStructure) { static NativeFunction f{ "APrimalStructure.BPPreventSpawnForPlayer" }; return NativeCall<bool, AShooterPlayerController*, bool, APrimalStructure*>(this, f, PC, bCheckCooldownTime, FromStructure); }
	bool BPPreventUsingAsFloorForStructure(FPlacementData* theOutPlacementData, APrimalStructure* StructureToPlaceOnMe) { static NativeFunction f{ "APrimalStructure.BPPreventUsingAsFloorForStructure" }; return NativeCall<bool, FPlacementData*, APrimalStructure*>(this, f, theOutPlacementData, StructureToPlaceOnMe); }
	void BPRefreshedStructureColors() { static NativeFunction f{ "APrimalStructure.BPRefreshedStructureColors" }; NativeCall<void>(this, f); }
	void BPStructurePreGetMultiUseEntries(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructure.BPStructurePreGetMultiUseEntries" }; NativeCall<void, APlayerController*>(this, f, ForPC); }
	bool BPTreatAsFoundationForSnappedStructure(APrimalStructure* OtherStructure, FPlacementData* WithPlacementData) { static NativeFunction f{ "APrimalStructure.BPTreatAsFoundationForSnappedStructure" }; return NativeCall<bool, APrimalStructure*, FPlacementData*>(this, f, OtherStructure, WithPlacementData); }
	void BPTriggerStasisEvent() { static NativeFunction f{ "APrimalStructure.BPTriggerStasisEvent" }; NativeCall<void>(this, f); }
	void BPUnstasis() { static NativeFunction f{ "APrimalStructure.BPUnstasis" }; NativeCall<void>(this, f); }
	bool BPUseCountStructureInRange() { static NativeFunction f{ "APrimalStructure.BPUseCountStructureInRange" }; return NativeCall<bool>(this, f); }
	void ClearCustomColors() { static NativeFunction f{ "APrimalStructure.ClearCustomColors" }; NativeCall<void>(this, f); }
	void ClientUpdateLinkedStructures(TArray<unsigned int>* NewLinkedStructures) { static NativeFunction f{ "APrimalStructure.ClientUpdateLinkedStructures" }; NativeCall<void, TArray<unsigned int>*>(this, f, NewLinkedStructures); }
	TSubclassOf<APrimalStructure>* GetBedFilterClass(TSubclassOf<APrimalStructure>* result) { static NativeFunction f{ "APrimalStructure.GetBedFilterClass" }; return NativeCall<TSubclassOf<APrimalStructure>*, TSubclassOf<APrimalStructure>*>(this, f, result); }
	bool IsValidForSnappingFrom(APrimalStructure* OtherStructure) { static NativeFunction f{ "APrimalStructure.IsValidForSnappingFrom" }; return NativeCall<bool, APrimalStructure*>(this, f, OtherStructure); }
	bool IsValidSnapPointFrom(APrimalStructure* ParentStructure, int MySnapPointFromIndex) { static NativeFunction f{ "APrimalStructure.IsValidSnapPointFrom" }; return NativeCall<bool, APrimalStructure*, int>(this, f, ParentStructure, MySnapPointFromIndex); }
	bool IsValidSnapPointTo(APrimalStructure* ChildStructure, int MySnapPointToIndex) { static NativeFunction f{ "APrimalStructure.IsValidSnapPointTo" }; return NativeCall<bool, APrimalStructure*, int>(this, f, ChildStructure, MySnapPointToIndex); }
	void MultiAddStructuresPlacedOnFloor(APrimalStructure* structure) { static NativeFunction f{ "APrimalStructure.MultiAddStructuresPlacedOnFloor" }; NativeCall<void, APrimalStructure*>(this, f, structure); }
	void MultiRefreshVariantSettings(int NewVariantIndex) { static NativeFunction f{ "APrimalStructure.MultiRefreshVariantSettings" }; NativeCall<void, int>(this, f, NewVariantIndex); }
	void MultiSetPickupAllowedBeforeNetworkTime(long double NewTime) { static NativeFunction f{ "APrimalStructure.MultiSetPickupAllowedBeforeNetworkTime" }; NativeCall<void, long double>(this, f, NewTime); }
	void NetDoSpawnEffects() { static NativeFunction f{ "APrimalStructure.NetDoSpawnEffects" }; NativeCall<void>(this, f); }
	void NetSpawnCoreStructureDeathActor() { static NativeFunction f{ "APrimalStructure.NetSpawnCoreStructureDeathActor" }; NativeCall<void>(this, f); }
	void NetUpdateOriginalOwnerNameAndID(int NewOriginalOwnerID, FString* NewOriginalOwnerName) { static NativeFunction f{ "APrimalStructure.NetUpdateOriginalOwnerNameAndID" }; NativeCall<void, int, FString*>(this, f, NewOriginalOwnerID, NewOriginalOwnerName); }
	void NetUpdateTeamAndOwnerName(int NewTeam, FString* NewOwnerName) { static NativeFunction f{ "APrimalStructure.NetUpdateTeamAndOwnerName" }; NativeCall<void, int, FString*>(this, f, NewTeam, NewOwnerName); }
	void SetEnabledPrimarySnappedStructureParent(bool bEnabled) { static NativeFunction f{ "APrimalStructure.SetEnabledPrimarySnappedStructureParent" }; NativeCall<void, bool>(this, f, bEnabled); }
	void UpdateTribeGroupStructureRank(char NewRank) { static NativeFunction f{ "APrimalStructure.UpdateTribeGroupStructureRank" }; NativeCall<void, char>(this, f, NewRank); }

	void GetMultiUseEntries(APlayerController* ForPC, TArray<FMultiUseEntry>* MultiUseEntries) { static NativeFunction f{ "APrimalStructure.GetMultiUseEntries" }; NativeCall<void, APlayerController*, TArray<FMultiUseEntry>*>(this, f, ForPC, MultiUseEntries); }
};

// can return a bed or a dino
struct FBedWithIDResult
{
	AActor* Actor;

	operator AActor*() const { return Actor; }
	[[deprecated("FindBedWithID returns AActor*, the result can be a dino")]] operator APrimalStructure*() const { ReportDeprecatedApiUse("APrimalStructureBed.FindBedWithID as APrimalStructure*"); return static_cast<APrimalStructure*>(Actor); }
	AActor* operator->() const { return Actor; }
	explicit operator bool() const { return Actor != nullptr; }
	bool operator==(std::nullptr_t) const { return Actor == nullptr; }
	bool operator!=(std::nullptr_t) const { return Actor != nullptr; }
};

struct APrimalStructureBed : APrimalStructure
{
	FVector& PlayerSpawnLocOffsetField() { static NativeFieldOffset f{ "APrimalStructureBed.PlayerSpawnLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& PlayerSpawnRotOffsetField() { static NativeFieldOffset f{ "APrimalStructureBed.PlayerSpawnRotOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	unsigned int& LinkedPlayerIDField() { static NativeFieldOffset f{ "APrimalStructureBed.LinkedPlayerID" }; return *GetNativePointerField<unsigned int*>(this, f); }
	FString& LinkedPlayerNameField() { static NativeFieldOffset f{ "APrimalStructureBed.LinkedPlayerName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& BedNameField() { static NativeFieldOffset f{ "APrimalStructureBed.BedName" }; return *GetNativePointerField<FString*>(this, f); }
	float& UseCooldownTimeField() { static NativeFieldOffset f{ "APrimalStructureBed.UseCooldownTime" }; return *GetNativePointerField<float*>(this, f); }
	float& UseCooldownRadiusField() { static NativeFieldOffset f{ "APrimalStructureBed.UseCooldownRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& AttachedToPlatformStructureEnemySpawnPreventionRadiusField() { static NativeFieldOffset f{ "APrimalStructureBed.AttachedToPlatformStructureEnemySpawnPreventionRadius" }; return *GetNativePointerField<float*>(this, f); }
	long double& NextAllowedUseTimeField() { static NativeFieldOffset f{ "APrimalStructureBed.NextAllowedUseTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastSignNamingTimeField() { static NativeFieldOffset f{ "APrimalStructureBed.LastSignNamingTime" }; return *GetNativePointerField<long double*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bDestroyAfterRespawnUse() { static NativeBitField f{ "APrimalStructureBed.bDestroyAfterRespawnUse" }; return { this, f }; }

	// Functions

	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureBed.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureBed.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	bool AllowPickupForItem(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructureBed.AllowPickupForItem" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructureBed.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureBed.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void ClientMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureBed.ClientMultiUse" }; NativeCall<void, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void ProcessEditText(AShooterPlayerController* ForPC, FString* TextToUse, bool __formal) { static NativeFunction f{ "APrimalStructureBed.ProcessEditText" }; NativeCall<void, AShooterPlayerController*, FString*, bool>(this, f, ForPC, TextToUse, __formal); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalStructureBed.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	void PlacedStructure(AShooterPlayerController* PC) { static NativeFunction f{ "APrimalStructureBed.PlacedStructure" }; NativeCall<void, AShooterPlayerController*>(this, f, PC); }
	bool AllowSpawnForPlayer(AShooterPlayerController* PC, bool bCheckCooldownTime, APrimalStructure* FromStructure) { static NativeFunction f{ "APrimalStructureBed.AllowSpawnForPlayer" }; return NativeCall<bool, AShooterPlayerController*, bool, APrimalStructure*>(this, f, PC, bCheckCooldownTime, FromStructure); }
	bool AllowSpawnForDownloadedPlayer(unsigned __int64 PlayerDataID, unsigned __int64 TribeID, bool bCheckCooldownTime) { static NativeFunction f{ "APrimalStructureBed.AllowSpawnForDownloadedPlayer" }; return NativeCall<bool, unsigned __int64, unsigned __int64, bool>(this, f, PlayerDataID, TribeID, bCheckCooldownTime); }
	bool CheckStructureActivateTribeGroupPermission(unsigned __int64 PlayerDataID, unsigned __int64 TribeID) { static NativeFunction f{ "APrimalStructureBed.CheckStructureActivateTribeGroupPermission" }; return NativeCall<bool, unsigned __int64, unsigned __int64>(this, f, PlayerDataID, TribeID); }
	void SpawnedPlayerFor_Implementation(AShooterPlayerController* PC, APawn* ForPawn) { static NativeFunction f{ "APrimalStructureBed.SpawnedPlayerFor_Implementation" }; NativeCall<void, AShooterPlayerController*, APawn*>(this, f, PC, ForPawn); }
	void Destroyed() { static NativeFunction f{ "APrimalStructureBed.Destroyed" }; NativeCall<void>(this, f); }
	void BeginPlay() { static NativeFunction f{ "APrimalStructureBed.BeginPlay" }; NativeCall<void>(this, f); }
	FSpawnPointInfo* GetSpawnPointInfo(FSpawnPointInfo* result) { static NativeFunction f{ "APrimalStructureBed.GetSpawnPointInfo" }; return NativeCall<FSpawnPointInfo*, FSpawnPointInfo*>(this, f, result); }
	static FBedWithIDResult FindBedWithID(UWorld* forWorld, int theBedID) { static NativeFunction f{ "APrimalStructureBed.FindBedWithID" }; return { NativeCall<AActor*, UWorld*, int>(nullptr, f, forWorld, theBedID) }; }
	FVector* GetPlayerSpawnLocation(FVector* result) { static NativeFunction f{ "APrimalStructureBed.GetPlayerSpawnLocation" }; return NativeCall<FVector*, FVector*>(this, f, result); }
	FRotator* GetPlayerSpawnRotation(FRotator* result) { static NativeFunction f{ "APrimalStructureBed.GetPlayerSpawnRotation" }; return NativeCall<FRotator*, FRotator*>(this, f, result); }
	void PostInitializeComponents() { static NativeFunction f{ "APrimalStructureBed.PostInitializeComponents" }; NativeCall<void>(this, f); }
	FString* GetDescriptiveName(FString* result) { static NativeFunction f{ "APrimalStructureBed.GetDescriptiveName" }; return NativeCall<FString*, FString*>(this, f, result); }
	static void StaticRegisterNativesAPrimalStructureBed() { static NativeFunction f{ "APrimalStructureBed.StaticRegisterNativesAPrimalStructureBed" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "APrimalStructureBed.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	void SpawnedPlayerFor(AShooterPlayerController* PC, APawn* ForPawn) { static NativeFunction f{ "APrimalStructureBed.SpawnedPlayerFor" }; NativeCall<void, AShooterPlayerController*, APawn*>(this, f, PC, ForPawn); }
};

struct APrimalStructureDoor : APrimalStructure
{
	TSubobjectPtr<USceneComponent>& MyDoorTransformField() { static NativeFieldOffset f{ "APrimalStructureDoor.MyDoorTransform" }; return *GetNativePointerField<TSubobjectPtr<USceneComponent>*>(this, f); }
	float& RotationSpeedField() { static NativeFieldOffset f{ "APrimalStructureDoor.RotationSpeed" }; return *GetNativePointerField<float*>(this, f); }
	USoundCue* DoorOpenSoundField() { static NativeFieldOffset f{ "APrimalStructureDoor.DoorOpenSound" }; return *GetNativePointerField<USoundCue**>(this, f); }
	USoundCue* DoorCloseSoundField() { static NativeFieldOffset f{ "APrimalStructureDoor.DoorCloseSound" }; return *GetNativePointerField<USoundCue**>(this, f); }
	unsigned int& CurrentPinCodeField() { static NativeFieldOffset f{ "APrimalStructureDoor.CurrentPinCode" }; return *GetNativePointerField<unsigned int*>(this, f); }
	float& DoorStateChangeIgnoreEncroachmentIntervalField() { static NativeFieldOffset f{ "APrimalStructureDoor.DoorStateChangeIgnoreEncroachmentInterval" }; return *GetNativePointerField<float*>(this, f); }
	char& DoorOpenStateField() { static NativeFieldOffset f{ "APrimalStructureDoor.DoorOpenState" }; return *GetNativePointerField<char*>(this, f); }
	char& ClientPrevDoorOpenStateField() { static NativeFieldOffset f{ "APrimalStructureDoor.ClientPrevDoorOpenState" }; return *GetNativePointerField<char*>(this, f); }
	long double& LastLockStateChangeTimeField() { static NativeFieldOffset f{ "APrimalStructureDoor.LastLockStateChangeTime" }; return *GetNativePointerField<long double*>(this, f); }
	FRotator& SecondDoorDefaultRotField() { static NativeFieldOffset f{ "APrimalStructureDoor.SecondDoorDefaultRot" }; return *GetNativePointerField<FRotator*>(this, f); }
	float& CurrentDoorAngleField() { static NativeFieldOffset f{ "APrimalStructureDoor.CurrentDoorAngle" }; return *GetNativePointerField<float*>(this, f); }
	USoundBase* UnlockDoorSoundField() { static NativeFieldOffset f{ "APrimalStructureDoor.UnlockDoorSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* LockDoorSoundField() { static NativeFieldOffset f{ "APrimalStructureDoor.LockDoorSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* LockedSoundField() { static NativeFieldOffset f{ "APrimalStructureDoor.LockedSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	long double& LastPinOpenSuccessTimeField() { static NativeFieldOffset f{ "APrimalStructureDoor.LastPinOpenSuccessTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastDoorStateChangeTimeField() { static NativeFieldOffset f{ "APrimalStructureDoor.LastDoorStateChangeTime" }; return *GetNativePointerField<long double*>(this, f); }
	char& DelayedDoorStateField() { static NativeFieldOffset f{ "APrimalStructureDoor.DelayedDoorState" }; return *GetNativePointerField<char*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bInvertOpenCloseDirection() { static NativeBitField f{ "APrimalStructureDoor.bInvertOpenCloseDirection" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupportsLocking() { static NativeBitField f{ "APrimalStructureDoor.bSupportsLocking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseSecondDoor() { static NativeBitField f{ "APrimalStructureDoor.bUseSecondDoor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupportsPinLocking() { static NativeBitField f{ "APrimalStructureDoor.bSupportsPinLocking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsLocked() { static NativeBitField f{ "APrimalStructureDoor.bIsLocked" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPinLocked() { static NativeBitField f{ "APrimalStructureDoor.bIsPinLocked" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAdminOnlyAccess() { static NativeBitField f{ "APrimalStructureDoor.bAdminOnlyAccess" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanBeForcedOpenByDino() { static NativeBitField f{ "APrimalStructureDoor.bCanBeForcedOpenByDino" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventBasingWhileMoving() { static NativeBitField f{ "APrimalStructureDoor.bPreventBasingWhileMoving" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceDoorOpenIn() { static NativeBitField f{ "APrimalStructureDoor.bForceDoorOpenIn" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceDoorOpenOut() { static NativeBitField f{ "APrimalStructureDoor.bForceDoorOpenOut" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsDoorMoving() { static NativeBitField f{ "APrimalStructureDoor.bIsDoorMoving" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceStaticMobility() { static NativeBitField f{ "APrimalStructureDoor.bForceStaticMobility" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRotatePitch() { static NativeBitField f{ "APrimalStructureDoor.bRotatePitch" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRotateRoll() { static NativeBitField f{ "APrimalStructureDoor.bRotateRoll" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRotateYaw() { static NativeBitField f{ "APrimalStructureDoor.bRotateYaw" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInitializedRotation() { static NativeBitField f{ "APrimalStructureDoor.bInitializedRotation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventDoorInterpolation() { static NativeBitField f{ "APrimalStructureDoor.bPreventDoorInterpolation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGotoDoorState() { static NativeBitField f{ "APrimalStructureDoor.bUseBPGotoDoorState" }; return { this, f }; }

	// Functions

	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureDoor.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureDoor.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	void BeginPlay() { static NativeFunction f{ "APrimalStructureDoor.BeginPlay" }; NativeCall<void>(this, f); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "APrimalStructureDoor.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructureDoor.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalStructureDoor.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	void OnRep_DoorOpenState(char PrevDoorOpenState) { static NativeFunction f{ "APrimalStructureDoor.OnRep_DoorOpenState" }; NativeCall<void, char>(this, f, PrevDoorOpenState); }
	void GotoDoorState(char DoorState) { static NativeFunction f{ "APrimalStructureDoor.GotoDoorState" }; NativeCall<void, char>(this, f, DoorState); }
	void DelayedGotoDoorState(char DoorState, float DelayTime) { static NativeFunction f{ "APrimalStructureDoor.DelayedGotoDoorState" }; NativeCall<void, char, float>(this, f, DoorState, DelayTime); }
	void DelayedGotoDoorStateTimer() { static NativeFunction f{ "APrimalStructureDoor.DelayedGotoDoorStateTimer" }; NativeCall<void>(this, f); }
	bool HasSamePinCode(APrimalStructureItemContainer* otherContainer) { static NativeFunction f{ "APrimalStructureDoor.HasSamePinCode" }; return NativeCall<bool, APrimalStructureItemContainer*>(this, f, otherContainer); }
	bool IsPinLocked() { static NativeFunction f{ "APrimalStructureDoor.IsPinLocked" }; return NativeCall<bool>(this, f); }
	int GetPinCode() { static NativeFunction f{ "APrimalStructureDoor.GetPinCode" }; return NativeCall<int>(this, f); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureDoor.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	bool CanOpen(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureDoor.CanOpen" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	FString* GetDescriptiveName(FString* result) { static NativeFunction f{ "APrimalStructureDoor.GetDescriptiveName" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool ApplyPinCode(AShooterPlayerController* ForPC, int appledPinCode, bool bIsSetting, int TheCustomIndex) { static NativeFunction f{ "APrimalStructureDoor.ApplyPinCode" }; return NativeCall<bool, AShooterPlayerController*, int, bool, int>(this, f, ForPC, appledPinCode, bIsSetting, TheCustomIndex); }
	void SetStaticMobility() { static NativeFunction f{ "APrimalStructureDoor.SetStaticMobility" }; NativeCall<void>(this, f); }
	void NetGotoDoorState_Implementation(char DoorState) { static NativeFunction f{ "APrimalStructureDoor.NetGotoDoorState_Implementation" }; NativeCall<void, char>(this, f, DoorState); }
	void PostInitializeComponents() { static NativeFunction f{ "APrimalStructureDoor.PostInitializeComponents" }; NativeCall<void>(this, f); }
	bool AllowStructureAccess(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureDoor.AllowStructureAccess" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	bool PreventCharacterBasing(AActor* OtherActor, UPrimitiveComponent* BasedOnComponent) { static NativeFunction f{ "APrimalStructureDoor.PreventCharacterBasing" }; return NativeCall<bool, AActor*, UPrimitiveComponent*>(this, f, OtherActor, BasedOnComponent); }
	bool AllowPickupForItem(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructureDoor.AllowPickupForItem" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	void BPSetDoorState(int DoorState) { static NativeFunction f{ "APrimalStructureDoor.BPSetDoorState" }; NativeCall<void, int>(this, f, DoorState); }
	bool AllowIgnoreCharacterEncroachment_Implementation(UPrimitiveComponent* HitComponent, AActor* EncroachingCharacter) { static NativeFunction f{ "APrimalStructureDoor.AllowIgnoreCharacterEncroachment_Implementation" }; return NativeCall<bool, UPrimitiveComponent*, AActor*>(this, f, HitComponent, EncroachingCharacter); }
	static void StaticRegisterNativesAPrimalStructureDoor() { static NativeFunction f{ "APrimalStructureDoor.StaticRegisterNativesAPrimalStructureDoor" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "APrimalStructureDoor.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	void BPGotoDoorState(int NewDoorState) { static NativeFunction f{ "APrimalStructureDoor.BPGotoDoorState" }; NativeCall<void, int>(this, f, NewDoorState); }
	void NetGotoDoorState(char DoorState) { static NativeFunction f{ "APrimalStructureDoor.NetGotoDoorState" }; NativeCall<void, char>(this, f, DoorState); }
};

struct APrimalStructureItemContainer : APrimalStructure
{
	UPrimalInventoryComponent* MyInventoryComponentField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.MyInventoryComponent" }; return *GetNativePointerField<UPrimalInventoryComponent**>(this, f); }
	float& SolarRefreshIntervalMinField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.SolarRefreshIntervalMin" }; return *GetNativePointerField<float*>(this, f); }
	float& SolarRefreshIntervalMaxField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.SolarRefreshIntervalMax" }; return *GetNativePointerField<float*>(this, f); }
	float& SolarRefreshIntervalField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.SolarRefreshInterval" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastSolarRefreshTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastSolarRefreshTime" }; return *GetNativePointerField<long double*>(this, f); }
	TSubclassOf<UPrimalItem>& BatteryClassOverrideField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.BatteryClassOverride" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	int& PoweredOverrideCounterField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.PoweredOverrideCounter" }; return *GetNativePointerField<int*>(this, f); }
	float& NotifyNearbyPowerGeneratorDistanceField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.NotifyNearbyPowerGeneratorDistance" }; return *GetNativePointerField<float*>(this, f); }
	int& NotifyNearbyPowerGeneratorOctreeGroupField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.NotifyNearbyPowerGeneratorOctreeGroup" }; return *GetNativePointerField<int*>(this, f); }
	TArray<UMaterialInterface*>& ActivateMaterialsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ActivateMaterials" }; return *GetNativePointerField<TArray<UMaterialInterface*>*>(this, f); }
	TArray<UMaterialInterface*>& InActivateMaterialsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.InActivateMaterials" }; return *GetNativePointerField<TArray<UMaterialInterface*>*>(this, f); }
	UChildActorComponent* MyChildEmitterSpawnableField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.MyChildEmitterSpawnable" }; return *GetNativePointerField<UChildActorComponent**>(this, f); }
	FString& BoxNameField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.BoxName" }; return *GetNativePointerField<FString*>(this, f); }
	float& InsulationRangeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.InsulationRange" }; return *GetNativePointerField<float*>(this, f); }
	float& HyperThermiaInsulationField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.HyperThermiaInsulation" }; return *GetNativePointerField<float*>(this, f); }
	float& HypoThermiaInsulationField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.HypoThermiaInsulation" }; return *GetNativePointerField<float*>(this, f); }
	float& ContainerActiveDecreaseHealthSpeedField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ContainerActiveDecreaseHealthSpeed" }; return *GetNativePointerField<float*>(this, f); }
	float& FuelConsumptionIntervalsMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.FuelConsumptionIntervalsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& DropInventoryOnDestructionLifespanField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DropInventoryOnDestructionLifespan" }; return *GetNativePointerField<float*>(this, f); }
	FString& ActivateContainerStringField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ActivateContainerString" }; return *GetNativePointerField<FString*>(this, f); }
	FString& DeactivateContainerStringField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DeactivateContainerString" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<UDamageType>& ContainerActiveHealthDecreaseDamageTypePassiveField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ContainerActiveHealthDecreaseDamageTypePassive" }; return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& ActiveRequiresFuelItemsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ActiveRequiresFuelItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<float>& FuelItemsConsumeIntervalField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.FuelItemsConsumeInterval" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& FuelItemsConsumedGiveItemsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.FuelItemsConsumedGiveItems" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	long double& NetDestructionTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.NetDestructionTime" }; return *GetNativePointerField<long double*>(this, f); }
	unsigned int& CurrentPinCodeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.CurrentPinCode" }; return *GetNativePointerField<unsigned int*>(this, f); }
	long double& CurrentFuelTimeCacheField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.CurrentFuelTimeCache" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastCheckedFuelTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastCheckedFuelTime" }; return *GetNativePointerField<long double*>(this, f); }
	int& LinkedPowerJunctionStructureIDField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LinkedPowerJunctionStructureID" }; return *GetNativePointerField<int*>(this, f); }
	int& CurrentItemCountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.CurrentItemCount" }; return *GetNativePointerField<int*>(this, f); }
	int& MaxItemCountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.MaxItemCount" }; return *GetNativePointerField<int*>(this, f); }
	TWeakObjectPtr<APrimalStructure>& LinkedPowerJunctionStructureField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LinkedPowerJunctionStructure" }; return *GetNativePointerField<TWeakObjectPtr<APrimalStructure>*>(this, f); }
	TSubclassOf<UPrimalItem>& NextConsumeFuelGiveItemTypeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.NextConsumeFuelGiveItemType" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	long double& LastLockStateChangeTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastLockStateChangeTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastActiveStateChangeTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastActiveStateChangeTime" }; return *GetNativePointerField<long double*>(this, f); }
	int& LastPowerJunctionLinkIDField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastPowerJunctionLinkID" }; return *GetNativePointerField<int*>(this, f); }
	FPrimalMapMarkerEntryData& MapMarkerLocationInfoField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.MapMarkerLocationInfo" }; return *GetNativePointerField<FPrimalMapMarkerEntryData*>(this, f); }
	float& BasedCharacterDamageIntervalField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.BasedCharacterDamageInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& BasedCharacterDamageAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.BasedCharacterDamageAmount" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<UDamageType>& BasedCharacterDamageTypeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.BasedCharacterDamageType" }; return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, f); }
	TSubclassOf<UPrimalItem>& EngramRequirementClassOverrideField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.EngramRequirementClassOverride" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	AActor* LinkedBlueprintSpawnActorPointField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LinkedBlueprintSpawnActorPoint" }; return *GetNativePointerField<AActor**>(this, f); }
	TSubclassOf<APrimalStructureItemContainer>& PoweredNearbyStructureTemplateField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.PoweredNearbyStructureTemplate" }; return *GetNativePointerField<TSubclassOf<APrimalStructureItemContainer>*>(this, f); }
	float& PoweredNearbyStructureRangeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.PoweredNearbyStructureRange" }; return *GetNativePointerField<float*>(this, f); }
	FString& OpenSceneActionNameField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.OpenSceneActionName" }; return *GetNativePointerField<FString*>(this, f); }
	FString& DisabledOpenSceneActionNameField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DisabledOpenSceneActionName" }; return *GetNativePointerField<FString*>(this, f); }
	TSubclassOf<UPrimalItem>& RequiresItemForOpenSceneActionField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.RequiresItemForOpenSceneAction" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	long double& DeathCacheCreationTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DeathCacheCreationTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastBasedCharacterDamageTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastBasedCharacterDamageTime" }; return *GetNativePointerField<long double*>(this, f); }
	int& LastBasedCharacterDamageFrameField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastBasedCharacterDamageFrame" }; return *GetNativePointerField<int*>(this, f); }
	long double& LastSignNamingTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastSignNamingTime" }; return *GetNativePointerField<long double*>(this, f); }
	FVector& JunctionCableBeamOffsetStartField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.JunctionCableBeamOffsetStart" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& JunctionCableBeamOffsetEndField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.JunctionCableBeamOffsetEnd" }; return *GetNativePointerField<FVector*>(this, f); }
	USoundBase* ContainerActivatedSoundField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ContainerActivatedSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	USoundBase* ContainerDeactivatedSoundField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ContainerDeactivatedSound" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TSubclassOf<APrimalStructureItemContainer>& DemolishInventoryDepositClassField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DemolishInventoryDepositClass" }; return *GetNativePointerField<TSubclassOf<APrimalStructureItemContainer>*>(this, f); }
	TSubclassOf<UPrimalItem>& FuelItemTrueClassField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.FuelItemTrueClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TSubclassOf<UPrimalItem>& ReplicatedFuelItemClassField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ReplicatedFuelItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	__int16& ReplicatedFuelItemColorIndexField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ReplicatedFuelItemColorIndex" }; return *GetNativePointerField<__int16*>(this, f); }
	USoundBase* DefaultAudioTemplateField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DefaultAudioTemplate" }; return *GetNativePointerField<USoundBase**>(this, f); }
	TArray<TSubclassOf<UPrimalItem>>& OverrideParticleTemplateItemClassesField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.OverrideParticleTemplateItemClasses" }; return *GetNativePointerField<TArray<TSubclassOf<UPrimalItem>>*>(this, f); }
	TArray<USoundBase*>& OverrideAudioTemplatesField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.OverrideAudioTemplates" }; return *GetNativePointerField<TArray<USoundBase*>*>(this, f); }
	float& MaxActivationDistanceField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.MaxActivationDistance" }; return *GetNativePointerField<float*>(this, f); }
	FString& BoxNamePrefaceStringField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.BoxNamePrefaceString" }; return *GetNativePointerField<FString*>(this, f); }
	unsigned char& TribeGroupInventoryRankField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.TribeGroupInventoryRank" }; return *GetNativePointerField<unsigned char*>(this, f); }
	TArray<float>& FuelConsumeDecreaseDurabilityAmountsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.FuelConsumeDecreaseDurabilityAmounts" }; return *GetNativePointerField<TArray<float>*>(this, f); }
	float& RandomFuelUpdateTimeMinField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.RandomFuelUpdateTimeMin" }; return *GetNativePointerField<float*>(this, f); }
	float& RandomFuelUpdateTimeMaxField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.RandomFuelUpdateTimeMax" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastDeactivatedTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastDeactivatedTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& LastActivatedTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.LastActivatedTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& ValidCraftingResourceMaxDurabilityField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ValidCraftingResourceMaxDurability" }; return *GetNativePointerField<float*>(this, f); }
	float& ActivationCooldownTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ActivationCooldownTime" }; return *GetNativePointerField<float*>(this, f); }
	float& UsablePriorityField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.UsablePriority" }; return *GetNativePointerField<float*>(this, f); }
	unsigned __int64& DeathCacheCharacterIDField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DeathCacheCharacterID" }; return *GetNativePointerField<unsigned __int64*>(this, f); }
	float& SinglePlayerFuelConsumptionIntervalsMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.SinglePlayerFuelConsumptionIntervalsMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& PoweredBatteryDurabilityToDecreasePerSecondField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.PoweredBatteryDurabilityToDecreasePerSecond" }; return *GetNativePointerField<float*>(this, f); }
	float& DropInventoryDepositTraceDistanceField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.DropInventoryDepositTraceDistance" }; return *GetNativePointerField<float*>(this, f); }
	TArray<TWeakObjectPtr<AShooterPlayerController>>& ValidatedByPinCodePlayerControllersField() { static NativeFieldOffset f{ "APrimalStructureItemContainer.ValidatedByPinCodePlayerControllers" }; return *GetNativePointerField<TArray<TWeakObjectPtr<AShooterPlayerController>>*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bAutoActivateContainer() { static NativeBitField f{ "APrimalStructureItemContainer.bAutoActivateContainer" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCanToggleActivation() { static NativeBitField f{ "APrimalStructureItemContainer.bCanToggleActivation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoActivateWhenFueled() { static NativeBitField f{ "APrimalStructureItemContainer.bAutoActivateWhenFueled" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowCustomName() { static NativeBitField f{ "APrimalStructureItemContainer.bAllowCustomName" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bContainerActivated() { static NativeBitField f{ "APrimalStructureItemContainer.bContainerActivated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyUseSpoilingMultipliersIfActivated() { static NativeBitField f{ "APrimalStructureItemContainer.bOnlyUseSpoilingMultipliersIfActivated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCraftingSubstractConnectedWater() { static NativeBitField f{ "APrimalStructureItemContainer.bCraftingSubstractConnectedWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForceNoPinLocking() { static NativeBitField f{ "APrimalStructureItemContainer.bForceNoPinLocking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bServerBPNotifyInventoryItemChanges() { static NativeBitField f{ "APrimalStructureItemContainer.bServerBPNotifyInventoryItemChanges" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bClientBPNotifyInventoryItemChanges() { static NativeBitField f{ "APrimalStructureItemContainer.bClientBPNotifyInventoryItemChanges" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisplayActivationOnInventoryUI() { static NativeBitField f{ "APrimalStructureItemContainer.bDisplayActivationOnInventoryUI" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetFuelConsumptionMultiplier() { static NativeBitField f{ "APrimalStructureItemContainer.bUseBPGetFuelConsumptionMultiplier" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPreventToggleActivation() { static NativeBitField f{ "APrimalStructureItemContainer.bPreventToggleActivation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bServerBPNotifyInventoryItemChangesUseQuantity() { static NativeBitField f{ "APrimalStructureItemContainer.bServerBPNotifyInventoryItemChangesUseQuantity" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bStartedUnderwater() { static NativeBitField f{ "APrimalStructureItemContainer.bStartedUnderwater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bCheckStartedUnderwater() { static NativeBitField f{ "APrimalStructureItemContainer.bCheckStartedUnderwater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisplayActivationOnInventoryUISecondary() { static NativeBitField f{ "APrimalStructureItemContainer.bDisplayActivationOnInventoryUISecondary" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisplayActivationOnInventoryUITertiary() { static NativeBitField f{ "APrimalStructureItemContainer.bDisplayActivationOnInventoryUITertiary" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bFuelAllowActivationWhenNoPower() { static NativeBitField f{ "APrimalStructureItemContainer.bFuelAllowActivationWhenNoPower" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPoweredAllowBattery() { static NativeBitField f{ "APrimalStructureItemContainer.bPoweredAllowBattery" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPoweredUsingBattery() { static NativeBitField f{ "APrimalStructureItemContainer.bPoweredUsingBattery" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPoweredHasBattery() { static NativeBitField f{ "APrimalStructureItemContainer.bPoweredHasBattery" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPoweredAllowSolar() { static NativeBitField f{ "APrimalStructureItemContainer.bPoweredAllowSolar" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPoweredUsingSolar() { static NativeBitField f{ "APrimalStructureItemContainer.bPoweredUsingSolar" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> UseBPApplyPinCode() { static NativeBitField f{ "APrimalStructureItemContainer.UseBPApplyPinCode" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsLocked() { static NativeBitField f{ "APrimalStructureItemContainer.bIsLocked" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPinLocked() { static NativeBitField f{ "APrimalStructureItemContainer.bIsPinLocked" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHasFuel() { static NativeBitField f{ "APrimalStructureItemContainer.bHasFuel" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsUnderwater() { static NativeBitField f{ "APrimalStructureItemContainer.bIsUnderwater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDisableActivationUnderwater() { static NativeBitField f{ "APrimalStructureItemContainer.bDisableActivationUnderwater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventAutoActivateWhenConnectedToWater() { static NativeBitField f{ "APrimalStructureItemContainer.bForcePreventAutoActivateWhenConnectedToWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupportsLocking() { static NativeBitField f{ "APrimalStructureItemContainer.bSupportsLocking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupportsPinLocking() { static NativeBitField f{ "APrimalStructureItemContainer.bSupportsPinLocking" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDropInventoryOnDestruction() { static NativeBitField f{ "APrimalStructureItemContainer.bDropInventoryOnDestruction" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyWhenAllItemsRemoved() { static NativeBitField f{ "APrimalStructureItemContainer.bDestroyWhenAllItemsRemoved" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDrinkingWater() { static NativeBitField f{ "APrimalStructureItemContainer.bDrinkingWater" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bPoweredWaterSourceWhenActive() { static NativeBitField f{ "APrimalStructureItemContainer.bPoweredWaterSourceWhenActive" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bActiveRequiresPower() { static NativeBitField f{ "APrimalStructureItemContainer.bActiveRequiresPower" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPowerJunction() { static NativeBitField f{ "APrimalStructureItemContainer.bIsPowerJunction" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoActivateIfPowered() { static NativeBitField f{ "APrimalStructureItemContainer.bAutoActivateIfPowered" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bLastToggleActivated() { static NativeBitField f{ "APrimalStructureItemContainer.bLastToggleActivated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bSupportsPinActivation() { static NativeBitField f{ "APrimalStructureItemContainer.bSupportsPinActivation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bIsPowered() { static NativeBitField f{ "APrimalStructureItemContainer.bIsPowered" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bOnlyAllowTeamActivation() { static NativeBitField f{ "APrimalStructureItemContainer.bOnlyAllowTeamActivation" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReplicateItemFuelClass() { static NativeBitField f{ "APrimalStructureItemContainer.bReplicateItemFuelClass" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseOpenSceneAction() { static NativeBitField f{ "APrimalStructureItemContainer.bUseOpenSceneAction" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHandledDestruction() { static NativeBitField f{ "APrimalStructureItemContainer.bHandledDestruction" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPActivated() { static NativeBitField f{ "APrimalStructureItemContainer.bUseBPActivated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanBeActivated() { static NativeBitField f{ "APrimalStructureItemContainer.bUseBPCanBeActivated" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanBeActivatedByPlayer() { static NativeBitField f{ "APrimalStructureItemContainer.bUseBPCanBeActivatedByPlayer" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPOnContainerActiveHealthDecrease() { static NativeBitField f{ "APrimalStructureItemContainer.bBPOnContainerActiveHealthDecrease" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bBPIsValidWaterSourceForPipe() { static NativeBitField f{ "APrimalStructureItemContainer.bBPIsValidWaterSourceForPipe" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAllowAutoActivateWhenNoPower() { static NativeBitField f{ "APrimalStructureItemContainer.bAllowAutoActivateWhenNoPower" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bAutoActivateWhenNoPower() { static NativeBitField f{ "APrimalStructureItemContainer.bAutoActivateWhenNoPower" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bRequiresItemExactClass() { static NativeBitField f{ "APrimalStructureItemContainer.bRequiresItemExactClass" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDestroyWhenAllItemsRemovedExceptDefaults() { static NativeBitField f{ "APrimalStructureItemContainer.bDestroyWhenAllItemsRemovedExceptDefaults" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInventoryForcePreventRemoteAddItems() { static NativeBitField f{ "APrimalStructureItemContainer.bInventoryForcePreventRemoteAddItems" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bInventoryForcePreventItemAppends() { static NativeBitField f{ "APrimalStructureItemContainer.bInventoryForcePreventItemAppends" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bDidSetContainerActive() { static NativeBitField f{ "APrimalStructureItemContainer.bDidSetContainerActive" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseDeathCacheCharacterID() { static NativeBitField f{ "APrimalStructureItemContainer.bUseDeathCacheCharacterID" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bHideAutoActivateToggle() { static NativeBitField f{ "APrimalStructureItemContainer.bHideAutoActivateToggle" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseCooldownOnTransferAll() { static NativeBitField f{ "APrimalStructureItemContainer.bUseCooldownOnTransferAll" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bUseBPSetPlayerConstructor() { static NativeBitField f{ "APrimalStructureItemContainer.bUseBPSetPlayerConstructor" }; return { this, f }; }
	BitFieldValue<bool, unsigned __int32> bReplicateLastActivatedTime() { static NativeBitField f{ "APrimalStructureItemContainer.bReplicateLastActivatedTime" }; return { this, f }; }

	// Functions

	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	bool IsPowered() { static NativeFunction f{ "APrimalStructureItemContainer.IsPowered" }; return NativeCall<bool>(this, f); }
	bool CanBeActivated() { static NativeFunction f{ "APrimalStructureItemContainer.CanBeActivated" }; return NativeCall<bool>(this, f); }
	bool AllowToggleActivation(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.AllowToggleActivation" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureItemContainer.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	float SubtractWaterFromConnections(float Amount, bool bAllowNetworking) { static NativeFunction f{ "APrimalStructureItemContainer.SubtractWaterFromConnections" }; return NativeCall<float, float, bool>(this, f, Amount, bAllowNetworking); }
	void ClientMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureItemContainer.ClientMultiUse" }; NativeCall<void, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void PreInitializeComponents() { static NativeFunction f{ "APrimalStructureItemContainer.PreInitializeComponents" }; NativeCall<void>(this, f); }
	void BeginPlay() { static NativeFunction f{ "APrimalStructureItemContainer.BeginPlay" }; NativeCall<void>(this, f); }
	void CheckForDeathCacheEmitter() { static NativeFunction f{ "APrimalStructureItemContainer.CheckForDeathCacheEmitter" }; NativeCall<void>(this, f); }
	void PlacedStructureLocation() { static NativeFunction f{ "APrimalStructureItemContainer.PlacedStructureLocation" }; NativeCall<void>(this, f); }
	void Stasis() { static NativeFunction f{ "APrimalStructureItemContainer.Stasis" }; NativeCall<void>(this, f); }
	void Unstasis() { static NativeFunction f{ "APrimalStructureItemContainer.Unstasis" }; NativeCall<void>(this, f); }
	void PlacedStructure(AShooterPlayerController* PC) { static NativeFunction f{ "APrimalStructureItemContainer.PlacedStructure" }; NativeCall<void, AShooterPlayerController*>(this, f, PC); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructureItemContainer.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	USoundBase* GetOverrideAudioTemplate() { static NativeFunction f{ "APrimalStructureItemContainer.GetOverrideAudioTemplate" }; return NativeCall<USoundBase*>(this, f); }
	bool IsValidWaterSourceForPipe(APrimalStructureWaterPipe* ForWaterPipe) { static NativeFunction f{ "APrimalStructureItemContainer.IsValidWaterSourceForPipe" }; return NativeCall<bool, APrimalStructureWaterPipe*>(this, f, ForWaterPipe); }
	void SetDelayedActivation() { static NativeFunction f{ "APrimalStructureItemContainer.SetDelayedActivation" }; NativeCall<void>(this, f); }
	void TryActivation() { static NativeFunction f{ "APrimalStructureItemContainer.TryActivation" }; NativeCall<void>(this, f); }
	void SetContainerActive(bool bNewActive) { static NativeFunction f{ "APrimalStructureItemContainer.SetContainerActive" }; NativeCall<void, bool>(this, f, bNewActive); }
	FString* GetDebugInfoString(FString* result) { static NativeFunction f{ "APrimalStructureItemContainer.GetDebugInfoString" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool CanOpen(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.CanOpen" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	void ServerCloseRemoteInventory(AShooterPlayerController* ByPC) { static NativeFunction f{ "APrimalStructureItemContainer.ServerCloseRemoteInventory" }; NativeCall<void, AShooterPlayerController*>(this, f, ByPC); }
	bool VerifyPinCode(int pinCode) { static NativeFunction f{ "APrimalStructureItemContainer.VerifyPinCode" }; return NativeCall<bool, int>(this, f, pinCode); }
	bool HasSamePinCode(APrimalStructureItemContainer* otherContainer) { static NativeFunction f{ "APrimalStructureItemContainer.HasSamePinCode" }; return NativeCall<bool, APrimalStructureItemContainer*>(this, f, otherContainer); }
	bool IsPinLocked() { static NativeFunction f{ "APrimalStructureItemContainer.IsPinLocked" }; return NativeCall<bool>(this, f); }
	int GetPinCode() { static NativeFunction f{ "APrimalStructureItemContainer.GetPinCode" }; return NativeCall<int>(this, f); }
	int AddToValidatedByPinCodePlayerControllers(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.AddToValidatedByPinCodePlayerControllers" }; return NativeCall<int, AShooterPlayerController*>(this, f, ForPC); }
	bool IsValidatedPinCodePlayerController(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.IsValidatedPinCodePlayerController" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	FString* GetDescriptiveName(FString* result) { static NativeFunction f{ "APrimalStructureItemContainer.GetDescriptiveName" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool ApplyPinCode(AShooterPlayerController* ForPC, int appledPinCode, bool bIsSetting, int TheCustomIndex) { static NativeFunction f{ "APrimalStructureItemContainer.ApplyPinCode" }; return NativeCall<bool, AShooterPlayerController*, int, bool, int>(this, f, ForPC, appledPinCode, bIsSetting, TheCustomIndex); }
	bool RemoteInventoryAllowViewing(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.RemoteInventoryAllowViewing" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	bool RemoteInventoryAllowActivation(AShooterPlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.RemoteInventoryAllowActivation" }; return NativeCall<bool, AShooterPlayerController*>(this, f, ForPC); }
	void UpdateContainerActiveHealthDecrease() { static NativeFunction f{ "APrimalStructureItemContainer.UpdateContainerActiveHealthDecrease" }; NativeCall<void>(this, f); }
	void CheckAutoReactivate() { static NativeFunction f{ "APrimalStructureItemContainer.CheckAutoReactivate" }; NativeCall<void>(this, f); }
	void ConsumeFuel(bool bGiveItem) { static NativeFunction f{ "APrimalStructureItemContainer.ConsumeFuel" }; NativeCall<void, bool>(this, f, bGiveItem); }
	void NotifyItemQuantityUpdated(UPrimalItem* anItem, int amount) { static NativeFunction f{ "APrimalStructureItemContainer.NotifyItemQuantityUpdated" }; NativeCall<void, UPrimalItem*, int>(this, f, anItem, amount); }
	void NotifyItemAdded(UPrimalItem* anItem, bool bEquipItem) { static NativeFunction f{ "APrimalStructureItemContainer.NotifyItemAdded" }; NativeCall<void, UPrimalItem*, bool>(this, f, anItem, bEquipItem); }
	void DeferredNotifyItemAdded() { static NativeFunction f{ "APrimalStructureItemContainer.DeferredNotifyItemAdded" }; NativeCall<void>(this, f); }
	void CheckFuelSetActive() { static NativeFunction f{ "APrimalStructureItemContainer.CheckFuelSetActive" }; NativeCall<void>(this, f); }
	void NotifyItemRemoved(UPrimalItem* anItem) { static NativeFunction f{ "APrimalStructureItemContainer.NotifyItemRemoved" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	void ClientNotifyInventoryItemChange(bool bIsItemAdd, UPrimalItem* theItem, bool bEquipItem) { static NativeFunction f{ "APrimalStructureItemContainer.ClientNotifyInventoryItemChange" }; NativeCall<void, bool, UPrimalItem*, bool>(this, f, bIsItemAdd, theItem, bEquipItem); }
	void RefreshFuelState() { static NativeFunction f{ "APrimalStructureItemContainer.RefreshFuelState" }; NativeCall<void>(this, f); }
	bool UseItemSpoilingTimeMultipliers() { static NativeFunction f{ "APrimalStructureItemContainer.UseItemSpoilingTimeMultipliers" }; return NativeCall<bool>(this, f); }
	void UpdateSolarPower() { static NativeFunction f{ "APrimalStructureItemContainer.UpdateSolarPower" }; NativeCall<void>(this, f); }
	void CharacterBasedOnUpdate(AActor* characterBasedOnMe, float DeltaSeconds) { static NativeFunction f{ "APrimalStructureItemContainer.CharacterBasedOnUpdate" }; NativeCall<void, AActor*, float>(this, f, characterBasedOnMe, DeltaSeconds); }
	bool AllowSaving() { static NativeFunction f{ "APrimalStructureItemContainer.AllowSaving" }; return NativeCall<bool>(this, f); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalStructureItemContainer.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	void ProcessEditText(AShooterPlayerController* ForPC, FString* TextToUse, bool bCheckedBox) { static NativeFunction f{ "APrimalStructureItemContainer.ProcessEditText" }; NativeCall<void, AShooterPlayerController*, FString*, bool>(this, f, ForPC, TextToUse, bCheckedBox); }
	void NetUpdateLocation_Implementation(FVector NewLocation) { static NativeFunction f{ "APrimalStructureItemContainer.NetUpdateLocation_Implementation" }; NativeCall<void, FVector>(this, f, NewLocation); }
	void NetSetContainerActive_Implementation(bool bSetActive, TSubclassOf<UPrimalItem> NetReplicatedFuelItemClass, __int16 NetReplicatedFuelItemColorIndex) { static NativeFunction f{ "APrimalStructureItemContainer.NetSetContainerActive_Implementation" }; NativeCall<void, bool, TSubclassOf<UPrimalItem>, __int16>(this, f, bSetActive, NetReplicatedFuelItemClass, NetReplicatedFuelItemColorIndex); }
	void NetUpdateBoxName_Implementation(FString* NewName) { static NativeFunction f{ "APrimalStructureItemContainer.NetUpdateBoxName_Implementation" }; NativeCall<void, FString*>(this, f, NewName); }
	void PlayDying(float KillingDamage, FDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructureItemContainer.PlayDying" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void SetDisabledTimer(float DisabledTime) { static NativeFunction f{ "APrimalStructureItemContainer.SetDisabledTimer" }; NativeCall<void, float>(this, f, DisabledTime); }
	void EnableActive() { static NativeFunction f{ "APrimalStructureItemContainer.EnableActive" }; NativeCall<void>(this, f); }
	void GetBlueprintSpawnActorTransform(FVector* spawnLoc, FRotator* spawnRot) { static NativeFunction f{ "APrimalStructureItemContainer.GetBlueprintSpawnActorTransform" }; NativeCall<void, FVector*, FRotator*>(this, f, spawnLoc, spawnRot); }
	bool OverrideHasWaterSource() { static NativeFunction f{ "APrimalStructureItemContainer.OverrideHasWaterSource" }; return NativeCall<bool>(this, f); }
	void RefreshPowered(APrimalStructureItemContainer* InDirectPower) { static NativeFunction f{ "APrimalStructureItemContainer.RefreshPowered" }; NativeCall<void, APrimalStructureItemContainer*>(this, f, InDirectPower); }
	void MovePowerJunctionLink() { static NativeFunction f{ "APrimalStructureItemContainer.MovePowerJunctionLink" }; NativeCall<void>(this, f); }
	void RefreshPowerJunctionLink() { static NativeFunction f{ "APrimalStructureItemContainer.RefreshPowerJunctionLink" }; NativeCall<void>(this, f); }
	void NotifyCraftedItem(UPrimalItem* anItem) { static NativeFunction f{ "APrimalStructureItemContainer.NotifyCraftedItem" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	void LoadedFromSaveGame() { static NativeFunction f{ "APrimalStructureItemContainer.LoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void CopyStructureValuesFrom(APrimalStructureItemContainer* otherItemContainer) { static NativeFunction f{ "APrimalStructureItemContainer.CopyStructureValuesFrom" }; NativeCall<void, APrimalStructureItemContainer*>(this, f, otherItemContainer); }
	void PostSpawnInitialize() { static NativeFunction f{ "APrimalStructureItemContainer.PostSpawnInitialize" }; NativeCall<void>(this, f); }
	void SetPoweredOverrideCounter(int NewPoweredOverrideCounter) { static NativeFunction f{ "APrimalStructureItemContainer.SetPoweredOverrideCounter" }; NativeCall<void, int>(this, f, NewPoweredOverrideCounter); }
	void TargetingTeamChanged() { static NativeFunction f{ "APrimalStructureItemContainer.TargetingTeamChanged" }; NativeCall<void>(this, f); }
	FSpawnPointInfo* GetSpawnPointInfo(FSpawnPointInfo* result) { static NativeFunction f{ "APrimalStructureItemContainer.GetSpawnPointInfo" }; return NativeCall<FSpawnPointInfo*, FSpawnPointInfo*>(this, f, result); }
	void SetPlayerConstructor(APlayerController* PC) { static NativeFunction f{ "APrimalStructureItemContainer.SetPlayerConstructor" }; NativeCall<void, APlayerController*>(this, f, PC); }
	float GetUsablePriority_Implementation() { static NativeFunction f{ "APrimalStructureItemContainer.GetUsablePriority_Implementation" }; return NativeCall<float>(this, f); }
	void RefreshInventoryItemCounts() { static NativeFunction f{ "APrimalStructureItemContainer.RefreshInventoryItemCounts" }; NativeCall<void>(this, f); }
	bool IsPlayerControllerInPinCodeValidationList(APlayerController* PlayerController) { static NativeFunction f{ "APrimalStructureItemContainer.IsPlayerControllerInPinCodeValidationList" }; return NativeCall<bool, APlayerController*>(this, f, PlayerController); }
	int GetDeathCacheCharacterID() { static NativeFunction f{ "APrimalStructureItemContainer.GetDeathCacheCharacterID" }; return NativeCall<int>(this, f); }
	static void StaticRegisterNativesAPrimalStructureItemContainer() { static NativeFunction f{ "APrimalStructureItemContainer.StaticRegisterNativesAPrimalStructureItemContainer" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "APrimalStructureItemContainer.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	bool BPApplyPinCode(AShooterPlayerController* ForPC, int appledPinCode, bool bIsSetting, int TheCustomIndex) { static NativeFunction f{ "APrimalStructureItemContainer.BPApplyPinCode" }; return NativeCall<bool, AShooterPlayerController*, int, bool, int>(this, f, ForPC, appledPinCode, bIsSetting, TheCustomIndex); }
	bool BPCanBeActivated() { static NativeFunction f{ "APrimalStructureItemContainer.BPCanBeActivated" }; return NativeCall<bool>(this, f); }
	bool BPCanBeActivatedByPlayer(AShooterPlayerController* PC) { static NativeFunction f{ "APrimalStructureItemContainer.BPCanBeActivatedByPlayer" }; return NativeCall<bool, AShooterPlayerController*>(this, f, PC); }
	void BPContainerActivated() { static NativeFunction f{ "APrimalStructureItemContainer.BPContainerActivated" }; NativeCall<void>(this, f); }
	void BPContainerDeactivated() { static NativeFunction f{ "APrimalStructureItemContainer.BPContainerDeactivated" }; NativeCall<void>(this, f); }
	float BPGetFuelConsumptionMultiplier() { static NativeFunction f{ "APrimalStructureItemContainer.BPGetFuelConsumptionMultiplier" }; return NativeCall<float>(this, f); }
	bool BPIsValidWaterSourceForPipe(APrimalStructureWaterPipe* ForWaterPipe) { static NativeFunction f{ "APrimalStructureItemContainer.BPIsValidWaterSourceForPipe" }; return NativeCall<bool, APrimalStructureWaterPipe*>(this, f, ForWaterPipe); }
	void BPNotifyInventoryItemChange(bool bIsItemAdd, UPrimalItem* theItem, bool bEquipItem) { static NativeFunction f{ "APrimalStructureItemContainer.BPNotifyInventoryItemChange" }; NativeCall<void, bool, UPrimalItem*, bool>(this, f, bIsItemAdd, theItem, bEquipItem); }
	void BPOnContainerActiveHealthDecrease() { static NativeFunction f{ "APrimalStructureItemContainer.BPOnContainerActiveHealthDecrease" }; NativeCall<void>(this, f); }
	void BPPreGetMultiUseEntries(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer.BPPreGetMultiUseEntries" }; NativeCall<void, APlayerController*>(this, f, ForPC); }
	void BPSetPlayerConstructor(APlayerController* PC) { static NativeFunction f{ "APrimalStructureItemContainer.BPSetPlayerConstructor" }; NativeCall<void, APlayerController*>(this, f, PC); }
	bool IsValidForDinoFeedingContainer(APrimalDinoCharacter* ForDino) { static NativeFunction f{ "APrimalStructureItemContainer.IsValidForDinoFeedingContainer" }; return NativeCall<bool, APrimalDinoCharacter*>(this, f, ForDino); }
	void NetSetContainerActive(bool bSetActive, TSubclassOf<UPrimalItem> NetReplicatedFuelItemClass, __int16 NetReplicatedFuelItemColorIndex) { static NativeFunction f{ "APrimalStructureItemContainer.NetSetContainerActive" }; NativeCall<void, bool, TSubclassOf<UPrimalItem>, __int16>(this, f, bSetActive, NetReplicatedFuelItemClass, NetReplicatedFuelItemColorIndex); }
	void NetUpdateBoxName(FString* NewName) { static NativeFunction f{ "APrimalStructureItemContainer.NetUpdateBoxName" }; NativeCall<void, FString*>(this, f, NewName); }
	void PowerGeneratorBuiltNearbyPoweredStructure(APrimalStructureItemContainer* PoweredStructure) { static NativeFunction f{ "APrimalStructureItemContainer.PowerGeneratorBuiltNearbyPoweredStructure" }; NativeCall<void, APrimalStructureItemContainer*>(this, f, PoweredStructure); }
	void GetMultiUseEntries(APlayerController* ForPC, TArray<FMultiUseEntry>* MultiUseEntries) { static NativeFunction f{ "APrimalStructureItemContainer.GetMultiUseEntries" }; NativeCall<void, APlayerController*, TArray<FMultiUseEntry>*>(this, f, ForPC, MultiUseEntries); }
};

struct APrimalStructureTurret : APrimalStructureItemContainer
{
	TWeakObjectPtr<AActor>& TargetField() { static NativeFieldOffset f{ "APrimalStructureTurret.Target" }; return *GetNativePointerField<TWeakObjectPtr<AActor>*>(this, f); }
	TSubclassOf<UPrimalItem>& AmmoItemTemplateField() { static NativeFieldOffset f{ "APrimalStructureTurret.AmmoItemTemplate" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& MuzzleFlashEmitterField() { static NativeFieldOffset f{ "APrimalStructureTurret.MuzzleFlashEmitter" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	float& FireIntervalField() { static NativeFieldOffset f{ "APrimalStructureTurret.FireInterval" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastFireTimeField() { static NativeFieldOffset f{ "APrimalStructureTurret.LastFireTime" }; return *GetNativePointerField<long double*>(this, f); }
	float& MaxFireYawDeltaField() { static NativeFieldOffset f{ "APrimalStructureTurret.MaxFireYawDelta" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxFirePitchDeltaField() { static NativeFieldOffset f{ "APrimalStructureTurret.MaxFirePitchDelta" }; return *GetNativePointerField<float*>(this, f); }
	FVector& TargetingLocOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.TargetingLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& TargetingRotationInterpSpeedField() { static NativeFieldOffset f{ "APrimalStructureTurret.TargetingRotationInterpSpeed" }; return *GetNativePointerField<float*>(this, f); }
	FieldArray<float, 3> TargetingRangesField() { static NativeFieldOffset f{ "APrimalStructureTurret.TargetingRanges" }; return { this, f }; }
	FVector& TargetingTraceOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.TargetingTraceOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	TSubclassOf<UDamageType>& FireDamageTypeField() { static NativeFieldOffset f{ "APrimalStructureTurret.FireDamageType" }; return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, f); }
	float& FireDamageAmountField() { static NativeFieldOffset f{ "APrimalStructureTurret.FireDamageAmount" }; return *GetNativePointerField<float*>(this, f); }
	float& FireDamageImpulseField() { static NativeFieldOffset f{ "APrimalStructureTurret.FireDamageImpulse" }; return *GetNativePointerField<float*>(this, f); }
	FRotator& TurretAimRotOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.TurretAimRotOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	FVector& AimTargetLocOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.AimTargetLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FVector& PlayerProneTargetOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.PlayerProneTargetOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	float& AimSpreadField() { static NativeFieldOffset f{ "APrimalStructureTurret.AimSpread" }; return *GetNativePointerField<float*>(this, f); }
	unsigned char& RangeSettingField() { static NativeFieldOffset f{ "APrimalStructureTurret.RangeSetting" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& AISettingField() { static NativeFieldOffset f{ "APrimalStructureTurret.AISetting" }; return *GetNativePointerField<unsigned char*>(this, f); }
	unsigned char& WarningSettingField() { static NativeFieldOffset f{ "APrimalStructureTurret.WarningSetting" }; return *GetNativePointerField<unsigned char*>(this, f); }
	int& NumBulletsField() { static NativeFieldOffset f{ "APrimalStructureTurret.NumBullets" }; return *GetNativePointerField<int*>(this, f); }
	int& NumBulletsPerShotField() { static NativeFieldOffset f{ "APrimalStructureTurret.NumBulletsPerShot" }; return *GetNativePointerField<int*>(this, f); }
	float& AlwaysEnableFastTurretTargetingOverVelocityField() { static NativeFieldOffset f{ "APrimalStructureTurret.AlwaysEnableFastTurretTargetingOverVelocity" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<AShooterProjectile>& ProjectileClassField() { static NativeFieldOffset f{ "APrimalStructureTurret.ProjectileClass" }; return *GetNativePointerField<TSubclassOf<AShooterProjectile>*>(this, f); }
	float& WarningExpirationTimeField() { static NativeFieldOffset f{ "APrimalStructureTurret.WarningExpirationTime" }; return *GetNativePointerField<float*>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& WarningEmitterShortField() { static NativeFieldOffset f{ "APrimalStructureTurret.WarningEmitterShort" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	TSubclassOf<APrimalEmitterSpawnable>& WarningEmitterLongField() { static NativeFieldOffset f{ "APrimalStructureTurret.WarningEmitterLong" }; return *GetNativePointerField<TSubclassOf<APrimalEmitterSpawnable>*>(this, f); }
	float& BatteryIntervalFromActivationBeforeFiringField() { static NativeFieldOffset f{ "APrimalStructureTurret.BatteryIntervalFromActivationBeforeFiring" }; return *GetNativePointerField<float*>(this, f); }
	bool& bWarnedField() { static NativeFieldOffset f{ "APrimalStructureTurret.bWarned" }; return *GetNativePointerField<bool*>(this, f); }
	UChildActorComponent* MyChildEmitterTargetingEffectField() { static NativeFieldOffset f{ "APrimalStructureTurret.MyChildEmitterTargetingEffect" }; return *GetNativePointerField<UChildActorComponent**>(this, f); }
	FRotator& DefaultTurretAimRotOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.DefaultTurretAimRotOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	FVector& MuzzleLocOffsetField() { static NativeFieldOffset f{ "APrimalStructureTurret.MuzzleLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	long double& LastWarningTimeField() { static NativeFieldOffset f{ "APrimalStructureTurret.LastWarningTime" }; return *GetNativePointerField<long double*>(this, f); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bClientFireProjectile() { static NativeBitField f{ "APrimalStructureTurret.bClientFireProjectile" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bUseInstantDamageShooting() { ReportDeprecatedApiUse("APrimalStructureTurret.bUseInstantDamageShooting"); static NativeBitField f{ "APrimalStructureTurret.bUseInstantDamageShooting" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bDisableInElectricalStorm() { ReportDeprecatedApiUse("APrimalStructureTurret.bDisableInElectricalStorm"); static NativeBitField f{ "APrimalStructureTurret.bDisableInElectricalStorm" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bUseBallistaAimOffsetOnCharacter() { ReportDeprecatedApiUse("APrimalStructureTurret.bUseBallistaAimOffsetOnCharacter"); static NativeBitField f{ "APrimalStructureTurret.bUseBallistaAimOffsetOnCharacter" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bIsReloading() { ReportDeprecatedApiUse("APrimalStructureTurret.bIsReloading"); static NativeBitField f{ "APrimalStructureTurret.bIsReloading" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bIsFiring() { ReportDeprecatedApiUse("APrimalStructureTurret.bIsFiring"); static NativeBitField f{ "APrimalStructureTurret.bIsFiring" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bFireProjectileInvertX() { ReportDeprecatedApiUse("APrimalStructureTurret.bFireProjectileInvertX"); static NativeBitField f{ "APrimalStructureTurret.bFireProjectileInvertX" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bShowProjectileOnlyBasedOnAmmo() { ReportDeprecatedApiUse("APrimalStructureTurret.bShowProjectileOnlyBasedOnAmmo"); static NativeBitField f{ "APrimalStructureTurret.bShowProjectileOnlyBasedOnAmmo" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bHideProjectileBone() { ReportDeprecatedApiUse("APrimalStructureTurret.bHideProjectileBone"); static NativeBitField f{ "APrimalStructureTurret.bHideProjectileBone" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bUseBPCanFire() { ReportDeprecatedApiUse("APrimalStructureTurret.bUseBPCanFire"); static NativeBitField f{ "APrimalStructureTurret.bUseBPCanFire" }; return { this, f }; }
	[[deprecated("not in this game build")]] BitFieldValue<bool, unsigned __int32> bHideProjectileBoneOnAttachedModule() { ReportDeprecatedApiUse("APrimalStructureTurret.bHideProjectileBoneOnAttachedModule"); static NativeBitField f{ "APrimalStructureTurret.bHideProjectileBoneOnAttachedModule" }; return { this, f }; }

	// Functions

	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureTurret.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	void BeginPlay() { static NativeFunction f{ "APrimalStructureTurret.BeginPlay" }; NativeCall<void>(this, f); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructureTurret.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	AActor* FindTarget() { static NativeFunction f{ "APrimalStructureTurret.FindTarget" }; return NativeCall<AActor*>(this, f); }
	void SetTarget(AActor* aTarget) { static NativeFunction f{ "APrimalStructureTurret.SetTarget" }; NativeCall<void, AActor*>(this, f, aTarget); }
	void WeaponTraceHits(TArray<FHitResult>* HitResults, FVector* StartTrace, FVector* EndTrace) { static NativeFunction f{ "APrimalStructureTurret.WeaponTraceHits" }; NativeCall<void, TArray<FHitResult>*, FVector*, FVector*>(this, f, HitResults, StartTrace, EndTrace); }
	bool NetExecCommand(FName CommandName, FNetExecParams* ExecParams) { static NativeFunction f{ "APrimalStructureTurret.NetExecCommand" }; return NativeCall<bool, FName, FNetExecParams*>(this, f, CommandName, ExecParams); }
	void DoFire(int RandomSeed) { static NativeFunction f{ "APrimalStructureTurret.DoFire" }; NativeCall<void, int>(this, f, RandomSeed); }
	void DoFireProjectile(FVector Origin, FVector ShootDir) { static NativeFunction f{ "APrimalStructureTurret.DoFireProjectile" }; NativeCall<void, FVector, FVector>(this, f, Origin, ShootDir); }
	void ClientsFireProjectile_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir) { static NativeFunction f{ "APrimalStructureTurret.ClientsFireProjectile_Implementation" }; NativeCall<void, FVector, FVector_NetQuantizeNormal>(this, f, Origin, ShootDir); }
	void SpawnImpactEffects(FHitResult* Impact, FVector* ShootDir) { static NativeFunction f{ "APrimalStructureTurret.SpawnImpactEffects" }; NativeCall<void, FHitResult*, FVector*>(this, f, Impact, ShootDir); }
	void SpawnTrailEffect(FVector* EndPoint) { static NativeFunction f{ "APrimalStructureTurret.SpawnTrailEffect" }; NativeCall<void, FVector*>(this, f, EndPoint); }
	bool ShouldDealDamage(AActor* TestActor) { static NativeFunction f{ "APrimalStructureTurret.ShouldDealDamage" }; return NativeCall<bool, AActor*>(this, f, TestActor); }
	void DealDamage(FHitResult* Impact, FVector* ShootDir, int DamageAmount, TSubclassOf<UDamageType> DamageType, float Impulse) { static NativeFunction f{ "APrimalStructureTurret.DealDamage" }; NativeCall<void, FHitResult*, FVector*, int, TSubclassOf<UDamageType>, float>(this, f, Impact, ShootDir, DamageAmount, DamageType, Impulse); }
	void StartWarning() { static NativeFunction f{ "APrimalStructureTurret.StartWarning" }; NativeCall<void>(this, f); }
	void FinishWarning() { static NativeFunction f{ "APrimalStructureTurret.FinishWarning" }; NativeCall<void>(this, f); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "APrimalStructureTurret.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalStructureTurret.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	bool IsValidToFire() { static NativeFunction f{ "APrimalStructureTurret.IsValidToFire" }; return NativeCall<bool>(this, f); }
	FRotator* GetMuzzleRotation(FRotator* result) { static NativeFunction f{ "APrimalStructureTurret.GetMuzzleRotation" }; return NativeCall<FRotator*, FRotator*>(this, f, result); }
	FVector* GetMuzzleLocation(FVector* result) { static NativeFunction f{ "APrimalStructureTurret.GetMuzzleLocation" }; return NativeCall<FVector*, FVector*>(this, f, result); }
	FVector* GetAttackingFromLocation(FVector* result) { static NativeFunction f{ "APrimalStructureTurret.GetAttackingFromLocation" }; return NativeCall<FVector*, FVector*>(this, f, result); }
	FVector* GetAimPivotLocation(FVector* result) { static NativeFunction f{ "APrimalStructureTurret.GetAimPivotLocation" }; return NativeCall<FVector*, FVector*>(this, f, result); }
	FName* GetMuzzleFlashSocketName(FName* result) { static NativeFunction f{ "APrimalStructureTurret.GetMuzzleFlashSocketName" }; return NativeCall<FName*, FName*>(this, f, result); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureTurret.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void ClientMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureTurret.ClientMultiUse" }; NativeCall<void, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void NotifyItemRemoved(UPrimalItem* anItem) { static NativeFunction f{ "APrimalStructureTurret.NotifyItemRemoved" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	void NotifyItemAdded(UPrimalItem* anItem, bool bEquipItem) { static NativeFunction f{ "APrimalStructureTurret.NotifyItemAdded" }; NativeCall<void, UPrimalItem*, bool>(this, f, anItem, bEquipItem); }
	void NotifyItemQuantityUpdated(UPrimalItem* anItem, int amount) { static NativeFunction f{ "APrimalStructureTurret.NotifyItemQuantityUpdated" }; NativeCall<void, UPrimalItem*, int>(this, f, anItem, amount); }
	void UpdateNumBullets() { static NativeFunction f{ "APrimalStructureTurret.UpdateNumBullets" }; NativeCall<void>(this, f); }
	void PreInitializeComponents() { static NativeFunction f{ "APrimalStructureTurret.PreInitializeComponents" }; NativeCall<void>(this, f); }
	void Stasis() { static NativeFunction f{ "APrimalStructureTurret.Stasis" }; NativeCall<void>(this, f); }
	void Unstasis() { static NativeFunction f{ "APrimalStructureTurret.Unstasis" }; NativeCall<void>(this, f); }
	void UpdatedTargeting() { static NativeFunction f{ "APrimalStructureTurret.UpdatedTargeting" }; NativeCall<void>(this, f); }
	FVector* GetTargetAimAtLocation(FVector* result) { static NativeFunction f{ "APrimalStructureTurret.GetTargetAimAtLocation" }; return NativeCall<FVector*, FVector*>(this, f, result); }
	FVector* GetTargetFireAtLocation(FVector* result, APrimalCharacter* ForTarget) { static NativeFunction f{ "APrimalStructureTurret.GetTargetFireAtLocation" }; return NativeCall<FVector*, FVector*, APrimalCharacter*>(this, f, result, ForTarget); }
	bool CanFire() { static NativeFunction f{ "APrimalStructureTurret.CanFire" }; return NativeCall<bool>(this, f); }
	FName* GetTargetAltAimSocket(FName* result, APrimalCharacter* ForTarget) { static NativeFunction f{ "APrimalStructureTurret.GetTargetAltAimSocket" }; return NativeCall<FName*, FName*, APrimalCharacter*>(this, f, result, ForTarget); }
	bool IsTurretFastTargetingAutoEnabled() { static NativeFunction f{ "APrimalStructureTurret.IsTurretFastTargetingAutoEnabled" }; return NativeCall<bool>(this, f); }
	bool UseTurretFastTargeting(bool bCheckFastTargetingAutoEnabled) { static NativeFunction f{ "APrimalStructureTurret.UseTurretFastTargeting" }; return NativeCall<bool, bool>(this, f, bCheckFastTargetingAutoEnabled); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureTurret.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static void StaticRegisterNativesAPrimalStructureTurret() { static NativeFunction f{ "APrimalStructureTurret.StaticRegisterNativesAPrimalStructureTurret" }; NativeCall<void>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "APrimalStructureTurret.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }
	bool BPTurretPreventsTargeting(APrimalCharacter* PotentialTarget) { static NativeFunction f{ "APrimalStructureTurret.BPTurretPreventsTargeting" }; return NativeCall<bool, APrimalCharacter*>(this, f, PotentialTarget); }
};

struct APrimalStructureItemContainer_CropPlot : APrimalStructureItemContainer
{
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer_CropPlot.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer_CropPlot.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	//char __padding[0xe8L];
	float& CropRefreshIntervalMinField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.CropRefreshIntervalMin" }; return *GetNativePointerField<float*>(this, f); }
	float& CropRefreshIntervalMaxField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.CropRefreshIntervalMax" }; return *GetNativePointerField<float*>(this, f); }
	float& WaterNearbyStructureRangeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.WaterNearbyStructureRange" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxWaterAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.MaxWaterAmount" }; return *GetNativePointerField<float*>(this, f); }
	float& ActiveRainWaterIncreaseSpeedField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.ActiveRainWaterIncreaseSpeed" }; return *GetNativePointerField<float*>(this, f); }
	float& AverageRainWaterIncreaseMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.AverageRainWaterIncreaseMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& WaterItemAmountMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.WaterItemAmountMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	FVector& ExtraCropMeshScaleField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.ExtraCropMeshScale" }; return *GetNativePointerField<FVector*>(this, f); }
	float& CropRefreshIntervalField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.CropRefreshInterval" }; return *GetNativePointerField<float*>(this, f); }
	float& CropPhaseFertilizerCacheField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.CropPhaseFertilizerCache" }; return *GetNativePointerField<float*>(this, f); }
	float& CropFruitFertilizerCacheField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.CropFruitFertilizerCache" }; return *GetNativePointerField<float*>(this, f); }
	//TEnumAsByte<enum ESeedCropPhase::Type>& CurrentCropPhaseField() { return *GetNativePointerField<TEnumAsByte<enum ESeedCropPhase::Type>*>(this, "APrimalStructureItemContainer_CropPlot.CurrentCropPhase"); }
	long double& LastCropRefreshTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.LastCropRefreshTime" }; return *GetNativePointerField<long double*>(this, f); }
	bool& bDelayCropRefreshField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.bDelayCropRefresh" }; return *GetNativePointerField<bool*>(this, f); }
	long double& NextAllowedCropRefreshTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.NextAllowedCropRefreshTime" }; return *GetNativePointerField<long double*>(this, f); }
	long double& CropRefreshTimeCacheField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.CropRefreshTimeCache" }; return *GetNativePointerField<long double*>(this, f); }
	int& FertilizerAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.FertilizerAmount" }; return *GetNativePointerField<int*>(this, f); }
	float& WaterAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.WaterAmount" }; return *GetNativePointerField<float*>(this, f); }
	unsigned char& NumGreenHouseStructuresField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.NumGreenHouseStructures" }; return *GetNativePointerField<unsigned char*>(this, f); }
	bool& bIsOpenToSkyField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.bIsOpenToSky" }; return *GetNativePointerField<bool*>(this, f); }
	float& FertilizerConsumptionRateMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.FertilizerConsumptionRateMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& LastReplicatedWaterAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.LastReplicatedWaterAmount" }; return *GetNativePointerField<float*>(this, f); }
	int& LastReplicatedFertilizerAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.LastReplicatedFertilizerAmount" }; return *GetNativePointerField<int*>(this, f); }
	float& LastWaterAmountField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.LastWaterAmount" }; return *GetNativePointerField<float*>(this, f); }
	float& MinWateredOverridesCraftingField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.MinWateredOverridesCrafting" }; return *GetNativePointerField<float*>(this, f); }
	int& MaxGreenHouseStructuresField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.MaxGreenHouseStructures" }; return *GetNativePointerField<int*>(this, f); }
	float& MaxGreenHouseCropGrowthMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.MaxGreenHouseCropGrowthMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& GainWaterRateField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.GainWaterRate" }; return *GetNativePointerField<float*>(this, f); }
	long double& LastForceReplicatedGreenhouseTimeField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_CropPlot.LastForceReplicatedGreenhouseTime" }; return *GetNativePointerField<long double*>(this, f); }

	// Functions

	bool AllowRemoteAddItemToInventory(UPrimalInventoryComponent* invComp, UPrimalItem* anItem) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.AllowRemoteAddItemToInventory" }; return NativeCall<bool, UPrimalInventoryComponent*, UPrimalItem*>(this, f, invComp, anItem); }
	void RefreshOpenToSky() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RefreshOpenToSky" }; NativeCall<void>(this, f); }
	void Tick(float DeltaTime) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.Tick" }; NativeCall<void, float>(this, f, DeltaTime); }
	void AutoWaterRefreshCrop() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.AutoWaterRefreshCrop" }; NativeCall<void>(this, f); }
	void DoRefreshCrop() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.DoRefreshCrop" }; NativeCall<void>(this, f); }
	void PostInitializeComponents() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.PostInitializeComponents" }; NativeCall<void>(this, f); }
	void Unstasis() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.Unstasis" }; NativeCall<void>(this, f); }
	float AddWater(float Amount, bool bAllowNetworking) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.AddWater" }; return NativeCall<float, float, bool>(this, f, Amount, bAllowNetworking); }
	bool RefreshCrop(float DeltaTime) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RefreshCrop" }; return NativeCall<bool, float>(this, f, DeltaTime); }
	//int GetPhaseInventoryItemCount(ESeedCropPhase::Type cropPhase) { return NativeCall<int, ESeedCropPhase::Type>(this, "APrimalStructureItemContainer_CropPlot.GetPhaseInventoryItemCount", cropPhase); }
	void RefreshWatered() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RefreshWatered" }; NativeCall<void>(this, f); }
	void RefreshWaterState() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RefreshWaterState" }; NativeCall<void>(this, f); }
	void SetWaterState(bool bValue) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.SetWaterState" }; NativeCall<void, bool>(this, f, bValue); }
	void RefreshFertilized() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RefreshFertilized" }; NativeCall<void>(this, f); }
	void NotifyItemRemoved(UPrimalItem* anItem) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.NotifyItemRemoved" }; NativeCall<void, UPrimalItem*>(this, f, anItem); }
	void NotifyItemAdded(UPrimalItem* anItem, bool bEquipItem) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.NotifyItemAdded" }; NativeCall<void, UPrimalItem*, bool>(this, f, anItem, bEquipItem); }
	void DrawHUD(AShooterHUD* HUD) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.DrawHUD" }; NativeCall<void, AShooterHUD*>(this, f, HUD); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	void BeginPlay() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.BeginPlay" }; NativeCall<void>(this, f); }
	FString* GetCropName(FString* result) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.GetCropName" }; return NativeCall<FString*, FString*>(this, f, result); }
	bool AreCropRequirementsMet() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.AreCropRequirementsMet" }; return NativeCall<bool>(this, f); }
	void RemovePlantedCrop() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RemovePlantedCrop" }; NativeCall<void>(this, f); }
	//void GetMultiUseEntries(APlayerController* ForPC, TArray<FMultiUseEntry>* MultiUseEntries) { NativeCall<void, APlayerController*, TArray<FMultiUseEntry>*>(this, "APrimalStructureItemContainer_CropPlot.GetMultiUseEntries", ForPC, MultiUseEntries); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	//void OnRep_CurrentCropPhase(ESeedCropPhase::Type PrevCropPhase) { NativeCall<void, ESeedCropPhase::Type>(this, "APrimalStructureItemContainer_CropPlot.OnRep_CurrentCropPhase", PrevCropPhase); }
	void OnRep_PlantedCrop(UClass* PrevPlantedCrop) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.OnRep_PlantedCrop" }; NativeCall<void, UClass*>(this, f, PrevPlantedCrop); }
	void UpdateCropVisuals() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.UpdateCropVisuals" }; NativeCall<void>(this, f); }
	void OnRep_HasFruitItems(bool bPreviousHasFruitItems) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.OnRep_HasFruitItems" }; NativeCall<void, bool>(this, f, bPreviousHasFruitItems); }
	bool UseItemSpoilingTimeMultipliers() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.UseItemSpoilingTimeMultipliers" }; return NativeCall<bool>(this, f); }
	void InventoryItemUsed(UObject* InventoryItemObject) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.InventoryItemUsed" }; NativeCall<void, UObject*>(this, f, InventoryItemObject); }
	bool ForceAllowsInventoryUse(UObject* InventoryItemObject) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.ForceAllowsInventoryUse" }; return NativeCall<bool, UObject*>(this, f, InventoryItemObject); }
	bool NetExecCommand(FName CommandName, FNetExecParams* ExecParams) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.NetExecCommand" }; return NativeCall<bool, FName, FNetExecParams*>(this, f, CommandName, ExecParams); }
	bool OverrideHasWaterSource() { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.OverrideHasWaterSource" }; return NativeCall<bool>(this, f); }
	void PlacedStructure(AShooterPlayerController* PC) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.PlacedStructure" }; NativeCall<void, AShooterPlayerController*>(this, f, PC); }
	bool RemoteInventoryAllowViewing(APlayerController* ForPC) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.RemoteInventoryAllowViewing" }; return NativeCall<bool, APlayerController*>(this, f, ForPC); }
	void Demolish(APlayerController* ForPC, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.Demolish" }; NativeCall<void, APlayerController*, AActor*>(this, f, ForPC, DamageCauser); }
	bool OverrideBlueprintCraftingRequirement(TSubclassOf<UPrimalItem> ItemTemplate, int ItemQuantity) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.OverrideBlueprintCraftingRequirement" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, ItemQuantity); }
	bool AllowBlueprintCraftingRequirement(TSubclassOf<UPrimalItem> ItemTemplate, int ItemQuantity) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.AllowBlueprintCraftingRequirement" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, ItemQuantity); }
	bool AllowCraftingResourceConsumption(TSubclassOf<UPrimalItem> ItemTemplate, int ItemQuantity) { static NativeFunction f{ "APrimalStructureItemContainer_CropPlot.AllowCraftingResourceConsumption" }; return NativeCall<bool, TSubclassOf<UPrimalItem>, int>(this, f, ItemTemplate, ItemQuantity); }
};

struct UPrimalStructureSettings : UObject
{
	static UClass* StaticClass() { static NativeStaticClass f{ "UPrimalStructureSettings.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "UPrimalStructureSettings.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	float& DecayDestructionPeriodMultiplierField() { static NativeFieldOffset f{ "UPrimalStructureSettings.DecayDestructionPeriodMultiplier" }; return *GetNativePointerField<float*>(this, f); }
};

struct APrimalStructureExplosive : APrimalStructure
{
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureExplosive.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	char __padding[0xa0L];
	unsigned int& ConstructorPlayerDataIDField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ConstructorPlayerDataID" }; return *GetNativePointerField<unsigned int*>(this, f); }
	AShooterCharacter* ConstructorPawnField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ConstructorPawn" }; return *GetNativePointerField<AShooterCharacter**>(this, f); }
	int& ConstructorTargetingTeamField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ConstructorTargetingTeam" }; return *GetNativePointerField<int*>(this, f); }
	FVector& ExplosiveLocOffsetField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ExplosiveLocOffset" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& ExplosiveRotOffsetField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ExplosiveRotOffset" }; return *GetNativePointerField<FRotator*>(this, f); }
	float& PlacementInitialSpeedField() { static NativeFieldOffset f{ "APrimalStructureExplosive.PlacementInitialSpeed" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementMaxSpeedField() { static NativeFieldOffset f{ "APrimalStructureExplosive.PlacementMaxSpeed" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementAccelField() { static NativeFieldOffset f{ "APrimalStructureExplosive.PlacementAccel" }; return *GetNativePointerField<float*>(this, f); }
	float& ExplosionDamageField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ExplosionDamage" }; return *GetNativePointerField<float*>(this, f); }
	float& ExplosionRadiusField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ExplosionRadius" }; return *GetNativePointerField<float*>(this, f); }
	float& ExplosionImpulseField() { static NativeFieldOffset f{ "APrimalStructureExplosive.ExplosionImpulse" }; return *GetNativePointerField<float*>(this, f); }
	float& AlertDinosRangeField() { static NativeFieldOffset f{ "APrimalStructureExplosive.AlertDinosRange" }; return *GetNativePointerField<float*>(this, f); }
	int& PickUpQuantityField() { static NativeFieldOffset f{ "APrimalStructureExplosive.PickUpQuantity" }; return *GetNativePointerField<int*>(this, f); }
	float& AnimationTargetHeightField() { static NativeFieldOffset f{ "APrimalStructureExplosive.AnimationTargetHeight" }; return *GetNativePointerField<float*>(this, f); }
	float& PlacementInterpSpeedField() { static NativeFieldOffset f{ "APrimalStructureExplosive.PlacementInterpSpeed" }; return *GetNativePointerField<float*>(this, f); }
	bool& bExplosiveReadyField() { static NativeFieldOffset f{ "APrimalStructureExplosive.bExplosiveReady" }; return *GetNativePointerField<bool*>(this, f); }
	FVector& OriginalRelativeLocationField() { static NativeFieldOffset f{ "APrimalStructureExplosive.OriginalRelativeLocation" }; return *GetNativePointerField<FVector*>(this, f); }
	FRotator& OriginalRelativeRotationField() { static NativeFieldOffset f{ "APrimalStructureExplosive.OriginalRelativeRotation" }; return *GetNativePointerField<FRotator*>(this, f); }
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureExplosive.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }

	// Functions
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>* OutLifetimeProps) { static NativeFunction f{ "APrimalStructureExplosive.GetLifetimeReplicatedProps" }; NativeCall<void, TArray<FLifetimeProperty>*>(this, f, OutLifetimeProps); }
	void LoadedFromSaveGame() { static NativeFunction f{ "APrimalStructureExplosive.LoadedFromSaveGame" }; NativeCall<void>(this, f); }
	void PostSpawnInitialize() { static NativeFunction f{ "APrimalStructureExplosive.PostSpawnInitialize" }; NativeCall<void>(this, f); }
	void Tick(float DeltaSeconds) { static NativeFunction f{ "APrimalStructureExplosive.Tick" }; NativeCall<void, float>(this, f, DeltaSeconds); }
	void SetPlayerConstructor(APlayerController* PC) { static NativeFunction f{ "APrimalStructureExplosive.SetPlayerConstructor" }; NativeCall<void, APlayerController*>(this, f, PC); }
	bool CanDetonateMe(AShooterCharacter* Character, bool bUsingRemote) { static NativeFunction f{ "APrimalStructureExplosive.CanDetonateMe" }; return NativeCall<bool, AShooterCharacter*, bool>(this, f, Character, bUsingRemote); }
	void PlayDying(float KillingDamage, FDamageEvent* DamageEvent, APawn* InstigatingPawn, AActor* DamageCauser) { static NativeFunction f{ "APrimalStructureExplosive.PlayDying" }; NativeCall<void, float, FDamageEvent*, APawn*, AActor*>(this, f, KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	bool TryMultiUse(APlayerController* ForPC, int UseIndex) { static NativeFunction f{ "APrimalStructureExplosive.TryMultiUse" }; return NativeCall<bool, APlayerController*, int>(this, f, ForPC, UseIndex); }
	void PrepareAsPlacementPreview() { static NativeFunction f{ "APrimalStructureExplosive.PrepareAsPlacementPreview" }; NativeCall<void>(this, f); }
	void ApplyPlacementPreview() { static NativeFunction f{ "APrimalStructureExplosive.ApplyPlacementPreview" }; NativeCall<void>(this, f); }
	void NetDoSpawnEffects_Implementation() { static NativeFunction f{ "APrimalStructureExplosive.NetDoSpawnEffects_Implementation" }; NativeCall<void>(this, f); }
};

struct APrimalStructureItemContainer_SupplyCrate : APrimalStructureItemContainer
{
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer_SupplyCrate.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass(const wchar_t* Package) { static NativeFunction f{ "APrimalStructureItemContainer_SupplyCrate.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, Package); }

	float& MinItemSetsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.MinItemSets" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxItemSetsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.MaxItemSets" }; return *GetNativePointerField<float*>(this, f); }
	float& NumItemSetsPowerField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.NumItemSetsPower" }; return *GetNativePointerField<float*>(this, f); }
	bool& bSetsRandomWithoutReplacementField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.bSetsRandomWithoutReplacement" }; return *GetNativePointerField<bool*>(this, f); }
	float& MinQualityMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.MinQualityMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	float& MaxQualityMultiplierField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.MaxQualityMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	TArray<FSupplyCrateItemSet, FDefaultAllocator>& ItemSetsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.ItemSets" }; return *GetNativePointerField<  TArray<FSupplyCrateItemSet, FDefaultAllocator>*>(this, f); }
	TSubclassOf<UPrimalSupplyCrateItemSets>& ItemSetsOverrideField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.ItemSetsOverride" }; return *GetNativePointerField<  TSubclassOf<UPrimalSupplyCrateItemSets>*>(this, f); }
	TArray<FSupplyCrateItemSet, FDefaultAllocator>& AdditionalItemSetsField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.AdditionalItemSets" }; return *GetNativePointerField<  TArray<FSupplyCrateItemSet, FDefaultAllocator>*>(this, f); }
	TSubclassOf<UPrimalSupplyCrateItemSets>& AdditionalItemSetsOverrideField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.AdditionalItemSetsOverride" }; return *GetNativePointerField<  TSubclassOf<UPrimalSupplyCrateItemSets>*>(this, f); }
	int& RequiredLevelToAccessField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.RequiredLevelToAccess" }; return *GetNativePointerField<  int*>(this, f); }
	int& MaxLevelToAccessField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.MaxLevelToAccess" }; return *GetNativePointerField<int*>(this, f); }
	float& InitialTimeToLoseHealthField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.InitialTimeToLoseHealth" }; return *GetNativePointerField<float*>(this, f); }
	float& IntervalTimeToLoseHealthField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.IntervalTimeToLoseHealth" }; return *GetNativePointerField<float*>(this, f); }
	float& IntervalPercentHealthToLoseField() { static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.IntervalPercentHealthToLose" }; return *GetNativePointerField<float*>(this, f); }

	BitFieldValue<bool, unsigned __int32> bIsBonusCrateField() { static NativeBitField f{ "APrimalStructureItemContainer_SupplyCrate.bIsBonusCrate" }; return { this, f }; }
	[[deprecated("not in this game build")]] float& IntervalToLoseHealthAfterAccessField() { ReportDeprecatedApiUse("APrimalStructureItemContainer_SupplyCrate.IntervalToLoseHealthAfterAccess"); static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.IntervalToLoseHealthAfterAccess" }; return *GetNativePointerField<float*>(this, f); }
	[[deprecated("not in this game build")]] TSubclassOf<UPrimalItem>& ItemSetExtraItemClassField() { ReportDeprecatedApiUse("APrimalStructureItemContainer_SupplyCrate.ItemSetExtraItemClass"); static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.ItemSetExtraItemClass" }; return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, f); }
	[[deprecated("not in this game build")]] float& ItemSetExtraItemQuantityByQualityMultiplierField() { ReportDeprecatedApiUse("APrimalStructureItemContainer_SupplyCrate.ItemSetExtraItemQuantityByQualityMultiplier"); static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.ItemSetExtraItemQuantityByQualityMultiplier" }; return *GetNativePointerField<float*>(this, f); }
	[[deprecated("not in this game build")]] float& ItemSetExtraItemQuantityByQualityPowerField() { ReportDeprecatedApiUse("APrimalStructureItemContainer_SupplyCrate.ItemSetExtraItemQuantityByQualityPower"); static NativeFieldOffset f{ "APrimalStructureItemContainer_SupplyCrate.ItemSetExtraItemQuantityByQualityPower" }; return *GetNativePointerField<float*>(this, f); }
};

struct APrimalStructureItemContainer_HordeCrate : APrimalStructureItemContainer_SupplyCrate
{
	static UClass* StaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer_HordeCrate.StaticClass" }; return NativeCall<UClass*>(nullptr, f); }
	static UClass* GetPrivateStaticClass() { static NativeStaticClass f{ "APrimalStructureItemContainer_HordeCrate.GetPrivateStaticClass" }; return NativeCall<UClass*, const wchar_t*>(nullptr, f, nullptr); }
	char __padding[0xEA8];
	UMaterialInterface* ElementPostProcessMaterial;
	FVector CrateLoc;
};