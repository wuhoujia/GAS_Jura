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

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
    FGameplayEffectContextHandle EffectContextHandle;
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<AActor> SourceAvatarActor;
	UPROPERTY()
	TObjectPtr<AController> SourceController;
	UPROPERTY()
	TObjectPtr<ACharacter> SourceCharacter;
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<AActor> TargetAvatarActor;
	UPROPERTY()
	TObjectPtr<AController> TargetController;
	UPROPERTY()
	TObjectPtr<ACharacter> TargetCharacter;
	FEffectProperties() = default;
};
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
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Strength,Category="Secondary Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, Strength)
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Resilience,Category="Secondary Attribute")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, Resilience)

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Virgo,Category="Secondary Attribute")
	FGameplayAttributeData Virgo;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet,Virgo)
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Intelligence,Category="Secondary Attribute")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet,Intelligence)
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Health,Category="Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, Health)
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxHealth,Category="Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Mana,Category="Vital Attributes")
	FGameplayAttributeData Mana; // 法力值
	ATTRIBUTE_ACCESSORS(UJuraCharacterAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxMana,Category="Vital Attributes")
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
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	UFUNCTION()
	void OnRep_Virgo(const FGameplayAttributeData& OldVirgo) const;
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
private:
	void MakeEffectProperties(const FGameplayEffectModCallbackData& Data,FEffectProperties& Props);
};
