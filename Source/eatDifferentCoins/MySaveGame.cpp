// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

UMySaveGame::UMySaveGame() 
{
	// �� GameInstance ��ȡ����
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // ��ȡ��ǰGameInstance
	if (MyGameInstance != nullptr) {
		this->CoinValue = MyGameInstance->CoinValue;
	}
}