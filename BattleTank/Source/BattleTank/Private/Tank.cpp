// Fill out your copyright notice in the Description page of Project Settings.

#include "public/Tank.h"
#include "public/Projectile.h"
#include "public/TankBarrel.h"
#include "public/TankTurret.h"
#include "public/TankAimingComponent.h"
#include "public/TankMovementComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
};

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
};

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
};

void ATank::Fire()
{
	bool isReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds);

	if (Barrel && isReloaded) 
	{ 
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile> /// Method returns projectile into Projectile variable
			(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	};
};
