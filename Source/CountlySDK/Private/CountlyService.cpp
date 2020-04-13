// Fill out your copyright notice in the Description page of Project Settings.


#include "CountlyService.h"

UCountlyService::UCountlyService()
{
	/*____________________________________________________________________________________________________________
	 *
	 * Initialize and set default values for all properties.
	 * _____________________________________________________________________________________________________________*/
	
	URL.Empty();
	AppKey.Empty();
	DeviceID.Empty();

	RequestLimit = 1000;														//Set the default RequestLimit to 1000
}

bool UCountlyService::Initialize()
{
	bool result = false;
	
	if (!URL.IsEmpty() && !AppKey.IsEmpty() && !DeviceID.IsEmpty())
	{
		result = true;
	}
	else result = false;

	return result;
}

UCountlyRequest* UCountlyService::NewRequest()
{
	UCountlyRequest* TempRequest = NewObject<UCountlyRequest>();

	TempRequest->AppKey = AppKey;
	TempRequest->DeviceID = DeviceID;
	TempRequest->URL = URL;
	
	return TempRequest;
}

bool UCountlyService::SendRequest(UCountlyRequest* Request)
{
	bool result = false;

	return result;
}

void UCountlyService::ChangeHttpMode(HttpModes NewHttpMode)
{
	HttpMode = NewHttpMode;
}

void UCountlyService::BeginPlay()
{
	Super::BeginPlay();

	// ...

}