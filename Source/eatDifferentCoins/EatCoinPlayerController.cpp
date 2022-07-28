// Fill out your copyright notice in the Description page of Project Settings.


#include "EatCoinPlayerController.h"
#include "UObject/ConstructorHelpers.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

AEatCoinPlayerController::AEatCoinPlayerController() 
{

}

void AEatCoinPlayerController::BeginPlay()
{
	Super::BeginPlay();

}