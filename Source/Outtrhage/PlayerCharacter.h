// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AttackStrategy.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class OUTTRHAGE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	IAttackStrategy* AttackStrategy1;
	IAttackStrategy* AttackStrategy2;
	IAttackStrategy* AttackStrategy3;
	IAttackStrategy* AttackStrategy4;
	IAttackStrategy* AttackStrategy5;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FVector GetAttackDirection(bool bIsRightStick = true, bool bIsRaw = false);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
