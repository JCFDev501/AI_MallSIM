// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DecisionPackageManager.generated.h"

class UWorkDecisionPackage;
class UHomeDecisionPackage;
class ADefaultGameMode;
class UMallDecisionPackage;
class UDefaultDecisionPackage;
class UBaseDecisionPackage;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API UDecisionPackageManager : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, UBaseDecisionPackage*> Packages; // The list of packages

	UPROPERTY()
	UDefaultDecisionPackage* DefaultPackage = nullptr; // The default package

	UPROPERTY()
	UMallDecisionPackage* MallPackage = nullptr; // The mall package

	UPROPERTY()
	UWorkDecisionPackage* WorkPackage = nullptr; // The mall package

	UPROPERTY()
	UHomeDecisionPackage* HomePackage = nullptr; // The mall package

public:
	UDecisionPackageManager(); // Constructor

	void InitAllPackages(ADefaultGameMode* GameMode); // Initializes all packages

	UBaseDecisionPackage* GetPackage(const FString& PackageName); // Returns the package with the given name


	
};
