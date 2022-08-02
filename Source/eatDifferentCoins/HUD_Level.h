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
		void ButtonResumeGameClickEvent();	// 继续游戏
	UFUNCTION()
		void ButtonSaveGameClickEvent();	// 保存游戏
	UFUNCTION()
		void ButtonLoadGameClickEvent();	// 读取游戏
	UFUNCTION()
		void ButtonQuitClickEvent();	// 退出游戏

	// 分数目标等UI
	UTextBlock* TextTotalCoin;
	UTextBlock* TextGoldCoin;
	UTextBlock* TextSliverCoin;
	UTextBlock* TextCopperCoin;
	UTextBlock* TextMission;

	// 暂停界面按键
	UVerticalBox* VerticalBoxButton;
	UButton* ButtonResumeGame;
	UButton* ButtonSaveGame;
	UButton* ButtonLoadGame;
	UButton* ButtonQuit;

	// 提示UI
	UVerticalBox* VerticalBoxTips;
};
