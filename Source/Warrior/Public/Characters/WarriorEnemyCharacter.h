// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "Characters/WarriorBaseCharacter.h"
#include "CoreMinimal.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyUIComponent;
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

    //~ Begin PawnCombatInterface Interface.
    virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
    //~ End PawnCombatInterface Interface

    //~ Begin IPawnUIInterface Interface.
    virtual UPawnUIComponent* GetPawnUIComponent() const override;
    virtual UEnemyUIComponent* GetEnemyUIComponent() const override;
    //~ End IPawnUIInterface Interface

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    UEnemyCombatComponent* EnemyCombatComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UEnemyUIComponent* EnemyUIComponent;

public:
    FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const
    {
        return EnemyCombatComponent;
    }

private:
    void InitEnemyStartUpData();
};
