// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EatCoinGameState.generated.h"

/**
 * װ��ÿһ�ص�ͨ����������Ӧ����
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	AEatCoinGameState();
	
	UPROPERTY(EditAnywhere)
		bool LevelSuccess = false; // ��ǰ�ؿ��Ƿ�ɹ���Ĭ��Ϊfalse

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void CoinTest();
};
