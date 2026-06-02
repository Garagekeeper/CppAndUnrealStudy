#pragma once

class Actor
{
protected:
	int Hp=100;
	int MaxHp=100;
	int AttackDamage=5;
	int CriticlaPerCentage = 10;

public:
	Actor() = default;
	Actor(int InHP, int InMaxHP ,int InDamage) : Hp(InHP), MaxHp(InMaxHP), AttackDamage(InDamage) {}
	Actor(const float Modifier = 1.0f)
	{
		Hp += static_cast<int>(Hp * Modifier);
		AttackDamage += static_cast<int>(AttackDamage * Modifier);
	}

	Actor(const int Inlevel)
	{
		Hp *= Inlevel;
		AttackDamage *= Inlevel;
	}
	virtual ~Actor() = default;

	virtual void TakeHeal(int Amount);
	virtual void ApplyDamage(Actor* Target, int AdditiveDmg);
	virtual void TakeDamage(Actor* From, int Amount);
	virtual void OnDeath();

	inline int GetHp() const { return Hp; }
	inline int GetAttackDamage() const { return AttackDamage; }
	inline int GetCriticlaPerCentage() const { return CriticlaPerCentage; }
};