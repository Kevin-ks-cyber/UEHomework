// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetCube.generated.h"

UCLASS()
class FIRSTPERSON_API ATargetCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere ,BlueprintReadWrite,Category="Cube",meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent>  CubeMeshComponent;
	
	UPROPERTY(EditAnywhere ,BlueprintReadWrite,Category="Cube",meta=(AllowPrivateAccess="true"))
	int32 Health ;
	
	/** Please add a variable description */
	UPROPERTY(EditAnywhere ,BlueprintReadWrite,Category="Cube",meta=(AllowPrivateAccess="true"))
	int32 Score;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
