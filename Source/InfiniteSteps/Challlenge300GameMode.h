// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfiniteStepsGameMode.h"
#include "Challlenge300GameMode.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API AChalllenge300GameMode : public AInfiniteStepsGameMode
{
	GENERATED_BODY()
	
public:

	AChalllenge300GameMode();

	virtual void IncrementSteps() override;
	virtual void LoadBestScore() override;
	virtual void StartGame() override;
	virtual void EndGame() override;

protected:

	void StartGameTimer();
	void StopGameTimer();
	UFUNCTION()
	void IncrementTime();

private:

	FTimerHandle GameTimer;
};
