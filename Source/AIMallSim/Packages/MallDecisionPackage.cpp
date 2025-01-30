// Fill out your copyright notice in the Description page of Project Settings.


#include "Packages/MallDecisionPackage.h"

#include "ConsiderationManager.h"
#include "DefaultGameMode.h"
#include "Util/StoreTypes.h"
#include "Util/UDecision.h"

bool UMallDecisionPackage::InitializeThisPackage(ADefaultGameMode* GameMode)
{
	// ----------------- Decision: Shopping -----------------
	UDecision* Shop = NewObject<UDecision>();
	Shop->GetActionDef().ActionName = "Shopping";
	Shop->GetActionDef().StoreType = EStoreType::ST_Store;
	Shop->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("ShopDesire"));
	DecisionsInPackages.Add(Shop);

	// ----------------- Decision: Leaving -----------------
	//UDecision* Leave = NewObject<UDecision>();
	//Leave->GetActionDef().ActionName = "Leaving";
	//Leave->GetActionDef().StoreType = EStoreType::ST_Exit;
	//Leave->AddConsideration(GameMode->GetConsiderationManager()->GetConsideration("Leave"));
	//DecisionsInPackages.Add(Leave);

	return true;
}
