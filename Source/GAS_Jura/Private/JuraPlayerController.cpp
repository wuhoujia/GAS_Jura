/// Fill out your copyright notice in the Description page of Project Settings.


#include "JuraPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "JuraEnemyCharacter.h"
#include "Interface/EnemyInterface.h"

void AJuraPlayerController::Move(const FInputActionValue& ActionValue)
{
	const FVector2D InputValue = ActionValue.Get<FVector2D>();
	const FRotator ControlRot = GetControlRotation();
	const FRotator YawRotation(0.f,ControlRot.Yaw,0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputValue.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputValue.X);
	}
}

void AJuraPlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility,false,HitResult);
	if (!HitResult.bBlockingHit) return;
	LastEnemy = CurrentEnemy;
	if (!Cast<IEnemyInterface>(HitResult.GetActor())) CurrentEnemy = nullptr;
	else CurrentEnemy = Cast<AJuraEnemyCharacter>(HitResult.GetActor());
	if (LastEnemy)
	{
		LastEnemy->UnHighLight();
	}
	if (CurrentEnemy)
	{
		CurrentEnemy->HighLight();
	}
}

AJuraPlayerController::AJuraPlayerController()
{
	bReplicates = true;
	LastEnemy = nullptr;
	CurrentEnemy = nullptr;
}

void AJuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AJuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(InputMappingCtx.Get());
	UEnhancedInputLocalPlayerSubsystem* LocalInputSubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(LocalInputSubSystem)
		LocalInputSubSystem->AddMappingContext(InputMappingCtx.Get(),0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputMode;
	InputMode.SetHideCursorDuringCapture(false);
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}

void AJuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	check(MoveAction);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AJuraPlayerController::Move);
}
