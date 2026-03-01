// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "Controllers/WarriorAIController.h"
#include "Navigation/CrowdFollowingComponent.h"

#include "WarriorDebugHelper.h"


AWarriorAIController::AWarriorAIController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
    if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
    {
        Debug::Print(TEXT("CrowdFollowingComponent valid"), FColor::Green);
    }
}
