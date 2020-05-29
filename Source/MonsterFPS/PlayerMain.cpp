// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMain.h"

// Sets default values
APlayerMain::APlayerMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerMain::BeginPlay()
{
	Super::BeginPlay();

  if (GEngine)
  {
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Character Spawned"));
  }
}

// Called every frame
void APlayerMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

  PlayerInputComponent->BindAxis("Forward", this, &APlayerMain::MoveVertical);
  PlayerInputComponent->BindAxis("Right", this, &APlayerMain::MoveHorizontal);

  // Set up "look" bindings.
  PlayerInputComponent->BindAxis("Yaw", this, &APlayerMain::AddControllerYawInput);
  PlayerInputComponent->BindAxis("Pitch", this, &APlayerMain::AddControllerPitchInput);

  // Set up "action" bindings.
  PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerMain::StartJump);
  PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerMain::StopJump);
}

void APlayerMain::Move(float vert, float hori)
{
  FVector Horizontal = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
  FVector Vertical = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

  AddMovementInput(Vertical, vert);
  AddMovementInput(Horizontal, hori);
}

void APlayerMain::MoveVertical(float y)
{
  Move(y, 0);
}

void APlayerMain::MoveHorizontal(float x)
{
  Move(0, x);
}

void APlayerMain::StartJump()
{
  bPressedJump = true;
}

void APlayerMain::StopJump()
{
  bPressedJump = false;
}

