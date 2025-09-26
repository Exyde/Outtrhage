// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"



// Sets default values for this component's properties
UHealthBar::UHealthBar()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthBar::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = maxHealth;
}

void UHealthBar::TakeDamage(int damageAmount)
{
	currentHealth -= damageAmount;
	OnHealthChanged.Broadcast(currentHealth, maxHealth);
	if (currentHealth < 0)
	{
		currentHealth = 0;
		OnHealthDepleted.Broadcast();
	}
}

void UHealthBar::Heal(int healAmount)
{
	currentHealth += healAmount;
	OnHealthChanged.Broadcast(currentHealth, maxHealth);
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}

