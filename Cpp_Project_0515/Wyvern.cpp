#include "Wyvern.h"

void Wyvern::ApplyDamage(Actor* Target, int AdditiveDmg)
{
	printf("와이번이 불을 뿜습니다.\n ");
	Actor::ApplyDamage(Target, AdditiveDmg);
}
