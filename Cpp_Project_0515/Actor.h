#pragma once

class Actor
{
protected:
						int AttackDamage=5;
						int CriticlaPerCentage = 10;
						int MaxHp=100;
						int Hp=100;

public:
						Actor() = default;
						Actor(const int Inlevel);
						Actor(const float Modifier = 1.0f);
						Actor(int InHP, int InMaxHP ,int InDamage) : Hp(InHP), MaxHp(InMaxHP), AttackDamage(InDamage) {}
						
	virtual				~Actor() = default;

	virtual void		ApplyDamage(Actor* Target, int AdditiveDmg);
	virtual void		OnDeath();
	virtual void		PrintStatus();
	virtual void		TakeDamage(Actor* From, int Amount);
	virtual void		TakeHeal(int Amount);

	inline int			CheckActorPointerValid(Actor* pActor) { return pActor != nullptr; }
	inline int			GetAttackDamage() const { return AttackDamage; }
	inline int			GetCriticlaPerCentage() const { return CriticlaPerCentage; }
	inline int			GetHp() const { return Hp; }
};