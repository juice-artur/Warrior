// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "WarriorFunctionLibrary.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"


UWarriorAbilitySystemComponent * UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor *InActor)
{
    check(InActor);

    return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

bool UWarriorFunctionLibrary::NativeDoesActorHaveTag(AActor *InActor, FGameplayTag TagToCheck)
{
    UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);

    return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor *InActor, FGameplayTag TagToAdd)
{
    UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);

    if (!ASC->HasMatchingGameplayTag(TagToAdd))
    {
        ASC->AddLooseGameplayTag(TagToAdd);
    }
}

void UWarriorFunctionLibrary::RemoveGameplayFromActorIfFound(AActor *InActor, FGameplayTag TagToRemove)
{
    UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);

    if (ASC->HasMatchingGameplayTag(TagToRemove))
    {
        ASC->RemoveLooseGameplayTag(TagToRemove);
    }
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor *InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType)
{
    OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}
