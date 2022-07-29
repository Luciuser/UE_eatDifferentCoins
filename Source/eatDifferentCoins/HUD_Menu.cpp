// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Menu.h"

bool UHUD_Menu::Initialize() {
	Super::Initialize();

	ButtonStartGame = Cast<UButton>(GetWidgetFromName("Button_StartGame"));
	ButtonLoadGame = Cast<UButton>(GetWidgetFromName("Button_LoadGame"));
	ButtonQuit = Cast<UButton>(GetWidgetFromName("Button_Quit"));

	//FScriptDelegate ClickDelegate;
	//ClickDelegate.BindUFunction(this, FName("ButtonStartGameClickEvent"));
	//ButtonStartGame->OnClicked.Add(ClickDelegate);

	//if (ButtonStartGame == nullptr) {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("OverLap happened"));
	//}
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("For a Test"));
	//}

	ButtonStartGame->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonStartGameClickEvent);
	ButtonLoadGame->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonLoadGameClickEvent);
	ButtonQuit->OnClicked.AddDynamic(this, &UHUD_Menu::ButtonQuitClickEvent);

	return true;
}

void UHUD_Menu::ButtonStartGameClickEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Start."));
}

void UHUD_Menu::ButtonLoadGameClickEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Load."));
}

void UHUD_Menu::ButtonQuitClickEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Quit."));
}