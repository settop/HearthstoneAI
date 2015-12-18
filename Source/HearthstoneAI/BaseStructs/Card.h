// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BoardState.h"
#include "CardData.h"
#include "Card.generated.h"

/**
 * 
 */
UCLASS( Blueprintable, Abstract )
class HEARTHSTONEAI_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Hearthstone Actions")
	static UCard* CreateCard(FCardData const& _cardData);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hearthstone Actions")
	void InitCard(FCardData const& _cardData);
	virtual void InitCard_Implementation(FCardData const& _cardData);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hearthstone Actions")
	void GetAvaliableActions(FBoardState const& _currentBoardState, UPARAM(ref) TArray<UAction*>& _actions);
	virtual void GetAvaliableActions_Implementation(FBoardState const& _currentBoardState, TArray<UAction*>& _actions);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FCardData CardData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ManaCost;
	
};
