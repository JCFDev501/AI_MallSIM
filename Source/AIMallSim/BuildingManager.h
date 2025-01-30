// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuildingManager.generated.h"

class AWorkObject;
class AHomeObject;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API UBuildingManager : public UObject
{
	GENERATED_BODY()

	// The list of homes
	UPROPERTY()
	TArray<AHomeObject*> Homes;

	// List of all WorkOBJ
	TArray<AWorkObject*> Jobs;

public:
	void GatherAllHomesAndWorkStations();

	// Get All homes
	TArray<AHomeObject*> GetHomes() { return Homes; }

	// Get All jobs
	TArray<AWorkObject*> GetJobs() { return Jobs; }
	
};
