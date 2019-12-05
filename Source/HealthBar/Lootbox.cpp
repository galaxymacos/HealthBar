// Fill out your copyright notice in the Description page of Project Settings.


#include "Lootbox.h"
#include "Engine/Engine.h"

// Sets default values
ALootbox::ALootbox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALootbox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALootbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALootbox::PickUpItem()
{
	float random = FMath::RandRange(0, 1);
	if (GEngine)
	{
		if (random < CommonItem)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You receive a common item!"));
		}
		else if(random < RareItem)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You receive a rare item!"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You receive a legendary item!"));
		}
	}
	
}

