#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MazePrac.h"

using namespace std;

int MazeRows = 10;
int MazeCols = 20;

int* Maze = nullptr;

void MazePrac1_Run()
{
	MazeAdventure();
}

EMapEnv GetMazeData(int X, int Y)
{
	return EMapEnv(Maze[X * MazeCols + Y]);
}

EMapEnv GetMazeData(Position* Pos)
{
	return EMapEnv(Maze[Pos->X * MazeCols + Pos->Y]);
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

			Position TargetPos(i,j);
			if (*(player.GetPos()) == TargetPos)
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

void CheckDirCanGO(bool* DirArr, Player& player)
{
	// 상 하 좌 우 방향으로 갈 수 있는지 기록
	for (int i = 0; i < 4; i++)
	{
		// 다음 좌표
		int NextX = player.GetPos()->X + Dx[i];
		int NextY = player.GetPos()->Y + Dy[i];

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

	int Flag = 0;

	int RandVal = RandomRange(100);
	if (RandEncounterNone <= RandVal && RandVal < RandEncounterCombat)
	{
		Flag |= (1 << EncounterCombat);
	}
	else if (RandVal < RandEncounterHeal)
	{
		Flag |= (1 << EncounterHeal);
	}
	else if (RandVal < RandEncounterTrap)
	{
		Flag |= (1 << EncounterTrap);
	}

	return Flag;
}

int GetRandMonsterIndex()
{

	int Res = -1;
	int RandVal = RandomRange(100);
	if (RandVal < RandMonsterOrc)
	{
		Res = 0;
	}
	else if (RandVal < RandMonsterSlime)
	{
		Res = 1;
	}
	else if (RandVal < RnadMonsterWyvern)
	{
		Res = 2;
	}

	return Res;
}

void PrintHP(Player& InPlayer, Monster& InMonster)
{
	printf("\n당신의 체력: %d\n", InPlayer.GetHp());
	printf("%s의 체력: %d\n\n",InMonster.GetNmase().c_str(), InMonster.GetHp());
}

int RollDice(int DiceMax)
{
	int Res = RandomRange(1, DiceMax);
	printf("주사위의 눈 : %d\n", Res);
	return Res;
}

int GetAdditiveDamageByDice(int DiceMax)
{
	// 여기서 입력할때까지 대기
	cin.get();
	return RollDice(DiceMax);
}


bool TurnBasedCombat(Player* player)
{
	const int DiceMax = 10;
	bool bPlayerWon = false;


	// 랜덤 몬스터
	Monster* monsterArr[3];
	monsterArr[0] = new Orc();
	monsterArr[1] = new Slime();
	monsterArr[2] = new Wyvern();

	int monsterIndex = GetRandMonsterIndex();

	Monster* monster = monsterArr[monsterIndex];

	int AdditiveDamage = 0;

	printf("\n!적을 만났습니다!\n");
	printf("엔터를 눌러서 적과의 전투를 시작해 주세요\n");
	cin.get();

	while (0 < monster->GetHp() && 0 < player->GetHp())
	{
		//-----------------------
		//1. 당신의 턴			|
		//-----------------------
		// 값 초기화

		system("cls");

		printf("\n-----------------당신의 차례------------------------\n");
		PrintHP(*player, *monster);

		printf("10면체 주사위를 굴려 5 + [주사위 눈금]의 데미지를 줄 수 있습니다.");
		printf("엔터를 눌러서 주사위를 굴려주세요\n");

		//데미지 산출 
		AdditiveDamage = GetAdditiveDamageByDice(DiceMax);

		// 공격 처리
		player->ApplyDamage(monster, AdditiveDamage);

		// 종료조건 체크
		if (monster->GetHp() <= 0 || player->GetHp() <= 0) break;
		printf("엔터를 눌러 턴을 넘기세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();


		printf("\n-----------------몬스터 차례------------------------\n");
		//-----------------------
		//2. 몬스터 턴			|
		//-----------------------
		PrintHP(*player, *monster);
		// 값 초기화
		AdditiveDamage = 0;

		printf("엔터를 눌러 적의 주사위를 확인하세요\n");

		//데미지 산출 
		AdditiveDamage = GetAdditiveDamageByDice(DiceMax);

		// 공격 처리
		monster->ApplyDamage(player, AdditiveDamage);

		if (monster->GetHp() <= 0 || player->GetHp() <= 0) break;
		printf("엔터를 눌러 내턴을 시작하세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();
	}

	if (monster->GetHp() <= 0)
	{
		printf("당신이 승리하였습니다.");
		int RewardVal = monster->GetRewardValue();
		printf("보상으로 %d원을 획득합니다.", RewardVal);
		player->GetReward(RewardVal);
		bPlayerWon =  true;
	}

	if (player->GetHp() <= 0)
	{
		printf("당신이 패배하였습니다.");
		bPlayerWon = false;
	}



	return bPlayerWon;
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

void MazeAdventure()
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

		player.PrintStatus();
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
		//player.MoveTo(Dx[Dir], Dy[Dir]);
		Position Delta(Dx[Dir], Dy[Dir]);
		*(player.GetPos()) += Delta;

		// 5. 종료 확인
		if (GetMazeData(player.GetPos()) == END)
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
				bWon = TurnBasedCombat(&player);
				if (!bWon) break;
			}
			else if (EncounterFlag & 1 << EncounterHeal)
			{
				player.TakeHeal(RandEncounterHealAmout);
				printf("쉼터를 만나 체력을 10 회복 합니다\n");

			}
			else if (EncounterFlag & 1 << EncounterTrap)
			{
				player.TakeDamage(nullptr, RandEncounterTrapDealAmout);
				printf("함정에 걸려 현제 체력이 10 감소 합니다.\n");
				if (player.GetHp() <= 0)
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

