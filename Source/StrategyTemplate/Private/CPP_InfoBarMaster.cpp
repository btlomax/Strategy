// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InfoBarMaster.h"

#include "ResourceData.h"

class UCPP_Ctrl_SingleResource;

UCPP_InfoBarMaster::UCPP_InfoBarMaster(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	GenerateResourceControls();
}


void UCPP_InfoBarMaster::NativeConstruct()
{
	Super::NativeConstruct();

	if (Slider)
	{
		ResourceSliderRef = CreateWidget<UCPP_Ctrl_ResourceSlider>(GetWorld(), Slider);

		if (ResourceSliderRef)
			ResourceSliderRef->AddToViewport();
	}	
}
	
void UCPP_InfoBarMaster::GenerateResourceControls()
{
	for (FResourceData resources : InfoBarResourceManager->Resources)
	{
		CreateWidget<UCPP_Ctrl_SingleResource>(GetWorld(),SingleResourceInstance)->AddToViewport();
	}
}
