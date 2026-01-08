// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "Components/PawnExtensionComponentBase.h"
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
    void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

    UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
    AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

    UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
    AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;

public:
    UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
    FGameplayTag CurrentEquippedWeaponTag;

private:
    TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
