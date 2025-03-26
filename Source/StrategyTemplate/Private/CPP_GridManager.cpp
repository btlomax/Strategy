// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "CPP_GridManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ACPP_GridManager::ACPP_GridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), Tag, TaggedActors);

	if (TaggedActors.Num() == 0)
		return;

	for (AActor* Actor : TaggedActors)
	{
		float distance = FVector::Dist(GetActorLocation(), Actor->GetActorLocation());

		if (distance < distanceToClosestBuilding)
		{
			distanceToClosestBuilding = distance;
			nearestBuilding = Actor;
		}
	}

	return nearestBuilding;
}

void ACPP_GridManager::RetreatToNearestSupplyBuilding(AActor* nearestBuilding)
{
	
}



