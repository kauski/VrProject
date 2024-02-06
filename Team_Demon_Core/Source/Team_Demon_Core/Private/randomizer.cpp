// Fill out your copyright notice in the Description page of Project Settings.


#include "randomizer.h"

randomizer::randomizer()
{
}

randomizer::~randomizer()
{
}


int randomizer::RandomRoll()
{
	srand((unsigned)time(NULL));
	int random{ 0 };
	random = rand() % -1000 + 1000;
	return random;
}

int randomizer::FindRandomX()
{
	int RandomX = RandomRoll();
	return RandomX;
}
int randomizer::FindRandomY()
{
	int RandomX = RandomRoll();
	return RandomX;
}
int randomizer::FindRandomZ()
{
	int RandomX = RandomRoll();
	return RandomX;
}

	