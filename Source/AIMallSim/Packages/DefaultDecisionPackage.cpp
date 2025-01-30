// Fill out your copyright notice in the Description page of Project Settings.


#include "Packages/DefaultDecisionPackage.h"

#include "ConsiderationManager.h"
#include "DefaultGameMode.h"
#include "Util/StoreTypes.h"
#include "Util/UDecision.h"

bool UDefaultDecisionPackage::InitializeThisPackage(ADefaultGameMode* GameMode)
{

	// ----------------- Decision: Eating -----------------
	UDecision* Eat = NewObject<UDecision>();
	Eat->GetActionDef().ActionName = "Eating";
	Eat->GetActionDef().StoreType = EStoreType::ST_Food;
	Eat->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Hunger"));
	Eat->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Distance"));
	DecisionsInPackages.Add(Eat);

	// ----------------- Decision: Resting -----------------
	UDecision* Rest = NewObject<UDecision>();
	Rest->GetActionDef().ActionName = "Resting";
	Rest->GetActionDef().StoreType = EStoreType::ST_Rest;
	Rest->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Energy"));
	Rest->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Distance"));
	DecisionsInPackages.Add(Rest);


	return true;
}
