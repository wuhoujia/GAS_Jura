// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/GameplayEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/JuraCharacterAttributeSet.h"
#include "Components/SphereComponent.h"


AGameplayEffectActor::AGameplayEffectActor()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldStatic,ECR_Block);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldDynamic,ECR_Overlap);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(SphereComponent);
	StaticMeshComponent->SetupAttachment(SphereComponent);
}

void AGameplayEffectActor::BeginPlay()
{
	Super::BeginPlay();
	if (SphereComponent)
	{
		SphereComponent->OnComponentBeginOverlap.AddDynamic(this,&AGameplayEffectActor::OnSphereBeginOverlap);
		SphereComponent->OnComponentEndOverlap.AddDynamic(this,&AGameplayEffectActor::OnSphereEndOverlap);
	}
}

void AGameplayEffectActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAbilitySystemComponent* AbilitySystemComponent = AbilitySystemInterface->GetAbilitySystemComponent();
		const UJuraCharacterAttributeSet* JuraCharacterAttributeSet = Cast<UJuraCharacterAttributeSet>(AbilitySystemComponent->GetAttributeSet(UJuraCharacterAttributeSet::StaticClass()));
		UJuraCharacterAttributeSet* MutableJuraCharacterAttributes = const_cast<UJuraCharacterAttributeSet*>(JuraCharacterAttributeSet);
		MutableJuraCharacterAttributes->SetHealth(MutableJuraCharacterAttributes->GetHealth()+25.f);
		Destroy();
	}
}

void AGameplayEffectActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

