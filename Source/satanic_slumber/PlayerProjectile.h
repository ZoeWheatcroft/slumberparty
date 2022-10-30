// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "PlayerProjectile.generated.h"

UCLASS()
class SATANIC_SLUMBER_API APlayerProjectile : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY()
	class UStaticMeshComponent* SphereMeshComponent;

public:	
	// Sets default values for this actor's properties
	APlayerProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector direction;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
