// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkateGameScoreWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class SKATEGAME_API USkateGameScoreWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	
public:
	UFUNCTION()
	void OnScoreUpdate(int32 CurrentScore);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> ScoreText;
};
