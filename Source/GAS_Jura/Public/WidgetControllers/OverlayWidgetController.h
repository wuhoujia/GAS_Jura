// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JuraWidgetController.h"
#include "AbilitySystem/JuraCharacterAttributeSet.h"
#include "OverlayWidgetController.generated.h"
class UJuraBaseUserWidget;
struct FOnAttributeChangeData;
class UDataTable;
/**
 *	给Tag配置消息UI 
 */
USTRUCT(BlueprintType)
struct FTagMessage : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FGameplayTag GameplayTag = FGameplayTag();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FText Message = FText();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<UJuraBaseUserWidget> MessageWidget;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UTexture2D> Image = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChanged, float, NewValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageWidgetChanged,FTagMessage,row);


/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class GAS_JURA_API UOverlayWidgetController : public UJuraWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValue() override;
	virtual void BindCallbacksToDependencies() override;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnMaxHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnManaChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnMaxManaChanged;
	UPROPERTY(BlueprintAssignable)
	FOnMessageWidgetChanged OnMessageWidgetChanged;
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Widget Data")
	TObjectPtr<UDataTable> MessageDataTable;
	template<typename T>
	T* GetRowByName(UDataTable* Table,const FGameplayTag& Tag);
};

template <typename T>
T* UOverlayWidgetController::GetRowByName(UDataTable* Table,const FGameplayTag& Tag)
{
	return Table->FindRow<T>(Tag.GetTagName(),TEXT(""));
}
