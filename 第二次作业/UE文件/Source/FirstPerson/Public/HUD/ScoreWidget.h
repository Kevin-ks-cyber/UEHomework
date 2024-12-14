// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetScore(int32 NewScore);
protected:
	virtual bool Initialize() override;
	
private:
	int32 Score;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ScoreText;
};
