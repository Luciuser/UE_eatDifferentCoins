// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "EatCoinGameMode.h"
#include "EatCoinPlayerController.h"
#include "EatCoinGameState.h"
#include "eatDifferentCoinsCharacter.h"
#include "EatCoinHUD.h"
#include "EatCoinGameState.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "EAT_COIN"

AEatCoinGameMode::AEatCoinGameMode()
{
	// �����µ� GamePlayerController �� GameState
	GameStateClass = AEatCoinGameState::StaticClass();
	PlayerControllerClass = AEatCoinPlayerController::StaticClass();
	HUDClass = AEatCoinHUD::StaticClass();
}

void AEatCoinGameMode::CoinTest(FName CurrentLevelName)
{
	ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// ��ȡ�����
	AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// ǿ������ת��Ϊ����

	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())); // ��ȡ��ǰGameInstance

	if (CurrentLevelName == FName("Level_1")) {
		if (eatCoinPlayerCharacter->CopperCoinValue >= 5) {
			this->LevelSuccess = true;
		}
	}
	if (CurrentLevelName == FName("Level_2")) {
		if (eatCoinPlayerCharacter->SliverCoinValue >= 5 || eatCoinPlayerCharacter->GoldCoinValue >= 3) {
			this->LevelSuccess = true;
		}
	}
	if (CurrentLevelName == FName("Level_3")) {
		if (MyGameInstance->CoinValue >= 30) {
			this->LevelSuccess = true;
		}
	}
}

void AEatCoinGameMode::GameLevelRestart()
{
	UWorld* World = GetWorld();
	UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(World)); // ��ȡ��ǰGameInstance
	if (MyGameInstance != nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Restart."));
		UGameplayStatics::OpenLevel(World, MyGameInstance->CurrentLevel);	 // ���¿�����ǰ�ؿ�
	}
}

void AEatCoinGameMode::GameSave()
{
	AEatCoinPlayerController *EatCoinPlayerController = Cast<AEatCoinPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (EatCoinPlayerController != nullptr) {
		EatCoinPlayerController->Save();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Save."));
	}
}

void AEatCoinGameMode::GameLoad()
{
	AEatCoinPlayerController *EatCoinPlayerController = Cast<AEatCoinPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (EatCoinPlayerController != nullptr) {
		EatCoinPlayerController->Load();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Load."));
		UWorld* world = GetWorld();
		UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // ��ȡ��ǰGameInstance
		UGameplayStatics::OpenLevel(world, MyGameInstance->CurrentLevel);	 // ����洢�Ĺؿ�
	}
}

void AEatCoinGameMode::GameQuit()
{
	AEatCoinPlayerController *EatCoinPlayerController = Cast<AEatCoinPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (EatCoinPlayerController != nullptr) {
		//EatCoinPlayerController->Save();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Quit."));
		UKismetSystemLibrary::QuitGame(this, EatCoinPlayerController, EQuitPreference::Quit, false);
	}
}

void AEatCoinGameMode::GamePause()
{
	bPause = !bPause;

	UGameplayStatics::SetGamePaused(this, bPause);	// ��ͣ��Ϸ

	// ��ʾ��ر���ͣ���水ť
	AEatCoinHUD *EatCoinHUD = Cast<AEatCoinHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	// ��ȡ��ǰ UI �ؼ�
	UHUD_Level *HUD = nullptr;
	if (EatCoinHUD != nullptr) {
		HUD = EatCoinHUD->HUDWidget;
	}
	if (HUD != nullptr) {
		if (bPause) {
			HUD->VerticalBoxButton->SetVisibility(ESlateVisibility::Visible);
		}
		else {
			HUD->VerticalBoxButton->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding HUD"));
	}

	// ��ʾ���ָ��
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
	if (PlayerController != nullptr) {
		PlayerController->bShowMouseCursor = bPause;
	}
}

void AEatCoinGameMode::GameOpenTips()
{
	// ��ʾ��ر���ͣ���水ť
	AEatCoinHUD *EatCoinHUD = Cast<AEatCoinHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	// ��ȡ��ǰ UI �ؼ�
	UHUD_Level *HUD = nullptr;
	if (EatCoinHUD != nullptr) {
		HUD = EatCoinHUD->HUDWidget;
	}
	if (HUD != nullptr) {
		if (bTips) {
			HUD->VerticalBoxTips->SetVisibility(ESlateVisibility::Visible);
			bTips = false;
		}
		else {
			HUD->VerticalBoxTips->SetVisibility(ESlateVisibility::Hidden);
			bTips = true;
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding HUD"));
	}
}

FText AEatCoinGameMode::MissionText(FName CurrentLevelName)
{
	if (CurrentLevelName == FName("Level_1")) {
		return FText::FromString("goal: collect 5 copper coins.");
	}
	if (CurrentLevelName == FName("Level_2")) {
		return FText::FromString("goal: collect 5 sliver coins or 3 gold coins.");
	}
	if (CurrentLevelName == FName("Level_3")) {
		return FText::FromString("goal: collect 30 scores.");
	}

	return FText();
}

#undef LOCTEXT_NAMESPACE // ע�⣺����ȡ���궨��