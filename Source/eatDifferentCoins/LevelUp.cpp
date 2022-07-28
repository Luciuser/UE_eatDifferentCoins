// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelUp.h"
#include "eatDifferentCoinsCharacter.h"
#include "EatCoinGameState.h"
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

	// ��̬������
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cone.Shape_Cone"));	// ��ȡ��̬��������Դ

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);	// �رվ�̬���������ײ
	}

	// ��ײ��Χ��
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(100, 100, 100));	// ��Χ�з�Χ
	BoxComponent->SetRelativeLocation(GetActorLocation());	// ��Χ���뾲̬������λ��ͬһԭ��
	BoxComponent->SetCollisionProfileName("Trigger");
	BoxComponent->SetupAttachment(VisualMesh);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ALevelUp::OnOverlapBegin);
}

void ALevelUp::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("level"));

		AGameStateBase *gameStateBase = UGameplayStatics::GetGameState(GetWorld());	// ��ȡ��Ϸ������
		AEatCoinGameState *eatCoinGameState = Cast<AEatCoinGameState>(gameStateBase);	// ǿ������ת��Ϊ����
		
		UWorld* world = GetWorld();

		if (eatCoinGameState != nullptr) {
			//PRINT(FString::FromInt(eatCoinGameState->LevelSuccess));
			eatCoinGameState->CoinTest();
			//PRINT(FString::FromInt(eatCoinGameState->LevelSuccess));
			if (eatCoinGameState->LevelSuccess) {
				//UGameplayStatics::SetGlobalTimeDilation(world, 0.2);	// ����ȫ��ʱ������
				//FPlatformProcess::Sleep(0.5);
				//PRINT(FString::FromInt(eatCoinGameState->LevelSuccess));
				UGameplayStatics::OpenLevel(world, this->NextLevel);	 // ������һ��
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

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("Hello World"));
}

// Called every frame
void ALevelUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
