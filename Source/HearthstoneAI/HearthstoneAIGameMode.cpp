// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "HearthstoneAI.h"
#include "HearthstoneAIGameMode.h"
#include "HearthstoneAIPlayerController.h"

AHearthstoneAIGameMode::AHearthstoneAIGameMode()
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = AHearthstoneAIPlayerController::StaticClass();
}
