// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/TasksNodes/BTT_SatisfyHunger.h"

#include "Patron.h"
#include "PatronAiController.h"
#include "Util/PatronSlot.h"
#include "Util/ScoredAction.h"

EBTNodeResult::Type UBTT_SatisfyHunger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
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

    // Update the patrons Hunger
    Patron->HungerStatComponent->IncreaseStatValue(Patron->HungerStatComponent->GetMaxVal());

    return EBTNodeResult::Succeeded;
}
