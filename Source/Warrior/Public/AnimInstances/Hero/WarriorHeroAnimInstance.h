// Warrior, Copyright 2026 - 2026, Juicy, Inc

#pragma once

#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "CoreMinimal.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;

UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()

public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
    AWarriorHeroCharacter* OwningHeroCharacter;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
    bool bShouldEnterRelaxState;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
    float EnterRelaxtStateThreshold = 5.f;

    float IdleElpasedTime;
};
