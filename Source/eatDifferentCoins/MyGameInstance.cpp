// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "HUD_Level.h"
#include "EatCoinHUD.h"
#include "Kismet/GameplayStatics.h"


void UMyGameInstance::addCoinValue(FName Name, int value)
{
	// ��������洢����
	if (Name == FName("GOLD")) {
		this->CoinValue += value;
	}
	if (Name == FName("SLIVER")) {
		this->CoinValue += value;
	}
	if (Name == FName("COPPER")) {
		this->CoinValue += value;
	}

	// �޸�HUD
	AEatCoinHUD *EatCoinHUD = Cast<AEatCoinHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	// ��ȡ��ǰ UI �ؼ�
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