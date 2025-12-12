// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPIpvmultiGameMode.h"
#include "FPIpvmultiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPIpvmultiGameMode::AFPIpvmultiGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
