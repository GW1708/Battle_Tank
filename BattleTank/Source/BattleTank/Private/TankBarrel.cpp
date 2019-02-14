// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::elevate(float relative_speed)
{
    // move the barrel the right amount this frame
    relative_speed = FMath::Clamp<float>(relative_speed, -1, +1);
    auto elevation_change = relative_speed * max_degrees_second_ * GetWorld()->DeltaTimeSeconds;
    auto raw_new_elevation = RelativeRotation.Pitch + elevation_change;
    auto elevation = FMath::Clamp<float>(raw_new_elevation, min_elevation_degrees_, max_elevation_degrees_);

    SetRelativeRotation(FRotator(elevation, 0, 0));
    // given a a max elevation speed and the frame time
    UE_LOG(LogTemp, Warning, TEXT("Barrel elevate called"))
}

