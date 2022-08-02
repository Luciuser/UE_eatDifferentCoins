// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Menu.h"
#include "HUD_Level.h"
#include "MyGameInstance.h"
#include "Components/SlateWrapperTypes.h"
#include "EatCoinGameMode.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "EAT_COIN"

bool UHUD_Level::Initialize() {
	Super::Initialize();

	//-------------------- 分数数据等UI -----------------------//
	TextTotalCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Total_Coin"));
	TextGoldCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Gold_Coin"));
	TextSliverCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Yin_Coin"));
	TextCopperCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Copper_Coin"));
	TextMission = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Mission"));

	// 从 GameInstance 获取数据
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(world));	// 获取GameMode类

	if (MyGameInstance != nullptr && TextTotalCoin != nullptr) {
		TextTotalCoin->SetText(FText::FromString(FString::FromInt(MyGameInstance->CoinValue)));
	}
	// 设置 UI 默认值
	if (TextGoldCoin != nullptr) {
		TextGoldCoin->SetText(FText::FromString("0"));
	}
	if (TextSliverCoin != nullptr) {
		TextSliverCoin->SetText(FText::FromString("0"));
	}
	if (TextCopperCoin != nullptr) {
		TextCopperCoin->SetText(FText::FromString("0"));
	}
	if (TextMission != nullptr && EatCoinGameMode != nullptr && MyGameInstance != nullptr) {
		TextMission->SetText(EatCoinGameMode->MissionText(MyGameInstance->CurrentLevel));
	}

	//-------------------- 暂停界面按钮 -----------------------//
	VerticalBoxButton = Cast<UVerticalBox>(GetWidgetFromName("VerticalBox_Button"));
	ButtonResumeGame = Cast<UButton>(GetWidgetFromName("Button_ResumeGame"));
	ButtonSaveGame = Cast<UButton>(GetWidgetFromName("Button_SaveGame"));
	ButtonLoadGame = Cast<UButton>(GetWidgetFromName("Button_LoadGame"));
	ButtonQuit = Cast<UButton>(GetWidgetFromName("Button_Quit"));

	if (VerticalBoxButton != nullptr) {
		//VerticalBoxButton->SetRenderOpacity(0);
		VerticalBoxButton->SetVisibility(ESlateVisibility::Hidden);	// 默认隐藏
	}
	ButtonResumeGame->OnClicked.AddDynamic(this, &UHUD_Level::ButtonResumeGameClickEvent);
	ButtonSaveGame->OnClicked.AddDynamic(this, &UHUD_Level::ButtonSaveGameClickEvent);
	ButtonLoadGame->OnClicked.AddDynamic(this, &UHUD_Level::ButtonLoadGameClickEvent);
	ButtonQuit->OnClicked.AddDynamic(this, &UHUD_Level::ButtonQuitClickEvent);

	//-------------------- 提示UI -----------------------//
	VerticalBoxTips = Cast<UVerticalBox>(GetWidgetFromName("VerticalBox_Tips"));
	if (VerticalBoxTips != nullptr) {
		//VerticalBoxButton->SetRenderOpacity(0);
		VerticalBoxTips->SetVisibility(ESlateVisibility::Hidden);	// 默认隐藏
		if (MyGameInstance != nullptr) {
			if (MyGameInstance->CurrentLevel == FName("Level_1")) {
				VerticalBoxTips->SetVisibility(ESlateVisibility::Visible);	// 默认隐藏
			}
		}
	}

	return true;
}

void UHUD_Level::ButtonResumeGameClickEvent()
{
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GamePause();	// 暂停游戏/继续游戏
	}
}

void UHUD_Level::ButtonSaveGameClickEvent()
{
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameSave();	// 保存游戏
	}
}

void UHUD_Level::ButtonLoadGameClickEvent()
{
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameLoad();	// 读取游戏
	}
}

void UHUD_Level::ButtonQuitClickEvent()
{
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameQuit();	// 退出游戏
	}
}


#undef LOCTEXT_NAMESPACE // 注意：必须取消宏定义