// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::aimAt(FVector hit_location)
{
	TankAimingComponent->aimAt(hit_location, launch_speed_);
}

void ATank::setBarrelReference(UStaticMeshComponent* barrel_to_set)
{
	TankAimingComponent->setBarrelReference(barrel_to_set);
}

