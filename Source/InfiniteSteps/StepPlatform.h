// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StepPlatform.generated.h"

UCLASS()
class INFINITESTEPS_API AStepPlatform : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Platform, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PlatformMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Platform, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* CrateMesh;

	class USceneComponent* PlatformRoot;
	
	// In which direction does this platform go from the previous platform
	bool isLeft = true;
	bool bContainsCrate = false;

public:	
	// Sets default values for this actor's properties
	AStepPlatform();

	void SetDirection(bool inDirection);
	bool GetDirection() { return isLeft; };
	void DetermineCrateSpawn();

	UPROPERTY(EditDefaultsOnly, Category = ShakeAnimation)
	class UCurveFloat* ShakeCurve;

	class APlatformSpawner* SpawnerRef;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Seconds until platform will collapse once stepped on
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Durability = 4;

	// ***
	// Durability animation
	UPROPERTY()
	class UTimelineComponent* ShakeTimeline;

	UFUNCTION()
	void ShakeTimelineReturnValue(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DecreaseDurability();

	void OpenCrate();

private:

	FTimerHandle DurabilityTimer;
};
