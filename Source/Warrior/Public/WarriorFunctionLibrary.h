// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorFunctionLibrary.generated.h"

class UWarriorAbilitySystemComponent;

UENUM()
enum class EWarriorConfirmType : uint8
{
    Yes,
    No
};


UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);
    static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

    UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
    static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

    UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
    static void RemoveGameplayFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

    UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
    static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType);
};
