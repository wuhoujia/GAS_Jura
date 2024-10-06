// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "JuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FAssetsTagDelegate,const FGameplayTagContainer&)
/**
 * 
 */
UCLASS()
class GAS_JURA_API UJuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void ActorInfoSet();
	FAssetsTagDelegate EffectTags;
};
