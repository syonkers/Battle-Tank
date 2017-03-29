// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	void LaunchProjectile(float Speed);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float Damage = 20.f;

	UPROPERTY(VisibleAnyWhere, Category = Components)
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnyWhere, Category = Components)
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnyWhere, Category = Components)
	UParticleSystemComponent* ImpactBlast = nullptr;
	
	UPROPERTY(VisibleAnyWhere, Category = Components)
	URadialForceComponent* ExplosionForce = nullptr;
};
