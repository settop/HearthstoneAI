// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseStructs/Action.h"
#include "CardData.h"
#include "SummonMinion.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEARTHSTONEAI_API USummonMinion : public UAction
{
	GENERATED_BODY()		
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Position;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FCardData CardData;
};
