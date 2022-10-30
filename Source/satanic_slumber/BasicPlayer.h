// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"

#include "BasicPlayer.generated.h"

UCLASS()
class SATANIC_SLUMBER_API ABasicPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicPlayer();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor>ActorToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* projectileSpawnPoint;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* firstPersonCamera;

	//the arrow that points out from the player's chest, where we shoot stuff from
	UPROPERTY(VisibleAnywhere)
		UArrowComponent* Arrow;
	
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* viewModels;

	const float cameraHeight = 150.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void HorizontalAxis(float AxisValue);
	void VerticalAxis(float AxisValue);
	void MousePitch(float AxisValue);
	void MouseYaw(float AxisValue);
	void StartJump();
	void StopJump();
	FVector InputAxis;
	FVector MouseInput;
	void OnFire();

public:	

	UFUNCTION(BlueprintCallable)
	void DamagePlayer();

	int health;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
