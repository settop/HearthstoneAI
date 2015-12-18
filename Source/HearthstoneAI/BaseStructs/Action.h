// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BoardState.h"
#include "Action.generated.h"

/**
 * 
 */
UCLASS( abstract, Blueprintable )
class HEARTHSTONEAI_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable, BlueprintNativeEvent, Category="Hearthstone Actions" )
	void ApplyAction( UPARAM( ref ) FBoardState& _boardState );
	virtual void ApplyAction_Implementation(FBoardState& _boardState);
};
