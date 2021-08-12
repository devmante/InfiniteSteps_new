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

	void IncrementSteps();
	void AddScoreAmount(int Amount);

protected:
	virtual void BeginPlay() override;

	// Scoring
	int Steps = 0;
	int Score = 0;
	int BestScore = 0;

	class AISHUD* HUD;
};
