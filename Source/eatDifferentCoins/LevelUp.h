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
		UStaticMeshComponent* VisualMesh;	// ��̬�����壬ֱ�Ӷ�ȡԲ׶ģ��

	UPROPERTY()
		class UBoxComponent* BoxComponent;	// ��ײ��Χ��

	UPROPERTY(EditAnywhere)
		FName CurrentLevel = FName("Game_Menu");	// ��ǰ�ؿ�����Ĭ��Ϊ Game_Menu

	UPROPERTY(EditAnywhere)
		FName NextLevel = FName("Game_Menu");	// ��һ�عؿ�����Ĭ��Ϊ Game_Menu

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ��ײ����
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
