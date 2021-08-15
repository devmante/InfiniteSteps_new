// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ISHUD.generated.h"


UCLASS()
class INFINITESTEPS_API AISHUD : public AHUD
{
	GENERATED_BODY()

public:
	AISHUD();

	void UpdateSteps(int Steps);
	void UpdateScore(int Score);
	void SetHighScore(int Score);
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (BlueprintProtected = true))
	TSubclassOf<class UUserWidget> UIClass;

	class UISScoreWidget* ScoreWidget;
};
