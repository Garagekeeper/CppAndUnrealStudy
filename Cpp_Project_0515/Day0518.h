#pragma once
/*
자료형
	int : 4byte

naming and coding convention
	변수명	: 보통 camel case, 하지만 언리얼의 경우 Pascal case, 길이가 길더라도 알아보기 편한게 좋다(자세히 적을 것)
	함수명	: Pascal case
	부울	: b 접두사, 헝가리 케이스
	문법적 금지
		- 예약어				: int, double등 컴파일러에서 미리 예약한 것들을 사용불가.
		- 숫자로 시작
		- 대부분의 특수 문자	: 언더바 (_)는 사용 가능하지만 비권장
		- __ or _				: 해당 접두사를 사용하는 것들은 컴파일러가 예약한 경우가 많아서 자제
		- 띄어쓰기
	비권장
		- 영어가 아닌 문자
		- 같은 스펠링에 대소문자가 다른 두 변수


	이 강의에서는 언리얼 표준(Pascal case 기반에 약간의 변형)을 따라가자
	중괄호 스타일도 잘 지키자.

	언리얼의 경우 코딩 규약 페이지가 따로 있음
	https://dev.epicgames.com/documentation/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine?lang=ko


Git
	https://learngitbranching.js.org/?locale=ko


연산자(Operator)
	- 산술 연산자		: +, -, *, /, %
	- 대입 연산자		: =
	- 복합 대입 연산자	: +=, -=, *=, /=. ... etc 대입 연산자와 다른 연산자를 복합적으로 사용하는 연산자.
	- 증감 연산자		: ++, --
	- 비트 연산자		:
	- 비교 연산자		:

Debug
	F9			: break point
	F5			: start debug
	shift + F5	: end Debug
	F11			:
	F12			:

*/

#include <iostream>
#include <vector>


using namespace std;

void Recursion(int x, int y, int n, vector<vector<int>>* grid);
void Print2ndDimensionGrid(int n, vector<vector<int>>* grid);

