// Fill out your copyright notice in the Description page of Project Settings.


#include "Patron.h"

#include "BuildingManager.h"
#include "DefaultGameMode.h"
#include "EngineUtils.h"
#include "PatronAiController.h"
#include "PatronManager.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HomeStuff/HomeObject.h"
#include "WorkStuff/WorkObject.h"
#include "WorkStuff/WorkStation.h"

// Sets default values
APatron::APatron()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up the body mesh
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	BodyMesh->SetupAttachment(GetCapsuleComponent());
	// Set up the head mesh
	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Component"));
	// Attach the head mesh to the body mesh
	HeadMesh->SetupAttachment(BodyMesh);

	// Create the hunger stat component
	HungerStatComponent = CreateDefaultSubobject<UHungerStatComponent>(TEXT("HungerStatComponent"));

	// Create the energy stat component
	EnergyStatComponent = CreateDefaultSubobject<UEnergyStatComponent>(TEXT("EnergyStatComponent"));

	// Create the walking speed stat component
	WalkingSpeedStatComponent = CreateDefaultSubobject<UWalkingSpeedStatComponent>(TEXT("WalkingSpeedStatComponent"));

    // Create the Scheduler Component
    SchedulerComponent = CreateDefaultSubobject<USchedulerComponent>(TEXT("SchedulerComponentComponent"));

	CurrentInterestIndex = -1; // Set the current interest index to 0

	MaxInterestIndex = 2; // Set the max interest index to 2

    ThisPatronsBed = nullptr;
}

// Called when the game starts or when spawned
void APatron::BeginPlay()
{
	Super::BeginPlay();

	// Find the patron manager
	for (TActorIterator<APatronManager> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PatronManager = *ActorItr;
	}

	// Call the RoleInterest function to set the interests of the patron
	RoleInterest();

    // Call the RoleTraits function to set the traits of the patron
    RoleTraits();

	// Get the AI controller for the patron
	PatronAiController = Cast<APatronAiController>(GetController());

	// Generate decisions for the patron
	PatronAiController->GenerateDecisions();

    PatronAiController->PatronControlling = this;

	// Call the UpdateCurrentInterest function to set the next interest
	UpdateCurrentInterest();

    // Assign Bed
    AssignBed();

    // Assign WorkStation
    AssignWorkStation();

    LastActivity = EActivityType::AT_None;
	
}

// Called every frame
void APatron::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Set the NextInterest
    NextInterest = Interests[CurrentInterestIndex];

    
}

// Called to bind functionality to input
void APatron::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void APatron::UpdateCurrentInterest()
{
	// Increment the current interest index
	CurrentInterestIndex++;

	// If the current interest index is greater than the max interest index
	if (CurrentInterestIndex > MaxInterestIndex)
	{
		// Reset the current interest index to 0
		CurrentInterestIndex = 0; 
	}
}

void APatron::RemovePatron()
{
	// Remove the patron from the patron manager
	PatronManager->RemovePatron(this);

	// Destroy the patron
	Destroy();
}

void APatron::UpdateMaterial(bool bSelected) const
{
    if (bSelected)
    {
    	BodyMesh->SetMaterial(0, SelectedMaterial);
	}
	else
	{
		BodyMesh->SetMaterial(0, OriginalMaterial);
	}
}

void APatron::RoleInterest()
{
    TArray<int> PickedRoles;  // Array to keep track of picked roles
    int Attempts = 0;         // Counter to prevent infinite loops

    while (Interests.Num() < 3 && Attempts < 100)
    {
        int RandomInt = FMath::RandRange(0, 10);

        // Check if we have already picked this role or if it's the same as the last one picked
        if (!PickedRoles.Contains(RandomInt) && (PickedRoles.IsEmpty() || PickedRoles.Last() != RandomInt))
        {
            EStoreType StoreInterestType = static_cast<EStoreType>(RandomInt);
            Interests.Add(StoreInterestType);      // Add the store type to the interests array
            PickedRoles.Add(RandomInt);            // Remember this role to prevent repeats
        }
        else
        {
            Attempts++;  // Increment attempt counter to avoid potential infinite loop
            continue;    // Skip to the next iteration
        }

        if (Interests.Num() >= 3) break;  // Break the loop if we have added enough interests
    }

    // Handle the case where it's not possible to add 3 unique items (Will never Hit this (Maybe :) ))
    if (Interests.Num() < 3)
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not find three unique roles after 100 attempts."));
    }

}

