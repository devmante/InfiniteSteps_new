// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerDataSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UPlayerDataSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY()
	uint8 PlayerOneStyle = 0;
	
};
