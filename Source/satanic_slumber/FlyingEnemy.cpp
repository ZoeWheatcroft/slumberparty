// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingEnemy.h"

float FLY_HEIGHT = 200.0f;
float FLY_OFFSET = 50.0f;

// Sets default values
AFlyingEnemy::AFlyingEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFlyingEnemy::BeginPlay()
{
	Super::BeginPlay();
	found_player = false;
}

void AFlyingEnemy::Fly() {
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, FLY_HEIGHT));
}

void GetDistanceToPlayer() {

}

void UpdateAIState() {

}

void AFlyingEnemy::ShootPlayer() {

}

void AFlyingEnemy::IdleMove() {



}

void AFlyingEnemy::MoveToPlayer() {


}

// Called every frame
void AFlyingEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, 1.0f, 0.0f));
	AddMovementInput(GetActorRightVector(), 1.0f);

	//AddMovementInput(GetActorRotation().Vector(), 2.0f);
	//AddActorLocalRotation(FRotator(0.0f, 3.0f, 0.0f));
	//AddActorWorldRotation(FRotator(0.0f, 3.0f, 0.0f));


	//last thing we do is always fly
	//unless dead
	//REMEMBER TO DO A DEAD CHECK ON THE FLIGHT
	//Fly();
}

// Called to bind functionality to input
void AFlyingEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}