// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingEnemy.h"
#include "Math/Vector.h"
#include "FloaterProjectile.h"
#include "Kismet/KismetMathLibrary.h"

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

float AFlyingEnemy::GetDistanceToPlayer() {
	//FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//FVector enemy_pos = GetActorLocation();

	//FVector vector_distance = enemy_pos - player_pos;
	//float distance = vector_distance.Size();

	return 0.0f;
}

void AFlyingEnemy::BackUp() {

}

void AFlyingEnemy::ShootPlayer() {
	//FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//FVector direction = player_pos - GetActorLocation();

	FTransform SpawnLocation;
	attacking = true;

	//AFloaterProjectile* proj = 
	AActor* proj = GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetActorTransform());
	FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector direction = player_pos - GetActorLocation();
	proj->SetActorRelativeRotation(direction.Rotation());
	//proj->SetActorLocation(GetActorLocation());
	

}

void AFlyingEnemy::IdleMove() {

	AddActorLocalRotation(FRotator(0.0f, 1.0f, 0.0f));
	AddMovementInput(GetActorForwardVector(), 1.0f);

}

void AFlyingEnemy::MoveToPlayer() {
	//ai state should be 1
	//get the locations so we know where to move
	FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector direction = player_pos - GetActorLocation();

	//look at the player so it doesnt look fucked up 
	SetActorRotation(direction.Rotation());
	//go torwards player
	//suppose i could do just add mov inp actor get forward vector
	//but eh
	AddMovementInput(direction, 0.1f);

	//AddActorLocalRotation(FRotator(0, 0.5f, 0));
}

void AFlyingEnemy::UpdateAIState() {
	float dist = GetDistanceToPlayer();

	if (dist < 500) {
		MoveToPlayer();
		if (!started_shooting) {
			FTimerHandle ShootingTimeManager;
			//srand(time(NULL));
			GetWorldTimerManager().SetTimer(ShootingTimeManager, this, &AFlyingEnemy::ShootPlayer, 1.0f + 6.5f * ((float)(rand()%10))*0.01f, true, 1.0f + rand()%10);
			started_shooting = true;
		}
		
	}
	else {
		IdleMove();
	}
}

// Called every frame
void AFlyingEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAIState();

	//AddMovementInput(GetActorRotation().Vector(), 2.0f);
	//AddActorLocalRotation(FRotator(0.0f, 3.0f, 0.0f));
	//AddActorWorldRotation(FRotator(0.0f, 3.0f, 0.0f));


	//last thing we do is always fly
	//unless dead
	//REMEMBER TO DO A DEAD CHECK ON THE FLIGHT
	//Fly();
	
	//GetOwner()->Char = GetVelocity() * 0.3f;
	//GetOwner()->GetComponentByClass(<UPrimitiveComponent>());
	//((UPrimitiveComponent*)GetOwner()->GetComponentByClass(UPrimitiveComponent()))->SetPhysicsLinearVelocity(GetVelocity(), false, "None");
}

// Called to bind functionality to input
void AFlyingEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}