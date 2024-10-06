// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/JuraAbilitySystemComponent.h"

void UJuraAbilitySystemComponent::ActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddLambda([this](UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle GameplayEffectHandle)
	{
		FGameplayTagContainer TagContainer;
		GameplayEffectSpec.GetAllAssetTags(TagContainer);
		// 把Effect生效得到的所有Tag信息广播出去
		EffectTags.Broadcast(TagContainer);
	});
}
