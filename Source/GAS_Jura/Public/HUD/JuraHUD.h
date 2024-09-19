// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "JuraHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class AJuraPlayerController;
class AJuraPlayerState;
class UJuraCharacterAttributeSet;
class UJuraAbilitySystemComponent;
class UOverlayWidgetController;
class UJuraBaseUserWidget;
/**
 * 
 */
UCLASS()
class GAS_JURA_API AJuraHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly,Category="Overlay",meta=(AllowPrivateAccess="true"))
	TObjectPtr<UJuraBaseUserWidget> OverlayWidget;
	UFUNCTION(BlueprintCallable)
	UOverlayWidgetController* GetOverlayWidgetController(UAbilitySystemComponent*ASC,UAttributeSet*AS ,APlayerState* PS,APlayerController* PC);
	UFUNCTION(BlueprintCallable)
	void InitOverlay(UAbilitySystemComponent*ASC,UAttributeSet*AS ,APlayerState* PS,APlayerController* PC);
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere,Category="Overlay")
	TSubclassOf<UJuraBaseUserWidget> OverlayWidgetClass;
	UPROPERTY(EditAnywhere,Category="Overlay")
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	UPROPERTY(BlueprintReadOnly,Category="Overlay",meta=(AllowPrivateAccess="true"))
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
