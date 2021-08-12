// Fill out your copyright notice in the Description page of Project Settings.


#include "ISScoreWidget.h"

#include "Components/TextBlock.h"

void UISScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UISScoreWidget::NativeOnInitialized()
{
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
