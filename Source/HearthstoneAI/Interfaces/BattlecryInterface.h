// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseStructs/BoardState.h"
#include "BattlecryInterface.generated.h"

/**
*
*/
UINTERFACE(Blueprintable)
class UBattlecry : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IBattlecry
{
	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hearthstone Actions", meta=(Tooltip="Get the avaliable actions when a minion is played, these actions are applied after a minion is summoned.\nThe board state is the current board state before the minion is played.\nThe summon position is the position the minion will be summoned at"))
	void GetAvaliableBattlecryActions(int32 _minionSummonPosition, FBoardState const& _boardState, UPARAM(ref) TArray<UAction*>& _actions);
};