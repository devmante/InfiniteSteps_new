// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeEndScreenWidget.h"

#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UTimeEndScreenWidget::SetScoreValue(int Value, bool bIsNewBest, bool bIsVictory)
{
	if (bIsVictory) // only display time if player has passed all 300 steps
	{
		if (VbTimeScore)
		{
			VbTimeScore->SetVisibility(ESlateVisibility::Visible);
		}
	}
	else
	{
		if (TxtPlayerLost)
		{
			TxtPlayerLost->SetVisibility(ESlateVisibility::Visible);
			VbTimeScore->SetVisibility(ESlateVisibility::Collapsed);
			return;
		}
	}

	if (TxtFinalMinutes)
	{
		TxtFinalMinutes->SetText(FText::FromString(FString::FromInt(Value / 60)));
	}

	if (TxtFinalSeconds)
	{
		int Seconds = Value % 60;

		if (Seconds <= 9) // display 1, 2, 3 as 01, 02, 03 etc.
		{
			FString StringSeconds = FString::FromInt(0);
			StringSeconds.AppendInt(Seconds);
			TxtFinalSeconds->SetText(FText::FromString(StringSeconds));
		}
		else
		{
			TxtFinalSeconds->SetText(FText::FromString(FString::FromInt(Seconds)));
		}
	}

	if (TxtNewBest && bIsNewBest)
	{
		TxtNewBest->SetVisibility(ESlateVisibility::Visible);
	}
}