int main()
{
	//간단 실슴

	// 1. 두 수를 입력받아 스왑하기
	int Number1 = 0, Number2 = 0;
	printf("두 수를 입력하세요: ");
	cin >> Number1 >> Number2;
	printf("Before swap num1 : %d, num2 : %d\n", Number1, Number2);
	int temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
	//swap(Number1, Number2);
	printf("after swap num1 : %d, num2 : %d\n\n", Number1, Number2);

	// 2. 두 수를 입력받아 합을 출력하기
	printf("두 수를 입력하세요: ");
	cin >> Number1 >> Number2;
	int Sum = Number1 + Number2;
	printf("두 수의 합 : %d + %d  = %d\n\n", Number1, Number2, Sum);

	// 3. 사각형의 가로, 세로를 입력받아 넓이를 출력하기
	printf("사각형의 가로 길이:");
	cin >> Number1;
	printf("사각형의 세로 길이:");
	cin >> Number2;
	int Area = Number1 * Number2;
	printf("사각형의 넓이 : %d x %d  = %d\n\n", Number1, Number2, Area);


	// 4. 두 수를 입력받아 나머지를 출력하기 (% 연산자를 사용한 것과 안한 것 모두)
	printf("두 수를 입력하세요: ");
	cin >> Number1 >> Number2;
	int modular = Number1 % Number2;
	printf("%%를 사용한 나머지 연산 : %d %% %d = %d\n", Number1, Number2, modular);
	modular = Number1 - (Number1 / Number2) * Number2;
	printf("%%를 사용하지 않은 나머지 연산 : %d %% %d = %d", Number1, Number2, modular);


	// 고급 실습
	//	1.온도 변환기
	//		설명 : 섭씨 온도를 정수로 입력받아 화씨 온도로 변환하여 출력하는 프로그램.
	//		공식 : 화씨 = 섭씨 * 9 / 5 + 32
	{
		int celcious = 0;
		printf("1.온도 변환기\n");
		printf("섭씨 온도를 입력해 주세요: ");
		cin >> celcious;

		float Farhen = celcious * 9.0f / 5 + 32;
		printf("(실수 계산)섭씨 %d도는 화씨로 %f도 입니다.\n", celcious, Farhen);
		printf("(정수 계산)섭씨 %d도는 화씨로 %d도 입니다.\n\n", celcious, celcious * 9 / 5 + 32);
	}
	//	2.시간 계산기
	//		초를 입력 받아 시분초 출력하기
	{
		printf("2.시간 계산기\n");
		int second = 0;
		int minute = 0;
		int hour = 0;

		printf("초를 입력해 주세요: ");
		cin >> second;
		int Internal = second;
		hour = Internal / 3600;
		minute = (Internal - hour * 3600) / 60;
		Internal = second % 60;

		printf("%d초는 %d시간 %d분 %d초 입니다.\n\n", second, hour, minute, Internal);
	}

	//	3.동전 개수 계산하기
	//		금액을 입력받아 500원, 100원, 50원, 10원 동전이 각각 몇 개 필요한지 계산하는 프로그램.
	//		금액이 큰 동전을 최대한 많이 받아야 한다.

	{
		printf("3.동전 개수 계산하기\n");
		int Amount = 0;
		int FiveHundred = 0;
		int Hundred = 0;
		int Fifty = 0;
		int Ten = 0;
		int internal = 0;


		printf("총 금액을 입력해 주세요: ");
		cin >> Amount;
		internal = Amount;
		FiveHundred = internal / 500;
		internal -= FiveHundred * 500;

		Hundred = internal / 100;
		internal -= Hundred * 100;

		Fifty = internal / 50;
		internal -= Fifty * 50;

		Ten = internal / 10;
		internal -= Ten * 10;

		printf("%d원은 다음과 같이 변환 가능합니다.", Amount);
		printf("500원: %d개\n", FiveHundred);
		printf("100원: %d개\n", Hundred);
		printf("50원: %d개\n", Fifty);
		printf("10원: %d개\n\n", Ten);

	}

	//	4.자리수 분리하기(입력은 항상 세자리라고 가정)
	//		수를 입력받고 100의 자리, 10의 자리, 1의 자리를 각각 출력하기
	//		각 자리의 수를 합해서 출력하기
	{
		printf("4.자리수 분리하기(입력은 항상 세자리라고 가정)\n");
		printf("세자리 임의의 수를 입력하세요: ");

		int InputNumber = 0;
		int Internal;
		int Hundred = 0;
		int Ten = 0;
		int One = 0;
		int SumOfDigit;

		cin >> InputNumber;

		Internal = InputNumber;
		Hundred = Internal / 100;
		Internal -= Hundred * 100;
		Ten = Internal / 10;
		One = Internal % 10;
		SumOfDigit = Hundred + Ten + One;

		printf("%d의 경우\n", InputNumber);
		printf("100의 자리: %d개\n", Hundred);
		printf(" 10의 자리: %d개\n", Ten);
		printf("  1의 자리: %d개\n", One);
		printf("각 자릿수의 합은 %d 입니다\n\n", SumOfDigit);
	}
	//	5.파일 용량 환산기
	//		메가바이트(MB) 단위의 파일 크기를 입력받아, 킬로바이트(KB)와 바이트(Byte) 단위로 환산해 출력하는 프로그램
	//		공식 : 1MB = 1024KB, 1KB = 1024Byte
	{
		printf("5.파일 용량 환산기\n");
		printf("변환할 용량을 입력하세요: ");
		int Amount = 0;
		const int KILLODIGIT = 1024;
		cin >> Amount;
		int Killobyte = Amount * KILLODIGIT;
		int Byte = Killobyte * KILLODIGIT;
		printf("%dMB는 %dKB, %dByte 입니다..\n\n", Amount, Killobyte, Byte);

	}

	//	6.타일 개수 계산기(면적 구하기)
	//		직사각형 방의 가로, 세로 길이(cm)를 입력받고, 가로 30cm, 세로 30cm인 타일로 이 방을 채우려면 타일이 총 몇 개 필요한지 출력하기
	{
		printf("6.타일 개수 계산기(면적 구하기)\n");
		int Hor = 0, Ver = 0;
		printf("사각형의 가로 길이:");
		cin >> Hor;
		printf("사각형의 세로 길이:");
		cin >> Ver;

		int HorTileNum = 0;
		int VerTilenum = 0;

		HorTileNum = (Hor + 29) / 30;
		VerTilenum = (Ver + 29) / 30;
		int NeededTileNum = HorTileNum * VerTilenum;

		printf("가로 %d, 세로%d 크기의 방을 채우려면 총 %d개의 타일이 필요합니다.\n\n", Hor, Ver, NeededTileNum);
	}

	// 7. 백준 2447 
	//	3의 거듭제곱수로 
	// ***
	// * *
	// *** 패턴의 재귀 별찍기 (n=1)
	// 단, n은 3의 거듭제곱수
	{
		int n;
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		int x = n == 3 ? 0 : n / 3;
		int y = n == 3 ? 0 : n / 3;
		Recursion(0, 0, n, &grid);
		Print2ndDimensionGrid(n, &grid);
		int temp;
	}

	return 0;
}

void Recursion(int x, int y, int n, vector<vector<int>>* grid)
{
	int temp;
	if (n == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			(*grid)[x + i][y] = 1;
			(*grid)[x][y + i] = 1;
			(*grid)[x + 2][y + i] = 1;
			(*grid)[x + i][y + 2] = 1;
		}
		(*grid)[x + 1][y + 1] = 0;

		/*9 9 27
		3 3 9  3 12 9 3 21 9

		0 0 3  0 3 3  0 6 3
		3 0 3  3 3 3  3 6 3
		6 0 3  6 3 3  6 3 3*/

	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) continue;
				int nx = x + i * n / 3;
				int ny = y + j * n / 3;
				int nextN = n / 3;
				Recursion(nx, ny, nextN, grid);
			}
		}
	}
}

void Print2ndDimensionGrid(int n, vector<vector<int>>* grid)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", (*grid)[i][j] == 1 ? '*' : ' ');
		}
		printf("\n");
	}
}