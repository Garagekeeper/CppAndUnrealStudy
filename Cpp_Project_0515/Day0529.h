#pragma once
/*
	- 구조체는 데이터 담을때만 쓰자
		- 멤버에 함수를 넣더라도 내부 데이터를 담을때만 쓰자
		- Enemy operator+(const Enemy& Others) const <- 멤버를 수정하지 않는다.


	Position TargetPos2(i,j);	해당 생성자	
	Position TargetPos = { i,j };  초기화 리스트
	Position (i, j); 해당 생성자
	Position () = { i,j }; 초기화리스트, 기본 생성자, 복사대입 연산자
	Position { i,j }; 초기화 리스트
*/

#include "Enemy.h"

void Day0529_Run();

void Day0529_Eaxm();

void PrintEnemInfo(Enemy& InEnemy);
void PrintPosition(Position& InPosition);