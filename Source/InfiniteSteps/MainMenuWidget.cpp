// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"

#include "InfiniteStepsInstance.h"
#include "PlayerDataSaveGame.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BtnInfiniteMode->OnClicked.AddDynamic(this, &UMainMenuWidget::LaunchInfiniteMode);
	Btn300Challenge->OnClicked.AddDynamic(this, &UMainMenuWidget::Launch300Challenge);
	BtnStyle->OnClicked.AddDynamic(this, &UMainMenuWidget::OpenStyleMenu);

	BtnReturn->OnClicked.AddDynamic(this, &UMainMenuWidget::ReturnToMainMenu);
	BtnStyle1->OnClicked.AddDynamic(this, &UMainMenuWidget::Style1Selected);
	BtnStyle2->OnClicked.AddDynamic(this, &UMainMenuWidget::Style2Selected);
	BtnStyle3->OnClicked.AddDynamic(this, &UMainMenuWidget::Style3Selected);
	BtnStyle4->OnClicked.AddDynamic(this, &UMainMenuWidget::Style4Selected);

	StyleChoiceBgs.Add(ImgStyle1Bg);
	StyleChoiceBgs.Add(ImgStyle2Bg);
	StyleChoiceBgs.Add(ImgStyle3Bg);
	StyleChoiceBgs.Add(ImgStyle4Bg);

	ISGameInstance = Cast<UInfiniteStepsInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (ISGameInstance)
	{
		LoadPlayerStyle();
	}
}

void UMainMenuWidget::LaunchInfiniteMode()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Map_IS_High_Score_Mode"));
}

void UMainMenuWidget::Launch300Challenge()
{
}

void UMainMenuWidget::OpenStyleMenu()
{
	if (WsMenuSwitcher)
	{
		WsMenuSwitcher->SetActiveWidgetIndex(1);
	}
}

void UMainMenuWidget::DeselectStyleChoices(UImage* SelectedStyleBg)
{
	for (UImage* Background : StyleChoiceBgs)
	{
		if (Background != SelectedStyleBg)
		{
			Background->SetBrushTintColor(FSlateColor(FLinearColor::White));
		}
	}
}

void UMainMenuWidget::ReturnToMainMenu()
{
	if (WsMenuSwitcher)
	{
		WsMenuSwitcher->SetActiveWidgetIndex(0);

		if (ISGameInstance)
		{
			ISGameInstance->SavePlayerData(PlayerOneStyleChoice);
		}
	}
}

void UMainMenuWidget::Style1Selected()
{
	if (ImgStyle1Bg)
	{
		ImgStyle1Bg->SetBrushTintColor(FSlateColor(FLinearColor::Black));
		DeselectStyleChoices(ImgStyle1Bg);
		PlayerOneStyleChoice = 0;
	}
}

void UMainMenuWidget::Style2Selected()
{
	if (ImgStyle2Bg)
	{
		ImgStyle2Bg->SetBrushTintColor(FSlateColor(FLinearColor::Black));
		DeselectStyleChoices(ImgStyle2Bg);
		PlayerOneStyleChoice = 1;
	}
}

void UMainMenuWidget::Style3Selected()
{
	if (ImgStyle3Bg)
	{
		ImgStyle3Bg->SetBrushTintColor(FSlateColor(FLinearColor::Black));
		DeselectStyleChoices(ImgStyle3Bg);
		PlayerOneStyleChoice = 2;
	}
}

void UMainMenuWidget::Style4Selected()
{
	if (ImgStyle4Bg)
	{
		ImgStyle4Bg->SetBrushTintColor(FSlateColor(FLinearColor::Black));
		DeselectStyleChoices(ImgStyle4Bg);
		PlayerOneStyleChoice = 3;
	}
}

// Load player style and select appropriate button in style menu
void UMainMenuWidget::LoadPlayerStyle()
{
	if (ISGameInstance->DoesPlayerDataExist())	// Create data save if none exists
	{
		if (ISGameInstance->LoadPlayerData())	// Load data from file
		{
			switch (ISGameInstance->DataSaveGame->PlayerOneStyle)
			{
			case 0:
				Style1Selected();
				break;
			case 1:
				Style2Selected();
				break;
			case 2:
				Style3Selected();
				break;
			case 3:
				Style4Selected();
				break;
			default:
				Style1Selected();
				break;
			}

		}
	}
	else
	{
		ISGameInstance->CreatePlayerDataSave();
		Style1Selected();
	}
}
