// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/LeaveConsideration.h"

#include "Patron.h"
#include "Util/DecisionContext.h"

float ULeaveConsideration::Score(const FDecisionContext& Context)
{
    // If the actor is a patron, return a score based on the patron's hunger level
    const APatron* Patron = Cast<APatron>(Context.Actor);

    if (Patron)
    {
        // Normalize hunger. The closer the current hunger is to MinHunger, the higher the urgency (score).
        const float NormalizedHunger = (Patron->HungerStatComponent->GetCurrentVal() - Patron->HungerStatComponent->GetMinVal()) / (Patron->HungerStatComponent->GetMaxVal() - Patron->HungerStatComponent->GetMinVal());

    	// Normalize energy. The closer the current energy is to MinEnergy, the higher the urgency (score).
        const float NormalizedEnergy = (Patron->EnergyStatComponent->GetCurrentVal() - Patron->EnergyStatComponent->GetMinVal()) / (Patron->EnergyStatComponent->GetMaxVal() - Patron->EnergyStatComponent->GetMinVal());

        // Invert the normalized value to increase the score as hunger increases.
        const float InvertedHunger = NormalizedHunger * -1;

        // Now use an exponential function for urgency, applying it to the inverted hunger.
        const float HungerScore = exp(InvertedHunger * HungerUrgencyCoefficient); // The score increases as the hunger increases

        // Invert the normalized value to increase the score as energy decreases.
        const float EnergyScore = exp(-NormalizedEnergy * EnergyUrgencyCoefficient); // Energy is more critical as it lowers

        // Combine the scores
        const float Score = HungerScore + EnergyScore - LeaveUrgency;

        return Score;
    }


	return 0.0f;
}
