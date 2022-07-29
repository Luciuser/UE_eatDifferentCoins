// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "HUD_Menu.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API UHUD_Menu : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	//页面控件
	//UPROPERTY(meta = (BindWidget))
		UButton* ButtonStartGame;
	//UPROPERTY(meta = (BindWidget))
		UButton* ButtonLoadGame;
	//UPROPERTY(meta = (BindWidget))
		UButton* ButtonQuit;
		
	FName FirstLevel = FName("Level_1");	// 第一关关卡

	UFUNCTION()
		void ButtonStartGameClickEvent();
	UFUNCTION()
		void ButtonLoadGameClickEvent();
	UFUNCTION()
		void ButtonQuitClickEvent();
};
