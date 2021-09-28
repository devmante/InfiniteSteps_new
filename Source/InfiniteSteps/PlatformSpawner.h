// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class INFINITESTEPS_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawner();

	UPROPERTY(EditAnywhere, Category = "References")
	class ABackgroundTower* TowerRef;

	// BP platform to be spawned
	UPROPERTY(EditAnywhere, Category = "Settings")
	TSubclassOf<class AStepPlatform> PlatformToSpawn;

	void HandlePlayerInput(bool IsLeft, class AIFPawn* Player);

	void EndGame();

	class AStepPlatform* CurrentPlatform;			// Platform currently occupied by player

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnPlatform();
	void DeleteOldestPlatform();
	void ShiftPlatforms();

	FVector LastPlatformLoc;										// Location of last spawned platform
	FVector PlatformSpawnOffset = FVector(0.0f, 10.0f, 15.6f);		// Distance between platforms

	int CurrentIndex;						// Which index of Platforms is the player currently at

	AStepPlatform* NextPlatform;		// Next platform for player to reach
	TArray<AStepPlatform*> Platforms;		// Array of all platforms

	class AInfiniteStepsGameMode* IFGameMode;

	bool bIsGameActive = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
