// Fill out your copyright notice in the Description page of Project Settings.


#include "Considerations/ShopDesireConsideration.h"

#include "Patron.h"
#include "Stores/StoreBase.h"
#include "Util/DecisionContext.h"

float UShopDesireConsideration::Score(const FDecisionContext& Context)
{
	const APatron* Patron = Cast<APatron>(Context.Actor);
	const AStoreBase* Store = Cast<AStoreBase>(Context.Target);

    if (Patron && Store && Patron->GetCurrentInterest() == Store->GetStoreType())
    {
        return 0.5f;  // Max utility if the store matches the current interest
    }
    return 0.0f;  // No utility if there is no interest match
}
