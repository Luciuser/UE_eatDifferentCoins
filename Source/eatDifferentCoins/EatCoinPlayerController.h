// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EatCoinPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API AEatCoinPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AEatCoinPlayerController();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	TSubclassOf<UUserWidget>HUDAssert;

	UPROPERTY()
		TSubclassOf<UUserWidget> HUDAsset;

	UPROPERTY()
		UUserWidget* HUD;

protected:
	virtual void BeginPlay() override;
};
