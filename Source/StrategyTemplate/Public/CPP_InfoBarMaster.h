// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Ctrl_ResourceSlider.h"
#include "CPP_Ctrl_SingleResource.h"
#include "ResourceManager.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "CPP_InfoBarMaster.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYTEMPLATE_API UCPP_InfoBarMaster : public UUserWidget
{
	GENERATED_BODY()
public:
	UCPP_InfoBarMaster(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	class UBorder* LTBorder;

	UPROPERTY(meta = (BindWidget))
	class UHorizontalBox* ResourcesHolder;

	UPROPERTY(BlueprintReadWrite, Category = "Resources", meta = (ExposeOnSerial = true))
	UResourceManager* InfoBarResourceManager;
	
	UFUNCTION(BlueprintCallable)
	void GenerateResourceControls();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UCPP_Ctrl_SingleResource> SingleResourceInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UCPP_Ctrl_ResourceSlider> Slider;

protected:
	
	UPROPERTY()
	UCPP_Ctrl_SingleResource* SingleResourceRef;

	UPROPERTY()
	UCPP_Ctrl_ResourceSlider* ResourceSliderRef;
};
