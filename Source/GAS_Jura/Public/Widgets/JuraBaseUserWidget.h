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
	UJuraBaseUserWidget();
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
protected:
	UFUNCTION(BlueprintImplementableEvent)
	virtual void OnWidgetControllerSet();
private:
	UPROPERTY()
	TObjectPtr<UObject> WidgetController;
};
