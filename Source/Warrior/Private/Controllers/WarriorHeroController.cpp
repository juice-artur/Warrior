// Warrior, Copyright 2026 - 2026, Juicy, Inc

#include "Controllers/WarriorHeroController.h"


AWarriorHeroController::AWarriorHeroController()
{
    HeroTeamID = FGenericTeamId(0);
}

FGenericTeamId AWarriorHeroController::GetGenericTeamId() const
{
    return HeroTeamID;
}
