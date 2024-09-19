// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JuraWidgetController.h"
#include "OverlayWidgetController.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged,float,NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChanged,float,NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChanged,float,NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChanged,float,NewMaxMana);

/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class GAS_JURA_API UOverlayWidgetController : public UJuraWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValue() override;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChanged OnMaxHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnManaChanged OnManaChanged;
	UPROPERTY(BlueprintAssignable)
	FOnMaxManaChanged OnMaxManaChanged;
};
