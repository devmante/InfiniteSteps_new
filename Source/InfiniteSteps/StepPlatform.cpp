// Fill out your copyright notice in the Description page of Project Settings.


#include "StepPlatform.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/TimelineComponent.h"

#include "PlatformSpawner.h"

// Sets default values
AStepPlatform::AStepPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PlatformRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PlatformRoot"));
	RootComponent = PlatformRoot;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	PlatformMesh->SetRelativeLocation(FVector(-5.0f, 10.0f, -10.0f));

	CrateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrateMesh"));
	CrateMesh->SetupAttachment(RootComponent);
	CrateMesh->SetRelativeLocation(FVector(-5.0f, 10.0f, 0.0f));
	CrateMesh->SetVisibility(false);


	ShakeTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("ShakeTimeline"));
}

void AStepPlatform::SetDirection(bool inDirection)
{
	isLeft = inDirection;
}

void AStepPlatform::DetermineCrateSpawn()
{
	float Roll = FMath::FRandRange(1, 10);

	if (Roll == 1)
	{
		bContainsCrate = true;
		CrateMesh->SetVisibility(true);
	}
}

void AStepPlatform::ShakeTimelineReturnValue(float Value)
{
	FRotator PlatformRotation = FRotator(0.0f, 0.0f, Value);
	SetActorRotation(PlatformRotation);
}

// Called when the game starts or when spawned
void AStepPlatform::BeginPlay()
{
	Super::BeginPlay();
	

	if (ShakeCurve)
	{
		FOnTimelineFloat InterpShakeFunction;
		InterpShakeFunction.BindUFunction(this, FName{ TEXT("ShakeTimelineReturnValue") });

		if (ShakeTimeline)
		{
			ShakeTimeline->AddInterpFloat(ShakeCurve, InterpShakeFunction, FName{ TEXT("Rotation") });
		}
	}
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

		if (SpawnerRef)
		{
			if (SpawnerRef->CurrentPlatform == this)
			{
				SpawnerRef->EndGame();
			}
		}
	}

	GetWorld()->GetTimerManager().SetTimer(DurabilityTimer,this, &AStepPlatform::DecreaseDurability, 1.0f, false);

	if (!ShakeTimeline->IsPlaying())
	{
		ShakeTimeline->Play();
	}
}

void AStepPlatform::OpenCrate()
{
	if (bContainsCrate)
	{
		CrateMesh->SetVisibility(false);
	}
}