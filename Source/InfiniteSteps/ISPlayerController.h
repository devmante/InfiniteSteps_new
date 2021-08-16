// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ISPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API AISPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	class AIFPawn* PawnRef;

private:

	void MoveLeft();
	void MoveRight();
};
