// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CubemonHealthBar.generated.h"


class ACubemon;
/**
 * 
 */
UCLASS()
class HEALTHBAR_API UCubemonHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	ACubemon* Cubemon;
};
