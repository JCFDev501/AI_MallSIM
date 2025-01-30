// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConsiderationBase.h"
#include "UObject/NoExportTypes.h"
#include "ConsiderationPackage.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UConsiderationPackage : public UObject
{
	GENERATED_BODY()

protected:
	// This is the list of considerations that will be used to calculate the utility of the action
	UPROPERTY()
	TMap<FString, UConsiderationBase*> Considerations;

public:

	UConsiderationPackage() = default;

	// Initialize the considerations
	virtual void InitializeConsiderationPackage();

	// Get ConsiderationByName
	UConsiderationBase* GetConsiderationByName(const FString& ConsiderationName);

	
};
