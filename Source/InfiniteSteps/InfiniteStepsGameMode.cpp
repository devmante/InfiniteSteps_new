// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfiniteStepsGameMode.h"
#include "InfiniteStepsCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"

#include "ISHUD.h"
#include "InfiniteStepsInstance.h"
#include "HighScoresSaveGame.h"

AInfiniteStepsGameMode::AInfiniteStepsGameMode()
{

}

void AInfiniteStepsGameMode::BeginPlay()
{
	HUD = Cast<AISHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	
	ISGameInstance = Cast<UInfiniteStepsInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (ISGameInstance)
	{  
		LoadBestScore();
	}
}

void AInfiniteStepsGameMode::LoadBestScore()
{
	if (ISGameInstance->IsNewGame())	// Create save game if none exists
	{
		ISGameInstance->CreateNewSave();
	}
	else
	{
		if (ISGameInstance->LoadScore())	// Load score from file
		{
			BestScore = ISGameInstance->ScoresSaveGame->InfiniteModeHighScore;

			if (HUD)
			{
				HUD->SetHighScore(BestScore);
			}
		}

	}
}

void AInfiniteStepsGameMode::EndGame()
{
	bHasPlayerWon = true; //the default game mode has no lose/win state this is here just in case

	if (Score > BestScore && ISGameInstance)
	{
		ISGameInstance->SaveScore(Score);
	}
	if (HUD)
	{
		FInputModeUIOnly InputData;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(InputData);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);

		HUD->ShowEndGameMenu(Score, Score > BestScore, bHasPlayerWon);
	}
}

void AInfiniteStepsGameMode::StartGame()
{
}

void AInfiniteStepsGameMode::StarOverGame()
{
	bHasPlayerWon = false;

	FInputModeGameOnly InputData;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(InputData);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(false);

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->RestartLevel();
}

void AInfiniteStepsGameMode::IncrementSteps()
{
	Steps++;
	AddScoreAmount(1);

	if (HUD)
	{
		HUD->UpdateSteps(Steps);
	}
}

void AInfiniteStepsGameMode::AddScoreAmount(int Amount)
{
	Score += Amount;

	if (HUD)
	{
		HUD->UpdateScore(Score);
	}
}

