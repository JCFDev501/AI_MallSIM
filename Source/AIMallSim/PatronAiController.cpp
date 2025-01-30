// Fill out your copyright notice in the Description page of Project Settings.


#include "PatronAiController.h"

#include "DefaultGameMode.h"
#include "EngineUtils.h"
#include "Patron.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HomeStuff/ResidentBed.h"
#include "WorkStuff/WorkStation.h"
#include "Stores/StoreBase.h"
#include "Util/PatronSlot.h"
#include "Util/UDecision.h"

void APatronAiController::BeginPlay()
{
	Super::BeginPlay();

	RunningAction = new FScoredAction(); // Todo : Make sure this is deleted

	//Get BlackboardComponent
	BlackboardComp = GetBlackboardComponent();

	// Initialize the Blackboard
	UseBlackboard(BlackBoardData, BlackboardComp);

}

void APatronAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update the time since the last update
	TimeSinceLastUpdate += DeltaTime;

	// Check if it is time to update
	if (TimeSinceLastUpdate >= UpdateInterval)
	{
		FindBestAction(); // Find the best action to take

		TimeSinceLastUpdate = 0.0f; // Reset the time since last update
	}
}

void APatronAiController::FindBestAction()
{
	// Check if the current action is still running
	if (RunningAction->State == EActionState::AS_Running) 
		return;

	APatron* Patron = Cast<APatron>(GetPawn());

	// Clear the actions list
	Actions.Empty();

	// Get Ai Controller
	//const APatronAiController* PatronAiController = Cast<APatronAiController>(Patron->GetController());

	// Reset the slot state
	if (CurrentSlotTargeted)
		CurrentSlotTargeted->SetSlotState(ESlotState::SS_Empty);

	// Create a new decision context
	FDecisionContext Context;
	Context.Actor = Patron;

	// List of scored actions
	TArray<FScoredAction*> ScoredActions;

	

	// Go through each decision and score it
	for (UDecision* Decision : CheckForUpdatedDecisions())
	{
		// Get the targets for the decision
		TArray<AStoreBase*> Targets = GatherTargets(Decision->GetActionDef().StoreType);
		TArray<AHomeObject*> HomeTargets = GatherTargetsForHomes(Decision->GetActionDef().StoreType);

		// Ran Out Of Time?!?!?!?!?!?!?!?
		if (Decision->GetActionDef().ActionName == "Sleeping")
		{
			Context.Target = PatronControlling->GetThisPatronsBed();
			FScoredAction* ScoredAction = Decision->Score(Context); // Score the decision

			// Add the scored action to the list if it has a positive score
			if (ScoredAction->Score > 0)
				ScoredActions.Add(ScoredAction);
		}
		else if(Decision->GetActionDef().ActionName == "Working")
		{
			Context.Target = PatronControlling->GetThisPatronsWorkStation();
			FScoredAction* ScoredAction = Decision->Score(Context); // Score the decision

			// Add the scored action to the list if it has a positive score
			if (ScoredAction->Score > 0)
				ScoredActions.Add(ScoredAction);
		}

		// Go through each target and score the decision
		for (AStoreBase* Target : Targets)
		{
			Context.Target = Target; // Set the target of the context
			FScoredAction* ScoredAction = Decision->Score(Context); // Score the decision

			// Add the scored action to the list if it has a positive score
			if (ScoredAction->Score > 0)
				ScoredActions.Add(ScoredAction);
		}

	}

	if (ScoredActions.Num() > 0)
	{
		// Sort the scored actions
		ScoredActions.Sort([](const FScoredAction& A, const FScoredAction& B)
		{
			return A.Score > B.Score;
		});

		// Get the best action
		RunningAction = ScoredActions[0];
		Actions = ScoredActions;
		RunAppropriateTree(RunningAction);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PatronAiController: No actions scored"));
	}
}

TArray<AStoreBase*> APatronAiController::GatherTargets(EStoreType StoreType) const
{
    TArray<AStoreBase*> Targets;

	// Get all the stores in the world
    for (TActorIterator<AStoreBase> It(GetWorld()); It; ++It)
    {
		if (It->GetStoreType() == StoreType || It->GetActionType() == StoreType)
			Targets.Add(*It);
    }

    return Targets;
}

TArray<AHomeObject*> APatronAiController::GatherTargetsForHomes(EStoreType StoreType) const
{
	TArray<AHomeObject*> Targets;

	// Get all the stores in the world
	for (TActorIterator<AHomeObject> It(GetWorld()); It; ++It)
	{
		if (It->GetStoreType() == StoreType || It->GetActionType() == StoreType)
			Targets.Add(*It);
	}

	return Targets;
}

