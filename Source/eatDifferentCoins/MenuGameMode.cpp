// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

AMenuGameMode::AMenuGameMode() {
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}

void AMenuGameMode::GameStart()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Start."));
	UWorld* world = GetWorld();
	// 将当前关卡赋给 GameInstance
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	if (MyGameInstance != nullptr) {
		MyGameInstance->CurrentLevel = this->FirstLevel;
	}
	UGameplayStatics::OpenLevel(world, this->FirstLevel);	 // 进入第一关
}

void AMenuGameMode::GameLoad()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Load."));

	AMenuPlayerController *MenuPlayerController = Cast<AMenuPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (MenuPlayerController != nullptr) {
		MenuPlayerController->Load();
	}
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	UGameplayStatics::OpenLevel(world, MyGameInstance->CurrentLevel);	 // 进入存储的关卡
}

void AMenuGameMode::GameQuit()
{
	AMenuPlayerController *MenuPlayerController = Cast<AMenuPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (MenuPlayerController != nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Quit."));
		UKismetSystemLibrary::QuitGame(this, MenuPlayerController, EQuitPreference::Quit, false);
	}
}