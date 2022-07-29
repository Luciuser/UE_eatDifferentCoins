// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

//#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Green,*(String));}}

UMySaveGame::UMySaveGame() 
{
	// 从 GameInstance 获取数据
	//UWorld* world = GetWorld();
	//UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	//if (MyGameInstance != nullptr) {
	//	this->CoinValue = MyGameInstance->CoinValue;
	//	this->CurrentLevel = MyGameInstance->CurrentLevel;
	//	PRINT(MyGameInstance->CurrentLevel.ToString());
	//	PRINT(this->CurrentLevel.ToString());
	//}
}