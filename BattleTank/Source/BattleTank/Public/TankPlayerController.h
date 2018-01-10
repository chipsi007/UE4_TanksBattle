// Copyright EmbranceIT Ltd.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/PlayerController.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 *  Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving barrel so that a shot would hit where
	// the crosshair intersect the world
	void AimTowrdsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 10000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
