// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h"

// Called at the start of the game
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	AITank = GetPawn();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ensure(PlayerTank && AITank))
		return;
		
	MoveToActor(PlayerTank, AcceptanceRadius);

	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
	if (TankAimingComponent->GetFiringState() == EFiringState::Locked)
		TankAimingComponent->Fire();

}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank))
			return;

		// Subscribe our local method to the tanks death event
		PossessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn())
		return;
	GetPawn()->DetachFromControllerPendingDestroy();
}

