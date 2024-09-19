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
