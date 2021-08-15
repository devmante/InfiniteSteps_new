// Fill out your copyright notice in the Description page of Project Settings.


#include "InfiniteStepsInstance.h"

#include "Kismet/GameplayStatics.h"

#include "HighScoresSaveGame.h"

const FString UInfiniteStepsInstance::ScoresSaveGameName = "High_Score_Data";

// Check if save file exists
bool UInfiniteStepsInstance::IsNewGame()
{
    if (UGameplayStatics::DoesSaveGameExist(ScoresSaveGameName, 0))
    {
        return true;
    }

    return false;
}

// Create new save file
void UInfiniteStepsInstance::CreateNewSave()
{
	if (ScoresSaveGame == nullptr)
	{
        USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(UHighScoresSaveGame::StaticClass());

        if (NewSaveGame)
        {
            ScoresSaveGame = Cast<UHighScoresSaveGame>(NewSaveGame);
        }

	}
}

// Save score to file
void UInfiniteStepsInstance::SaveScore()
{
    if (ScoresSaveGame)
    {
        UGameplayStatics::SaveGameToSlot(ScoresSaveGame, ScoresSaveGameName, 0);
    }
}

// Load score
bool UInfiniteStepsInstance::LoadScore()
{
    ScoresSaveGame = nullptr;

    USaveGame* Slot = UGameplayStatics::LoadGameFromSlot(ScoresSaveGameName, 0);

    if (Slot != nullptr)
    {
        ScoresSaveGame = Cast<UHighScoresSaveGame>(Slot);
        return true;
    }

    return false;
}
