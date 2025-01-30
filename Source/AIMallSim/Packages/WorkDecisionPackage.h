// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Packages/BaseDecisionPackage.h"
#include "WorkDecisionPackage.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UWorkDecisionPackage : public UBaseDecisionPackage
{
	GENERATED_BODY()

	virtual bool InitializeThisPackage(ADefaultGameMode* GameMode) override;
	
};
