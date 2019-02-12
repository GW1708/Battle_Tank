// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto tank = getControlledTank();

    if(tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller reports: Possess %s"), *tank->GetName())
    } else { UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller reports: no tank found")) }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    aimTowardsCrosshair();
}

ATank* ATankPlayerController::getControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::aimTowardsCrosshair()
{
    if (!getControlledTank()) { return; }

    FVector hit_location;
    if (getSightRayHitLocation(hit_location))
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *hit_location.ToString());
    }
}

bool ATankPlayerController::getSightRayHitLocation(FVector& outhit_location) const
{
    outhit_location = FVector(1.0);
    return true;
}