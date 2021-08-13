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
	
private:
	virtual void NativeConstruct() override;

	void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StepsValue;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreValue;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BestScoreValue;
};