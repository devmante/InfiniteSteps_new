// Fill out your copyright notice in the Description page of Project Settings.


#include "InfiniteStepsInstance.h"

#include "Kismet/GameplayStatics.h"

#include "HighScoresSaveGame.h"
#include "PlayerDataSaveGame.h"

const FString UInfiniteStepsInstance::ScoresSaveGameName = "High_Score_Data";
const FString UInfiniteStepsInstance::PlayerDataSaveGameName = "Player_Data";

// ***
// High scores - start
// Check if save file exists
bool UInfiniteStepsInstance::IsNewGame()
{
    return !UGameplayStatics::DoesSaveGameExist(ScoresSaveGameName, 0);

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
            SaveScore(0);
        }

	}
}

// Save score to file
void UInfiniteStepsInstance::SaveScore(int Score)
{
    if (ScoresSaveGame)
    {
        ScoresSaveGame->InfiniteModeHighScore = Score;
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
// High scores end

// ***
// Player data start
// Check if player data file exists
bool UInfiniteStepsInstance::DoesPlayerDataExist()
{
    return UGameplayStatics::DoesSaveGameExist(PlayerDataSaveGameName, 0);
}

// Create player data save file
void UInfiniteStepsInstance::CreatePlayerDataSave()
{
    if (DataSaveGame == nullptr)
    {
        USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(UPlayerDataSaveGame::StaticClass());

        if (NewSaveGame)
        {
            DataSaveGame = Cast<UPlayerDataSaveGame>(NewSaveGame);
            UGameplayStatics::SaveGameToSlot(DataSaveGame, PlayerDataSaveGameName, 0);
        }
    }
}

// Save player style choice
void UInfiniteStepsInstance::SavePlayerData(uint8 Style)
{
    if (DataSaveGame)
    {
        DataSaveGame->PlayerOneStyle = Style;
        bool bSaved = UGameplayStatics::SaveGameToSlot(DataSaveGame, PlayerDataSaveGameName, 0);
    }
}

// Load player data file
bool UInfiniteStepsInstance::LoadPlayerData()
{
    DataSaveGame = nullptr;

    USaveGame* Slot = UGameplayStatics::LoadGameFromSlot(PlayerDataSaveGameName, 0);

    if (Slot != nullptr)
    {
        DataSaveGame = Cast<UPlayerDataSaveGame>(Slot);
        return true;
    }

    return false;
}
