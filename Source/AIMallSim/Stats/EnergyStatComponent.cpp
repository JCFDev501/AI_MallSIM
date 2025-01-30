// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/EnergyStatComponent.h"

#include "Patron.h"
#include "PatronManager.h"

void UEnergyStatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEnergyStatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (!TraitsAccessed)
	{
		for (const ETraits Trait : PatronThatOwnsThisComponent->GetTraits())
		{
			if (Trait == ETraits::Traits_Athletic || Trait == ETraits::Traits_Young)
			{
				OriginalDecayRate = DecayRate - 1.0;
			}
			else if (Trait == ETraits::Traits_OutOfShape || Trait == ETraits::Traits_Old)
			{
				OriginalDecayRate = DecayRate + 1.0;
			}
		}
		TraitsAccessed = true;
	}
	

	// Update the energy lost over time based on the population

	if (PatronThatOwnsThisComponent->GetPatronManager()->GetPopulation() < 25) // If the population is less than 25
		DecayRate = OriginalDecayRate * 1.0; // Decay rate is the same
	else if (PatronThatOwnsThisComponent->GetPatronManager()->GetPopulation() < 50) // If the population is less than 50
		DecayRate = OriginalDecayRate * 1.25; // Decay rate is increased by 25%
	else if (PatronThatOwnsThisComponent->GetPatronManager()->GetPopulation() < 75) // If the population is less than 75
		DecayRate = OriginalDecayRate * 1.50; // Decay rate is increased by 50%
	else if (PatronThatOwnsThisComponent->GetPatronManager()->GetPopulation() < 100) //	If the population is less than 100
		DecayRate = OriginalDecayRate * 1.75; // Decay rate is increased by 75%
	else
		DecayRate = OriginalDecayRate * 2.0; // Decay rate is doubled
	
}
