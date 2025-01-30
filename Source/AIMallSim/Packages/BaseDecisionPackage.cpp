// Fill out your copyright notice in the Description page of Project Settings.


#include "Packages/BaseDecisionPackage.h"

void UBaseDecisionPackage::SuppressPackage(bool bIsThisPackageSuppressed)
{
	if (bIsThisPackageSuppressed)
		bSuppressed = true;
	else
		bSuppressed = false;
}
