// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class EATDIFFERENTCOINS_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		int CoinValue = 0;	// Ǯ�Ҽ�ֵ��Ĭ��Ϊ0
	UFUNCTION()
		void addCoinValue(FName Name, int value);	// ����Ǯ�Ҽ�ֵ����
};
