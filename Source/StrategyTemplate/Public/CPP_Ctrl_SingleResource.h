// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_Ctrl_SingleResource.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYTEMPLATE_API UCPP_Ctrl_SingleResource : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(Meta = (BindWidget))
	class UBorder* background;

	UPROPERTY(Meta = (BindWidget))
	class UTextBlock* name;

	UPROPERTY(Meta = (BindWidget))
	class UTextBlock* amount;

	UFUNCTION(BlueprintCallable)
	void ChangeText();
};
