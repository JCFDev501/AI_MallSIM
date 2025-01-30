// Fill out your copyright notice in the Description page of Project Settings.


#include "GodPlayerController.h"

#include "DefaultGameMode.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Patron.h"
#include "PlayerHud.h"

void AGodPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

    if (EnhancedInputComponent)
    {
        // Assuming LeftClickAction is a UInputAction* that's been properly initialized elsewhere in your controller
        EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Started, this, &AGodPlayerController::OnLeftClick);
    }
}

void AGodPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    if (PatronClickedOn)
		DefaultGameMode->GetPlayerHud()->LoadPanelInfo(PatronClickedOn); // Load the panel info for the clicked patron
}

void AGodPlayerController::BeginPlay()
{
	Super::BeginPlay();

    // Get the default game mode
    DefaultGameMode = Cast<ADefaultGameMode>(GetWorld()->GetAuthGameMode());

    if (!DefaultGameMode)
    {
    	UE_LOG(LogTemp, Error, TEXT("GodPlayerController: DefaultGameMode is not set!"));
	}

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(GodPlayerControllerMappingContext, 0);
    }
}

void AGodPlayerController::OnLeftClick()
{
    float MouseX, MouseY;
    if (GetMousePosition(MouseX, MouseY)) // Get mouse position
    {
        FVector WorldLocation, WorldDirection;
        if (DeprojectScreenPositionToWorld(MouseX, MouseY, WorldLocation, WorldDirection)) // Convert to world position
        {
            FHitResult HitResult;
            FVector StartLocation = WorldLocation;
            FVector EndLocation = StartLocation + (WorldDirection * 10000.0f); // Extend to ensure it hits something

            // Perform a raycast to determine what the player clicked on
            if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility))
            {
                APatron* NewPatronClickedOn = Cast<APatron>(HitResult.GetActor());

                // Update material and panel visibility based on the new patron clicked on
                if (NewPatronClickedOn != PatronClickedOn)
                {
                    if (PatronClickedOn)
                    {
                        PatronClickedOn->UpdateMaterial(false); // Update material of previously clicked-on patron
                    }

                    PatronClickedOn = NewPatronClickedOn;

                    if (PatronClickedOn)
                    {
                        PatronClickedOn->UpdateMaterial(true); // Update material of newly clicked-on patron
                        DefaultGameMode->GetPlayerHud()->ShowPanel(); // Show the panel
                    }
                    else
                    {
                        DefaultGameMode->GetPlayerHud()->HidePanel(); // Hide the panel if no patron is clicked on
                    }
                }
            }
        }
    }
}
