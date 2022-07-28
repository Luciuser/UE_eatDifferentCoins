// Fill out your copyright notice in the Description page of Project Settings.

#include "eatDifferentCoinsCharacter.h"
#include "EatCoinGameState.h"
#include "Kismet/GameplayStatics.h"

AEatCoinGameState::AEatCoinGameState()
{

}

void AEatCoinGameState::CoinTest()
{
	ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// ��ȡ�����
	AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// ǿ������ת��Ϊ����

	if (eatCoinPlayerCharacter->GoldCoinValue >= 5) {
		this->LevelSuccess = true;
	}
}

// Called when the game starts or when spawned
void AEatCoinGameState::BeginPlay()
{
	Super::BeginPlay();
}