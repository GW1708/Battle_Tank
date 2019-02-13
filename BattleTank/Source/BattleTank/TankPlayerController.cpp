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
        getControlledTank()->aimAt(hit_location);
    }
}

bool ATankPlayerController::getSightRayHitLocation(FVector& outhit_location) const
{
    auto crosshair_screen_location = findCrosshairPosition();
    FVector look_direction;

    if (deprojectCrosshairPosition(crosshair_screen_location, look_direction))
    {
        getLookVectorHitLocation(look_direction, outhit_location);
    }

    return true;
}

FVector2D ATankPlayerController::findCrosshairPosition() const
{
    int32 viewport_size_x, viewport_size_y;
    GetViewportSize(viewport_size_x, viewport_size_y);
    auto screen_location = FVector2D(viewport_size_x * crosshair_location_x_, viewport_size_y * crosshair_location_y_);
    return screen_location;
}

bool ATankPlayerController::deprojectCrosshairPosition(
    FVector2D &crosshair_screen_location, FVector &outworld_direction) const
{
    FVector world_location;

    return DeprojectScreenPositionToWorld(
            crosshair_screen_location.X, crosshair_screen_location.Y, world_location, outworld_direction);
}

bool ATankPlayerController::getLookVectorHitLocation(FVector look_direction, FVector &outhit_location) const
{
    FHitResult hit_result;
    auto start_location = PlayerCameraManager->GetCameraLocation();

    bool line_trace_success =
    GetWorld()->LineTraceSingleByChannel(
        hit_result,
        start_location,
        start_location + look_direction * line_trace_range_,
        ECollisionChannel::ECC_Visibility
    );

    if (line_trace_success) {
        outhit_location = hit_result.Location;
    } else {
        outhit_location = FVector(0.f);
    }

    return line_trace_success;
}