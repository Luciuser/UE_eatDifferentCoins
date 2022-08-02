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
	
	// Ӳ�Ҳ��Ժ������жϹؿ��Ƿ�ɹ�
	UFUNCTION()
		void CoinTest(FName CurrentLevelName);

	// ������ǰ�ؿ�
	UFUNCTION()
		void GameLevelRestart();

	// ��ȡ��Ϸ
	UFUNCTION()
		void GameLoad();

	// ������Ϸ
	UFUNCTION()
		void GameSave();

	// �˳���Ϸ
	UFUNCTION()
		void GameQuit();

	// ��ͣ��Ϸ
	UFUNCTION()
		void GamePause();

	// ����ʾ
	UFUNCTION()
		void GameOpenTips();

	// ��ͬ�ؿ��������ı�����
	UFUNCTION()
		FText MissionText(FName CurrentLevelName);

	// ��ͬ�ؿ��Ĺؿ��ı�����
	UFUNCTION()
		FText MissionCurretLevel(FName CurrentLevelName);

	UPROPERTY(EditAnywhere)
		bool LevelSuccess = false; // ��ǰ�ؿ��Ƿ�ɹ���Ĭ��Ϊfalse

	UPROPERTY(EditAnywhere)
		bool bPause = false;	// �ж��Ƿ���ͣ
	UPROPERTY(EditAnywhere)
		bool bTips = false;	// �ж��Ƿ��tips
};
