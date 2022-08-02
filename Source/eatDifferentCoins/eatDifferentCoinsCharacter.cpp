// Copyright Epic Games, Inc. All Rights Reserved.

#include "eatDifferentCoinsCharacter.h"
#include "HUD_Level.h"
#include "EatCoinHUD.h"
#include "EatCoinPlayerController.h"
#include "EatCoinGameMode.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/SlateWrapperTypes.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Containers/UnrealString.h"

//////////////////////////////////////////////////////////////////////////
// AeatDifferentCoinsCharacter

AeatDifferentCoinsCharacter::AeatDifferentCoinsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

}

//////////////////////////////////////////////////////////////////////////
// Input

void AeatDifferentCoinsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AeatDifferentCoinsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AeatDifferentCoinsCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AeatDifferentCoinsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AeatDifferentCoinsCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AeatDifferentCoinsCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AeatDifferentCoinsCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AeatDifferentCoinsCharacter::OnResetVR);

	// 绑定自制输入
	PlayerInputComponent->BindAction("Quit", IE_Pressed, this, &AeatDifferentCoinsCharacter::OnQuit);
	PlayerInputComponent->BindAction("Save", IE_Pressed, this, &AeatDifferentCoinsCharacter::OnSave);
	PlayerInputComponent->BindAction("Restart", IE_Pressed, this, &AeatDifferentCoinsCharacter::OnRestart);
	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &AeatDifferentCoinsCharacter::OnPause).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAction("Help", IE_Pressed, this, &AeatDifferentCoinsCharacter::OnOpenTips);

}

void AeatDifferentCoinsCharacter::OnQuit()
{
	//AEatCoinPlayerController *EatCoinPlayerController = Cast<AEatCoinPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	//if (EatCoinPlayerController != nullptr) {
	//	EatCoinPlayerController->Save();
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Quit."));

	//	UKismetSystemLibrary::QuitGame(this, EatCoinPlayerController, EQuitPreference::Quit, false);
	//}
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameQuit();	// 退出游戏
	}
}

void AeatDifferentCoinsCharacter::OnSave()
{
	//AEatCoinPlayerController *EatCoinPlayerController = Cast<AEatCoinPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	//if (EatCoinPlayerController != nullptr) {
	//	EatCoinPlayerController->Save();
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Save."));
	//}
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameSave();	// 保存游戏
	}
}

void AeatDifferentCoinsCharacter::OnRestart()
{
	//UWorld* World = GetWorld();
	//UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(World)); // 获取当前GameInstance
	//if (MyGameInstance != nullptr) {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Game Restart."));
	//	UGameplayStatics::OpenLevel(World, MyGameInstance->CurrentLevel);	 // 重新开启当前关卡
	//}
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameLevelRestart();	// 重启当前关卡
	}
}

void AeatDifferentCoinsCharacter::OnPause()
{
	//bPause = !bPause;

	//UGameplayStatics::SetGamePaused(this, bPause);	// 暂停游戏

	//// 显示或关闭暂停界面按钮
	//AEatCoinHUD *EatCoinHUD = Cast<AEatCoinHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	// 获取当前 UI 控件
	//UHUD_Level *HUD = nullptr;
	//if (EatCoinHUD != nullptr) {
	//	HUD = EatCoinHUD->HUDWidget;
	//}
	//if (HUD != nullptr) {
	//	if (bPause) {
	//		HUD->VerticalBoxButton->SetVisibility(ESlateVisibility::Visible);
	//	}
	//	else {
	//		HUD->VerticalBoxButton->SetVisibility(ESlateVisibility::Hidden);
	//	}
	//}
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding HUD"));
	//}

	//// 显示鼠标指针
	//APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
	//if (PlayerController != nullptr) {
	//	PlayerController->bShowMouseCursor = bPause;
	//}
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GamePause();	// 暂停游戏
	}
}

void AeatDifferentCoinsCharacter::OnOpenTips()
{
	AEatCoinGameMode *EatCoinGameMode = Cast<AEatCoinGameMode>(UGameplayStatics::GetGameMode(GetWorld()));	// 获取GameMode类
	if (EatCoinGameMode != nullptr) {
		EatCoinGameMode->GameOpenTips();	// 暂停游戏
	}
}

void AeatDifferentCoinsCharacter::addCharacterCoin(FName Name, int value)
{
	// 增加人物存储数据
	if (Name == FName("GOLD")) {
		this->GoldCoinValue ++;
	}
	if (Name == FName("SLIVER")) {
		this->SliverCoinValue ++;
	}
	if (Name == FName("COPPER")) {
		this->CopperCoinValue ++;
	}
	//this->CoinValue++;

	//// 修改GameInstance
	//UWorld* world = GetWorld();
	////UGameplayStatics::GetGameInstance(world);
	//UMyGameInstance *MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(world)); // 获取当前GameInstance
	//if (MyGameInstance != nullptr) {
	//	MyGameInstance->CoinValue = this->CoinValue;
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("just a teset"));
	//}

	// 修改HUD
	AEatCoinHUD *EatCoinHUD = Cast<AEatCoinHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	// 获取当前 UI 控件
	UHUD_Level *HUD = nullptr;
	if (EatCoinHUD != nullptr) {
		HUD = EatCoinHUD->HUDWidget;
	}

	if (HUD != nullptr) {
		//HUD->TextTotalCoin->SetText(FText::FromString(FString::FromInt(this->CoinValue)));
		HUD->TextGoldCoin->SetText(FText::FromString(FString::FromInt(this->GoldCoinValue)));
		HUD->TextSliverCoin->SetText(FText::FromString(FString::FromInt(this->SliverCoinValue)));
		HUD->TextCopperCoin->SetText(FText::FromString(FString::FromInt(this->CopperCoinValue)));
		//HUD->TextMission->SetText(FText::FromString("test"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WRONG while finding HUD"));
	}

}

void AeatDifferentCoinsCharacter::OnResetVR()
{
	// If eatDifferentCoins is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in eatDifferentCoins.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AeatDifferentCoinsCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AeatDifferentCoinsCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AeatDifferentCoinsCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AeatDifferentCoinsCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AeatDifferentCoinsCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AeatDifferentCoinsCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
