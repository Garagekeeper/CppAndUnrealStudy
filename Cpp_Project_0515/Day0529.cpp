#include "Day0529.h"

void Day0529_Run()
{


	Position p1(2, 3);
	printf("p1 : (%d, %d)\n", p1.X, p1.Y);
	Position p2(5, 1);
	printf("p2 : (%d, %d)\n\n", p2.X, p2.Y);

	Position Sum = p1 + p2;
	printf("Sum : (%d, %d)\n", Sum.X, Sum.Y);
	Position Diff = p1 - p2;
	printf("Diff : (%d, %d)\n", Diff.X, Diff.Y);
}

void Day0529_Eaxm()
{
	Enemy E1("오크", 1);
	Enemy E2("슬라임", 2);

	PrintEnemInfo(E1);
	PrintEnemInfo(E2);

	Enemy E3 = E1 + E2;

	PrintEnemInfo(E3);
	Enemy E4 = E3 + E1;
	PrintEnemInfo(E4);
	Enemy E5 = E4 * 2;
	PrintEnemInfo(E5);
	E5 *= 2;
	PrintEnemInfo(E5);
}

void PrintEnemInfo(Enemy& InEnemy)
{
	printf("-------------------------------------\n");
	printf("이름	: %s\n", InEnemy.Name.c_str());
	printf("HP      : %d\n", InEnemy.HP);
	printf("ATTACK	: %d\n", InEnemy.AttackDamage);
	printf("보상	: %d\n", InEnemy.Reward);
	printf("-------------------------------------\n");
}

void PrintPosition(Position& InPosition)
{
	printf("-------------------------------------\n");
	printf("X      : %d\n", InPosition.X);
	printf("Y      : %d\n", InPosition.Y);
	printf("-------------------------------------\n");
}

//간단실습 
// 1.(-) 연산자 오버로딩
// 2.(*) 연산자 오버로딩 오른쪽 값은 플롯
// 3. *= 연산자 오버로딩 오른쪽 값은 플롯


//실습