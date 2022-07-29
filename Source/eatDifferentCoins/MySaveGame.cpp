// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

UMySaveGame::UMySaveGame() 
{
	// 从 GameInstance 获取数据
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	if (MyGameInstance != nullptr) {
		this->CoinValue = MyGameInstance->CoinValue;
	}
}