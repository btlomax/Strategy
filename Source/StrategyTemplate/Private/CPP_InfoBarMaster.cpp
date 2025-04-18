// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InfoBarMaster.h"

#include "ResourceData.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Engine/TextureRenderTarget2D.h"

class UCPP_Ctrl_SingleResource;

UCPP_InfoBarMaster::UCPP_InfoBarMaster(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
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
	for (int i = 0; i < InfoBarResourceManager->Resources.Num(); i++)
	{
		SingleResourceRef = CreateWidget<UCPP_Ctrl_SingleResource>(GetWorld(),SingleResourceInstance);

		SingleResourceRef->AssignResource(InfoBarResourceManager->Resources[i]);

		ResourcesHolder->AddChild(SingleResourceRef);
	}
}
