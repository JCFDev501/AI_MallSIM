// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stores/StoreBase.h"
#include "RestArea.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API ARestArea : public AStoreBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyAmountGivenToPatron", meta = (AllowPrivateAccess = "true"))
	float EnergyAmount;

public:
	ARestArea();

	// Get Food Amount
	float GetEnergyAmount() const { return EnergyAmount; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
