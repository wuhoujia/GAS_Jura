// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

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
