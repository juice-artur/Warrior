// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "Components/Combat/PawnCombatComponent.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnCombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnCombatInterface : public UInterface
{
	GENERATED_BODY()
};


class WARRIOR_API IPawnCombatInterface
{
	GENERATED_BODY()

public:
    virtual UPawnCombatComponent* GetPawnCombatComponent() const = 0;
};
