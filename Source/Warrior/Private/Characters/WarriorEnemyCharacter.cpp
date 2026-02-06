// Warrior, Copyright 2026 - 2026, Juicy, Inc.

#include "Characters/WarriorEnemyCharacter.h"

#include "Components/Combat/EnemyCombatComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "WarriorDebugHelper.h"


AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;

    GetCharacterMovement()->bUseControllerDesiredRotation = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 180.0f, 0.0f);
    GetCharacterMovement()->MaxWalkSpeed = 300.0f;
    GetCharacterMovement()->BrakingDecelerationWalking = 1000.0f;

    EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");
}

void AWarriorEnemyCharacter::PossessedBy(AController *NewController)
{
    Super::PossessedBy(NewController);

    InitEnemyStartUpData();
}

void AWarriorEnemyCharacter::InitEnemyStartUpData()
{
    if (CharacterStartUpData.IsNull())
    {
        return;
    }

    UAssetManager::GetStreamableManager().RequestAsyncLoad(
        CharacterStartUpData.ToSoftObjectPath(),
            FStreamableDelegate::CreateLambda([this]()
            {
                UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.Get();
                if (LoadedData)
                {
                    LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
                    Debug::Print(TEXT("Enemy Start Up Data Loaded"),FColor::Green);
                }
            }
        )
    );
}
