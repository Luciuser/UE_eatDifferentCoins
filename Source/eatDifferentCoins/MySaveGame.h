// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UMySaveGame();

	UPROPERTY(EditAnywhere)
		int CoinValue;	// 需要保存的总钱币价值
	UPROPERTY(EditAnywhere)
		FName CurrentLevel = FName("Game_Menu");	// 当前关卡名，默认为 Game_Menu
};
