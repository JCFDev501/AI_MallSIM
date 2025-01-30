// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/TasksNodes/BTT_ChangeInterest.h"

#include "Patron.h"
#include "PatronAiController.h"
#include "Util/ChangeInterestMemory.h"
#include "Util/PatronSlot.h"
#include "Util/ScoredAction.h"

EBTNodeResult::Type UBTT_ChangeInterest::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    FChangeInterestMemory* Memory = reinterpret_cast<FChangeInterestMemory*>(NodeMemory);

    // Check if this task has already been executed
    if (Memory->bHasExecuted)
    {
        return EBTNodeResult::Succeeded;
    }

    APatronAiController* PatronAiController = Cast<APatronAiController>(OwnerComp.GetAIOwner());
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

    // Update the patrons interests
    Patron->UpdateCurrentInterest();

    // Mark this task as executed
    Memory->bHasExecuted = true;

    return EBTNodeResult::Succeeded;
}

uint16 UBTT_ChangeInterest::GetInstanceMemorySize() const
{
    return sizeof(FChangeInterestMemory);
}
