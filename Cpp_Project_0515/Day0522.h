#pragma once
/*
	배열
		- 같은 종류의 데이터를 여러개 저장할 때 사용
		- 연속적으로 저장
		- type name[size];
			- int Number[3];
			- int Number2[3][4];
		- 배열의 이름은 배열의 시작 주송
			- [] 연산자는 이를 활용
			- Number[2] 는 *(Number + 2) 와 같은 연산
			- Number2[1][2]는 *(*(Number2+1) + 2)와 같은 연산
			- Number2[1][2]는 *(Number2[0] + 1 * 4 + 2))와 같은 연산
		- 생성하자마자 초기화 가능
			- int Arr[5] = { 0, 1, 2};
				- 3번째부터 0으로 채워짐
		- 탐색 O(N)
		- 삽입 O(N)
		- 삭제 O(N)
		- 랜덤 액세스 O(1)

	캐스팅
		- 타입을 다른 타입으로 변경하는 것
		- C 스타일
			- (변활할 타입) 데이터
			- (float) data;
			- 강제 변환 (일단 바꾸고 본다, 위험함)
		- C++ 스타일
			- static_cast<float>(data);
				- C스타일 cast와 매우 유사
				- 문법적으로 암시적 변환이 허용될 때만 캐스팅 해줌
				- 컴파일 타임 캐스팅
			- dynamic_cast<Child>(Parent);
				- 상속을 배워야 의미가 있다.
				- 다운 캐스팅을 할 때 사용
				- 캐스팅 가능하면 null이 아닌값 할 수 없으면 null을 반환
				- RTTI(RunTime Type Information)을 관리
					- 다운 캐스팅 시 자식 클래스를 모두 검사해서 느림.
				- 런타임 캐스팅
				- 남용말자 언리얼은 상속구조랑, 캐스팅을 각자 만들어 놓았다.
			- const_cast<float>(data);
				- const, volatile 속성을 제거하나 추가할 때 사용
				- 사용되지 않는것이 권장됨 (레거시 처리용)
			- reinterpret_cast<float>(data);
				- C스타일의 캐스팅의 위험한 부분을 그대로 가져온 것.
				- 원래 타입의 구조를 무시하고 새 타입으로 강제적으로 해석하게 하는 캐스팅
				- 포인터 타입간 변환이나 유니온 변환 같은 경우 사용
				- 절대 나를 사용하지 마시오

	참조
		- 변수의 별명
		- 데이터 타입 &
		- int& RefNum;
		- 참조는 재설정이 안됨
		- 선언시 원본을 지정해야함
		- Day0522_Reference() 참고
		- 출력용 파라미터는 앞에다가Out을 붙임
	
	포인터
		- 포인터와 배열은 근본적으로 같다.

	* constexpr : 컴파일타임에 계산되도록 보장하는 키워드 (const는 런타임까지 지연될 수 있음)
		- 변수, 함수등에 사용가능
*/

const int MazeRows = 10;
const int MazeCols = 20;

//U, D, L, R 순서로 검사
const int Dx[4] = { -1, 1, 0, 0 };
const int Dy[4] = { 0, 0, -1, 1 };



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

void Day0522_Run();
int GetRandRange(int min, int max);
int GetRandRange(int max);
void Day0522_Array_Exaple01();
void Day0522_Array_Exaple02();
void Day0522_Array_Exaple03();

void Day0522_Casting();
void Day0522_Reference();
void Day0522_ReferenceTest(int& Data1, int& Data2, int& Data3);

void Day0522_ArrayParameter();
void Test_ArrayParameter(int* Array, int Length);

void Day0522_Print_Array(int* Array, int Length);
double Day0522_Array_Exaple04(int* Array, int Length);
int Day0522_Array_Exaple05(int* Array, int Length);

/// <summary>
/// 배열의 원소들을 섞는 알고리즘
/// 편향문제를 해결함.
/// </summary>
/// /// <param name="Array">대상 배열</param>
/// /// <param name="Length">배열의 길이</param>
void FisherYatesShuffle(int* Array, int Length);
void Day0522_shuffle();

int RollingDice(const int DiceMax);
void Day0522_Practice01();

void Day0522_ReverseArray(int* Array, int Size);
void Day0522_Practice02();
void Day0522_Practice03();
//void Print2DMap(int (*Array)[MazeCols], int RowSize, int ColSize);
//void CheckDirCanGO(bool* DirArr, int PlayerX, int PlayerY);
//void PrintChoiceScreen(bool* DirArr);
//int GetDirInput();
//void Day0522_Practice04();