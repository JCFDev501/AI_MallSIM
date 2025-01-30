// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionDefinition.h"

UENUM(BlueprintType)
enum class EActionState : uint8
{
    AS_NotRunning UMETA(DisplayName = "NotRunning"),
	AS_Running UMETA(DisplayName = "Rinning"),
	AS_Completed UMETA(DisplayName = "Completed"),
};

/**
 * Represents an actionable decision with a computed score.
 */
struct FScoredAction
{
    FActionDefinition ActionDef;
    AActor* Target;
    float Score;

    EActionState State = EActionState::AS_NotRunning;

    FScoredAction();
};
