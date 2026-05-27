#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Day0527.h"

using namespace std;

void Day0527_Run()
{
	const char* TestString1 = "Hello String!\n";
	const char* TestString2 = "안녕 문자열!\n";		// 인코딩이 자동으로 처리되서 한글이 보이는거다.

	// wchar_t : 유니코드용 char.

	const char* TestString = "Hello";
	int Size = MyStrLen(TestString);
	printf("\nMyStrLen\n");
	printf("[%s]의 길이는 [%d]입니다.\n", TestString, Size);

	char Buffer[32] = { 0, };
	printf("\nMyStrCpy\n");
	printf("Dest:%s\n", Buffer);
	printf("Source:%s\n", TestString);
	MyStrCpy(Buffer, TestString);
	printf("cpy 후 Dest의 내용은 [%s]입니다.\n", Buffer);	// Buffer : Hello

	printf("\nMyStrCat\n");
	printf("Dest:%s\n", Buffer);
	printf("Source:%s\n", TestString);
	MyStrCat(Buffer, TestString);
	printf("cat 후 Dest의 내용은 [%s]입니다.\n", Buffer);	// Buffer : HelloHello

	printf("\nMyStrCmp\n");
	printf("%s, %s는 %s니다.\n", "abc", "abc", MyStrCmp("abc", "abc") == 0 ? "같습" : "다릅");
	printf("%s, %s는 %s니다.\n", "ab", "abc", MyStrCmp("ab", "abc") == 0 ? "같습" : "다릅");
	printf("%s, %s는 %s니다.\n", "abb", "abc", MyStrCmp("abb", "abc") == 0 ? "같습" : "다릅");
	printf("%s, %s는 %s니다.\n", "abc", "abb", MyStrCmp("abc", "abb") == 0 ? "같습" : "다릅");
	printf("%s, %s는 %s니다.\n", "abc", "ab", MyStrCmp("abc", "ab") == 0 ? "같습" : "다릅");

	printf("\nMyAtoI\n");
	const char* TestStringNubmer1 = "123";
	int Number = MyAtoI(TestStringNubmer1);
	printf("문자열 [%s]는 인티저 [%d]입니다.\n", TestStringNubmer1, Number);

	printf("\nMyAtoF\n");
	const char* TestStringNubmer2 = "12.3";
	float FloatNumber = (float)MyAtoF(TestStringNubmer2);
	printf("문자열 [%s]는 실수 [%f]입니다.\n", TestStringNubmer2, FloatNumber);
	

	printf("\nMyAtoITestCAsePass\n");

	const char* TestCasePass[] = { "123", "-342" ,"0", "33", "+192"," -11" ,};
	const char* TestCaseFail[] = { "45ds" , "as54"," +-233","" };

	int PassCnt = 0;
	int FailCnt = 0;

	for (const char* Case : TestCasePass)
	{
		if (MyAtoI(Case) == atoi(Case))
			PassCnt++;
		else
			FailCnt++;

		printf("[%s] = [%d] : %s\n", Case, MyAtoI(Case), MyAtoI(Case) == atoi(Case) ? "Pass" : "Fail");
	}
	printf("\nPassCnt = %d, Failcnt = %d\n\n", PassCnt, FailCnt);


	printf("\nMyAtoITestCAseFail\n");

	PassCnt = 0;
	FailCnt = 0;
	for (const char* Case : TestCaseFail)
	{
		if (MyAtoI(Case) == 0)
			PassCnt++;
		else
			FailCnt++;

		printf("[%s] = [%d] : %s\n", Case, MyAtoI(Case), MyAtoI(Case) == 0 ? "Pass" : "Fail");
	}
	printf("\nPassCnt = %d, Failcnt = %d\n\n", PassCnt, FailCnt);


	printf("\nMyAtoFTestCAsePass\n");

	const char* TestCasePass2[] = { "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54"};
	const float TestCaseResult2[] = { 123.45f, -38.556f, 0.0f, 3.14f, 0.5f, 0.7f, 12.0f, -0.54f };
	const char* TestCaseFail2[] = { "12.05.78", "45.dd", "aqw45.8", "12. 35", "" };

	int temp = sizeof(char*);
	temp = sizeof(std::string);
	PassCnt = 0;
	FailCnt = 0;

	for (int i = 0; i < sizeof(TestCasePass2) / sizeof(TestCasePass2[0]); i++)
	{
		if (CompareFloat(MyAtoF(TestCasePass2[i]), TestCaseResult2[i]))
			PassCnt++;
		else
			FailCnt++;

		printf("[%s] = [%f] : %s\n", TestCasePass2[i], MyAtoF(TestCasePass2[i]), CompareFloat(MyAtoF(TestCasePass2[i]), TestCaseResult2[i]) ? "Pass" : "Fail");
	}
	printf("\nPassCnt = %d, Failcnt = %d\n\n", PassCnt, FailCnt);


	printf("\nMyAtoFTestCAseFail\n");

	PassCnt = 0;
	FailCnt = 0;

	for (int i = 0; i < sizeof(TestCaseFail2) / sizeof(TestCasePass2[0]); i++)
	{
		if (CompareFloat(MyAtoF(TestCaseFail2[i]), 0))
			PassCnt++;
		else
			FailCnt++;

		printf("[%s] = [%f] : %s\n", TestCaseFail2[i], MyAtoF(TestCaseFail2[i]), CompareFloat(MyAtoF(TestCaseFail2[i]), 0) ? "Pass" : "Fail");
	}
	printf("\nPassCnt = %d, Failcnt = %d\n\n", PassCnt, FailCnt);
}

