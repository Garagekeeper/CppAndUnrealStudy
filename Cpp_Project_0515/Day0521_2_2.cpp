#include "Day0521_2_2.h"

void PrintRoundForPrac2(int Round)
{
	printf("--------------------- %d 회차 ------------\n", Round);
}

void PrintMoneyForPrac2(int Yours, int Computer)
{
	printf("  당신의 소지금 : %d\n", Yours);
	printf("컴퓨터의 소지금 : %d\n\n", Computer);
}

int RollDice(int DiceMax)
{
	return rand() % DiceMax + 1;
}

void PrintDice(int Yours, int Computer)
{
	printf("  당신의 주사위 : %d\n", Yours);
	printf("컴퓨터의 주사위 : %d\n\n", Computer);
}

int GetMinBet(int A, int B)
{
	int Res = A <= B ? A : B;
	return Res;
}

int BetByYouForPrac2(int Minbet)
{
	int InputNumber = 0;
	while (true)
	{
		printf("배팅 금액 입력 : ");

		cin >> InputNumber;
		cin.clear();
		cin.ignore(10000, '\n');

		if (InputNumber <= 0 || InputNumber > Minbet)
			printf("베팅 금액은 1이상이어야 하고 두사람의 소지금액 이하여야 합니다.\n\n");
		else
		{
			break;
		}
	}
	printf("당신의 배팅 금액 = %d\n\n", InputNumber);
	return InputNumber;
}

int BetByComputer(int Minbet)
{
	int Res = rand() % Minbet + 1;

	printf("컴퓨터의 배팅 금액 = %d\n\n", Res);

	return Res;
}

void PrintTotalDice(int Yours, int Computer)
{
	printf("  당신의 주사위 총 합: %d\n", Yours);
	printf("컴퓨터의 주사위 총 합: %d\n\n", Computer);
}

void PrintResult()
{}

bool CheckGameEnd(int Yours, int Computers)
{
	if (Yours == 0)
	{
		printf("당신의 패배로 게임이 종료 되었습니다.\n\n");
		return true;
	}
	else if (Computers == 0)
	{
		printf("컴퓨터의 패배로 게임이 종료 되었습니다.\n\n");
		return true;
	}

	return false;
}


void RunPracticeTwo()
{
	//	2.주사위 게임
		//		초기 세팅
		//		플레이어와 컴퓨터 모두 일정 금액(예 : 10000원)으로 시작한다.
		//		1차 주사위 굴리기
		//		게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
		//		각자 주사위 결과를 공개한다.
		//		배팅
		//		이전 판에서 진 쪽이 배팅 금액을 제시한다.
		//		제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
		//		배팅 금액은 두 사람 모두에게서 차감된다.
		//		2차 주사위 굴리기
		//		다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
		//		(1차 + 2차) 주사위의 합을 계산한다.
		//		승패 판정 및 금액 증감
		//		합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
		//		동점일 경우 배팅 금액은 그대로 반환한다.
		//		다음 판 진행
		//		소지금이 0 이하인 쪽이 나오면 게임 종료.

	printf("2. 주사위 게임\n");
	int YourDePosit = 10000;
	int ComputerDePosit = 10000;

	int YourDice = 0;
	int ComputerDice = 0;

	const int DiceMax = 6;
	int Round = 1;
	bool IsComputerWon = false;

	while (true)
	{
		PrintRoundForPrac2(Round);
		PrintMoneyForPrac2(YourDePosit, ComputerDePosit);

		printf("주사위 던지기\n");
		YourDice = RollDice(DiceMax);
		ComputerDice = RollDice(DiceMax);
		PrintDice(YourDice, ComputerDice);


		printf("배팅\n");
		int MinBet = GetMinBet(YourDePosit, ComputerDePosit);
		int bet = 0;
		// 직전에 컴퓨터가 진 경우 컴퓨터가 임의 배팅
		if (!IsComputerWon)
		{
			bet = BetByComputer(MinBet);
		}
		else
		{
			bet = BetByYouForPrac2(MinBet);
		}


		printf("주사위 던지기\n");
		int NYourDice = RollDice(DiceMax);
		int NComputerDice = RollDice(DiceMax);

		int YourDiceAmount = NYourDice + YourDice;
		int ComputerDiceAmount = NComputerDice + ComputerDice;

		PrintDice(NYourDice, NComputerDice);
		PrintTotalDice(YourDiceAmount, ComputerDiceAmount);

		if (YourDiceAmount > ComputerDiceAmount)
		{
			printf("당신의 승리!\n");
			YourDePosit += bet;
			ComputerDePosit -= bet;
			IsComputerWon = false;
		}
		else if (YourDiceAmount < ComputerDiceAmount)
		{
			printf("당신의 패배!\n");
			YourDePosit -= bet;
			ComputerDePosit += bet;
			IsComputerWon = true;
		}
		else if (YourDiceAmount == ComputerDiceAmount)
		{
			printf("무승부!\n");
			IsComputerWon = false;
		}

		if (CheckGameEnd(YourDePosit, ComputerDePosit))
			break;

		Round++;
	}

}
