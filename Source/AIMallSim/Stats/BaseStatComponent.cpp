// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/BaseStatComponent.h"

#include "Patron.h"

// Sets default values for this component's properties
UBaseStatComponent::UBaseStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MinVal = 0.0f; // Default value 
	MaxVal = 0.0f; // Default value
	DecayRate = 0.0f; // Default value
	bIsDecayAble = false; // Default value
	DecayTime = 0.0f; // Default value
	TimeTillNextDecay = 0.0f; // Default value
	ValModifer = 0.0f; // Default value
	TraitsAccessed = false; // Default value`
}


// Called when the game starts
void UBaseStatComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentVal = MaxVal + ValModifer; // Default value
	OriginalDecayRate = DecayRate; // Default value

	PatronThatOwnsThisComponent = Cast<APatron>(GetOwner()); // Get the owner of the component
	
}


// Called every frame
void UBaseStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Decay(DeltaTime);
}

void UBaseStatComponent::IncreaseStatValue(float Value)
{
	CurrentVal += Value; // Increase the current value by the value
	if (CurrentVal > MaxVal) // Check if the current value is greater than the max value
	{
		CurrentVal = MaxVal; // Set the current value to the max value
	}
}

void UBaseStatComponent::Decay(float DeltaTime)
{
	if (bIsDecayAble) // Check if the stat is decayable
	{
		TimeTillNextDecay -= DeltaTime; // Decrease the time till next decay
		if (TimeTillNextDecay <= 0.0f) // Check if the time till next decay is less than or equal to 0
		{
			CurrentVal -= DecayRate; // Decrease the current value by the decay rate
			TimeTillNextDecay = DecayTime;
		}
	}
}
