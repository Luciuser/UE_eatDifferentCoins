// Fill out your copyright notice in the Description page of Project Settings.

#include "Coin.h"
#include "eatDifferentCoinsCharacter.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 静态网格体
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cylinder.Shape_Cylinder"));	// 读取静态网格体资源

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);	// 关闭静态网格体的碰撞
	}

	// 碰撞包围盒
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(100, 100, 100));	// 包围盒范围
	BoxComponent->SetRelativeLocation(GetActorLocation());	// 包围盒与静态网格体位于同一原点
	BoxComponent->SetCollisionProfileName("Trigger");
	BoxComponent->SetupAttachment(VisualMesh);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);
	//VisualMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);

	// 材质，好像没用，TODO
	Material = CreateDefaultSubobject<UMaterial>(TEXT("Material"));
}

// 包围盒碰撞函数
void ACoin::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("OverLap happened"));

		ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// 获取玩家类
		AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// 强制类型转换为子类

		if (eatCoinPlayerCharacter != nullptr) {
			//PRINT(FString::FromInt(eatCoinPlayerCharacter->GoldCoinValue));
			eatCoinPlayerCharacter->addCharacterCoin(this->CoinType, this->CoinValue);	// 增加子类的硬币数量
			//PRINT(FString::FromInt(eatCoinPlayerCharacter->GoldCoinValue));
			this->Destroy();	// 删除硬币实例
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding AeatDifferentCoinsCharacter"));
		}

	}
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

	NewLocation.Z += DeltaHeight * HeightMove;	// 硬币随时间跳动
	float DeltaRotation = DeltaTime * RotationSpeed;// 硬币随时间旋转
	NewRotation.Yaw += DeltaRotation;
	
	SetActorLocationAndRotation(NewLocation, NewRotation);	// 设置位置及旋转

}

