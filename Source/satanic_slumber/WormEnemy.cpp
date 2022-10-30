// Fill out your copyright notice in the Description page of Project Settings.


#include "WormEnemy.h"
#include "Misc/App.h"

// Sets default values
AWormEnemy::AWormEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWormEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	moveDuration = 3.0f;
	popDuration = 5.0f;
	spikeInterval = 0.1f;
	spikeClock = 0.0f;
	FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	direction = player_pos - GetActorLocation();
}

void AWormEnemy::SpawnSpike(float DeltaTime) {
	if (spikeClock >= spikeInterval) {
		AActor* spike = GetWorld()->SpawnActor<AActor>(SpikeActor, GetActorTransform());
		spike->SetActorLocation(GetActorLocation());
		spikeClock = 0.0f;
	}
	spikeClock += DeltaTime;

}

void AWormEnemy::Move() {
	FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	direction = player_pos - GetActorLocation();
	AddMovementInput(direction, 1.0f);

}

void AWormEnemy::PopUp() {
	
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 10.0f));

}

// Called every frame
void AWormEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (moving) {
		Move();
		SpawnSpike(DeltaTime);
		moveClock += DeltaTime;
		if (moveClock >= moveDuration) {
			moving = false;
			moveClock = 0.0f;
		}
	}
	else {
		PopUp();
		popClock += DeltaTime;
		if (popClock >= popDuration) {
			moving = true;
			FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			direction = player_pos - GetActorLocation();
			popClock = 0.0f;
		}
	}

}

// Called to bind functionality to input
void AWormEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

