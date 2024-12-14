// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FirstPersonHUD.generated.h"

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

	void CreateScoreWidget();
	void CreateScoreBoardWidget();
	void UpdateScore(int32 Score);
	void UpdateScoreList(TArray<FString> Scores);
};
