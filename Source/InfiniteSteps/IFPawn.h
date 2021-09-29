// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IFPawn.generated.h"

UCLASS()
class INFINITESTEPS_API AIFPawn : public APawn
{
	GENERATED_BODY()

	class USceneComponent* PlayerRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* PlayerMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	class UInfiniteStepsInstance* ISInstance;
public:
	// Sets default values for this pawn's properties
	AIFPawn();

	UPROPERTY(EditAnywhere, Category = "PlatformSpawner")
	class APlatformSpawner* SpawnerRef;

	UPROPERTY(EditDefaultsOnly, Category = Appearance)
	class UMaterial* Style1;

	UPROPERTY(EditDefaultsOnly, Category = Appearance)
	UMaterial* Style2;

	UPROPERTY(EditDefaultsOnly, Category = Appearance)
	UMaterial* Style3;

	UPROPERTY(EditDefaultsOnly, Category = Appearance)
	UMaterial* Style4;

	uint8 PlayerStyle = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	void LoadAndSetStyle();

	// ***
	// Animation curves
	UPROPERTY(EditDefaultsOnly, Category = AnimationCurves)
	class UCurveFloat* StompCurve;

	UPROPERTY(EditDefaultsOnly, Category = AnimationCurves)
	UCurveFloat* FallCurve;

	UPROPERTY(EditDefaultsOnly, Category = AnimationCurves)
	UCurveFloat* CelebrateCurve;

	// ***
	// Anim timeline float return functions
	UFUNCTION()
	void StompTimelineReturnValue(float Value);

	UFUNCTION()
	void FallTimelineReturnValue(float Value);

	UFUNCTION()
	void CelebrateTimelineReturnValue(float Value);

	// ***
	// Anim timelines
	UPROPERTY()
	class UTimelineComponent* StompTimeline;

	UPROPERTY()
	UTimelineComponent* FallTimeline;

	UPROPERTY()
	UTimelineComponent* CelebrateTimeline;

	// ***
	// Anim vars

	FVector AnimStartLocation;

private:

	void SetupAnimationTimelines();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RotateMesh(bool Left);
	void AnimateStomp();
	void AnimateFall();
	void AnimateCelebration();
};
