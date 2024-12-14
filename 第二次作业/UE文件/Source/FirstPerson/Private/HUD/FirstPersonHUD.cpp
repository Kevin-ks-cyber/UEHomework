// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FirstPersonHUD.h"

#include "Blueprint/UserWidget.h"
#include "HUD/ScoreBoardWidget.h"
#include "HUD/ScoreWidget.h"

void AFirstPersonHUD::CreateScoreWidget()
{
	TObjectPtr<APlayerController>  PlayerController = GetOwningPlayerController();
	if (ScoreWidgetClass!=nullptr)
	{
		ScoreWidgetInstance = CreateWidget<UScoreWidget>(PlayerController,ScoreWidgetClass);
		ScoreWidgetInstance->AddToViewport();
	}
}

void AFirstPersonHUD::CreateScoreBoardWidget()
{
	TObjectPtr<APlayerController>  PlayerController = GetOwningPlayerController();
	if (ScoreBoardWidgetClass!=nullptr)
	{
		ScoreBoardWidgetInstance = CreateWidget<UScoreBoardWidget>(PlayerController,ScoreBoardWidgetClass);
		ScoreBoardWidgetInstance->AddToViewport();
	}
}

void AFirstPersonHUD::UpdateScore(int32 Score)
{
	ScoreWidgetInstance->SetScore(Score);
}

void AFirstPersonHUD::UpdateScoreList(TArray<FString> Scores)
{
	ScoreBoardWidgetInstance->UpdateScores(Scores);
}
