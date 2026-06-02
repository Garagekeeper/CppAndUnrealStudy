#include "Slime.h"

void Slime::ApplyDamage(Actor* Target, int AdditiveDmg)
{
	printf("슬라임이 물컹한 액체를 던집니다\n ");
	Actor::ApplyDamage(Target, AdditiveDmg);
}
