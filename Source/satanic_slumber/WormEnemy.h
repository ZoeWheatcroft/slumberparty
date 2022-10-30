// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WormEnemy.generated.h"

UCLASS()
class SATANIC_SLUMBER_API AWormEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWormEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move();
	void PopUp();
	void SpawnSpike(float DeltaTime);

	FVector direction;

	//are we moving or popping
	bool moving = true;

	//how long we've been moving for 
	float moveClock = 0.0f;
	//how long we're going to move
	float moveDuration = 10.0f;

	//how long been popping
	float popClock = 0.0f;
	//how long will pop for
	float popDuration = 5.0f;

	float spikeClock;
	float spikeInterval;

public:	


	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor>SpikeActor;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
