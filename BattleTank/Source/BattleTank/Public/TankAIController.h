// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;
	
private:
	virtual void BeginPlay() override;

	virtual void Tick (float DeltaTime) override;

	float AcceptanceRadius = 3000;

	APawn* PlayerTank = nullptr;

	APawn* AITank = nullptr;

};
