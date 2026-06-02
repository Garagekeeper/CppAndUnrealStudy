#pragma once

#include "Actor.h"
#include "MazeCommon.h"

class Player : public Actor
{	
protected:
	int Money = 0;
	
	Position* Pos;

public:
	Player(int PosX, int PosY) 
		: Actor(100,100, 5) 
	{
		Pos = new Position(PosX, PosY);
		Money = 0;
	}
	virtual ~Player()
	{
		delete[] Pos;
	}

	void GetReward(int Amount);
	void MoveTo(int Nx, int Ny);
	void PrintStatus();
	virtual void OnDeath() override;

	virtual void ApplyDamage(Actor* Target, int AdditiveDmg) override;

	inline Position* GetPos() { return Pos; }
	
};