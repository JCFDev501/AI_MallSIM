// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/WalkingSpeedStatComponent.h"

#include "Patron.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWalkingSpeedStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set current value to a number between the min and max value
	CurrentVal = FMath::RandRange(MinVal, MaxVal);

	PatronThatOwnsThisComponent->GetCharacterMovement()->MaxWalkSpeed = CurrentVal + ValModifer;
}

void UWalkingSpeedStatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!TraitsAccessed)
	{
		// Check patron traits to see if they are a fast or slow walker
		for (const ETraits Trait : PatronThatOwnsThisComponent->GetTraits())
		{
			if (Trait == ETraits::Traits_FastWalker)
			{
				ValModifer = 50.f;
			}
			else if (Trait == ETraits::Traits_SlowWalker || Trait == ETraits::Traits_Old)
			{
				ValModifer = -50;
			}
		}

		TraitsAccessed = true;

		PatronThatOwnsThisComponent->GetCharacterMovement()->MaxWalkSpeed = CurrentVal + ValModifer;
		CurrentVal = PatronThatOwnsThisComponent->GetCharacterMovement()->MaxWalkSpeed;
	}
}
