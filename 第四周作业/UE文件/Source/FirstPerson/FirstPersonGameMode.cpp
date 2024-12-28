// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstPersonGameMode.h"
#include "FirstPersonCharacter.h"
#include "FirstPersonPlayerController.h"
#include "Game/FirstPersonPlayerState.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ConstructorHelpers.h"

AFirstPersonGameMode::AFirstPersonGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void AFirstPersonGameMode::PrintScore()
{
	TArray<FString> PlayerScores;
	int32 TotalScore = 0;
	int32 Index = 1;
	for (TObjectPtr<APlayerState> PlayerState : GameState->PlayerArray)
	{
		FString ScoreString = FString::Printf(TEXT("玩家%d分数为: %d"), Index, Cast<AFirstPersonPlayerState>(PlayerState)->GetPlayerScore());
		PlayerScores.Add(ScoreString);
		TotalScore+=Cast<AFirstPersonPlayerState>(PlayerState)->GetPlayerScore();
		Index++;
	}
	FString TotalScoreString = FString::Printf(TEXT("总分数为: %d"),TotalScore);
	PlayerScores.Add(TotalScoreString);
	
	int32 PCNum = UGameplayStatics::GetNumPlayerControllers(GetWorld());
	for(int32 PCIndex = 0; PCIndex < PCNum; ++PCIndex)
	{
		if(APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), PCIndex))
		{
			Cast<AFirstPersonPlayerController>(PlayerController)->ShowAllPlayerScores(PlayerScores);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Null Player Controller");
		}
	}
}

void AFirstPersonGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
}




