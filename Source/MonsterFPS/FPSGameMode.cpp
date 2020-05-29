// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameMode.h"

void AFPSGameMode::StartPlay()
{
  Super::StartPlay();

  if (GEngine)
  {
    //Display a debug message
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("First on screen Debug message"));

  }
}
