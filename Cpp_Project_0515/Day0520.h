#pragma once

/*
연산자
	비트 연산자
		- 비트 단위로 연산하는 연산자
		- &		: 둘다 1이면 1				,타겟 비트가 1인지 확인, 타겟 비트를 0으로 세팅
		- |		: 둘 중 하나라도 1이면 1	,타켓 비트를 1로 세팅
		- ~		: 0, 1 뒤집기				,
		- ^		: 둘이 다르면 1				,특정 비트만 토글 시킬 때 0으로 세팅하면 원본, 1로 세팅하면 반전
		- <<	: 왼쪽 쉬프트 (2 곱하기)	,마스크 생성시 or랑 같이 유용하게 사용
		- >>	: 오른쪽 쉬프트 (2 나누기)	,

자료형
	열거형
		- 상수의 집합
		- enum

제어구문 
	반복문
		- for
		- while
		- do-while
		- ranged for (for auto a : A) 

랜덤
	stdio.h 
		- rand : 랜덤을 뱉긴하는데 매번 같은 순서로 똑같은 값이 나온다  
		- srand: 시드를 기반으로 랜덤을 뱉음 시드마다 다람
			- time.h, srand(time(0));
	random 헤더
		- 랜덤 디바이스, 알고리즘을 정해야해서 귀찮음
		- 정규분포 쓸 수 있음.

	* 헤더를 추가하는 순서도 중요하다
		- 순환참조 이슈도 있음

*/

// 간단 실습
//{
//	// 1. 비트 연산을 활용해서 홀짝을 판별하기 (입력 데이터는 양수)
//	int InputNum = 0;
//	printf("판별할 숫자를 입력하세요: ");
//	cin >> InputNum;
//	int mask = 1;
//	if (InputNum & mask)
//	{
//		printf("홀수\n\n");
//	}
//	else
//	{
//		printf("짝수\n\n");
//	}
//}

//{
//	// 2. 캐릭터가 사용가능한 무기 enum 만들고
//	// 데이터 설정해서 이용해서 특정 무기를 사용할 수 있는 지 확인하는 코드 만들기
//	//

//	enum EWepon
//	{
//		SWORD	= 0,
//		BOW,
//		RIFLE,
//		PISTOLE,
//		EWPONLENGTH,
//	};

//	int PlayerData = 0;
//	int InputNum = 0;
//	int mask = 0;
//	EWepon INputEnum;

//	PlayerData |= (1 << SWORD) | (1 << RIFLE);
//	printf("확인할 무기를 선택해주세요\n");
//	printf("1.검, 2.활, 3.소총, 4.권총\n");
//	cin >> InputNum;

//	switch (InputNum - 1)
//	{
//		case SWORD:
//			mask = (1 << SWORD);
//			break;
//		case BOW:
//			mask = (1 << BOW);
//			break;
//		case RIFLE:
//			mask = (1 << RIFLE);
//			break;
//		case PISTOLE:
//			mask = (1 << PISTOLE);
//			break;
//	}

//	if (mask & PlayerData)
//	{
//		printf("해당 무기는 사용할 수 있습니다.\n\n");
//	}
//	else
//	{
//		printf("해당 무기는 사용할 수 없습니다.\n\n");
//	}

//	// 3. 캐릭터가 사용가능한 무기를 추가 혹은 삭제하기
//	printf("현재 사용 가능한 무기 입니다\n");
//	for (int i = 0; i < EWPONLENGTH; i++)
//	{
//		if (PlayerData >> i & 1)
//		{
//			switch (i)
//			{
//				case SWORD:
//					printf("검 ");
//					break;
//				case BOW:
//					printf("활 ");
//					break;
//				case RIFLE:
//					printf("소총 ");
//					break;
//				case PISTOLE:
//					printf("권총 ");
//					break;
//			}
//		}
//	}
//	printf("\n\n");


//	printf("추가할 무기를 선택하세요\n");
//	printf("1.검, 2.활, 3.소총, 4.권총\n");
//	cin >> InputNum;

