// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SkateGameScoreVolume.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SKATEGAME_API USkateGameScoreVolume : public UBoxComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGivePointsSignature, int, PointsToGivce);

public:
	// Sets default values for this component's properties
	USkateGameScoreVolume();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	bool bIsPawnInside = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	int PointsToGive = 100.0;

	UPROPERTY(BlueprintAssignable)
	FOnGivePointsSignature OnGivePoints;
};
