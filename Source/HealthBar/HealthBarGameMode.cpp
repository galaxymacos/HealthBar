// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HealthBarGameMode.h"
#include "HealthBarHUD.h"
#include "HealthBarCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHealthBarGameMode::AHealthBarGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHealthBarHUD::StaticClass();
}
