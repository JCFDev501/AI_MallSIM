// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConsiderationManager.generated.h"

class UHomeConsideration;
class UWorkConsideration;
class USleepConsideration;
class UHungerConsideration;
class UEnergyConsideration;
class UDistanceConsideration;
class UShopDesireConsideration;
class ULeaveConsideration;
class UConsiderationBase;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API UConsiderationManager : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString ,UConsiderationBase*> Considerations; // The list of considerations in the manager

	// Considerations
	UPROPERTY()
	UHungerConsideration* HungerConsideration = nullptr;

	UPROPERTY()
	UEnergyConsideration* EnergyConsideration = nullptr;

	UPROPERTY()
	UDistanceConsideration* DistanceConsideration = nullptr;

	UPROPERTY()
	UShopDesireConsideration* ShopDesireConsideration = nullptr;

	UPROPERTY()
	ULeaveConsideration* LeaveConsideration = nullptr;

	UPROPERTY()
	USleepConsideration* SleepConsideration = nullptr;

	UPROPERTY()
	UWorkConsideration* WorkConsideration = nullptr;

	UPROPERTY()
	UHomeConsideration* HomeConsideration = nullptr;

public:
	bool InitializeConsiderationManager(); // Initializes the manager and if it was successful returns true

	UConsiderationBase* GetConsideration(const FString& ConsiderationName); // Returns the consideration with the given name
	
};
