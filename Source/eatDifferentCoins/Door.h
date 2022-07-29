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
		UStaticMeshComponent* VisualMesh;	// ��̬�����壬ֱ�Ӷ�ȡԲ׶ģ��

	//UPROPERTY()
		//class UBoxComponent* BoxComponent;	// ��ײ��Χ��

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//�����Ƿ��Ѿ�����
	bool Open = false;

	int CurrentNum = 0;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
