// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//UE_LOG(LogTemp, Warning, TEXT("Dot product: %f"), SlippageSpeed);
	/// Work-out the required acceleration this fram to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	/// Calculate and apply sideways (F = ma)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; /// Two tracks
	TankRoot->AddForce(CorrectionForce);
};

void UTankTrack::SetThrottle(float Throttle)
{
	/// TODO Clamp actual throttle value
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
};


