// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Hitable.generated.h"

enum DamageType
{
	Normal,
};

enum AttackerTag
{
	Player,
	Enemy,
	Environment,
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHitable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OUTTRHAGE_API IHitable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
		virtual void OnHit(AttackerTag tag, DamageType type, int damage);
};
