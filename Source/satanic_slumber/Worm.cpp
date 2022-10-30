// Fill out your copyright notice in the Description page of Project Settings.


#include "Worm.h"

// Sets default values
AWorm::AWorm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorm::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

