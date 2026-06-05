// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownMover2.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ATopDownMover2::ATopDownMover2()
{
	PrimaryActorTick.bCanEverTick = true;

	// One instance gets possessed by Player0 (the last placed in the level)
	// The others move autonomously via bIsMoving set in the Details panel
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoReceiveInput  = EAutoReceiveInput::Disabled;

	// Initialize the visual component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Use a Sphere so it se distingue visually from TopDownMover (Cube)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (SphereMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMesh.Object);
	}

	// Default values
	Velocity      = 400.0f;
	MoveDirection = EMoveDirection::Up;
	bIsMoving     = false;
}

// Called when the game starts or when spawned
void ATopDownMover2::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("TopDownMover2 listo!")));
	}

	UE_LOG(LogTemp, Warning, TEXT("TopDownMover2 BeginPlay"));
}

// Called every frame
void ATopDownMover2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMoving)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector MovementStep    = FVector::ZeroVector;

		// Top-down: +X = Arriba, -X = Abajo, +Y = Derecha, -Y = Izquierda
		switch (MoveDirection)
		{
		case EMoveDirection::Up:
			MovementStep.X =  1.0f;
			break;
		case EMoveDirection::Down:
			MovementStep.X = -1.0f;
			break;
		case EMoveDirection::Right:
			MovementStep.Y =  1.0f;
			break;
		case EMoveDirection::Left:
			MovementStep.Y = -1.0f;
			break;
		case EMoveDirection::UpRights:
			MovementStep.X =  1.0f;
			MovementStep.Y =  1.0f;
			break;
		case EMoveDirection::UpLeft:
			MovementStep.X =  1.0f;
			MovementStep.Y = -1.0f;
			break;
		case EMoveDirection::DownRight:
			MovementStep.X = -1.0f;
			MovementStep.Y =  1.0f;
			break;
		case EMoveDirection::DownLeft:
			MovementStep.X = -1.0f;
			MovementStep.Y = -1.0f;
			break;
		}

		CurrentLocation += MovementStep * Velocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

// Called to bind functionality to input
void ATopDownMover2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("ToggleMove2", IE_Pressed, this, &ATopDownMover2::ToggleMovement).bConsumeInput = false;
	UE_LOG(LogTemp, Warning, TEXT("TopDownMover2 SetupPlayerInputComponent"));
}

void ATopDownMover2::ToggleMovement()
{
	bIsMoving = !bIsMoving;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
			FString::Printf(TEXT("TopDownMover2 bIsMoving: %s"), bIsMoving ? TEXT("TRUE") : TEXT("FALSE")));
	}

	UE_LOG(LogTemp, Warning, TEXT("TopDownMover2 ToggleMovement"));
}
