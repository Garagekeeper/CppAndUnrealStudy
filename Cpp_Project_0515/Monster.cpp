#include "Monster.h"

Monster::Monster(const float Modifier)
	: Actor(Modifier)
{
	Reward += static_cast<int>(Reward * Modifier);
}

Monster::Monster(const std::string& InName, int Inlevel)
	: Name(InName), Actor(Inlevel)
{
	Reward *= Inlevel;
}

void Monster::OnDeath()
{
	printf("적(%s)이 쓰러졌습니다!\n", Name.c_str());
}

void Monster::PrintStatus()
{
	printf("%s의 체력: %d\n\n", Name.c_str(), Hp);
}
