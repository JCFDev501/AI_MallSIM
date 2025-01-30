// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Util/ScheduledActivity.h"
#include "SchedulerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIMALLSIM_API USchedulerComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "ScheduledActivity", meta = (AllowPrivateAccess = "true"))
	TArray<FScheduledActivity> ScheduledActivities;

	UPROPERTY(VisibleAnywhere, Category = "ScheduledActivity", meta = (AllowPrivateAccess = "true"))
	FScheduledActivity CurrentScheduledActivity;

	UPROPERTY()
	ADayNightCycle* DayNightCycle;

	int32 MaxIndex;
	int32 CurrentIndex;

	int32 LastUpdatedMinute;

	bool FirstTimeInterval;

public:	
	// Sets default values for this component's properties
	USchedulerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Generate Schedule
	void GenerateSchedule();

	FScheduledActivity GetCurrentScheduledActivity() const { return CurrentScheduledActivity; }

	void UpdateSchedule();
};
