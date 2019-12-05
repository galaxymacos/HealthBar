// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProximityMine.generated.h"

UCLASS()
class HEALTHBAR_API AProximityMine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProximityMine();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, Category = "Explosion")
	class USphereComponent* rangeDetector;

	UPROPERTY(EditAnywhere, Category = "Explosion")
		int ExplosionRange;

	UPROPERTY(EditAnywhere, Category = "Explosion")
		float ExplosionDelay;

	UPROPERTY(EditAnywhere, Category = "Explosion")
		UParticleSystem* Explosion;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void DestroyMine(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


private:
	bool isMineStarted = false;
	float ExplosionTimeRemains;
	bool isPlayerInRange;
	class AHealthBarCharacter* player;
};


