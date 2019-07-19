// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "Character_Base.generated.h"
UCLASS()
class RTHCOMBATSYSTEM_API ACharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_Base();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,  Category = "Stats")
		int32 AttackStat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats")
		int32 DefenceStat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats")
		int32 HealthStat;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Attack")
	void CarryOutAttack(ACharacter_Base* Attacker, ACharacter_Base* Defender);


	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* HitSound = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* MissSound = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UTextRenderComponent* HitNotificationText = nullptr;
};
