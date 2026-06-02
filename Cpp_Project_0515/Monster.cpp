#include "Monster.h"

void Monster::OnDeath()
{
	printf("적(%s)이 쓰러졌습니다!\n", Name.c_str());
}
