// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ABasicEnemy::ABasicEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ABasicEnemy::BeginPlay()
{
	Super::BeginPlay();

	InputAxis = FVector(0, 0, 0);
	MouseInput = FVector(0, 0, 0);
}

// Called every frame
void ABasicEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

//The input functions are automatically called every frame
//Get the horizontal input (AD) and apply it 
void ABasicEnemy::HorizontalAxis(float AxisValue) 
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}

//Get the vertical input (WS) and apply it
void ABasicEnemy::VerticalAxis(float AxisValue) 
{
	AddMovementInput(GetActorRotation().Vector(), AxisValue);
	
}

//get the mouse up down input
//not complete but eh
void ABasicEnemy::MousePitch(float AxisValue) {
	//FRotator NewRotation = GetActorRotation();
	//NewRotation.Yaw += MouseInput.X;

	//AddActorLocalRotation(FRotator(AxisValue, 0, 0));
}

//get the mouse left right input
void ABasicEnemy::MouseYaw(float AxisValue) {

	AddActorLocalRotation(FRotator(0.0f, AxisValue, 0.0f));

}

// Called to bind functionality to input
void ABasicEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(InputComponent);

	InputComponent->BindAxis("HorizontalAxis", this, &ABasicEnemy::HorizontalAxis);
	InputComponent->BindAxis("VerticalAxis", this, &ABasicEnemy::VerticalAxis);

	InputComponent->BindAxis("MouseYaw", this, &ABasicEnemy::MouseYaw);

}
