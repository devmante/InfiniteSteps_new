// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "HighScoresSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UHighScoresSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
	int InfiniteModeHighScore;

};
