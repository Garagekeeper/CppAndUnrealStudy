#include "Day0521_2_1.h"

enum EPlayerState
{
	IDLE,
	JUMP,
	ATTACK,
	INVINCIBLE,
};

int PlayerState = 0;

void PrintPlayerState(int PlayerState)
{
	printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
		PrintPlayerStateCheck(PlayerState, IDLE), PrintPlayerStateCheck(PlayerState, JUMP), PrintPlayerStateCheck(PlayerState, ATTACK), PrintPlayerStateCheck(PlayerState, INVINCIBLE));
	printf("------------------------------------------------------------------\n");
}



void AddState(int State)
{
	PlayerState |= (1 << State);
}

void RemoveState(int State)
{
	PlayerState &= ~(1 << State);
}

void ToggleState(int State)
{
	PlayerState ^= (1 << State);
}

void RunPracticeOne()
{
	//	1.비트플래그를 이용한 캐릭터 상태 변환 구현하기
		//		캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
		//		다음 작업을 수행하고 현재 상태 출력하기
		//		플레이어의 상태를 대기로 설정
		//		점프 상태 추가
		//		공격 상태 추가
		//		대기 상태 해제
		//		무적 상태 추가
		//		무적 상태 토글(XOR 사용)
		//		현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
		//		대기 : [O] , 점프 : [O] , 공격 : [X] , 무적 : [O]

	AddState(IDLE);
	PrintPlayerState(PlayerState);

	printf("점프 상태 추가\n");
	AddState(JUMP);
	PrintPlayerState(PlayerState);

	printf("공격 상태 추가\n");
	AddState(ATTACK);
	PrintPlayerState(PlayerState);

	printf("대기 상태 해제\n");
	RemoveState(IDLE);
	PrintPlayerState(PlayerState);

	printf("무적 상태 추가\n");
	AddState(INVINCIBLE);
	PrintPlayerState(PlayerState);

	printf("무적 상태 토글(XOR 사용)\n");
	ToggleState(INVINCIBLE);
	PrintPlayerState(PlayerState);
}




