// Warrior, Copyright 2026 - 2026, Juicy, Inc

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "WarriorBaseAnimInstance.generated.h"


UCLASS()
class WARRIOR_API UWarriorBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


protected:
    UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
    bool DoesOwnerHaveTag(FGameplayTag TagToCheck) const;
};
