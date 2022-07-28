// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "Coin.generated.h"

UCLASS()
class EATDIFFERENTCOINS_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;	// 静态网格体，直接读取圆柱体模型

	UPROPERTY(EditAnywhere)
		UMaterial* Material;	// 静态网格体材质，在UE界面中设置

	UPROPERTY()
		class UBoxComponent* MyBoxComponent;	// 碰撞包围盒

	UPROPERTY(EditAnywhere)
		float HeightMoveSpeed = 20;	// 硬币纵向跳动速度，默认为20

	UPROPERTY(EditAnywhere)
		float RotationSpeed = 20;	// 硬币纵向跳动速度，默认为20

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
