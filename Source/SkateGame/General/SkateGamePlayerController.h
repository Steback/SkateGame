// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SkateGamePlayerController.generated.h"

class UUserWidget;
class ASkateGameCamera;
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	TSubclassOf<ASkateGameCamera> CameraTemplate;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Gameplay)
	TObjectPtr<ASkateGameCamera> CameraActor;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=UI)
	TArray<TObjectPtr<UUserWidget>> Widgets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=UI)
	TArray<TSubclassOf<UUserWidget>> WidgetsToSpawn;
};
