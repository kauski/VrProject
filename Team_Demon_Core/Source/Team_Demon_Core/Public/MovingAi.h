
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameEngine.h"
#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include <ctime>
#include "GameFramework/Actor.h"
#include "MovingAi.generated.h"


UCLASS()
class TEAM_DEMON_CORE_API AmovingAi : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float FloatSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float MaxDegreesPerSecond = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float TimeToMove = 10.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "FloatingActor")
		FVector VolumeMax = FVector(10000, 10000, 10000);
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "FloatingActor")
		FVector VolumeMin = FVector(-10000, -10000, -10000);
	AmovingAi();
	



protected:
	float delay;
	FVector TargetLocation = FVector(0, 0, 0);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
