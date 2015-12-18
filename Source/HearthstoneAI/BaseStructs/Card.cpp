// Fill out your copyright notice in the Description page of Project Settings.

#include "HearthstoneAI.h"
#include "Card.h"
#include "CardTypes/MinionCard.h"

UCard * UCard::CreateCard(FCardData const & _cardData)
{
	UClass* c = nullptr;

	if (_cardData.Type == "Minion")
	{
		c = UMinionCard::StaticClass();
	}
	//else if ()
	//{
	//
	//}

	if (*_cardData.CardType)
	{
		c = *_cardData.CardType;
	}
	verifyf(c, TEXT("Unable to find valid card type for card. Card: %s Card Type: %s"), _cardData.Name.GetPlainWIDEString(), _cardData.Type.GetPlainWIDEString());
	UCard* newCard = NewObject<UCard>((UObject*)GetTransientPackage(), c);

	newCard->InitCard(_cardData);
	return newCard;
}

void UCard::InitCard_Implementation(FCardData const & _cardData)
{
	CardData = _cardData;
	ManaCost = _cardData.Cost;
}

void UCard::GetAvaliableActions_Implementation(FBoardState const & _currentBoardState, TArray<UAction*>& _actions)
{
}
