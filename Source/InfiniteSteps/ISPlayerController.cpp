// Fill out your copyright notice in the Description page of Project Settings.


#include "ISPlayerController.h"

#include "IFPawn.h"
#include "PlatformSpawner.h"

void AISPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PawnRef = Cast<AIFPawn>(GetPawn());
}

void AISPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("Left", IE_Pressed, this, &AISPlayerController::MoveLeft);
		InputComponent->BindAction("Right", IE_Pressed, this, &AISPlayerController::MoveRight);
	}
}

void AISPlayerController::MoveLeft()
{
	if (PawnRef)
	{
		if (PawnRef->SpawnerRef)
		{
			PawnRef->RotateMesh(true);
			PawnRef->SpawnerRef->HandlePlayerInput(true, PawnRef);
		}

	}
}

void AISPlayerController::MoveRight()
{
	if (PawnRef)
	{
		if (PawnRef->SpawnerRef)
		{
			PawnRef->RotateMesh(false);
			PawnRef->SpawnerRef->HandlePlayerInput(false, PawnRef);
		}
	}
}
