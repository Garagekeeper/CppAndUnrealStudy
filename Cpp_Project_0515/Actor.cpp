#include <iostream>
#include "Utils.h"
#include "Actor.h"

void Actor::TakeHeal(int Amount)
{
	Hp += Amount;
	if (Hp > MaxHp) Hp = MaxHp;
}

void Actor::ApplyDamage(Actor* Target, int AdditiveDmg)
{
	int FinalDamage = AttackDamage + AdditiveDmg;
	int CritRatio = RandomRange(100) < CriticlaPerCentage ? 2 : 1;
	if (CritRatio == 2)
		printf("\n 크리티컬이 발생하여");
	printf("(기본 데미지 (%d) + 추가 데미지(%d)) * %d = %d로 공격했습니다!.\n", AttackDamage, AdditiveDmg, CritRatio, FinalDamage * CritRatio);
	Target->TakeDamage(this, FinalDamage);
}

void Actor::TakeDamage(Actor* From, int Amount)
{
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

