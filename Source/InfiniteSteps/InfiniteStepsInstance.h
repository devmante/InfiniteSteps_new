// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InfiniteStepsInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UInfiniteStepsInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	bool IsNewGame();
	void CreateNewSave();

	void SaveScore(int Score);
	bool LoadScore();

	UPROPERTY()
	class UHighScoresSaveGame* ScoresSaveGame;

private:

	static const FString ScoresSaveGameName;

};
