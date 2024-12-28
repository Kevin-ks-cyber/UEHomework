// Fill out your copyright notice in the Description page of Project Settings.



#include "FirstPerson/Public/Cube/TargetCube.h"

#include "JsonTool/DataManager.h"

// Sets default values
ATargetCube::ATargetCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CubeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Cube Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (CubeMeshAsset.Succeeded())
	{
		TObjectPtr<UStaticMesh> CubeMesh = CubeMeshAsset.Object;
		CubeMeshComponent->SetStaticMesh(CubeMesh);
		CubeMeshComponent->SetSimulatePhysics(true);
		SetRootComponent(CubeMeshComponent);
	}
	FString FilePath = FPaths::ProjectDir() + TEXT("GameData.json");
	int32 CubeScore;
	UDataManager::GetIntFromJson(TEXT("CubeScore"), CubeScore,FilePath);
	Health = 2;
	Score = CubeScore;
}

// Called when the game starts or when spawned
void ATargetCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

