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

	void SetScoreValue(int Value);
	void SetStepValue(int Value);
	void SetHighScoreValue(int Value);
	void DisplayEndScreenMenu(int Score, bool bIsNewBest);
	void SetPlayerIcon(uint8 Style);
	
	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	class UTexture2D* PlayerIcon1;

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	UTexture2D* PlayerIcon2;

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	UTexture2D* PlayerIcon3;

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	UTexture2D* PlayerIcon4;

private:
	virtual void NativeConstruct() override;

	void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StepsValue;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreValue;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BestScoreValue;

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CvpGameOver;

	UPROPERTY(meta = (BindWidget))
	class UEndScreenWidget* GameOverUI;

	UPROPERTY(meta = (BindWidget))
	class UImage* ImgPlayerIcon;

	class AIFPawn* PawnRef;
};
