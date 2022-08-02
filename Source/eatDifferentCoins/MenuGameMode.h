// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API AMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMenuGameMode();

	// 开始游戏
	UFUNCTION()
		void GameStart();

	// 读取游戏
	UFUNCTION()
		void GameLoad();

	// 退出游戏
	UFUNCTION()
		void GameQuit();

	FName FirstLevel = FName("Level_1");	// 第一关关卡

};
