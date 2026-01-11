// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/WarriorHeroWeapon.h"

AWarriorHeroWeapon *UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
