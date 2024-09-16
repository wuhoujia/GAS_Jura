// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraBaseCharacter.h"

AJuraBaseCharacter::AJuraBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
}
// Called when the game starts or when spawned
void AJuraBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

