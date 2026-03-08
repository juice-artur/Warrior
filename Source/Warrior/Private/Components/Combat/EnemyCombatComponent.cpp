// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "Components/Combat/EnemyCombatComponent.h"

#include "WarriorDebugHelper.h"


void UEnemyCombatComponent::OnHitTargetActor(AActor *HitActor)
{
    if (HitActor)
    {
        Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is hitting ") + HitActor->GetActorNameOrLabel());
    }
}
