// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "StepPlatform.h"
#include "IFPawn.h"
#include "InfiniteStepsGameMode.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformSpawner::BeginPlay()
{
	IFGameMode = Cast<AInfiniteStepsGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	Super::BeginPlay();
	
	LastPlatformLoc = GetActorLocation();

	for (int i = 0; i < 10; i++)
	{
		SpawnPlatform();
	}

	NextPlatform = Platforms[0];
}

void APlatformSpawner::SpawnPlatform()
{
	if (!PlatformToSpawn) return;

	// Randomly choose left or right
	bool Direction = UKismetMathLibrary::RandomBool();

	FVector SpawnLoc;
	AStepPlatform* NewPlatform;

	// Spawn platform to the left
	if (Direction)
	{
		FActorSpawnParameters SpawnParams;
		SpawnLoc = LastPlatformLoc + PlatformSpawnOffset;
		NewPlatform = GetWorld()->SpawnActor<AStepPlatform>(PlatformToSpawn, SpawnLoc, GetActorRotation(), SpawnParams);
		NewPlatform->SetDirection(Direction);
	}
	// Spawn platform to the right
	else
	{
		// Negate Y value of spawn offset
		FVector RightOffset = FVector(PlatformSpawnOffset.X, PlatformSpawnOffset.Y * -1, PlatformSpawnOffset.Z);
		SpawnLoc = LastPlatformLoc + RightOffset;

		FActorSpawnParameters SpawnParams;
		NewPlatform = GetWorld()->SpawnActor<AStepPlatform>(PlatformToSpawn, SpawnLoc, GetActorRotation(), SpawnParams);
		NewPlatform->SetDirection(Direction);
	}

	LastPlatformLoc = NewPlatform->GetActorLocation();

	Platforms.Add(NewPlatform);

	UE_LOG(LogTemp, Warning, TEXT("Platform spawned!"));
}

void APlatformSpawner::DeleteOldestPlatform()
{
	if (Platforms.Num() > 15)
	{
		Platforms[0]->Destroy();
		Platforms.RemoveAt(0);
	}
}

void APlatformSpawner::ShiftPlatforms()
{
	DeleteOldestPlatform();

	for (int i = 0; i < Platforms.Num(); i++)
	{
		Platforms[i]->AddActorWorldOffset(FVector(0.0f, 0.0f, -15.0f));
	}

	LastPlatformLoc =  Platforms.Last()->GetActorLocation();
}

void APlatformSpawner::HandlePlayerInput(bool IsLeft, AIFPawn* Player)
{
	if (IsLeft == NextPlatform->GetDirection())
	{
		ShiftPlatforms();

		// Move player to next platform
		Player->SetActorLocation(NextPlatform->GetActorLocation());
		NextPlatform->DecreaseDurability();

		// Update Index
		CurrentIndex = Platforms.Find(NextPlatform);
		// Set next platform
		NextPlatform = Platforms[CurrentIndex + 1];

		SpawnPlatform();

		// Update score in game mode and UI
		if (IFGameMode)
		{
			IFGameMode->IncrementSteps();
		}
	}
	// Game over
	else
	{

	}
}

// Called every frame
void APlatformSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

