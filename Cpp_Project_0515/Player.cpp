#include "Player.h"


void Player::GetReward(int Amount)
{
	Money += Amount;
}

void Player::MoveTo(int Nx, int Ny)
{
	Pos->X += Nx;
	Pos->Y += Ny;
}

void Player::PrintStatus()
{
	printf("\n당신의   체력: %d", Hp);
	printf("\n당신의 소지금: %d\n", Money);
}

void Player::OnDeath()
{
	printf("당신이 쓰러졌습니다....\n");
}

void Player::ApplyDamage(Actor* Target, int AdditiveDmg)
{
	printf("당신이 공격합니다\n");
	Actor::ApplyDamage(Target, AdditiveDmg);
}