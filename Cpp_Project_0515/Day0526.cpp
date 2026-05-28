#include <iostream>
#include <stdlib.h>
#include "Day0526.h"

using namespace std;

void Day0526_Run1()
{
	//int Array[5] = { 1,2,3,4,5 };
	//int* pArray = Array;
	//
	//// 같은 결과, 배열의 이름은 포인터
	////Day0526_PointerParameter(pArray, 5);
	//Day0526_PointerParameter(Array, 5);

	//int a = 10;
	//int b = 90;

	//printf("before: %d, %d\n", a, b);
	//Day0526_Example01(&a, &b);
	//printf("after: %d, %d\n", a, b);

	//int Max = Day0526_Example02(Array, 5);
	//printf("배열의 최댓값은 %d 입니다\n", Max);

	//printf("before: ");
	//Day0526_PointerParameter(Array, 5);
	//Day0526_Example03(Array, 5);
	//printf("after: ");
	//Day0526_PointerParameter(Array, 5);

	//int* Alloc = new int(5);
	//delete Alloc;
	//Alloc = nullptr;

	//int* Alloc2 = new int[10];
	//delete[]  Alloc2;
	//Alloc2 = nullptr;

	Homework05_Run();
}

void Day0526_PointerParameter(int* Data, int Size)
{
	for (auto i = 0; i < Size; i++)
	{
		printf("%d ", *(Data + i));
	}
	printf("\n");
}