//	switch (InputNum - 1)
//	{
//		case SWORD:
//			mask = (1 << SWORD);
//			break;
//		case BOW:
//			mask = (1 << BOW);
//			break;
//		case RIFLE:
//			mask = (1 << RIFLE);
//			break;
//		case PISTOLE:
//			mask = (1 << PISTOLE);
//			break;
//	}

//	PlayerData |= mask;
//	printf("현재 사용 가능한 무기 입니다\n");
//	for (int i = 0; i < EWPONLENGTH; i++)
//	{
//		if (PlayerData >> i & 1)
//		{
//			switch (i)
//			{
//				case SWORD:
//					printf("검 ");
//					break;
//				case BOW:
//					printf("활 ");
//					break;
//				case RIFLE:
//					printf("소총 ");
//					break;
//				case PISTOLE:
//					printf("권총 ");
//					break;
//			}
//		}
//	}
//	printf("\n\n");


//	printf("제거할 무기를 선택하세요\n");
//	printf("1.검, 2.활, 3.소총, 4.권총\n");
//	cin >> InputNum;

//	switch (InputNum - 1)
//	{
//		case SWORD:
//			mask = (1 << SWORD);
//			break;
//		case BOW:
//			mask = (1 << BOW);
//			break;
//		case RIFLE:
//			mask = (1 << RIFLE);
//			break;
//		case PISTOLE:
//			mask = (1 << PISTOLE);
//			break;
//	}

//	PlayerData &= ~mask;

//	printf("현재 사용 가능한 무기 입니다\n");
//	for (int i = 0; i < EWPONLENGTH; i++)
//	{
//		if (PlayerData >> i & 1)
//		{
//			switch (i)
//			{
//				case SWORD:
//					printf("검 ");
//					break;
//				case BOW:
//					printf("활 ");
//					break;
//				case RIFLE:
//					printf("소총 ");
//					break;
//				case PISTOLE:
//					printf("권총 ");
//					break;
//			}
//		}
//	}
//	printf("\n\n");

//}

//{
//	//1. 0을 입력 받을 때까지 입력 받은 숫자의 합을 출력
//		//while do-while 둘다 하기
//	int InputNum = -1;
//	int sum = 0;
//	printf("더할 숫자들을 차례로 입력하세요(0 입력시 종료)");
//	while(true)
//	{
//		cin >> InputNum;
//		if (InputNum == 0)
//		{
//			printf("합: %d\n\n", sum);
//			break;
//		}
//		sum += InputNum;
//	}

//	sum = 0;

//	do
//	{
//		cin >> InputNum;
//		if (InputNum == 0)
//		{
//			printf("합: %d\n\n", sum);
//			break;
//		}
//		sum += InputNum;
//	} while (InputNum != 0);
//}

//{
//	// 2. 입력받은 수의 구구단 출력하기
//	printf("몇단을 할까요");
//	int Num = 0;
//	cin >> Num;
//	for (int i = 1; i <= 9; i++)
//		printf("%d x %d = %d\n", Num, i, Num * i);

//	printf("\n\n");
//}

//{
//	// 3.1부터 입력받은 수까지 홀수만 출력
//	printf("숫자를 입력해 주세요");
//	int Num = 0;
//	cin >> Num;
//	for (int i = 1; i <= Num; i++)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);
//	}
//	printf("\n\n");
//}

//{
//	// 4.1~100 중에 7의 배수 출력하기
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 7 == 0)
//			printf("%d ", i);
//	}

//	printf("\n\n");
//}

//{
//	// 5. 팩토리얼 계산하기;
//	printf("N을 입력해 주세요");
//	int Number = 0;
//	cin >> Number;
//	long long factorial = Number;
//	while (--Number)
//	{
//		factorial *= Number;
//	}
//	printf("%lld ", factorial);
//	printf("\n\n");
//}

