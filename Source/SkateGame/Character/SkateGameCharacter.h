// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SkateGameCharacter.generated.h"

class UInputAction;

UCLASS()
class SKATEGAME_API ASkateGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkateGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/** Called for acceleration input */
	UFUNCTION()
	void Accelerate(const FInputActionValue& Value);
	
	/** Called for acceleration input */
	UFUNCTION()
	void StopAccelerate();
	
	/** Called for acceleration input */
	UFUNCTION()
	void Rotate(const FInputActionValue& Value);

	/** Called for jump input */
	virtual void Jump() override;

	/** Called for jump input */
	virtual void StopJumping() override;

	/** Called for jump input */
	UFUNCTION()
	void Impulse(const FInputActionValue& Value);

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	bool bIsJumping = false;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	bool bIsMoving = false;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	bool bCanImpulse = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	float ImpulseForce = 100.0f;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	float BaseSpeed = 0.0f;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	float CurrentSpeed = 0.0f;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	float ImpulseCooldown = 2.0f;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Gameplay, meta=(AllowPrivateAccess = "true"))
	float ImpulseCooldownTimer = 0.0f;
	
	/** Accelerate Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* AccelerateAction;
	
	/** Rotate Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* RotateAction;
	
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	
	/** Jump Impulse Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* ImpulseAction;
};
