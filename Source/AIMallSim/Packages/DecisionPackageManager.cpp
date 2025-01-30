// Fill out your copyright notice in the Description page of Project Settings.


#include "Packages/DecisionPackageManager.h"

#include "BaseDecisionPackage.h"
#include "DefaultDecisionPackage.h"
#include "HomeDecisionPackage.h"
#include "MallDecisionPackage.h"
#include "WorkDecisionPackage.h"

UDecisionPackageManager::UDecisionPackageManager()
{
	DefaultPackage = NewObject<UDefaultDecisionPackage>();
	DefaultPackage->PackageName = "DefaultPackage";
	Packages.Add(DefaultPackage->GetPackageName(), DefaultPackage);

	MallPackage = NewObject<UMallDecisionPackage>();
	MallPackage->PackageName = "MallPackage";
	Packages.Add(MallPackage->GetPackageName(), MallPackage);

	WorkPackage = NewObject<UWorkDecisionPackage>();
	WorkPackage->PackageName = "WorkPackage";
	Packages.Add(WorkPackage->GetPackageName(), WorkPackage);

	HomePackage = NewObject<UHomeDecisionPackage>();
	HomePackage->PackageName = "HomePackage";
	Packages.Add(HomePackage->GetPackageName(), HomePackage);

}

void UDecisionPackageManager::InitAllPackages(ADefaultGameMode* GameMode)
{
	// Initialize all packages
	for (const auto Package : Packages)
	{
		const bool succeeded = Package.Value->InitializeThisPackage(GameMode);

		if (!succeeded)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to initialize package %s"), *Package.Key);
		}
	}
}

UBaseDecisionPackage* UDecisionPackageManager::GetPackage(const FString& PackageName)
{
	if (Packages.Contains(PackageName))
	{
		return Packages[PackageName];
	}

	UE_LOG(LogTemp, Error, TEXT("Package %s not found in DecisionPackageManager"), *PackageName);

	return nullptr;
}
