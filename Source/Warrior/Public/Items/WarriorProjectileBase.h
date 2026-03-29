// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "WarriorProjectileBase.generated.h"

struct FGameplayEventData;
class UBoxComponent;
class UNiagaraComponent;
class UProjectileMovementComponent;

UENUM(BlueprintType)
enum class EProjectileDamagePolicy : uint8
{
    OnHit,
    OnBeginOverlap
};


UCLASS()
class WARRIOR_API AWarriorProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	AWarriorProjectileBase();

protected:
	virtual void BeginPlay() override;

    UFUNCTION()
    virtual void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
        FVector NormalImpulse, const FHitResult& Hit);

    UFUNCTION()
    virtual void OnProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Spawn Projectile Hit FX"))
    void BP_OnSpawnProjectileHitFX(const FVector& HitLocation);

protected:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
    UBoxComponent* ProjectileCollisionBox;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
    UNiagaraComponent* ProjectileNiagaraComponent;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
    UProjectileMovementComponent* ProjectileMovementComp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
    EProjectileDamagePolicy ProjectileDamagePolicy = EProjectileDamagePolicy::OnHit;

    UPROPERTY(BlueprintReadOnly, Category = "Projectile", meta = (ExposeOnSpawn = "true"))
    FGameplayEffectSpecHandle ProjectileDamageEffectSpecHandle;

private:
    void HandleApplyProjectileDamage(APawn* InHitPawn, const FGameplayEventData& InPayload);
};
