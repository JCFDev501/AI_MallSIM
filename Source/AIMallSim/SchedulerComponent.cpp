// Fill out your copyright notice in the Description page of Project Settings.


#include "SchedulerComponent.h"

#include "DefaultGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USchedulerComponent::USchedulerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

    MaxIndex = 27;
    CurrentIndex = 0;
    LastUpdatedMinute = -1;

    FirstTimeInterval = true;
}


// Called when the game starts
void USchedulerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
    GenerateSchedule();

    AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());

    if (GameMode)
    {
        if (const ADefaultGameMode* DefaultGameMode = Cast<ADefaultGameMode>(GameMode))
        {
            DayNightCycle = DefaultGameMode->GetDayNightCycle();
        }
    }

    // Calculate the modifier based on the current day of the week
	const int32 IndexDayModifier = static_cast<int32>(DayNightCycle->GetCurrentDayOfTheWeek()) * 4;

    // Calculate the modifier based on the current time of day
    int32 IndexTimeOfDayModifier = 0;
    switch (DayNightCycle->GetCurrentTimeOfDay())
    {
    case ETimeOfDay::Afternoon:
        IndexTimeOfDayModifier = 1;
        break;
    case ETimeOfDay::Evening:
        IndexTimeOfDayModifier = 2;
        break;
    case ETimeOfDay::Night:
        IndexTimeOfDayModifier = 3;
        break;
    default:
        break;
    }

    // Calculate the current index
    CurrentIndex = IndexDayModifier + IndexTimeOfDayModifier;

    
}


// Called every frame
void USchedulerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    CurrentScheduledActivity = ScheduledActivities[CurrentIndex];

    int32 CurrentMinute = DayNightCycle->GetCurrentMinute();

    // Check if it's the start of a new 4-minute interval and the update has not been performed yet
    if (CurrentMinute % 4 == 0 && CurrentMinute != LastUpdatedMinute)
    {
        UpdateSchedule();
        LastUpdatedMinute = CurrentMinute;
    }
}

void USchedulerComponent::GenerateSchedule()
{
    // Clear the current schedule
    ScheduledActivities.Empty();

    // Generate a random schedule for each day of the week
    for (int32 i = 0; i < 7; i++)
    {
        // Generate a random activity for each time of day
        for (int32 j = 0; j < 4; j++)
        {
            FScheduledActivity NewScheduledActivity;
            NewScheduledActivity.DayOfTheWeek = static_cast<EMyDayOfWeek>(i);
            NewScheduledActivity.TimeOfDay = static_cast<ETimeOfDay>(j);
            NewScheduledActivity.Activity = static_cast<EActivityType>(FMath::RandRange(1, static_cast<int32>(EActivityType::AT_Home)));

            // Add the scheduled activity to the schedule
            ScheduledActivities.Add(NewScheduledActivity);
        }
    }
}

void USchedulerComponent::UpdateSchedule()
{
    // Calculate the modifier based on the current day of the week
    const int32 IndexDayModifier = static_cast<int32>(DayNightCycle->GetCurrentDayOfTheWeek()) * 4;

    // Calculate the modifier based on the current time of day
    int32 IndexTimeOfDayModifier = 0;
    switch (DayNightCycle->GetCurrentTimeOfDay())
    {
    case ETimeOfDay::Afternoon:
        IndexTimeOfDayModifier = 1;
        break;
    case ETimeOfDay::Evening:
        IndexTimeOfDayModifier = 2;
        break;
    case ETimeOfDay::Night:
        IndexTimeOfDayModifier = 3;
        break;
    default:
        break;
    }

    // Calculate the current index
    CurrentIndex = IndexDayModifier + IndexTimeOfDayModifier;

    // Ensure CurrentIndex stays within bounds
    CurrentIndex %= ScheduledActivities.Num();

    
}

