// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CountlyRequest.generated.h"

/**
 * 
 */
UCLASS()
class COUNTLYSDK_API UCountlyRequest : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString URL;

	UPROPERTY()
	FString AppKey;

	UPROPERTY()
	FString DeviceID;

	UPROPERTY()
	FDateTime TimeStamp;
	
};
