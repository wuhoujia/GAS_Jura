// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "UObject/StrongObjectPtr.h"
#include "JuraPlayerController.generated.h"

class AJuraEnemyCharacter;
/**
 * 
 */
UCLASS()
class GAS_JURA_API AJuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> InputMappingCtx;
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> MoveAction;
	// move action call back
	void Move(const FInputActionValue& ActionValue);
	// check cursor
	void CursorTrace();
	TObjectPtr<AJuraEnemyCharacter> LastEnemy;
	TObjectPtr<AJuraEnemyCharacter> CurrentEnemy;
public:
	AJuraPlayerController();
protected:
	virtual void PlayerTick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
