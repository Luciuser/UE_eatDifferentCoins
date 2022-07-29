// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

#define PRINT(String) {if (GEngine){GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,*(String));}}

// Sets default values
ABoard::ABoard()
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
	}
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//PRINT(FString::FromInt((int)DeltaTime));

	// 随时间移动
	if (this->CurrentTime <= this->MoveTime) {
		FVector NewLocation = GetActorLocation();
		NewLocation.X += XMoveSpeed * this->CurrentTime;
		NewLocation.Y += YMoveSpeed * this->CurrentTime;
		NewLocation.Z += ZMoveSpeed * this->CurrentTime;

		SetActorLocationAndRotation(NewLocation, GetActorRotation());	// 设置位置及旋转
	}
	else if (this->CurrentTime > this->MoveTime && 
				this->CurrentTime <= this->MoveTime + this->StopTime) {

	}
	else if (this->CurrentTime > this->MoveTime + this->StopTime && 
				this->CurrentTime <= this->MoveTime * 2 + this->StopTime) {
		FVector NewLocation = GetActorLocation();
		NewLocation.X -= XMoveSpeed * (this->CurrentTime - this->MoveTime - this->StopTime);
		NewLocation.Y -= YMoveSpeed * (this->CurrentTime - this->MoveTime - this->StopTime);
		NewLocation.Z -= ZMoveSpeed * (this->CurrentTime - this->MoveTime - this->StopTime);

		SetActorLocationAndRotation(NewLocation, GetActorRotation());	// 设置位置及旋转
	}
	else if (this->CurrentTime > this->MoveTime * 2 + this->StopTime && 
				this->CurrentTime <= this->MoveTime * 2 + this->StopTime * 2) {

	}
	else {
		this->CurrentTime = 0;
	}
	this->CurrentTime+=DeltaTime;

}

