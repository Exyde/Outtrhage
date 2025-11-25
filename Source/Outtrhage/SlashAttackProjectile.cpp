// SlashAttackProjectile.cpp
// Boilerplate implementation for ASlashAttackProjectile (inherits from a Projectile base)

#include "SlashAttackProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values
ASlashAttackProjectile::ASlashAttackProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    // If the base Projectile class doesn't set these up, uncomment and adapt:
    /*
    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    CollisionComp->InitSphereRadius(5.0f);
    CollisionComp->SetCollisionProfileName("Projectile");
    RootComponent = CollisionComp;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->UpdatedComponent = CollisionComp;
    ProjectileMovement->InitialSpeed = 3000.f;
    ProjectileMovement->MaxSpeed = 3000.f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;

    CollisionComp->OnComponentHit.AddDynamic(this, &ASlashAttackProjectile::OnHit);
    */
}

// Called when the game starts or when spawned
void ASlashAttackProjectile::BeginPlay()
{
    Super::BeginPlay();
    OnProjectileSpawned.Broadcast();
    UE_LOG(LogTemp, Verbose, TEXT("%s - BeginPlay"), *GetName());
}

// Called every frame
void ASlashAttackProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    OnProjectileOnTick.Broadcast();
    currentState = EProjectileState::Active;
    timer += DeltaTime;
    
    if (timer >= timeToDamage)
    {
        OnProjectileStartDamage.Broadcast();
        // Implement damage logic here if needed
    }
}