// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "HearthstoneAI.h"
#include "HearthstoneAIPlayerController.h"

AHearthstoneAIPlayerController::AHearthstoneAIPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
