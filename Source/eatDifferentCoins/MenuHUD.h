// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "HUD_Menu.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMenuHUD();
	class UHUD_Menu* HUDWidget;
	TSubclassOf<class UUserWidget> HUDWidgetClass;
};
