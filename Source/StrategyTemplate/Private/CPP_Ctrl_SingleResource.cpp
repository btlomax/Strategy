// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Ctrl_SingleResource.h"

#include "Components/TextBlock.h"

void UCPP_Ctrl_SingleResource::AssignResource(FResourceData resourceData)
{
	AssignedResourceData = resourceData;
}

void UCPP_Ctrl_SingleResource::SetName(FString nameText)
{
	name->SetText(FText::FromString(nameText));
}

void UCPP_Ctrl_SingleResource::SetAmount(FString amountText)
{
	amount->SetText(FText::FromString(amountText));
}

