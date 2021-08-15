// Fill out your copyright notice in the Description page of Project Settings.


#include "ISHUD.h"

#include "ISScoreWidget.h"

AISHUD::AISHUD()
{

}

void AISHUD::UpdateSteps(int Steps)
{
	if (ScoreWidget)
	{
		ScoreWidget->SetStepValue(Steps);
	}
}

void AISHUD::UpdateScore(int Score)
{
	if (ScoreWidget)
	{
		ScoreWidget->SetScoreValue(Score);
	}
}

void AISHUD::SetHighScore(int Score)
{
	if (ScoreWidget)
	{
		ScoreWidget->SetHighScoreValue(Score);
	}
}

void AISHUD::BeginPlay()
{
	if (UIClass)
	{
		ScoreWidget = CreateWidget<UISScoreWidget>(GetWorld(), UIClass);
		ScoreWidget->AddToViewport();
	}
}