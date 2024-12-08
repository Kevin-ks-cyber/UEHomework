// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonTool/DataManager.h"

TMap<FString, TSharedPtr<FJsonObject>> UDataManager::CachedJsonObjects;

// Constructor
UDataManager::UDataManager()
{
}

TSharedPtr<FJsonObject> UDataManager::GetCachedJson(const FString& FilePath)
{
    if (CachedJsonObjects.Contains(FilePath))
    {
        return CachedJsonObjects[FilePath];
    }

    FString FileContent;
    if (FFileHelper::LoadFileToString(FileContent, *FilePath))
    {
        TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(FileContent);
        TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
        if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
        {
            CachedJsonObjects.Add(FilePath, JsonObject);
            return JsonObject;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("读取文件失败: %s"), *FilePath);
    return nullptr;
}

bool UDataManager::GetFloatFromJson(const FString& Key, float& OutValue,const FString& FilePath)
{
    GetCachedJson(FilePath);
    for (const auto& Entry : CachedJsonObjects)
    {
        if (Entry.Value->HasTypedField<EJson::Number>(Key))
        {
            OutValue = Entry.Value->GetNumberField(Key);
            return true;
        }
        else if (Entry.Value->HasTypedField<EJson::String>(Key))
        {
            FString StringValue = Entry.Value->GetStringField(Key);
            return LexTryParseString(OutValue, *StringValue);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Failed to get float value for key: %s"), *Key);
    return false;
}

bool UDataManager::GetIntFromJson(const FString& Key, int32& OutValue,const FString& FilePath)
{
    GetCachedJson(FilePath);
    for (const auto& Entry : CachedJsonObjects)
    {
        if (Entry.Value->HasTypedField<EJson::Number>(Key))
        {
            OutValue = Entry.Value->GetIntegerField(Key);
            return true;
        }
        else if (Entry.Value->HasTypedField<EJson::String>(Key))
        {
            FString StringValue = Entry.Value->GetStringField(Key);
            return LexTryParseString(OutValue, *StringValue);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Failed to get integer value for key: %s"), *Key);
    return false;
}

bool UDataManager::GetStringFromJson(const FString& Key, FString& OutValue,const FString& FilePath)
{
    GetCachedJson(FilePath);
    for (const auto& Entry : CachedJsonObjects)
    {
        if (Entry.Value->HasTypedField<EJson::String>(Key))
        {
            OutValue = Entry.Value->GetStringField(Key);
            return true;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Failed to get string value for key: %s"), *Key);
    return false;
}