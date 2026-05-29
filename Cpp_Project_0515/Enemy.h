#pragma once

#include<string>
#include "MazeCommon.h"

struct Enemy
{
	std::string Name = "고블린";
	int HP							= 20;
	int AttackDamage				= 5;
	int	Reward						= 10;
	const int CriticalPercentage	= 10;

	Enemy(const float Modifier = 1.0f)
	{
		HP += static_cast<int>(HP * Modifier);
		AttackDamage += static_cast<int>(AttackDamage * Modifier);
		Reward += static_cast<int>(Reward * Modifier);
	}
	Enemy(const std::string& InName, int Inlevel)
		: Name(InName)
	{
		HP *= Inlevel;
		AttackDamage *= Inlevel;
		Reward *= Inlevel;
	}

	Enemy(std::string Name, int HP, int AttackDamage, int Reward) : Name(Name), HP(HP), AttackDamage(AttackDamage), Reward(Reward) {}

	void EHeal(int Amount);
	void EGetDamage(int Amount);

	Enemy operator+(const Enemy& InOther) const
	{
		return Enemy(Name + InOther.Name, HP + InOther.HP, (AttackDamage + InOther.AttackDamage) / 2, Reward + InOther.Reward);
	}

	Enemy operator-(const Enemy& InOther) const
	{
		std::string FinalName;
		size_t Pos = Name.find(InOther.Name);
		FinalName = Name.substr(0, Pos);

		return Enemy(FinalName, HP - InOther.HP, AttackDamage - InOther.AttackDamage / 2, Reward - InOther.Reward);
	}

	Enemy operator*(const int Val) const
	{
		return Enemy(Name, HP * Val, AttackDamage * Val, Reward * Val);
	}

	Enemy& operator*=(const int Val)
	{

		HP *= Val;
		AttackDamage *= Val;
		Reward *= Val;

		return *this;
	}

};
