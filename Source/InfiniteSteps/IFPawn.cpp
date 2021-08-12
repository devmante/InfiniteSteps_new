// Fill out your copyright notice in the Description page of Project Settings.


#include "IFPawn.h"

#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "PlatformSpawner.h"

// Sets default values
AIFPawn::AIFPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PlayerRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerRoot"));
	RootComponent = PlayerRoot;

	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(PlayerRoot);
	PlayerMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraArm->SetupAttachment(PlayerRoot);
	CameraArm->SetRelativeLocation(FVector(0.0f, 0.0f, 10.0f));
	CameraArm->SetRelativeRotation(FRotator(0.0f, -180.0f, 0.0f));
	CameraArm->TargetArmLength = 150.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);
	Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	Camera->SetOrthoWidth(256);

}

// Called when the game starts or when spawned
void AIFPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIFPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIFPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &AIFPawn::MoveLeft);
	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &AIFPawn::MoveRight);
}

void AIFPawn::RotateMesh(bool Left)
{
	// Rotate left
	if (Left)
	{
		PlayerMesh->SetRelativeRotation(FRotator(0.0f, -45.0f, 0.0f));
	}
	else
	{
		PlayerMesh->SetRelativeRotation(FRotator(0.0f, -135.0f, 0.0f));
	}

}

void AIFPawn::MoveLeft()
{
	RotateMesh(true);

	if (SpawnerRef)
	{
		SpawnerRef->HandlePlayerInput(true, this);
	}
}

void AIFPawn::MoveRight()
{
	RotateMesh(false);

	if (SpawnerRef)
	{
		SpawnerRef->HandlePlayerInput(false, this);
	}
}
