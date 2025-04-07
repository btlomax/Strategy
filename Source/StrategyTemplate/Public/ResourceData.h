// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResourceData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct STRATEGYTEMPLATE_API FResourceData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float productionRate;

	FResourceData()
		: Name(NAME_None), Amount(0), productionRate(0.f)
	{}

	FResourceData(FName InName, int32 InAmount, float ProductionRate)
		: Name(InName), Amount(InAmount), productionRate(ProductionRate)
	{}
};
