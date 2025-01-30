// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingManager.h"

#include "HomeStuff/HomeObject.h"
#include "Kismet/GameplayStatics.h"
#include "WorkStuff/WorkObject.h"

void UBuildingManager::GatherAllHomesAndWorkStations()
{
    // Get all actors in the world
	TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);

    // Iterate through all actors
    for (AActor* Actor : AllActors)
    {
        // Check if the actor is a home or a work station
        AHomeObject* HomeActor = Cast<AHomeObject>(Actor);
        //AWorkStation* WorkStationActor = Cast<AWorkStation>(Actor);
        if (HomeActor)
        {
            // Add the actor to the array
            Homes.Add(HomeActor);
        }
    }

    // Iterate through all actors
    for (AActor* Actor : AllActors)
    {
        // Check if the actor is a home or a work station
        AWorkObject* JobActor = Cast<AWorkObject>(Actor);
        //AWorkStation* WorkStationActor = Cast<AWorkStation>(Actor);
        if (JobActor)
        {
            // Add the actor to the array
            Jobs.Add(JobActor);
        }
    }
}
