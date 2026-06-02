#pragma once
#include <iostream>

const int InvalidPosition				= 1;
const int InitialHealth					= 100;
const int InitialMoney					= 100;

const int RandEncounterNone				= 50;
const int RandEncounterCombat			= 65;
const int RandEncounterHeal				= 75;
const int RandEncounterTrap				= 100;

const int RandEncounterHealAmout		= 10;
const int RandEncounterTrapDealAmout	= 10;

const int RandMonsterOrc				= 33;
const int RandMonsterSlime				= 66;
const int RnadMonsterWyvern				= 100;

//U, D, L, R 순의 방향 벡터
const int Dx[4]							= { -1, 1, 0, 0 };
const int Dy[4]							= { 0, 0, -1, 1 };

enum EMapEnv
{
	ROAD,
	WALL,
	START,
	END,
	PLAYER,
};

enum EDir
{
	UP,
	Down,
	Left,
	Right,
	EDirLength
};

enum EEncounter
{
	EncounterNone = 0,
	EncounterCombat = 1,
	EncounterHeal = 2,
	EncounterTrap = 3,
};

struct Position
{
	int X = 0;
	int Y = 0;

	Position() = default;
	Position(int InX, int InY) : X(InX), Y(InY) 
	{

	}


	Position operator+(Position& InOthers) const
	{
		return Position(X + InOthers.X, Y + InOthers.Y);
	}

	Position& operator+=(Position& InOthers)
	{
		X += InOthers.X;
		Y += InOthers.Y;
		return *this;
	}

	Position operator-(Position& InOthers) const
	{
		return Position(X - InOthers.X, Y - InOthers.Y);
	}

	bool operator==(Position& InOthers) const
	{
		return (X == InOthers.X) && (Y == InOthers.Y);
	}
};
