// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stores/StoreBase.h"
#include "FoodArea.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API AFoodArea : public AStoreBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FoodAmountGivenToPatron", meta = (AllowPrivateAccess = "true"))
	float FoodAmount;

public:
	AFoodArea();

	// Get Food Amount
	float GetFoodAmount() const { return FoodAmount; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
