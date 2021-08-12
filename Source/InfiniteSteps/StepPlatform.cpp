// Fill out your copyright notice in the Description page of Project Settings.


#include "StepPlatform.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AStepPlatform::AStepPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PlatformRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PlatformRoot"));
	RootComponent = PlatformRoot;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	PlatformMesh->SetRelativeLocation(FVector(-20.0f, 5.0f, -10.0f));
	PlatformMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
}

void AStepPlatform::SetDirection(bool inDirection)
{
	isLeft = inDirection;
}

// Called when the game starts or when spawned
void AStepPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStepPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStepPlatform::DecreaseDurability()
{
	Durability--;

	if (Durability <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(DurabilityTimer);
	}

	GetWorld()->GetTimerManager().SetTimer(DurabilityTimer, 1.0f, false);
}

