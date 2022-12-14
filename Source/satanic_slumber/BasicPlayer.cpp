// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlayer.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Rotator.h"

// Sets default values
ABasicPlayer::ABasicPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a first person camera component.
	firstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("firstPersonCamera"));
	check(firstPersonCamera != nullptr);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow from face"));

	// Attach the camera component to our capsule component.
	firstPersonCamera->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// Position the camera slightly above the eyes.
	firstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, cameraHeight));

	// Enable the pawn to control camera rotation.
	firstPersonCamera->bUsePawnControlRotation = true;

	// Create a first person mesh component for the owning player.
	viewModels = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(viewModels != nullptr);

	// Only the owning player sees this mesh.
	viewModels->SetOnlyOwnerSee(true);

	// Attach the FPS mesh to the FPS camera.
	viewModels->SetupAttachment(firstPersonCamera);

	projectileSpawnPoint = CreateDefaultSubobject<USphereComponent>(TEXT("Projectile Spwn Pnt"));
	projectileSpawnPoint->SetupAttachment(viewModels);

	projectileSpawnPoint->SetRelativeLocation(FVector(-124.63, 486.54, 0));
	
	//projectileSpawnPoint->SetHiddenInGame();

	// Disable some environmental shadows to preserve the illusion of having a single mesh.
	viewModels->bCastDynamicShadow = false;
	viewModels->CastShadow = false;
}

// Called when the game starts or when spawned
void ABasicPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	health = 5;

	InputAxis = FVector(0, 0, 0);
	MouseInput = FVector(0, 0, 0);
}

// Called every frame
void ABasicPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (health <= 0) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("DEAD"));
	}
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

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABasicPlayer::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABasicPlayer::StopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABasicPlayer::OnFire);
	PlayerInputComponent->BindAction("VectorAttack", IE_Pressed, this, &ABasicPlayer::VectorAttack);
}

void ABasicPlayer::StartJump()
{
	bPressedJump = true;
}
void ABasicPlayer::StopJump()
{
	bPressedJump = false;
}

void ABasicPlayer::MousePitch(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void ABasicPlayer::MouseYaw(float AxisValue)
{
	AddControllerYawInput(AxisValue);
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

void ABasicPlayer::OnFire() {
	AActor* proj = GetWorld()->SpawnActor<AActor>(ActorToSpawn, projectileSpawnPoint->GetComponentLocation(), projectileSpawnPoint->GetComponentRotation());
	proj->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 35.0f));
	FVector player_pos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector direction = player_pos - GetActorLocation();
	proj->SetActorRelativeRotation(direction.Rotation());
}

void ABasicPlayer::VectorAttack() {
	FVector pitchRotation = FVector(1, 0, 0);
	for (int pitchDivisor = 1; pitchDivisor <= vectorAttacks; pitchDivisor++) {
		FVector yawRotation = pitchRotation;
		for (int yawDivisor = 1; yawDivisor <= vectorAttacks; yawDivisor++) {
			AActor* proj = GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetActorLocation(), yawRotation.Rotation());
			proj->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 35.0f));
			FRotator yawRotator = FRotator(0, (365.0f / vectorAttacks) * yawDivisor, 0);
			yawRotation = yawRotator.RotateVector(yawRotation);
		}
		FRotator pitchRotator = FRotator((365.0f / vectorAttacks) * pitchDivisor, 0, 0);
		pitchRotation = pitchRotator.RotateVector(pitchRotation);
	}
}

void ABasicPlayer::DamagePlayer() {
	//printf("HEALTH: %d", health);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("HEALTH: %d"), health));
	health -= 1;
}