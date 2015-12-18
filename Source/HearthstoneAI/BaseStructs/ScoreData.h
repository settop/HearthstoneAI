// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ScoreData.generated.h"

/**
*
*/
USTRUCT( BlueprintType )
struct FScoreData
{
	GENERATED_BODY()

	static int32 const DefaultHealth = 30;
	static int32 const MaxHandSize = 10;
	static int32 const MaxMinions = 7;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip ="This is the amount of score you have when at max health (i.e. 30 health no armour)" ) )
	float MyHealthScoreBaseValue;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "Raises the health score to the power of this value. < 1 means health is more valuable the less you have") )
	float MyHealthScoreExponent;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "This is the amount of score you have when the enemy is close to dead (i.e. 0 health no armour)") )
	float EnemyHealthScoreDeadValue;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "Raises the health score to the power of this value. > 1 means missing health is more valuable the less health they have") )
	float EnemyHealthScoreExponent;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score returned when the other player is dead. Suggest 2*EnemyScoreDeadValue") )
	float EnemyLethalScore;
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score for each card in your hand") )
	float MyCardHandScore;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score you have when you have a full hand") )
	float MyFullHandCardScore;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score you get each time you burn one of your cards") )
	float MyBurnedCardScore;
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score for each card in the enemies hand") )
	float EnemyCardHandScore;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score you have when the enemy has a full hand") )
	float EnemyFullHandCardScore;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "The score you get each time you burn one of your enemies cards") )
	float EnemyBurnedCardScore;
};