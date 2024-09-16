// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "UObject/StrongObjectPtr.h"
#include "JuraPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAS_JURA_API AJuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Category="Input")
	TWeakObjectPtr<UInputMappingContext> InputMappingCtx;
	UPROPERTY(EditAnywhere,Category="Input")
	TWeakObjectPtr<UInputAction> MoveAction;
	// move action call back
	void Move(const FInputActionValue& ActionValue);
public:
	AJuraPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
