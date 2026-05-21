#include "Day0521_2_3.h"

void PrintRoundForPrac3(int Round)
{
	printf("\n---------%d회차-----------\n", Round);
}

int BetByYouForPrac3(int Deposit)
{
	int Bet = 0;
	while (true)
	{
		printf("배팅을 하세요!\n");
		cin >> Bet;
		cin.clear();
		cin.ignore(10000, '\n');

		if (Bet < 100 || Bet > Deposit)
		{
			printf("베팅 금액은 100이상이어야 하고 소지금액 이하여야 합니다.\n\n");
		}
		else
		{
			break;
		}
	}
	return Bet;
}

int ChooseOddEven()
{
	int YourChoice = 0;
	printf("홀짝을 선택하세요\n");
	printf("[1. 홀 ]	[2. 짝 ]\n");
	cin >> YourChoice;

	return YourChoice;
}

int SelectOddEvenByComputer()
{
	return rand() % 2 + 1;
}

void PrintRes(int Computers)
{
	printf("결과 : %s\n", Computers == 1 ? "홀" : "짝");
}

bool GetSstreakChallengeBool()
{
	printf("\n\n");
	printf("연승 도전 여부를 선택하세요!");
	printf("[1. 수락 ]	[2. 거부 ]\n");
	int inputNum = 0;
	cin >> inputNum;

	return !(inputNum - 1);
}

bool CheckEndCondition(int Deposit)
{
	if (Deposit < 100)
	{
		printf("소지금이 부족해 강제로 종료 됩니다.\n\n");
		return true;
	}
	return false;
}

void PrintMoneyForPrac3(int Yours)
{
	printf("현재 잔액 : %d\n\n", Yours);
}

void RunPracticeThree()
{
	//	3.홀짝 게임
		//		초기 금액 및 배팅
		//			플레이어는 기본금 100원으로 베팅을 시작한다.
		//		홀짝 선택
		//			플레이어가 1(홀)또는 2(짝)을 선택한다.
		//		결과 결정
		//			컴퓨터가 랜덤으로 1(홀)또는 2(짝)을 선택한다.
		//			플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
		//		연속 배팅 선택
		//			승리 시 플레이어는 두 가지 중 하나를 선택 :
		//			(A)이긴 금액을 모두 다시 한 번에 배팅(연승 도전)
		//			(B)이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
		//		게임 종료 조건
		//			플레이어가 소지금이 100원 미만일 경우 게임 종료.

	printf("3. 홀짝 게임");
	int Deposit = 1000;
	int YourChoice = 0;
	int ComputerChoice = 0;
	int Round = 1;
	int Bet = 0;
	bool IsPlayerWon = false;
	bool IsTryStreak = false;

	while (true)
	{
		PrintRoundForPrac3(Round);
		PrintMoneyForPrac3(Deposit);

		if (!IsTryStreak)
		{
			Bet = BetByYouForPrac3(Deposit);
			Deposit -= Bet;
		}
		printf("배팅금 : %d\n", Bet);
		PrintMoneyForPrac3(Deposit);

		YourChoice = ChooseOddEven();
		ComputerChoice = SelectOddEvenByComputer();
		PrintRes(ComputerChoice);
		
		if (YourChoice == ComputerChoice)
		{
			printf("적중 했습니다!.");
			IsPlayerWon = true;

			IsTryStreak = GetSstreakChallengeBool();

			if (IsTryStreak)	
				Bet *= 2;
			else
				Deposit += Bet * 2;
			
		}
		else
		{
			printf("패배 했습니다!.");
			IsPlayerWon = false;
			IsTryStreak = false;

			if (CheckEndCondition(Deposit))
				break;
		}
		Round++;
	}

	return;
}
