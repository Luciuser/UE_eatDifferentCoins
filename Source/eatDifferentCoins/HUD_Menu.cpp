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

	//FScriptDelegate ClickDelegate;
	//ClickDelegate.BindUFunction(this, FName("ButtonStartGameClickEvent"));
	//ButtonStartGame->OnClicked.Add(ClickDelegate);

	//if (ButtonStartGame == nullptr) {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("OverLap happened"));
	//}
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("For a Test"));
	//}

	ButtonStartGame->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonStartGameClickEvent);
	ButtonLoadGame->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonLoadGameClickEvent);
	ButtonQuit->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonQuitClickEvent);

	return true;
}

void UHUD_Menu::ButtonStartGameClickEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Start."));
	//UWorld* world = GetWorld();
	//// 将当前关卡赋给 GameInstance
	//UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	//if (MyGameInstance != nullptr) {
	//	MyGameInstance->CurrentLevel = this->FirstLevel;
	//}
	//UGameplayStatics::OpenLevel(world, this->FirstLevel);	 // 进入第一关
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameStart();	// 开始游戏
	}
}

void UHUD_Menu::ButtonLoadGameClickEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Load."));

	//AMenuPlayerController *MenuPlayerController = Cast<AMenuPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	//if (MenuPlayerController != nullptr) {
	//	MenuPlayerController->Load();
	//}
	//UWorld* world = GetWorld();
	//UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	////PRINT(MyGameInstance->CurrentLevel.ToString());
	////UGameplayStatics::OpenLevel(world, this->FirstLevel);	 // 进入第一关
	//UGameplayStatics::OpenLevel(world, MyGameInstance->CurrentLevel);	 // 进入存储的关卡
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameLoad();	// 开始游戏
	}
}

void UHUD_Menu::ButtonQuitClickEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Quit."));
	//
	//AMenuPlayerController *MenuPlayerController = Cast<AMenuPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	//if (MenuPlayerController != nullptr) {
	//	UKismetSystemLibrary::QuitGame(this, MenuPlayerController, EQuitPreference::Quit, false);
	//}
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameQuit();	// 开始游戏
	}
}