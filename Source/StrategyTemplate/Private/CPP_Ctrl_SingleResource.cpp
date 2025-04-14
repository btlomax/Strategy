// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Ctrl_SingleResource.h"

#include "Components/TextBlock.h"

void UCPP_Ctrl_SingleResource::AssignResource(FResourceData resourceData)
{
	AssignedResourceData = resourceData;
	
	SetName(FText::FromName(resourceData.Name));
	SetAmount(FText::AsNumber(resourceData.Amount));
}

void UCPP_Ctrl_SingleResource::SetName(FText nameText)
{
	name->SetText(nameText);
}

void UCPP_Ctrl_SingleResource::SetAmount(FText amountText)
{
	amount->SetText(amountText);
}

