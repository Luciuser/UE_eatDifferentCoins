// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Level.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "EAT_COIN"

bool UHUD_Level::Initialize() {
	Super::Initialize();

	//ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// ��ȡ�����
	//eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// ǿ������ת��Ϊ����

	TextTotalCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Total_Coin"));
	TextGoldCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Gold_Coin"));
	TextSliverCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Yin_Coin"));
	TextCopperCoin = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Copper_Coin"));
	TextMission = Cast<UTextBlock>(GetWidgetFromName("Text_Get_Mission"));

	// �� GameInstance ��ȡ����
	UWorld* world = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // ��ȡ��ǰGameInstance
	if (MyGameInstance != nullptr && TextTotalCoin != nullptr) {
		TextTotalCoin->SetText(FText::FromString(FString::FromInt(MyGameInstance->CoinValue)));
	}
	// ���� UI Ĭ��ֵ
	if (TextGoldCoin != nullptr) {
		TextGoldCoin->SetText(LOCTEXT("0", "0"));
	}
	if (TextSliverCoin != nullptr) {
		TextSliverCoin->SetText(LOCTEXT("0", "0"));
	}
	if (TextCopperCoin != nullptr) {
		TextCopperCoin->SetText(LOCTEXT("0", "0"));
	}
	if (TextMission != nullptr) {
		TextMission->SetText(LOCTEXT("Mission: collect five gold coin", "Mission: collect five gold coin"));
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

#undef LOCTEXT_NAMESPACE // ע�⣺����ȡ���궨��
