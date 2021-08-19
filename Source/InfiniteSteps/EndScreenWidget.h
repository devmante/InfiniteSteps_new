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
	void SetPlayerIcon(uint8 Style);

	// TODO: Create player icon widget that handles loading and setting the right icon

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	class UTexture2D* PlayerIcon1;

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	UTexture2D* PlayerIcon2;

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	UTexture2D* PlayerIcon3;

	UPROPERTY(EditDefaultsOnly, Category = PlayerIcons)
	UTexture2D* PlayerIcon4;

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

	UPROPERTY(meta = (BindWidget))
	class UImage* ImgPlayerIcon;
};
