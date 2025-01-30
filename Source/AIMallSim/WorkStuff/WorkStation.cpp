// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkStuff/WorkStation.h"

// Sets default values
AWorkStation::AWorkStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the bed Mesh
	StationMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StationMesh"));

	// The cast makes it so the Default Root Component does not generate
	SetRootComponent(Cast<USceneComponent>(StationMesh));

}

// Called when the game starts or when spawned
void AWorkStation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorkStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

