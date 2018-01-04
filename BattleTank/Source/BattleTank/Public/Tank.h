// Copyright EmbranceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.generated.h"

// Forward Declaration
//class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	// UClass* ProjectileBlueprint;  // Alternative - https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 5000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
