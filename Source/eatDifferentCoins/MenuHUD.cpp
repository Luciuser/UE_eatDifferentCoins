// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"

AMenuHUD::AMenuHUD() 
{
	//// 开启鼠标指针
	//APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
	//if (PlayerController != nullptr) {
	//	PlayerController->bShowMouseCursor = true;
	//}

	if (GEngine && GEngine->GameViewport)
	{
		// 找到蓝图类，需要加_C
		static ConstructorHelpers::FClassFinder<UUserWidget> MenuHUDWidgetBP(TEXT("WidgetBlueprint'/Game/ThirdPersonCPP/UI/HUD_Menu.HUD_Menu_C'"));
		if (MenuHUDWidgetBP.Succeeded()) {
			HUDWidgetClass = MenuHUDWidgetBP.Class; // 得到class
		}

		HUDWidget = CreateWidget<UHUD_Menu>(GetWorld()->GetGameInstance(), HUDWidgetClass);
		if (HUDWidget != nullptr) {
			HUDWidget->AddToViewport();	// 显示UI
		}
	}
}