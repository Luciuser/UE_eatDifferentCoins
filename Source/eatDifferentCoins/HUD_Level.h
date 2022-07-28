// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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

	//Ò³Ãæ¿Ø¼þ
	class UTextBlock* TxtMenuTitle;
};
