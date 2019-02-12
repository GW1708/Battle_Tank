// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    ATank* getControlledTank() const;

	virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    // Moves to Barrel so, that a shot would hit where the barrel intersects the world
    void aimTowardsCrosshair();
    bool getSightRayHitLocation(FVector& outhit_location) const;
};
