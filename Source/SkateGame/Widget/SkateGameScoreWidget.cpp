// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateGameScoreWidget.h"

#include "Components/TextBlock.h"
#include "General/SkateGameState.h"

void USkateGameScoreWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ASkateGameState* GameState = Cast<ASkateGameState>(GetWorld()->GetGameState()))
	{
		GameState->OnUpdateScore.AddDynamic(this, &USkateGameScoreWidget::OnScoreUpdate);
	}
}

void USkateGameScoreWidget::OnScoreUpdate(int32 CurrentScore)
{
	if (IsValid(ScoreText))
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("%i"), CurrentScore)));
	}
}
