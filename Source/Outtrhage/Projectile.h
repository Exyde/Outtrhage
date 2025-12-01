// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProjectileSpawnedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProjectileStartDamageSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProjectileOnTickSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProjectileEndSignature);

enum class EProjectileState : uint8
{
	Spawning,
	Active,
	Deactivating,
	Inactive
};

UCLASS()
class OUTTRHAGE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	int damage;
	int timer;
	EProjectileState currentState;

	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnProjectileSpawnedSignature OnProjectileSpawned;
	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnProjectileStartDamageSignature OnProjectileStartDamage;
	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnProjectileOnTickSignature OnProjectileOnTick;
	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnProjectileEndSignature OnProjectileEnd;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
