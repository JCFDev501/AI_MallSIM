// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PatronManager.generated.h"

class APatronSpawnPoint;
class APatron;
/**
 *  This class will manage the spawning of patrons in the mall and keep track of the population of the mall.
 */
UCLASS()
class AIMALLSIM_API APatronManager : public AActor
{
	GENERATED_BODY()

	// List of all patrons in the mall
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	TArray<APatron*> Patrons;

	// Current population of the mall
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	int32 Population;

	// Max population of the mall
	int32 MaxPopulation;

	// Last Population Count
	int32 LastPopulation;

	// Blueprint of the patron to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<APatron> PatronBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	APatronSpawnPoint* PatronSpawnPoint;

	// The Timer Handle for spawning patrons
	FTimerHandle PatronSpawnTimer;

	// Target Time for patron spawn Timer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	float TimeBeforeSpawnNextPatron;
public:
	APatronManager();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Spawns a patron in the mall
	void SpawnPatron();

	// Removes a patron from the mall
	void RemovePatron(APatron* Patron);

	// Returns the current population of the mall
	int32 GetPopulation() const { return Population; }
	
};
