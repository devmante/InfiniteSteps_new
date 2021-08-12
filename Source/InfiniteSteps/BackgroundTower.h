// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroundTower.generated.h"

UCLASS()
class INFINITESTEPS_API ABackgroundTower : public AActor
{
	GENERATED_BODY()

	class USceneComponent* TowerRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Platform, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Floor1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Platform, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Floor2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Platform, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Floor3;
	
public:	
	// Sets default values for this actor's properties
	ABackgroundTower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<class UStaticMeshComponent*> Floors;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
