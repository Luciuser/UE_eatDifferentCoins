// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EatCoinGameState.generated.h"

/**
 *
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	AEatCoinGameState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
