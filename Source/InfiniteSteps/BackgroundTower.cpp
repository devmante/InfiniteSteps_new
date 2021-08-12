// Fill out your copyright notice in the Description page of Project Settings.


#include "BackgroundTower.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ABackgroundTower::ABackgroundTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TowerRoot = CreateDefaultSubobject<USceneComponent>(TEXT("TowerRoot"));
	RootComponent = TowerRoot;

	Floor1 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor1"));
	Floor1->SetupAttachment(RootComponent);
	Floor1->SetRelativeScale3D(FVector(6.0f, 6.0f, 6.0f));

	Floor2 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor2"));
	Floor2->SetupAttachment(RootComponent);
	Floor2->SetRelativeScale3D(FVector(6.0f, 6.0f, 6.0f));
	Floor2->SetRelativeLocation(FVector(0.0f, 87.0f, 78.0f));		// Offset due to weird mesh pivot

	Floor3 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor3"));
	Floor3->SetupAttachment(RootComponent);
	Floor3->SetRelativeScale3D(FVector(6.0f, 6.0f, 6.0f));
	Floor3->SetRelativeLocation(FVector(0.0f, 0.0f, 156.0f));

	Floors.Add(Floor1);
	Floors.Add(Floor2);
	Floors.Add(Floor3);
}

// Called when the game starts or when spawned
void ABackgroundTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABackgroundTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

