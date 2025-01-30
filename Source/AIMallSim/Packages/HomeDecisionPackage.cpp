// Fill out your copyright notice in the Description page of Project Settings.


#include "Packages/HomeDecisionPackage.h"

#include "ConsiderationManager.h"
#include "DefaultGameMode.h"
#include "Util/StoreTypes.h"
#include "Util/UDecision.h"

bool UHomeDecisionPackage::InitializeThisPackage(ADefaultGameMode* GameMode)
{
	// ----------------- Decision: Sleep -----------------
	UDecision* Home = NewObject<UDecision>();
	Home->GetActionDef().ActionName = "Sleeping";
	Home->GetActionDef().StoreType = EStoreType::ST_Home;
	Home->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Sleep"));
	DecisionsInPackages.Add(Home);

	return true;
}
