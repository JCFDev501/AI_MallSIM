// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionDefinition.h"
#include "DecisionContext.h"
#include "ScoredAction.h"

#include "UDecision.Generated.h"

class UPackageManager;
class UEnergyConsideration;
class UHungerConsideration;
class UConsiderationBase;
/**
 * 
 */

// Todo: Make a Package Manager for decisions instead of using the Consideration Package Manager
// Todo: Refactor the Decision
UCLASS()
class AIMALLSIM_API UDecision : public UObject
{
	GENERATED_BODY()

	// What action to take
	FActionDefinition ActionDef;

	// Reference to the Consideration package Manager
	//UPROPERTY()
	//UPackageManager* PackageManager = nullptr;

	// List of Considerations Names
	//TArray<FString> ConsiderationNames;

	TArray<UConsiderationBase*> Considerations;


public:
	UDecision() = default;

	FScoredAction* Score(const FDecisionContext& Context);

	// Get Action Definition
	FActionDefinition& GetActionDef() { return ActionDef; }

	void AddConsideration(UConsiderationBase* consideration);

private:
	static float CombineScores(const TArray<float>& Scores);
};
