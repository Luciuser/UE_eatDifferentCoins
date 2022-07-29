// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "EatCoinGameMode.h"
#include "EatCoinPlayerController.h"
#include "EatCoinGameState.h"
#include "eatDifferentCoinsCharacter.h"
#include "EatCoinHUD.h"
#include "EatCoinGameState.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "EAT_COIN"

AEatCoinGameMode::AEatCoinGameMode()
{
	// 设置新的 GamePlayerController 和 GameState
	GameStateClass = AEatCoinGameState::StaticClass();
	PlayerControllerClass = AEatCoinPlayerController::StaticClass();
	HUDClass = AEatCoinHUD::StaticClass();
}

void AEatCoinGameMode::CoinTest(FName CurrentLevelName)
{
	ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// 获取玩家类
	AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// 强制类型转换为子类

	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())); // 获取当前GameInstance

	if (CurrentLevelName == FName("Level_1")) {
		if (eatCoinPlayerCharacter->CopperCoinValue >= 5) {
			this->LevelSuccess = true;
		}
	}
	if (CurrentLevelName == FName("Level_2")) {
		if (eatCoinPlayerCharacter->SliverCoinValue >= 5 || eatCoinPlayerCharacter->GoldCoinValue >= 3) {
			this->LevelSuccess = true;
		}
	}
	if (CurrentLevelName == FName("Level_3")) {
		if (MyGameInstance->CoinValue >= 20) {
			this->LevelSuccess = true;
		}
	}

}

FText AEatCoinGameMode::MissionText(FName CurrentLevelName)
{
	if (CurrentLevelName == FName("Level_1")) {
		return FText::FromString("goal: collect 5 copper coins.");
	}
	if (CurrentLevelName == FName("Level_2")) {
		return FText::FromString("goal: collect 5 sliver coins or 3 gold sliver.");
	}
	if (CurrentLevelName == FName("Level_3")) {
		return FText::FromString("goal: collect 20 scores.");
	}

	return FText();
}

#undef LOCTEXT_NAMESPACE // 注意：必须取消宏定义