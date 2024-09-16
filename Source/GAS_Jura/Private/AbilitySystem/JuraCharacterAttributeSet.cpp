// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/JuraCharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

UJuraCharacterAttributeSet::UJuraCharacterAttributeSet()
{
	InitHealth(100.f);
	InitMana(100.f);
	InitMaxHealth(100.f);
	InitMaxMana(100.f);
}

void UJuraCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UJuraCharacterAttributeSet,Health,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UJuraCharacterAttributeSet,MaxHealth,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UJuraCharacterAttributeSet,Mana,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UJuraCharacterAttributeSet,MaxMana,COND_None,REPNOTIFY_Always);
}

void UJuraCharacterAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJuraCharacterAttributeSet,Health,OldHealth);
}

void UJuraCharacterAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJuraCharacterAttributeSet,MaxHealth,OldMaxHealth);
}

void UJuraCharacterAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJuraCharacterAttributeSet,Mana,OldMana);
}

void UJuraCharacterAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJuraCharacterAttributeSet,MaxMana,OldMaxMana);
}
