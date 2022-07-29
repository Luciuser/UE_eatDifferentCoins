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
		UStaticMeshComponent* VisualMesh;	// ��̬�����壬ֱ�Ӷ�ȡԲ����ģ��

	UPROPERTY(EditAnywhere)
		float XMoveSpeed = 1;	// ������X�����ƶ��ٶ�

	UPROPERTY(EditAnywhere)
		float YMoveSpeed = 1;	// ������Y�����ƶ��ٶ�

	UPROPERTY(EditAnywhere)
		float ZMoveSpeed = 1;	// ������Z�����ƶ��ٶ�

	UPROPERTY(EditAnywhere)
		float MoveTime = 2;	// ���ƶ�ʱ��

	UPROPERTY(EditAnywhere)
		float StopTime = 2;	// ��ͣ��ʱ��

	UPROPERTY(EditAnywhere)
		float CurrentTime = 0;	// �嵱ǰʱ��

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
