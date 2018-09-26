// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	/// Move barrel the right amount each frame
	/// Given max elevation speed adn the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, +1.0);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0.0f, Rotation, 0.0f));
};


