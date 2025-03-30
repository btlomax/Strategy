// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "CPP_GridManager.h"

#include <string>

#include "AIController.h"
#include "AIHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACPP_GridManager::ACPP_GridManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TileSize = 100;
}

// Called when the game starts or when spawned
void ACPP_GridManager::BeginPlay()
{
	Super::BeginPlay();
	SingleTile.Empty();
}
}

// Called every frame
void ACPP_GridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/// <summary>
/// Find nearest supply building
/// </summary>
/// <param name="Tag"></param>
/// <returns></returns>
AActor* ACPP_GridManager::FindClosestSupplyBuilding(FName Tag)
{
	AActor* nearestBuilding = nullptr;
	float distanceToClosestBuilding = TNumericLimits<float>::Max();

	TArray<AActor*> taggedActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), Tag, taggedActors);

	if (taggedActors.Num() == 0)
		return nearestBuilding;

	for (AActor* actor : taggedActors)
	{
		float distance = FVector::Dist(GetActorLocation(), actor->GetActorLocation());

		if (distance < distanceToClosestBuilding)
		{
			distanceToClosestBuilding = distance;
			nearestBuilding = actor;
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, nearestBuilding->GetName());

	return nearestBuilding;
}

void ACPP_GridManager::RetreatToNearestSupplyBuilding(AActor* nearestBuilding, AActor* unitToMove)
{
	FVector location = nearestBuilding->GetActorLocation();
	FVector currentLocation = unitToMove->GetActorLocation();
	FVector newLocation(location.X, location.Y, currentLocation.Z);

	FString strLocation = newLocation.ToString();
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, strLocation);

	SetActorLocation(newLocation);
}

FVector ACPP_GridManager::CalculateGridKey(AActor* currentUnit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Made it to start of CalculateGridKey"));
	FVector currentLocation = currentUnit->GetActorLocation();

	float gridKeyX = UKismetMathLibrary::FFloor(currentLocation.X / getTileSize());
	float gridKeyY = UKismetMathLibrary::FFloor(currentLocation.Y / getTileSize());

	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Made it to end of CalculateGridKey"));
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FVector(gridKeyX, gridKeyY, currentLocation.Z).ToString());
	return FVector(gridKeyX, gridKeyY, currentLocation.Z);
}

void ACPP_GridManager::RegisterUnitInGrid(AActor* currentUnit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Made it to start of register unit in grid."));
	FVector unitGridKey = CalculateGridKey(currentUnit);
	

	if (SingleTile.Find(currentUnit) && currentUnit)
	{
		SingleTile.Add(currentUnit, unitGridKey);
		PrintTileContents(SingleTile);
	}
}

void ACPP_GridManager::PrintTileContents(TMap<AActor*, FVector> tile)
{
	TArray<AActor*> actors;
	TArray<FVector> locations;
	tile.GenerateKeyArray(actors);
	tile.GenerateValueArray(locations);

	for (int i = 0; i < actors.Num(); i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, actors[i]->GetName());
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, locations[i].ToString());
	}	
}

void ACPP_GridManager::UpdateUnitGridPosition(AActor* unit)
{
	if (unit-ActorHasTag("Unit"))
	{
		AActor* currentUnit = unit;
		TMap<AActor*, FVector> tile = getSingleTile();

		if (tile.Find(currentUnit))
		{
			tile.Remove(currentUnit);

			CalculateGridKey(currentUnit);

			tile.Add(currentUnit);
		}
	}
}