// Todo: Refractor this
void APatronAiController::GenerateDecisions()
{
	// Get Game Mode and cast to Default Game Mode
	ADefaultGameMode* GameMode = Cast<ADefaultGameMode>(GetWorld()->GetAuthGameMode());

	DecisionPackagesInUse.Add(GameMode->GetDecisionPackageManager()->GetPackage("DefaultPackage")); // DefaultPackage
	DecisionPackagesInUse.Add(GameMode->GetDecisionPackageManager()->GetPackage("MallPackage"));
	DecisionPackagesInUse.Add(GameMode->GetDecisionPackageManager()->GetPackage("WorkPackage"));
	DecisionPackagesInUse.Add(GameMode->GetDecisionPackageManager()->GetPackage("HomePackage"));

}

TArray<UDecision*> APatronAiController::CheckForUpdatedDecisions()
{
	UpdateDecisionsBasedOffPatronScheduler();

	
	// Clear the current DecisionsList
	DecisionsList.Empty();

	// Iterate over the current packages and add decisions from the ones that are not suppressed
	for (UBaseDecisionPackage* Package : DecisionPackagesInUse)
	{
		if (!Package->GetIsPackageSuppressed())
		{
			for (UDecision* Decision : Package->GetDecisionsInPackage())
			{
				DecisionsList.Add(Decision);
			}
		}
	}

	return DecisionsList;
	

	
}

void APatronAiController::UpdateDecisionsBasedOffPatronScheduler()
{
	// Update the packages based on the current activity
	const EActivityType CurrentActivity = PatronControlling->SchedulerComponent->GetCurrentScheduledActivity().Activity;

	for (UBaseDecisionPackage* Package : DecisionPackagesInUse)
	{
		if (CurrentActivity == EActivityType::AT_Home)
		{
			if (Package->PackageName == "HomePackage")
				Package->SuppressPackage(false);
			else if (Package->PackageName == "MallPackage" || Package->PackageName == "WorkPackage")
				Package->SuppressPackage(true);
		}
		else if (CurrentActivity == EActivityType::AT_Work)
		{
			if (Package->PackageName == "WorkPackage")
				Package->SuppressPackage(false);
			else if (Package->PackageName == "MallPackage" || Package->PackageName == "HomePackage")
				Package->SuppressPackage(true);
		}
		else if (CurrentActivity == EActivityType::AT_Mall)
		{
			if (Package->PackageName == "MallPackage")
				Package->SuppressPackage(false);
			else if (Package->PackageName == "WorkPackage" || Package->PackageName == "HomePackage")
				Package->SuppressPackage(true);
		}
	}
}


void APatronAiController::RunAppropriateTree(FScoredAction* ActionToExecute)
{
	// Update the ActionToExecute State
	ActionToExecute->State = EActionState::AS_Running;

	// Set the target
	BlackboardComp->SetValueAsObject("Target", ActionToExecute->Target);

	// Cast the target to a store
	AStoreBase* TargetStore = Cast<AStoreBase>(ActionToExecute->Target);


	if (TargetStore)
	{
		// Check to see if any slots are available
		if (TargetStore->IsAtFullCapacity())
		{
			BlackboardComp->SetValueAsObject("PatronSlot", nullptr);
		}
		else
		{
			// Grab the first available slot
			BlackboardComp->SetValueAsObject("PatronSlot", TargetStore->GetNextAvailableSlot());
		}

		// Set Patron Slot Targeted
		CurrentSlotTargeted = Cast<APatronSlot>(BlackboardComp->GetValueAsObject("PatronSlot"));
	}
	

	// Run a behavior tree

	if (ActionToExecute->ActionDef.ActionName == "Shopping" && CurrentSlotTargeted )
	{
		// Run the shopping tree
		RunBehaviorTree(ShoppingTree);

		APatron* Patron = Cast<APatron>(GetPawn());

		Patron->UpdateCurrentInterest();
	}
	else if (ActionToExecute->ActionDef.ActionName == "Eating" && CurrentSlotTargeted)
	{
		// Run the eating tree
		RunBehaviorTree(EatingTree);
	}
	else if (ActionToExecute->ActionDef.ActionName == "Resting" && CurrentSlotTargeted)
	{
		// Run the resting tree
		RunBehaviorTree(RestingTree);
	}
	else if (ActionToExecute->ActionDef.ActionName == "Leaving")
	{
		// Run the Leaving tree
		RunBehaviorTree(LeavingTree);
	}
	else if (ActionToExecute->ActionDef.ActionName == "Sleeping")
	{
		BlackboardComp->SetValueAsObject("ResidentSlot", PatronControlling->GetThisPatronsBed()->GetResidentSlot());

		// Run the Leaving tree
		RunBehaviorTree(SleepTree);
	}
	else if (ActionToExecute->ActionDef.ActionName == "Working")
	{
		BlackboardComp->SetValueAsObject("ResidentSlot", PatronControlling->GetThisPatronsWorkStation()->GetResidentSlot());

		// Run the Leaving tree
		RunBehaviorTree(WorkTree);
	}
	else
	{
		// Run the wander tree
		RunBehaviorTree(WanderTree);
	}


}

