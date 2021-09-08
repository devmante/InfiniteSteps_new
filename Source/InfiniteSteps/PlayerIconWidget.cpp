// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIconWidget.h"

#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"

#include "IFPawn.h"

void UPlayerIconWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	AIFPawn* PawnRef = Cast<AIFPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (PawnRef)
	{
		SetPlayerIcon(PawnRef->PlayerStyle);
	}
}

void UPlayerIconWidget::SetPlayerIcon(uint8 Style)
{
	switch (Style)
	{
	case 0:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon1);
		break;
	case 1:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon2);
		break;
	case 2:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon3);
		break;
	case 3:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon4);
		break;
	default:
		ImgPlayerIcon->SetBrushFromTexture(PlayerIcon1);
		break;
	}
}