int MyStrLen(const char* _Str)
{
	int Length = 0;
	while (*(_Str + Length) != '\0')
	{
		Length++;
	}
	return Length;
}

char* MyStrCpy(char* _Destination, const char* _Source)
{
	/*int index = 0;
	while (*(_Source + index) != '\0')
	{
		*(_Destination + index) = *(_Source + index);
		index++;
	}
	//
	*(_Destination + index) = '\0';
	//
	return _Destination;*/

	// 표준 구현
	

	char* Res = _Destination;
	while ((*_Destination++ = *_Source++) != '\0');

	return Res;

}

char* MyStrCat(char* _Destination, const char* _Source)
{
	//MyStrCat
	//int _DestEnd = MyStrLen(_Destination);
	//int index = 0;
	//
	//while (*(_Source + index) != '\0')
	//{
	//	*(_Destination + index + _DestEnd) = *(_Source + index);
	//	index++;
	//}
	//
	//*(_Destination + index + _DestEnd) = '\0';
	//
	//return _Destination;

	// 표준 구현
	char* Res = _Destination;

	while (*_Destination)
		_Destination++;

	while ((*_Destination++ = *_Source++) != '\0')
	{

	}

	return Res;
}

int MyStrCmp(const char* _Str1, const char* _Str2)
{
	/*int Index = 0;
	int Res = 0;
	while (*(_Str1 + Index) != '\0' && *(_Str2 + Index) != '\0')
	{
		if (*(_Str1 + Index) < *(_Str2 + Index))
			return -1;

		if (*(_Str1 + Index) > *(_Str2 + Index))
			return 1;
			
		Index++;
	}

	if (*(_Str1 + Index) == '\0' && *(_Str2 + Index) == '\0') return 0;
	else if (*(_Str1 + Index) == '\0') return -1;
	else if (*(_Str2 + Index) == '\0') return 1;

	return 0;*/

	// 표준 구현

	while (*_Str1 && (*_Str1 == *_Str2))
	{
		_Str1++;
		_Str2++;
	}

	return *(const unsigned char*)_Str1 - *(const unsigned char*)_Str2;
}

