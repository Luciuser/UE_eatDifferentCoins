// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"

AMenuPlayerController::AMenuPlayerController() {

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetHideCursorDuringCapture(false);
	SetShowMouseCursor(true);  //��ʾ���
	//this->bShowMouseCursor = true;
}