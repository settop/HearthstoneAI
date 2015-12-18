// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "CardData.generated.h"

class UCard;
class UMinion;
/**
 * 
 */
USTRUCT( BlueprintType )
struct FCardData : public FTableRowBase
{
	GENERATED_BODY()
public:
	FCardData();

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = ID )
	FName ID;
	//fluff data to decorate the card
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Fluff )
	FName Name;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Fluff )
	FName Text;

	//stats of the card
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	int32 Cost;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	int32 Attack;	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	int32 Health;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	int32 Durability;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	TArray<FName> Mechanics;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	FName Type;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	FName Race;

	//data about this cards code spcialiation if it has one
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Specialisation)
	TSubclassOf<UMinion> MinionClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Specialisation)
	TSubclassOf<UCard> CardType;
};
