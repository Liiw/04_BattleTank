// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankAIController.h"
#include "Public/TankAimingComponent.h"
#include "Tank.h" // So OnDeath can be implemented


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
};

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) {return;}
	
	/// Move Towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	/// Aim Towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if ((AIFiringEnabled == true)&&(AimingComponent->GetFiringState()==EFiringState::Locked))
	{
		/// FIRE!
		AimingComponent->Fire();
	};	
};

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) { return; };

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);

	};
}
void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; };
	GetPawn()->DetachFromControllerPendingDestroy();
};
;


