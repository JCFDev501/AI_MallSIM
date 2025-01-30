// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/ConsiderationPackage.h"

void UConsiderationPackage::InitializeConsiderationPackage()
{
	//
}

UConsiderationBase* UConsiderationPackage::GetConsiderationByName(const FString& ConsiderationName)
{
	return Considerations[ConsiderationName];
}
