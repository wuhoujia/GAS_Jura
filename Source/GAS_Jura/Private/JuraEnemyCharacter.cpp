// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraEnemyCharacter.h"

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

AJuraEnemyCharacter::AJuraEnemyCharacter()
{
}
