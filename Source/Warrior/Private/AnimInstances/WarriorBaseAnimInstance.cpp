// Warrior, Copyright 2026 - 2026, Juicy, Inc

#include "AnimInstances/WarriorBaseAnimInstance.h"

#include "WarriorFunctionLibrary.h"


bool UWarriorBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
    if (APawn* OwningPawn = TryGetPawnOwner())
    {
        return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn,TagToCheck);
    }

    return false;
}
