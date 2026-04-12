// Warrior, Copyright 2026 - 2026, Juicy, Inc

#pragma once

#include "Characters/WarriorBaseCharacter.h"
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WarriorHeroCharacter.generated.h"

class UHeroUIComponent;
class UHeroCombatComponent;
struct FInputActionValue;
class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;


UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
    AWarriorHeroCharacter();

    FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const
    {
        return HeroCombatComponent;
    }

    //~ Begin IPawnUIInterface Interface.
    virtual UPawnUIComponent* GetPawnUIComponent() const override;
    virtual UHeroUIComponent* GetHeroUIComponent() const override;
    //~ End IPawnUIInterface Interface

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

    //~ Begin APawn Interface.
    virtual void PossessedBy(AController* NewController) override;
    //~ End APawn Interface

    //~ Begin PawnCombatInterface Interface.
    virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
    //~ End PawnCombatInterface Interface

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    UHeroCombatComponent* HeroCombatComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
    UHeroUIComponent* HeroUIComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = CharacterData, meta = (AllowPrivateAccess = "true"))
    UDataAsset_InputConfig* InputConfigDataAsset;

    UPROPERTY()
    FVector2D SwitchDirection = FVector2D::ZeroVector;

private:
    void InputMove(const FInputActionValue& InputActionValue);
    void InputLook(const FInputActionValue& InputActionValue);

    void Input_SwitchTargetTriggered(const FInputActionValue& InputActionValue);
    void Input_SwitchTargetCompleted(const FInputActionValue& InputActionValue);

    void Input_PickUpStonesStarted(const FInputActionValue& InputActionValue);

    void InputAbilityInputPressed(FGameplayTag InInputTag);
    void InputAbilityInputReleased(FGameplayTag InInputTag);
};
