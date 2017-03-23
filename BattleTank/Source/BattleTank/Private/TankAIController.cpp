// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		auto AITank = Cast<ATank>(GetPawn());

		MoveToActor(PlayerTank, AcceptanceRadius);

		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
	}
}


