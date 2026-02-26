// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "HeroUIComponent.generated.h"


UCLASS()
class WARRIOR_API UHeroUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnPercentChangedDelegate OnCurrentRageChanged;
};
