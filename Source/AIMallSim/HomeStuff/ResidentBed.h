// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Util/ResidentSlot.h"
#include "ResidentBed.generated.h"

UCLASS()
class AIMALLSIM_API AResidentBed : public AActor
{
	GENERATED_BODY()

	// Static Mesh for store Visual
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BedMesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BedMesh;

	// Our Store Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ResidentSlot", meta = (AllowPrivateAccess = "true"))
	AResidentSlot* ResidentSlot;
	
public:	
	// Sets default values for this actor's properties
	AResidentBed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AResidentSlot* GetResidentSlot() const { return ResidentSlot; }

};
