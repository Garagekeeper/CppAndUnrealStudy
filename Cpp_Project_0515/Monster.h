#pragma once
#include<string>

#include "Actor.h"
#include "MazeCommon.h"

class Monster : public Actor
{
	std::string				Name = "몬스터";
	int						Reward = 10;


public:
							Monster(const float Modifier = 1.0f);
							Monster(const std::string& InName, int Inlevel);
							Monster(std::string Name, int InHp, int InAttackDamage, int InReward)
								: Actor(InHp, InHp, InAttackDamage), Name(Name), Reward(InReward) {}
	virtual					~Monster() = default;

	virtual void			OnDeath() override;
	virtual void			PrintStatus() override;

	inline int				GetRewardValue() const { return Reward; }
	inline std::string		GetName() const { return Name; }
};
