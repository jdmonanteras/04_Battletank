// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override; 
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .333333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
