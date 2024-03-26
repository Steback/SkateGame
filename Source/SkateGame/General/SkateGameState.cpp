// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateGameState.h"

#include "Actor/Components/SkateGameScoreVolume.h"

ASkateGameState::ASkateGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASkateGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

#if defined(UE_EDITOR) || defined(UE_BUILD_DEVELOPMENT)
	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(80, 1.0f, FColor::Cyan, FString::Printf(TEXT("Score: %i"), Score));
	}
#endif
}

void ASkateGameState::RegisterObstacle(USkateGameScoreVolume* Obstacle)
{
	if (IsValid(Obstacle) && !Obstacles.Contains(Obstacle))
	{
		Obstacle->OnGivePoints.AddDynamic(this, &ASkateGameState::OnGivePoints);
		Obstacles.Add(Obstacle);
	}
}

void ASkateGameState::OnGivePoints(int PointsToGive)
{
	Score += PointsToGive;
}
