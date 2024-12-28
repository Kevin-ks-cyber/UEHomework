// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/HealthWidget.h"

#include "Components/ProgressBar.h"

void UHealthWidget::SetHealthPercent(float NewHealthPercent)
{
	HealthPercent = NewHealthPercent;
	if (HealthPercentBar)
	{
		HealthPercentBar->SetPercent(HealthPercent);
	}
}

bool UHealthWidget::Initialize()
{

	if (Super::Initialize())
	{
		SetHealthPercent(1.f);
		return true;
	}
	else
	{
		return false;
	}
}
