// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EatCoinGameState.generated.h"

/**
 * 装载每一关的通关条件和相应数据
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	AEatCoinGameState();
	
	UPROPERTY(EditAnywhere)
		bool LevelSuccess = false; // 当前关卡是否成功，默认为false

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void CoinTest();
};
