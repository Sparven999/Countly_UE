// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Queue.h"
#include "CoreMinimal.h"
#include "CountlyRequest.h"
#include "Components/ActorComponent.h"
#include "CountlyService.generated.h"

UENUM()
enum HttpModes
{
	HM_Auto		UMETA(DisplayName = "Auto"),
	HM_POSTOnly	UMETA(DisplayName = "Http Only")
};

/**
 * 
 */
UCLASS()
class COUNTLYSDK_API UCountlyService : public UActorComponent
{
	GENERATED_BODY()


public:

	UCountlyService();
	
	UPROPERTY()
	FString URL;

	UPROPERTY()
	FString AppKey;

	UPROPERTY()
	FString DeviceID;

	UFUNCTION()
	bool Initialize();

	UFUNCTION()
	UCountlyRequest* NewRequest();

	UFUNCTION()
	bool SendRequest(UCountlyRequest* Request);

	UFUNCTION()
	void ChangeHttpMode(HttpModes NewHttpMode);

private:

	TQueue<UCountlyRequest, EQueueMode::Mpsc> RequestQueue;		//We want this to be of type MPSC so we can use it easier with another thread. This to not bog down the game thread!

	UPROPERTY()
	TEnumAsByte<HttpModes> HttpMode;
};
