// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConsiderationBase.generated.h"

struct FDecisionContext;
/**
 *  Abstract base class for considerations that contribute to decision scoring.
 */
UCLASS(Abstract)
class AIMALLSIM_API UConsiderationBase : public UObject
{
	GENERATED_BODY()

public:
	virtual float Score(const FDecisionContext& Context) PURE_VIRTUAL(UConsiderationBase::Score, return 0.f;);
};
