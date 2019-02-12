// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    auto controlled_tank = getControlledTank();
    auto player_tank = getPlayerTank();

    if(controlled_tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller reports: Possess %s"), *controlled_tank->GetName())
    } else { UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller reports: no possessed tank found")) }

    if(player_tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller reports: Found %s"), *player_tank->GetName())
    } else { UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller reports: no player tank found")) }
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

ATank* ATankAIController::getControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::getPlayerTank() const
{
    auto player_pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!player_pawn) { return nullptr; }
    auto player_tank = Cast<ATank>(player_pawn);
    return player_tank;
}
