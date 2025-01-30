// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "PatronSlot.generated.h"

/**
 * This enum represents the state of the slot.
 */
UENUM(BlueprintType)
enum class ESlotState : uint8
{
	SS_Empty UMETA(DisplayName = "Empty"),
	SS_Targeted UMETA(DisplayName = "Targeted"),
};

/**
 *  This class is a target point that represents a slot in the store.
 *	Each Store has a certain number of slots that can be occupied by a patron.
 */
UCLASS()
class AIMALLSIM_API APatronSlot : public ATargetPoint
{
	GENERATED_BODY()

	// A slot current state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentState", meta = (AllowPrivateAccess = "true"))
	ESlotState CurrentSlotState;

public:

	APatronSlot();

	// Set the Slot State
	void SetSlotState(ESlotState NewState) { CurrentSlotState = NewState; }

	// Get SlotState
	ESlotState GetSlotState() const { return CurrentSlotState; }

	// set the slot
	void SetSlot(ESlotState newState) { CurrentSlotState = newState; }
};
