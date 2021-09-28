// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeScoreWidget.h"

#include "Components/TextBlock.h"

void UTimeScoreWidget::SetScoreValue(int Value)
{
	if (TxtMinutes)
	{
		TxtMinutes->SetText(FText::FromString(FString::FromInt(Value / 60)));
	}

	if (TxtSeconds)
	{
		int Seconds = Value % 60;

		if (Seconds <= 9) // display 1, 2, 3 as 01, 02, 03 etc.
		{
			FString StringSeconds = FString::FromInt(0);
			StringSeconds.AppendInt(Seconds);
			TxtSeconds->SetText(FText::FromString(StringSeconds));
		}
		else
		{
			TxtSeconds->SetText(FText::FromString(FString::FromInt(Seconds)));
		}
	}

}

void UTimeScoreWidget::SetHighScoreValue(int Value)
{
	if (TxtBestMinutes)
	{
		TxtMinutes->SetText(FText::FromString(FString::FromInt(Value / 60)));
	}

	if (TxtBestSeconds)
	{
		int Seconds = Value % 60;

		if (Seconds <= 9) // display 1, 2, 3 as 01, 02, 03 etc.
		{
			FString StringSeconds = FString::FromInt(0);
			StringSeconds.AppendInt(Seconds);
			TxtBestSeconds->SetText(FText::FromString(StringSeconds));
		}
		else
		{
			TxtBestSeconds->SetText(FText::FromString(FString::FromInt(Seconds)));
		}
	}
}