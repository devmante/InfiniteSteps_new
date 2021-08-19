// Fill out your copyright notice in the Description page of Project Settings.


#include "EndScreenWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
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

void UEndScreenWidget::SetPlayerIcon(uint8 Style)
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
	UGameplayStatics::OpenLevel(GetWorld(), "Map_IS_Main_Menu");
}
