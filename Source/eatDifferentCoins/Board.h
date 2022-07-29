// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "Board.generated.h"

UCLASS()
class EATDIFFERENTCOINS_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoard();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;	// 静态网格体，直接读取圆柱体模型

	UPROPERTY(EditAnywhere)
		float XMoveSpeed = 1;	// 板沿着X方向移动速度

	UPROPERTY(EditAnywhere)
		float YMoveSpeed = 1;	// 板沿着Y方向移动速度

	UPROPERTY(EditAnywhere)
		float ZMoveSpeed = 1;	// 板沿着Z方向移动速度

	UPROPERTY(EditAnywhere)
		float MoveTime = 2;	// 板移动时间

	UPROPERTY(EditAnywhere)
		float StopTime = 2;	// 板停滞时间

	UPROPERTY(EditAnywhere)
		float CurrentTime = 0;	// 板当前时间

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
