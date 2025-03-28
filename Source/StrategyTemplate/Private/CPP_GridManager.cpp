// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "CPP_GridManager.h"

#include "AIController.h"
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

void ACPP_GridManager::RetreatToNearestSupplyBuilding(AActor* nearestBuilding)
{
	FVector location = nearestBuilding->GetActorLocation();
	FVector currentLocation = GetActorLocation();
	FVector newLocation(location.X, location.Y, currentLocation.Z);

	FString strLocation = newLocation.ToString();
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, strLocation);

	SetActorLocation(newLocation);
}

FVector ACPP_GridManager::CalculateGridKey(AActor* currentUnit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Made it to start of CalculateGridKey"));
	FVector currentLocation = currentUnit->GetActorLocation();
	
	float gridKeyX = UKismetMathLibrary::FFloor(currentLocation.X / TileSize);
	float gridKeyY = UKismetMathLibrary::FFloor(currentLocation.Y / TileSize);

	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Made it to end of CalculateGridKey"));
	return FVector(gridKeyX, gridKeyY, currentLocation.Z);
}

void ACPP_GridManager::RegisterUnitInGrid(AActor* currentUnit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Made it to start of register unit in grid."));
	AActor* unit = currentUnit;
	FVector unitGridKey = CalculateGridKey(currentUnit);

	if (!SingleTile.Find(currentUnit) && currentUnit)
	{
		SingleTile.Add(currentUnit, unitGridKey);
	}	
}




