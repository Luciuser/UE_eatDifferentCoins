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

	// ��̬������
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/SM_Door.SM_Door"));	// ��ȡ��̬��������Դ

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		//VisualMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);	// �رվ�̬���������ײ
	}

	//// ��ײ��Χ��
	//BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	//BoxComponent->InitBoxExtent(FVector(5, 50, 200));	// ��Χ�з�Χ
	//BoxComponent->SetRelativeLocation(GetActorLocation());	// ��Χ���뾲̬������λ��ͬһԭ��
	//BoxComponent->SetCollisionProfileName("Trigger");
	//BoxComponent->SetupAttachment(VisualMesh);
	//BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);	// �رվ�̬���������ײ
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
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(world));	// ��ȡGameMode��

	if (EatCoinGameMode != nullptr && EatCoinGameMode->LevelSuccess) {
		// ���п���
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("door"));

		if (CurrentNum < 1) {
			FRotator NewRotation = GetActorRotation();
			NewRotation.Yaw += 90;
			SetActorLocationAndRotation(GetActorLocation(), NewRotation);	// ����λ�ü���ת
			CurrentNum++;
		}
	}
}
