// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JuraBaseCharacter.generated.h"

UCLASS(Abstract)
class GAS_JURA_API AJuraBaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AJuraBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,Category="Weapon",meta=(AllowPrivateAccess="true"))
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
