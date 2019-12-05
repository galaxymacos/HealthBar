// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "Components/StaticMeshComponent.h"
#include "HealthBarCharacter.h"
#include "GameFramework/Controller.h"

// Sets default values
ALaunchPad::ALaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(StaticMesh);

	
}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaunchPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AHealthBarCharacter* player = Cast<AHealthBarCharacter>(OtherActor);
	if(player != nullptr)
	{
		player->LaunchCharacter(FVector(0, 0, 1000), false, false);
		
		
	}
}

