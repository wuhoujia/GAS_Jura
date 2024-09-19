// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetControllers/JuraWidgetController.h"

void UJuraWidgetController::SetWidgetController(const FWidgetControllerParams& WCP)
{
	AbilitySystemComponent = WCP.AbilitySystemComponent;
	JuraPlayerController = WCP.JuraPlayerController;
	JuraPlayerState = WCP.JuraPlayerState;
	JuraAttributeSet = WCP.JuraAttributeSet;
}

void UJuraWidgetController::BroadcastInitialValue()
{
	
}

void UJuraWidgetController::BindCallbacksToDependencies()
{

}
