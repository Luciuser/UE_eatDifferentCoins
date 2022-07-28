// Fill out your copyright notice in the Description page of Project Settings.

#include "eatDifferentCoinsCharacter.h"
#include "EatCoinGameState.h"
#include "Kismet/GameplayStatics.h"

AEatCoinGameState::AEatCoinGameState()
{

}

void AEatCoinGameState::CoinTest()
{
	ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// 获取玩家类
	AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// 强制类型转换为子类

	if (eatCoinPlayerCharacter->GoldCoinValue >= 5) {
		this->LevelSuccess = true;
	}
}

// Called when the game starts or when spawned
void AEatCoinGameState::BeginPlay()
{
	Super::BeginPlay();
}