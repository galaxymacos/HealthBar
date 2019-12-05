// Fill out your copyright notice in the Description page of Project Settings.


#include "Caltrop.h"
#include "HealthBarCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ACaltrop::ACaltrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(StaticMesh);


}

// Called when the game starts or when spawned
void ACaltrop::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ACaltrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACaltrop::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AHealthBarCharacter* player = Cast<AHealthBarCharacter>(OtherActor);
	if(player != nullptr)
	{
		player->HealthPercentage -= 0.1f;
		Destroy();	
	}
}

