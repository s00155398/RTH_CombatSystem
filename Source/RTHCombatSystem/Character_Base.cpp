// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Base.h"
#include "Text.h"
// Sets default values
ACharacter_Base::ACharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitSound = CreateDefaultSubobject<UAudioComponent>(FName("Hit AudioComponent"));
	HitSound->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MissSound = CreateDefaultSubobject<UAudioComponent>(FName("Miss AudioComponent"));
	MissSound->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	HitNotificationText = CreateDefaultSubobject<UTextRenderComponent>(FName("Hit Notification Text"));
	HitNotificationText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
}

// Called when the game starts or when spawned
void ACharacter_Base::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HealthStat <= 0)
	{
		IsDead = true;
	}
}

// Called to bind functionality to input
void ACharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacter_Base::CarryOutAttack_Implementation(ACharacter_Base* Attacker, ACharacter_Base* Defender)
{
	
	int Attack = Attacker->AttackStat;
	int Defence = Defender->DefenceStat;

	int ranNum = FMath::RandRange(1, 20);
	
	if (ranNum + Attack > Defence)
	{
		Defender->HealthStat -= 25;
		Attacker->HitNotificationText->SetText(FText::FromString("Hit"));
		HitSound->Play();
	}
	else
	{
		Attacker->HitNotificationText->SetText(FText::FromString("Miss"));
		MissSound->Play();
	}
}
