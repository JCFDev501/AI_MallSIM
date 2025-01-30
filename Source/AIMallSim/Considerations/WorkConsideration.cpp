// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/WorkConsideration.h"

#include "Patron.h"
#include "Util/DecisionContext.h"


float UWorkConsideration::Score(const FDecisionContext& Context)
{
    const APatron* Patron = Cast<APatron>(Context.Actor);
    if (!Patron)
    {
        return 0.0f; // Context.Actor is not a Patron, return a default score
    }

    if (Patron->SchedulerComponent->GetCurrentScheduledActivity().Activity == EActivityType::AT_Work)
    {
        return 0.5f;  // Max utility if it's night
    }

    return 0.0f; // No utility if it's not night
}
