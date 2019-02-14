// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    ATank* getControlledTank() const;

	virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere)
    float crosshair_location_x_ = 0.5;
    UPROPERTY(EditAnywhere)
    float crosshair_location_y_ = 0.3333;
    UPROPERTY(EditAnywhere)
    float line_trace_range_ = 1.e6;

    // Moves to Barrel so, that a shot would hit where the barrel intersects the world
    void aimTowardsCrosshair();
    bool getSightRayHitLocation(FVector& outhit_location) const;
    bool getLookVectorHitLocation(FVector look_direction, FVector &outhit_location) const;

    FVector2D findCrosshairPosition() const;

    bool deprojectCrosshairPosition(FVector2D &crosshair_screen_location, FVector &outworld_direction) const;
};
