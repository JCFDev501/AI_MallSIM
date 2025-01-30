// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Considerations/ConsiderationBase.h"
#include "DistanceConsideration.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UDistanceConsideration : public UConsiderationBase
{
	GENERATED_BODY()

	// Maximum effective distance for full utility calculation
	UPROPERTY(VisibleAnywhere, Category = "Decision Making")
	float MaxDistance = 5000.0f;  // Default to 10000 Unreal units

public:
	virtual float Score(const FDecisionContext& Context) override;
	
};
