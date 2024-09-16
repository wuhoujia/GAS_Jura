// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "JuraPlayerState.generated.h"

class UJuraCharacterAttributeSet;
class UJuraAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GAS_JURA_API AJuraPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly,Category="Ability")
	TObjectPtr<UJuraAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditDefaultsOnly,Category="Ability")
	TObjectPtr<UJuraCharacterAttributeSet> AttributeSet;
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UJuraCharacterAttributeSet* GetAttributeSet();
	AJuraPlayerState();
};
