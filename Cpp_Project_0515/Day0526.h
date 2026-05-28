#pragma once
/*
	포인터
		- 메모리 "주소"를 저장하는 변수
		- datatype* name;
			- int* pInt;
			- char* pString;
			- int Data = 10;
			- pInt = &Data;
		- nullptr을 사용
			- 값이 비어있는지, 0번째 주소인지 확실한 구분을 위해서 c++11에 도입
		- 연산자
			- & : 주소 연산자
			- * : 간접 참조 연산자. (포인터변수가 가진 주소값의 실제 값을 가져옴)
			- + num: 값 타입 사이즈 만큼 num번 더한다
			- - num: 값 타입 사이즈 만큼 num번 뺀다.

		- 상수와 포인터
			- const int* ConstPointer = &Data;
			- const (int) * ConstPointer = &Data;
			- ConstPointer = &Data2 <- Ok
			- * ConstPointer = 20; <- err
			- ConstPointer는 Data의 주소를 가리키는데 그 값을 변경하지 않겠다
			- const는 자기 왼쪽에 있는 것을 변경하지 않는다.
			- 그런데 왼쪽에 아무것도 없으면 오른쪽을 수정하지 않는다.

			- const int* const ConstPointer = &Data;
			- int (*) const ConstPointer = &Data;
			- ConstPointer = &Data2 <- err
			- * ConstPointer = 20; <- ok
			- 주소를 변경하지 않겠다.


	메모리 영역
		- Code
			- 실행코드 저장
		- Data
			- 처음부터 끝까지 유지되는 변수가 저장
			- 전역 변수, static 변수
		- Heap
			- 실행중에 필요에 따라 직접 메모리를 할당하고 사용하는 공간
			- 반드시 할당-해제를 짝을 맞춰야한다.
			- 크기가 제한이 없다고 보면 됨
				- RAM 크기와 비슷
			- 느림
		- Stack
			- 함수가 호출 될때 필요한 변수, 파리미터 등이 저장
			- 함수가 끝나면 자동으로 정리
			- 값의 상한이 있음(프로젝트마다 다름, 윈도우 기본값 = 1MB)
			- 스택 오버플로우
			- 빠름

	동적 할당
		- 런타임에 메모리를 확보하는 행위
			- heap을 사용
		- 기본적으로 느리다. (OS에 부탁하는 부분)
			- 한번에 최대한 크게 받아오자
		- 메모리 단편화
		- C style (생략)
			- 타입 안정성 없고, 생성자 호출 불가, 초기화 X
		- CPP style
			- 타입 안정성 있고, 초기화 있음, 생성자 호출 가능
			- new
				- int* Alloc = new int(5); // int 크기로 동적할당을 하는데, 초기값으로 5를 넣은뒤 주소를 Alloc에 저장하라
				- int* Alloc2 = new int[10];
			- delete
				- delete Alloc; (제일 앞칸만 지우기)
				- delete[]  Alloc2; (뒷칸도 모두 지우기)
				- Alloc = nullptr
					- Dangling Pointer 방지
				- 여기까지가 한 세트
		- 2차원 배열을 동적 할당으로 생성하는 건 비추
			int** Arr = new int*[5]; (5행10 열
			for (int i=0; i<5; i++)
				Arr[i] = new int[10]

			for (int i=0; i<5; i++)
				delete[] Arr[i];
			delete[] Arr;


	반복문
		- 범위기반 for
			- 배열이나 컨테이너를 순회할 때 사용
			- for (auto e : Array)
				printf("%d ", e);

	enum은 헤더에 넣자

	//과제 5
	// 문자열 처리
	const char* ShapePlayer = "P ";
	const char* ShapeWall	= "# ";
	const char* ShapePath	= ". ";
	const char* ShapeStart	= "S ";
	const char* ShapeEnd	= "E ";

	// 인라인 처리
	// Maze가 헤더이 있는 경우
	intline bool isGoal(int x, int y) {return Maze[x][y] == MazeEnd}

	4방향 bool 변수를 비트 플래그로 처리하자
*/

