// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FloaterProjectile.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "FlyingEnemy.generated.h"

UCLASS()
class SATANIC_SLUMBER_API AFlyingEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFlyingEnemy();

protected:

	float FLY_HEIGHT;
	float FLY_OFFSET;
	bool found_player;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fly();

public:	

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor>ActorToSpawn;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		int32 ai_state = 0;

	bool started_shooting = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		int32 distance_to_player = 0;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void UpdateAIState();
	float GetDistanceToPlayer();

	//move to player
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void MoveToPlayer();

	//backing up from player
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void BackUp();

	//shoot player
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void ShootPlayer();

	//idle
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void IdleMove();

};
