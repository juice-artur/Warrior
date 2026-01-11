// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "WarriorTypes/WarriorStructTypes.h"

#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}
