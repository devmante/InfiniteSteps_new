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

	TowerMeshesRoot = CreateDefaultSubobject<USceneComponent>(TEXT("TowerMeshesRoot"));
	TowerMeshesRoot->SetupAttachment(RootComponent);

	Floor1 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor1"));
	Floor1->SetupAttachment(TowerMeshesRoot);
	Floor1->SetRelativeScale3D(FVector(8.0f, 8.0f, 8.0f));
	Floor1->SetRelativeLocation(FVector(-203.5f, 72.5f, 0.0f));

	Floor2 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor2"));
	Floor2->SetupAttachment(TowerMeshesRoot);
	Floor2->SetRelativeScale3D(FVector(8.0f, 8.0f, 8.0f));
	Floor2->SetRelativeLocation(FVector(-203.5f, 188.5f, 104.0f));		// Offset due to weird mesh pivot

	Floor3 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor3"));
	Floor3->SetupAttachment(TowerMeshesRoot);
	Floor3->SetRelativeScale3D(FVector(8.0f, 8.0f, 8.0f));
	Floor3->SetRelativeLocation(FVector(-203.5f, 72.5f, 205.0f));

}

// Center the tower around the player
void ABackgroundTower::MoveTower(float PlayerYLoc)
{
	SetActorLocation(FVector(InitialLocation.X, InitialLocation.Y + PlayerYLoc, GetActorLocation().Z));

	if (GetActorLocation().Z < -30.0f)
	{	// Shift tower meshes locally
		MoveTowerMeshes();
	}
	else
	{	// Move the whole actor down initally to hide the ground
		AddActorWorldOffset(FVector(0.0f, 0.0f, -15.6f));
	}
}

// Called when the game starts or when spawned
void ABackgroundTower::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
}

// Move mesh components to create imagine of infinite tower
void ABackgroundTower::MoveTowerMeshes()
{
	TowerMeshesRoot->AddLocalOffset(FVector(0.0f, 0.0f, -15.6f));

	// Each floor is 78 units high (13 scaled up by 6)
	// Once gone past the height of 2 floors reset back to 0.0 Z and repeat
	// 202.8 = height of 2 floors + 3 platforms worth shift to hide grass
	if (TowerMeshesRoot->GetRelativeLocation().Z < -202.8)
	{
		TowerMeshesRoot->SetRelativeLocation(FVector::ZeroVector);
	}

}

// Called every frame
void ABackgroundTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

