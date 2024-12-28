// Copyright Epic Games, Inc. All Rights Reserved.


#include "FirstPersonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "FirstPersonCharacter.h"
#include "FirstPersonGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "Game/FirstPersonPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "HUD/FirstPersonHUD.h"
#include "HUD/ScoreBoardWidget.h"
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

	FirstPersonHUD =  Cast<AFirstPersonHUD>(GetHUD());
	if (FirstPersonHUD!=nullptr)
	{
		FirstPersonHUD->CreateScoreWidget();
		FirstPersonHUD->CreateHealthWidget();
		FirstPersonHUD->UpdateHealthWidget(1.f);
	}
	float GameTime;
	UDataManager::GetFloatFromJson(TEXT("GameTime"), GameTime,FilePath);
	CountdownDuration = GameTime;
	RemainingTime = FMath::TruncToInt(CountdownDuration);
	StartCountdown();
}

void AFirstPersonPlayerController::UpdateScore(int32 Score)
{
	if (FirstPersonHUD!=nullptr)
	{
		
		FirstPersonHUD->UpdateScore(Cast<AFirstPersonPlayerState>(GetCharacter()->GetPlayerState())->GetPlayerScore());
	}
	
}

void AFirstPersonPlayerController::ShowAllPlayerScores_Implementation(const TArray<FString>& Scores)
{
	if (FirstPersonHUD!=nullptr)
	{
		FirstPersonHUD->CreateScoreBoardWidget();
		FirstPersonHUD->UpdateScoreList(Scores);
	}
}

/*void AFirstPersonPlayerController::ShowAllPlayerScores(TArray<FString> Scores)
{

	if (FirstPersonHUD!=nullptr)
	{
		FirstPersonHUD->CreateScoreBoardWidget();
		FirstPersonHUD->UpdateScoreList(Scores);
	}
	/*ScoreBoardWidgetInstance = CreateWidget<UScoreBoardWidget>(this,ScoreBoardWidgetClass);
	ScoreBoardWidgetInstance->AddToViewport();
	ScoreBoardWidgetInstance->UpdateScores(Scores);#1#
	
}*/

void AFirstPersonPlayerController::ShowBulletWidget(int32 BulletNumber)
{
	if (FirstPersonHUD!=nullptr)
	{
		FirstPersonHUD->CreateBulletWidget();
		FirstPersonHUD->UpdateBulletWidget(BulletNumber);
	}
	
}

void AFirstPersonPlayerController::UpdateBulletWidget(int32 BulletNumber)
{
	if (FirstPersonHUD!=nullptr)
	{
		FirstPersonHUD->UpdateBulletWidget(BulletNumber);
	}
}

void AFirstPersonPlayerController::ShowFrontSightWidget()
{
	FirstPersonHUD->CreateFrontSightWidget();
}

void AFirstPersonPlayerController::SetFrontSightRed()
{
	FirstPersonHUD->SetFrontSightRed();
}

void AFirstPersonPlayerController::SetFrontSightWhite()
{
	FirstPersonHUD->SetFrontSightWhite();
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

		GetPlayerState<AFirstPersonPlayerState>()->SetPlayerHealth(GetPlayerState<AFirstPersonPlayerState>()->GetPlayerHealth() - 3);
		FirstPersonHUD->UpdateHealthWidget(GetPlayerState<AFirstPersonPlayerState>()->GetPlayerHealth()/GetPlayerState<AFirstPersonPlayerState>()->GetMaxPlayerHealth());
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("游戏结束"));
		AFirstPersonGameMode* FirstPersonGameMode = Cast<AFirstPersonGameMode>(GetWorld()->GetAuthGameMode());
		if (FirstPersonGameMode)
		{
			FirstPersonGameMode->PrintScore();
		}
		
		AFirstPersonCharacter* FirstPersonCharacter = Cast<AFirstPersonCharacter>(GetCharacter());
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
		//UKismetSystemLibrary::QuitGame(this,nullptr,EQuitPreference::Quit,true);
	}
}