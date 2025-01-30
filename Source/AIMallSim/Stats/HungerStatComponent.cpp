// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/HungerStatComponent.h"

#include "Patron.h"
#include "Util/PatronTraits.h"

void UHungerStatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHungerStatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!TraitsAccessed)
	{
		for (const ETraits Trait : PatronThatOwnsThisComponent->GetTraits())
		{
			if (Trait == ETraits::Traits_Gourmand)
			{
				DecayRate = DecayRate + 1.0;
			}
			else if (Trait == ETraits::Traits_HealthNut)
			{
				DecayRate = DecayRate - 1.0;
			}
		}
		TraitsAccessed = true;
	}
}
