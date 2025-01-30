// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DefaultGameMode.h"
#include "Packages/BaseDecisionPackage.h"
#include "DefaultDecisionPackage.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UDefaultDecisionPackage : public UBaseDecisionPackage
{
	GENERATED_BODY()

public:
	virtual bool InitializeThisPackage(ADefaultGameMode* GameMode) override;
	
};
