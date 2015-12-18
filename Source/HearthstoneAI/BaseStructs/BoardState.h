// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Array.h"
#include "BoardState.generated.h"

class UAction;
class UCard;
class UMinion;
/**
*
*/
USTRUCT( BlueprintType )
struct FBoardState
{
	GENERATED_BODY()
public:
	FBoardState();
	FBoardState(FBoardState const& _other);

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	TArray <UMinion*> MyMinions;
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	TArray <UMinion*> EnemyMinions;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	TArray<UCard*> MyHand;
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 EnemyHandCardCount;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 MyHealth;
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 MyArmour;
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 EnemyHealth;
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 EnemyArmour;
};