// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "Characters/WarriorBaseCharacter.h"
#include "CoreMinimal.h"
#include "WarriorEnemyCharacter.generated.h"

class UWidgetComponent;
class UEnemyUIComponent;
class UEnemyCombatComponent;
class UBoxComponent;


UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
    AWarriorEnemyCharacter();

protected:
    virtual void BeginPlay() override;

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

    UFUNCTION()
    virtual void OnBodyCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

#if WITH_EDITOR
    //~ Begin UObject Interface.
    virtual void PostEditChangeProperty( struct FPropertyChangedEvent& PropertyChangedEvent) override;
    //~ End UObject Interface
#endif

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    UEnemyCombatComponent* EnemyCombatComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
    FName LeftHandCollisionBoxAttachBoneName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    UBoxComponent* LeftHandCollisionBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
    FName RightHandCollisionBoxAttachBoneName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    UBoxComponent* RightHandCollisionBox;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UEnemyUIComponent* EnemyUIComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UWidgetComponent* EnemyHealthWidgetComponent;

public:
    FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const
    {
        return EnemyCombatComponent;
    }

    FORCEINLINE UBoxComponent* GetLeftHandCollisionBox() const {return LeftHandCollisionBox;}
    FORCEINLINE UBoxComponent* GetRightHandCollisionBox() const {return RightHandCollisionBox;}

private:
    void InitEnemyStartUpData();
};
