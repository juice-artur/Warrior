// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "AbilitySystem/WarriorAbilitySystemComponent.h"


void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag &InInputTag)
{
    if (!InInputTag.IsValid())
    {
        return;
    }

    for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag))
            {
            continue;
        }

        TryActivateAbility(AbilitySpec.Handle);
    }
}
void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag &InInputTag)
{

}
