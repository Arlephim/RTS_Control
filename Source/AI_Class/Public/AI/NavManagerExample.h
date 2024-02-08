// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavManagerExample.generated.h"

UCLASS()
class AI_CLASS_API ANavManagerExample : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANavManagerExample();

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector Goal;

	UPROPERTY(EditAnywhere)
	ACharacter* TargetNavActor;

	UFUNCTION(CallInEditor)
	void SendCommand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
