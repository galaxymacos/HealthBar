// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubemon.h"
#include "WidgetComponent.h"
#include "CubemonHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "HealthBarProjectile.h"
#include "Engine/Engine.h"

// Sets default values
ACubemon::ACubemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);
	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(StaticMesh);
	
	FloatingHealthBar = CreateDefaultSubobject<UWidgetComponent>("FloatingHealthBar");
	FloatingHealthBar->SetCollisionResponseToAllChannels(ECR_Ignore);
	FloatingHealthBar->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	
}

// Called when the game starts or when spawned
void ACubemon::BeginPlay()
{
	Super::BeginPlay();
	Cast<UCubemonHealthBar>(FloatingHealthBar->GetUserWidgetObject())->Cubemon = this;
}

// Called every frame
void ACubemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//
	//
	APlayerCameraManager* camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	FloatingHealthBar->SetWorldRotation(camera->GetCameraRotation());
	FloatingHealthBar->AddLocalRotation(FRotator(0, 180, 0));
	if(HP <= 0.f)
	{
		Destroy();
	}
}


void ACubemon::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AHealthBarProjectile* projectile = Cast<AHealthBarProjectile>(Other);
	if (projectile != nullptr)
	{

		HP -= 0.1f;
		if (HP <= 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("destroy box"));
			Destroy();
		}
	}
}

