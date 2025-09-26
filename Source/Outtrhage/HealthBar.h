// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/ProgressBar.h"
#include "HealthBar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepletedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, NewHealth, float, MaxHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OUTTRHAGE_API UHealthBar : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthBar();

	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnHealthDepletedSignature OnHealthDepleted;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	int maxHealth;

	UPROPERTY()
	int currentHealth;

public:	
	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual int GetCurrentHealth() const { return currentHealth; }
	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual int GetMaxHealth() const { return maxHealth; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual void TakeDamage(int damageAmount);
	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual void Heal(int healAmount);
		
};
