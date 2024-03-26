// Fill out your copyright notice in the Description page of Project Settings.


#include "General/SkateGamePlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Actor/SkateGameCamera.h"
#include "Blueprint/UserWidget.h"


void ASkateGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	CameraActor = GetWorld()->SpawnActor<ASkateGameCamera>(CameraTemplate);
	if (IsValid(CameraActor))
	{
		CameraActor->SetTarget(GetPawn());
		SetViewTargetWithBlend(CameraActor);
	}
	
	for (const auto& WidgetClass : WidgetsToSpawn)
	{
		if (UUserWidget* Widget = CreateWidget<UUserWidget>(this, WidgetClass))
		{
			Widget->AddToViewport();
			Widget->SetVisibility(ESlateVisibility::Visible);

			Widgets.Add(Widget);
		}
	}
}
