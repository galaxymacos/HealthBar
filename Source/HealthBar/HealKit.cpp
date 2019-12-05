// Fill out your copyright notice in the Description page of Project Settings.


#include "HealKit.h"
#include "Components/StaticMeshComponent.h"
#include "HealthBarCharacter.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHealKit::AHealKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AHealKit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator rotator(0, 10 * DeltaTime, 0);
	AddActorLocalRotation(rotator);
}

void AHealKit::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AHealthBarCharacter* player = Cast<AHealthBarCharacter>(OtherActor);
	if (player)
	{
		player->GenerateHealthTillFull(0.1f);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), pickupSound, GetActorLocation(), GetActorRotation());
		Destroy();
		
	}
}

