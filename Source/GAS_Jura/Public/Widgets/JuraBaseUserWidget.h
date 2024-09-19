// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JuraBaseUserWidget.generated.h"

class UJuraWidgetController;
/**
 * 
 */
UCLASS()
class GAS_JURA_API UJuraBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UJuraWidgetController* InWidgetController);
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetControllerSet();
private:
	UPROPERTY(BlueprintReadWrite,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UJuraWidgetController> WidgetController;
};
