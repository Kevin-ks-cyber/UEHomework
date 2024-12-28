// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FirstPersonHUD.h"

#include "Blueprint/UserWidget.h"
#include "HUD/BulletWidget.h"
#include "HUD/FrontSightWidget.h"
#include "HUD/HealthWidget.h"
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

void AFirstPersonHUD::CreateHealthWidget()
{
	TObjectPtr<APlayerController>  PlayerController = GetOwningPlayerController();
	if (HealthWidgetClass!=nullptr)
	{
		HealthWidgetInstance = CreateWidget<UHealthWidget>(PlayerController,HealthWidgetClass);
		HealthWidgetInstance->AddToViewport();
	}
}

void AFirstPersonHUD::UpdateHealthWidget(float HealthPercent)
{
	HealthWidgetInstance->SetHealthPercent(HealthPercent);
}

void AFirstPersonHUD::CreateBulletWidget()
{
	TObjectPtr<APlayerController>  PlayerController = GetOwningPlayerController();
	if (BulletWidgetClass!=nullptr)
	{
		BulletWidgetInstance = CreateWidget<UBulletWidget>(PlayerController,BulletWidgetClass);
		BulletWidgetInstance->AddToViewport();
	}
}

void AFirstPersonHUD::UpdateBulletWidget(int32 BulletNumber)
{
	BulletWidgetInstance->SetBulletNumber(BulletNumber);
}

void AFirstPersonHUD::CreateFrontSightWidget()
{
	TObjectPtr<APlayerController>  PlayerController = GetOwningPlayerController();
	if (FrontSightWidgetClass!=nullptr)
	{
		FrontSightWidgetInstance = CreateWidget<UFrontSightWidget>(PlayerController,FrontSightWidgetClass);
		FrontSightWidgetInstance->AddToViewport();
	}
}

void AFirstPersonHUD::SetFrontSightRed()
{
	FrontSightWidgetInstance->SetFrontSightRed();
}

void AFirstPersonHUD::SetFrontSightWhite()
{
	FrontSightWidgetInstance->SetFrontSightWhite();
}
