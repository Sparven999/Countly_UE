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
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	UPROPERTY(BlueprintReadWrite)
	int RequestLimit;											//The number of requests we can have in the queue. If reached it will remove oldest requests first. Suggested/default amount = 1000
	
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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
