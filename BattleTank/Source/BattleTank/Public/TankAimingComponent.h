// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();
	void setBarrelReference(UStaticMeshComponent* barrel_to_set);


public:
	void aimAt(FVector hit_location, float launch_speed);

private:
    UStaticMeshComponent* barrel_ = nullptr;
    void moveBarrelTowards(FVector aim_direction);
};
