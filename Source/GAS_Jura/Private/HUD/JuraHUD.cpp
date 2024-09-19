// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/JuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "WidgetControllers/OverlayWidgetController.h"
#include "Widgets/JuraBaseUserWidget.h"


UOverlayWidgetController* AJuraHUD::GetOverlayWidgetController(UAbilitySystemComponent* ASC,
	UAttributeSet* AS, APlayerState* PS, APlayerController* PC)
{
	if (!OverlayWidgetController)
	{
		// 类似单例的处理
		FWidgetControllerParams WCP(ASC,AS,PC,PS);
		OverlayWidgetController = NewObject<UOverlayWidgetController>();
		OverlayWidgetController->SetWidgetController(WCP);
	}
	return OverlayWidgetController;
}

void AJuraHUD::InitOverlay(UAbilitySystemComponent* ASC, UAttributeSet* AS, APlayerState* PS,
                           APlayerController* PC)
{
	checkf(OverlayWidgetClass,TEXT("Overlay Widget Class is not set"));
	checkf(OverlayWidgetControllerClass,TEXT("Overlay Widget Controller Class is not set"));
	OverlayWidget = CreateWidget<UJuraBaseUserWidget>(GetWorld(),OverlayWidgetClass);
	UOverlayWidgetController* OverlayWidgetCtrl = GetOverlayWidgetController(ASC,AS,PS,PC);
	OverlayWidget->SetWidgetController(OverlayWidgetCtrl);
	OverlayWidgetCtrl->BroadcastInitialValue();
	OverlayWidget->AddToViewport();
}

void AJuraHUD::BeginPlay()
{
	Super::BeginPlay();
}
