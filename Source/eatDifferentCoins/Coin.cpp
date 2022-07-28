// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ��̬������
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cylinder.Shape_Cylinder"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// ����
	Material = CreateDefaultSubobject<UMaterial>(TEXT("Material"));
	VisualMesh->SetMaterial(0, Material); // TODO�����ò��ʣ�����û��
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Ӳ����ʱ����������ת
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * HeightMoveSpeed;	// Ӳ����ʱ������
	float DeltaRotation = DeltaTime * RotationSpeed;// Ӳ����ʱ����ת
	NewRotation.Yaw += DeltaRotation;
	
	SetActorLocationAndRotation(NewLocation, NewRotation);

}

