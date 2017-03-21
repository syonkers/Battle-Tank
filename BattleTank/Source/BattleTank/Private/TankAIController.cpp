// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*auto PossessedTank = GetPlayerTank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController cannot find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI found player tank %s"), *(PossessedTank->GetName()));
	}*/
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


