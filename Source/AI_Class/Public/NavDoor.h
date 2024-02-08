// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavDoor.generated.h"

UCLASS()
class AI_CLASS_API ANavDoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANavDoor();

	UPROPERTY(Blueprintable)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(Blueprintable)
	FVector StartLocation = {0, 0, 0};

	UFUNCTION(BlueprintCallable)
	void OpenDoor();

	UFUNCTION(BlueprintCallable)
	void CloseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
