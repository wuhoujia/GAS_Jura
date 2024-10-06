// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectActor.generated.h"

class UAbilitySystemComponent;
struct FActiveGameplayEffectHandle;
class UGameplayEffect;
class USphereComponent;

UENUM(BlueprintType)
enum EGameplayEffectApplyPolicy
{
	EEAP_BeginOverlap,
	EEAP_EndOverlap,
	EEAP_DoNotApplay
};

UENUM(BlueprintType)
enum EGameplayEffectRemovalPolicy
{
	EERP_EndOverlap,
	EERP_DoNotRemove
};

USTRUCT(BlueprintType)
struct FGameplayEffectWrapper
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TEnumAsByte<EGameplayEffectApplyPolicy> ApplyPolicy = EGameplayEffectApplyPolicy::EEAP_BeginOverlap;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TEnumAsByte<EGameplayEffectRemovalPolicy> RemovalPolicy = EGameplayEffectRemovalPolicy::EERP_DoNotRemove;
};

USTRUCT()
struct FGameplayEffectRemoveHandler
{
	GENERATED_BODY()
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
	FActiveGameplayEffectHandle Handle;
	FGameplayEffectRemoveHandler(TSubclassOf<UGameplayEffect> GameplayEffectClass,FActiveGameplayEffectHandle Handle)
		:GameplayEffectClass(GameplayEffectClass),Handle(Handle){};
	FGameplayEffectRemoveHandler() = default;
};

UCLASS()
class GAS_JURA_API AGameplayEffectActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGameplayEffectActor();
	UFUNCTION(BlueprintCallable)
	void ApplyGameplayEffectToActor(AActor* TargetActor,TSubclassOf<UGameplayEffect> GameplayEffect);
	UFUNCTION(BlueprintCallable)
	void RemoveGameplayEffect(AActor* TargetActor,TSubclassOf<UGameplayEffect> GameplayEffectClass);
	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(AActor* TargetActor);
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	bool bShouldDestroy = false;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<FGameplayEffectWrapper> InstantGameplayEffectClasses;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<FGameplayEffectWrapper> DurationGameplayEffectClasses;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<FGameplayEffectWrapper> InfiniteGameplayEffectClasses;
	TMap<UAbilitySystemComponent*,TArray<FGameplayEffectRemoveHandler>> GameplayEffectHandles;
private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess))
	float EffectLevel = 1.f;
};
