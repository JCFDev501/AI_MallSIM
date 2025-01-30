// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Considerations/ConsiderationBase.h"
#include "LeaveConsideration.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API ULeaveConsideration : public UConsiderationBase
{
	GENERATED_BODY()

	UPROPERTY()
	float HungerUrgencyCoefficient = 1.2f;

	UPROPERTY()
	float EnergyUrgencyCoefficient = 3.4f;

	UPROPERTY()
	float LeaveUrgency = 0.5f;

public:
	virtual float Score(const FDecisionContext& Context) override;
	
};
