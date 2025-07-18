// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create components
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraMesh"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//Setup Camera
	Camera->FieldOfView = 120.0f;
	Camera->SetupAttachment(CameraMesh);
	Camera->SetRelativeLocation(FVector(-120.0f, 0, 150.0f));
}

void AMyPawn::MoveLR(float movementDelta)
{
	FVector newLocation = GetActorLocation();
	newLocation.Y += movementDelta*movementSpeed;
	SetActorLocation(newLocation);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Register L R movement
	PlayerInputComponent->BindAxis(TEXT("MoveLR"),this,&AMyPawn::MoveLR);

}

