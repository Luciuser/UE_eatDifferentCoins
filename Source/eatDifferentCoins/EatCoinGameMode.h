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
	
	// 硬币测试函数，判断关卡是否成功
	UFUNCTION()
		void CoinTest(FName CurrentLevelName);

	// 重启当前关卡
	UFUNCTION()
		void GameLevelRestart();

	// 读取游戏
	UFUNCTION()
		void GameLoad();

	// 保存游戏
	UFUNCTION()
		void GameSave();

	// 退出游戏
	UFUNCTION()
		void GameQuit();

	// 暂停游戏
	UFUNCTION()
		void GamePause();

	// 打开提示
	UFUNCTION()
		void GameOpenTips();

	// 不同关卡的任务文本数据
	UFUNCTION()
		FText MissionText(FName CurrentLevelName);

	// 不同关卡的关卡文本数据
	UFUNCTION()
		FText MissionCurretLevel(FName CurrentLevelName);

	UPROPERTY(EditAnywhere)
		bool LevelSuccess = false; // 当前关卡是否成功，默认为false

	UPROPERTY(EditAnywhere)
		bool bPause = false;	// 判断是否暂停
	UPROPERTY(EditAnywhere)
		bool bTips = false;	// 判断是否打开tips
};
