#pragma once
/*
	
자료형
	float (부동 소수점)
		- 32bit
		- 구조적으로 오차가 있는 데이터 타입.
		- 6.75 -> b 0110.11 -> 1.1011 x 2^2 (정규화) 
		- 부호비트,		지수부,		가수부
		- 0				2 + 127		1011	
		- 0				1000 0001
		- [0][1000 0001][1011 0000 0000 0000 0000 000]
		- 비교 연산을 주의해서 하도록
		- 0.1은 double, 0.1f는 float

	double 
		- 64bit
		- float realNum = 0.1;			<- 암시적 변환 발생.
		- float realNum = (float)0.1;	<- 명시적 변환.

	bool
		- 8bit (cpu나 메모리의 최소 단위인듯)
		- 참, 거짓 (true, false)만 저장
		- 0이 아닌 값을 가지면 true;

	char
		- 1byte짜리 정수형 타입
		- 문자를 저장하는 자료형
		
	문자열
		- char*
		- std::string

	long long
		- 64bit
		- 
	
	wchar_t
		- 유니코드를 지원하는 문자 자료형
		- L'가' 이런 식으로 사용
		- char와 암시적 변환이 되지 않는다.


	상수
		- const 키워드 사용
		- 프로그램의 안전성과 가독성 증가
		- 컴파일러 차원에서 오류 걸러줌
		

연산자
	비교 연산자
		- 

	논리 연산자
		- bool을 다루는 연산자
		- && || ! 



제어구문
	if
	if else
	else if
	삼항 연산자 ( (condition) ? trueValue : falseValue ;)
		- 한줄로 만들 수 있다는게 장점
		- 람다에서도 유용

* 문자열 비교는 되도록이면 하지 말자.
* 곱하기와 나누기중에 곱하기가 빠르다 (정확히 말하면 나누기가 느리다)
* 메인 루프에서는 if문을 최대한 안쓰는 구조가 좋다.
* 조건문에서는 항상 범위가 큰 것을 먼저 체크하는 것이 좋다.
* 테스트할 때 가장 먼저해야할 것 -> 경계값, 중간값.

*/

