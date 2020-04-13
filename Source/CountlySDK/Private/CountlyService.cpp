// Fill out your copyright notice in the Description page of Project Settings.


#include "CountlyService.h"

UCountlyService::UCountlyService(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	/*____________________________________________________________________________________________________________
	 *
	 * Initialize and set default values for all properties.
	 * _____________________________________________________________________________________________________________*/
	
	URL.Empty();
	AppKey.Empty();
	DeviceID.Empty();
}

bool UCountlyService::Initialize()
{
	bool result = false;
	
	if(!URL.IsEmpty() && !AppKey.IsEmpty() && !DeviceID.IsEmpty())
	{
		
	}

	return result;
}
