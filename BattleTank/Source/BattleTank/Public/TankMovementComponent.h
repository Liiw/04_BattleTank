// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float Throw); /// Throw- control stick position

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurn(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		virtual void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

private:
	// Called from the pathfinding logic by the AI controllers
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
	
	
};
