// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "HUD_Level.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API UHUD_Level : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

	UFUNCTION()
		void ButtonResumeGameClickEvent();	// ������Ϸ
	UFUNCTION()
		void ButtonSaveGameClickEvent();	// ������Ϸ
	UFUNCTION()
		void ButtonLoadGameClickEvent();	// ��ȡ��Ϸ
	UFUNCTION()
		void ButtonQuitClickEvent();	// �˳���Ϸ

	// ����Ŀ���UI
	UTextBlock* TextTotalCoin;
	UTextBlock* TextGoldCoin;
	UTextBlock* TextSliverCoin;
	UTextBlock* TextCopperCoin;
	UTextBlock* TextMission;

	// ��ͣ���水��
	UVerticalBox* VerticalBoxButton;
	UButton* ButtonResumeGame;
	UButton* ButtonSaveGame;
	UButton* ButtonLoadGame;
	UButton* ButtonQuit;

	// ��ʾUI
	UVerticalBox* VerticalBoxTips;
};
