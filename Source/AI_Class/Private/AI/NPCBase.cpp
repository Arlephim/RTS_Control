// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NPCBase.h"
#include "AI/AIControllerBase.h"

// Sets default values
ANPCBase::ANPCBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AAIControllerBase::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
}

// Called when the game starts or when spawned
void ANPCBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPCBase::ResumeMovement_Implementation()
{
	// if (GetController() && GetController()->Implements<UAIMovementInterface>())
	// if (IAIMovementInterface* MovementInterface = Cast<IAIMovementInterface>(GetController()))
	//{
	//		MovementInterface->ResumeMovement();
	//}

	if (GetController() && GetController()->Implements<UAIMovementInterface>())
	{
		IAIMovementInterface::Execute_ResumeMovement(GetController());
	}
}

void ANPCBase::StopMovement_Implementation()
{
	if (GetController() && GetController()->Implements<UAIMovementInterface>())
	{
		IAIMovementInterface::Execute_StopMovement(GetController());
	}
}


