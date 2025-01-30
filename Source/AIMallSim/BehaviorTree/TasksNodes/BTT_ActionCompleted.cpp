// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/TasksNodes/BTT_ActionCompleted.h"

#include "Patron.h"
#include "PatronAiController.h"
#include "Util/PatronSlot.h"

EBTNodeResult::Type UBTT_ActionCompleted::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const APatronAiController* PatronAiController = Cast<APatronAiController>(OwnerComp.GetAIOwner());
    if (!PatronAiController)
    {
        // If the cast fails, return failed
        return EBTNodeResult::Failed;
    }

	const APatron* Patron = Cast<APatron>(PatronAiController->GetPawn());
    if (!Patron)
    {
        // If the cast fails, return failed
        return EBTNodeResult::Failed;
    }

    // Set the action to completed
	PatronAiController->GetRunningAction()->State = EActionState::AS_Completed;

	return EBTNodeResult::Succeeded;

}
