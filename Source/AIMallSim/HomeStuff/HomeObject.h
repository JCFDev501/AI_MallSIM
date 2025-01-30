// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResidentBed.h"
#include "GameFramework/Actor.h"
#include "HomeObject.generated.h"

enum class EStoreType : uint8;

UCLASS()
class AIMALLSIM_API AHomeObject : public AActor
{
	GENERATED_BODY()

	// Static Mesh for store Visual
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HomeObjectMesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* HomeMesh;

	// Our Store Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ResidentBeds", meta = (AllowPrivateAccess = "true"))
	TArray<AResidentBed*> ResidentBeds;

	// The Type Of Store
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoreType", meta = (AllowPrivateAccess = "true"))
	EStoreType StoreType;

	// Additional Store Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionType", meta = (AllowPrivateAccess = "true"))
	EStoreType ActionType;
	
public:	
	// Sets default values for this actor's properties
	AHomeObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Check Full Capacity
	bool IsAtFullCapacity();

	// Get the next available bed
	AResidentBed* GetNextAvailableBed();

	// Get Store Type
	EStoreType GetStoreType() const { return StoreType; }

	// Get Action Type
	EStoreType GetActionType() const { return ActionType; }
		

};
