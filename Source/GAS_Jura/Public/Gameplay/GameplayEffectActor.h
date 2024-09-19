// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class GAS_JURA_API AGameplayEffectActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGameplayEffectActor();
	UFUNCTION(BlueprintCallable)
	void ApplyGameplayEffectToActor(AActor* TargetActor,TSubclassOf<UGameplayEffect> GameplayEffect);
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
};
