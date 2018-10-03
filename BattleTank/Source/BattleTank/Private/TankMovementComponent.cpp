// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankMovementComponent.h"
#include "public/TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) return;

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
};

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) return;
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	/// TODO Prevent double-speed due to dual control input
};

void UTankMovementComponent::IntendTurn(float Throw)
{
	if (!LeftTrack || !RightTrack) return;
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
};

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	/// No need to call Super as we're replacing the functionality

	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to: %s"), *GetOwner()->GetName(), *MoveVelocity.ToString())
};



