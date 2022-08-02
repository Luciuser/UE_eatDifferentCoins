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
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// ��ȡGameMode��
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // ��ȡ��ǰGameInstance
	if (MyGameInstance != nullptr) {
		MyGameInstance->CoinValue = 0;	// ��ʼ��
	}
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameStart();	// ��ʼ��Ϸ
	}
}

void UHUD_Menu::ButtonLoadGameClickEvent()
{
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// ��ȡGameMode��
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameLoad();	// ��ʼ��Ϸ
	}
}

void UHUD_Menu::ButtonQuitClickEvent()
{
	AMenuGameMode *MenuGameMode = Cast<AMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// ��ȡGameMode��
	if (MenuGameMode != nullptr) {
		MenuGameMode->GameQuit();	// ��ʼ��Ϸ
	}
}