int MyAtoI(const char* _String)
{
	//int Index = 0;
	//int Res = 0;
	//int Mul = 10;
	//int Sign = 1;
	//bool bMetSign = false;
	//while (*(_String + Index) != '\0')
	//{
	//	char Digit = *(_String + Index);
	//	if ('0' <= Digit && Digit <= '9')
	//	{
	//		Res *= Mul;
	//		Res += ((Digit - '0') * Sign);
	//	}
	//	else
	//	{
	//		if (!(Digit == ' ') && !(Digit == '-') && !(Digit == '+')) return 0;
	// 
	//		if ((Digit == '+') && bMetSign) return 0;
	//		if ((Digit == '+') && (Res == 0)) { Sign = 1; bMetSign = true; }
	//		
	//		if ((Digit == '-') && bMetSign) return 0;
	//		if ((Digit == '-') && (Res == 0)) { Sign = -1; bMetSign = true; }
	//		
	//		if ((Digit == '+') && (Res != 0)) break;
	//		if ((Digit == '-') && (Res != 0)) break;
	//		if ((Digit == ' ') && (Res != 0)) break;
	//		
	//		
	//	}
	//	Index++;
	//}
	////실패 : 0 반환 -> 45ds, as54 "12 35" -> 0
	////기타 : 
	//return Res;

	int Sign = 1;
	int Res = 0;

	while (*_String == ' ' || *_String == '\t' || *_String == '\n' || *_String == '\r')
		_String++;

	if (*_String == '-')
	{
		Sign = -1;
		_String++;
	}

	if (*_String == '+')
	{
		_String++;
	}

	while (*_String <= '9' && '0' <= *_String)
	{
		Res *= 10;
		Res += *_String - '0';
		_String++;
	}

	if (*_String != '\0')
		Res = 0;

	return Res * Sign;
}

float MyAtoF(const char* _String)
{

	////실패 : 0 반환 -> 12.05.78, 45.ㅇㅇ"12. 35" -> 0
	////기타 : 

	//int Index = 0;
	//int Res = 0;
	//int Mul = 10;
	//int Sign = 1;
	//double ResFrac = 0.0;
	//double MulFrac = 0.1;
	//bool bMetPoint = false;
	//bool bMetSign = false;

	//while (*(_String + Index) != '\0')
	//{
	//	char Digit = *(_String + Index);
	//	if ('0' <= Digit && Digit <= '9')
	//	{
	//		if (bMetPoint)
	//		{
	//			ResFrac += ((Digit - '0') * Sign) * MulFrac;
	//			MulFrac /= 10;
	//		}
	//		else
	//		{
	//			Res *= Mul;
	//			Res += ((Digit - '0') * Sign);
	//		}
	//	}
	//	else
	//	{

	//		if (!(Digit == ' ') && !(Digit == '-') && !(Digit == '+') && !(Digit == '.')) return 0;

	//		if ((Digit == '.') && bMetPoint) return 0;
	//		if ((Digit == '.') && !bMetPoint) bMetPoint = true;

	//		if ((Digit == '+') && bMetSign) return 0;
	//		if ((Digit == '+') && (Res == 0)) { Sign = 1; bMetSign = true; }

	//		if ((Digit == '-') && bMetSign) return 0;
	//		if ((Digit == '-') && (Res == 0)) { Sign = -1; bMetSign = true; }

	//		if ((Digit == '+') && (Res != 0)) break;
	//		if ((Digit == '-') && (Res != 0)) break;
	//		if ((Digit == ' ') && (Res != 0)) break;
	//	}
	//	Index++;
	//}

	//return Res + ResFrac;

	float Res = .0f;
	float Frac = 0.0f;
	float Mul = 0.1f;
	int Sign = 1;

	while (*_String == ' ' || *_String == '\t' || *_String == '\n' || *_String == '\r')
		_String++;

	if (*_String == '-')
	{
		Sign = -1;
		_String++;
	}

	if (*_String == '+')
	{
		_String++;
	}

	while (*_String <= '9' && '0' <= *_String)
	{
		Res *= 10;
		Res += *_String - '0';
		_String++;
	}

	if (*_String == '.')
	{
		_String++;
	}

	while (*_String <= '9' && '0' <= *_String)
	{
		Frac = Frac + (*_String - '0') * Mul;
		Mul *= 0.1f;
		_String++;
	}

	if (*_String != '\0')
	{
		Res = 0;
		Frac = 0;
	}




	return (Res + Frac) * Sign;
}

bool CompareFloat(float A, float B)
{
	if (A - B > -0.00001f && A - B < 0.00001f)
		return true;
	return false;
}
