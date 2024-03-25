// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "SkateGameCamera.generated.h"

/**
 * */
UCLASS()
class SKATEGAME_API ASkateGameCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	ASkateGameCamera();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void SetTarget(AActor* InTarget);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	float ForwardOffset = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	float UpOffset = 100.0f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TObjectPtr<AActor> Target;
};
