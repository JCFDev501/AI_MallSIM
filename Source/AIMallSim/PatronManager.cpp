// Fill out your copyright notice in the Description page of Project Settings.


#include "PatronManager.h"

#include "Patron.h"
#include "Util/PatronSpawnPoint.h"

APatronManager::APatronManager()
	: Population(0), LastPopulation(0)
{
	// Set the default target time to 5 seconds
	TimeBeforeSpawnNextPatron = 5.0f;

	// Set the default max population to 125
	MaxPopulation = 120;
}

void APatronManager::BeginPlay()
{
	Super::BeginPlay();

	// Set a repeating timer to call SpawnPatron every TimeBeforeSpwanNextPatron seconds
	GetWorld()->GetTimerManager().SetTimer(PatronSpawnTimer, this, &APatronManager::SpawnPatron, TimeBeforeSpawnNextPatron, true);
}

void APatronManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APatronManager::SpawnPatron()
{
	// Check if the population is at the max
	if (LastPopulation == MaxPopulation)
		return;

	if (!PatronBlueprint) // Ensure the blueprint is set
	{
		UE_LOG(LogTemp, Warning, TEXT("Patron blueprint is not set."));
		return;
	}

	if (!PatronSpawnPoint) // Ensure the blueprint is set
	{
		UE_LOG(LogTemp, Warning, TEXT("Patron blueprint is not set."));
		return;
	}

	UWorld* World = GetWorld(); // Get the current world
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("World context is null, cannot spawn patron."));
		return;
	}

	const FVector Location = PatronSpawnPoint->GetActorLocation();
	const FRotator Rotation = PatronSpawnPoint->GetActorRotation();

	// Spawn the patron in the world
	APatron* NewPatron = World->SpawnActor<APatron>(PatronBlueprint, Location, Rotation);

	// Add the patron to the list of patrons
	Patrons.Add(NewPatron);

	// Increment the population
	Population++;

	// Increment the last population
	LastPopulation++;
}

void APatronManager::RemovePatron(APatron* Patron)
{
	if (Patrons.Contains(Patron)) // Check if the patron is in the list of patrons
	{
		Patrons.Remove(Patron); // Remove the patron from the list
		Population--; // Decrement the population
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Patron not found in the list of patrons."));
	}
}
