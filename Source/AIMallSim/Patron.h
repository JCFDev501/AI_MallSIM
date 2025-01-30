// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SchedulerComponent.h"
#include "GameFramework/Character.h"
#include "Stats/EnergyStatComponent.h"
#include "Stats/HungerStatComponent.h"
#include "Stats/WalkingSpeedStatComponent.h"
#include "Util/PatronTraits.h"
#include "Util/StoreTypes.h"
#include "Patron.generated.h"

class APatronAiController;
class AWorkStation;
class AResidentBed;
class APatronManager;

UCLASS()
class AIMALLSIM_API APatron : public ACharacter
{
	GENERATED_BODY()

	// Static Mesh for Body Visual
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyMesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BodyMesh;

	// Static Mesh for Body Visual
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeadMesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* HeadMesh;

	// Reference to patron Manager
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PatronManager", meta = (AllowPrivateAccess = "true"))
	APatronManager* PatronManager;

	// List Of Interests
	UPROPERTY(VisibleAnywhere, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	TArray<EStoreType> Interests;

	// List Of Traits
	UPROPERTY(VisibleAnywhere, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	TArray<ETraits> Traits;

	// Current Interest
	UPROPERTY(VisibleAnywhere, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	EStoreType NextInterest;

	// Original Material
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeadMesh", meta = (AllowPrivateAccess = "true"))
	UMaterial* OriginalMaterial;

	// Selected Material
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeadMesh", meta = (AllowPrivateAccess = "true"))
	UMaterial* SelectedMaterial;

	int CurrentInterestIndex;
	int MaxInterestIndex;

	UPROPERTY()
	APatronAiController* PatronAiController;

	UPROPERTY(VisibleAnywhere, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	AResidentBed* ThisPatronsBed;

	UPROPERTY(VisibleAnywhere, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	AWorkStation* ThisPatronsWorkStation;

	EActivityType LastActivity;

public:
	// Sets default values for this pawn's properties
	APatron();

	// --------------------------------------------- Stats ---------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	UHungerStatComponent* HungerStatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	UEnergyStatComponent* EnergyStatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	UWalkingSpeedStatComponent* WalkingSpeedStatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	USchedulerComponent* SchedulerComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Get Current Interest
	EStoreType GetCurrentInterest() const { return NextInterest; }

	// Get Interests
	TArray<EStoreType> GetInterests() const { return Interests; }

	// Get Traits
	TArray<ETraits> GetTraits() const { return Traits; }

	// Get the Patron Manager
	APatronManager* GetPatronManager() const { return PatronManager; }

	// Update the Current Interest
	void UpdateCurrentInterest();

	// Remove patron from the store
	void RemovePatron();

	// Update patrons Material
	void UpdateMaterial(bool bSelected) const;

	AResidentBed* GetThisPatronsBed() const { return ThisPatronsBed; }
	AWorkStation* GetThisPatronsWorkStation() const { return ThisPatronsWorkStation; }

private:
	// TODO: This function should be called when the patron enters the store
	void RoleInterest();

	static bool IsTraitInExclusiveGroup(int Trait, const TArray<int>& PickedTraits);

	// This function will be called when we spawn a patron
	void RoleTraits();

	void AssignBed();

	void AssignWorkStation();

};
