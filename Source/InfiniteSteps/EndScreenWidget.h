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
	virtual void SetScoreValue(int Value, bool bIsNewBest, bool bIsVictory);

protected:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TxtNewBest;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnPlayAgain;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnExit;

private:

	void NativeOnInitialized() override;

	UFUNCTION()
	void PlayAgainButtonClicked();
	UFUNCTION()
	void ExitButtonClicked();

	UPROPERTY(meta = (BindWidgetOptional))
	UTextBlock* TxtFinalScore;


};
