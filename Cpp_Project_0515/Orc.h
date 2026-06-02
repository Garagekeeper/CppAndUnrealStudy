#pragma once
#include "Monster.h"

class Orc : public Monster
{


public:
	Orc() : Monster("오크", 30, 5, 10) {};
	virtual void ApplyDamage(Actor* Target, int AdditiveDmg) override;
};
