// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/ScoreWidget.h"

#include "Components/TextBlock.h"

void UScoreWidget::SetScore(int32 NewScore)
{
	if (ScoreText)
	{
		FString ScoreString = FString::Printf(TEXT("Score: %d"), NewScore);
		ScoreText->SetText(FText::FromString(ScoreString));
	}
}

bool UScoreWidget::Initialize()
{
	if (Super::Initialize())
	{
		SetScore(0);
		return true;
	}
	else
	{
		return false;
	}
	
}
