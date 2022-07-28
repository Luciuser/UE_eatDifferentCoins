// Fill out your copyright notice in the Description page of Project Settings.


#include "EatCoinGameMode.h"
#include "EatCoinPlayerController.h"
#include "EatCoinGameState.h"
#include "EatCoinHUD.h"

AEatCoinGameMode::AEatCoinGameMode()
{
	// �����µ� GamePlayerController �� GameState
	GameStateClass = AEatCoinGameState::StaticClass();
	PlayerControllerClass = AEatCoinPlayerController::StaticClass();
	HUDClass = AEatCoinHUD::StaticClass();
}