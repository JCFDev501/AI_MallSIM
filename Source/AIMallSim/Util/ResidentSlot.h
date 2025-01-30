// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "ResidentSlot.generated.h"

class APatron;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API AResidentSlot : public ATargetPoint
{
	GENERATED_BODY()

	UPROPERTY()
	APatron* ResidentAssignedToThisSlot; // The patron assigned to this slot

public:
	AResidentSlot();

	// Set the patron assigned to this slot
	void SetResident(APatron* NewResident) { ResidentAssignedToThisSlot = NewResident; }

	// Get Assigned patron
	APatron* GetAssignedPatron() const { return ResidentAssignedToThisSlot; }
	
};
