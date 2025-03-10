// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
//#include "TCPMessages.h"
//#include "ExperimentPlugin.h"
#include "BehaviorTree/BehaviorTree.h"
#include "PredatorController/SmartObject.h"
#include "CharacterPredator.generated.h"

UCLASS()
class ACharacterPredator : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterPredator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	class UBehaviorTree* BehaviorTreeComponentChar; 
	//UBehaviorTree* BehaviorTreeComponentChar;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereComponent; 

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "AI")
	class ASmartObject* SmartObject;
	//ASmartObject* SmartObject;

	bool Attack = false; 
};
