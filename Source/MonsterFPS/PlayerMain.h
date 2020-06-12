// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "PlayerMain.generated.h"

UCLASS()
class MONSTERFPS_API APlayerMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
  void Move(float x, float y);

	UFUNCTION()
	void MoveVertical(float y);

	UFUNCTION()
	void MoveHorizontal(float x);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FPSMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Dick;

	// Function that handles firing projectiles.
	UFUNCTION()
  void Fire();

	// Gun muzzle's offset from the camera location.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  FVector MuzzleOffset;

	// Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABullet> BulletClass;
};
