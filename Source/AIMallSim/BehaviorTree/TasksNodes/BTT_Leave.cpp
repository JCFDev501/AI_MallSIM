// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/TasksNodes/BTT_Leave.h"

#include "Patron.h"
#include "PatronAiController.h"
#include "Util/ScoredAction.h"

EBTNodeResult::Type UBTT_Leave::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const APatronAiController* PatronAiController = Cast<APatronAiController>(OwnerComp.GetAIOwner());
    if (!PatronAiController)
    {
        // If the cast fails, return failed
        return EBTNodeResult::Failed;
    }

    APatron* Patron = Cast<APatron>(PatronAiController->GetPawn());
    if (!Patron)
    {
        // If the cast fails, return failed
        return EBTNodeResult::Failed;
    }

    Patron->RemovePatron(); // Remove the patron from the bar

    return EBTNodeResult::Succeeded;
}
