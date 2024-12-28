// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/BulletWidget.h"

#include "Components/TextBlock.h"

void UBulletWidget::SetBulletNumber(int32 NewBulletNumber)
{
	if (BulletText)
	{
		FString ScoreString = FString::Printf(TEXT("剩余子弹数: %d"), NewBulletNumber);
		BulletText->SetText(FText::FromString(ScoreString));
	}
}

bool UBulletWidget::Initialize()
{
	return Super::Initialize();
}
