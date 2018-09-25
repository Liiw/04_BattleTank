// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	/// Move barrel the right amount each frame
	/// Given max elevation speed adn the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, +1.0);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
};


