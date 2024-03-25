// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateGameCharacter.h"

#include "EnhancedInputComponent.h"


// Sets default values
ASkateGameCharacter::ASkateGameCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASkateGameCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASkateGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASkateGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Accelerate
		EnhancedInputComponent->BindAction(AccelerateAction, ETriggerEvent::Triggered, this, &ASkateGameCharacter::Accelerate);

		// Rotate
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ASkateGameCharacter::Rotate);
	}
}

void ASkateGameCharacter::Accelerate(const FInputActionValue& Value)
{
	// input is a Vector2D
	const float ImpulseValue = Value.Get<float>();
	
	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(90, 1.0f, FColor::Cyan, FString::Printf(TEXT("Impulse Value: %f"), ImpulseValue));
	}
}

void ASkateGameCharacter::Rotate(const FInputActionValue& Value)
{
	// input is a Vector2D
	const float RotateDirection = Value.Get<float>();
	
	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(91, 1.0f, FColor::Cyan, FString::Printf(TEXT("Rotate Direction: %f"), RotateDirection));
	}
}

