// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "FloaterProjectile.generated.h"

UCLASS()
class SATANIC_SLUMBER_API AFloaterProjectile : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	class UStaticMeshComponent* SphereMeshComponent;

	UPROPERTY()
		class UProjectileMovementComponent* ProjMovementComponent;
	
public:	
	// Sets default values for this actor's properties
	AFloaterProjectile();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector direction;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
