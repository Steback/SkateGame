// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateGameCamera.h"


ASkateGameCamera::ASkateGameCamera()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASkateGameCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASkateGameCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IsValid(Target))
	{
		const FVector ForwardVector = Target->GetActorForwardVector() * ForwardOffset;
		const FVector UpVector = Target->GetActorUpVector() * UpOffset;
		SetActorLocation((Target->GetActorLocation() - ForwardVector) + UpVector);
		
		SetActorRotation(Target->GetActorRotation());
	}
}

void ASkateGameCamera::SetTarget(AActor* InTarget)
{
	if (IsValid(InTarget))
	{
		Target = InTarget;
	}
}
