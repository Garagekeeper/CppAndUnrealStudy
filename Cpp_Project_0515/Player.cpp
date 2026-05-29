#include "Player.h"

void Player::Heal(float Amount)
{
	HP += Amount;
	if (HP > MaxHP) HP = MaxHP;
}

void Player::GetDamage(int Amount)
{
	HP -= Amount;
}

void Player::GetReward(int Amount)
{
	Money += Amount;
}

void Player::MoveTo(int Nx, int Ny)
{
	Pos->X += Nx;
	Pos->Y += Ny;
}
