// Fill out your copyright notice in the Description page of Project Settings.


#include "EatCoinPlayerController.h"
#include "UObject/ConstructorHelpers.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

AEatCoinPlayerController::AEatCoinPlayerController() 
{
	//static ConstructorHelpers::FClassFinder<AHUD> 
}

void AEatCoinPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//static ConstructorHelpers::FObjectFinder<UMG_API::UUserWidget> HUD_Class(TEXT("/Game/ThirdPersonCPP/UI/HUD_Level"));
	//static ConstructorHelpers::FClassFinder<UMG_API::UUserWidget> HUD_Class(TEXT("WidgetBlueprint'/Game/ThirdPersonCPP/UI/HUD_Level.HUD_Level_C'"));
	//if (HUD_Class.Succeeded())
	//{
	//	HUDAsset = HUD_Class.Class;
	//	if (HUDAsset)
	//	{
	//		HUD = CreateWidget<UUserWidget>(this, HUDAsset);
	//		if (HUD)
	//		{
	//			HUD->AddToViewport();
	//		}
	//	}
	//}

}