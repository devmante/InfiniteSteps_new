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

	PawnRef = Cast<AIFPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (PawnRef)
	{
		SetPlayerIcon(PawnRef->PlayerStyle);
	}
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
		GameOverUI->SetPlayerIcon(PawnRef->PlayerStyle);

		if (CvpGameOver)
		{
			CvpGameOver->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void UISScoreWidget::SetPlayerIcon(uint8 Style)
{
	switch (Style)
	{
	case 1:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon1);
		break;
	case 2:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon2);
		break;
	case 3:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon3);
		break;
	case 4:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon4);
		break;
	default:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon1);
		break;
	}
}
