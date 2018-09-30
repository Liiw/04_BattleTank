// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankAIController.h"
#include "Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
};

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		/// TODO Move Towards the player

		/// Aim Towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		/// FIRE!
		// TODO Enable after debugging ControlledTank->Fire();
	};
};


