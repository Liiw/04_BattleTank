// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:

	// Disable AI firing for testing purposes
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		bool AIFiringEnabled = false;

	// How close can the AI get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 7000.0f;
};
