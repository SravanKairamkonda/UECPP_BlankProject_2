// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class UECPP_BLANKPROJECT_2_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	//Delta movement
	void MoveLR(float movementDelta);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//Main pawn camera
	UPROPERTY(EditAnyWhere);
	UCameraComponent* Camera;

	UPROPERTY(EditAnyWhere);
	UStaticMeshComponent* CameraMesh;

	//Movement speed
	UPROPERTY(EditAnyWhere, Category = "Pawn Settings");
	float movementSpeed = 1.0f;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
