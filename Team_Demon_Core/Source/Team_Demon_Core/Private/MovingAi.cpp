// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingAi.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"
// Sets default values
AmovingAi::AmovingAi()
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AmovingAi::BeginPlay()
{
	
	

	Super::BeginPlay();
	delay = GetWorld()->GetTimeSeconds();

}


// Called every frame
void AmovingAi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//finds a random location to move to, scene editable time, rotation speed and movement speed.
	if (GetWorld()->GetTimeSeconds() > delay + TimeToMove)
	{

		TargetLocation = FMath::RandPointInBox(FBox(FVector(VolumeMin), FVector(VolumeMax)));
		delay = GetWorld()->GetTimeSeconds();
	}

	FVector Location = GetActorLocation();
	FVector Direction = TargetLocation - Location;
	FRotator TargetRotation = Direction.Rotation();
	
	Location += GetActorForwardVector() * FloatSpeed * DeltaTime;
	FRotator NewRotation = FMath::Lerp(GetActorRotation(), TargetRotation, DeltaTime * MaxDegreesPerSecond / 180.0f);
	SetActorLocationAndRotation(Location, NewRotation);

}
