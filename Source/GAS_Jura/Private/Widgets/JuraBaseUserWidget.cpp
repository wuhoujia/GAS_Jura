// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/JuraBaseUserWidget.h"

UJuraBaseUserWidget::UJuraBaseUserWidget()
{
	
}

void UJuraBaseUserWidget::SetWidgetController(UObject* InWidgetController)
{
	this->WidgetController = InWidgetController;
	OnWidgetControllerSet();
}

