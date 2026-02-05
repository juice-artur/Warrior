// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;


UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
    AWarriorEnemyCharacter();

protected:
    //~ Begin APawn Interface.
    virtual void PossessedBy(AController* NewController) override;
    //~ End APawn Interface

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    UEnemyCombatComponent* EnemyCombatComponent;

public:
    FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const
    {
        return EnemyCombatComponent;
    }

private:
    void InitEnemyStartUpData();
};
