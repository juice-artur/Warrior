// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "WarriorStructTypes.generated.h"

class UWarriorHeroLinkedAnimLayer;


USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
    TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};
