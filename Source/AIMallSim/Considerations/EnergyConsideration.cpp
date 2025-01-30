// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/EnergyConsideration.h"

#include "Patron.h"
#include "Util/DecisionContext.h"

float UEnergyConsideration::Score(const FDecisionContext& Context)
{
	// If the actor is a patron, return a score based on the patron's hunger level
	const APatron* Patron = Cast<APatron>(Context.Actor);

	if (Patron)
	{
		const float NormalizedEnergy = (Patron->EnergyStatComponent->GetCurrentVal() - Patron->EnergyStatComponent->GetMinVal()) / (Patron->EnergyStatComponent->GetMaxVal() - Patron->EnergyStatComponent->GetMinVal());

		const float Score = exp(-NormalizedEnergy * UrgencyCoefficient); // Energy is more critical as it lowers

		return Score;
	}

	// If the actor is not a patron, return a neutral score
	UE_LOG(LogTemp, Warning, TEXT("EnergyConsideration: Actor is not a patron"));

	return 0.f;
}
