// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloaterProjectile.generated.h"

UCLASS()
class SATANIC_SLUMBER_API AFloaterProjectile : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	class UStaticMeshComponent* SphereMeshComponent;
	
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
