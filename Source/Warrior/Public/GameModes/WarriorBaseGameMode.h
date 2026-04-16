// Warrior, Copyright 2026 - 2026, Juicy, Inc

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WarriorTypes/WarriorEnumTypes.h"
#include "WarriorBaseGameMode.generated.h"


UCLASS()
class WARRIOR_API AWarriorBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWarriorBaseGameMode();

    FORCEINLINE EWarriorGameDifficulty GetCurrentGameDifficulty() const { return CurrentGameDifficulty;}

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
    EWarriorGameDifficulty CurrentGameDifficulty;

};
