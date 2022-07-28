// Copyright Epic Games, Inc. All Rights Reserved.

#include "eatDifferentCoinsGameMode.h"
#include "eatDifferentCoinsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AeatDifferentCoinsGameMode::AeatDifferentCoinsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
