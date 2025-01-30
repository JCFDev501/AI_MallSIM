// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/DistanceConsideration.h"

#include "Util/DecisionContext.h"

float UDistanceConsideration::Score(const FDecisionContext& Context)
{
    if (Context.Actor && Context.Target)
    {
        const float Distance = (Context.Target->GetActorLocation() - Context.Actor->GetActorLocation()).Size();
        const float NormalizedDistance = Distance / MaxDistance / 10;

        const float Score = 0.1f - NormalizedDistance;  // Higher utility for closer targets

        return Score;
    }

    UE_LOG(LogTemp, Warning, TEXT("DistanceConsideration: One or more actors are invalid."));
    return 0.f;  // Return a neutral score if any actor is null
}
