// Fill out your copyright notice in the Description page of Project Settings.


#include "HomeStuff/ResidentBed.h"

// Sets default values
AResidentBed::AResidentBed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the bed Mesh
	BedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BedMesh"));

	// The cast makes it so the Default Root Component does not generate
	SetRootComponent(Cast<USceneComponent>(BedMesh));

}

// Called when the game starts or when spawned
void AResidentBed::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResidentBed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

