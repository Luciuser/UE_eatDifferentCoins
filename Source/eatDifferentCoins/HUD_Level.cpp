// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Level.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "EAT_COIN"

bool UHUD_Level::Initialize() {
	Super::Initialize();

	//ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// 获取玩家类
	//eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// 强制类型转换为子类

	TextTotalCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Total_Coin"));
	TextGoldCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Gold_Coin"));
	TextSliverCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Yin_Coin"));
	TextCopperCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Copper_Coin"));
	TextMission = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Mission"));

	if (TextTotalCoin != nullptr) {
		TextTotalCoin->SetText(LOCTEXT("9", "9"));
	}
	if (TextGoldCoin != nullptr) {
		TextGoldCoin->SetText(LOCTEXT("2", "2"));
	}
	if (TextSliverCoin != nullptr) {
		TextSliverCoin->SetText(LOCTEXT("6", "6"));
	}
	if (TextCopperCoin != nullptr) {
		TextCopperCoin->SetText(LOCTEXT("4", "4"));
	}
	if (TextMission != nullptr) {
		TextMission->SetText(LOCTEXT("5", "5"));
	}

	//updateUI();

	return true;
}

//void UHUD_Level::updateUI()
//{
//	if (TextTotalCoin != nullptr) {
//		TextTotalCoin->SetText(FText::FromString(FString::FromInt(eatCoinPlayerCharacter->CoinValue)));
//	}
//	if (TextGoldCoin != nullptr) {
//		TextGoldCoin->SetText(FText::FromString(FString::FromInt(eatCoinPlayerCharacter->GoldCoinValue)));
//	}
//	if (TextSliverCoin != nullptr) {
//		TextSliverCoin->SetText(FText::FromString(FString::FromInt(eatCoinPlayerCharacter->SliverCoinValue)));
//	}
//	if (TextCopperCoin != nullptr) {
//		TextCopperCoin->SetText(FText::FromString(FString::FromInt(eatCoinPlayerCharacter->CopperCoinValue)));
//	}
//	if (TextMission != nullptr) {
//		TextMission->SetText(FText::FromString("test"));
//	}
//}

#undef LOCTEXT_NAMESPACE // 注意：必须取消宏定义
