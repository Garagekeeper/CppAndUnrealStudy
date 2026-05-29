#pragma once

#include "MazeCommon.h"

struct Player
{
	const int CriticalPercentage = 10;
	const int MaxHP = 100;
	
	int HP = 100;
	int BaseAttackDamage = 5;
	int Money = 0;
	
	Position* Pos;

	Player(int PosX, int PosY) : HP(100), BaseAttackDamage(5), Money(0) 
	{
		Pos = new Position(PosX, PosY);
	}
	void Heal(float Amount);
	void GetDamage(int Amount);
	void GetReward(int Amount);
	void MoveTo(int Nx, int Ny);

	~Player()
	{
		delete[] Pos;
	}
};