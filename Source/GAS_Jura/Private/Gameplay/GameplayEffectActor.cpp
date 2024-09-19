// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/GameplayEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"


AGameplayEffectActor::AGameplayEffectActor()
{	
}


void AGameplayEffectActor::ApplyGameplayEffectToActor(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffect)
{
	UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(!AbilitySystemComponent) return;
	check(GameplayEffect);
	FGameplayEffectContextHandle GameplayEffectContext = AbilitySystemComponent->MakeEffectContext();
	GameplayEffectContext.AddSourceObject(this);
	const FGameplayEffectSpecHandle GameplayEffectSpec = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect,1.f,GameplayEffectContext);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GameplayEffectSpec.Data.Get());
}


