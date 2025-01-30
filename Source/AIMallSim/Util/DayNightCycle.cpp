// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/DayNightCycle.h"

#include "DefaultGameMode.h"
#include "PlayerHud.h"

ADayNightCycle::ADayNightCycle()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set the timer interval to 1 minute (60 seconds)
	TimerInterval = 1.0f;

    CurrentDay = EMyDayOfWeek::Monday;
    CurrentMinute = 0;
    CurrentSecond = 0;
}

void ADayNightCycle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

    GameMode->GetPlayerHud()->LoadDayNightCyclePanelInfo();

}

ETimeOfDay ADayNightCycle::GetCurrentTimeOfDay() const
{
    // Determine time of day based on current hour
    if (CurrentMinute >= 0 && CurrentMinute < 4)
    {
        return ETimeOfDay::Morning;
    }

    if (CurrentMinute >= 4 && CurrentMinute < 8)
    {
        return ETimeOfDay::Afternoon;
    }

    if (CurrentMinute >= 8 && CurrentMinute < 12)
    {
        return ETimeOfDay::Evening;
    }
   
	return ETimeOfDay::Night;
    
}

void ADayNightCycle::BeginPlay()
{
	Super::BeginPlay();

    GameMode = Cast<ADefaultGameMode>(GetWorld()->GetAuthGameMode());

	ResetTime();

	// Start the timer to update time every TimerInterval seconds
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ADayNightCycle::UpdateTime, TimerInterval, true);
}

void ADayNightCycle::UpdateTime()
{
    // Increment time
    CurrentSecond += 1;

    if (CurrentSecond >= 60)
    {
        CurrentSecond = 0;
        CurrentMinute += 1;

        if (CurrentMinute >= 16)
        {
            CurrentMinute = 0;
            
        	EndOfDay();
            
        }
    }
}

void ADayNightCycle::EndOfDay()
{
    // Increment day
    switch (CurrentDay)
    {
    case EMyDayOfWeek::Sunday:
        CurrentDay = EMyDayOfWeek::Monday;
        break;
    case EMyDayOfWeek::Monday:
        CurrentDay = EMyDayOfWeek::Tuesday;
        break;
    case EMyDayOfWeek::Tuesday:
        CurrentDay = EMyDayOfWeek::Wednesday;
        break;
    case EMyDayOfWeek::Wednesday:
        CurrentDay = EMyDayOfWeek::Thursday;
        break;
    case EMyDayOfWeek::Thursday:
        CurrentDay = EMyDayOfWeek::Friday;
        break;
    case EMyDayOfWeek::Friday:
        CurrentDay = EMyDayOfWeek::Saturday;
        break;
    case EMyDayOfWeek::Saturday:
        CurrentDay = EMyDayOfWeek::Sunday;
        break;
    }

    // Reset time to the beginning of the day
    ResetTime();
}

void ADayNightCycle::ResetTime()
{
    CurrentMinute = 0;
    CurrentSecond = 0;
}