void Day0526_Run1();
void Day0526_PointerParameter(int* Data, int Size);
void Day0526_Example01(int* a, int* b);
int Day0526_Example02(int* Arr, int Size);
void Day0526_Example03(int* Arr, int Size);


#pragma region Maze
enum Day0526EMapEnv
{
	ROAD,
	WALL,
	START,
	END,
	PLAYER,
};

enum Day0526EDir
{
	UP,
	Down,
	Left,
	Right,
	EDirLength
};

enum Day0526EEncounter
{
	EncounterNone	= 0,
	EncounterCombat = 1,
	EncounterHeal	= 2,
	EncounterTrap	= 3,
};

/// <summary>
/// Min 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Min">랜덤값의 최소</param>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>Min 부터 Max사이의 랜덤 값</returns>
int Day0526RandomRange(int Min, int Max);

/// <summary>
/// 0 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>0 부터 Max사이의 랜덤 값</returns>
int Day0526RandomRange(int Max);


/// <summary>
/// 맵을 출력하는 함수
/// </summary>
void Day0526Print2DMap();
/// <summary>
/// 주어진 좌표를 기준으로 상하좌우로 갈 수 있는지 판단하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
/// <param name="PlayerX">플레이어의 X좌표</param>
/// <param name="PlayerY">플레이어의 ㅛ좌표</param>
void Day0526CheckDirCanGO(bool* DirArr, int PlayerX, int PlayerY);

/// <summary>
/// 이동할 수 있는 방향을 출력하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
void Day0526PrintChoiceScreen(bool* DirArr);

/// <summary>
/// 방향을 입력받는 함수 (wasd로 입력받아 방향값으로 반환)
/// </summary>
/// <returns>입력받은 방향, 비정상적인 값일 경우 EDirLength 반환</returns>
int Day0526GetDirInput();

/// <summary>
/// 랜덤 인카운더를 결정하는 함수
/// </summary>
/// <returns> 랜덤인카운터 플래그</returns>
int Day0526RandEncounter();

/// <summary>
/// 나와 몬스터의 체력을 출력하는 함수
/// </summary>
/// <param name="YoursHp">당신의 체력</param>
/// <param name="MonstersHP">몬스터의 체력</param>
void Day0526PrintHP(int YoursHp, int MonstersHP);

/// <summary>
/// 나와 체력을 출력하는 함수
/// </summary>
/// <param name="YoursHp">당신의 체력</param>
void Day0526PrintHP(int YoursHp);

/// <summary>
/// DiceMax면체의 주사위를 굴려서 반환하는 함수
/// </summary>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int Day0526RollDice(int DiceMax);

/// <summary>
/// 공격 데미지를 계산해서 반환하는 함수
/// </summary>
/// <param name="BaseDamage">기본 데미지</param>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int Day0526GetAttackDamage(int BaseDamage, int DiceMax);

/// <summary>
/// 크리티컬의 적용여부 반환
/// </summary>
/// <param name="CriticalPercentage">크리티컬 페선테이지</param>
/// <returns>크리티컬 여부</returns>
bool Day0526IsCritical(int CriticalPercentage);
/// <summary>
/// 턴제 전투를 진행하는 함수
/// </summary>
/// /// <param name="InitailPlayerHp">플레이어 체력</param>
/// <returns>승리 여부</returns>
bool Day0526TurnBasedCombat(int PlayerHp);
void Homework05_Run();

/// <summary>
/// 해당 위치의 타일 정보를 리턴하는 함수
/// </summary>
/// <param name="X">X좌표</param>
/// <param name="Y">Y좌표</param>
/// <returns>해당 위치의 데이터</returns>
Day0526EMapEnv Day0526GetMazeData(int X, int Y);
/// <summary>
/// 해당 위치의 타일 정보를 세팅하는 함수
/// </summary>
/// <param name="X">X좌표</param>
/// <param name="Y">Y좌표</param>
/// <param name="Data">세팅할 값</param>
void	Day0526SetMazeData(int X, int Y, Day0526EMapEnv Data);
#pragma endregion
