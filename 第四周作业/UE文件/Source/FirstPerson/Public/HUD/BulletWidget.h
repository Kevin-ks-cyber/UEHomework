// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BulletWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UBulletWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetBulletNumber(int32 NewBulletNumber);
protected:
	virtual bool Initialize() override;
	
private:
	int32 BulletNumber;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> BulletText;
};
