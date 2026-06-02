#pragma once
#include<string>

#include "Actor.h"
#include "MazeCommon.h"

class Monster : public Actor
{
	std::string Name = "몬스터";
	int	Reward						= 10;


public:
	Monster(const float Modifier = 1.0f)
		: Actor(Modifier)
	{
		Reward += static_cast<int>(Reward * Modifier);
	}
	Monster(const std::string& InName, int Inlevel)
		: Name(InName), Actor(Inlevel)
	{
		Reward *= Inlevel;
	}

	Monster(std::string Name, int InHp, int InAttackDamage, int InReward)
		: Actor(InHp, InHp, InAttackDamage), Name(Name), Reward(InReward) {}

	virtual void OnDeath() override;
	inline int GetRewardValue() const { return Reward; }
	inline std::string GetNmase() const { return Name; }
};
