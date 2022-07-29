// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EatCoinGameMode.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 静态网格体
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/SM_Door.SM_Door"));	// 读取静态网格体资源

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		//VisualMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);	// 关闭静态网格体的碰撞
	}

	//// 碰撞包围盒
	//BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	//BoxComponent->InitBoxExtent(FVector(5, 50, 200));	// 包围盒范围
	//BoxComponent->SetRelativeLocation(GetActorLocation());	// 包围盒与静态网格体位于同一原点
	//BoxComponent->SetCollisionProfileName("Trigger");
	//BoxComponent->SetupAttachment(VisualMesh);
	//BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);	// 关闭静态网格体的碰撞
	//BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	//BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* world = GetWorld();
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(world));	// 获取GameMode类

	if (EatCoinGameMode != nullptr && EatCoinGameMode->LevelSuccess) {
		// 进行开门
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("door"));

		if (CurrentNum < 1) {
			FRotator NewRotation = GetActorRotation();
			NewRotation.Yaw += 90;
			SetActorLocationAndRotation(GetActorLocation(), NewRotation);	// 设置位置及旋转
			CurrentNum++;
		}
	}
}

