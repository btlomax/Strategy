// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_PlayerUIMaster.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYTEMPLATE_API UCPP_PlayerUIMaster : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Meta = (BindWidget))
	class UCPP_InfoBarMaster* InfoBar;

	UPROPERTY(Meta = (BindWidget))
	class UCPP_Ctrl_ResourceSlider* ResourceSlider;
	
};
