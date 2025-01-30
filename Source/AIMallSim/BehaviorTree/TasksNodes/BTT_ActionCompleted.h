// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Util/ScoredAction.h"
#include "BTT_ActionCompleted.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UBTT_ActionCompleted : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override final;

	
};
