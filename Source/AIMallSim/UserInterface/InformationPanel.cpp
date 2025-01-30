// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterface/InformationPanel.h"

#include "Patron.h"
#include "PatronAiController.h"
#include "Components/TextBlock.h"

void UInformationPanel::UpdatePatronInfoPanel(APatron* Patron)
{
	// Get the Patron Traits
	TArray<ETraits> Traits = Patron->GetTraits();

	// Get the Patron Interests
	TArray<EStoreType> Interests = Patron->GetInterests();

	// Get the Patron AI Controller
	const APatronAiController* PatronAiController = Cast<APatronAiController>(Patron->GetController());

	if (!PatronAiController)
	{
		UE_LOG(LogTemp, Error, TEXT("Patron AI Controller is nullptr"));
		return;
	}

	// Update the Patron Name Text
	PatronNameText->SetText(FText::FromString(Patron->GetName()));

	// Update the Patron Hunger Text
	PatronHungerText->SetText(FText::FromString(FString::Printf(TEXT("Hunger: %f"), Patron->HungerStatComponent->GetCurrentVal())));

	// Update the Patron Energy Text
	PatronEnergyText->SetText(FText::FromString(FString::Printf(TEXT("Energy: %f"), Patron->EnergyStatComponent->GetCurrentVal())));

	// Update the WalkSpeed Text
	WalkSpeedText->SetText(FText::FromString(FString::Printf(TEXT("Walk Speed: %f"), Patron->WalkingSpeedStatComponent->GetCurrentVal())));

	// Loop through the Traits
	for (int i = 0; i < Traits.Num(); i++)
	{
		// Get the enum name for the trait
		FString TraitName = UEnum::GetValueAsString(Traits[i]);
		// Update the Patron Trait Text
		if (i == 0)
		{
			PatronTrait1Text->SetText(FText::FromString(TraitName));
		}
		else if (i == 1)
		{
			PatronTrait2Text->SetText(FText::FromString(TraitName));
		}
		else if (i == 2)
		{
			PatronTrait3Text->SetText(FText::FromString(TraitName));
		}
	}

	// Loop through the Interests
	for (int i = 0; i < Interests.Num(); i++)
	{
		// Get the enum name for the interest
		FString InterestName = UEnum::GetValueAsString(Interests[i]);
		// Update the Mall Store Interest Text Widgets
		if (i == 0)
		{
			MallStoreInterest1Text->SetText(FText::FromString(InterestName));
		}
		else if (i == 1)
		{
			MallStoreInterest2Text->SetText(FText::FromString(InterestName));
		}
		else if (i == 2)
		{
			MallStoreInterest3Text->SetText(FText::FromString(InterestName));
		}
	}

	if (PatronAiController->GetActions().Num() > 0)
	{

		// Update the first And Current Action Name Text
		const FString ActionName = FString(TEXT("This patron is: ")) + PatronAiController->GetActions()[0]->ActionDef.ActionName;
		TopActionName1Text->SetText(FText::FromString(ActionName));
		CurrentActionNameText->SetText(FText::FromString(ActionName));
		// Update the first And Current Action Target Text

		const FString TargetName = FString(TEXT("This patron is targeting: ")) + PatronAiController->GetActions()[0]->Target->GetName();
		TopActionTarget1Text->SetText(FText::FromString(TargetName));
		CurrentActionTargetText->SetText(FText::FromString(TargetName));
		// Update the first And Current Action Score Text
		TopActionScore1Text->SetText(FText::FromString(FString::Printf(TEXT("Score: %f"), PatronAiController->GetActions()[0]->Score)));
		CurrentActionScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %f"), PatronAiController->GetActions()[0]->Score)));

		// Update the Second Action Name Text
		const FString ActionName1 = FString(TEXT("This patron was considering to: ")) + PatronAiController->GetActions()[1]->ActionDef.ActionName;
		TopActionName2Text->SetText(FText::FromString(ActionName1));
		// Update the Second Action Target Text
		const FString TargetName1 = FString(TEXT("This patron was considering to target: ")) + PatronAiController->GetActions()[1]->Target->GetName();
		TopActionTarget2Text->SetText(FText::FromString(TargetName1));
		// Update the Second Action Score Text
		TopActionScore2Text->SetText(FText::FromString(FString::Printf(TEXT("Score: %f"), PatronAiController->GetActions()[1]->Score)));

		// Update the Third Action Name Text
		const FString ActionName2 = FString(TEXT("This patron was considering to: ")) + PatronAiController->GetActions()[2]->ActionDef.ActionName;
		TopActionName3Text->SetText(FText::FromString(ActionName2));
		// Update the Third Action Target Text
		const FString TargetName2 = FString(TEXT("This patron was considering to target: ")) + PatronAiController->GetActions()[2]->Target->GetName();
		TopActionTarget3Text->SetText(FText::FromString(TargetName2));
		// Update the Third Action Score Text
		TopActionScore3Text->SetText(FText::FromString(FString::Printf(TEXT("Score: %f"), PatronAiController->GetActions()[2]->Score)));

		// Update the Forth Action Name Text
		const FString ActionName3 = FString(TEXT("This patron was considering to: ")) + PatronAiController->GetActions()[3]->ActionDef.ActionName;
		TopActionName4Text->SetText(FText::FromString(ActionName3));
		// Update the Forth Action Target Text
		const FString TargetName3 = FString(TEXT("This patron was considering to target: ")) + PatronAiController->GetActions()[3]->Target->GetName();
		TopActionTarget4Text->SetText(FText::FromString(TargetName3));
		// Update the Forth Action Score Text
		TopActionScore4Text->SetText(FText::FromString(FString::Printf(TEXT("Score: %f"), PatronAiController->GetActions()[3]->Score)));

		// Update the Fifth Action Name Text
		const FString ActionName4 = FString(TEXT("This patron was considering to: ")) + PatronAiController->GetActions()[4]->ActionDef.ActionName;
		TopActionName5Text->SetText(FText::FromString(ActionName4));
		// Update the Fifth Action Target Text
		const FString TargetName4 = FString(TEXT("This patron was considering to target: ")) + PatronAiController->GetActions()[4]->Target->GetName();
		TopActionTarget5Text->SetText(FText::FromString(TargetName4));
		// Update the Fifth Action Score Text
		TopActionScore5Text->SetText(FText::FromString(FString::Printf(TEXT("Score: %f"), PatronAiController->GetActions()[4]->Score)));

	}
	
}
