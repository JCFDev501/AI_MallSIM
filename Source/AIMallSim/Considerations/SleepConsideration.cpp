// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/SleepConsideration.h"

#include "DefaultGameMode.h"
#include "Patron.h"
#include "Kismet/GameplayStatics.h"
#include "Util/DayNightCycle.h"
#include "Util/DecisionContext.h"

float USleepConsideration::Score(const FDecisionContext& Context)
{
	const ADefaultGameMode* DefaultGameMode = Cast<ADefaultGameMode>(UGameplayStatics::GetGameMode(Context.Actor->GetWorld()));
    if (!DefaultGameMode)
    {
        return 0.0f; // Unable to get the game mode, return a default score
    }

    const APatron* Patron = Cast<APatron>(Context.Actor);
    if (!Patron)
    {
        return 0.0f; // Context.Actor is not a Patron, return a default score
    }

    if (DefaultGameMode->GetDayNightCycle()->GetCurrentTimeOfDay() == ETimeOfDay::Night)
    {
        return 0.51f;  // Max utility if it's night
    }

    return 0.0f; // No utility if it's not night
}
