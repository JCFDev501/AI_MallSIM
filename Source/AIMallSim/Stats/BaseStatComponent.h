// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseStatComponent.generated.h"


class APatron;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIMALLSIM_API UBaseStatComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatSetting", meta = (AllowPrivateAccess = "true"))
	float MaxVal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatSetting", meta = (AllowPrivate = "true"))
	float MinVal;

	UPROPERTY(VisibleAnywhere, Category = "StatSetting", meta = (AllowPrivateAccess = "true"))
	float CurrentVal;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decay Settings", meta = (AllowPrivate = "true"))
	bool bIsDecayAble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decay Settings", meta = (AllowPrivate = "true"))
	float DecayRate;

	float OriginalDecayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decay Settings", meta = (AllowPrivate = "true"))
	float DecayTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Decay Settings", meta = (AllowPrivate = "true"))
	float TimeTillNextDecay;

	UPROPERTY()
	APatron* PatronThatOwnsThisComponent;

	UPROPERTY()
	float ValModifer;

	UPROPERTY()
	bool TraitsAccessed;


public:	
	// Sets default values for this component's properties
	UBaseStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void IncreaseStatValue(float Value); // Increase the current value by the value

	float GetMaxVal() const { return MaxVal; } // Get the max value

	float GetMinVal() const { return MinVal; } // Get the min value

	float GetCurrentVal() const { return CurrentVal; } // Get the current value

private:
	void Decay(float DeltaTime);
};
