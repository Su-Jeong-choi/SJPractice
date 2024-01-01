// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SjPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;

UCLASS()
class SJPRACTICE_API ASjPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultIMC;
	
};
