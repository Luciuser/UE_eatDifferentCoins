// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeBoard.h"

// Sets default values for this component's properties
UCubeBoard::UCubeBoard()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = false;
}


// Called when the game starts
void UCubeBoard::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCubeBoard::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

