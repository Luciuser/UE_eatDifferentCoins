// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EatCoinPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AEatCoinPlayerController();

protected:

	virtual void BeginPlay() override;

public:

	// 保存游戏函数
	void Save();

	// 退出游戏函数
	void Load();
};
