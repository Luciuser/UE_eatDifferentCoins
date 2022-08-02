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

	// ��ʼ��Ϸ
	UFUNCTION()
		void GameStart();

	// ��ȡ��Ϸ
	UFUNCTION()
		void GameLoad();

	// �˳���Ϸ
	UFUNCTION()
		void GameQuit();

	FName FirstLevel = FName("Level_1");	// ��һ�عؿ�

};
