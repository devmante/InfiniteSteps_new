// Fill out your copyright notice in the Description page of Project Settings.


#include "IFPawn.h"

#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TimelineComponent.h"

#include "PlatformSpawner.h"
#include "ISPlayerController.h"
#include "InfiniteStepsInstance.h"
#include "PlayerDataSaveGame.h"

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
	CameraArm->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f));
	CameraArm->SetRelativeRotation(FRotator(0.0f, -180.0f, 0.0f));
	CameraArm->TargetArmLength = 80.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);
	Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	Camera->SetOrthoWidth(128);

	StompTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("StompTimeline"));
	FallTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("FallTimeline"));
	CelebrateTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("CelebrateTimeline"));
}

// Called when the game starts or when spawned
void AIFPawn::BeginPlay()
{
	Super::BeginPlay();
	
	AISPlayerController* ISController = Cast<AISPlayerController>(GetController());
	if (ISController)
	{
		FInputModeGameOnly InputData;
		ISController->SetInputMode(InputData);
	}

	SetupAnimationTimelines();
}

void AIFPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	LoadAndSetStyle();
}

void AIFPawn::LoadAndSetStyle()
{
	ISInstance = Cast<UInfiniteStepsInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (ISInstance)
	{
		if (ISInstance->LoadPlayerData())	// Load data from file
		{
			PlayerStyle = ISInstance->DataSaveGame->PlayerOneStyle;
			switch (PlayerStyle)
			{
			case 0:
				PlayerMesh->SetMaterial(0, Style1);
				break;
			case 1:
				PlayerMesh->SetMaterial(0, Style2);
				break;
			case 2:
				PlayerMesh->SetMaterial(0, Style3);
				break;
			case 3:
				PlayerMesh->SetMaterial(0, Style4);
				break;
			default:
				PlayerMesh->SetMaterial(0, Style1);
				break;
			}

		}
	}
}

// Called every frame
void AIFPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Rotate the mesh towards movement direction
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

void AIFPawn::AnimateStomp()
{
	AnimStartLocation = GetActorLocation();

	if (StompTimeline)
	{
		StompTimeline->Play();
	}
}

void AIFPawn::AnimateFall()
{
	AnimStartLocation = GetActorLocation();

	if (FallTimeline)
	{
		FallTimeline->Play();
	}
}

void AIFPawn::AnimateCelebration()
{
	AnimStartLocation = GetActorLocation();

	if (CelebrateTimeline)
	{
		CelebrateTimeline->Play();
	}
}


void AIFPawn::StompTimelineReturnValue(float Value)
{
}

void AIFPawn::FallTimelineReturnValue(float Value)
{
}

void AIFPawn::CelebrateTimelineReturnValue(float Value)
{
}

void AIFPawn::SetupAnimationTimelines()
{
	if (StompCurve)
	{
		FOnTimelineFloat InterpStompFunction;
		InterpStompFunction.BindUFunction(this, FName{ TEXT("StompTimelineReturnValue") });

		if (StompTimeline)
		{
			StompTimeline->AddInterpFloat(StompCurve, InterpStompFunction, FName{ TEXT("Location") });
		}
	}

	if (FallCurve)
	{
		FOnTimelineFloat InterpFallFunction;
		InterpFallFunction.BindUFunction(this, FName{ TEXT("FallTimelineReturnValue") });

		if (FallTimeline)
		{
			FallTimeline->AddInterpFloat(FallCurve, InterpFallFunction, FName{ TEXT("Location") });
		}
	}

	if (CelebrateCurve)
	{
		FOnTimelineFloat InterpCelebrateFunction;
		InterpCelebrateFunction.BindUFunction(this, FName{ TEXT("CelebrateTimelineReturnValue") });

		if (CelebrateTimeline)
		{
			CelebrateTimeline->AddInterpFloat(CelebrateCurve, InterpCelebrateFunction, FName{ TEXT("Location") });
		}
	}
}