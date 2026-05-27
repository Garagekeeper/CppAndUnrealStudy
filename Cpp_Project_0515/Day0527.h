#pragma once
/*
	문자열
		- 연속된 char (char의 배열)
		- (const) char* / char [] <- CStyle;
		- std::string <- CppStyle;
		- 모든 문자열의 끝에는 널문자 '\0'가 있다.
			- 이를 통해서 길이를 알 수 있다.
		- char*는 원래 아스키코드만
			- 유니코드 디버깅해보면 쓰레기값
			- 알아서 인코딩하고 처리해줌
		- 진짜 유니코드는 wchar_t
		- strlen(const char* str)
		- strcpy(Dest string, const Source string)
			- 합리적으로 보이나, 사이즈가 없어서 unSafe
			- strcpy_s도 있는데 언리얼 C++하는데 굳이
		- strcat(Dest string, const Source string)
			- Dest에 Source를 덧붙임.
		- strcmp
			- 비교
			- 앞에게 사전순으로 빠르면	:	(-1)
			- 같으면					:	( 0)
			- 뒤에게 사전순으로 빠르면	:	( 1)
		- atoi(str) <- alphabet to int
		- atof(str) <- alphabet to float



	
	
	
	
	
	* 메모리 공간을 잡을 때 2의 승수로 잡자 (편하다, 단편화 줄인다)
	* 상수는 헤더에 쓰는게 기본이다.
	* extern : 실제 선언은 아니고 다른곳에 이 형태의 변수/함수등이 존재한다고 알려주는 것.
	const int Row = 10;		// 사실 이건 옛날 방식(런타임에 결정될 수 있음)
	constexpr int Row = 10	// 이게 요즘 방식(무조건 컴파일 타입)
	const int Col = 20;

	const char* const ShapePlayer = "P ";	//주소와 값을 수정 못하게

	extern int Maze[Row][Col];
*/

void Day0527_Run();

int MyStrLen(const char* _Str);
char* MyStrCpy(char* _Destination, const char* _Source);
char* MyStrCat(char* _Destination, const char* _Source);
int MyStrCmp(const char* _Str1, const char* _Str2);
int MyAtoI(const char* _String);
float MyAtoF(const char* _String);
bool CompareFloat(float A, float B);

void Day0527_Prac01();


/*

	// 처음 공백제거
	while (*_String == ' ' || *_String == '\t' || *_String == '\n' || *_String == '\r')
	{
		_String++;
	}

	// 부호처리
	int Sign = 1;
	if (*_String == '-')
	{
		Sign = -1;
		_String++;
	}
	else if (*_String == '+')
	{
		Sign = 1;
		_String++;
	}

	//문자를 숫자로
	while (*_String >= '0' && *_String <= '9')
	{
		Res = Res * 10 + (*_String - '0');
		_String++;
	}

	if (*_String == '.')
	{
		_String++;
	}
	while (*_String >= '0' && *_String <= '9')
	{
		Frac += Mul * (*_String - '0');
		Mul *= 0.1f;
		_String++;
	}

	if (*_String != '\0')
		return 0;
*/