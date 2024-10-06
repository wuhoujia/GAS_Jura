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
	HealthDelegate.AddLambda([this](const FOnAttributeChangeData& health)
	{
		OnHealthChanged.Broadcast(health.NewValue);
	});
	
	FOnGameplayAttributeValueChange& MaxHealthDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetMaxHealthAttribute());
	MaxHealthDelegate.AddLambda([this](const FOnAttributeChangeData& MaxHealth)
	{
		OnMaxHealthChanged.Broadcast(MaxHealth.NewValue);
	});
	
	FOnGameplayAttributeValueChange& ManaDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetManaAttribute());
	ManaDelegate.AddLambda([this](const FOnAttributeChangeData& Mana)
	{
		OnManaChanged.Broadcast(Mana.NewValue);
	});
	
	FOnGameplayAttributeValueChange& MaxManaDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CastedJuraAS->GetMaxManaAttribute());
	MaxManaDelegate.AddLambda([this](const FOnAttributeChangeData& MaxMana)
	{
		OnMaxManaChanged.Broadcast(MaxMana.NewValue);
	});

	
	UJuraAbilitySystemComponent* JuraAbilitySystemComponent = Cast<UJuraAbilitySystemComponent>(AbilitySystemComponent);
	// 硬编码加载 -- 蓝图编辑加载不生效
	if(!MessageDataTable)
	{
		const FName Path = TEXT("/Script/Engine.DataTable'/Game/Blueprint/UI/DataTable/MsgWidgets.MsgWidgets'");
		MessageDataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *Path.ToString()));
	}
	
	JuraAbilitySystemComponent->EffectTags.AddLambda([this](const FGameplayTagContainer& AssetTags)
	{
		for(const FGameplayTag& Tag:AssetTags)
		{
			FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
			if (Tag.MatchesTag(MessageTag))
			{
				const FTagMessage* TagMessage = GetRowByName<FTagMessage>(MessageDataTable,Tag);
				if(TagMessage)	OnMessageWidgetChanged.Broadcast(*TagMessage);
			}
		}
	});
}

