// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "JumpActor.generated.h"

UCLASS()
class UECPP_BLANKPROJECT_2_API AJumpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJumpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Mesh Component
	UPROPERTY(EditAnyWhere);
	UStaticMeshComponent* JumpMesh;

	//Jump Settings
	UPROPERTY(EditAnyWhere, Category = "Jump Settings");
	float JumpHeight = 200.0f;
	UPROPERTY(EditAnyWhere, Category = "Jump Settings");
	float JumpSpeed = 1.0f;
	UPROPERTY(EditAnyWhere, Category = "Jump Settings");
	float JumpOffset = 0.0f;


private:
	//Position where actor was spawned
	FVector m_startPos;
	//Current offset relative to start
	float m_currentOffset = 0.0f;
	//Direction in which the jump is currently being executed
	int m_CurrentDirection = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
