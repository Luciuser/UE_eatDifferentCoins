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

	//Ò³Ãæ¿Ø¼þ
	//UPROPERTY(meta = (BindWidget))
		UButton* ButtonStartGame;
	//UPROPERTY(meta = (BindWidget))
		UButton* ButtonLoadGame;
	//UPROPERTY(meta = (BindWidget))
		UButton* ButtonQuit;

	UFUNCTION()
		void ButtonStartGameClickEvent();
	UFUNCTION()
		void ButtonLoadGameClickEvent();
	UFUNCTION()
		void ButtonQuitClickEvent();
};
