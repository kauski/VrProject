/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include <vector>
#include "Testing.generated.h"
#include <vector>
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM_DEMON_CORE_API UTesting : public UActorComponent
{
	GENERATED_BODY()
		

public:	
	UPROPERTY(EditanyWhere, BlueprintReadWrite, category = properties)
		FVector locations;
	// Sets default values for this component's properties
	UTesting();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
};
*/