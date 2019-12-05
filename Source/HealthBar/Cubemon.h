// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cubemon.generated.h"

UCLASS()
class HEALTHBAR_API ACubemon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubemon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HP = 1.f;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* HeadMesh;

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* FloatingHealthBar;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	
};
