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
		/// Move Towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		/// Aim Towards the player
		ControlledTank->FindComponentByClass<UTankAimingComponent>()->AimAt(PlayerTank->GetActorLocation(), LaunchSpeed);

		/// FIRE!
		// TODO Enable after debugging ControlledTank->Fire();
	};
};


