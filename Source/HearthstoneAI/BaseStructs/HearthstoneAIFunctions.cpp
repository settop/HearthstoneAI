// Fill out your copyright notice in the Description page of Project Settings.

#include "HearthstoneAI.h"
#include "HearthstoneAIFunctions.h"


float UHearthstoneAIFunctions::GetScore( FBoardState const& _boardState, FScoreData const& _scoreData )
{
	return 0.f;
}

TArray<UAction*> UHearthstoneAIFunctions::GetPossibleActions( FBoardState const& _boardState )
{
	return TArray<UAction*>();
}

float UHearthstoneAIFunctions::GetMyHealthScoreValue( FScoreData const& _scoreData, int32 _myCurrentHealth, int32 _myCurrentArmour )
{
	return _scoreData.MyHealthScoreBaseValue * FMath::Pow( (float)(_myCurrentHealth + _myCurrentArmour) / (float)FScoreData::DefaultHealth, _scoreData.MyHealthScoreExponent );
}

float UHearthstoneAIFunctions::GetEnemyHealthScoreValue( FScoreData const& _scoreData, int32 _enemyCurrentHealth, int32 _enemyCurrentArmour )
{
	int32 enemyTotalHealth = _enemyCurrentHealth + _enemyCurrentArmour;
	if( enemyTotalHealth == 0 )
	{
		//they are dead, inflate this higher to enure we don't miss lethal
		return _scoreData.EnemyLethalScore;
	}
	else
	{
		int32 missingHealth = FScoreData::DefaultHealth - enemyTotalHealth;
		return _scoreData.EnemyHealthScoreDeadValue * FMath::Pow( (float)missingHealth / (float)FScoreData::DefaultHealth, _scoreData.EnemyHealthScoreExponent );
	}
}

float UHearthstoneAIFunctions::GetMyHandScore( FScoreData const& _scoreData, int32 _numCards )
{
	if( _numCards == FScoreData::MaxHandSize )
	{
		return _scoreData.MyFullHandCardScore;
	}
	else
	{
		return _numCards * _scoreData.MyCardHandScore;
	}
}

float UHearthstoneAIFunctions::GetEnemyHandScore( FScoreData const& _scoreData, int32 _numCards )
{
	if( _numCards == FScoreData::MaxHandSize )
	{
		return _scoreData.EnemyFullHandCardScore;
	}
	else
	{
		return _numCards * _scoreData.EnemyCardHandScore;
	}
}
