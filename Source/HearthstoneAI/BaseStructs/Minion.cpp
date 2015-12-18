// Fill out your copyright notice in the Description page of Project Settings.

#include "HearthstoneAI.h"
#include "Action.h"
#include "Minion.h"



UMinion* UMinion::CreateMinion(FCardData const & _cardData)
{
	UClass* c = UMinion::StaticClass();
	if (*_cardData.MinionClass)
	{
		c = *_cardData.MinionClass;
	}
	UMinion* newMinion = NewObject<UMinion>((UObject*)GetTransientPackage(), c);

	newMinion->InitMinion(_cardData);
	return newMinion;
}

void UMinion::InitMinion_Implementation(FCardData const & _cardData)
{
	CardData = _cardData;

	MaxAttacksPerTurn = _cardData.Mechanics.Contains("Windfury") ? 2u : 1u;
	AvaliableAttacks = _cardData.Mechanics.Contains("Charge") ? MaxAttacksPerTurn : 0u;

	MaxHealth = _cardData.Health;
	CurrentHealth = MaxHealth;

	Attack = _cardData.Attack;
}

void UMinion::GetAvaliableActions_Implementation(FBoardState const & _currentBoardState, TArray<UAction*>& _actions)
{
	if(AvaliableAttacks > 0)
	{
		GetAttackActions(_currentBoardState, _actions);
	}
}

void UMinion::GetAttackActions(FBoardState const & _currentBoardState, UPARAM(ref)TArray<UAction*>& _actions)
{

}
