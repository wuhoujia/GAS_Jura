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
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GameplayEffectSpec.Data.Get());
	// 区分无限效果
	if(GameplayEffectSpec.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite)
	{
		TArray<FGameplayEffectRemoveHandler>& GameplayEffectRemoveHandlers = GameplayEffectHandles.FindOrAdd(AbilitySystemComponent);
		GameplayEffectRemoveHandlers.Add(FGameplayEffectRemoveHandler(GameplayEffect,ActiveGameplayEffectHandle));
	}
}

void AGameplayEffectActor::RemoveGameplayEffect(AActor* TargetActor,TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(!AbilitySystemComponent) return;
	TArray<FGameplayEffectRemoveHandler>& GameplayEffectRemoveHandlers = GameplayEffectHandles.FindChecked(AbilitySystemComponent);
	TArray<FGameplayEffectRemoveHandler> GameplayEffectLeft;
	for (FGameplayEffectRemoveHandler GameplayEffectRemoveHandler : GameplayEffectRemoveHandlers)
	{
		if(GameplayEffectRemoveHandler.GameplayEffectClass == GameplayEffectClass)
		{
			AbilitySystemComponent->RemoveActiveGameplayEffect(GameplayEffectRemoveHandler.Handle,1);
		}
		else
		{
			GameplayEffectLeft.Add(GameplayEffectRemoveHandler);
		}
	}
	// 交换
	Swap(GameplayEffectRemoveHandlers,GameplayEffectLeft);
}

void AGameplayEffectActor::OnBeginOverlap(AActor* TargetActor)
{
	// 即刻性
	for (FGameplayEffectWrapper InstantGameplayEffect : InstantGameplayEffectClasses)
	{
		if (InstantGameplayEffect.ApplyPolicy == EEAP_BeginOverlap)
		{
			ApplyGameplayEffectToActor(TargetActor,InstantGameplayEffect.GameplayEffectClass);
		} 
	}
	// 周期性
	for (FGameplayEffectWrapper DurationGameplayEffect : DurationGameplayEffectClasses)
	{
		if (DurationGameplayEffect.ApplyPolicy == EEAP_BeginOverlap)
		{
			ApplyGameplayEffectToActor(TargetActor,DurationGameplayEffect.GameplayEffectClass);
		} 
	}
	// 无限性
	for (FGameplayEffectWrapper InfiniteGameplayEffect : InfiniteGameplayEffectClasses)
	{
		if (InfiniteGameplayEffect.ApplyPolicy == EEAP_BeginOverlap)
		{
			ApplyGameplayEffectToActor(TargetActor,InfiniteGameplayEffect.GameplayEffectClass);
		} 
	}
}

void AGameplayEffectActor::OnEndOverlap(AActor* TargetActor)
{
	// 即刻性
	for (FGameplayEffectWrapper InstantGameplayEffect : InstantGameplayEffectClasses)
	{
		if (InstantGameplayEffect.ApplyPolicy == EEAP_EndOverlap)
		{
			ApplyGameplayEffectToActor(TargetActor,InstantGameplayEffect.GameplayEffectClass);
		} 
	}
	// 周期性
	for (FGameplayEffectWrapper DurationGameplayEffect : DurationGameplayEffectClasses)
	{
		if (DurationGameplayEffect.ApplyPolicy == EEAP_EndOverlap)
		{
			ApplyGameplayEffectToActor(TargetActor,DurationGameplayEffect.GameplayEffectClass);
		} 
	}
	// 无限性
	for (FGameplayEffectWrapper InfiniteGameplayEffect : InfiniteGameplayEffectClasses)
	{
		if (InfiniteGameplayEffect.ApplyPolicy == EEAP_EndOverlap)
		{
			ApplyGameplayEffectToActor(TargetActor,InfiniteGameplayEffect.GameplayEffectClass);
		}
		// 去除策略 只需要处理 InfiniteEffect
		if(InfiniteGameplayEffect.RemovalPolicy == EERP_EndOverlap)
		{
			RemoveGameplayEffect(TargetActor,InfiniteGameplayEffect.GameplayEffectClass);
		}
	}
	
	
}


