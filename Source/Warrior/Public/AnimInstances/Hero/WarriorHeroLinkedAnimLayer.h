// Warrior, Copyright 2026 - 2026, Juicy, Inc

#pragma once

#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "CoreMinimal.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

class UWarriorHeroAnimInstance;
UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
    UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};
