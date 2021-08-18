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

	// High Scores
	bool IsNewGame();
	void CreateNewSave();

	void SaveScore(int Score);
	bool LoadScore();

	UPROPERTY()
	class UHighScoresSaveGame* ScoresSaveGame;

	// Player Data

	UPROPERTY()
	class UPlayerDataSaveGame* DataSaveGame;

	bool DoesPlayerDataExist();
	void CreatePlayerDataSave();

	void SavePlayerData(uint8 Style);
	bool LoadPlayerData();

private:

	static const FString ScoresSaveGameName;
	static const FString PlayerDataSaveGameName;

};
