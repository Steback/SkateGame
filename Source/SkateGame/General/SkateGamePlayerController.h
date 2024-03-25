// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SkateGamePlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class SKATEGAME_API ASkateGamePlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;
};
