// Copyright Epic Games, Inc. All Rights Reserved.


#include "FirstPersonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "FirstPersonCharacter.h"
#include "Engine/LocalPlayer.h"
#include "JsonTool/DataManager.h"
#include "Kismet/KismetSystemLibrary.h"

void AFirstPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	FString FilePath = FPaths::ProjectDir() + TEXT("GameData.json");
	float GameTime;
	UDataManager::GetFloatFromJson(TEXT("GameTime"), GameTime,FilePath);
	CountdownDuration = GameTime;
	RemainingTime = FMath::TruncToInt(CountdownDuration);
	StartCountdown();
}

void AFirstPersonPlayerController::StartCountdown()
{
	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle,this,&AFirstPersonPlayerController::UpdateCountdown,1.0f, true );
}

void AFirstPersonPlayerController::UpdateCountdown()
{
	if (RemainingTime > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("剩余时间: %d"), RemainingTime);
		
		--RemainingTime;
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
		
		UE_LOG(LogTemp, Warning, TEXT("游戏结束"));
		AFirstPersonCharacter* FirstPersonCharacter = Cast<AFirstPersonCharacter>(GetCharacter());
		if (FirstPersonCharacter != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("分数: %d"), FirstPersonCharacter->GetScore());
		}
		UKismetSystemLibrary::QuitGame(this,nullptr,EQuitPreference::Quit,true);
	}
}