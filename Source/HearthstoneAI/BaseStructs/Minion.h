// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BoardState.h"
#include "CardData.h"
#include "Minion.generated.h"

class UAction;
/**
 * 
 */
UCLASS( Blueprintable )
class HEARTHSTONEAI_API UMinion : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Hearthstone Actions")
	static UMinion* CreateMinion(FCardData const& _cardData);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hearthstone Actions")
	void InitMinion(FCardData const& _cardData);
	virtual void InitMinion_Implementation(FCardData const& _cardData);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hearthstone Actions")
	void GetAvaliableActions(FBoardState const& _currentBoardState, UPARAM(ref) TArray<UAction*>& _actions);
	virtual void GetAvaliableActions_Implementation(FBoardState const& _currentBoardState, TArray<UAction*>& _actions);

	UFUNCTION(BlueprintCallable, Category = "Hearthstone Actions")
	void GetAttackActions(FBoardState const& _currentBoardState, UPARAM(ref) TArray<UAction*>& _actions);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FCardData CardData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAttacksPerTurn;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 AvaliableAttacks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack; 	
};
