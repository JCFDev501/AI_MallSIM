// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GodPlayerController.generated.h"

class APatron;
class ADefaultGameMode;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API AGodPlayerController : public APlayerController
{
	GENERATED_BODY()

	// Mapping of input to movement
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* GodPlayerControllerMappingContext;

	//Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LeftClickAction;

	// Default GameMode
	UPROPERTY()
	ADefaultGameMode* DefaultGameMode;

	// Patron currently selected
	UPROPERTY()
	APatron* PatronClickedOn;

protected:
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

public:
	virtual void BeginPlay() override;

private:
	void OnLeftClick();
	
};
