// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterface/DayNightCycleWidget.h"

#include "DefaultGameMode.h"
#include "Components/TextBlock.h"
#include "Util/DayNightCycle.h"

void UDayNightCycleWidget::UpdateDayNightCycleInfo() const
{
	const ADefaultGameMode* GameMode = Cast<ADefaultGameMode>(GetWorld()->GetAuthGameMode());

    if (GameMode)
    {
	    const ADayNightCycle* DayNightCycle = GameMode->GetDayNightCycle();

	    const EMyDayOfWeek CurDay = DayNightCycle->GetCurrentDayOfTheWeek();
	    const ETimeOfDay CurTimeOfDay = DayNightCycle->GetCurrentTimeOfDay();

	    const FString CurrentDay = UEnum::GetValueAsString(CurDay);
	    const FString CurrentTimeOfDay = UEnum::GetValueAsString(CurTimeOfDay);
        
        CurrentDayText->SetText(FText::FromString(CurrentDay));
        TimeOfDayText->SetText(FText::FromString(CurrentTimeOfDay));

        CurrentMinText->SetText(FText::FromString(FString::Printf(TEXT("Min: %d"), DayNightCycle->GetCurrentMinute())));
        CurrentSecText->SetText(FText::FromString(FString::Printf(TEXT("Sec: %d"), DayNightCycle->GetCurrentSecond())));
    }
}
