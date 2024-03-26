// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateGameScoreVolume.h"

#include "Character/SkateGameCharacter.h"
#include "General/SkateGameState.h"


// Sets default values for this component's properties
USkateGameScoreVolume::USkateGameScoreVolume()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkateGameScoreVolume::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &USkateGameScoreVolume::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &USkateGameScoreVolume::OnEndOverlap);

	if (ASkateGameState* GameState = Cast<ASkateGameState>(GetWorld()->GetGameState()))
	{
		GameState->RegisterObstacle(this);
	}
}

void USkateGameScoreVolume::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsPawnInside)
	{
		if (OnGivePoints.IsBound())
		{
			OnGivePoints.Broadcast(PointsToGive);
		}
	}
}

void USkateGameScoreVolume::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ASkateGameCharacter* Character = Cast<ASkateGameCharacter>(OtherActor))
	{
		bIsPawnInside = true;
	}
}

void USkateGameScoreVolume::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ASkateGameCharacter* Character = Cast<ASkateGameCharacter>(OtherActor))
	{
		bIsPawnInside = false;
	}
}
