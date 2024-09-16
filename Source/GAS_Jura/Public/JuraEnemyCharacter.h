// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JuraBaseCharacter.h"
#include "Interface/EnemyInterface.h"
#include "JuraEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAS_JURA_API AJuraEnemyCharacter : public AJuraBaseCharacter,public IEnemyInterface
{
	GENERATED_BODY()
public:
	AJuraEnemyCharacter();
	virtual void BeginPlay() override;
	virtual void HighLight() override;
	virtual void UnHighLight() override;
};
