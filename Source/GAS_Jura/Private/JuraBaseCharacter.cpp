// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraBaseCharacter.h"
#include "AbilitySystem/JuraAbilitySystemComponent.h"

AJuraBaseCharacter::
AJuraBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AJuraBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UJuraCharacterAttributeSet* AJuraBaseCharacter::GetAttributeSet()
{
	return AttributeSet;
}

// Called when the game starts or when spawned
void AJuraBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

