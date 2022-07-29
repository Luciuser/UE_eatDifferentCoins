// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class EATDIFFERENTCOINS_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;	// 静态网格体，直接读取圆锥模型

	//UPROPERTY()
		//class UBoxComponent* BoxComponent;	// 碰撞包围盒

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//定义是否已经开门
	bool Open = false;

	int CurrentNum = 0;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
