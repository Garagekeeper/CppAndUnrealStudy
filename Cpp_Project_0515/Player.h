#pragma once

#include "Actor.h"
#include "MazeCommon.h"

class Player : public Actor
{	
protected:
	int					Money = 0;
	
	Position*			Pos;

public:
						Player(int PosX, int PosY);
	virtual				~Player() override;

	void				GetReward(int Amount);
	void				MoveTo(int Nx, int Ny);
	virtual void		PrintStatus() override;

	virtual void		OnDeath() override;
	virtual void		ApplyDamage(Actor* Target, int AdditiveDmg);

	inline Position*	GetPos() { return Pos; }
	
};