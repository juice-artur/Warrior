// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "HeroUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquippedWeaponChangedDelegate, TSoftObjectPtr<UTexture2D>, SoftWeaponIcon);



UCLASS()
class WARRIOR_API UHeroUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnPercentChangedDelegate OnCurrentRageChanged;

    UPROPERTY(BlueprintCallable,BlueprintAssignable)
    FOnEquippedWeaponChangedDelegate OnEquippedWeaponChanged;
};
