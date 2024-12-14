// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonPlayerController.generated.h"

class AFirstPersonHUD;
class UInputMappingContext;

/**
 *
 */
class UScoreBoardWidget;
class UScoreWidget;
UCLASS()
class FIRSTPERSON_API AFirstPersonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputMappingContext>  InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void UpdateScore(int32 Score);

	//设置为RPC调用,否则在GameMode中调用时FirstPersonHUD为空
	UFUNCTION(Client, Reliable)
	void ShowAllPlayerScores(const TArray<FString>& Scores);
	
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UScoreBoardWidget> ScoreBoardWidgetClass;
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TObjectPtr<UScoreBoardWidget> ScoreBoardWidgetInstance;
	

private:
	void StartCountdown();
	
	void UpdateCountdown();
	
	FTimerHandle CountdownTimerHandle;
	
	float CountdownDuration;
	
	int32 RemainingTime;

	UPROPERTY()
	TObjectPtr<AFirstPersonHUD> FirstPersonHUD;
};
