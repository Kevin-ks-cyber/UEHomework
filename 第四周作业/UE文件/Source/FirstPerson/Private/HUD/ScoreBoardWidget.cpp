// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/ScoreBoardWidget.h"

#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UScoreBoardWidget::UpdateScores(TArray<FString> Scores)
{
	if (!ScoreList || !TextBlockClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ScoreList or TextBlockClass is not set."));
		return;
	}

	// 清空现有的子组件
	ScoreList->ClearChildren();

	// 添加新的分数文本块
	for (const FString& Score : Scores)
	{
		TObjectPtr<UTextBlock> TextBlock  = NewObject<UTextBlock>(this, TextBlockClass);
		if (TextBlock)
		{
			TextBlock->SetText(FText::FromString(Score));
			ScoreList->AddChildToVerticalBox(TextBlock);
		}
	}
}
