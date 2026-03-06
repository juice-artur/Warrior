// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"
#include "WarriorAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;


UCLASS()
class WARRIOR_API AWarriorAIController : public AAIController
{
	GENERATED_BODY()

public:
    AWarriorAIController(const FObjectInitializer& ObjectInitializer);

    //~ Begin IGenericTeamAgentInterface Interface.
    virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
    //~ End IGenericTeamAgentInterface Interface

protected:
    UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
    UAIPerceptionComponent* EnemyPerceptionComponent;

    UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
    UAISenseConfig_Sight* AISenseConfig_Sight;

protected:
    UFUNCTION()
    virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    virtual void BeginPlay() override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config")
    bool bEnableDetourCrowdAvoidance = true;

    UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config", meta = (EditCondition = "bEnableDetourCrowdAvoidance", UIMin = "1", UIMax = "4"))
    int32 DetourCrowdAvoidanceQuality = 4;

    UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config", meta = (EditCondition = "bEnableDetourCrowdAvoidance"))
    float CollisionQueryRange = 600.f;
};
