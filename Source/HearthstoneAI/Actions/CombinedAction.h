// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseStructs/Action.h"
#include "CombinedAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEARTHSTONEAI_API UCombinedAction : public UAction
{
	GENERATED_BODY()
public:

	virtual void ApplyAction_Implementation(FBoardState& _boardState);	

	UFUNCTION(BlueprintCallable, Category = "Hearthstone Actions")
	void AddSubAction(UAction* _action);

	TArray<UAction*, TInlineAllocator<2>> SubActions;
};
