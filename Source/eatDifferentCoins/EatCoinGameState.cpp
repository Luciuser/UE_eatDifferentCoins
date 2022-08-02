// Fill out your copyright notice in the Description page of Project Settings.

#include "EatCoinGameState.h"
#include "eatDifferentCoinsCharacter.h"
#include "Kismet/GameplayStatics.h"

AEatCoinGameState::AEatCoinGameState()
{

}

//void AEatCoinGameState::CoinTest()
//{
//	ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// 获取玩家类
//	AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// 强制类型转换为子类
//
//	if (eatCoinPlayerCharacter->CopperCoinValue >= 5) {
//		this->LevelSuccess = true;
//	}
//}
//
//FText AEatCoinGameState::MissionText(FName CurrentLevelName)
//{
//	if (CurrentLevelName == FName("Level_1")) {
//		return FText::FromString("任务：收集5枚铜币");
//	}
//	if (CurrentLevelName == FName("Level_2")) {
//		return FText::FromString("任务：收集5枚铜币");
//	}
//	if (CurrentLevelName == FName("Level_3")) {
//		return FText::FromString("任务：收集5枚铜币");
//	}
//
//	return FText();
//}

// Called when the game starts or when spawned
void AEatCoinGameState::BeginPlay()
{
	Super::BeginPlay();
}