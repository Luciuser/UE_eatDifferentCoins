// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Menu.h"
#include "MenuGameMode.h"
#include "MenuPlayerController.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

bool UHUD_Menu::Initialize() {
	Super::Initialize();

	ButtonStartGame = Cast<UButton>(GetWidgetFromName("Button_StartGame"));
	ButtonLoadGame = Cast<UButton>(GetWidgetFromName("Button_LoadGame"));
	ButtonQuit = Cast<UButton>(GetWidgetFromName("Button_Quit"));

	ButtonStartGame->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonStartGameClickEvent);
	ButtonLoadGame->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonLoadGameClickEvent);
	ButtonQuit->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonQuitClickEvent);

	return true;
}

void UHUD_Menu::ButtonStartGameClickEvent()
{
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	if (MyGameInstance != nullptr) {
		MyGameInstance->CoinValue = 0;	// 初始化
	}
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameStart();	// 开始游戏
	}
}

void UHUD_Menu::ButtonLoadGameClickEvent()
{
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameLoad();	// 开始游戏
	}
}

void UHUD_Menu::ButtonQuitClickEvent()
{
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameQuit();	// 开始游戏
	}
}