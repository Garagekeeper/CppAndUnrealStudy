#include "Enemy.h"

void Enemy::EHeal(int Amount)
{
	HP += Amount;
	if (HP > Amount) HP = Amount;
}

void Enemy::EGetDamage(int Amount)
{
	HP -= Amount;
}