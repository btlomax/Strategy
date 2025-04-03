// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UPROPERTY(meta = (BindWidget))
	class UBorder* LTBorder;

	UFUNCTION(BlueprintCallable)
	void ChangeColour();
	
};
