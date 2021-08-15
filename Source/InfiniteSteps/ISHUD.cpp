// Fill out your copyright notice in the Description page of Project Settings.


#include "ISHUD.h"

#include "ISScoreWidget.h"

AISHUD::AISHUD()
{

}

void AISHUD::BeginPlay()
{
}

void AISHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (UIClass)
	{
		ScoreWidget = CreateWidget<UISScoreWidget>(GetWorld(), UIClass);
		ScoreWidget->AddToViewport();
	}
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

void AISHUD::ShowEndGameMenu(int Score, bool bIsNewBest)
{
	if (ScoreWidget)
	{
		ScoreWidget->DisplayEndScreenMenu(Score, bIsNewBest);
	}
}
