#include "Orc.h"

void Orc::ApplyDamage(Actor* Target, int AdditiveDmg)
{
	printf("오크가 몽둥이를 휘두릅니다\n ");
	Actor::ApplyDamage(Target, AdditiveDmg);
}
