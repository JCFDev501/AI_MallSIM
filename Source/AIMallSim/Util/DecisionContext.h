// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * Context for making a decision, which includes the actor and the target.
 */
struct FDecisionContext
{
    AActor* Actor;  // The agent making the decision

    AActor* Target;  // The target of the decision
};
