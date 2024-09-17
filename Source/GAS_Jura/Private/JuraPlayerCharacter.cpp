// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/JuraAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/JuraPlayerState.h"

AJuraPlayerCharacter::AJuraPlayerCharacter()
{
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	MovementComponent->bOrientRotationToMovement = true;
	MovementComponent->RotationRate = FRotator(0.,400.f,0.f);
	MovementComponent->bConstrainToPlane = true;
	MovementComponent->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AJuraPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AJuraPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	/*在服务器上初始化ASC*/
	InitAbilityActorInfo();
}

void AJuraPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	/*在客户端上初始化ASC*/
	InitAbilityActorInfo();
}

void AJuraPlayerCharacter::InitAbilityActorInfo()
{
	AJuraPlayerState* JuraPlayerState = GetPlayerState<AJuraPlayerState>();
	check(JuraPlayerState);
	JuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(JuraPlayerState,this);
	AbilitySystemComponent = Cast<UJuraAbilitySystemComponent>(JuraPlayerState->GetAbilitySystemComponent());
	AttributeSet = JuraPlayerState->GetAttributeSet();
}
