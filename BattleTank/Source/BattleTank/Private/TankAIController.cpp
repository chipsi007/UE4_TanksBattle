// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// auto PlayerTank = GetPlayerTank();
	//if (!PlayerTank)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("ArController can't find player tank"))
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *PlayerTank->GetName())
	//}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn); // for OnDeath
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Received!"))
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	// Move towards the player
	 MoveToActor(PlayerTank, AcceptanceRadius);

	// Fire if ready
	 auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	 AimingComponent->AimAt(PlayerTank->GetActorLocation());

	 if (AimingComponent->GetFiringState() == EFiringState::Locked)
	 {
		 AimingComponent->Fire();
	 }
}



