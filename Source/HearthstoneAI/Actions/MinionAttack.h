// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseStructs/Action.h"
#include "MinionAttack.generated.h"

/**
 * 
 */
UCLASS()
class HEARTHSTONEAI_API UMinionAttack : public UAction
{
	GENERATED_BODY()
	
public:
	virtual void ApplyAction_Implementation( FBoardState& _boardState ) override;


	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 AttackingMinionIndex;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 TargetMinionIndex;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	bool GoingFace;
};
