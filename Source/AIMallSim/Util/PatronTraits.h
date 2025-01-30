// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ETraits : uint8
{
	Traits_Young UMETA(DisplayName = "Young"),
	Traits_Old UMETA(DisplayName = "Old"),

	Traits_FastWalker UMETA(DisplayName = "FastWalker"),
	Traits_SlowWalker UMETA(DisplayName = "SlowWalker"),

	Traits_HardWorker UMETA(DisplayName = "HardWorker"),
	Traits_Lazy UMETA(DisplayName = "Lazy"),

	Traits_Gourmand  UMETA(DisplayName = "Gourmand"),
	Traits_HealthNut  UMETA(DisplayName = "HealthNut"),

	Traits_Athletic  UMETA(DisplayName = "Athletic"),
	Traits_OutOfShape  UMETA(DisplayName = "OutOfShape"),
};
