// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "WarriorAbilitySystemComponent.generated.h"


UCLASS()
class WARRIOR_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
    void OnAbilityInputPressed(const FGameplayTag& InInputTag);
    void OnAbilityInputReleased(const FGameplayTag& InInputTag);
};
