// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

//#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Green,*(String));}}

UMySaveGame::UMySaveGame() 
{
	// �� GameInstance ��ȡ����
	//UWorld* world = GetWorld();
	//UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // ��ȡ��ǰGameInstance
	//if (MyGameInstance != nullptr) {
	//	this->CoinValue = MyGameInstance->CoinValue;
	//	this->CurrentLevel = MyGameInstance->CurrentLevel;
	//	PRINT(MyGameInstance->CurrentLevel.ToString());
	//	PRINT(this->CurrentLevel.ToString());
	//}
}