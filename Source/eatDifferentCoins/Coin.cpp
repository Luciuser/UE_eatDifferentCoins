// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 静态网格体
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cylinder.Shape_Cylinder"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// 材质
	Material = CreateDefaultSubobject<UMaterial>(TEXT("Material"));
	VisualMesh->SetMaterial(0, Material); // TODO，设置材质，好像没用
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

	// 硬币随时间跳动并旋转
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * HeightMoveSpeed;	// 硬币随时间跳动
	float DeltaRotation = DeltaTime * RotationSpeed;// 硬币随时间旋转
	NewRotation.Yaw += DeltaRotation;
	
	SetActorLocationAndRotation(NewLocation, NewRotation);

}

