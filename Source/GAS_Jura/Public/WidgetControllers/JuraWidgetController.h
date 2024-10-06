// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JuraWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;


USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()
	FWidgetControllerParams(){}
	FWidgetControllerParams(
		UAbilitySystemComponent* ASC,
		UAttributeSet* AS,
		APlayerController* PC,
		APlayerState* PS):
	AbilitySystemComponent(ASC),
	JuraAttributeSet(AS),
	JuraPlayerController(PC),
	JuraPlayerState(PS){};
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAttributeSet> JuraAttributeSet;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerController> JuraPlayerController;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerState> JuraPlayerState;
};
UCLASS()
class GAS_JURA_API UJuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	void SetWidgetController(const FWidgetControllerParams& WCP);
	virtual void BroadcastInitialValue();
	virtual void BindCallbacksToDependencies();
protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAttributeSet> JuraAttributeSet;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerController> JuraPlayerController;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerState> JuraPlayerState;
};
