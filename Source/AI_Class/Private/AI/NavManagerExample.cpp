// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NavManagerExample.h"

#include "AI/AIControllerBase.h"
#include "AI/NPCBase.h"


// Sets default values
ANavManagerExample::ANavManagerExample()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ANavManagerExample::SendCommand()
{
	if (TargetNavActor)
	{
		if (AAIControllerBase* Controller = Cast<AAIControllerBase>(TargetNavActor->GetController()))
		{
			Controller->SendMoveCommand(Goal+GetActorLocation());
		}
	}
}

// Called when the game starts or when spawned
void ANavManagerExample::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ANavManagerExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

