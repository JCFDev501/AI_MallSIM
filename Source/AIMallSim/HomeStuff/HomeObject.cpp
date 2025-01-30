// Fill out your copyright notice in the Description page of Project Settings.


#include "HomeStuff/HomeObject.h"

// Sets default values
AHomeObject::AHomeObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Store Mesh
	HomeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HomeMesh"));

	// The cast makes it so the Default Root Component does not generate
	SetRootComponent(Cast<USceneComponent>(HomeMesh));

}

// Called when the game starts or when spawned
void AHomeObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHomeObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AHomeObject::IsAtFullCapacity()
{
	for (const auto Bed : ResidentBeds)
		if (Bed->GetResidentSlot()->GetAssignedPatron() == nullptr)
			return false; // We are not at full capacity

	return true; // We are at full capacity
}

AResidentBed* AHomeObject::GetNextAvailableBed()
{
	for (const auto Bed : ResidentBeds)
	{
		if (Bed->GetResidentSlot()->GetAssignedPatron() == nullptr)
		{
			return Bed; // this bed is Available
		}
	}

	return nullptr; // We are at full capacity
}



