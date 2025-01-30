// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionDefinition.generated.h" 

enum class EStoreType : uint8;
/**
 * Action Definition that specifies what actions can be taken and their target tags.
 */
USTRUCT(BlueprintType)
struct FActionDefinition
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionName;  // Name of the action, e.g., "Eat", "Shop"

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStoreType StoreType;  // Tag that identifies compatible targets, e.g., "FoodVendor", "Store"

};

