// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerIconWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UPlayerIconWidget : public UUserWidget
{
	GENERATED_BODY()
	
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

	void SetPlayerIcon(uint8 Style);

	UPROPERTY(meta = (BindWidget))
	class UImage* ImgPlayerIcon;
};
