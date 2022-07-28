// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "LevelUp.generated.h"

UCLASS()
class EATDIFFERENTCOINS_API ALevelUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelUp();
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;	// 静态网格体，直接读取圆锥模型

	UPROPERTY()
		class UBoxComponent* BoxComponent;	// 碰撞包围盒

	UPROPERTY(EditAnywhere)
		FName CurrentLevel = FName("Game_Menu");	// 当前关卡名，默认为 Game_Menu

	UPROPERTY(EditAnywhere)
		FName NextLevel = FName("Game_Menu");	// 下一关关卡名，默认为 Game_Menu

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 碰撞函数
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
