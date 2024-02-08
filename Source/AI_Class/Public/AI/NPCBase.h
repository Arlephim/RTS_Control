// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIControllerBase.h"
#include "GameFramework/Character.h"
#include "NPCBase.generated.h"

UCLASS()
class AI_CLASS_API ANPCBase : public ACharacter, public IAIMovementInterface
{
	GENERATED_BODY()

public:
	
	ANPCBase();

	UPROPERTY(EditInstanceOnly)
	AActor* ReferenceActor;

protected:
	
	virtual void BeginPlay() override;

public:
	virtual void ResumeMovement_Implementation() override;
	virtual void StopMovement_Implementation() override;
};
