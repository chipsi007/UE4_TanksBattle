// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTruckToSet, UTankTrack* RightTruckToSet)
{
	if (!LeftTruckToSet || !RightTruckToSet) { return; }
	LeftTrack = LeftTruckToSet;
	RightTrack = RightTruckToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO prevent double-speed due to dual controle use

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO prevent double-speed due to dual controle use

}
