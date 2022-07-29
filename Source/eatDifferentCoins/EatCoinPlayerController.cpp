// Fill out your copyright notice in the Description page of Project Settings.


#include "EatCoinPlayerController.h"
#include "MySaveGame.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

AEatCoinPlayerController::AEatCoinPlayerController() 
{

}

void AEatCoinPlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void AEatCoinPlayerController::Save()
{
	UMySaveGame * SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	
	SaveGameInstance->CoinValue = MyGameInstance->CoinValue;
	SaveGameInstance->CurrentLevel = MyGameInstance->CurrentLevel;

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("MySlot"), 0);	// 保存到插槽中

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Game Saved"));
}

void AEatCoinPlayerController::Load()
{
	UMySaveGame * SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("MySlot", 0));	// 从插槽中读取

	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance

	MyGameInstance->CoinValue = SaveGameInstance->CoinValue;
	MyGameInstance->CurrentLevel = SaveGameInstance->CurrentLevel;

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Load Game"));

}
