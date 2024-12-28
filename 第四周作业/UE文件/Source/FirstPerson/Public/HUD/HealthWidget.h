// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetHealthPercent(float NewHealthPercent);
protected:
	virtual bool Initialize() override;
private:
	float HealthPercent;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthPercentBar;
};
