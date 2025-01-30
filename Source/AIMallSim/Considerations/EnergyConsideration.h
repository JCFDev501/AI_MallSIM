// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Considerations/ConsiderationBase.h"
#include "EnergyConsideration.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UEnergyConsideration : public UConsiderationBase
{
	GENERATED_BODY()

	UPROPERTY()
	float UrgencyCoefficient = 3.4f;

public:
	virtual float Score(const FDecisionContext& Context) override;
	
};
