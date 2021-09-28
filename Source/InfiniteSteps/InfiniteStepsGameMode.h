// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InfiniteStepsGameMode.generated.h"

UCLASS(minimalapi)
class AInfiniteStepsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInfiniteStepsGameMode();

	virtual void IncrementSteps();
	virtual void AddScoreAmount(int Amount);

	virtual void LoadBestScore();

	virtual void EndGame();
	virtual void StartGame();
	void StarOverGame();

protected:
	virtual void BeginPlay() override;

	// Scoring
	int Steps = 0;
	int Score = 0;
	int BestScore = 0;

	bool bHasPlayerWon = false;

	class AISHUD* HUD;

	class UInfiniteStepsInstance* ISGameInstance;
};
