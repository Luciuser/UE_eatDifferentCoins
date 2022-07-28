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
		UStaticMeshComponent* VisualMesh;	// ��̬�����壬ֱ�Ӷ�ȡԲ����ģ��

	UPROPERTY(EditAnywhere)
		UMaterial* Material;	// ��̬��������ʣ���UE����������

	UPROPERTY()
		class UBoxComponent* BoxComponent;	// ��ײ��Χ��

	UPROPERTY(EditAnywhere)
		float HeightMoveSpeed = 100;	// Ӳ�����������ٶȣ�Ĭ��Ϊ20

	UPROPERTY(EditAnywhere)
		float RotationSpeed = 75;	// Ӳ�����������ٶȣ�Ĭ��Ϊ20

	UPROPERTY(EditAnywhere)
		int CoinValue = 1;	// Ӳ��������Ĭ��Ϊ1

	UPROPERTY(EditAnywhere)
		FName CoinType = FName("GOLD");	// Ӳ�����࣬Ĭ��Ϊ���

	// ��ײ����
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
