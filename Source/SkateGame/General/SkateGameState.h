// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SkateGameState.generated.h"

class USkateGameScoreVolume;
/**
 * 
 */
UCLASS()
class SKATEGAME_API ASkateGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ASkateGameState();
	
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
	void RegisterObstacle(USkateGameScoreVolume* Obstacle);

	UFUNCTION()
	void OnGivePoints(int PointsToGive);
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay)
	int Score = 0;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay)
	TArray<TObjectPtr<USkateGameScoreVolume>> Obstacles;
};
