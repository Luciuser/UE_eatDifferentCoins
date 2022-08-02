// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterFloor.h"
#include "EatCoinGameMode.h"
#include "eatDifferentCoinsCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

// Sets default values
AWaterFloor::AWaterFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 静态网格体
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cube.Shape_Cube"));	// 读取静态网格体资源

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);	// 关闭静态网格体的碰撞
		VisualMesh->OnComponentBeginOverlap.AddDynamic(this, &AWaterFloor::OnOverlapBegin);
	}
}

// Called when the game starts or when spawned
void AWaterFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaterFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaterFloor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(OtherActor); // 确定碰撞的对象
		if (eatCoinPlayerCharacter != nullptr) {
			UWorld* world = GetWorld();
			AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(world));	// 获取GameMode类

			if (EatCoinGameMode != nullptr) {
				EatCoinGameMode->GameLevelRestart();
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding AEatCoinGameState"));
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Water Test."));

}

