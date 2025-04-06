// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ResourceManager.h"
#include "GS_ResourceManager.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYTEMPLATE_API AGS_ResourceManager : public AGameStateBase
{
	GENERATED_BODY()
public:

	AGS_ResourceManager();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	UResourceManager* resourceManager;
	
};
