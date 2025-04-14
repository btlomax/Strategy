// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_PlayerUIMaster.generated.h"

/**
 * 
 */

class UCPP_InfoBarMaster;
class UResourceManager;

UCLASS()
class STRATEGYTEMPLATE_API UCPP_PlayerUIMaster : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCPP_PlayerUIMaster(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void InitUI(UResourceManager* SetResourceManager);
	
	// The class for the InfoBar (set in Blueprint)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UCPP_InfoBarMaster> InfoBarClass;

	// Set this before Construct or via Init
	UPROPERTY(BlueprintReadWrite, Category = "Resources")
	UResourceManager* ResourceManager;

	UPROPERTY(Meta = (BindWidget))
	class UCPP_Ctrl_ResourceSlider* ResourceSlider;

protected:
	// Keeping a reference to the spawned InfoBar
	UPROPERTY()
	UCPP_InfoBarMaster* InfoBarRef;	
};
