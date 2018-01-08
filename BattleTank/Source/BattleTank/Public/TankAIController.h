// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAimingComponent.h"
#include "TankAIController.generated.h"
// Depends on movement component via pathfinding system

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

protected:
	// How close can the AI tank get to the player
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 6000;

private:
	virtual void Tick(float DeltaTime) override;
};
