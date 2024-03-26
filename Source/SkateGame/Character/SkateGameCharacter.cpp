// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateGameCharacter.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/MovementComponent.h"


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

	if (const UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		BaseSpeed = MovementComponent->MaxWalkSpeed;
	}
}

// Called every frame
void ASkateGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (bIsJumping && IsValid(MovementComponent))
	{
		bIsJumping = MovementComponent->IsFalling();
	}

	if (!bIsMoving && CurrentSpeed > BaseSpeed)
	{
		CurrentSpeed = FMath::Max(CurrentSpeed - (BaseSpeed * DeltaTime), BaseSpeed);
		MovementComponent->MaxWalkSpeed = CurrentSpeed;
		AddMovementInput(GetActorForwardVector(), CurrentSpeed / BaseSpeed);
	}

#if defined(UE_EDITOR) || defined(UE_BUILD_DEVELOPMENT)
	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(90, 1.0f, FColor::Cyan, FString::Printf(TEXT("Max speed: %f"), MovementComponent->MaxWalkSpeed));
		GEngine->AddOnScreenDebugMessage(91, 1.0f, FColor::Cyan, FString::Printf(TEXT("Valocity: %s"), *MovementComponent->Velocity.ToString()));
	}
#endif
	
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
		EnhancedInputComponent->BindAction(AccelerateAction, ETriggerEvent::Completed, this, &ASkateGameCharacter::StopAccelerate);

		// Rotate
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ASkateGameCharacter::Rotate);
		
		// Jump
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASkateGameCharacter::Jump);
		
		// Impulse
		EnhancedInputComponent->BindAction(ImpulseAction, ETriggerEvent::Started, this, &ASkateGameCharacter::Impulse);
	}
}

void ASkateGameCharacter::Accelerate(const FInputActionValue& Value)
{
	// input is a Vector2D
	const float ImpulseValue = Value.Get<float>();
	AddMovementInput(GetActorForwardVector(), ImpulseValue);
	bIsMoving = true;

	CurrentSpeed = FMath::Max(CurrentSpeed, BaseSpeed);
	if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		MovementComponent->MaxWalkSpeed = CurrentSpeed;
	}
}

void ASkateGameCharacter::StopAccelerate()
{
	bIsMoving = false;
}

void ASkateGameCharacter::Rotate(const FInputActionValue& Value)
{
	// input is a Vector2D
	const float RotateDirection = Value.Get<float>();

	AddControllerYawInput(RotateDirection);
}

void ASkateGameCharacter::Jump()
{
	Super::Jump();
	bIsJumping = true;
}

void ASkateGameCharacter::StopJumping()
{
	Super::StopJumping();
}

void ASkateGameCharacter::Impulse(const FInputActionValue& Value)
{
	if (bIsMoving)
	{
		if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
		{
			MovementComponent->MaxWalkSpeed += ImpulseForce;
			CurrentSpeed = MovementComponent->MaxWalkSpeed;
		}
	}
}

