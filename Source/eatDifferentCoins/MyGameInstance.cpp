// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "HUD_Level.h"
#include "EatCoinHUD.h"
#include "Kismet/GameplayStatics.h"


void UMyGameInstance::addCoinValue(FName Name, int value)
{
	// 增加人物存储数据
	if (Name == FName("GOLD")) {
		this->CoinValue += value;
	}
	if (Name == FName("SLIVER")) {
		this->CoinValue += value;
	}
	if (Name == FName("COPPER")) {
		this->CoinValue += value;
	}

	// 修改HUD
	AEatCoinHUD *EatCoinHUD = Cast<AEatCoinHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	// 获取当前 UI 控件
	UHUD_Level *HUD = nullptr;
	if (EatCoinHUD != nullptr) {
		HUD = EatCoinHUD->HUDWidget;
	}

	if (HUD != nullptr) {
		HUD->TextTotalCoin->SetText(FText::FromString(FString::FromInt(this->CoinValue)));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding HUD"));
	}
}