////간단 실습
//
//{
//	// 1. 원의 반지름을 입력 받아서 넓이 구하기
//	float Radius = .0f;
//	const float PHI = 3.141592f;
//	float Area = .0f;
//	printf("원의 반지름을 입력하세요: ");
//	cin >> Radius;
//
//	Area = PHI * Radius * Radius;
//	printf("반지름 %f인 원의 넓이는 %.2f 입니다.\n\n", Radius, Area);
//
//}
//{
//	// 2. 3개의 값을 입력 받아서 평균 구하기
//	float Num1 = .0f;
//	float Num2 = .0f;
//	float Num3 = .0f;
//	const int TotalNumber = 3;
//	float SumOfNum = .0f;
//	float Average = .0f;
//
//	printf("3개의 값을 입력하세요: ");
//	cin >> Num1 >> Num2 >> Num3;
//	SumOfNum = Num1 + Num2 + Num3;
//	Average = (SumOfNum * 1.0f) / TotalNumber;
//	printf("평균은 %.2f 입니다\n\n", Average);
//
//}
//
//// 3. 정가와 할인율을 입력받고 할인된 가격 구하기
//{
//	float NormalPrice = .0f;
//	float DiscountPercentage = .0f;
//	float DiscountPrice = .0f;
//	printf("정가와 할인율을 입력하세요: ");
//	cin >> NormalPrice >> DiscountPercentage;
//	DiscountPrice = (100 - DiscountPercentage) * NormalPrice * 0.01f;
//	printf("할인된 가격은 %.2f 입니다.\n\n", DiscountPrice);
//}
//{
//	//1. 숫자를 입력받아 양수인지 음수인지 0인지 판단하는 코드
//	int Number = 0;
//	printf("판별할 숫자를 입력해 주세요: ");
//	cin >> Number;
//	if (Number > 0)			printf("%d는 양수입니다.\n", Number);
//	else if (Number == 0)	printf("%d는 0입니다.\n", Number);
//	else if (Number < 0)	printf("%d는 음수입니다.\n", Number);
//
//	}
//
//{
//	//2. 숫자를 입력받아 홀수인지 짝수인지 판단하는 코드
//	int Number = 0;
//	printf("판별할 숫자를 입력해 주세요: ");
//	cin >> Number;
//	if (Number % 2 == 0)
//	{
//		printf("%d는 짝수입니다.\n", Number);
//	}
//	else
//	{
//		printf("%d는 홀수입니다.\n", Number);
//	}
//}
//
//{
//	//3. 두 수를 입력 받아 더 큰 수를 출력하는 코드
//	int Number1 = 0;
//	int Number2 = 0;
//	printf("판별할 숫자를 입력해 주세요: ");
//	cin >> Number1 >> Number2;
//	if (Number1 > Number2)			printf("%d와 %d 중에서는 %d가 큽니다.\n", Number1, Number2, Number1);
//	else if (Number1 == Number2)	printf("두 수는 같습니다..\n");
//	else if (Number1 < Number2)		printf("%d와 %d 중에서는 %d가 큽니다.\n", Number1, Number2, Number2);
//}
//
//{
//	//1. 나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출룍
//	int Age = 0;
//	int Height = 0;
//	printf("나이와 키를 입력하세요: ");
//	cin >> Age >> Height;
//	if (Age >= 6 && Height >= 120)
//		printf("탑승 가능!\n");
//	else
//		printf("탑승 불가능\n");
//}
//
//{
//	//2. 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기 
//	int Score = 0;
//	printf("점수를 입력하세요: ");
//	cin >> Score;
//	if (Score >= 90)
//		printf("A\n");
//	else if (Score >= 80)
//		printf("B\n");
//	else if (Score >= 70)
//		printf("C\n");
//	else if (Score >= 60)
//		printf("D\n");
//	else
//		printf("F\n");
//}
//
//{
//	//3, 세 과목의 점수를 입력받아, 세 과목 모두 60점 이상이면 "합격", 아니면 불합격
//	// 한 과목이라도 40점 미만이면 불합격
//	int SubjectA = 0;
//	int SubjectB = 0;
//	int SubjectC = 0;
//
//	printf("세 과목의 점수를 입력하세요: ");
//	cin >> SubjectA >> SubjectB >> SubjectC;
//
//	if ((SubjectA + SubjectB + SubjectC) / 3 >= 60)
//	{
//		if (SubjectA < 40 || SubjectB < 40 || SubjectC < 40)
//			printf("불합격");
//
//		printf("합격");
//	}
//	else
//	{
//		printf("불합격");
//	}
//
//	printf("\n");
//}

