// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JuraBaseCharacter.h"
#include "JuraPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class GAS_JURA_API AJuraPlayerCharacter : public AJuraBaseCharacter
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere,Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(VisibleAnywhere,Category="Camera")
	TObjectPtr<UCameraComponent> CameraComponent;
public:
	AJuraPlayerCharacter();
};
