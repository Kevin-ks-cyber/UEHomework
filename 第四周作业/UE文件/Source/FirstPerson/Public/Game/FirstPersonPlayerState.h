// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FirstPersonPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSON_API AFirstPersonPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AFirstPersonPlayerState();

	// 获取分数
	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 GetPlayerScore() ;
	// 设置分数
	UFUNCTION(BlueprintCallable, Category = "Score")
	void SetPlayerScore(int32 NewScore);

	// 获取分数
	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetPlayerHealth() ;
	// 设置分数
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetPlayerHealth(float NewHealth);

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxPlayerHealth() ;

	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere)
	float MaxPlayerHealth;
private:
	// 当 Score 属性在客户端被更新时，这个函数会被调用
	UFUNCTION()
	void OnRep_PlayerScore() ;

	UFUNCTION()
	void OnRep_PlayerHealth() ;
	
	UPROPERTY(ReplicatedUsing=OnRep_PlayerScore)
	int32 PlayerScore;

	UPROPERTY(ReplicatedUsing=OnRep_PlayerHealth)
	float PlayerHealth;
	
	// 服务器 RPC 函数用于设置分数
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetScore(int32 NewScore);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetHealth(float NewHealth);
	
};

inline float AFirstPersonPlayerState::GetMaxPlayerHealth()
{
	return MaxPlayerHealth;
}
