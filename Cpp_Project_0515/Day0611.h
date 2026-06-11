#pragma once
#include <vector>

/*
	void* :  
		- 일단 포인터긴 한데 무슨 데이터 타입을 가리키는지는 모름
		- printf의 %p는 이 타입을 받음
		- 모든 포인터는 void*로 캐스팅이 가능하지만, 이 타입으로 넘겨 받으면 원래 데이터에 접근을 못함
		- 메모리 풀에서 메모리를 미리 만들 때 이 형식으로 만들어도 된다.

	STL (Standard Template library)
		- C++의 기본적인 라이브러리
		- 구성요소
			- 컨테이너 : vector, map, set, queue
			- 알고리즘 : 컨테이너 내부의 데이터를 여러방식으로 조회/조작 하는 방법들(정렬, 탐색)
			- 반복자(Iterator) : 컨테이너의 특정 위치를 가리킴(포인터 느낌)
			- 함수객체(Functor) : 커스텀 정렬 등에 사용되는 것 (일반적으로 람다로 사용, 물론 직접 만들어도 됨 struct로)

	람다 (무명 함수)
		- 짧은 코드의 함수를 코드 내에서 바로 정의하고 사용(1회용)
		- [캡쳐](매개변수) -> 반환타입 {구현} 대부분의 경우 반환 타입은 생략가능(컴파일러가 추론)
			- 화살표랑 반환타입이 세트인듯
		- 어지간하면 값 복사는 하지 말자
		- 캡쳐는 람다 실행 시 외부 변수접근을 어떻게 할지
			- [ ]				: 접근 안함
			- [&]				: 함수 내부의 지역변수를 모두 참조로 (값 변경 가능, 비권장)
			- [=]				: 모두 복사로 (읽기 전용, 비권장)
			- [this]			: 클래스의 멤버 변수와 함수에 접근 가능 (비권장)
			- [변수명]			: 특정 변수만 복사로 캡쳐
			- [&변수명]			: 변수를 참조로 (만드는 시점과, 실행시점이 달라서 값이 다를 수 있어서 생김, 근데 댕글링 포인터는 여전)
			- [=, &변수명]		: 변수명은 참조로, 나머지는 복사로
*/

class Day0611
{
public:

	void Day0611_Run();
	void TemplateQueueTest();
	void TemplateVectorTest();

	void STLAlgoTest();
	void PrintVector(const std::vector<int>& InData);
	bool Comp3(const int& a, const int& b)
	{
		return a < b;
	}

	void Practice1();
	void Practice2();
	void Practice3();
	void Practice4();
};

struct Comp
{
	bool operator()(const int& a, const int& b) const
	{
		return a < b;
	}
};
