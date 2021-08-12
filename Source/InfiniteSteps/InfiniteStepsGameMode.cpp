// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfiniteStepsGameMode.h"
#include "InfiniteStepsCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"

#include "ISHUD.h"

AInfiniteStepsGameMode::AInfiniteStepsGameMode()
{

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

void AInfiniteStepsGameMode::BeginPlay()
{
	HUD = Cast<AISHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	
}