void APatron::RoleTraits()
{
    TArray<int> PickedTraits;  // Array to keep track of picked traits
    int Attempts = 0;          // Counter to prevent infinite loops

    while (PickedTraits.Num() < 3 && Attempts < 100)
    {
        int RandomInt = FMath::RandRange(0, static_cast<int32>(ETraits::Traits_OutOfShape));

        // Check if we have already picked this trait and if it's in an exclusive group with a picked trait
        if (!PickedTraits.Contains(RandomInt) && !IsTraitInExclusiveGroup(RandomInt, PickedTraits))
        {
            ETraits Trait = static_cast<ETraits>(RandomInt);
            Traits.Add(Trait);              // Add the trait to the Traits array
            PickedTraits.Add(RandomInt);   // Remember this trait to prevent repeats
        }
        else
        {
            Attempts++;  // Increment attempt counter to avoid potential infinite loop
            continue;    // Skip to the next iteration
        }
    }

    // Handle the case where it's not possible to add 3 unique traits
    if (PickedTraits.Num() < 3)
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not find three unique traits after 100 attempts."));
    }
}

void APatron::AssignBed()
{
    // Get the default game mode
    const ADefaultGameMode* DefaultGameMode = Cast<ADefaultGameMode>(GetWorld()->GetAuthGameMode());

    if (DefaultGameMode)
    {
        // Loop our list of Beds from BuildingManager
        for (const auto Home : DefaultGameMode->GetBuildingManager()->GetHomes())
        {
	        if (Home->IsAtFullCapacity()) // If this home is full skip it
                continue;

            ThisPatronsBed = Home->GetNextAvailableBed(); // Get Next Open bed

            // Assign next open bed
            ThisPatronsBed->GetResidentSlot()->SetResident(this);

            return;
        }
    }
}

void APatron::AssignWorkStation()
{
    // Get the default game mode
    const ADefaultGameMode* DefaultGameMode = Cast<ADefaultGameMode>(GetWorld()->GetAuthGameMode());

    if (DefaultGameMode)
    {
        // Loop our list of Beds from BuildingManager
        for (const auto Job : DefaultGameMode->GetBuildingManager()->GetJobs())
        {
            if (Job->IsAtFullCapacity()) // If this home is full skip it
                continue;

            ThisPatronsWorkStation = Job->GetNextAvailableStation(); // Get Next Open bed

            // Assign next open bed
            ThisPatronsWorkStation->GetResidentSlot()->SetResident(this);

            return;
        }
    }
}

bool APatron::IsTraitInExclusiveGroup(int Trait, const TArray<int>& PickedTraits)
{
    // Define trait groups where traits are mutually exclusive
    TArray<TArray<int>> ExclusiveGroups = 
    {
        { static_cast<int>(ETraits::Traits_Young), static_cast<int>(ETraits::Traits_Old) },
        { static_cast<int>(ETraits::Traits_FastWalker), static_cast<int>(ETraits::Traits_SlowWalker) },
        { static_cast<int>(ETraits::Traits_HardWorker), static_cast<int>(ETraits::Traits_Lazy) },
        { static_cast<int>(ETraits::Traits_Gourmand), static_cast<int>(ETraits::Traits_HealthNut) },
        { static_cast<int>(ETraits::Traits_Athletic), static_cast<int>(ETraits::Traits_OutOfShape) }
    };

    // Check if the new trait is in any exclusive group with a picked trait
    for (const auto& Group : ExclusiveGroups)
    {
        if (Group.Contains(Trait) && PickedTraits.ContainsByPredicate([&Group](int PickedTrait) { return Group.Contains(PickedTrait); }))
        {
            return true;
        }
    }

    return false;
}

