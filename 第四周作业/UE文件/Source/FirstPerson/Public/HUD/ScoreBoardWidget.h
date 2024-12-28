// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreBoardWidget.generated.h"
class  UVerticalBox;
class UTextBlock;
/**
 * 
 */
UCLASS()

class FIRSTPERSON_API UScoreBoardWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Scoreboard")
	void UpdateScores(TArray<FString> Scores);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UTextBlock> TextBlockClass;
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVerticalBox>  ScoreList;

	
};