//{
//	//1. 세 수 중 최댓값과 최솟값 찾기
//	//	3개의 정수를 입력받아, 그중 가장 큰 수와 가장 작은 수를 출력
//	int InputNum1 = 0;
//	int InputNum2 = 0;
//	int InputNum3 = 0;
//	int MaxValue = 0;
//	int MinValue = 0;
//
//	printf("1. 세 수 중 최댓값과 최솟값 찾기\n");
//	printf("세 수를 입력하세요: ");
//	cin >> InputNum1 >> InputNum2 >> InputNum3;
//	if (InputNum2 <= InputNum3)
//	{
//		MaxValue = InputNum3;
//		MinValue = InputNum2;
//	}
//	else
//	{
//		MaxValue = InputNum2;
//		MinValue = InputNum3;
//	}
//
//	if (MaxValue < InputNum1)
//		MaxValue = InputNum1;
//	if (MinValue > InputNum1)
//		MinValue = InputNum1;
//
//	printf("최댓값: %d, 최솟갑: %d\n\n", MaxValue, MinValue);
//	}
//
//{
//	//	2.세 개의 선분 길이를 입력받아, 이 선분들로 삼각형을 만들 수 있는지 판별하기
//	//	조건 : 삼각형이 되려면 '가장 긴 변의 길이 < 나머지 두 변의 길이의 합'이어야 함.
//	int InputNum1 = 0;
//	int InputNum2 = 0;
//	int InputNum3 = 0;
//	int SumofNumber = 0;
//	int MaxValue = 0;
//	printf("2.세 개의 선분 길이를 입력받아, 이 선분들로 삼각형을 만들 수 있는지 판별하기\n");
//	printf("세 수를 입력하세요: ");
//	cin >> InputNum1 >> InputNum2 >> InputNum3;
//
//	SumofNumber = InputNum1 + InputNum2 + InputNum3;
//	MaxValue = InputNum1;
//
//	if (MaxValue < InputNum2)
//		MaxValue = InputNum2;
//
//	if (MaxValue < InputNum3)
//		MaxValue = InputNum3;
//
//	int SumOfRestTwoSides = SumofNumber - MaxValue;
//	if (SumOfRestTwoSides > MaxValue)
//	{
//		printf("삼각형 생성 가능\n\n");
//	}
//	else
//	{
//		printf("삼각형 생성 불가\n\n");
//	}
//
//
//	if (InputNum1 > InputNum2 && InputNum1 > InputNum3 && InputNum1 < InputNum2 + InputNum3
//		|| InputNum2 > InputNum1 && InputNum2 > InputNum3 && InputNum2 < InputNum1 + InputNum3
//		|| InputNum3 > InputNum1 && InputNum3 > InputNum2 && InputNum3 < InputNum1 + InputNum2)
//	{
//		printf("삼각형 생성 가능\n\n");
//	}
//	else
//	{
//		printf("삼각형 생성 불가\n\n");
//	}
//}
//
//{
//	// 2.미니 계산기
//	//	두 개의 정수와 하나의 연산자(+, -, *, / )를 입력받아 결과를 출력
//	//	단, 나눗셈에서 0으로 나누려고 하면 "0으로 나눌 수 없습니다"라는 에러 메시지를 출력
//	printf("3.미니 계산기\n");
//	while (true)
//	{
//		int LeftOperand = 0;
//		int RightOperand = 0;
//		char Operator = ' ';
//		float Results = .0f;
//		bool bCanCalc = true;
//
//		printf("계산식을 입력해 주세요!: ");
//		cin >> LeftOperand >> Operator >> RightOperand;
//
//		if (Operator == '+')
//		{
//			Results = LeftOperand + RightOperand;
//		}
//		else if (Operator == '-')
//		{
//			Results = LeftOperand - RightOperand;
//		}
//		else if (Operator == '*')
//		{
//			Results = LeftOperand * RightOperand;
//		}
//		else if (Operator == '/')
//		{
//			if (RightOperand == 0)
//			{
//				printf("0으로 나눌 수 없습니다\n\n");
//				bCanCalc = false;
//			}
//			else
//				Results = (1.0) * LeftOperand / RightOperand;
//		}
//		else
//		{
//			printf("알 수 없는 연산입니다.\n\n");
//			bCanCalc = false;
//		}
//		if (bCanCalc)
//			printf("해당 식의 결과는 %.1f 입니다.\n\n", Results);
//		else
//			break;
//	}
//
//}
//
//{
//	// 3.윤년 판별기
//	//	연도(예 : 2024)를 입력받아 그 해가 윤년인지 평년인지 출력
//	//	윤년의 조건 :
//	//  연도가 4로 나누어 떨어지면 윤년이다.
//	//	하지만 100으로 나누어 떨어지면 평년이다.
//	//	그럼에도 400으로 나누어 떨어지면 윤년이다.
//	int Years = 0;
//	printf("4.윤년 판별기\n");
//	printf("판별할 연도를 입력하세요\n");
//	cin >> Years;
//
//	if (Years % 4 == 0 && Years % 100 == 0 && Years % 400 == 0 || Years % 4 == 0 && Years % 100 != 0)
//	{
//		printf("윤년 입니다.\n");
//	}
//	else
//	{
//		printf("평년 입니다.");
//	}
//
//	if (Years % 4 == 0)
//	{
//		if (Years % 100 == 0)
//		{
//			if (Years % 400 == 0)
//			{
//				printf("윤년 입니다.\n\n");
//			}
//			printf("평년 입니다.\n\n");
//		}
//		printf("윤년 입니다.\n\n");
//	}
//	else
//		printf("평년 입니다.\n\n");
//
//}
