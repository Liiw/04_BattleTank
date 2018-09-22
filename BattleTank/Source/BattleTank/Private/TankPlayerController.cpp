// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankPlayerController.h"

// Tick
	// Super
	// AimTowardsCrosshair();

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank"));
	}
	else
	{ 
	UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	/// Get world location linetrace through crosshair
	/// If it hits the lanscape
		/// Tell controlled tank to aim at this point
}

