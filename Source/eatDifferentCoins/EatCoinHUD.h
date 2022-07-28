// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "HUD_Level.h"
#include "GameFramework/HUD.h"
#include "EatCoinHUD.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AEatCoinHUD();

	class UHUD_Level* HUDWidget;
	TSubclassOf<class UUserWidget> HUDWidgetClass;
};
