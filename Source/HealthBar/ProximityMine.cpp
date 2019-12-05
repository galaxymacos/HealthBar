// Fill out your copyright notice in the Description page of Project Settings.


#include "ProximityMine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "HealthBarCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "HealthBarProjectile.h"
#include "Engine/Engine.h"

// Sets default values
AProximityMine::AProximityMine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetSimulatePhysics(true);
	StaticMesh->SetNotifyRigidBodyCollision(true);
	StaticMesh->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	StaticMesh->OnComponentHit.AddDynamic(this, &AProximityMine::DestroyMine);
	SetRootComponent(StaticMesh);

	rangeDetector = CreateDefaultSubobject<USphereComponent>("RangeDetector");
	rangeDetector->SetCollisionResponseToAllChannels(ECR_Overlap);
	rangeDetector->InitSphereRadius(220);
	rangeDetector->SetupAttachment(RootComponent);
	ExplosionTimeRemains = 5;

}

// Called when the game starts or when spawned
void AProximityMine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProximityMine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(isMineStarted)
	{
		ExplosionTimeRemains -= DeltaTime;
		if(ExplosionTimeRemains<=0)
		{
			if (isPlayerInRange)
			{
				player->HealthPercentage -= 0.3f;
			}
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetActorLocation(), GetActorRotation());
			Destroy();
		}
	}
}

void AProximityMine::NotifyActorBeginOverlap(AActor* OtherActor)
{
	player = Cast<AHealthBarCharacter>(OtherActor);
	if (player != nullptr)
	{
		isPlayerInRange = true;
		if(!isMineStarted)
		{
			isMineStarted = true;
		}
	}
}

void AProximityMine::NotifyActorEndOverlap(AActor* OtherActor)
{
	player = Cast<AHealthBarCharacter>(OtherActor);
	if (player != nullptr)
	{
		isPlayerInRange = false;

	}
}

void AProximityMine::DestroyMine(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	AHealthBarProjectile* projectile = Cast<AHealthBarProjectile>(OtherActor);
	if(projectile != nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("I just hit something"));
		}
		Destroy();
	}
	
	

}



