// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::setBarrelReference(UTankBarrel* barrel_to_set)
{
    barrel_ = barrel_to_set;
}

void UTankAimingComponent::aimAt(FVector hit_location, float launch_speed)
{
	if (!barrel_) {return;}

	FVector launch_velocity;
	FVector start_location = barrel_->GetSocketLocation(FName("Projectile"));
	bool calculated_velocity = UGameplayStatics::SuggestProjectileVelocity(
	    this,
	    launch_velocity,
	    start_location,
	    hit_location,
	    launch_speed,
	    false,
	    0,
	    0,
	    ESuggestProjVelocityTraceOption::DoNotTrace
    );

	if(calculated_velocity)
    {
        auto aim_direction = launch_velocity.GetSafeNormal();
        moveBarrelTowards(aim_direction);
    }
}

void UTankAimingComponent::moveBarrelTowards(FVector aim_direction)
{
    // work out difference between current barrel rotation and aimdirection
    auto barrel_rotator = barrel_->GetForwardVector().Rotation();
    auto aim_as_rotator = aim_direction.Rotation();
    auto delta_rotator = aim_as_rotator - barrel_rotator;

    barrel_->elevate(delta_rotator.Pitch);

}
