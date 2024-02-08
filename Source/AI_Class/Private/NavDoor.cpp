// Fill out your copyright notice in the Description page of Project Settings.


#include "NavDoor.h"


// Sets default values
ANavDoor::ANavDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ANavDoor::OpenDoor()
{
}

void ANavDoor::CloseDoor()
{
	
}

// Called when the game starts or when spawned
void ANavDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANavDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

