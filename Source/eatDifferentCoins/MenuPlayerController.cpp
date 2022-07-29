// Fill out your copyright notice in the Description page of Project Settings.

#include "MySaveGame.h"
#include "MenuPlayerController.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Green,*(String));}}

AMenuPlayerController::AMenuPlayerController() {

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetHideCursorDuringCapture(false);
	SetShowMouseCursor(true);  //显示鼠标
	//this->bShowMouseCursor = true;
}

void AMenuPlayerController::Load()
{
	UMySaveGame * SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("MySlot", 0));

	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	MyGameInstance->CoinValue = SaveGameInstance->CoinValue;
	
	PRINT(FString::FromInt(SaveGameInstance->CoinValue));
	PRINT(FString::FromInt(MyGameInstance->CoinValue));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Load Game"));

}