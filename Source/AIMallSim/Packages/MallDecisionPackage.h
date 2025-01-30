// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Packages/BaseDecisionPackage.h"
#include "MallDecisionPackage.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UMallDecisionPackage : public UBaseDecisionPackage
{
	GENERATED_BODY()


public:
	virtual bool InitializeThisPackage(ADefaultGameMode* GameMode) override;
	
};
