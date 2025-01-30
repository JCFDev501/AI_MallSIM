// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHud.generated.h"

class APatron;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API APlayerHud : public AHUD
{
	GENERATED_BODY()

public:
	// ----------------------------- Information Panel -----------------------------
	UFUNCTION(BlueprintCallable)
	void ShowPanel();
	UFUNCTION(BlueprintCallable)
	void HidePanel();
	UFUNCTION(BlueprintCallable)
	void LoadPanelInfo(APatron* Patron);

	// ------------------------------ DayNightCycle panel ---------------------------

	UFUNCTION(BlueprintCallable)
	void ShowDayNightCyclePanel();
	UFUNCTION(BlueprintCallable)
	void HideDayNightCyclePanel();
	UFUNCTION(BlueprintCallable)
	void LoadDayNightCyclePanelInfo();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> InfoPanelWidgetClass;

	UPROPERTY()
	class UInformationPanel* InfoPanelWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> DayNightCyclePanelWidgetClass;

	UPROPERTY()
	class UDayNightCycleWidget* DayNightCyclePanelWidget;
	
};
