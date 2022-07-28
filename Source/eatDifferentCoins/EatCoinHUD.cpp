// Fill out your copyright notice in the Description page of Project Settings.


#include "EatCoinHUD.h"
#include "UObject/ConstructorHelpers.h"

AEatCoinHUD::AEatCoinHUD() {
	if (GEngine && GEngine->GameViewport)
	{
		// �ҵ���ͼ�࣬��Ҫ��_C
		static ConstructorHelpers::FClassFinder<UUserWidget> MenuHUDWidgetBP(TEXT("WidgetBlueprint'/Game/ThirdPersonCPP/UI/HUD_Level.HUD_Level_C'"));
		if (MenuHUDWidgetBP.Succeeded()) {
			HUDWidgetClass = MenuHUDWidgetBP.Class; // �õ�class
		}

		HUDWidget = CreateWidget<UHUD_Level>(GetWorld()->GetGameInstance(), HUDWidgetClass);
		if (HUDWidget != nullptr) {
			HUDWidget->AddToViewport();	// ��ʾUI
		}
	}
}