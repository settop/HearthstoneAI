// Fill out your copyright notice in the Description page of Project Settings.

#include "HearthstoneAI.h"
#include "Actions/CombinedAction.h"
#include "Actions/SummonMinion.h"
#include "BaseStructs/ScoreData.h"
#include "Interfaces/BattlecryInterface.h"
#include "MinionCard.h"

void UMinionCard::GetAvaliableActions_Implementation(FBoardState const & _currentBoardState, TArray<UAction*>& _actions)
{
	if (_currentBoardState.MyMinions.Num() >= FScoreData::MaxMinions)
	{
		//board is full, cant summon anything
		return;
	}
	int32 summonPosition = _currentBoardState.MyMinions.Num();

	USummonMinion* summonMinionAction = NewObject<USummonMinion>();
	summonMinionAction->Position = summonPosition;
	summonMinionAction->CardData = CardData;

	if (IBattlecry* battlecryIF = Cast<IBattlecry>(this))
	{
		TArray<UAction*> battlecryActions;
		battlecryIF->GetAvaliableBattlecryActions(summonPosition, _currentBoardState, battlecryActions);
		_actions.Reserve(_actions.Num() + battlecryActions.Num());
		for (UAction* battlecryAction : battlecryActions)
		{
			UCombinedAction* combinedAction = NewObject<UCombinedAction>();
			combinedAction->SubActions.Add(summonMinionAction);
			combinedAction->SubActions.Add(battlecryAction);
			_actions.Add(combinedAction);
		}
	}
	else
	{
		_actions.Add(summonMinionAction);
	}
}

int32 UMinionCard::GetFriendlyMinionIndexAfterSummon(int32 _currentIndex, int32 _summonIndex)
{
	if (_currentIndex < _summonIndex)
	{
		return _currentIndex;
	}
	else
	{
		return _currentIndex + 1;
	}
}
