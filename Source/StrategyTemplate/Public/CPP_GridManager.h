// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_GridManager.generated.h"

UCLASS()
class STRATEGYTEMPLATE_API ACPP_GridManager : public AActor
{
	GENERATED_BODY()

private:
	 double TileSize;

public:
	 double getTileSize()
	{
		return TileSize;	
	}

	 void setTile(double value)
	{
		TileSize = value;
	}

public:
	TMap<AActor*, FVector> SingleTile;

public:
	UFUNCTION(BlueprintCallable)
	TMap<AActor*, FVector> getSingleTile()
	{
		return SingleTile;
	}

public:
	UFUNCTION(BlueprintCallable)
	void UpdateUnitGridPosition(AActor* unit);
	
	
public:	
	// Sets default values for this actor's properties
	ACPP_GridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	AActor* FindClosestSupplyBuilding(FName Tag);

public:
	UFUNCTION(BlueprintCallable)
	void PrintTileContents(TMap<AActor*, FVector> tile);

public:
	UFUNCTION(BlueprintCallable)
	void RetreatToNearestSupplyBuilding(AActor* nearestBuilding, AActor* unitToMove);
	
public:
	UFUNCTION(BlueprintCallable)
	FVector CalculateGridKey(AActor* currentUnit);

public:
	UFUNCTION(BlueprintCallable)
	void RegisterUnitInGrid(AActor* currentUnit);
};

