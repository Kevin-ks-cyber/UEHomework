// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/FirstPersonPlayerState.h"

#include "Net/UnrealNetwork.h"

AFirstPersonPlayerState::AFirstPersonPlayerState()
{
	PlayerScore = 0;
}

int32 AFirstPersonPlayerState::GetPlayerScore() 
{
	return PlayerScore;
	
}

void AFirstPersonPlayerState::SetPlayerScore(int32 NewScore)
{
	PlayerScore = NewScore;
	//不设置服务器更新的话最终在GameMode中得到的分数为0
	Server_SetScore(NewScore);
}

void AFirstPersonPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// 注册 Score 属性为可复制属性
	DOREPLIFETIME(AFirstPersonPlayerState, PlayerScore);
}

void AFirstPersonPlayerState::OnRep_PlayerScore() 
{
	UE_LOG(LogTemp, Log, TEXT("Score updated to %d"), PlayerScore);
}

void AFirstPersonPlayerState::Server_SetScore_Implementation(int32 NewScore)
{
	if (HasAuthority())
	{
		// 只有服务器端可以设置新的分数
		PlayerScore = NewScore;
	}
}

bool AFirstPersonPlayerState::Server_SetScore_Validate(int32 NewScore)
{
	return true;
}
