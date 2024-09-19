// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JuraWidgetController.h"
#include "AbilitySystem/JuraCharacterAttributeSet.h"
#include "OverlayWidgetController.generated.h"
struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);
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
protected:
	void HealthChanged(const FOnAttributeChangeData& Health);

	void ManaChanged(const FOnAttributeChangeData& Mana);

	void MaxHealthChanged(const FOnAttributeChangeData& MaxHealth);

	void MaxManaChanged(const FOnAttributeChangeData& MaxMana);
public:
	virtual void BroadcastInitialValue() override;
	virtual void BindCallbacksToDependencies() override;
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChanged OnMaxHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnManaChanged OnManaChanged;
	UPROPERTY(BlueprintAssignable)
	FOnMaxManaChanged OnMaxManaChanged;
};
