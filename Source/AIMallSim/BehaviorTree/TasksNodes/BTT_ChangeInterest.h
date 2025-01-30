// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ChangeInterest.generated.h"

/**
 * 
 */
UCLASS()
class AIMALLSIM_API UBTT_ChangeInterest : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override final;

protected:
	virtual uint16 GetInstanceMemorySize() const override;
};
