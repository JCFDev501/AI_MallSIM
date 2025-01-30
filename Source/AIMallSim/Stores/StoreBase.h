// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StoreBase.generated.h"

enum class EStoreType : uint8;
class APatronSlot;

UCLASS()
class AIMALLSIM_API AStoreBase : public AActor
{
	GENERATED_BODY()

	// Static Mesh for store Visual
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoreMesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StoreMesh;

	// Our Store Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PatronSlots", meta = (AllowPrivateAccess = "true"))
	TArray<APatronSlot*> PatronSlots;

	// The Type Of Store
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoreType", meta = (AllowPrivateAccess = "true"))
	EStoreType StoreType;

	// Additional Store Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionType", meta = (AllowPrivateAccess = "true"))
	EStoreType ActionType;




public:	
	// Sets default values for this actor's properties
	AStoreBase();

	// Check To see if store is At full capacity
	bool IsAtFullCapacity();

	APatronSlot* GetNextAvailableSlot();

	// Get Patron Slots
	TArray<APatronSlot*> GetPatronSlots() const { return PatronSlots; }

	// Get Store Type
	EStoreType GetStoreType() const { return StoreType; }

	// Get Action Type
	EStoreType GetActionType() const { return ActionType; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
