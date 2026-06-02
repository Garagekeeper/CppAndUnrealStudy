#pragma once
#include "Monster.h"

class Wyvern : public Monster
{

public:
	Wyvern() : Monster("와이번", 30, 15, 30) {};
	virtual void ApplyDamage(Actor* Target, int AdditiveDmg) override;
};
