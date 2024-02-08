// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIControllerBase.h"

#include "AI/NPCBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Navigation/PathFollowingComponent.h"


// Sets default values
AAIControllerBase::AAIControllerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIControllerBase::SendMoveCommand(const FVector& InGoal)
{
	if (GetCharacter())
	{
		FAIMoveRequest MoveRequest;
		MoveRequest
		.SetAcceptanceRadius(50.f)
		.SetCanStrafe(true)
		.SetUsePathfinding(true)
		.SetGoalLocation(InGoal);

		FNavPathSharedPtr Path;
		
		FPathFollowingRequestResult RequestID = MoveTo(MoveRequest, &Path);
		
		GetPathFollowingComponent()->OnRequestFinished.AddUObject(this, &ThisClass::MoveFinished);
	}
}

void AAIControllerBase::SendMoveCommand(const FVector& InGoal, bool bAbortCurrent)
{
	GetPathFollowingComponent()->AbortMove(*this, FPathFollowingResultFlags::UserAbort);
	
	SendMoveCommand(InGoal);
}

void AAIControllerBase::ResumeMovement_Implementation()
{
	ensure(GetPathFollowingComponent());
	GetPathFollowingComponent()->ResumeMove();
}

void AAIControllerBase::StopMovement_Implementation()
{
	ensure(GetPathFollowingComponent());
	GetPathFollowingComponent()->PauseMove();
}

void AAIControllerBase::MoveFinished(FAIRequestID FaiRequestID, const FPathFollowingResult& PathFollowingResult)
{
	
	GetPathFollowingComponent()->OnRequestFinished.RemoveAll(this);
}

void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
}

void AAIControllerBase::OnUnPossess()
{
	Super::OnUnPossess();
	
}

void AAIControllerBase::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (Result.IsSuccess())
	{
		
	}
	else if (Result.IsFailure())
	{
		
	}
	else if (Result.IsInterrupted())
	{
		
	}
}

