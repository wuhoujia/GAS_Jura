// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraEnemyCharacter.h"

#include "AbilitySystem/JuraAbilitySystemComponent.h"
#include "AbilitySystem/JuraCharacterAttributeSet.h"

void AJuraEnemyCharacter::HighLight()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(250);
}

void AJuraEnemyCharacter::UnHighLight()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AJuraEnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	UJuraAbilitySystemComponent* JuraAbilitySystemComponent = Cast<UJuraAbilitySystemComponent>(AbilitySystemComponent);
	JuraAbilitySystemComponent->ActorInfoSet();
}

AJuraEnemyCharacter::AJuraEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UJuraAbilitySystemComponent>("AbilityComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UJuraCharacterAttributeSet>("AttributeSet");
}

void AJuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}
