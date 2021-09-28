// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EndScreenWidget.h"
#include "TimeEndScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITESTEPS_API UTimeEndScreenWidget : public UEndScreenWidget
{
	GENERATED_BODY()
	
public:
	virtual void SetScoreValue(int Value, bool bIsNewBest, bool bIsVictory) override;

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtFinalMinutes;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtFinalSeconds;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TxtPlayerLost;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* VbTimeScore;
};
