// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DayNightCycle.generated.h"

class ADefaultGameMode;

UENUM(BlueprintType)
enum class EMyDayOfWeek : uint8
{
    Monday UMETA(DisplayName = "Monday"),
    Tuesday UMETA(DisplayName = "Tuesday"),
    Wednesday UMETA(DisplayName = "Wednesday"),
    Thursday UMETA(DisplayName = "Thursday"),
    Friday UMETA(DisplayName = "Friday"),
    Saturday UMETA(DisplayName = "Saturday"),
    Sunday UMETA(DisplayName = "Sunday")
};

UENUM(BlueprintType)
enum class ETimeOfDay : uint8
{
    Morning UMETA(DisplayName = "Morning"),
    Afternoon UMETA(DisplayName = "Afternoon"),
    Evening UMETA(DisplayName = "Evening"),
    Night UMETA(DisplayName = "Night")
};

/**
 * 
 */
UCLASS()
class AIMALLSIM_API ADayNightCycle : public AActor
{
	GENERATED_BODY()

    // Current time variables
    EMyDayOfWeek CurrentDay;
    int32 CurrentMinute;
    int32 CurrentSecond;

    // Timer handle for updating time
    FTimerHandle TimeHandle;

    // Timer interval in seconds (1 minute)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time", meta = (AllowPrivateAccess = "true"))
    float TimerInterval;

    UPROPERTY()
    ADefaultGameMode* GameMode;

public:
    // Sets default values for this actor's properties
    ADayNightCycle();

    void Init() { BeginPlay(); }
    virtual void Tick(float DeltaSeconds) override;

	ETimeOfDay GetCurrentTimeOfDay() const;
    EMyDayOfWeek GetCurrentDayOfTheWeek() const { return CurrentDay; }
    int32 GetCurrentMinute() const { return CurrentMinute; }
    int32 GetCurrentSecond() const { return CurrentSecond; }

    void SetTimerSpeed(float value) { TimerInterval = value; }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    // Update the time
    void UpdateTime();

    // Handle end of day
    void EndOfDay();

    // Reset the time to the beginning of the day
    void ResetTime();
	
};
