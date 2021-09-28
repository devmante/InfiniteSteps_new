// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ISScoreWidget.h"
#include "TimeScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UTimeScoreWidget : public UISScoreWidget
{
	GENERATED_BODY()
	
public:

	virtual void SetScoreValue(int Value) override;
	virtual void SetHighScoreValue(int Value) override;

protected:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtMinutes;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtSeconds;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtBestMinutes;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtBestSeconds;
};
