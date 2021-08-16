// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UEndScreenWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetScoreValue(int Value, bool bIsNewBest);

private:

	void NativeOnInitialized() override;

	UFUNCTION()
	void PlayAgainButtonClicked();
	UFUNCTION()
	void ExitButtonClicked();

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TxtFinalScore;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtNewBest;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnPlayAgain;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnExit;
};
