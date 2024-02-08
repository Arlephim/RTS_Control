// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/AI_ClassGameMode.h"
#include "Core/AI_ClassPlayerController.h"
#include "Core/AI_ClassCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_ClassGameMode::AAI_ClassGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAI_ClassPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}