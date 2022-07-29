// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EatCoinGameMode.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEatCoinGameMode();
	
	UPROPERTY(EditAnywhere)
		bool LevelSuccess = false; // 当前关卡是否成功，默认为false

	UFUNCTION()
		void CoinTest(FName CurrentLevelName);

	UFUNCTION()
		FText MissionText(FName CurrentLevelName);
};
