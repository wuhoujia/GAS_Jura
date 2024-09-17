// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JuraWidgetController.generated.h"

class AJuraPlayerController;
class AJuraPlayerState;
class UJuraCharacterAttributeSet;
class UJuraAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GAS_JURA_API UJuraWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UJuraAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UJuraCharacterAttributeSet> JuraAttributeSet;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AJuraPlayerController> JuraPlayerController;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AJuraPlayerState> JuraPlayerState;
	
};
