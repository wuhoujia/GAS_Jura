// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetControllers/OverlayWidgetController.h"

#include "AbilitySystem/JuraCharacterAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValue()
{
	Super::BroadcastInitialValue();
	UJuraCharacterAttributeSet* CastedJuraAS = CastChecked<UJuraCharacterAttributeSet>(JuraAttributeSet);
	float Health = CastedJuraAS->GetHealth();
	float MaxHealth = CastedJuraAS->GetMaxHealth();
	OnHealthChanged.Broadcast(Health);
	OnMaxHealthChanged.Broadcast(MaxHealth);
	OnManaChanged.Broadcast(CastedJuraAS->GetMana());
	OnMaxManaChanged.Broadcast(CastedJuraAS->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UJuraCharacterAttributeSet* CastedJuraAS = CastChecked<UJuraCharacterAttributeSet>(JuraAttributeSet);
	
	FOnGameplayAttributeValueChange& HealthDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetHealthAttribute());
	HealthDelegate.AddUObject(this,&UOverlayWidgetController::HealthChanged);

	FOnGameplayAttributeValueChange& MaxHealthDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetMaxHealthAttribute());
	MaxHealthDelegate.AddUObject(this,&UOverlayWidgetController::MaxHealthChanged);

	FOnGameplayAttributeValueChange& ManaDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetManaAttribute());
	ManaDelegate.AddUObject(this,&UOverlayWidgetController::ManaChanged);

	FOnGameplayAttributeValueChange& MaxManaDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetMaxManaAttribute());
	MaxManaDelegate.AddUObject(this,&UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& health)
{
	OnHealthChanged.Broadcast(health.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& mana)
{
	OnManaChanged.Broadcast(mana.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& MaxHealth)
{
	OnMaxHealthChanged.Broadcast(MaxHealth.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& MaxMana)
{
	OnMaxManaChanged.Broadcast(MaxMana.NewValue);
}
