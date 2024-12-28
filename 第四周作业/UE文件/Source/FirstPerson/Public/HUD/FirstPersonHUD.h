// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FirstPersonHUD.generated.h"

class UFrontSightWidget;
class UBulletWidget;
class UHealthWidget;
class UScoreBoardWidget;
class UScoreWidget;
/**
 * 
 */
UCLASS()
class FIRSTPERSON_API AFirstPersonHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UScoreWidget> ScoreWidgetClass;
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TObjectPtr<UScoreWidget> ScoreWidgetInstance;

	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UScoreBoardWidget> ScoreBoardWidgetClass;
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TObjectPtr<UScoreBoardWidget> ScoreBoardWidgetInstance;

	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UHealthWidget> HealthWidgetClass;
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TObjectPtr<UHealthWidget> HealthWidgetInstance;

	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UBulletWidget> BulletWidgetClass;
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TObjectPtr<UBulletWidget> BulletWidgetInstance;


	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UFrontSightWidget> FrontSightWidgetClass;
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TObjectPtr<UFrontSightWidget> FrontSightWidgetInstance;
	

	void CreateScoreWidget();
	void UpdateScore(int32 Score);
	
	void CreateScoreBoardWidget();
	void UpdateScoreList(TArray<FString> Scores);

	void CreateHealthWidget();
	void UpdateHealthWidget(float HealthPercent);

	void CreateBulletWidget();
	void UpdateBulletWidget(int32 BulletNumber);

	void CreateFrontSightWidget();
	void SetFrontSightRed();
	void SetFrontSightWhite();
};
