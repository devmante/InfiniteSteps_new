// Fill out your copyright notice in the Description page of Project Settings.


#include "EndScreenWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

#include "InfiniteStepsGameMode.h"

void UEndScreenWidget::SetScoreValue(int Value, bool bIsNewBest)
{
	if (TxtFinalScore)
	{
		TxtFinalScore->SetText(FText::FromString(FString::FromInt(Value)));
	}

	if (TxtNewBest && bIsNewBest)
	{
		TxtNewBest->SetVisibility(ESlateVisibility::Visible);
	}
}

void UEndScreenWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (BtnPlayAgain)
	{
		BtnPlayAgain->OnClicked.AddDynamic(this, &UEndScreenWidget::PlayAgainButtonClicked);
	}

	if (BtnExit)
	{
		BtnExit->OnClicked.AddDynamic(this, &UEndScreenWidget::ExitButtonClicked);
	}
}

void UEndScreenWidget::PlayAgainButtonClicked()
{
	AInfiniteStepsGameMode* GameMode = Cast<AInfiniteStepsGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		GameMode->StarOverGame();
	}
}

void UEndScreenWidget::ExitButtonClicked()
{
	// TODO: add main menu, and travel to it here!
}