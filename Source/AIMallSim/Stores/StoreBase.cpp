// Fill out your copyright notice in the Description page of Project Settings.


#include "Stores/StoreBase.h"

#include "Util/PatronSlot.h"

// Sets default values
AStoreBase::AStoreBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StoreMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	// The cast makes it so the Default Root Component does not generate
	SetRootComponent(Cast<USceneComponent>(StoreMesh));

}

bool AStoreBase::IsAtFullCapacity()
{
	for (const auto Slot : PatronSlots)
		if (Slot->GetSlotState() == ESlotState::SS_Empty)
			return false; // We are not at full capacity

	return true; // We are at full capacity
}

APatronSlot* AStoreBase::GetNextAvailableSlot()
{
	for (const auto Slot : PatronSlots)
	{
		if (Slot->GetSlotState() == ESlotState::SS_Empty)
		{
			Slot->SetSlotState(ESlotState::SS_Targeted);
			return Slot; // We are not at full capacity
		}
	}

	return nullptr; // We are at full capacity
}

// Called when the game starts or when spawned
void AStoreBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStoreBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

