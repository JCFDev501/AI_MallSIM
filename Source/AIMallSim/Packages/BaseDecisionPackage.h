// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseDecisionPackage.generated.h"

class ADefaultGameMode;
class UDecisionPackageManager;
class UDecision;
/**
 *  This class is the base class for all decision packages. A decision package is a collection of decisions that are used to make a decision.
 */
UCLASS()
class AIMALLSIM_API UBaseDecisionPackage : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSuppressed = false;

protected:
	UPROPERTY()
	TArray<UDecision*> DecisionsInPackages; // The list of decisions in the package

public:
	FString PackageName = "N/A";

	virtual bool InitializeThisPackage(ADefaultGameMode* GameMode) PURE_VIRTUAL(UBaseDecisionPackage::InitializeThisPackage, return true;); // Initializes the package and if it was successful returns true

	TArray<UDecision*> GetDecisionsInPackage() { return DecisionsInPackages; } // Returns the decisions in the package

	FString GetPackageName() { return PackageName; }

	void SuppressPackage(bool bIsThisPackageSuppressed);

	bool GetIsPackageSuppressed() const { return bSuppressed; }

};
