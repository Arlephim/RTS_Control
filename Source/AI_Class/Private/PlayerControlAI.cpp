// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControlAI.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AI/AIControllerBase.h"
#include "GameFramework/Character.h"


void APlayerControlAI::SelectAgent()
{
	FHitResult OutHitActor;
	
	GetHitResultUnderCursor(ECC_Camera, false, OutHitActor);

	SelectedAgent = Cast<ACharacter>(OutHitActor.GetActor());

	if (SelectedAgent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("AgentSelected"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Cannot Select that Agent"));
	}
}

void APlayerControlAI::TryToSendAgent()
{
	if (SelectedAgent)
	{
		FHitResult OutHitPoint;
	
		GetHitResultUnderCursor(ECC_Camera, false, OutHitPoint);

		if (AAIControllerBase* AgentController = Cast<AAIControllerBase>(SelectedAgent->GetController()))
		{
			AgentController->SendMoveCommand(OutHitPoint.ImpactPoint);
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Moving"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Invalid Agent"));
		}
	}
}


void APlayerControlAI::SetupInputComponent()
{

	Super::SetupInputComponent();


	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(SelectAgent_Action, ETriggerEvent::Triggered, this, &APlayerControlAI::SelectAgent);
		EnhancedInputComponent->BindAction(MoveAgent_Action, ETriggerEvent::Triggered, this, &APlayerControlAI::TryToSendAgent);
	}
}

void APlayerControlAI::BeginPlay()
{
	Super::BeginPlay();
	SetShowMouseCursor(true);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_Default, 0);
	}
	
}
