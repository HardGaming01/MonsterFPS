// Fill out your copyright notice in the Description page of Project Settings.


#include "Cuttable.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
ACuttable::ACuttable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACuttable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACuttable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

