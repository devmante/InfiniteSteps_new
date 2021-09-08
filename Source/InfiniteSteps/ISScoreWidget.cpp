// Fill out your copyright notice in the Description page of Project Settings.


#include "ISScoreWidget.h"

#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"

#include "EndScreenWidget.h"
#include "IFPawn.h"

void UISScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UISScoreWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UISScoreWidget::SetScoreValue(int Value)
{
	if (ScoreValue)
	{
		ScoreValue->SetText(FText::FromString(FString::FromInt(Value)));
	}
}

void UISScoreWidget::SetStepValue(int Value)
{
	if (StepsValue)
	{
		StepsValue->SetText(FText::FromString(FString::FromInt(Value)));
	}
}

void UISScoreWidget::SetHighScoreValue(int Value)
{
	if (BestScoreValue)
	{
		BestScoreValue->SetText(FText::FromString(FString::FromInt(Value)));
	}
}

void UISScoreWidget::DisplayEndScreenMenu(int Score, bool bIsNewBest)
{
	if (GameOverUI)
	{
		GameOverUI->SetScoreValue(Score, bIsNewBest);

		if (CvpGameOver)
		{
			CvpGameOver->SetVisibility(ESlateVisibility::Visible);
		}
	}
}
