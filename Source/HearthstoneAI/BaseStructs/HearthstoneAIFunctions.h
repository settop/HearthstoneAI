// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BoardState.h"
#include "ScoreData.h"
#include "Action.h"
#include "HearthstoneAIFunctions.generated.h"

/**
 * 
 */
UCLASS()
class UHearthstoneAIFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	UFUNCTION( BlueprintCallable, Category = "Hearthstone AI" )
	static float GetScore( FBoardState const& _boardState, FScoreData const& _scoreData );
	UFUNCTION( BlueprintCallable, Category = "Hearthstone AI" )
	static TArray<UAction*> GetPossibleActions( FBoardState const& _boardState );

	UFUNCTION( BlueprintCallable, Category = "Hearthstone AI" )
	static float GetMyHealthScoreValue( FScoreData const& _scoreData, int32 _myCurrentHealth, int32 _myCurrentArmour );
	UFUNCTION( BlueprintCallable, Category = "Hearthstone AI" )
	static float GetEnemyHealthScoreValue( FScoreData const& _scoreData, int32 _enemyCurrentHealth, int32 _enemyCurrentArmour );

	UFUNCTION( BlueprintCallable, Category = "Hearthstone AI" )
	static float GetMyHandScore( FScoreData const& _scoreData, int32 _numCards );
	UFUNCTION( BlueprintCallable, Category = "Hearthstone AI" )
	static float GetEnemyHandScore( FScoreData const& _scoreData, int32 _numCards );
};
