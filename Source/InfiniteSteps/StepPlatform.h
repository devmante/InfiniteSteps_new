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

	class USceneComponent* PlatformRoot;
	
	// In which direction does this platform go from the previous platform
	UPROPERTY(VisibleAnywhere)
	bool isLeft = true;
public:	
	// Sets default values for this actor's properties
	AStepPlatform();

	void SetDirection(bool inDirection);
	bool GetDirection() { return isLeft; };

	// Durability animation
	UPROPERTY()
	class UTimelineComponent* ShakeTimeline;

	UPROPERTY()
	class UCurveFloat* ShakeCurve;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Seconds until platform will collapse once stepped on
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Durability = 3;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DecreaseDurability();

private:

	FTimerHandle DurabilityTimer;
};
