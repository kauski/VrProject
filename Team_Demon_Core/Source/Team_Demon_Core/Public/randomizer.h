#pragma once
#include <cstdlib>
#include <iostream>
#include "CoreMinimal.h"
#include <vector>
using namespace std;
class TEAM_DEMON_CORE_API randomizer
{
public:
	randomizer();
	~randomizer();
	UFUNCTION(BlueprintCallable, Category = "NPCMove")
		UPROPERTY(EditAnyWhere)
		int FindRandomX();
	int FindRandomY();
	int FindRandomZ();
	int RandomRoll();


};
