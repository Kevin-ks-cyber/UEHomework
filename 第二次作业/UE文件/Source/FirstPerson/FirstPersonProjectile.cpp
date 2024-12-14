// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstPersonProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "JsonTool/DataManager.h"

void AFirstPersonProjectile::DestroyBullet()
{
	Destroy();
}

AFirstPersonProjectile::AFirstPersonProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AFirstPersonProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AFirstPersonProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		FString FilePath = FPaths::ProjectDir() + TEXT("GameData.json");
		float ScaleFactor;
		UDataManager::GetFloatFromJson(TEXT("ScaleFactor"), ScaleFactor,FilePath);
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		OtherComp->SetWorldScale3D(FVector(ScaleFactor,ScaleFactor,ScaleFactor));
		//GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,HitComp->GetOwner()->GetName());
		//GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,this->GetOwner()->GetName().Append("子弹owner"));
		//GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,this->GetOwner()->GetOwner()->GetName().Append("Rifle Owner"));
		GetWorldTimerManager().SetTimer(TimerHandle_DelayedDestroy, this, &AFirstPersonProjectile::DestroyBullet, 0.01f, false);
		//Destroy();
	}
}