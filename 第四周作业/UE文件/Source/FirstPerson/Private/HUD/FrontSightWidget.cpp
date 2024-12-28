// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FrontSightWidget.h"

#include "Components/TextBlock.h"

void UFrontSightWidget::SetFrontSightRed()
{
	FrontSightText->SetColorAndOpacity(FColor::Red);
}

void UFrontSightWidget::SetFrontSightWhite()
{
	FrontSightText->SetColorAndOpacity(FColor::White);
}

bool UFrontSightWidget::Initialize()
{
	
	return Super::Initialize();
}
