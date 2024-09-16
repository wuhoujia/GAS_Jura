// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/JuraAbilitySystemComponent.h"
#include "JuraCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_JURA_API UJuraCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UJuraCharacterAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Health,Category="First Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, Health)
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxHealth,Category="First Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Mana,Category="First Attributes")
	FGameplayAttributeData Mana; // 法力值
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxMana,Category="First Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, MaxMana)

protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
