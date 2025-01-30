// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * This enum represents the store type.
 */
UENUM(BlueprintType)
enum class EStoreType : uint8
{
	ST_Gaming UMETA(DisplayName = "Gaming"),
	ST_Clothing UMETA(DisplayName = "Clothing"),
	ST_Hardware UMETA(DisplayName = "Hardware"),
	ST_Pharmacy  UMETA(DisplayName = "Pharmacy "),
	ST_Electronics  UMETA(DisplayName = "Electronics "),
	ST_Furniture  UMETA(DisplayName = "Furniture "),
	ST_Toy  UMETA(DisplayName = "Toy "),
	ST_Jewelry  UMETA(DisplayName = "Jewelry"),
	ST_SportingGoods UMETA(DisplayName = "SportingGoods"),
	ST_Thrift  UMETA(DisplayName = "Thrift"),
	ST_Books UMETA(DisplayName = "Books"),

	ST_Store UMETA(DisplayName = "Store"),
	ST_Food UMETA(DisplayName = "Food"), // Todo: Maybe we should have a separate class for this
	ST_Rest UMETA(DisplayName = "Rest"), // Todo: Maybe we should have a separate class for this
	ST_Exit UMETA(DisplayName = "Exit"),
	ST_Home UMETA(DisplayName = "Home"),
	ST_Work UMETA(DisplayName = "Work"),
	ST_Yard UMETA(DisplayName = "Yard")
};
