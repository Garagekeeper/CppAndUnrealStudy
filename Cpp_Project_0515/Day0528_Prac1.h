#pragma once

//U, D, L, R 순의 방향 벡터
const int Dx[4] = { -1, 1, 0, 0 };
const int Dy[4] = { 0, 0, -1, 1 };

// 랜덤으로 적을 만날 확률
const int RandEncounterPerCentage = 30;

struct Player
{
	int PosX;
	int PosY;
	float HP = 100.0f;
	float BaseAttackDamage = 5.0f;
	int Money = 0;
	const int CriticalPercentage = 10;

	Player(int PosX, int PosY) : PosX(PosX), PosY(PosY), HP(100.0f), BaseAttackDamage(5.0f), Money(0) {}
};

struct Enemy
{
	float HP = 20.0f;
	float AttackDamage = 5.0f;;
	int	  Reward = 10;
	const int CriticalPercentage = 10;

	Enemy(const float Modifier = 1.0f)
	{
		HP += HP * Modifier;
		AttackDamage += AttackDamage * Modifier;
		Reward += (int)(Reward * Modifier);
	}
};

enum EMapEnv
{
	ROAD,
	WALL,
	START,
	END,
	PLAYER,
};

enum EDir
{
	UP,
	Down,
	Left,
	Right,
	EDirLength
};

enum EEncounter
{
	EncounterNone = 0,
	EncounterCombat = 1,
	EncounterHeal = 2,
	EncounterTrap = 3,
};

/// <summary>
/// Min 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Min">랜덤값의 최소</param>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>Min 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Min, int Max);

/// <summary>
/// 0 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>0 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Max);

/// <summary>
/// 해당 위치의 타일 정보를 리턴하는 함수
/// </summary>
/// <param name="X">X좌표</param>
/// <param name="Y">Y좌표</param>
/// <returns>해당 위치의 데이터</returns>
EMapEnv GetMazeData(int X, int Y);
/// <summary>
/// 해당 위치의 타일 정보를 세팅하는 함수
/// </summary>
/// <param name="X">X좌표</param>
/// <param name="Y">Y좌표</param>
/// <param name="Data">세팅할 값</param>
void SetMazeData(int X, int Y, EMapEnv Data);

/// <summary>
/// 맵을 출력하는 함수
/// </summary>
void Print2DMap(Player& player);
/// <summary>
/// 주어진 좌표를 기준으로 상하좌우로 갈 수 있는지 판단하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
/// <param name="PlayerX">플레이어의 X좌표</param>
/// <param name="PlayerPosY">플레이어의 ㅛ좌표</param>
void CheckDirCanGO(bool* DirArr, struct Player& player);

/// <summary>
/// 이동할 수 있는 방향을 출력하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
void PrintChoiceScreen(bool* DirArr);

/// <summary>
/// 방향을 입력받는 함수 (wasd로 입력받아 방향값으로 반환)
/// </summary>
/// <returns>입력받은 방향, 비정상적인 값일 경우 EDirLength 반환</returns>
int GetDirInput();

/// <summary>
/// 랜덤 인카운더를 결정하는 함수
/// </summary>
/// <returns> 랜덤인카운터 플래그</returns>
int RandEncounter();

/// <summary>
/// 나와 몬스터의 체력을 출력하는 함수
/// </summary>
/// <param name="YoursHp">당신의 체력</param>
/// <param name="MonstersHP">몬스터의 체력</param>
void PrintHP(float YoursHp, float MonstersHP);


/// <summary>
/// DiceMax면체의 주사위를 굴려서 반환하는 함수
/// </summary>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int RollDice(int DiceMax);

/// <summary>
/// 공격 데미지를 계산해서 반환하는 함수
/// </summary>
/// <param name="BaseDamage">기본 데미지</param>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int GetAttackDamage(float BaseDamage, int DiceMax);

/// <summary>
/// 크리티컬의 적용여부 반환
/// </summary>
/// <param name="CriticalPercentage">크리티컬 페선테이지</param>
/// <returns>크리티컬 여부</returns>
bool IsCritical(int CriticalPercentage);
/// <summary>
/// 턴제 전투를 진행하는 함수
/// </summary>
/// /// <param name="InitailPlayerHp">플레이어 체력</param>
/// <returns>승리 여부</returns>
bool TurnBasedCombat(Player& player);
void Day0528_Prac1_Run();
void InitMap();
void Day0528_MazeAdventure();

void FindStart(int& OutX, int& OutY);
void PrintStatus(Player& player);
