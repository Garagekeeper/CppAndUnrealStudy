#pragma once
#include "Monster.h"

class Slime : public Monster
{


public:
	Slime() : Monster("슬라임",15, 2, 5) {};
	virtual void ApplyDamage(Actor* Target, int AdditiveDmg) override;
};