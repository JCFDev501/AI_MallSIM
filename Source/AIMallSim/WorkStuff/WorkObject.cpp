// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkStuff/WorkObject.h"

#include "WorkStation.h"

// Sets default values
AWorkObject::AWorkObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Store Mesh
	JobMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JobMesh"));

	// The cast makes it so the Default Root Component does not generate
	SetRootComponent(Cast<USceneComponent>(JobMesh));
}

// Called when the game starts or when spawned
void AWorkObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorkObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AWorkObject::IsAtFullCapacity()
{
	for (const auto WorkStation : ResidentWorkStations)
		if (WorkStation->GetResidentSlot()->GetAssignedPatron() == nullptr)
			return false; // We are not at full capacity

	return true; // We are at full capacity
}

AWorkStation* AWorkObject::GetNextAvailableStation()
{
	for (const auto WorkStation : ResidentWorkStations)
	{
		if (WorkStation->GetResidentSlot()->GetAssignedPatron() == nullptr)
		{
			return WorkStation; // this bed is Available
		}
	}

	return nullptr; // We are at full capacity
}

