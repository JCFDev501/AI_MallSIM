// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InformationPanel.generated.h"

class APatron;
/**
 * 
 */
UCLASS()
class AIMALLSIM_API UInformationPanel : public UUserWidget
{
	GENERATED_BODY()

public:


	// ------------------------------------------ Stats ------------------------------------------

	// Patron Name Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PatronNameText;

	// Patron Hunger Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PatronHungerText;

	// Patron Energy Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PatronEnergyText;

	// WalkSpeed Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* WalkSpeedText;

	// ------------------------------------------ Traits ------------------------------------------

	// Patron Trait #1 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PatronTrait1Text;

	// Patron Trait #2 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PatronTrait2Text;

	// Patron Trait #3 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PatronTrait3Text;

	// ------------------------------------------ Mall Store Interests ------------------------------------------

	// Mall Store Interest #1 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* MallStoreInterest1Text;

	// Mall Store Interest #2 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* MallStoreInterest2Text;

	// Mall Store Interest #3 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* MallStoreInterest3Text;

	// ------------------------------------------ Top 5 Chosen Actions ------------------------------------------

	// Top Action Name #1 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionName1Text;
	// Top Action Target #1 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionTarget1Text;
	// Top Action Score #1 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionScore1Text;

	// Top Action Name #2 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionName2Text;
	// Top Action Target #2 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionTarget2Text;
	// Top Action Score #2 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionScore2Text;

	// Top Action Name #3 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionName3Text;
	// Top Action Target #3 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionTarget3Text;
	// Top Action Score #3 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionScore3Text;

	// Top Action Name #4 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionName4Text;
	// Top Action Target #4 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionTarget4Text;
	// Top Action Score #4 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionScore4Text;

	// Top Action Name #5 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionName5Text;
	// Top Action Target #5 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionTarget5Text;
	// Top Action Score #5 Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TopActionScore5Text;

	// ---------------------------------------------------- Current Action ----------------------------------------------------

	// Current Action Name Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CurrentActionNameText;
	// Current Action Target Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CurrentActionTargetText;
	// Current Action Score Text
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CurrentActionScoreText;

	void UpdatePatronInfoPanel(APatron* Patron);
};
