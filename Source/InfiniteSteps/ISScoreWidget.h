// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ISScoreWidget.generated.h"

class UTextBlock;

UCLASS()
class INFINITESTEPS_API UISScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void SetScoreValue(int Value);
	void SetStepValue(int Value);
	virtual void SetHighScoreValue(int Value);
	void DisplayEndScreenMenu(int Score, bool bIsNewBest, bool bHasPlayerWon);

protected:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StepsValue;

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CvpGameOver;

	UPROPERTY(meta = (BindWidget))
	class UEndScreenWidget* GameOverUI;

private:
	virtual void NativeConstruct() override;

	void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidgetOptional))
	UTextBlock* ScoreValue;

	UPROPERTY(meta = (BindWidgetOptional))
	UTextBlock* BestScoreValue;

};
