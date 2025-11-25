#pragma once

#include "Projectile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlashAttackProjectile.generated.h"

UCLASS()
class OUTTRHAGE_API ASlashAttackProjectile : public AProjectile
{
    GENERATED_BODY()

public:
    ASlashAttackProjectile();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

protected:
    float timeToDamage;
    // Add properties here
    
private:
    // Add private methods here
};