// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelUp.h"
#include "eatDifferentCoinsCharacter.h"
#include "MyGameInstance.h"
#include "EatCoinGameState.h"
#include "EatCoinGameMode.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

// Sets default values
ALevelUp::ALevelUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 静态网格体
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cone.Shape_Cone"));	// 读取静态网格体资源

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);	// 关闭静态网格体的碰撞
		//VisualMesh->SetVisibility(false);
	}

	// 碰撞包围盒
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(100, 100, 100));	// 包围盒范围
	BoxComponent->SetRelativeLocation(GetActorLocation());	// 包围盒与静态网格体位于同一原点
	BoxComponent->SetCollisionProfileName("Trigger");
	BoxComponent->SetupAttachment(VisualMesh);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ALevelUp::OnOverlapBegin);
}

void ALevelUp::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("level"));

		//AGameStateBase *gameStateBase = UGameplayStatics::GetGameState(GetWorld());	// 获取游戏数据类
		//AEatCoinGameState *eatCoinGameState = Cast<AEatCoinGameState>(gameStateBase);	// 强制类型转换为子类
		UWorld* world = GetWorld();
		AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(world));	// 获取GameMode类

		UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance

		if (EatCoinGameMode != nullptr) {
			PRINT(FString::FromInt(EatCoinGameMode->LevelSuccess));
			PRINT(MyGameInstance->CurrentLevel.ToString());
			// 判断是否成功
			EatCoinGameMode->CoinTest(MyGameInstance->CurrentLevel);
			PRINT(FString::FromInt(EatCoinGameMode->LevelSuccess));
			if (EatCoinGameMode->LevelSuccess) {
				EatCoinGameMode->LevelSuccess = false;
				// 将当前关卡赋给 GameInstance
				if (MyGameInstance != nullptr) {
					MyGameInstance->CurrentLevel = this->NextLevel;
				}
				//UGameplayStatics::SetGlobalTimeDilation(world, 0.2);	// 设置全局时间膨胀
				//FPlatformProcess::Sleep(0.5);
				//PRINT(FString::FromInt(eatCoinGameState->LevelSuccess));
				UGameplayStatics::OpenLevel(world, this->NextLevel);	 // 进入下一关
			}
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding AEatCoinGameState"));
		}
	}
}

// Called when the game starts or when spawned
void ALevelUp::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void ALevelUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

