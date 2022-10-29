// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlayer.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ABasicPlayer::ABasicPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	InputAxis = FVector(0, 0, 0);
	MouseInput = FVector(0, 0, 0);
}

// Called every frame
void ABasicPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// AddActorLocalRotation(FRotator(0.0f, 3.0f, 0.0f));
}

// Called to bind functionality to input
void ABasicPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(InputComponent);

	InputComponent->BindAxis("HorizontalAxis", this, &ABasicPlayer::HorizontalAxis);
	InputComponent->BindAxis("VerticalAxis", this, &ABasicPlayer::VerticalAxis);

	InputComponent->BindAxis("MouseYaw", this, &ABasicPlayer::MouseYaw);
	InputComponent->BindAxis("MousePitch", this, &ABasicPlayer::MousePitch);
}

void ABasicPlayer::MousePitch(float AxisValue)
{
	AddActorLocalRotation(FRotator(AxisValue, 0, 0));
}

void ABasicPlayer::MouseYaw(float AxisValue)
{
	AddActorLocalRotation(FRotator(0, AxisValue, 0));
}

//The input functions are automatically called every frame
//Get the horizontal input (AD) and apply it 
void ABasicPlayer::HorizontalAxis(float AxisValue) 
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}

//Get the vertical input (WS) and apply it
void ABasicPlayer::VerticalAxis(float AxisValue) 
{
	AddMovementInput(GetActorRotation().Vector(), AxisValue);
}
