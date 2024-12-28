// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstPersonGameMode.generated.h"

UCLASS(minimalapi)
class AFirstPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFirstPersonGameMode();

	void PrintScore();
protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};



