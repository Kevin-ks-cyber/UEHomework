// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataManager.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UDataManager : public UObject
{
	GENERATED_BODY()
public:
	UDataManager();
	//UFUNCTION(BlueprintCallable, Category = "Data Management")
	static TSharedPtr<FJsonObject> GetCachedJson(const FString& FilePath);

	UFUNCTION(BlueprintCallable, Category = "Data Management")
	static bool GetFloatFromJson(const FString& Key, float& OutValue,const FString& FilePath);

	UFUNCTION(BlueprintCallable, Category = "Data Management")
	static bool GetIntFromJson(const FString& Key, int32& OutValue,const FString& FilePath);

	UFUNCTION(BlueprintCallable, Category = "Data Management")
	static bool GetStringFromJson(const FString& Key, FString& OutValue,const FString& FilePath);

private:
	static TMap<FString, TSharedPtr<FJsonObject>> CachedJsonObjects;
};
