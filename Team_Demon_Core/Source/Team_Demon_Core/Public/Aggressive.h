// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/GameEngine.h"
#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include <ctime>
#include "GameFramework/Actor.h"
#include "Aggressive.generated.h"

UCLASS()
class TEAM_DEMON_CORE_API AAggressive : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float FloatSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float MaxDegreesPerSecond = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float MaxChaseDegrees = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingACtor")
		float MaxChaseSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float TimeToMove = 10.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "FloatingActor")
		FVector VolumeMax = FVector(10000, 10000, 10000);
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "FloatingActor")
		FVector VolumeMin = FVector(-10000, -10000, -10000);
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "FloatingActor")
		float AggroDistance = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		int AttackTimes = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float TimeBetweenAttack = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float ResetAttackTimer = 30.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float SpeedBetweenAttack = 50.0f;
	bool IsAttacking = false;
	float CollisionTimer = 1.0f;
	UFUNCTION(BlueprintCallable)
		void OnOverlapBeg();
	AAggressive();

protected:
	int DefaultValue{ 0 };
	bool Patrol = true;
	float distance = 0.0f;
	float delay = 10.0f;
	FVector TargetLocation = FVector(0, 0, 0);
	FVector StartLocation = FVector(0, 0, 0);


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
