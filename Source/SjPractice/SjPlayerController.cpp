// Fill out your copyright notice in the Description page of Project Settings.


#include "SjPlayerController.h"
#include "EnhancedInputSubsystems.h"

void ASjPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem && DefaultIMC)
	{
		Subsystem->AddMappingContext(DefaultIMC, 0);
	}
}
