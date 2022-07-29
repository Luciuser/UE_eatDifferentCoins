// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"

AMenuHUD::AMenuHUD() 
{
	//// �������ָ��
	//APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
	//if (PlayerController != nullptr) {
	//	PlayerController->bShowMouseCursor = true;
	//}

	if (GEngine && GEngine->GameViewport)
	{
		// �ҵ���ͼ�࣬��Ҫ��_C
		static ConstructorHelpers::FClassFinder<UUserWidget> MenuHUDWidgetBP(TEXT("WidgetBlueprint'/Game/ThirdPersonCPP/UI/HUD_Menu.HUD_Menu_C'"));
		if (MenuHUDWidgetBP.Succeeded()) {
			HUDWidgetClass = MenuHUDWidgetBP.Class; // �õ�class
		}

		HUDWidget = CreateWidget<UHUD_Menu>(GetWorld()->GetGameInstance(), HUDWidgetClass);
		if (HUDWidget != nullptr) {
			HUDWidget->AddToViewport();	// ��ʾUI
		}
	}
}