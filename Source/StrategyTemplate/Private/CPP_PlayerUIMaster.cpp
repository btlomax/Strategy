// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerUIMaster.h"

#include "CPP_InfoBarMaster.h"

UCPP_PlayerUIMaster::UCPP_PlayerUIMaster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

/// Essentially EventBeginPlay but for User Widgets. Otherwise known as EventConstruct in BP
void UCPP_PlayerUIMaster::NativeConstruct()
{
	Super::NativeConstruct();

	if (InfoBarClass && ResourceManager)
	{
		InfoBarRef = CreateWidget<UCPP_InfoBarMaster>(GetWorld(), InfoBarClass);
		if (InfoBarRef)
		{
			InfoBarRef->InfoBarResourceManager = ResourceManager;
			InfoBarRef->AddToViewport();
		}
	}
}

// This is called in the editor by BP_PlayerPawn as the resource manager and UI is attached to it.
// This way, the UI moves with the player as they move around the map.
UResourceManager* UCPP_PlayerUIMaster::InitUI(UResourceManager* SetResourceManager)
{
	ResourceManager = SetResourceManager;

	return ResourceManager;
}

