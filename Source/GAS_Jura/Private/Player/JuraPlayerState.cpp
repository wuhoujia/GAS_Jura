// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/JuraPlayerState.h"
#include "AbilitySystem/JuraAbilitySystemComponent.h"
#include "AbilitySystem/JuraCharacterAttributeSet.h"

UAbilitySystemComponent* AJuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UJuraCharacterAttributeSet* AJuraPlayerState::GetAttributeSet()
{
	return AttributeSet;
}

AJuraPlayerState::AJuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UJuraAbilitySystemComponent>("AbilityComponent");
	AttributeSet = CreateDefaultSubobject<UJuraCharacterAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;
}
