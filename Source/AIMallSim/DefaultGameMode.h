// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Packages/DecisionPackageManager.h"
#include "DefaultGameMode.generated.h"

class ADayNightCycle;
class UBuildingManager;
class APlayerHud;
class UConsiderationManager;
class UPackageManager;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API ADefaultGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY()
	UDecisionPackageManager* DecisionPackageManager = nullptr;

	UPROPERTY()
	UConsiderationManager* ConsiderationManager = nullptr;

	UPROPERTY()
	UBuildingManager* BuildingManager = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DayNight", meta = (AllowPrivateAccess = "true"))
	ADayNightCycle* DayNightCycle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DayNight", meta = (AllowPrivateAccess = "true"))
	float TimerSpeedForDayNight;

	UPROPERTY()
	APlayerHud* PlayerHud = nullptr;

public:

	virtual void BeginPlay() override;

	UDecisionPackageManager* GetDecisionPackageManager() const { return DecisionPackageManager; }

	UConsiderationManager* GetConsiderationManager() const { return ConsiderationManager; }

	UBuildingManager* GetBuildingManager() const { return BuildingManager; }

	ADayNightCycle* GetDayNightCycle() const { return DayNightCycle; }

	APlayerHud* GetPlayerHud() const { return PlayerHud; }
};
