// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsiderationManager.h"

#include "Considerations/DistanceConsideration.h"
#include "Considerations/EnergyConsideration.h"
#include "Considerations/HomeConsideration.h"
#include "Considerations/HungerConsideration.h"
#include "Considerations/LeaveConsideration.h"
#include "Considerations/ShopDesireConsideration.h"
#include "Considerations/SleepConsideration.h"
#include "Considerations/WorkConsideration.h"

bool UConsiderationManager::InitializeConsiderationManager()
{
	// Create the considerations
	HungerConsideration = NewObject<UHungerConsideration>(this, UHungerConsideration::StaticClass());
	EnergyConsideration = NewObject<UEnergyConsideration>(this, UEnergyConsideration::StaticClass());
	ShopDesireConsideration = NewObject<UShopDesireConsideration>(this, UShopDesireConsideration::StaticClass());
	DistanceConsideration = NewObject<UDistanceConsideration>(this, UDistanceConsideration::StaticClass());
	LeaveConsideration = NewObject<ULeaveConsideration>(this, ULeaveConsideration::StaticClass());
	SleepConsideration = NewObject<USleepConsideration>(this, USleepConsideration::StaticClass());
	WorkConsideration = NewObject<UWorkConsideration>(this, UWorkConsideration::StaticClass());
	HomeConsideration = NewObject<UHomeConsideration>(this, UHomeConsideration::StaticClass());

	// Add the considerations to the package
	Considerations.Add("Hunger", HungerConsideration);
	Considerations.Add("Energy", EnergyConsideration);
	Considerations.Add("ShopDesire", ShopDesireConsideration);
	Considerations.Add("Distance", DistanceConsideration);
	Considerations.Add("Leave", LeaveConsideration);
	Considerations.Add("Sleep", SleepConsideration);
	Considerations.Add("Work", WorkConsideration);
	Considerations.Add("Home", HomeConsideration);

	return true;

}

UConsiderationBase* UConsiderationManager::GetConsideration(const FString& ConsiderationName)
{
	if (Considerations.Contains(ConsiderationName))
	{
		return Considerations[ConsiderationName];
	}

	UE_LOG (LogTemp, Warning, TEXT("Consideration %s not found in ConsiderationManager"), *ConsiderationName);

	return nullptr;
	
}
