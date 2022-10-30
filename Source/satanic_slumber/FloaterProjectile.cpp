// Fill out your copyright notice in the Description page of Project Settings.


#include "FloaterProjectile.h"

//#include "Components/FloaterProjectileComponent.h"

FVector direction;

// Sets default values
AFloaterProjectile::AFloaterProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh Component"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Engine/BasicShapes/Sphere"));
	//SphereMeshComponent->SetStaticMesh(MeshObj.Object);

	

	//RootComponent = SphereMeshComponent;
	

}

// Called when the game starts or when spawned
void AFloaterProjectile::BeginPlay()
{
	Super::BeginPlay();
	//FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//direction = player_pos - GetActorLocation();
}

// Called every frame
void AFloaterProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AddMovementInput(direction, 0.1f);
}

