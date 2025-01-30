// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DayNightCycle.h"
#include "ScheduledActivity.generated.h"

UENUM(BlueprintType)
enum class EActivityType : uint8
{
    AT_None UMETA(DisplayName = "None"),
    AT_Work UMETA(DisplayName = "Work"),
    AT_Mall UMETA(DisplayName = "Mall"),
    AT_Home UMETA(DisplayName = "Home"),
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FScheduledActivity
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    EMyDayOfWeek DayOfTheWeek; // What Day

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    ETimeOfDay TimeOfDay; // What Time of day

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    EActivityType Activity; // What we have planned
};
