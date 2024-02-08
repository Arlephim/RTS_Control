// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControlAI.generated.h"


UCLASS()
class AI_CLASS_API APlayerControlAI : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* IMC_Default;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* SelectAgent_Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAgent_Action;

protected:

	virtual void SetupInputComponent() override;
	
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	ACharacter* SelectedAgent;

	UFUNCTION(BlueprintCallable)
	void SelectAgent();

	UFUNCTION(BlueprintCallable)
	void TryToSendAgent();
	
};
