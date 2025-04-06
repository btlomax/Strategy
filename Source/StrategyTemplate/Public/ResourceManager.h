// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResourceData.h"
#include "Components/ActorComponent.h"
#include "ResourceManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STRATEGYTEMPLATE_API UResourceManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UResourceManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	TArray<FResourceData> Resources;

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void AddResource(FName ResourceName, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	int32 GetResource(FName ResourceName) const;

private:
	void UpdateResourceProduction(float DeltaTime);
};
