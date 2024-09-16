// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "JuraBaseCharacter.generated.h"

class UJuraCharacterAttributeSet;
class UJuraAbilitySystemComponent;

UCLASS(Abstract)
class GAS_JURA_API AJuraBaseCharacter : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AJuraBaseCharacter();
	
protected:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UJuraCharacterAttributeSet* GetAttributeSet();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,Category="Weapon",meta=(AllowPrivateAccess="true"))
	TObjectPtr<USkeletalMeshComponent> Weapon;
	UPROPERTY(EditDefaultsOnly,Category="Ability")
	TObjectPtr<UJuraAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditDefaultsOnly,Category="Ability")
	TObjectPtr<UJuraCharacterAttributeSet> AttributeSet;
};
