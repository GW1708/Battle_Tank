// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    // -1 is max downward speed, 1 max upward speed
	void elevate(float relative_speed);

private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float max_degrees_second_ = 10.f;

    UPROPERTY(EditAnywhere, Category = Setup)
    float max_elevation_degrees_ = 40.f;

    UPROPERTY(EditAnywhere, Category = Setup)
    float min_elevation_degrees_ = 0.f;
	
};
