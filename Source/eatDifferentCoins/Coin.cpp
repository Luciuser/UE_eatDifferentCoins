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

	// ��̬������
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/ThirdPerson/Coins/Shape_Cylinder.Shape_Cylinder"));	// ��ȡ��̬��������Դ

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

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);
	//VisualMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);

	// ���ʣ�����û�ã�TODO
	Material = CreateDefaultSubobject<UMaterial>(TEXT("Material"));
}

// ��Χ����ײ����
void ACoin::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("OverLap happened"));

		ACharacter *playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	// ��ȡ�����
		AeatDifferentCoinsCharacter *eatCoinPlayerCharacter = Cast<AeatDifferentCoinsCharacter>(playerCharacter);	// ǿ������ת��Ϊ����

		if (eatCoinPlayerCharacter != nullptr) {
			//PRINT(FString::FromInt(eatCoinPlayerCharacter->GoldCoinValue));
			eatCoinPlayerCharacter->addCharacterCoin(this->CoinType, this->CoinValue);	// ���������Ӳ������
			//PRINT(FString::FromInt(eatCoinPlayerCharacter->GoldCoinValue));
			this->Destroy();	// ɾ��Ӳ��ʵ��
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

	// Ӳ����ʱ����������ת
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * HeightMove;	// Ӳ����ʱ������
	float DeltaRotation = DeltaTime * RotationSpeed;// Ӳ����ʱ����ת
	NewRotation.Yaw += DeltaRotation;
	
	SetActorLocationAndRotation(NewLocation, NewRotation);	// ����λ�ü���ת

}

