// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DayNightCycleWidget.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UDayNightCycleWidget : public UUserWidget
{
	GENERATED_BODY()

	// Current Day Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CurrentDayText;

	// Time Of Day Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TimeOfDayText;

	// Current Min Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CurrentMinText;

	// Current Sec Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CurrentSecText;

public:
	void UpdateDayNightCycleInfo() const;
	
};
