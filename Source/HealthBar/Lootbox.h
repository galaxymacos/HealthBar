// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lootbox.generated.h"

UCLASS()
class HEALTHBAR_API ALootbox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootbox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropProbability")
	float CommonItem = 0.6f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropProbability")
	float RareItem = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropProbability")
	float LegendaryItem = 0.1f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PickUpItem();
};
