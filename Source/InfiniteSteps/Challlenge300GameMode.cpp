// Fill out your copyright notice in the Description page of Project Settings.


#include "Challlenge300GameMode.h"

#include "Kismet/GameplayStatics.h"

#include "ISHUD.h"
#include "InfiniteStepsInstance.h"
#include "HighScoresSaveGame.h"

AChalllenge300GameMode::AChalllenge300GameMode()
{
	bHasPlayerWon = false;
	bSpawnCrates = false;
}

void AChalllenge300GameMode::IncrementSteps()
{
	Steps++;

	if (HUD)
	{
		HUD->UpdateSteps(Steps);
	}
}

void AChalllenge300GameMode::LoadBestScore()
{
	if (ISGameInstance->IsNewGame())	// Create save game if none exists
	{
		ISGameInstance->CreateNewSave();
	}
	else
	{
		if (ISGameInstance->LoadScore())	// Load score from file
		{
			BestScore = ISGameInstance->ScoresSaveGame->TimeModeHighScore;

			if (HUD)
			{
				HUD->SetHighScore(BestScore);
			}
		}

	}
}

void AChalllenge300GameMode::StartGame()
{
	StartGameTimer();
}

void AChalllenge300GameMode::EndGame()
{
	StopGameTimer();

	if (Steps == 300)
	{
		bHasPlayerWon = true;
	}

	if (Score != 0 && BestScore != 0 && Score < BestScore && ISGameInstance)
	{
		ISGameInstance->SaveTimeScore(Score);
	}

	if (HUD)
	{
		FInputModeUIOnly InputData;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(InputData);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);

		HUD->ShowEndGameMenu(Score, Score != 0 && Score < BestScore, bHasPlayerWon);
	}
}

void AChalllenge300GameMode::StartGameTimer()
{
	GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &AChalllenge300GameMode::IncrementTime, 1.0f, true);
}

void AChalllenge300GameMode::StopGameTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(GameTimer);
}

void AChalllenge300GameMode::IncrementTime()
{
	AddScoreAmount(1);
}
