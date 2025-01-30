// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud.h"

#include "UserInterface/DayNightCycleWidget.h"
#include "UserInterface/InformationPanel.h"

void APlayerHud::ShowPanel()
{
	if (!InfoPanelWidget)
	{
		// Make widget owned by our player
		APlayerController* PlayerController = Cast<APlayerController>(GetOwner());
		InfoPanelWidget = Cast<UInformationPanel>(CreateWidget(PlayerController, InfoPanelWidgetClass));

		InfoPanelWidget->AddToViewport();
	}
	else
	{
		InfoPanelWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void APlayerHud::HidePanel()
{
	if (InfoPanelWidget)
	{
		InfoPanelWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void APlayerHud::LoadPanelInfo(APatron* Patron)
{
	if (InfoPanelWidget)
	{
		InfoPanelWidget->UpdatePatronInfoPanel(Patron);
	}
}

void APlayerHud::ShowDayNightCyclePanel()
{
	if (!DayNightCyclePanelWidget)
	{
		// Make widget owned by our player
		APlayerController* PlayerController = Cast<APlayerController>(GetOwner());
		DayNightCyclePanelWidget = Cast<UDayNightCycleWidget>(CreateWidget(PlayerController, DayNightCyclePanelWidgetClass));

		DayNightCyclePanelWidget->AddToViewport();
	}
	else
	{
		DayNightCyclePanelWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void APlayerHud::HideDayNightCyclePanel()
{
	if (DayNightCyclePanelWidget)
	{
		DayNightCyclePanelWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void APlayerHud::LoadDayNightCyclePanelInfo()
{
	DayNightCyclePanelWidget->UpdateDayNightCycleInfo();
}
