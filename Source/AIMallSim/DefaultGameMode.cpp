// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultGameMode.h"

#include "BuildingManager.h"
#include "ConsiderationManager.h"
#include "PlayerHud.h"
#include "Util/DayNightCycle.h"

void ADefaultGameMode::BeginPlay()
{

	DecisionPackageManager = NewObject<UDecisionPackageManager>(this, UDecisionPackageManager::StaticClass());

	ConsiderationManager = NewObject<UConsiderationManager>(this, UConsiderationManager::StaticClass());

	BuildingManager = NewObject<UBuildingManager>(this, UBuildingManager::StaticClass());

	DayNightCycle = NewObject<ADayNightCycle>(this, ADayNightCycle::StaticClass());

	DayNightCycle->Init();

	ConsiderationManager->InitializeConsiderationManager();

	DecisionPackageManager->InitAllPackages(this);

	BuildingManager->GatherAllHomesAndWorkStations();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true;
		PlayerController->bEnableMouseOverEvents = true;
	}

	// Create the player HUD
	PlayerHud = Cast<APlayerHud>(PlayerController->GetHUD());

	if (PlayerHud)
	{
		PlayerHud->ShowPanel();
		PlayerHud->HidePanel();
		PlayerHud->ShowDayNightCyclePanel();
	}

	DayNightCycle->SetTimerSpeed(TimerSpeedForDayNight);
	
}
