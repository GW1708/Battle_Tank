// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

ATank* ATankPlayerController::getControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto tank = getControlledTank();

    if(tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller reports: Possess %s"), *tank->GetName())
    } else { UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller reports: no tank found")) }
}
