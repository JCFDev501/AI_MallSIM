// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/TasksNodes/BTT_SatisfyEnergy.h"

#include "Patron.h"
#include "PatronAiController.h"

EBTNodeResult::Type UBTT_SatisfyEnergy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
    Patron->EnergyStatComponent->IncreaseStatValue(Patron->EnergyStatComponent->GetMaxVal());

    return EBTNodeResult::Succeeded;
}
