// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorkObject.generated.h"

enum class EStoreType : uint8;
class AWorkStation;

UCLASS()
class AIMALLSIM_API AWorkObject : public AActor
{
	GENERATED_BODY()

	// Static Mesh for store Visual
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorkObjectMesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* JobMesh;

	// Our Store Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorkStations", meta = (AllowPrivateAccess = "true"))
	TArray<AWorkStation*> ResidentWorkStations;

	// The Type Of Store
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoreType", meta = (AllowPrivateAccess = "true"))
	EStoreType StoreType;

	// Additional Store Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionType", meta = (AllowPrivateAccess = "true"))
	EStoreType ActionType;
	
public:	
	// Sets default values for this actor's properties
	AWorkObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Check Full Capacity
	bool IsAtFullCapacity();

	// Get the next available bed
	AWorkStation* GetNextAvailableStation();

};
