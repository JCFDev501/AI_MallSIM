// Fill out your copyright notice in the Description page of Project Settings.


#include "Packages/WorkDecisionPackage.h"

#include "ConsiderationManager.h"
#include "DefaultGameMode.h"
#include "Util/StoreTypes.h"
#include "Util/UDecision.h"

bool UWorkDecisionPackage::InitializeThisPackage(ADefaultGameMode* GameMode)
{
	// ----------------- Decision: Work -----------------
	UDecision* Work = NewObject<UDecision>();
	Work->GetActionDef().ActionName = "Working";
	Work->GetActionDef().StoreType = EStoreType::ST_Work;
	Work->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Work"));
	DecisionsInPackages.Add(Work);


	return true;
}
