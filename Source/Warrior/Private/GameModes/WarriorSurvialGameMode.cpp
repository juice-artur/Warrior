// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "GameModes/WarriorSurvialGameMode.h"


void AWarriorSurvialGameMode::BeginPlay()
{
    Super::BeginPlay();
}

void AWarriorSurvialGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AWarriorSurvialGameMode::SetCurrentSurvialGameModeState(EWarriorSurvialGameModeState InState)
{
    CurrentSurvialGameModeState = InState;

    OnSurvialGameModeStateChanged.Broadcast(CurrentSurvialGameModeState);
}
