// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerUIMaster.h"

#include "CPP_InfoBarMaster.h"

UCPP_PlayerUIMaster::UCPP_PlayerUIMaster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

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

UResourceManager* UCPP_PlayerUIMaster::InitUI(UResourceManager* SetResourceManager)
{
	ResourceManager = SetResourceManager;

	return ResourceManager;
}

