// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankPlayerController.h"
#include "Public/Tank.h"

// Tick
	// Super
	// AimTowardsCrosshair();

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
};

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
};

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; };

	FVector HitLocation; /// OUT parameter
	if (GetSightRayHitLocation(HitLocation))
	{ 
		GetControlledTank()->AimAt(HitLocation);
	};
};

// Get world location linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	///Find the crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation(ViewPortSizeX * CrossHairXlocation, ViewPortSizeY * CrossHairYLocation);

	/// De-project screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		/// Line-trace along that LookDirection and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		return true;
	};
		
	return false;
};

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; /// To be discarded

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
};

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	};
	OutHitLocation = FVector(0);
	return false; // Line trace did not succeed
};