//{
//	// 6. 피라미드 별찍기
//	printf("높이를 입력해 주세요");
//	int Height;
//	cin >> Height;

//	/*  ㄴㄴㅁ
//		ㄴㅁㅁㅁ
//		ㅁㅁㅁㅁㅁ
//	*/
//	for (int i = 0; i < Height; i++)
//	{
//		//공백 출력
//		for (int j = Height - i; j > 0; j--)
//			printf(" ");
//		
//		//별 출력
//		int lim = 2 * i + 1;
//		for (int j = 0; j < lim; j++)
//			printf("*");

//		printf("\n");
//	}
//	printf("\n");
//}

/*
// 간단 실습

	// 원래는 이렇게 변경하면 안된다네요 
	srand(static_cast<unsigned int>(time(0)));

	{
		// 1. 가위 바위 보
		//	- 3선승
		//	- enum

		int YourScore = 0;
		int ComputerScore = 0;
		enum ERSPSTATE
		{
			SCISSORS = 0,
			ROCK = 1,
			PAPERS = 2,
			ERSPSTATELENGTH,
		};
		while (YourScore < 3 && ComputerScore < 3)
		{
			printf("-------------------------------------------------------------------\n");
			printf("현재 점수 => ");
			printf("%d(컴퓨터) : %d(당신)\n", ComputerScore, YourScore);
			printf("어떤 것을 낼지 선택 하세요\n");
			printf("[ 1.가위 ]    [ 2.바위 ]    [ 3.보 ]\n");

			int InputNum = 0;
			cin >> InputNum;

			printf("\n");

			InputNum--;
			ERSPSTATE ComPuterDicision = ERSPSTATE(rand() % ERSPSTATELENGTH);
			switch (ComPuterDicision)
			{
				case ROCK:
					printf("컴퓨터	: [바위]\n");
					printf("당신	: [");
					if (InputNum == PAPERS)
					{
						printf("보]\n");
						printf("당신의 승리!\n");
						YourScore++;
					}
					else if (InputNum == SCISSORS)
					{
						printf("가위]\n");
						printf("당신의 패배..\n");
						ComputerScore++;
					}
					else
					{
						printf("바위]\n");
						printf("무승부!\n");
					}
					break;
				case SCISSORS:
					printf("컴퓨터 : [가위]\n");
					printf("당신	: [");
					if (InputNum == ROCK)
					{
						printf("바위]\n");
						printf("당신의 승리!\n");
						YourScore++;
					}
					else if (InputNum == PAPERS)
					{
						printf("보]\n");
						printf("당신의 패배..\n");
						ComputerScore++;
					}
					else
					{
						printf("가위]\n");
						printf("무승부!\n");
					}
					break;
				case PAPERS:
					printf("컴퓨터 : [보]\n");
					printf("당신	: [");
					if (InputNum == SCISSORS)
					{
						printf("가위]\n");
						printf("당신의 승리!\n");
						YourScore++;
					}
					else if (InputNum == ROCK)
					{
						printf("바위]\n");
						printf("당신의 패배..\n");
						ComputerScore++;
					}
					else
					{
						printf("보]\n");
						printf("무승부!\n");
					}
					break;
				default:
					printf("input err");
					break;
			}

			printf("-------------------------------------------------------------------\n");
			printf("\n");
		}

		if (YourScore == 3)
			printf("You Won!\n\n");
		else
			printf("You Lose...\n\n");

	}

	{
		// UpDown
		// - 1 ~ 100 사이의 숫자 선택, 업다운 룰과 같이 시작
		// - 5번안에 맞춰야함
		printf("UpDown 게임!\n");
		int Target = rand() % 100 + 1;
		int Input = 0;
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			printf("예상 숫자: ");
			cin >> Input;
			if (Input == Target)
			{
				printf("You Won!\n\n");
				break;
			}
			else if (Input > Target)
			{
				printf("Down!\n");
			}
			else if (Input < Target)
			{
				printf("Up!\n");
			}
		}

		if (i == 5)
			printf("You Lose... Target was %d\n\n", Target);
	}


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

		enum EPlayerState
		{
			IDLE,
			JUMP,
			ATTACK,
			INVINCIBLE,
		};

		int PlayerState = 0;
		PlayerState |= (1 << IDLE);
		printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
			(PlayerState & (1 << IDLE)) ? 'O' : 'X', (PlayerState & (1 << JUMP)) ? 'O' : 'X', (PlayerState & (1 << ATTACK)) ? 'O' : 'X', (PlayerState & (1 << INVINCIBLE)) ? 'O' : 'X');
		printf("------------------------------------------------------------------\n");

		printf("점프 상태 추가\n");
		PlayerState |= (1 << JUMP);
		printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
			(PlayerState & (1 << IDLE)) ? 'O' : 'X', (PlayerState & (1 << JUMP)) ? 'O' : 'X', (PlayerState & (1 << ATTACK)) ? 'O' : 'X', (PlayerState & (1 << INVINCIBLE)) ? 'O' : 'X');
		printf("------------------------------------------------------------------\n");

		printf("공격 상태 추가\n");
		PlayerState |= (1 << ATTACK);
		printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
			(PlayerState & (1 << IDLE)) ? 'O' : 'X', (PlayerState & (1 << JUMP)) ? 'O' : 'X', (PlayerState & (1 << ATTACK)) ? 'O' : 'X', (PlayerState & (1 << INVINCIBLE)) ? 'O' : 'X');
		printf("------------------------------------------------------------------\n");

		printf("대기 상태 해제\n");
		PlayerState &= ~(1 << IDLE);
		printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
			(PlayerState & (1 << IDLE)) ? 'O' : 'X', (PlayerState & (1 << JUMP)) ? 'O' : 'X', (PlayerState & (1 << ATTACK)) ? 'O' : 'X', (PlayerState & (1 << INVINCIBLE)) ? 'O' : 'X');
		printf("------------------------------------------------------------------\n");

		printf("무적 상태 추가\n");
		PlayerState |= (1 << INVINCIBLE);
		printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
			(PlayerState & (1 << IDLE)) ? 'O' : 'X', (PlayerState & (1 << JUMP)) ? 'O' : 'X', (PlayerState & (1 << ATTACK)) ? 'O' : 'X', (PlayerState & (1 << INVINCIBLE)) ? 'O' : 'X');
		printf("------------------------------------------------------------------\n");

		printf("무적 상태 토글(XOR 사용)\n");
		PlayerState ^= (1 << INVINCIBLE);
		printf("현재 상태 \n 대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n",
			(PlayerState & (1 << IDLE)) ? 'O' : 'X', (PlayerState & (1 << JUMP)) ? 'O' : 'X', (PlayerState & (1 << ATTACK)) ? 'O' : 'X', (PlayerState & (1 << INVINCIBLE)) ? 'O' : 'X');
		printf("------------------------------------------------------------------\n");
	}

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

		int yourDice = 0;
		int ComputerDice = 0;
		int round = 1;
		bool IsComputerWon = false;

		while(true)
		{
			printf("--------------------- %d 회차 ------------\n", round);
			printf("  당신의 소지금 : %d\n", YourDePosit);
			printf("컴퓨터의 소지금 : %d\n\n", ComputerDePosit);
			printf("주사위 던지기\n");
			yourDice = rand() % 6 + 1;
			ComputerDice = rand() % 6 + 1;

			printf("  당신의 주사위 : %d\n", yourDice);
			printf("컴퓨터의 주사위 : %d\n\n", ComputerDice);

			printf("배팅\n");

			int min = YourDePosit >= ComputerDePosit ? ComputerDePosit : YourDePosit;
			int bet = 0;
			// 직전에 컴퓨터가 진 경우 컴퓨터가 임의 배팅
			if (!IsComputerWon)
			{
				bet = rand() % min + 1;
				printf("컴퓨터의 배팅 금액 = %d\n\n", bet);
			}
			else
			{
				int InputNumber = 0;
				while (true)
				{
					printf("배팅 금액 입력 : ");
					cin >> InputNumber;
					cin.clear();				<---------------------------------------------------------------- 에러 상태 해제
					cin.ignore(10000, '\n')		<---------------------------------------------------------------- 버퍼 지우기
					if (InputNumber <= 0 || InputNumber > min)
						printf("베팅 금액은 1이상이어야 하고 두사람의 소지금액 이하여야 합니다.\n\n");
					else
					{
						bet = InputNumber;
						break;
					}
					printf("당신의 배팅 금액 = %d\n\n", bet);
				}
			}


			printf("주사위 던지기\n");
			int nyourDice = rand() % 6 + 1;
			int nComputerDice = rand() % 6 + 1;

			int yourDiceAmount = nyourDice + yourDice;
			int ComputerDiceAmount = nComputerDice + ComputerDice;

			printf("  당신의 주사위 : %d\n", nyourDice);
			printf("컴퓨터의 주사위 : %d\n\n", nComputerDice);

			printf("  당신의 주사위 총 합: %d\n", yourDiceAmount);
			printf("컴퓨터의 주사위 총 합: %d\n\n", ComputerDiceAmount);

			if (yourDiceAmount > ComputerDiceAmount)
			{
				printf("당신의 승리!\n");
				YourDePosit += bet;
				ComputerDePosit -= bet;
				IsComputerWon = false;
			}
			else if (yourDiceAmount < ComputerDiceAmount)
			{
				printf("당신의 패배!\n");
				YourDePosit -= bet;
				ComputerDePosit += bet;
				IsComputerWon = true;
			}
			else if (yourDiceAmount == ComputerDiceAmount)
			{
				printf("무승부!\n");
				IsComputerWon = false;
			}

			if (YourDePosit == 0)
			{
				printf("당신의 패배로 게임이 종료 되었습니다.\n\n");
				break;
			}
			else if (ComputerDePosit == 0)
			{
				printf("컴퓨터의 패배로 게임이 종료 되었습니다.\n\n");
				break;
			}

			round++;
		}

	}

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
		int Deposit = 100;
		int YourChoice = 0;
		int ComputerChoice = 0;
		int round = 1;
		int bet = 0;
		bool IsPlayerWon = false;
		bool IsTryStreak = false;

		while (true)
		{
			printf("\n---------%d회차-----------\n", round);
			printf("현재 잔액 : %d\n\n", Deposit);

			while (true)
			{
				if (IsTryStreak) break;

				printf("배팅을 하세요!\n");
				cin >> bet;

				if (bet < 0 || bet > Deposit)
				{
					printf("베팅 금액은 0이상이어야 하고 소지금액 이하여야 합니다.\n\n");
				}
				else
				{
					Deposit -= bet;
					break;
				}
			}
			printf("배팅금 : %d\n", bet);

			printf("홀짝을 선택하세요\n");
			printf("[1. 홀 ]	[2. 짝 ]\n");
			cin >> YourChoice;
			ComputerChoice = rand() % 2 + 1;

			printf("결과 : %s\n", ComputerChoice == 1 ? "홀" : "짝");
			if (YourChoice == ComputerChoice)
			{
				printf("적중 했습니다!.");
				IsPlayerWon = true;

				printf("\n\n");
				printf("연승 도전 여부를 선택하세요!");
				printf("[1. 수락 ]	[2. 거부 ]\n");
				int inputNum = 0;
				cin >> inputNum;
				IsTryStreak = !(inputNum - 1);

				if (IsTryStreak)
				{
					bet *= 2;
				}
				else
				{
					Deposit += bet * 2;
				}

			}
			else
			{
				printf("패배 했습니다!.");
				IsPlayerWon = false;

				if (Deposit < 100)
				{
					printf("소지금이 부족해 강제로 종료 됩니다.\n\n");
					break;

				}
			}
			round++;
		}
	}
*/