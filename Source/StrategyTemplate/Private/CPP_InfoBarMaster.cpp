// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InfoBarMaster.h"

class UCPP_Ctrl_SingleResource;

void UCPP_InfoBarMaster::ChangeColour()
{
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, "Changing colour");
}
