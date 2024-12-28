// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FrontSightWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UFrontSightWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetFrontSightRed();
	void SetFrontSightWhite();

protected:
	virtual bool Initialize() override;
	
	
private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> FrontSightText;
};
