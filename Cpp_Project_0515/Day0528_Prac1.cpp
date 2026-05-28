#include <iostream>
#include <fstream>

#include "Day0528_Prac1.h"
using namespace std;

int MazeRows = 10;
int MazeCols = 20;

int* Maze = nullptr;

void Day0528_Prac1_Run()
{
	Day0528_MazeAdventure();
}

int RandomRange(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

int RandomRange(int Max)
{
	return RandomRange(0, Max);
}

EMapEnv GetMazeData(int X, int Y)
{
	return EMapEnv(Maze[X * MazeCols + Y]);
}

void SetMazeData(int X, int Y, EMapEnv Data)
{
	Maze[X * MazeCols + Y] = Data;
}

void Print2DMap(Player& player)
{

	for (int i = 0; i < MazeRows; i++)
	{
		for (int j = 0; j < MazeCols; j++)
		{
			EMapEnv TileData = GetMazeData(i, j);
			if ((i == player.PosX) && (j == player.PosY))
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

void CheckDirCanGO(bool* DirArr, struct Player& player)
{

	// 상 하 좌 우 방향으로 갈 수 있는지 기록
	for (int i = 0; i < 4; i++)
	{
		// 다음 좌표
		int NextX = player.PosX + Dx[i];
		int NextY = player.PosY + Dy[i];

		// 다음 좌표가 맵의 밖이면 불가
		if (NextX < 0 || NextX >= MazeRows || NextY < 0 || NextY >= MazeCols)
		{
			DirArr[i] = false;
			continue;
		}

		// 다음 좌표가 벽이면 불가
		if (GetMazeData(NextX, NextY) == WALL)
		{
			DirArr[i] = false;
			continue;
		}

		//나머지 경우는 가능
		DirArr[i] = true;
	}
}

void PrintChoiceScreen(bool* DirArr)
{
	printf("이동할 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽)\n");
	for (int i = 0; i < EDirLength; i++)
	{
		if (DirArr[i] == false) continue;
		switch (EDir(i))
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

int GetDirInput()
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

int RandEncounter()
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
	int RandVal = RandomRange(100);
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

void PrintHP(float YourHP, float MonsterHP)
{
	printf("\n당신의 체력: %.1f\n", YourHP);
	printf("몬스터의 체력: %.1f\n\n", MonsterHP);
}

int RollDice(int DiceMax)
{
	int Res = RandomRange(1, DiceMax);
	printf("주사위의 눈 : %d\n", Res);
	return Res;
}

int GetAttackDamage(float BaseDamage, int DiceMax)
{

	// 여기서 입력할때까지 대기

	cin.get();
	return (int)BaseDamage + RollDice(DiceMax);
}

bool IsCritical(int CriticalPercentage)
{
	if (RandomRange(100) < CriticalPercentage)
		return true;
	return false;
}

bool TurnBasedCombat(struct Player& player)
{
	const int DiceMax = 10;


	Enemy Orc(rand() / (float)RAND_MAX);

	bool IsCrit = false;
	int Damage = 0;
	int FinalDamage = 0;

	printf("\n!적을 만났습니다!\n");
	printf("엔터를 눌러서 적과의 전투를 시작해 주세요\n");
	cin.get();

	while (0 < Orc.HP && 0 < player.HP)
	{
		//-----------------------
		//1. 당신의 턴			|
		//-----------------------
		// 값 초기화
		IsCrit = false;

		system("cls");

		printf("\n-----------------당신의 차례------------------------\n");
		PrintHP(player.HP, Orc.HP);

		printf("10면체 주사위를 굴려 5 + [주사위 눈금]의 데미지를 줄 수 있습니다.");
		printf("엔터를 눌러서 주사위를 굴려주세요\n");

		//데미지 산출 
		Damage = GetAttackDamage(player.BaseAttackDamage, DiceMax);
		//최종 데미지 계산
		IsCrit = IsCritical(player.CriticalPercentage);
		FinalDamage = IsCrit ? Damage * 2 : Damage;
		// 공격 처리
		Orc.HP -= FinalDamage;
		if (IsCrit)
			printf("\n 크리티컬이 발생하여");

		printf("%d의 데미지로 적을 공격했습니다!.\n", (int)FinalDamage);

		// 종료조건 체크
		if (Orc.HP <= 0 || player.HP <= 0) break;
		printf("엔터를 눌러 턴을 넘기세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();


		printf("\n-----------------몬스터 차례------------------------\n");
		//-----------------------
		//2. 몬스터 턴			|
		//-----------------------
		PrintHP(player.HP, Orc.HP);
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;

		printf("엔터를 눌러 적의 주사위를 확인하세요\n");

		//데미지 산출 
		Damage = GetAttackDamage(Orc.AttackDamage, DiceMax);
		//최종 데미지 계산
		IsCrit = IsCritical(Orc.CriticalPercentage);
		FinalDamage = IsCrit ? Damage * 2 : Damage;
		// 공격 처리
		player.HP -= FinalDamage;
		if (IsCrit)
			printf("\n 크리티컬이 발생하여");

		printf("%d(기본 데미지) + 주사위 = %d 데미지로공격 받았습니다!.\n", (int)Orc.AttackDamage, (int)FinalDamage);

		if (Orc.HP <= 0 || player.HP <= 0) break;
		printf("엔터를 눌러 내턴을 시작하세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();
	}

	if (Orc.HP <= 0)
	{
		printf("당신이 승리하였습니다.");
		printf("보상으로 %d원을 획득합니다.", Orc.Reward);
		player.Money += Orc.Reward;
		return true;
	}

	printf("당신이 패배하였습니다.");
	return false;
}

void InitMap()
{
	const string FilePath = "./Data/MapData.txt";
	std::string FileContents;

	std::ifstream InputFile(FilePath);
	if (InputFile.is_open())
	{
		FileContents = string (
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);

		printf("파일 내용 \n%s\n", FileContents.c_str());
		InputFile.close();
	}
	else
	{
		//파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.");
	}

	size_t PosBefore = 0;
	size_t Pos = FileContents.find('\n');
	string OneStringLine = "";

	for (int i = (int)PosBefore; i < (int)Pos; i++)
		OneStringLine += FileContents[i];

	// 크기 추출
	size_t commaPos = OneStringLine.find(',');

	string ColString = OneStringLine.substr(0, commaPos);
	string RowString = OneStringLine.substr(commaPos + 1);

	MazeRows = atoi(RowString.c_str());
	MazeCols = atoi(ColString.c_str());

	Maze = new int[MazeRows * MazeCols];
	int indexX = 0;

	for (int i = (int)(Pos+1); FileContents[i] != '\0'; i++)
	{
		if (FileContents[i] == ',') continue;
		if (FileContents[i] == '\n') continue;
		*(Maze + indexX) = FileContents[i] - '0';
		//Maze[indexX] = FileContents[i] - '0';
		indexX++;
	}
}

void Day0528_MazeAdventure()
{
	InitMap();
	
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

	int StartX = 0;
	int StartY = 0;

	FindStart(StartX, StartY);

	Player player{ StartX, StartY };
	int Dir = EDirLength;


	//탈출까지 반복
	while (true)
	{
		system("cls");
		// 0. 격자맵 출력
		Print2DMap(player);

		PrintStatus(player);
		// 1. 이동가능 방향 판단
		CheckDirCanGO(CanGo, player);


		// 3. 이동 방향 입력
		while (Dir == EDirLength)
		{
			// 이동 선택 화면 출력
			PrintChoiceScreen(CanGo);
			Dir = GetDirInput();
			if (Dir == EDirLength || CanGo[Dir] == false)
			{
				printf("\n\n올바른 방향을 입력하세요\n\n");
				Dir = EDirLength;
			}
		}
		// 4.이동처리
		player.PosX += Dx[Dir];
		player.PosY += Dy[Dir];

		// 5. 종료 확인
		if (GetMazeData(player.PosX, player.PosY) == END)
		{
			printf("탈출하였습니다! \n");
			break;
		}


		// 6. 일정확률로 적을 만남 (현재는 한번만 만남, 이래야 테스트 원활)
		bool bWon = false;
		int EncounterFlag = RandEncounter();
		if (EncounterFlag != EncounterNone)
		{

			if (EncounterFlag & 1 << EncounterCombat)
			{
				bWon = TurnBasedCombat(player);
				if (!bWon) break;
			}
			else if (EncounterFlag & 1 << EncounterHeal)
			{
				player.HP += 10;
				printf("쉼터를 만나 체력을 10 회복 합니다\n");

			}
			else if (EncounterFlag & 1 << EncounterTrap)
			{
				player.HP -= 10;
				printf("함정에 걸려 현제 체력이 10 감소 합니다.\n");
				if (player.HP <= 0)
				{
					printf("사망하였습니다");
					break;
				}
			}

			printf("계속 탈출하려면 아무키나 누르세요");
			cin.get();
		}


		// 입력 변수 초기화
		Dir = EDirLength;
	}
	delete[] Maze;
	Maze = nullptr;
}

void FindStart(int& OutX, int& OutY)
{
	for (int y = 0; y < MazeCols; y++)
	{
		for (int x = 0; x < MazeRows; x++)
		{
			if (GetMazeData(x, y) == START)    // 플레이어 시작점을 찾았으면
			{
				OutX = x;
				OutY = y;
				return;     // 저장하고 함수 종료
			}
		}
	}
	OutX = -1; // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
	OutY = -1;
}

void PrintStatus(Player& player)
{
	printf("\n당신의   체력: %.1f", player.HP);
	printf("\n당신의 소지금: %d\n", player.Money);
}
