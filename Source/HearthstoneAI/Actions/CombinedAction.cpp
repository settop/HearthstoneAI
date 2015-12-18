// Fill out your copyright notice in the Description page of Project Settings.

#include "HearthstoneAI.h"
#include "CombinedAction.h"

void UCombinedAction::ApplyAction_Implementation(FBoardState & _boardState)
{
	for (UAction* subAction : SubActions)
	{
		subAction->ApplyAction(_boardState);
	}
}

void UCombinedAction::AddSubAction(UAction * _action)
{
	SubActions.Add(_action);
}
