// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/JuraBaseUserWidget.h"


void UJuraBaseUserWidget::SetWidgetController(UJuraWidgetController* InWidgetController)
{
	this->WidgetController = InWidgetController;
	OnWidgetControllerSet();
}
