// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMain.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"

// Sets default values
APlayerMain::APlayerMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  // Create a first person camera component.
  FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
  // Attach the camera component to our capsule component.
  FPSCameraComponent->SetupAttachment(GetCapsuleComponent());

  // Position the camera slightly above the eyes.
  FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
  // Allow the pawn to control camera rotation.
  FPSCameraComponent->bUsePawnControlRotation = true;

  // Create The arm mesh
  // Create a first person mesh component for the owning player.
  FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
  // Only the owning player sees this mesh.
  FPSMesh->SetOnlyOwnerSee(true);
  // Attach the FPS mesh to the FPS camera.
  FPSMesh->SetupAttachment(FPSCameraComponent);
  // Disable some environmental shadowing to preserve the illusion of having a single mesh.
  FPSMesh->bCastDynamicShadow = false;
  FPSMesh->CastShadow = false;

  // The owning player doesn't see the regular (third-person) body mesh.
  GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void APlayerMain::BeginPlay()
{
	Super::BeginPlay();

  if (GEngine)
  {
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Character Spawned"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Try to add some debug text"));

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

  PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerMain::Fire);
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

void APlayerMain::Fire()
{
}
