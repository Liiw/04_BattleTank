// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Relative speed clamped between -1 and +1
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSeconds = 15.0f;
};
