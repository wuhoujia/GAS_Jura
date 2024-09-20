// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/JuraCharacterAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayAbilityBlueprint.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UJuraCharacterAttributeSet::UJuraCharacterAttributeSet()
{
	InitHealth(30);
	InitMana(30.f);
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

void UJuraCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue,0.f,GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue,0.f,GetMaxMana());
	}
}

void UJuraCharacterAttributeSet::MakeEffectProperties(const FGameplayEffectModCallbackData& Data,
	FEffectProperties& Props)
{
	Props.EffectContextHandle = Data.EffectSpec.GetEffectContext();
	Props.SourceAbilitySystemComponent = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
	if (IsValid(Props.SourceAbilitySystemComponent)&&Props.SourceAbilitySystemComponent->AbilityActorInfo.IsValid()&&Props.SourceAbilitySystemComponent->AbilityActorInfo.Get()->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceAbilitySystemComponent->AbilityActorInfo.Get()->AvatarActor.Get();
		Props.SourceController = Props.SourceAbilitySystemComponent->AbilityActorInfo.Get()->PlayerController.Get();
		if(Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (APawn* pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = pawn->GetController();
			}
		}
		if(Props.SourceController)
		{
			Props.SourceCharacter = Props.SourceController.Get()->GetCharacter();
		}
	}
	if (Data.Target.AbilityActorInfo.IsValid()&&Data.Target.AbilityActorInfo->AvatarActor.IsValid()&&Data.Target.AbilityActorInfo.Get()->PlayerController.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo.Get()->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UJuraCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	FEffectProperties Props;
	MakeEffectProperties(Data,Props);
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

