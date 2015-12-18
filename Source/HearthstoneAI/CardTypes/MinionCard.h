// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseStructs/Card.h"
#include "MinionCard.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEARTHSTONEAI_API UMinionCard : public UCard
{
	GENERATED_BODY()	
public:
	virtual void GetAvaliableActions_Implementation(FBoardState const& _currentBoardState, TArray<UAction*>& _actions);
	

	UFUNCTION(BlueprintPure, Category = "Hearthstone Actions")
	static int32 GetFriendlyMinionIndexAfterSummon(int32 _currentIndex, int32 _summonIndex);
};
