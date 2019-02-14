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
	void elevate(float degrees_per_second);

private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float max_degrees_second_ = 20.f;

    UPROPERTY(EditAnywhere, Category = Setup)
    float max_elevation_degrees_ = 40.f;

    UPROPERTY(EditAnywhere, Category = Setup)
    float min_elevation_degrees_ = 0.f;
	
};
