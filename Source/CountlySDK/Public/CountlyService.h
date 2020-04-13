// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Queue.h"
#include "CoreMinimal.h"
#include "CountlyRequest.h"
#include "UObject/NoExportTypes.h"
#include "CountlyService.generated.h"

/**
 * 
 */
UCLASS()
class COUNTLYSDK_API UCountlyService : public UObject
{
	GENERATED_BODY()


public:

	UCountlyService(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY()
	FString URL;

	UPROPERTY()
	FString AppKey;

	UPROPERTY()
	FString DeviceID;

	UFUNCTION()
	bool Initialize();

private:
	TQueue<UCountlyRequest, EQueueMode::Mpsc> RequestQueue;		//We want this to be of type MPSC so we can use it easier with another thread. This to not bog down the game thread! 
};
