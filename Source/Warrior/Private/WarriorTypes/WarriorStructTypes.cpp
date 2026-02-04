// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "WarriorTypes/WarriorStructTypes.h"

#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"


bool FWarriorHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}
