// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stats/BaseStatComponent.h"
#include "HungerStatComponent.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UHungerStatComponent : public UBaseStatComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
