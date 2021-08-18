// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:

	UFUNCTION()
	void LaunchInfiniteMode();
	UFUNCTION()
	void Launch300Challenge();
	UFUNCTION()
	void OpenStyleMenu();
	UFUNCTION()
	void ReturnToMainMenu();
	void DeselectStyleChoices(class UImage* SelectedStyleBg);

	UFUNCTION()
	void Style1Selected();
	UFUNCTION()
	void Style2Selected();
	UFUNCTION()
	void Style3Selected();
	UFUNCTION()
	void Style4Selected();

	TArray<UImage*> StyleChoiceBgs;
	
private:

	void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* WsMenuSwitcher;

	// Main menu
	UPROPERTY(meta = (BindWidget))
	class UButton* BtnInfiniteMode;

	UPROPERTY(meta = (BindWidget))
	UButton* Btn300Challenge;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnStyle;


	// Style menu

	UPROPERTY(meta = (BindWidget))
	UButton* BtnReturn;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnStyle1;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnStyle2;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnStyle3;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnStyle4;

	// Style menu - backgrounds

	UPROPERTY(meta = (BindWidget))
	UImage* ImgStyle1Bg;

	UPROPERTY(meta = (BindWidget))
	UImage* ImgStyle2Bg;

	UPROPERTY(meta = (BindWidget))
	UImage* ImgStyle3Bg;

	UPROPERTY(meta = (BindWidget))
	UImage* ImgStyle4Bg;
};
