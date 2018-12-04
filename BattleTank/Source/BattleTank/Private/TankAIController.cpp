// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankAIController.h"
#include "Public/TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
};

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) {return;}
	
	/// Move Towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	/// Aim Towards the player
	ControlledTank->FindComponentByClass<UTankAimingComponent>()->AimAt(PlayerTank->GetActorLocation());

	/// FIRE!
	// TODO Enable after debugging ControlledTank->Fire();
	
};


