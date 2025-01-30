// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/HungerConsideration.h"

#include "Patron.h"
#include "Util/DecisionContext.h"

float UHungerConsideration::Score(const FDecisionContext& Context)
{
    // If the actor is a patron, return a score based on the patron's hunger level
    const APatron* Patron = Cast<APatron>(Context.Actor);

    if (Patron)
    {
        // Normalize hunger. The closer the current hunger is to MinHunger, the higher the urgency (score).
        //const float NormalizedHunger = (Patron->GetCurrentHunger() - Patron->GetMinHunger()) / (Patron->GetMaxHunger() - Patron->GetMinHunger());

        const float NormalizedHunger = (Patron->HungerStatComponent->GetCurrentVal() - Patron->HungerStatComponent->GetMinVal()) / (Patron->HungerStatComponent->GetMaxVal() - Patron->HungerStatComponent->GetMinVal());

        // Invert the normalized value to increase the score as hunger increases.
        const float InvertedHunger = NormalizedHunger * -1;

        // Now use an exponential function for urgency, applying it to the inverted hunger.

        const float Score = exp(InvertedHunger * UrgencyCoefficient); // The score increases as the hunger increases

        return Score;
    }

    UE_LOG(LogTemp, Warning, TEXT("HungerConsideration: Actor is not a patron"));
    return 0.f;
}
