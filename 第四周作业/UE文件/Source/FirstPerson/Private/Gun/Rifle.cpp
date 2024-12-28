// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/Rifle.h"

#include "FirstPerson/TP_PickUpComponent.h"
#include "FirstPerson/TP_WeaponComponent.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BulletNumber = 30;
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ARifle::GetBulletNumber()
{
	return BulletNumber;
}

void ARifle::SetBulletNumber(int32 NewBulletNumber)
{
	BulletNumber = NewBulletNumber;
}

/*
void ARifle::HandlePickUp(AFirstPersonCharacter* PickUpCharacter)
{
	if (TP_Weapon->AttachWeapon(PickUpCharacter))
	{
		Cast<FirstAnim> PickUpCharacter->GetMesh1P()->GetAnimInstance()
	}
}
*/

