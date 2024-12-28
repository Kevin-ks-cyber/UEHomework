// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

class AFirstPersonCharacter;
class UTP_WeaponComponent;
class UTP_PickUpComponent;

UCLASS()
class FIRSTPERSON_API ARifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Bullet)
	int32 BulletNumber;

	UFUNCTION(BlueprintCallable)
	int32 GetBulletNumber();
	UFUNCTION(BlueprintCallable)
	void SetBulletNumber(int32 NewBulletNumber);
	/*/** Please add a variable description #1#
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UTP_WeaponComponent> TP_Weapon;

	/** Please add a variable description #1#
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UTP_PickUpComponent> TP_PickUp;*/
	
};


