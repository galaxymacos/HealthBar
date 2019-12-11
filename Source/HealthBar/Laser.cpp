// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"
#include "Components/StaticMeshComponent.h"
#include "Cubemon.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(StaticMesh);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(StaticMesh);
	ProjectileMovementComponent->InitialSpeed = 3000.f;
	ProjectileMovementComponent->MaxSpeed = 3000.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
	currentDamage = initialDamage;
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaser::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto cubemon = Cast<ACubemon>(OtherActor);
	if(cubemon != nullptr)
	{
		cubemon->HP -= currentDamage;
		currentDamage /= 2;
		
	}
}

void ALaser::FireInDirection(const FVector& ShootDirection)
{
	// ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;	
}

