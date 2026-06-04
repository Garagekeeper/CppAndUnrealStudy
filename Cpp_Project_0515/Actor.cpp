#include <iostream>
#include "Utils.h"
#include "Actor.h"

Actor::Actor(const float Modifier)
{
	{
		Hp += static_cast<int>(Hp * Modifier);
		AttackDamage += static_cast<int>(AttackDamage * Modifier);
	}
}

Actor::Actor(const int Inlevel)
{
	Hp *= Inlevel;
	AttackDamage *= Inlevel;
}

void Actor::TakeHeal(int Amount)
{
	Hp += Amount;
	if (Hp > MaxHp) Hp = MaxHp;
}

void Actor::ApplyDamage(Actor* Target, int AdditiveDmg)
{
	if (!CheckActorPointerValid(Target))
	{
		printf("!!!포인터가 유효하지 않습니다.!!!\n");
		return;
	}

	int FinalDamage = AttackDamage + AdditiveDmg;
	int CritRatio = RandomRange(100) < CriticlaPerCentage ? 2 : 1;
	if (CritRatio == 2)
		printf("\n 크리티컬이 발생하여");
	printf("(기본 데미지 (%d) + 추가 데미지(%d)) * %d = %d로 공격했습니다!.\n", AttackDamage, AdditiveDmg, CritRatio, FinalDamage * CritRatio);
	Target->TakeDamage(this, FinalDamage);
}

void Actor::TakeDamage(Actor* From, int Amount)
{
	if (!CheckActorPointerValid(From))
	{
		printf("!!!포인터가 유효하지 않습니다.!!!\n");
		return;
	}

	Hp -= Amount ;
	if (Hp <= 0)
	{
		Hp = 0;
		OnDeath();
	}
}

void Actor::OnDeath()
{
	printf("Actor is dead\n");
}

void Actor::PrintStatus()
{
	printf("Actor의 체력: %d\n\n", Hp);
}

