#include <iostream>
#include "Day0522.h"

using namespace std;

// 미로 배열
int Day0526Maze[MazeRows][MazeCols] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
	{1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
	{1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1},
	{1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,3,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void Day0522_Run()
{
	//Day0522_Array_Exaple01();
	//Day0522_Array_Exaple02();
	//Day0522_Array_Exaple03();
	//Day0522_Casting();
	//Day0522_Reference();
	//Day0522_ArrayParameter();
	//Day0522_shuffle();
	//Day0522_Practice01();
	//Day0522_Practice02();
	//Day0522_Practice03();
	//Day0522_Practice04();
}

int GetRandRange(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int GetRandRange(int max)
{
	return GetRandRange(0, max);
}

void Day0522_Array_Exaple01()
{
	//1. 배열 만들고 초기화 후 출력하기 (1,2 차원 전부 다)
	int Arr1[5];
	int ColSize = sizeof(Arr1) / sizeof(int);

	printf("1. 배열 만들고 초기화 후 출력하기 (1,2 차원 전부 다)\n");
	printf("Arr1 : ");

	for (int i = 0; i < ColSize; i++)
		Arr1[i] = GetRandRange(100);

	for (int i = 0; i < ColSize; i++)
		printf("[%d]", Arr1[i]);

	printf("\n\n");

	int Arr2[24][24] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	ColSize = sizeof(Arr2[0]) / sizeof(int);
	int RowSize = sizeof(Arr2) / sizeof(int) / ColSize;

	auto temp = (Arr2[0] + 25);

	for (int i = 0; i < RowSize; i++)
	{
		for (int j = 0; j < ColSize; j++)
		{
			//printf("[%d]", Arr2[i][j]);
			//printf("[%d]", *(*(Arr2 + i) + j));
			printf("[%d]", *(Arr2[0] + i * ColSize + j));
		}
		printf("\n");
	}

	printf("\n");
}

void Day0522_Array_Exaple02()
{
	//2. 배열원소의 값을 모두 더하고 평균 구해보기
	printf("2. 배열원소의 값을 모두 더하고 평균 구해보기\n");
	int Arr1[5];
	int Sum = 0;
	float Avg = 0.0f;
	int ColSize = sizeof(Arr1) / sizeof(int);

	for (int i = 0; i < ColSize; i++)
		Arr1[i] = GetRandRange(100);

	for (int i = 0; i < ColSize; i++)
	{
		printf("[%d]", Arr1[i]);
		Sum += Arr1[i];
	}
	Avg = Sum / (float)ColSize;
	printf(" 평균 : %.1f\n", Avg);
	printf("\n");
}

void Day0522_Array_Exaple03()
{
	//3. 배열의 최대 최소 구해보기
	printf("3. 배열의 최대 최소 구해보기\n");
	int Arr1[5];
	int Min = INT32_MAX;
	int Max = INT32_MIN;
	int ColSize = sizeof(Arr1) / sizeof(int);

	for (int i = 0; i < ColSize; i++)
		Arr1[i] = GetRandRange(100);

	for (int i = 0; i < ColSize; i++)
	{
		printf("[%d]", Arr1[i]);
		if (Arr1[i] <= Min) Min = Arr1[i];
		if (Arr1[i] >= Max) Max = Arr1[i];
	}

	printf(" Min:%d, Max:%d\n", Min, Max);
}

void Day0522_Casting()
{
	int Integer = 10;
	//float Rnum = (float)Integer;
	float Rnum = static_cast<float>(Integer);

}

void Day0522_Reference()
{
	int Num = 10;
	int Target = Num;
	Target = 15;

	// 여기까지 Num의 변화는 없음 (복사하니까)
	// 함수의 매개변수도 마찬가지

	Num = 10;
	int& Target2 = Num;
	Target2 = 15;

	// 이러면 Num의 값이 바뀜
	// 함수의 매개변수도 마찬가지

	int Data1 = 10;
	int Data2 = 20;
	int Data3 = 30;
	Day0522_ReferenceTest(Data1, Data2, Data3);

}

void Day0522_ReferenceTest(int& OutData1, int& OutData2, int& OutData3)
{
	OutData1 += 10;
	OutData2 += 10;
	OutData3 += 30;
}

void Day0522_ArrayParameter()
{
	const int Length = 5;
	int Array[Length] = { 10, 50, 30, 20, 40 };

	Test_ArrayParameter(Array, Length);
}

void Test_ArrayParameter(int* Array, int Length)
{
	for (int i = 0; i < Length; i++)
	{
		printf("%d", Array[i]);
	}
	printf("\n");
}

void Day0522_Print_Array(int* Array, int Length)
{
	for (int i = 0; i < Length; i++)
		printf("%d ", Array[i]);
}

double Day0522_Array_Exaple04(int* Array, int Length)
{
	int Sum = 0;
	float Avg = 0.0f;

	for (int i = 0; i < Length; i++)
		Sum += Array[i];

	return Avg = Sum / (float)Length;
}

int Day0522_Array_Exaple05(int* Array, int Length)
{
	int Max = INT32_MIN;
	int Min = INT32_MAX;

	for (int i = 0; i < Length; i++)
	{
		if (Array[i] < Min)	Min = Array[i];
		if (Array[i] > Max)	Max = Array[i];
	}

	return Max;
}

void Day0522_shuffle()
{
	const int DataSize = 100;
	int Data[DataSize] = { 0, };

	for (int i = 0; i < DataSize; i++)
		Data[i] = i;

	Day0522_Print_Array(Data, DataSize);
	FisherYatesShuffle(Data, DataSize);
	Day0522_Print_Array(Data, DataSize);
}

void FisherYatesShuffle(int* Array, int Length)
{
	//0. 배열의 마지막에서 처음 방향으로 진행
	//1. 현재 인덱스랑 자기 앞의 인덱스 (자기포함)에서 랜덤으로 골라서 swap
	//2. 다음 인덱스로 진행
	//3. 0번 인덱스까지 가면 1회 한 것.

	for (int i = Length - 1; i > 0; i--)
	{
		int Target = rand() % (i + 1);
		int Temp = Array[i];
		Array[i] = Array[Target];
		Array[Target] = Temp;
	}
}

int RollingDice(const int DiceMax)
{
	return rand() % DiceMax + 1;
}

void Day0522_Practice01()
{
	printf("1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기\n");
	// 눈의 개수를 카운팅할 배열 생성
	const int DiceMax = 6;
	int CountArr[DiceMax] = { 0, };

	// 1,000,000 번 반복
	for (int i = 0; i < 1'000'000; i++)
	{
		// 주사위의 눈의 카운팅 값을 증가 시키기
		int DiceRes = RollingDice(DiceMax);
		CountArr[DiceRes - 1]++;
	}

	// 주사위 눈 출력
	for (int i = 0; i < DiceMax; i++)
	{
		printf("[%4d] ", i + 1);
	}
	printf("\n");

	// 배열의 원소 출력(횟수 출력)
	Day0522_Print_Array(CountArr, DiceMax);
	printf("\n");
}

void Day0522_ReverseArray(int* Array, int Size)
{
	int Left = 0;
	int Right = Size - 1;

	// 배열의 처음과 끝에서 시작
	// 해당 칸들의 숫자를 swap
	// Left는 오른쪽 한칸, Right는 왼쪽으로 한칸
	// 서로 겹치지 않을 때까지 반복
	while (Right > Left)
	{
		int temp = Array[Left];
		Array[Left] = Array[Right];
		Array[Right] = temp;

		Left++;
		Right--;
	}
}

void Day0522_Practice02()
{
	printf("2.배열에 저장된 값을 거꾸로 뒤집는 함수 만들기\n");
	const int Length = 10;
	int TargetArray[Length];

	// 배열에 0~100 까지의 값을 넣음
	for (int i = 0; i < Length; i++)
		TargetArray[i] = GetRandRange(100);

	// 뒤집기 전 배열 값 출력
	printf("before : ");
	Day0522_Print_Array(TargetArray, Length);

	// 뒤집기
	printf("\n");
	Day0522_ReverseArray(TargetArray, Length);

	// 뒤집은 후 배열 출력
	printf("after  : ");
	Day0522_Print_Array(TargetArray, Length);
}

//void Day0522_Practice03()
//{
//	printf("3.로또 번호 생성기(셔플알고리즘 활용하기)\n");
//
//	// 크기 45의 배열을 초기화
//	// 자기 인덱스를 초기값으로 가짐
//	const int LottoMax = 45;
//	int LottoArray[LottoMax];
//
//	for (int i = 0; i < LottoMax; i++)
//		LottoArray[i] = i + 1;
//
//	// 배열 셔플
//	FisherYatesShuffle(LottoArray, LottoMax);
//
//	// 앞에서 6개를 뽑아 로또 번호를 생성한다.
//	printf("오늘의 로또 번호! : ");
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", LottoArray[i]);
//	}
//
//	printf("\n");
//}
//
//void Print2DMap(int (*Array)[MazeCols], int RowSize, int ColSize)
//{
//
//	for (int i = 0; i < RowSize; i++)
//	{
//		for (int j = 0; j < ColSize; j++)
//		{
//			if (Array[i][j] == ROAD)
//				printf("%c", '.');
//			else if (Array[i][j] == WALL)
//				printf("%c", '#');
//			else if (Array[i][j] == START)
//				printf("%c", 'S');
//			else if (Array[i][j] == END)
//				printf("%c", 'E');
//			if (Array[i][j] == PLAYER)
//				printf("%c", 'P');
//			if (Array[i][j] == PLAYER + START)
//				printf("%c", 'P');
//		}
//		printf("\n");
//
//	}
//}
//
//void CheckDirCanGO(bool *DirArr, int PlayerX, int PlayerY)
//{
//
//	// 상 하 좌 우 방향으로 갈 수 있는지 기록
//	for (int i = 0; i < 4; i++)
//	{
//		// 다음 좌표
//		int NextX = PlayerX + Dx[i];
//		int NextY = PlayerY + Dy[i];
//
//		// 다음 좌표가 맵의 밖이면 불가
//		if (NextX < 0 || NextX >= MazeRows || NextY < 0 || NextY >= MazeCols)
//		{
//			DirArr[i] = false;
//			continue;
//		}
//
//		// 다음 좌표가 벽이면 불가
//		if (Maze[NextX][NextY] == WALL)
//		{
//			DirArr[i] = false;
//			continue;
//		}
//
//		//나머지 경우는 가능
//		DirArr[i] = true;
//	}
//}
//
//void PrintChoiceScreen(bool* DirArr)
//{
//	printf("이동할 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽)\n");
//	for (int i = 0; i < EDirLength; i++)
//	{
//		if (DirArr[i] == false) continue;
//		switch (EDir(i))
//		{
//			case UP:
//				printf("w(↑) ");
//				break;
//			case Down:
//				printf("s(↓) ");
//				break;
//			case Right:
//				printf("d(→) ");
//				break;
//			case Left:
//				printf("a(←) ");
//				break;
//		}
//	}
//	printf("\n");
//	printf("방향 입력: ");
//}
//
//int GetDirInput()
//{
//	char Input;
//	cin >> Input;
//	if (Input == 'w' || Input == 'W')
//		return UP;
//	if (Input == 's' || Input == 'S')
//		return Down;
//	if (Input == 'a' || Input == 'A')
//		return Left;
//	if (Input == 'd' || Input == 'D')
//		return Right;
//
//	return EDirLength;
//}
//
//void Day0522_Practice04()
//{
//	printf("4.미로 탈출 게임 만들기\n");
//
//	bool CanGo[EDirLength] = { false, false, false, false };
//
//	// 시작 좌표 설정
//	int PlayerX = 1;
//	int PlayerY = 1;
//	int Dir = EDirLength;
//	Maze[PlayerX][PlayerY] += PLAYER;
//
//	//탈출까지 반복
//	while (true)
//	{
//		// 0. 격자맵 출력
//		Print2DMap(Maze, MazeRows, MazeCols);
//
//		// 1. 이동가능 방향 판단
//		CheckDirCanGO(CanGo,PlayerX, PlayerY);
//		
//		
//		// 3. 이동 방향 입력
//		while (Dir == EDirLength)
//		{
//			// 이동 선택 화면 출력
//			PrintChoiceScreen(CanGo);
//			Dir = GetDirInput();
//			if (CanGo[Dir] == false)
//			{
//				printf("올바른 방향을 입력하세요\n");
//				Dir = EDirLength;
//			}
//		}
//		// 4. 다음칸으로 처리 시작
//		Maze[PlayerX][PlayerY] -= PLAYER;
//		PlayerX += Dx[Dir];
//		PlayerY += Dy[Dir];
//
//		// 5. 종료 확인
//		if (Maze[PlayerX][PlayerY] == END)
//			break;
//
//		// 6. 이동처리 종료
//		Maze[PlayerX][PlayerY] += PLAYER;
//
//		
//
//		// 입력 변수 초기화
//		Dir = EDirLength;
//	}
//
//	printf("탈출하였습니다! \n");
//}
//