void Day0526_Example01(int* a, int* b)
{
	//1. 두 변수의 값을 변경하는 함수 만들기
	//	swap(a, b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Day0526_Example02(int* Arr, int Size)
{
	/*2. 포인터를 이용해 배열의 최댓값 찾기
		인덱스 사용 금지*/

	int Max = INT32_MIN;
	for (int i = 0; i < Size; i++)
		Max = (*(Arr + i) > Max) ? *(Arr + i) : Max;

	return Max;
}

void Day0526_Example03(int* Arr, int Size)
{
	//3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
	int* Left = Arr;
	int* Right = (Arr + Size - 1);
	while (Right > Left)
	{
		int temp = *Left;
		*Left = *Right;
		*Right = temp;
		Left++;
		Right--;

	}
}


/*
1차원 배열을 할당받아서 2차원 배열처럼 사용하기
주말과제의 Maze를 int* Maze;로 변경해보기
미로 탈출 게임에 랜덤 인카운터 종류 늘려보기
*/


#pragma region Maze
//U, D, L, R 순의 방향 벡터
const int Dx[4] = { -1, 1, 0, 0 };
const int Dy[4] = { 0, 0, -1, 1 };

// 랜덤으로 적을 만날 확률
const int RandEncounterPerCentage = 30;

const int MazeRows = 10;
const int MazeCols = 20;

int Day0526PlayerX = 0;
int Day0526PlayerY = 0;

//int Maze[MazeRows][MazeCols] =
//{
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//	{1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1},
//	{1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1},
//	{1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,3,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};

//int Maze[MazeRows*MazeCols] =
//{
//	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//	1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,
//	1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,
//	1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,
//	1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,
//	1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,
//	1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,
//	1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
//	1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,3,1,
//	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
//};

int* Day0526Maze = nullptr;

int Day0526RandomRange(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

int Day0526RandomRange(int Max)
{
	return Day0526RandomRange(0, Max);
}

void Day0526Print2DMap()
{

	for (int i = 0; i < MazeRows; i++)
	{
		for (int j = 0; j < MazeCols; j++)
		{
			Day0526EMapEnv TileData = Day0526GetMazeData(i, j);
			if ((i == Day0526PlayerX) && (j == Day0526PlayerY))
				printf("%c", 'P');
			else if (TileData == ROAD)
				printf("%c", '.');
			else if (TileData == WALL)
				printf("%c", '#');
			else if (TileData == START)
				printf("%c", 'S');
			else if (TileData == END)
				printf("%c", 'E');

		}
		printf("\n");

	}
}

void Day0526CheckDirCanGO(bool* DirArr, int PlayerX, int PlayerY)
{

	// 상 하 좌 우 방향으로 갈 수 있는지 기록
	for (int i = 0; i < 4; i++)
	{
		// 다음 좌표
		int NextX = PlayerX + Dx[i];
		int NextY = PlayerY + Dy[i];

		// 다음 좌표가 맵의 밖이면 불가
		if (NextX < 0 || NextX >= MazeRows || NextY < 0 || NextY >= MazeCols)
		{
			DirArr[i] = false;
			continue;
		}

		// 다음 좌표가 벽이면 불가
		if (Day0526GetMazeData(NextX, NextY) == WALL)
		{
			DirArr[i] = false;
			continue;
		}

		//나머지 경우는 가능
		DirArr[i] = true;
	}
}

void Day0526PrintChoiceScreen(bool* DirArr)
{
	printf("이동할 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽)\n");
	for (int i = 0; i < EDirLength; i++)
	{
		if (DirArr[i] == false) continue;
		switch (Day0526EDir(i))
		{
			case UP:
				printf("w(↑) ");
				break;
			case Down:
				printf("s(↓) ");
				break;
			case Right:
				printf("d(→) ");
				break;
			case Left:
				printf("a(←) ");
				break;
		}
	}
	printf("\n");
	printf("방향 입력: ");
}

int Day0526GetDirInput()
{
	char Input;
	cin >> Input;
	cin.clear();
	cin.ignore(10000, '\n');
	if (Input == 'w' || Input == 'W')
		return UP;
	if (Input == 's' || Input == 'S')
		return Down;
	if (Input == 'a' || Input == 'A')
		return Left;
	if (Input == 'd' || Input == 'D')
		return Right;

	return EDirLength;
}

int Day0526RandEncounter()
{
	/*
	EncounterNone	= 0, (50)
	EncounterCombat	= 1, (15)
	EncounterHeal	= 2, (20)
	EncounterTrap	= 3, (15)
	*/
	// 0부터 100까지 랜덤값이 29보다 작으면 (30프로)
	// Todo 검즘 한번하기
	int Flag = 0;
	int RandVal = Day0526RandomRange(100);
	if (RandVal < 50)
	{
		return Flag;
	}
	else if (RandVal < 65)
	{
		Flag |= (1 << EncounterCombat);
		return Flag;
	}
	else if (RandVal < 85)
	{
		Flag |= (1 << EncounterHeal);
		return Flag;
	}
	else if (RandVal < 100)
	{
		Flag |= (1 << EncounterTrap);
		return Flag;
	}

	return Flag;
}

void Day0526PrintHP(int YourHP, int MonsterHP)
{
	printf("\n당신의 체력: %d\n", YourHP);
	printf("몬스터의 체력: %d\n\n", MonsterHP);
}

void Day0526PrintHP(int YourHP)
{
	printf("\n당신의 체력: %d\n", YourHP);
}

int Day0526RollDice(int DiceMax)
{
	int Res = Day0526RandomRange(1, DiceMax);
	printf("주사위의 눈 : %d\n", Res);
	return Res;
}

int Day0526GetAttackDamage(int BaseDamage, int DiceMax)
{

	// 여기서 입력할때까지 대기

	cin.get();
	return BaseDamage + Day0526RollDice(DiceMax);
}

bool Day0526IsCritical(int CriticalPercentage)
{
	if (Day0526RandomRange(100) < CriticalPercentage)
		return true;
	return false;
}

bool Day0526TurnBasedCombat(int PlayerHp)
{
	const int BaseDamage = 5;
	const int DiceMax = 10;
	const int CriticalPercentage = 10;

	int YourHP = PlayerHp;
	int MonsterHP = 15;
	bool IsCrit = false;

	int Damage = 0;
	int FinalDamage = 0;

	printf("\n!적을 만났습니다!\n");
	printf("엔터를 눌러서 적과의 전투를 시작해 주세요\n");
	cin.get();

	while (0 < MonsterHP && 0 < YourHP)
	{
		//-----------------------
		//1. 당신의 턴			|
		//-----------------------
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;

		system("cls");

		printf("\n-----------------당신의 차례------------------------\n");
		Day0526PrintHP(YourHP, MonsterHP);

		printf("10면체 주사위를 굴려 5 + [주사위 눈금]의 데미지를 줄 수 있습니다.");
		printf("엔터를 눌러서 주사위를 굴려주세요\n");

		//데미지 산출 
		Damage = Day0526GetAttackDamage(BaseDamage, DiceMax);
		//최종 데미지 계산
		IsCrit = Day0526IsCritical(CriticalPercentage);
		FinalDamage = IsCrit ? Damage * 2 : Damage;
		// 공격 처리
		MonsterHP -= FinalDamage;
		if (IsCrit)
			printf("\n 크리티컬이 발생하여");

		printf("%d의 데미지로 적을 공격했습니다!.\n", FinalDamage);

		// 종료조건 체크
		if (MonsterHP <= 0 || YourHP <= 0) break;
		printf("엔터를 눌러 턴을 넘기세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();


		printf("\n-----------------몬스터 차례------------------------\n");
		//-----------------------
		//2. 몬스터 턴			|
		//-----------------------
		Day0526PrintHP(YourHP, MonsterHP);
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;

		printf("엔터를 눌러 적의 주사위를 확인하세요\n");

		//데미지 산출 
		Damage = Day0526GetAttackDamage(BaseDamage, DiceMax);
		//최종 데미지 계산
		IsCrit = Day0526IsCritical(CriticalPercentage);
		FinalDamage = IsCrit ? Damage * 2 : Damage;
		// 공격 처리
		YourHP -= FinalDamage;
		if (IsCrit)
			printf("\n 크리티컬이 발생하여");

		printf("%d의 데미지로공격 받았습니다!.\n", FinalDamage);

		if (MonsterHP <= 0 || YourHP <= 0) break;
		printf("엔터를 눌러 내턴을 시작하세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();
	}

	if (MonsterHP <= 0)
	{
		printf("당신이 승리하였습니다.");
		return true;
	}

	printf("당신이 패배하였습니다.");
	return false;
}

void Homework05_Run()
{
	const int InitailPlayerHp = 100;
	Day0526Maze = new int[MazeCols * MazeRows]
		{
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1,
			1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
			1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
			1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
			1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 3, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
	printf("미로게임 턴제 전투 만들기\n");
	// 0.초기값 설정
	//다음을 반복
		// 1. 격자 출력
		// 2. 이동 가능 방향 판단
		// 3. 이동 가능 방향 출력
		// 4. 플레이어 입력
		// 5. 이동

		// 7. 종료조건 확인

	bool CanGo[EDirLength] = { false, false, false, false };

	// 시작 좌표 설정
	Day0526PlayerX = 1;
	Day0526PlayerY = 1;
	int Dir = EDirLength;

	int PlayerHp = InitailPlayerHp;

	//탈출까지 반복
	while (true)
	{
		system("cls");
		// 0. 격자맵 출력
		Day0526Print2DMap();
		
		Day0526PrintHP(PlayerHp);
		// 1. 이동가능 방향 판단
		Day0526CheckDirCanGO(CanGo, Day0526PlayerX, Day0526PlayerY);


		// 3. 이동 방향 입력
		while (Dir == EDirLength)
		{
			// 이동 선택 화면 출력
			Day0526PrintChoiceScreen(CanGo);
			Dir = Day0526GetDirInput();
			if (Dir == EDirLength || CanGo[Dir] == false)
			{
				printf("\n\n올바른 방향을 입력하세요\n\n");
				Dir = EDirLength;
			}
		}
		// 4.이동처리
		Day0526PlayerX += Dx[Dir];
		Day0526PlayerY += Dy[Dir];

		// 5. 종료 확인
		if (Day0526GetMazeData(Day0526PlayerX, Day0526PlayerY) == END)
		{
			printf("탈출하였습니다! \n");
			break;
		}


		// 6. 일정확률로 적을 만남 (현재는 한번만 만남, 이래야 테스트 원활)
		bool bWon = false;
		int EncounterFlag = Day0526RandEncounter();
		if (EncounterFlag != EncounterNone)
		{
			
			if (EncounterFlag & 1 << EncounterCombat)
			{
				bWon = Day0526TurnBasedCombat(InitailPlayerHp);
				if (!bWon) break;
			}
			else if (EncounterFlag & 1 << EncounterHeal)
			{
				PlayerHp += 10;
				printf("쉼터를 만나 체력을 10 회복 합니다\n");

			}
			else if (EncounterFlag & 1 << EncounterTrap)
			{
				PlayerHp -= 10;
				printf("함정에 걸려 현제 체력이 10 감소 합니다.\n");
			}

			printf("계속 탈출하려면 아무키나 누르세요");
			cin.get();
		}


		// 입력 변수 초기화
		Dir = EDirLength;
	}
	delete[] Day0526Maze;
	Day0526Maze = nullptr;
}
Day0526EMapEnv Day0526GetMazeData(int X, int Y)
{
	return Day0526EMapEnv(Day0526Maze[Y * MazeCols + X]);
}

void Day0526SetMazeData(int X, int Y, Day0526EMapEnv Data)
{
	Day0526Maze[Y * MazeCols + X] = Data;
}
#pragma endregion
