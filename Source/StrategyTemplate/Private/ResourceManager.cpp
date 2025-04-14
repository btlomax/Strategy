// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManager.h"

// Sets default values for this component's properties
UResourceManager::UResourceManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UResourceManager::BeginPlay()
{
	Super::BeginPlay();

	Resources.Empty();
}


// Called every frame
void UResourceManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UResourceManager::AddResource(FName ResourceName, int32 Amount)
{
	for (FResourceData& Resource : Resources)
	{
		if (Resource.Name == ResourceName)
		{
			Resource.Amount += Amount;
			return;
		}
	}

	FResourceData NewResource;
	NewResource.Name = ResourceName;
	NewResource.Amount = Amount;
	Resources.Add(NewResource);
}

int32 UResourceManager::GetResource(FName ResourceName) const
{
	for (const FResourceData& Resource : Resources)
	{
		if (Resource.Name == ResourceName)
		{
			return Resource.Amount;
		}	
	}

	return 0;
}

void UResourceManager::UpdateResourceProduction(float DeltaTime)
{
	for (FResourceData& Resource : Resources)
	{
		Resource.Amount += FMath::RoundToInt(DeltaTime * Resource.productionRate);
	}
}

void UResourceManager::GetDataTable()
{
	FSoftObjectPath TablePath(TEXT("/Script/Engine.DataTable'/Game/TopDown/Blueprints/DT_Resources.DT_Resources'"));
	UDataTable* ResourceTable = Cast<UDataTable>(TablePath.TryLoad());

	if (ResourceTable)
	{
		static const FString Context(TEXT("Resources"));
		TArray<FName>RowNames = ResourceTable->GetRowNames();

		for (FName RowName : RowNames)
		{
			FResourceData* Row = ResourceTable->FindRow<FResourceData>(RowName, Context);

			if (Row)
			{
				UE_LOG(LogTemp, Display, TEXT("%s"), *Row->Name.ToString());

				if (!Resources.Contains(*Row))
					Resources.Add(*Row);
				//UE_LOG(LogTemp, Display, TEXT("%s"), Row->Amount);
			}	
		}	
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("%s"), TEXT("Failed to load resource data"));
	}
}

