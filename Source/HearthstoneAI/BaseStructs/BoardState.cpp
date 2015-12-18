// Fill out your copyright notice in the Description page of Project Settings.

#include "HearthstoneAI.h"
#include "Card.h"
#include "Minion.h"
#include "BoardState.h"

template<typename T>
TArray<T*> CopyUObjectArray(TArray<T*> const& _otherArray)
{
	TArray<T*> ret;
	ret.Reserve(_otherArray.Num());
	for (T const* otherObject : _otherArray)
	{
		ret.Add(DuplicateObject(otherObject, otherObject->GetOuter()));
	}
	return ret;
}

FBoardState::FBoardState()
{}

FBoardState::FBoardState(FBoardState const& _other) : 
	MyMinions(CopyUObjectArray(_other.MyMinions)),
	EnemyMinions(CopyUObjectArray(_other.MyMinions)),
	MyHand(CopyUObjectArray(_other.MyHand)),
	EnemyHandCardCount(_other.EnemyHandCardCount),
	MyHealth(_other.MyHealth),
	MyArmour(_other.MyArmour),
	EnemyHealth(_other.EnemyHealth),
	EnemyArmour(_other.EnemyArmour)
{
	
}