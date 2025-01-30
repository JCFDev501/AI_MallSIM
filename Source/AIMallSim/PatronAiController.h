// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HomeStuff/HomeObject.h"
#include "Packages/BaseDecisionPackage.h"
#include "Util/ScoredAction.h"
#include "PatronAiController.generated.h"

class APatronSlot;
class AStoreBase;
class UDecision;
class APatron;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API APatronAiController : public AAIController
{
	GENERATED_BODY()

	// List of Decisions to make
	UPROPERTY()
	TArray<UDecision*> DecisionsList;

	// List of scored actions
	TArray<FScoredAction*> Actions;

	// List of decisionPackages in use
	UPROPERTY(VisibleAnywhere, Category = "Patron", meta = (AllowPrivateAccess = "true"))
	TArray<UBaseDecisionPackage*> DecisionPackagesInUse;

	// The current decision
	FScoredAction* RunningAction;

	// Timer to manage update intervals
	float TimeSinceLastUpdate = 0.0f;

	// Blackboard
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Black Board", meta = (AllowPrivateAccess = "true"))
	UBlackboardData* BlackBoardData;

	UPROPERTY()
	UBlackboardComponent* BlackboardComp;

	// Update interval in seconds
	UPROPERTY(EditAnywhere, Category = "TimeSplicing", meta = (AllowPrivateAccess = "true"))
	float UpdateInterval = 0.7f;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* ShoppingTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* EatingTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* RestingTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* LeavingTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* WanderTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* SleepTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* WorkTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior", meta = (AllowPrivateAccess = true))
	UBehaviorTree* YardTree;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:
	FScoredAction* GetRunningAction() const { return RunningAction; }

	// Current Patron Slot
	UPROPERTY(VisibleAnywhere, Category = "Patron")
	APatronSlot* CurrentSlotTargeted = nullptr;

	void GenerateDecisions(); // Generate the decisions for the patron
	TArray<UDecision*> CheckForUpdatedDecisions();
	void UpdateDecisionsBasedOffPatronScheduler();

	// Get Actions
	TArray<FScoredAction*> GetActions() const { return Actions; }

	// Get Packages in use
	TArray<UBaseDecisionPackage*> GetPackagesInUse() { return DecisionPackagesInUse; }

	UPROPERTY(VisibleAnywhere, Category = "Patron", meta = (AllowPrivateAccess = "true"))
	APatron* PatronControlling;


private:
	void FindBestAction(); // Find the best action to take

	TArray<AStoreBase*> GatherTargets(EStoreType StoreType) const; // Gather all the targets for a decision
	TArray<AHomeObject*> GatherTargetsForHomes(EStoreType StoreType) const; // Gather all the targets for a decision

	void RunAppropriateTree(FScoredAction* ActionToExecute); // Run the appropriate behavior tree
};
