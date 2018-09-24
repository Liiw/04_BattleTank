// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController found player tank: %s"), *(PlayerTank->GetName()));
	};
};

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		/// TODO Move Towards the player

		/// Aim Towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		/// FIRE!
	};
};

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
};


