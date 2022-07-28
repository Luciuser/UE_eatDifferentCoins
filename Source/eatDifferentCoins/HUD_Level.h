// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
//#include "eatDifferentCoinsCharacter.h"
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

	//void updateUI();	// ����UI

	//ҳ��ؼ�
	UTextBlock* TextTotalCoin;
	UTextBlock* TextGoldCoin;
	UTextBlock* TextSliverCoin;
	UTextBlock* TextCopperCoin;
	UTextBlock* TextMission;

	//AeatDifferentCoinsCharacter *eatCoinPlayerCharacter;	// �����
};
