// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Considerations/ConsiderationBase.h"
#include "HungerConsideration.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UHungerConsideration : public UConsiderationBase
{
	GENERATED_BODY()

	UPROPERTY()
	float UrgencyCoefficient = 1.6f;

public:
	virtual float Score(const FDecisionContext& Context) override;
	
};
